#include "micromegas.h"
#include "micromegas_aux.h"
#include "micromegas_f.h"
double sWidth=0.01;
static int neg_cs_flag;

static int NC=0;

static char ** inP;
static int  *  inAP;
static int  *  inG;
static int  *  inNum;

static numout ** code22; 
static int *inC;    /* combinatoric coefficients  NCxNC*/

static double *inDelta; /* inDelta[i]= (inMass[i]-M)/M; */
static double *inG_;    /* inG[i]*pow(1+inDelta[i],1.5);*/
static double **inMassAddress;
static double *inMass;  /* masses */
static int *sort;

static int LSP;
static double M;                  /* =inMass[LSP] */
double M1=0,M2=0;
static double DeltaXf;

static double pmass[4];

#define XSTEP 1.1
static double eps=0.001; /* precision of integration */

static int nsub=1;       /*  subprocess number  */

static double MassCut;

static int fast_;    /* to pass the Fast argument */
static double xf_;   /* to pass the Xf argument   */

#define MPlank 1.22E19 /*GeV*/

static numout * mainChan=NULL;


static  double sigma_simpson(double PcmIn)
{ double r;
  if(kin22(PcmIn,pmass)) return 0;
  _nsub_=nsub;
  r= simpson(dSigma_dCos,-1.,1,0.3*eps);
  if(r<0) { neg_cs_flag=1;r=0;}
/*
printf("PcmIN=%E sigma=%E\n",  PcmIn, r*3.8937966E8); 
*/
  return r;
}

static  double sigma_gauss(double PcmIn)
{ double r;
  if(kin22(PcmIn,pmass)) return 0.; 
  _nsub_=nsub;
  r=gauss(dSigma_dCos,-1.,1.,5);
  if(r<0) { neg_cs_flag=1;r=0;}
  return r;
}  

static double (*sigma)(double)= sigma_gauss;

static double geff(double x)
{ double sum=0; int l;

  for(l=0;l<NC;l++)
  { int k=sort[l];
    double A=x*inDelta[k];
    if(A>15 || M+inMass[k] > MassCut) return sum;
    sum+=inG_[k]*exp(-A)*K2pol(1/(x+A));
  }
  return sum;
}


static void termod(double t, double * sqrt_gStar, double * heff)
{
  const  double table[276][3]=
  {
#include"geff_heff.tab"
  };

  if(t>= table[0][0])
  { if(sqrt_gStar) *sqrt_gStar=table[0][1];
    if(heff)             *heff=table[0][2];
  } else if(t<=0 )
  { if(sqrt_gStar) *sqrt_gStar=table[275][1];
    if(heff)             *heff=table[275][2];
  } else
  {
    int hi=0, lo=275, c;
    double tlo,thi;
    double slo,shi;

    for(c=138; lo-hi >1; c=(lo+hi)/2) if(table[c][0]< t) lo=c; else hi=c;

    tlo=table[lo][0];
    thi=table[hi][0];

    if(sqrt_gStar)
    {
       slo=table[lo][1];
       shi=table[hi][1];
       *sqrt_gStar=( (thi-t)*slo - (tlo-t)*shi)/(thi-tlo);
    }
    if(heff)
    {  slo=table[lo][2];
       shi=table[hi][2];
       *heff=( (thi-t)*slo - (tlo-t)*shi)/(thi-tlo);
    }
  }
}

static double y_pass;

static double weight_integrand(double v)
{  double x,gf;
   double sqrt_gStar;

   if(v==0.) return 0;
   x=xf_-3*log(v)/(y_pass-2);
   gf=geff(x);

   termod(M/x,&sqrt_gStar,NULL);
   return K1pol(1/(x*y_pass))*3*v*v*sqrt_gStar/(sqrt(x)*gf*gf*(y_pass-2));
}

static double weightBuff_x[1000];
static double weightBuff_y[1000];
static int inBuff=0;

static double weight(double y)
{ int i;
  double w;
  for(i=0;i<inBuff;i++) if(y==weightBuff_x[i]) return weightBuff_y[i];
  y_pass=y;
  w=  simpson(weight_integrand,0.,1.,0.3*eps);
  if(inBuff<1000){weightBuff_x[inBuff]=y; weightBuff_y[inBuff++]=w;}
  return w;
}

static int exi;

static double s_integrand( double u)
{  double z,y,sv_tot,w;
   double Xf_1;
   double ms,md,sqrtS,PcmIn;
   
   if(u==0. || u==1.) return 0.;

   z=1-u*u;
   y=2 +(DeltaXf - 3*log(z))/xf_;
   sqrtS=M*y;

   ms = M1 + M2;  if(ms>=sqrtS)  return 0;
   md = M1 - M2;
   PcmIn = sqrt((sqrtS-ms)*(sqrtS+ms)*(sqrtS-md)*(sqrtS+md))/(2*sqrtS);
   sv_tot=sigma(PcmIn);         

   if(exi) { w=weight(y); Xf_1=1;} else {w=K1pol(1/(xf_*y)); Xf_1=xf_;}

   return sqrt(2*Xf_1*y/M_PI)*y*(PcmIn*PcmIn/(M*M))*sv_tot*w*6*u*z*z;
}

