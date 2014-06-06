#ifdef __hpux
#include<dl.h>
#else
#include <dlfcn.h>
#endif

#include <unistd.h>
#include <ctype.h>
#include <string.h>

#include <sys/wait.h>

#include <sys/types.h>
#include <sys/utsname.h>


#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>


#include "micromegas.h"
#include "micromegas_aux.h"
#include "micromegas_f.h"

int checkLockFile(void)
{ int fd,ret;
  static char *lockTxt=NULL; 
  char*fname;
  if(lockTxt==NULL)
  {
     struct utsname buff;
     uname(&buff);
     lockTxt=(char*)malloc(100);
     sprintf(lockTxt," process %d on %s\n",getpid(),buff.nodename);
  }
  fname=malloc(strlen(WORK)+20);
  sprintf(fname,"%s/lock_",WORK);
  fd=open(fname, O_WRONLY|O_CREAT,0666);
  if(fd<0)
  { printf("Can not creat lock file: '%s' Program terminated\n",fname);
    exit(55); return -1;
  }
#ifdef FLOCK  
  ret=flock(fd,LOCK_EX|LOCK_NB);   
#else
  ret = lockf(fd, F_TLOCK, 10);
#endif  
  if(ret)
  { printf("Library generation is temporary locked by other program\n"
           "see file %s/lock_\n",WORK);
#ifdef FLOCK
    flock(fd,LOCK_EX);
#else
    lockf(fd, F_LOCK, 10);
#endif    
  }
  free(fname);
  write(fd,lockTxt,strlen(lockTxt));
  return fd;
}

void removeLock(int fd)
{
#ifdef FLOCK
   flock(fd,LOCK_UN);
#else
   lockf(fd, F_ULOCK, 10);
#endif
   close(fd);
}


static void* newSymbol(void*handle,char *name)
{
#ifdef __hpux
void * addr;
     if(shl_findsym((shl_t*)&handle,name,TYPE_UNDEFINED,&addr)) return NULL;
       else return addr;
#else
      return dlsym(handle, name);
#endif
}

static void * dLoad(char * libName)
{
void *q;
if(access(libName,R_OK)) return NULL;

#ifdef __hpux
   return  shl_load(libName,0,0L);
#else
   q= dlopen(libName, RTLD_NOW);
   if(!q) printf("%s\n",dlerror()); 
   return q;
#endif
}


static void dClose(void * handle)
{
#ifdef __hpux
       shl_unload(handle);
#else
       dlclose(handle);
#endif
}

static numout* loadLib(void* handle, char * lib)
{ numout * cc=malloc(sizeof(numout));
  char name[100];
  if(!handle) {free(cc); return NULL;}   
  cc->handle=handle;
  sprintf(name,"interface_%s",lib);
  cc->interface=newSymbol(handle, name);
  if(!cc->interface || cc->interface->nprc==0){free(cc); return NULL;}
  else
  {  int i;
     cc->init=0;
     cc->Q=NULL, cc->SC=NULL, cc->GG=NULL;
     cc->link=malloc(sizeof(double*)*(1+cc->interface->nvar));
     cc->link[0]=NULL;
     for(i=1;i<=cc->interface->nvar;i++) 
     { char *name=cc->interface->varName[i];
       cc->link[i]=varAddress(name);
       if(strcmp(name,"Q")==0) cc->Q=cc->interface->va+i; 
       else if(strcmp(name,"SC")==0) cc->SC=cc->interface->va+i;
       else if(strcmp(name,"GG")==0) cc->GG=cc->interface->va+i;
     }  
  }
  return cc;
}

void pname2lib(char*pname, char * libname)
{ int i;
  int j=0;
  for(i=0;i<strlen(pname);i++)
  if(isalpha(pname[i]))   
  { if(islower(pname[i]))  libname[j++]=pname[i];
    else {libname[j++]='_'; libname[j++]=tolower(pname[i]);}
  }   
  else 
  { switch(pname[i])
    { case '+': libname[j++]='_';libname[j++]='_'; libname[j++]='p';break;
      case '-': libname[j++]='_';libname[j++]='_'; libname[j++]='m';break;
      case '~': libname[j++]='_';libname[j++]='_'; libname[j++]='t';break;
      default: libname[j++]=pname[i];
    }
  }
  libname[j]=0;   
}