static int Npow;

static double s_pow_integrand(double u)
{
   double ms,md,sqrtS;
   double z,y,sv_tot,pp,w,Xf_1;
   double PcmIn;
   
   if(u==0. || u==1.) return 0.;

   z=1-u*u;
   y=2+(DeltaXf - 3*log(z))/xf_;

   ms = M1 + M2;
   md = M1 - M2;
   sqrtS=(M*y);
   PcmIn = sqrt((sqrtS-ms)*(sqrtS+ms)*(sqrtS-md)*(sqrtS+md))/(2*sqrtS);
   pp= PcmIn* PcmIn;

   switch(Npow)
   { case 0: sv_tot=1; break;
     case 1: sv_tot= pp; break;
     case 2: sv_tot= pp*pp; break;
     case 3: sv_tot= pp*pp*pp; break;
   }

   if(exi){ w=weight(y); Xf_1=1;} else { w=K1pol(1/(xf_*y)); Xf_1=xf_;}
   return sqrt(Xf_1*y/(2*M_PI))*y*(PcmIn/M)*sv_tot*w*6*u*z*z;
}

static double m2u(double m) {return sqrt(1-exp((DeltaXf+xf_*(2-m/M))/3));}

typedef struct gridStr
{  int n;
   double ul[100];
   double ur[100];
   int pow[100];
}  gridStr;

static double u_max;

static gridStr   makeGrid(double mp,double wp)
{
  gridStr grd;

  int n=0,j;
  int pow_[6]={3,3,4,4,3,3};
  double c[5]={-8,-3,0,3,8};

  grd.ul[0]=0.;
  for(j=0;j<5;j++) if(mp+c[j]*wp>M*(2+DeltaXf/xf_))
  {  grd.ur[n]=m2u(mp+c[j]*wp);
     grd.pow[n]=pow_[j];
     grd.ul[n+1]=grd.ur[n];
     if( grd.ur[n]>u_max) { grd.ur[n]=u_max;  grd.n=n+1; return grd;}
     n++;
  }
  grd.ur[n]=u_max;
  grd.pow[n]=pow_[5];
  grd.n=n+1;
  return grd;
}

#ifdef DEBUG
static void printGrid(gridStr * grd)
{ int i;
  printf("~~~~~~~~~~~~~\n");
  for(i=0;i<grd->n;i++) printf("%E %E %d\n",grd->ul[i],grd->ur[i],grd->pow[i]);
  printf("~~~~~~~~~~~~~\n");
}
#endif

static gridStr  crossGrids(gridStr * grid1, gridStr * grid2)
{ gridStr grid;
  int n=0,i0=0,i1=0,i;
  grid.ul[0]=0.;
  while(i0<grid1->n && i1<grid2->n)
  { double d0= grid1->pow[i0]/(grid1->ur[i0]-grid1->ul[i0]);
    double d1= grid2->pow[i1]/(grid2->ur[i1]-grid2->ul[i1]);
    double d = ( d0>d1? d0:d1);
    int m=(grid1->pow[i0] > grid2->pow[i1]? grid1->pow[i0]:grid2->pow[i1]);

    if(grid1->ur[i0] < grid2->ur[i1]) { grid.ur[n]=grid1->ur[i0++];}
    else                              { grid.ur[n]=grid2->ur[i1++];}


    grid.pow[n]=0.999+d*(grid.ur[n]-grid.ul[n]);

    if(grid.pow[n]>m) grid.pow[n]=m;
    if(grid.pow[n]==1) grid.pow[n]=2;

    n++;
    grid.ul[n]=grid.ur[n-1];
  }
  grid.n=n;
  for(i=0;i<grid.n;i++) if(grid.ur[i]-grid.ul[i]>0.4
                         && grid.pow[i]<4)  grid.pow[i]=4;
  return grid;
}



static double * paramAddress(char * name)
{
  int k,k0;
  char ** f;
  double * res=varAddress(name);
  if(res)  return res; 

  if(mainChan)
  {                                                                              
    CalcHEP_interface * ci=mainChan->interface; 
    k0=ci->nvar+1;
    f=ci->varName+k0;
  
    for(k=0; k<ci->nfunc;k++) 
      if(strcmp(name, f[k])==0) return ci->va+k+k0; 
  }
  return NULL;
}

double findParam(char*name, int *err)
{ double * v;
  v=paramAddress(name);
  if(v){*err=0; return *v;} else{ *err=1; return 0;}
}  

double findParamW(char*name)
{ double * v;
  v=paramAddress(name);
  if(v){ return *v;}
  else{ printf("ERROR: parameter '%s' is not detected\n",name); return 0;}
}
                                                                                
double findparamw_(char*f_name, int len)
{
   char c_name[20];
   fName2c(f_name,c_name,len);
   return findParamW(c_name);
}


static int  new_code(int k1,int k2);

static int testSubprocesses(void)
{
 static int first=1;
 int err,k1,k2,i,j;
 double *Q;

 if(first)
 {
    first=0;
    
    for(i=0,NC=0;i<Nodd;i++,NC++) 
        if(strcmp(OddPrtcls[i].name,OddPrtcls[i].aname))NC++;
        
    inP=(char**)malloc(NC*sizeof(char*));
    inAP=(int*)malloc(NC*sizeof(int));
    inG=(int*)malloc(NC*sizeof(int));
    inDelta=(double*)malloc(NC*sizeof(double)); 
    inG_=(double*)malloc(NC*sizeof(double));
    inMassAddress=(double**)malloc(NC*sizeof(double*));
    inMass=(double*)malloc(NC*sizeof(double));
    inNum= (int*)malloc(NC*sizeof(int));
    sort=(int*)malloc(NC*sizeof(int));

    code22=(numout**)malloc(NC*NC*sizeof(numout*));
    inC=(int*)malloc(NC*NC*sizeof(int)); 

      
    for(i=0,j=0;i<Nodd;i++)
    {  
       inP[j]=OddPrtcls[i].name;
       inNum[j]=OddPrtcls[i].NPDG;
       inG[j]=(OddPrtcls[i].spin2+1)*OddPrtcls[i].cdim;
       if(strcmp(OddPrtcls[i].name,OddPrtcls[i].aname))
       {
         inAP[j]=j+1;
         j++;
         inP[j]=OddPrtcls[i].aname;
         inG[j]=inG[j-1];
         inAP[j]=j-1;
         inNum[j]=-OddPrtcls[i].NPDG;
       } else inAP[j]=j;
       j++;
    }

    for(i=0;i<NC;i++) sort[i]=i;
    for(k1=0;k1<NC;k1++) for(k2=0;k2<NC;k2++) inC[k1*NC+k2]=-1;
    for(k1=0;k1<NC;k1++) for(k2=0;k2<NC;k2++) if(inC[k1*NC+k2]==-1)
    {  int kk1=inAP[k1];
       int kk2=inAP[k2];
       inC[k1*NC+k2]=1;
       if(inC[k2*NC+k1]==-1)   {inC[k2*NC+k1]=0;   inC[k1*NC+k2]++;}
       if(inC[kk1*NC+kk2]==-1) {inC[kk1*NC+kk2]=0; inC[k1*NC+k2]++;}
       if(inC[kk2*NC+kk1]==-1) {inC[kk2*NC+kk1]=0; inC[k1*NC+k2]++;}
    }

    for(k1=0;k1<NC;k1++) for(k2=0;k2<NC;k2++) code22[k1*NC+k2]=NULL;
    mainChan=NULL;
    if(strcmp(OddPrtcls[0].name,OddPrtcls[0].aname)==0)
         { new_code(0,0); mainChan=code22[0*NC+0];} 
    else { new_code(0,1); mainChan=code22[0*NC+1];}

    if(!mainChan){printf("Can not compile generate and load code for "
      "annihilation  channel %s %s->2*x\n Program stops.\n", 
         OddPrtcls[0].name,OddPrtcls[0].aname); exit(44);}
        
    for(i=0,j=0;i<Nodd;i++)
    {
       inMassAddress[j]=paramAddress(OddPrtcls[i].mass);
       if(!inMassAddress[j]) 
       { printf(" Can not find mass  %s among parameetrs\n",OddPrtcls[i].mass);
         exit(5);
       }

       if(strcmp(OddPrtcls[i].name,OddPrtcls[i].aname))
       {
         j++;
         inMassAddress[j]=inMassAddress[j-1];
       }
       j++;
    }
  }
  Q=NULL;
  for(i=1;i<=mainChan->interface->nvar;i++) 
 {  if(mainChan->link[i]) 
    mainChan->interface->va[i]=*(mainChan->link[i]);
    if(strcmp(mainChan->interface->varName[i],"Q")==0) Q=mainChan->interface->va+i;
 }
 if(Q) *Q=100;
 
 err=mainChan->interface->calcFunc();
 if(err>0) return err;

 M=fabs(*(inMassAddress[0]));
 for(i=0;i<NC;i++) 
 { inMass[i]=fabs(*(inMassAddress[i]));
   if(M>inMass[i]) M=inMass[i];
 }

 if(Q) 
 { *Q=2*M;
    assignVal("Q",2*M);
    err=mainChan->interface->calcFunc();
    if(err>0) return err;
 }
            
 for(i=0; i<NC-1;)
 { int i1=i+1;
   if(inMass[sort[i]] > inMass[sort[i1]])
   { int c=sort[i]; sort[i]=sort[i1]; sort[i1]=c;
     if(i) i--; else i++;
   } else i++;
 }

 LSP=sort[0];
 M=inMass[LSP];

 for(i=0;i<NC;i++)
 { inDelta[i]= (inMass[i]-M)/M;
   inG_[i]=inG[i]*pow(1+inDelta[i],1.5);
 }

  for(k1=0;k1<NC;k1++)  for(k2=0;k2<NC;k2++) if(code22[k1*NC+k2]) code22[k1*NC+k2]->init=0;
return 0;
}
 