typedef struct  procRec 
{ struct procRec  * next;
  char * libname;
  numout * cc;
}  procRec;   

static  procRec* allProc=NULL;

numout*newProcess_(int twidth,int model, char*Process, char*excludeVirtual, char*excludeOut,char*lib,int usr)
{
   char *proclibf,*command;
   void * handle=NULL;
   int new=0;
   numout * cc;
   procRec*test;
   int Len;
   
   for(test=allProc;test; test=test->next)
   { if(strcmp(lib,test->libname)==0) return test->cc;}

   Len=strlen(WORK)+strlen(lib)+200;
   proclibf=malloc(Len);

   if(Process) Len+=strlen(Process);
   if(excludeVirtual) Len+=strlen(excludeVirtual);
   if(excludeOut) Len+=strlen(excludeOut);
   command=malloc(Len);
 
   sprintf(command,"cd %s;" MAKE " -s -f make_check  lib=%s model=%d",WORK,lib,model); 

   system(command);
   
   sprintf(proclibf,"%s/so_generated/%s.so",WORK,lib);
   handle=dLoad(proclibf);
   if(!handle)
   {
      char options[20];
      char modelCh[50];
      int ret,fd,i;
      if(usr)
      {  char * reserved[3]={"omg", "pwidth", "dir"};
         for(i=0;i<3;i++)
         {
           char * c=strstr(lib,reserved[i]);
           if(c==lib)
           {  printf("Library names started from '%s' are reserved for internal use\n",
                           reserved[i]);
              if(i==0) printf("The libraries of WIMP annihilation  become available automatically\n"
                              "after calculation of relic density.\n");              
              free(command); free(proclibf);
              return NULL;
            }
         }
      }
      for(i=0;Process[i]==' ';i++); if(Process[i]==0)
      {/* printf("Such Library is absent and  process is not specified\n");*/
        free(command); free(proclibf); 
        return NULL;    
      }      
      fd=checkLockFile(); 
      if(twidth) strcpy(options,"5[[{[{}");else strcpy(options,"");
      for(modelCh[0]=0; model>1;model--) strcat(modelCh,"[");
       
      sprintf(command,"cd %s; ./newProcess %s \"%s\" \"%s\" \"%s\"",
                          WORK, lib,options,modelCh,Process);

      if(excludeVirtual) sprintf(command+strlen(command)," \"%s\"",excludeVirtual);
      else  sprintf(command+strlen(command)," \"\"");            
      if(excludeOut) sprintf(command+strlen(command)," \"%s\"",excludeOut);       
      ret=system(command);
  
      removeLock(fd);

      if(ret<0 || WIFSIGNALED(ret)>0 ) exit(10);
      
      
      if(ret==0) handle=dLoad(proclibf); else 
      { printf(" Can not compile %s \n", Process);
        free(command); free(proclibf);
        return NULL;
      } 
      if(!handle)
      { printf(" Can not load the compiled library %s \n",proclibf);
         free(command); free(proclibf);
        return NULL;
      }         
      new=1;   
   }
   cc=loadLib(handle,lib);
   if(!cc && new) dClose(handle);
   if(cc)
   {  test=(procRec*)malloc(sizeof(procRec));
      test->next=allProc; allProc=test;
      test->libname=(char*) malloc(strlen(lib)+1);
      strcpy(test->libname,lib);
      test->cc=cc;
   } else if(new) dClose(handle);  
    free(command); free(proclibf);
   return cc; 
}


int  procInfo1(numout*cc, int *nsub, int * nin, int *nout)
{
  if(nin) *nin=cc->interface->nin;
  if(nout)*nout=cc->interface->nout;
  if(nsub)*nsub=cc->interface->nprc;
  return 0;
}