int sortOddParticles(char * lsp)
{ int i,err;
  err=testSubprocesses();
  if(err)
  {
    strcpy(lsp,mainChan->interface->varName[err]);
    return err;
  }
  
  if(M<0.1) 
  { sprintf(lsp,"M(%s)<0.1",inP[LSP]);
    return -1;
  } 
  
  if(sWidth>0) for(i=0;i< Nodd;i++) assignVal(OddPrtcls[i].width,sWidth*M);
  if(lsp) strcpy(lsp,inP[LSP]);
  return 0;
}


static int  new_code(int k1,int k2)
{
   char lib[40];
   char process[40];
   char lib1[12],lib2[12];
   numout*cc;
   static char* excludeOut=NULL;
  
   if(excludeOut==NULL)
   { int size=100,len=1,i; 
     excludeOut=(char*)malloc(size);
     excludeOut[0]=0;
     
     for(i=0;i<Nodd;i++) 
     { 
       if(size-len<15){size+=100; excludeOut=realloc(excludeOut,size);}  
       sprintf(excludeOut+strlen(excludeOut),",%s",OddPrtcls[i].name);
       len+=strlen(OddPrtcls[i].name)+1;
       if(strcmp(OddPrtcls[i].name,OddPrtcls[i].aname))
       {
        sprintf(excludeOut+strlen(excludeOut),",%s",OddPrtcls[i].aname);
        len+=strlen(OddPrtcls[i].aname)+1;
       }
     }
   }

/*
   char PM;
   if(inNum[k1]>0) PM='P'; else PM='M';
        sprintf(lib1,"%c%d",PM,abs(inNum[k1]));
   if(inNum[k2]>0) PM='P'; else PM='M';
        sprintf(lib2,"%c%d",PM,abs(inNum[k2]));
*/

   pname2lib(inP[k1],lib1);
   pname2lib(inP[k2],lib2); 
    
   sprintf(lib,"omg%s%s",lib1,lib2);
   sprintf(process,"%s,%s->2*x",inP[k1],inP[k2]);
   cc=newProcess_(1,1,process,NULL,excludeOut+1,lib,0);
   if(cc) 
   { (*cc->interface->twidth)=1;
        code22[k1*NC+k2]=cc;
   } else inC[k1*NC+k2]=0;

   return 0;
}   
   

static void gaussC2(double * c, double * x, double * f)
{
  double  A[2][2];
  int i,j;
  double det;
  double B[2];
    
  for(i=0;i<2;i++)
  { int l=1; for(j=0;j<2;j++) {A[i][j]=l*c[i+j]; l=-l;}  
     B[i]=l*c[2+i];
  }
  
  det=A[0][0]*A[1][1] - A[0][1]*A[1][0];
  
  f[0]= ( B[0]*A[1][1]-B[1]*A[0][1])/det;
  f[1]= (-B[0]*A[1][0]+B[1]*A[0][0])/det;
  
  det=sqrt(f[0]+f[1]*f[1]/4.);
   
  x[0]= -f[1]/2.-det;
  x[1]= -f[1]/2.+det;
 
  for(i=0;i<2;i++) { B[i]=c[i]; A[0][i]=1; }
  for(j=0;j<2;j++)   A[1][j]=A[0][j]*x[j];

  det= A[0][0]*A[1][1] - A[0][1]*A[1][0];
  
  f[0]= ( B[0]*A[1][1]-B[1]*A[0][1])/det;
  f[1]= (-B[0]*A[1][0]+B[1]*A[0][0])/det;
} 