int procInfo2(numout*cc,int nsub,char**name,double*mass)
{
  int i;
  int ntot=cc->interface->nin+cc->interface->nout;
    
  if(nsub<1 || nsub> cc->interface->nprc) return 2;

  if(name)for(i=0;i<ntot ;i++) 
  name[i]=(cc->interface->pinf)(nsub,i+1,NULL,NULL);

  if(mass)
  {  
    for(i=1;i<=cc->interface->nvar;i++) if(cc->link[i]) cc->interface->va[i]=*(cc->link[i]);  
    if(cc->Q) *(cc->Q)=100;
    if(cc->interface->calcFunc()>0) { printf("cannot calculate constr\n"); return 4;}
    if(cc->Q)
    {
      cc->interface->pinf(nsub,1,mass,NULL);
      *(cc->Q)=mass[0];
      if(cc->SC && cc->GG) *(cc->GG)=*(cc->SC);
      cc->interface->pinf(nsub,1,mass,NULL);
      *(cc->Q)=mass[0];
      if(cc->SC && cc->GG) *(cc->GG)=*(cc->SC);
    }      
       
    for(i=0;i<ntot ;i++) cc->interface->pinf(nsub,i+1,mass+i,NULL);     
  }
  return 0;
}

numout*newProcess(char*Process,char*lib){return newProcess_(0,1,Process,NULL,"",lib,1);}


void newprocess_(char*Process,char*lib, int * address, int len1,int len2)
{ char cProcess[100], clib[100];
  numout*cc;
  fName2c(Process,cProcess,len1);
  fName2c(lib,clib,len2);
  cc=newProcess(cProcess,clib);
  if(!cc) *address=0;else memcpy(address,&cc,sizeof(cc)); 
}
  
     
void  procinfo1_(int*ccf, int *ntot, int * nin, int *nout)
{  numout*cc;
   memcpy(&cc,ccf,sizeof(cc));
   procInfo1(cc, ntot, nin, nout);}

void procinfo2_(int*ccf,int*nsub,char*name,double*mass,int len)
{ int ntot, nin, nout,i;
  numout*cc;
  char ** cname;  
  memcpy(&cc,ccf,sizeof(cc));
  procInfo1(cc, &ntot, &nin, &nout);
  cname=malloc((nin+nout)*sizeof(char*));
  
  procInfo2(cc,*nsub,cname, mass);
  for(i=0;i<nin+nout;i++) cName2f(cname[i],name+i*len,len);
}