static double aRate(double X, int everage,int Fast, float ** wPrc)
{
  double Sum=0.;
  int i,l1,l2;
  int nPrc=0;
  char* pname[5];
  gridStr grid,grid1;
  double MassCutOut=MassCut+M*log(100.)/X;
  double Msmall,Mlarge;

  int nPrcTot=0;

  if(MassCutOut<M*(2+10/X)) MassCutOut=M*(2+10/X); 

  xf_=X;
  exi=everage;

  if(wPrc) *wPrc=NULL;

  for(l1=0;l1<NC;l1++)
  { int k1=sort[l1]; if(M+inMass[k1]>MassCut) break;
  for(l2=0;l2<NC;l2++)
  {
    double Sumkk=0.;
    double x[2],f[2];
    double factor;
    int k2=sort[l2];
    CalcHEP_interface * CI;

    if(inMass[k1]+inMass[k2] > MassCut) break;

    if(inC[k1*NC+k2]<=0) continue;
    if(code22[k1*NC+k2]==NULL) new_code(k1,k2);
    if(inC[k1*NC+k2]<=0) continue;


    if(!code22[k1*NC+k2]->init)
    { numout * cd=code22[k1*NC+k2];
      CalcHEP_interface *cdi=cd->interface;
      for(i=1;i<=cdi->nvar;i++) if(cd->link[i]) cdi->va[i]=*(cd->link[i]);
      
      if( cdi->calcFunc()>0 ) {FError=1; return -1;}
      cd->init=1;
    }

    if(wPrc)
    {  nPrcTot+=code22[k1*NC+k2]->interface->nprc;
       *wPrc=(float*)realloc(*wPrc,sizeof(float)*(nPrcTot));
    }

    sqme=code22[k1*NC+k2]->interface->sqme;
    DeltaXf=(inDelta[k1]+inDelta[k2])*X;
    inBuff=0;

    M1=inMass[k1];
    M2=inMass[k2];

    Msmall=M1>M2? M1-M*(1-sWidth): M2-M*(1-sWidth);
    Mlarge=M1>M2? M2+M*(1-sWidth): M1+M*(1-sWidth);

    u_max=m2u(MassCutOut);
    if(Fast)
    { 
      if(Fast==1)
      {  double c[4];

         for(Npow=0;Npow<4;Npow++) c[Npow]=simpson(s_pow_integrand, 0. ,1. ,1.E-4);
         gaussC2(c,x,f);
         for(i=0;i<2;i++){ x[i]=sqrt(x[i]); f[i]*=2*x[i]/M;}
      }else 
      {
         double c[2];
         for(Npow=0;Npow<2;Npow++) c[Npow]=simpson(s_pow_integrand, 0. ,1. ,1.E-4);
         x[0]= sqrt(c[1]/c[0]);
         f[0]= c[0]*2*x[0]/M;
      }
    }
    factor=inC[k1*NC+k2]*inG[k1]*inG[k2]*exp(-DeltaXf);
    CI=code22[k1*NC+k2]->interface;
    for(nsub=1; nsub<= CI->nprc;nsub++,nPrc++)
    { double u_min=0.;
      double a=0;

      if(wPrc) (*wPrc)[nPrc]=0;

      for(i=0;i<4;i++)  pname[i]=CI->pinf(nsub,i+1,pmass+i,NULL);
      if(pmass[2]+pmass[3]>MassCutOut) continue;

      if( (pmass[2]>Mlarge && pmass[3]<Msmall)
        ||(pmass[3]>Mlarge && pmass[2]<Msmall))
           { *(CI->twidth)=1; *(CI->gtwidth)=1;}
      else { *(CI->twidth)=0; *(CI->gtwidth)=0;}
      *(CI->gswidth)=0;
                             
      if(pmass[2]+pmass[3] > pmass[0]+pmass[1])
      { double smin=pmass[2]+pmass[3];
        if((pmass[0]!=M1 || pmass[1]!=M2)&&(pmass[0]!=M2 || pmass[1]!=M1))
        { double ms=pmass[0]+pmass[1];
          double md=pmass[0]-pmass[1];
          double Pcm=sqrt((smin-ms)*(smin+ms)*(smin-md)*(smin+md))/(2*smin);
          smin=sqrt(M1*M1+Pcm*Pcm)+sqrt(M2*M2+Pcm*Pcm);
        }
        u_min=m2u(smin); 
      }else  u_min=0;
      
repeat:
      neg_cs_flag=0;
      if(!Fast) a=simpson(s_integrand,u_min,1.,eps); 
      else if(Fast!=1) a=f[0]*sigma(x[0]); else
      {
          int isPole=0;
          char * s;
          int m,w,n;
          double mass,width;

          for(n=1;(s=code22[k1*NC+k2]->interface->den_info(nsub,n,&m,&w));n++)
          if(m && w && strcmp(s,"\1\2")==0 )
          { mass=code22[k1*NC+k2]->interface->va[m];
            width=code22[k1*NC+k2]->interface->va[w];
            if(mass<MassCutOut && mass+8*width > pmass[0]+pmass[1]
                            && mass+8*width > pmass[2]+pmass[3])
            { if((pmass[0]!=M1 || pmass[1]!=M2)&&(pmass[0]!=M2 || pmass[1]!=M1))
              { double ms=pmass[0]+pmass[1];
                double md=pmass[0]-pmass[1];
                double Pcm=sqrt((mass-ms)*(mass+ms)*(mass-md)*(mass+md))/(2*mass);
                mass=sqrt(M1*M1+Pcm*Pcm)+sqrt(M2*M2+Pcm*Pcm);
              }
              grid1=makeGrid(mass,width);
              if(isPole) grid=crossGrids(&grid,&grid1); else grid=grid1;
              isPole++;
            }
          }
          if(isPole==0)
          {  grid.n=1;
             grid.ul[0]=u_min;
             grid.ur[0]=u_max;
             grid.pow[0]=3;
          }

          if(grid.n==1 && pmass[0]+pmass[1]> 1.1*(pmass[2]+pmass[3]))
                a=f[0]*sigma(x[0])+f[1]*sigma(x[1]);
          else for(i=0;i<grid.n;i++)if(u_min<=grid.ur[i])
          {  
             double ul= u_min<grid.ul[i]? grid.ul[i]:u_min;
             double da=gauss(s_integrand,ul,grid.ur[i],grid.pow[i]);
             a+=da;             
          }
      }
      if(neg_cs_flag && *(CI->gswidth)==0)
      { *(CI->gswidth)=1;
         goto  repeat;
      }   
/* 
printf("X=%.2E (%d) %.3E %s %s %s %s\n",X,everage, a, pname[0],pname[1],pname[2],pname[3]);
*/
      Sumkk+=a;
      if(wPrc) (*wPrc)[nPrc] = a*factor;
    }
    Sum+=factor*Sumkk;
/*
printf("Sum=%E\n",Sum);
*/
  }
  }
  if(wPrc) for(i=0; i<nPrc;i++)  (*wPrc)[i]/=Sum;
  if(!everage) { double gf=geff(X);  Sum/=gf*gf;}
/*
exit(1);
*/
  return Sum;
}


static double Yeq(double X)
{  double heff;
   termod(M/X,NULL,&heff);
   return (45/(4*M_PI*M_PI*M_PI*M_PI))*X*X*
                    geff(X)*sqrt(M_PI/(2*X))*exp(-X)/heff;
}
                          

struct {double*data;double xtop; int pow,size;} vSigmaGrid={NULL,0,0,0}; 

static double darkOmega1(double * Xf,double Z1,double dZ1,int Fast,double Beps)
{
  double X = *Xf;
  double sqrt_gStar;

  double CCX=(Z1-1)*(Z1+1);
  double dCCX=(Z1-1+dZ1)*(Z1+1+dZ1)-CCX;
  double d, dYdX,Yeq0X;
  double dCC,dCC1,dCC2,X1,X2,vSigma,vSigma1,vSigma2;
  double cFactor=sqrt(M_PI/45)*MPlank*M;
  int i;

  if(vSigmaGrid.data==NULL) 
  { vSigmaGrid.data=(double*)malloc(20*sizeof(double));
    vSigmaGrid.size=20; 
  }
    
  sigma= (Fast)?sigma_gauss:sigma_simpson;

  if(Beps>=1) Beps=0.999;

  MassCut=M*(2-log(Beps)/X);
  d=X*0.01; dYdX=(Yeq(X+d)-Yeq(X-d))/(2*d);
  Yeq0X=Yeq(X)/X;
  termod(M/X,&sqrt_gStar,NULL);
  vSigma=aRate(X,0,Fast,NULL); if(FError) return -1;
  if(vSigma ==0) 
  { printf("ERROR:Zero annihilation rate,\n");
    return -1;
  }

  dCC=-CCX-dYdX/(vSigma*cFactor*sqrt_gStar*Yeq0X*Yeq0X);


  vSigmaGrid.data[0]=vSigma;
  vSigmaGrid.xtop=X;
  vSigmaGrid.pow=1;  

  if(fabs(dCC)<dCCX) { *Xf=X; return Yeq(X)*sqrt(1+dCC+CCX);} 
   
  dCC1=dCC;dCC2=dCC;X1=X;X2=X; vSigma1=vSigma;vSigma2=vSigma;
  while(dCC2>0) 
  {  
     X1=X2;
     dCC1=dCC2;
     vSigma1=vSigma2;
     X2=X2/XSTEP;
     X=X2;
     MassCut=M*(2-log(Beps)/X);
     termod(M/X,&sqrt_gStar,NULL);
     d=0.01*X; dYdX= (Yeq(X+d)-Yeq(X-d))/(2*d);
     Yeq0X=Yeq(X)/X;
     vSigma2=aRate(X,0,Fast,NULL); if(FError) return -1;
     dCC2=-CCX-dYdX/(vSigma2*cFactor*sqrt_gStar*Yeq0X*Yeq0X);
     
     if(vSigmaGrid.pow==vSigmaGrid.size)
     { vSigmaGrid.size+=10;
       vSigmaGrid.data=(double*)realloc(vSigmaGrid.data,sizeof(double)*vSigmaGrid.size);
     }       
     for(i=vSigmaGrid.pow;i;i--) vSigmaGrid.data[i]=vSigmaGrid.data[i-1];
     vSigmaGrid.xtop=X; vSigmaGrid.data[0]=vSigma2; vSigmaGrid.pow++;
  }
             
  while (dCC1<0)
  {  
     X2=X1;
     dCC2=dCC1;
     vSigma2=vSigma1;
     X1=X1*XSTEP;
     X=X1;
     MassCut=M*(2-log(Beps)/X);
     termod(M/X,&sqrt_gStar,NULL);
     d=0.01*X; dYdX=(Yeq(X+d)-Yeq(X-d))/(2*d);
     Yeq0X=Yeq(X)/X;
     vSigma1=aRate(X,0,Fast,NULL); if(FError) return -1;
     dCC1=-CCX-dYdX/(vSigma1*cFactor*sqrt_gStar*Yeq0X*Yeq0X);

     if(vSigmaGrid.pow==vSigmaGrid.size)
     { vSigmaGrid.size+=10;
       vSigmaGrid.data=(double*)realloc(vSigmaGrid.data,sizeof(double)*vSigmaGrid.size);
     }       

     vSigmaGrid.data[vSigmaGrid.pow++]=vSigma1; 
  }
            
  for(;;) 
  { 
     if(fabs(dCC1)<dCCX)  { *Xf=X1; return Yeq(X1)*sqrt(1+dCC1+CCX);}
     if(fabs(dCC2)<dCCX)  { *Xf=X2; return Yeq(X2)*sqrt(1+dCC2+CCX);}
                
     X=(X1*dCC2 - X2*dCC1)/(dCC2-dCC1);
     MassCut=M*(2-log(Beps)/X);
     termod(M/X,&sqrt_gStar,NULL);
     d=0.01*X;  dYdX= (Yeq(X+d)-Yeq(X-d))/(2*d);
     Yeq0X=Yeq(X)/X;
     vSigma= (vSigma1*(X2-X) - vSigma2*(X1-X))/(X2-X1);
     dCC=-CCX-dYdX/(vSigma*cFactor*sqrt_gStar*Yeq0X*Yeq0X);
     if(dCC*dCC1>0) {dCC1=dCC;X1=X;vSigma1=vSigma;} else {dCC2=dCC;X2=X;vSigma2=vSigma;}
  }             

}