/*===========================================================*/
static double PcmOut, totcoef;
static double pvect[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

double (*sqme)(int nsub,double *pvect, int * err_code)=NULL;
static double eps=0.001;
int  _nsub_=0;

int  kin22(double PcmIn,double * pmass)
{  
   double ms,md,sqrtS;

   sqrtS=sqrt(pmass[0]*pmass[0]+PcmIn*PcmIn)+sqrt(pmass[1]*pmass[1]+PcmIn*PcmIn);
   ms = pmass[2] + pmass[3];  if(ms>=sqrtS*0.9999999) return 1;
   md = pmass[2] - pmass[3];
   PcmOut = sqrt((sqrtS-ms)*(sqrtS+ms)*(sqrtS-md)*(sqrtS+md))/(2*sqrtS);
   totcoef = PcmOut /(32.0*M_PI*PcmIn*sqrtS*sqrtS);
   pvect[3] = PcmIn;
   pvect[7] =-PcmIn;
   pvect[0] = sqrt(PcmIn*PcmIn   + pmass[0]*pmass[0]);
   pvect[4] = sqrt(PcmIn*PcmIn   + pmass[1]*pmass[1]);
   pvect[8] = sqrt(PcmOut*PcmOut + pmass[2]*pmass[2]);
   pvect[12]= sqrt(PcmOut*PcmOut + pmass[3]*pmass[3]);

   return 0;
}

double  dSigma_dCos(double  cos_f)
{
   double  r;
   double sin_f=sqrt(fabs((1-cos_f)*(1+cos_f)));
   int err_code=0;
   pvect[11]=PcmOut*cos_f;
   pvect[15]=-pvect[11];
   pvect[10]=PcmOut*sin_f;
   pvect[14]=-pvect[10];
   r = (*sqme)(_nsub_,pvect,&err_code);
   err_code=0;
   return r * totcoef;
}


double cs22(numout * cc, int nsub, double P, double cos1, double cos2 , int * err) 
{
  int i;
  double pmass[4];
  for(i=1;i<=cc->interface->nvar;i++) if(cc->link[i]) cc->interface->va[i]=*(cc->link[i]);

  if( cc->interface->calcFunc()>0 ) {*err=4; return 0;}
  *(cc->interface->gtwidth)=0;
  *(cc->interface->twidth)=0;
  *(cc->interface->gswidth)=0;
  for(i=0;i<4;i++) cc->interface->pinf(nsub,1+i,pmass+i,NULL); 
  *err=0;
  sqme=cc->interface->sqme;
  _nsub_=nsub; 
  if(kin22(P,pmass)) return 0; else return 3.8937966E8*simpson(dSigma_dCos,cos1,cos2,0.3*eps);
}


double pWidth2(numout * cc, int nsub)
{
  double pvect[12];
  double width=0.;
  double m1,m2,m3; 
  int i,ntot,nin,nout;

  procInfo1(cc,&ntot,&nin,&nout);
  if(nsub<1 ||  nsub>ntot|| nin!=1||nout !=2)  return 0;
     
  for(i=1;i<=cc->interface->nvar;i++) if(cc->link[i]) cc->interface->va[i]=*(cc->link[i]);

  if( cc->interface->calcFunc()>0 ) { return -1;}
  if(cc->Q) 
  {
    cc->interface->pinf(nsub,1,&m1,NULL);
    *(cc->Q)=m1;
    if( cc->interface->calcFunc()>0 ) { return -1;}
    if(cc->SC && cc->GG)  cc->GG=cc->SC;           
  }  
  

  cc->interface->pinf(nsub,1,&m1,NULL);
  cc->interface->pinf(nsub,2,&m2,NULL); 
  cc->interface->pinf(nsub,3,&m3,NULL);
  if(m1 >m2 + m3)
  {   int i,err_code; 
      double md=m2-m3;
      double ms=m2+m3;
      double pRestOut=sqrt((m1*m1 - ms*ms)*(m1*m1-md*md))/(2*m1);
      double totcoef= pRestOut/(8. * M_PI * m1*m1);
           
      for(i=1;i<12;i++) pvect[i]=0;
      pvect[0]=m1;
      pvect[7]=pRestOut;
      pvect[4]=sqrt(pRestOut*pRestOut+m2*m2);
      pvect[11]=-pRestOut;
      pvect[8]=sqrt(pRestOut*pRestOut+m3*m3);
      width = totcoef * (cc->interface->sqme)(nsub,pvect,&err_code);
  }
  return width;
}
 
double decay2Info(char * pname, FILE* f)
{ int i,j,ntot;
  numout * cc;
  double wtot;
  char pname2[20],process[20],plib[20];
  char * dname[8];

  for(i=0,j=0;pname[i];i++)
  if(pname[i]!=' ') pname2[j++]=pname[i];
  pname2[j]=0;
  strcpy(plib,"2width_");
  pname2lib(pname2,plib+7);
  sprintf(process,"%s->2*x",pname2);
  cc=newProcess_(0,1,process,NULL,"",plib,0);
  if(!cc) return -1; 
  procInfo1(cc,&ntot,NULL,NULL);
  if(f) fprintf(f,"\n Partial width for %s->2x decays in GeV\n",pname2); 
  for(wtot=0,i=1;i<=ntot;i++)
  { double w;
    procInfo2(cc,i,dname,NULL);
    w=pWidth2(cc,i);
    if(w!=0)
    { wtot+=w;
      if(f) fprintf(f,"%3.3s %3.3s  %.2E\n",dname[1],dname[2],w); 
    }
  }
  if(f) fprintf(f," Total width %.2E GeV\n",wtot);
  return  wtot;
}
/*============ Fortran ==========*/

double cs22_(int*ccf,int*nsub,double*P,double*cos1,double*cos2,int*err)
{ numout*cc;
  memcpy(&cc,ccf,sizeof(cc));
  return cs22(cc,*nsub,*P,*cos1,*cos2 ,err);
} 

double pwidth2_(int * ccf, int *nsub)
{  numout*cc;
   memcpy(&cc,ccf,sizeof(cc));
   return pWidth2(cc,*nsub);
}

void  sethelicities_(double *h1,double *h2) { Helicity[0]=*h1; Helicity[1]=*h2;} 