static void XderivLn(double x, double *Y, double *dYdx)
{
  double y=exp(Y[0]);
  double yeq=Yeq(x);
  double sqrt_gStar;
  int i=log(x/vSigmaGrid.xtop)/log(XSTEP)-0.00001;
  double X1=vSigmaGrid.xtop*pow(XSTEP,i);   double sigmav1=vSigmaGrid.data[i];
  double X2=vSigmaGrid.xtop*pow(XSTEP,i+1); double sigmav2=vSigmaGrid.data[i+1];
  double sigmav;  
  
  sigmav1=log(sigmav1); sigmav2=log(sigmav2);

  if(i>0) 
  { double X0=vSigmaGrid.xtop*pow(XSTEP,i-1); double sigmav0=vSigmaGrid.data[i-1]; 

sigmav0=log(sigmav0);

    sigmav=sigmav0*(x-X1)*(x-X2)/(X0-X1)/(X0-X2)
          +sigmav1*(x-X0)*(x-X2)/(X1-X0)/(X1-X2)
          +sigmav2*(x-X0)*(x-X1)/(X2-X0)/(X2-X1); 
  }else if(i+2<vSigmaGrid.pow)
  { double X0=vSigmaGrid.xtop*pow(XSTEP,i+2); double sigmav0=vSigmaGrid.data[i+2];
sigmav0=log(sigmav0);
    sigmav=sigmav0*(x-X1)*(x-X2)/(X0-X1)/(X0-X2)
          +sigmav1*(x-X0)*(x-X2)/(X1-X0)/(X1-X2)
          +sigmav2*(x-X0)*(x-X1)/(X2-X0)/(X2-X1); 
    
  } else sigmav=(sigmav1*(x-X2)-sigmav2*(x-X1))/(X1-X2);

/*printf("sigmav=%e\n");*/
  
sigmav=exp(sigmav);
  
  termod(M/x,&sqrt_gStar,NULL);

  *dYdx=-(M/x/x)*MPlank*sqrt_gStar*sqrt(M_PI/45)*sigmav*(y-yeq*yeq/y);
  
/*printf("x=%e dydx=%e\n",x,*dYdx);*/

}


double darkOmegaFO(double * Xf_, int Fast, double Beps)
{
  double Yf,Yi;

  double  Z1=2.5;
  double  dZ1=0.05;
  double x;
  double Xf=25;
  if(Xf_) *Xf_=Xf; 

  assignVal("Q",2*M); 
  if(Beps>=1) Beps=0.999;
  Yf=  darkOmega1(&Xf, Z1, dZ1,Fast, Beps); 
  if(Yf<0||FError) return -1;
  x=Xf;
  Yi=1/( (M/x)*sqrt(M_PI/45)*MPlank*aRate(x, 1,Fast, NULL) );
  if(!finite(Yi)||FError)   return -1;
  if(Xf_) *Xf_=Xf; 
  return  2.742E8*M/(1/Yf +  1/Yi); /* 2.828-old 2.755-new 2.742 next-new */
}


double darkOmega(double * Xf, int Fast, double Beps)
{
  double Yt,Yi,Xt=25;
  double Z1=1.1;
  double Z2=10; 
  int i;
  double Xf1;

  if(Xf)*Xf=Xt;
  assignVal("Q",2*M);
  if(Beps>=1) Beps=0.999;
  if(Z1<=1) Z1=1.1;

  fast_=Fast;
  Yt=  darkOmega1(&Xt, Z1, (Z1-1)/5,Fast, Beps); 
  if(Yt<0||FError) return -1;
  Xf1=Xt;
  for(i=0; ;i++)
  { double X2=vSigmaGrid.xtop*pow(XSTEP,i+1);
    double y;

    if(Yt>=Z2*Yeq(Xt))  break;
    
    if(Xt>X2*0.999999) continue; 
    while(vSigmaGrid.pow<=i+1)
    { double X;
      if(vSigmaGrid.pow==vSigmaGrid.size)
      { vSigmaGrid.size+=10;
        vSigmaGrid.data=(double*)realloc(vSigmaGrid.data,sizeof(double)*vSigmaGrid.size);
      } 
     
      X=vSigmaGrid.xtop*pow(XSTEP,vSigmaGrid.pow);
      MassCut=M*(2-log(Beps)/X);      
      vSigmaGrid.data[vSigmaGrid.pow++]=aRate(X,0,Fast,NULL);
      if(FError) return -1;     
    }
    y=log(Yt);
    odeint(&y,1 , Xt , X2 , 1.E-3, (X2-Xt)/2, &XderivLn); 
    Yt=exp(y);
    Xt=X2;
  }
  if(Xf) *Xf=0.5*(Xf1+Xt);

  Yi=1/( (M/Xt)*sqrt(M_PI/45)*MPlank*aRate(Xt,1,Fast,NULL) );
  if(!finite(Yi)||FError)  return -1;

  return  2.742E8*M/(1/Yt  +  1/Yi); /* 2.828-old 2.755-new,2.742 -newnew */
}


double printChannels(double Xf ,double cut, double Beps, int prcn, FILE * f)
{ int i, nsub, l1,l2;
  int nPrc,nform=log10(1/cut)-2;
  float *wPrc;
  double Sum;

  MassCut=M*(2-log(Beps)/Xf);

  Sum=aRate(Xf, 1,1,&wPrc)*(M/Xf)*sqrt(M_PI/45)*MPlank/(2.742E8*M);
  if(FError) return -1;
  if(wPrc==NULL) return 0;
  if(nform<0)nform=0;

  fprintf(f,"\nChannels which contribute to 1/(omega) more than %G%%.\n",100*cut );
  if(prcn) fprintf(f,"Relative contrubutions in %% are displyed\n");
     else  fprintf(f,"Absolut  contrubutions  are  displyed\n");

  for(l1=0,nPrc=0;l1<NC;l1++)
  { int k1=sort[l1]; if(M+inMass[k1]>MassCut) break;
  for(l2=0;l2<NC;l2++)
  {                
    int k2=sort[l2];

    if( inMass[k1]+inMass[k2]>MassCut) break;
    if( inC[k1*NC+k2]<=0) continue;

    for(nsub=1; nsub<=code22[k1*NC+k2]->interface->nprc; nsub++,nPrc++) if(fabs(wPrc[nPrc])>=cut)
    {  char *pname[4];
       for(i=0;i<4;i++)  pname[i]=code22[k1*NC+k2]->interface->pinf(nsub,i+1,NULL,NULL);
       if(prcn)
       { if(cut <0.000001) fprintf(f,"%.1E%% %s %s -> %s %s \n",
                         100*wPrc[nPrc],pname[0],pname[1],pname[2],pname[3]);
         else              fprintf(f,"%*.*f%% %s %s -> %s %s \n",nform+3,nform,
                         100*wPrc[nPrc],pname[0],pname[1],pname[2],pname[3]);
       } else 
        fprintf(f,"%.1E %s %s -> %s %s \n",Sum*wPrc[nPrc],pname[0],pname[1],pname[2],pname[3]);    
    }
  }
  }
  return 1/Sum;
}
double lopmass_(void) {return M;}

void printMasses(FILE * f,int sort)
{
if(f==NULL) return;

fprintf(f,"\nMasses of SuperParticles:\n");
{ int i,col;
  int *n=malloc(sizeof(int)*Nodd);
  int *nn=malloc(sizeof(int)*Nodd);
  double * mass=malloc(sizeof(double)*Nodd);
  int pow;

  for(pow=0,i=0; i<Nodd; i++) 
  { int err;
    double  v=findParam(OddPrtcls[i].mass,&err); 
    if(err==0) mass[i]=fabs(v); else mass[i]=-1;
    n[pow]=i;
    nn[pow]=i;
    pow++;
  }
  if(pow>1)
  for(i=0;i<pow-1;)
  {  int i1=i+1;
     if( mass[n[i]] > mass[n[i1]])
     { int k=n[i]; n[i]=n[i1]; n[i1]=k;
       if(i==0) i++; else i--;
     } else i++;
  }

  for(col=0,i=0;i<pow;i++)
  { int k;
    if(sort)k=n[i];else k=nn[i];
  
    fprintf(f,"%-3.3s : %-6.6s= %7.1f ", OddPrtcls[k].name,
           OddPrtcls[k].mass,mass[k]);
                        
    col++;
    if(f)
    { if(col==1 || col==2) fprintf(f,"|| ");
      if(col==3) { col=0; fprintf(f,"\n");}
    }
  }
  fprintf(f,"\n");
  free(n); free(nn); free(mass);

}
}
