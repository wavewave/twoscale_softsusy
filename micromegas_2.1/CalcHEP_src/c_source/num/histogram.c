/*
 Copyright (C) 1997, 2006 Alexander Pukhov
*/

#include"syst.h"
#include"histogram.h"
#include"crt_util.h"
#include"edittab.h"
#include"syst.h"
#include"read_func.h"
#include"rd_num.h"
#include"interface.h"
#include"plot.h"
#include"subproc.h" 
#include"phys_val.h"


table histTab={"*** Table ***","Distributions",
                   "Parameter_1|> Min_1  <|> Max_1  <|"
                   "Parameter_2|> Min_2  <|> Max_2  <|",NULL};
                   
typedef  struct  histRec 
{ struct histRec * next;
  linelist  mother;
  long  nPoints;
  char key[2];               
  char plist[2][10];
  double hMin[2],hMax[2];
  float f[900];
  float ff[900];   
} histRec;

static histRec * histPtr=NULL;

int clearHists(void)
{ histRec * hists=histPtr;
  int i;
  if(histPtr==NULL) return 0;
  while(hists)
  { 
    for(i=0;i<900;i++){hists->f[i]=0;hists->ff[i]=0;}
    hists->nPoints=0; 
    hists=hists->next;
  }
  return 1;
}



void  fillHists(double w)
{ histRec * hists=histPtr;
  int i,j;
  double z1,z2;   
  for(;hists;hists=hists->next)
  { 
    z1=calcPhysVal(hists->key[0],hists->plist[0]);       
    if( z1<=hists->hMin[0] || z1>=hists->hMax[0]) continue; 
    if(hists->key[1]=='0')
    {     
      i=300*(z1 - hists->hMin[0])/(hists->hMax[0] - hists->hMin[0]);    
      hists->f[i]+=w;
      hists->ff[i]+=w*w;    
    }else
    {  
      z2=calcPhysVal(hists->key[1],hists->plist[1]);
      if( z2<=hists->hMin[1] || z2>=hists->hMax[1]) continue;
      i=30*(z1-hists->hMin[0])/(hists->hMax[0]-hists->hMin[0]);    
      j=30*(z2-hists->hMin[1])/(hists->hMax[1]-hists->hMin[1]);
      hists->f[30*i+j]+=w;
      hists->ff[30*i+j]+=w*w;
    }          
    hists->nPoints++;   
  }
}


int correctHistList(void)
{ 
   linelist ln=histTab.strings;
   int lineNum=0;
   int i;
   char keyChar[2];
   double rMin[2]={0.,0.}, rMax[2]={0.,0.};
   char  histStr[2][STRSIZ], minStr[2][STRSIZ], maxStr[2][STRSIZ];
   char fieldName[50];    
   histRec * hptr = histPtr;

   for( ;hptr;hptr=hptr->next) hptr->mother=NULL;
   while(ln)
   {
      char lv[2][10]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
      for(i=0;i<2;i++){histStr[i][0]=0;minStr[i][0]=0;histStr[i][0]=0;}
      sscanf(ln->line,"%[^|]%*c%[^|]%*c%[^|]%*c%[^|]%*c%[^|]%*c%[^\n]%",
              histStr[0],minStr[0],maxStr[0],histStr[1],minStr[1],maxStr[1]);            
      lineNum++;

      for(i=0;i<2;i++)
      {
        trim(minStr[i]);trim(histStr[i]);trim(maxStr[i]);
/*============ Parameter ===========*/
        sprintf(fieldName,"Wrong field 'Parameter.%d'",i+1);
        if(histStr[i][0]==0) 
            { if(i==0) goto errorExit; else keyChar[i]='0'; continue; }
        if(! checkPhysVal(histStr[i], &keyChar[i],lv[i])) goto errorExit;
/*================ MIN bound ============*/
        sprintf(fieldName,"Wrong field 'Min.%d bound'",i+1);
        if (!minStr[i][0]|| calcExpression(minStr[i],rd_num,&rMin[i] ))  goto errorExit;
/*================== MAX bound ==========*/
        sprintf(fieldName,"Wrong field 'Max.%d bound'",i+1);
        if(!maxStr[i][0] ||calcExpression(maxStr[i],rd_num,&rMax[i] ))  goto errorExit;
        if(rMax[i]<rMin[i]){ double tmp=rMax[i]; rMax[i]=rMin[i]; rMin[i]=tmp;}
      }
      
      for(hptr = histPtr; hptr; hptr=hptr->next)
      { if(hptr->key[0]==keyChar[0] && !strcmp(lv[0],hptr->plist[0])
                  &&hptr->hMin[0]==rMin[0]&&hptr->hMax[0]==rMax[0]
         &&hptr->key[1]==keyChar[1]&& !strcmp(lv[1],hptr->plist[1])
                  &&hptr->hMin[1]==rMin[1]&&hptr->hMax[1]==rMax[1] 
         &&hptr->mother==NULL) 
         {  
            hptr->mother=ln;
            goto cont;  
         } 
      }
      hptr=malloc(sizeof(histRec));
      hptr->next=histPtr;
      hptr->mother=ln;
      histPtr=hptr;
      for(i=0;i<2;i++)
      { hptr->key[i]=keyChar[i];
        strcpy(hptr->plist[i],lv[i]);
        hptr->hMin[i]=rMin[i]; 
        hptr->hMax[i]=rMax[i];
      }  
      for(i=0;i<900;i++) {hptr->f[i]=0; hptr->ff[i]=0;}
      hptr->nPoints=0;
      cont: 
      ln=ln->next;
   }      
   hptr = histPtr; 
   histPtr=NULL;  
   while(hptr) 
   { histRec *  hptr_=hptr;
     hptr=hptr->next;
     if(!hptr_->mother) free(hptr_); else {hptr_->next=histPtr; histPtr=hptr_;}
   }
   return 0;
   errorExit:
      sprintf(errorText," Error in  line %d .\n"
                         "%s.",lineNum,fieldName);
      messanykey(2,10,errorText);
      return 1;
}

static void writeDistributions(FILE*iprt)
{
  histRec * hists=histPtr;
  int i,k;
  linelist rec;
  
  for(rec=histTab.strings;rec;rec=rec->next)
  {
     for(hists=histPtr;hists;hists=hists->next) if(hists->mother == rec) 
     {  int Nprint;
        fprintf(iprt, " nPoints=%d ",hists->nPoints);
        for(i=0;i<2;i++) 
        {  fprintf(iprt, " key=%c",hists->key[i]);
           for(k=0;k<10 && hists->plist[i][k];k++) fprintf(iprt, "%d",hists->plist[i][k]); 
           fprintf(iprt," hMin=%-12E hMax=%-12E",hists->hMin[i],hists->hMax[i]); 
        }
        if(hists->key[1]=='0') Nprint=300; else Nprint=900;
        fprintf(iprt,"\n  f: ");   
        for(i=0;i<Nprint;i++) fprintf(iprt," %-12E", hists->f[i]); 
        fprintf(iprt,"\n ff: ");
        for(i=0;i<Nprint;i++) fprintf(iprt," %-12E",hists->ff[i]);
     }
     fprintf(iprt,"\n");
  } 
}


static void readDistributions(FILE*iprt)
{
  int i,k;
  linelist rec;
  for(rec=histTab.strings;rec;rec=rec->next)
  {  int Nread; 
     histRec * hist=malloc(sizeof(histRec));

     hist->next=histPtr;
     hist->mother=rec;
     histPtr=hist;
     
     fscanf(iprt, " nPoints=%ld",&(hist->nPoints));
     
     for(i=0;i<2;i++)
     { fscanf(iprt," key=%c",&(hist->key[i]));
       for(k=0;k<10 ;k++) 
       { 
         fscanf(iprt, "%c",hist->plist[i]+k);
         if(hist->plist[i][k]==' ') { hist->plist[i][k]=0; break;} else
         hist->plist[i][k] -= '0';
       } 
     
       fscanf(iprt,"hMin=%lf hMax=%lf\n",&(hist->hMin[i]),&(hist->hMax[i]));
     }
    
     if(hist->key[1]=='0') Nread=300; else Nread=900;     
     fscanf(iprt,"  f: ");
     for(i=0;i<Nread;i++) fscanf(iprt," %f",hist->f+i); 
     fscanf(iprt," ff: ");
     for(i=0;i<Nread;i++) fscanf(iprt," %f",hist->ff+i);
     for(;i<900;i++){ hist->f[i]=0; hist->ff[i]=0;}
  } 
}


int wrt_hist(FILE *nchan)
{  fprintf(nchan,"\n"); 
   writetable0(&histTab,nchan); 
   writeDistributions(nchan);
   return 0;
}

int rdr_hist(FILE *nchan)
{  fscanf(nchan,"\n"); 
   readtable0(&histTab,nchan);   
   readDistributions(nchan);
   return 0;
}


int wrt_hist2(FILE *nchan, char * comment)
{  if(comment) fprintf(nchan,"%s\n",comment); else  fprintf(nchan,"\n"); 
   writetable0(&histTab,nchan); 
   writeDistributions(nchan);
   return 0;
}


int rdr_hist2(FILE *nchan, char *comment)
{  if(comment) fscanf(nchan,"%[^\n]\n",comment); else fscanf(nchan,"%*[^\n]\n"); 
   if(readtable0(&histTab,nchan)) return 1;
   readDistributions(nchan);
   return 0;
}


static int strcmp2(char*c1,char*c2)
{ 
  for(;;) if(*c1==' ') c1++;
  else    if(*c2==' ') c2++;
  else    if(*c1==*c2){if(*c1) { c1++; c2++;} else return 0;}
  else    return *c1-*c2; 
}


int add_hist(FILE *f, char *procname)
{  
  table histTab2=histTab;
  histRec * histPtr2=histPtr;
  histRec *r,*r2;
  char procname2[100], *out,*out2;
  int err=0; 
  histPtr=NULL;
  histTab.strings=NULL;

  err=rdr_hist2(f,procname2);

  if(err) return err;

  if(!histPtr2){ strcpy(procname,procname2); return 0; }
    
  out=strstr(procname,"->"); out2=strstr(procname2,"->");
  if(out==NULL || out2==NULL) err=4; 
  else if(strcmp2(out,out2))  err=3;
  else 
  {  char instr[100],instr2[100],*c,*c2;
     int l=out-procname;  
     strncpy(instr,procname,l); instr[l]=0;
     l=out2-procname2;
     strncpy(instr2,procname2,l); instr2[l]=0;

     c=strchr(instr,','); if(c) {c[0]=0; c++;}
     c2=strchr(instr2,','); if(c2){ c2[0]=0; c2++;}
     if((!c)&&(!c2)){ if(strcmp2(instr,instr2)) sprintf(procname,"pX1%s",out);}
     else if(c&&c2) 
     { char *n1="pX1";
       char *n2="pX2";

       if(strcmp2(instr,instr2)==0) n1=instr; 
       if(strcmp2(c,c2)==0) n2=c;

       sprintf(procname,"%s,%s%s",n1,n2,out2);
     } else err=3;   
  }


  if(err==0)
  {
     for(r2=histPtr2;r2;r2=r2->next) for(r=histPtr;r;r=r->next)
     if(strcmp2(r->mother->line,r2->mother->line)==0) 
     { int i;
       double n1=r->nPoints;
       double n2=r2->nPoints;
       double n=n1+n2;
       int Ntot;
       
       if(r->key[1]=='0') Ntot=300; else Ntot=900;
       for(i=0;i<Ntot;i++) 
       {   
           r2->ff[i]=(n/n1)*(n/n1)*(r->ff[i]  
             - r->f[i]*r->f[i]/n1 )+
                     (n/n2)*(n/n2)*(r2->ff[i] 
                     - r2->f[i]*r2->f[i]/n2);
           r2->f[i]=(n/n1)*r->f[i]+(n/n2)*r2->f[i];
           r2->ff[i]+=(r2->f[i])*(r2->f[i])/n;
        }
       r2->nPoints+=r->nPoints;;
  
     }
  }

  cleartab(&histTab);
  histTab=histTab2;

  while(histPtr){r=histPtr->next; free(histPtr); histPtr=r;}
  histPtr=histPtr2;
  return err;
}


static int nBinMenu(int X, int Y)
{                   

static int kBinMenu=3;
char   strmen[] =
   "\015"
   " 300         "
   " 150         "
   " 100         "
   "  75         "
   "  60         "
   "  50         "
   "  30         " 
   "  25         "
   "  20         "
   "  15         "
   "  12         "
   "  10         "
   "  6          "
   "  5          "
   "  4          "
   "  3          "
   "  2          ";

   void * pscr=NULL;
   
   int n;
   if(!kBinMenu) kBinMenu=3;
           
   menu1(X,Y,"number of bins",strmen,"",&pscr,&kBinMenu);
   if (kBinMenu)
   {
     sscanf(strmen+1+strmen[0]*(kBinMenu-1),"%d",&n);
     put_text(&pscr);
     return n;
   }
   return 0;
}

static int  nBinMenu2(int X, int Y, int*nb1, int*nb2)
{                   

static int nb1_=3, nb2_=3;
char   strmen[] =
   "\011"
   " 30      "
   " 15      "
   " 10      "
   "  6      "
   "  5      "
   "  3      "
   "  2      "
   "  1      ";

   void * pscr1=NULL;
   void * pscr2=NULL;

   if(!nb1_) nb1_=3;
   if(!nb2_) nb2_=3;
 
   menu1(X,Y,"N bin1",strmen,"",&pscr1,&nb1_);
   if (nb1_)
   {
     sscanf(strmen+1+strmen[0]*(nb1_-1),"%d",nb1);
     menu1(X+13,Y,"N bin2",strmen,"",&pscr2,&nb2_);
     put_text(&pscr1);
     if (nb2_) 
     { sscanf(strmen+1+strmen[0]*(nb2_-1),"%d",nb2); 
       put_text(&pscr2);
       return 1;
     }
   }
   return 0;
}



void showHist(int X, int Y)
{
   char  histStr1[STRSIZ],histStr2[STRSIZ];
   linelist ln=histTab.strings;
   char * menutxt;
   void * pscr=NULL;
   int mode =0;
   char procName[60];
   int npos=0;
   int width;
   int i,j;
   
   for(i=0,j=0;proces_1.proces[i];i++) 
      if(proces_1.proces[i]!='%') procName[j++]=proces_1.proces[i];
   procName[j]=0;
   
   while(ln)
   {  npos++;
      ln=ln->next;     
   }
   if(!npos) return; 

   sscanf(histTab.format,"%[^|]|%*[^|]|%*[^|]|%[^|]",histStr1,histStr2);   
   width=strlen(histStr1)+strlen(histStr2)+1;
   menutxt=malloc(2+width*npos);
   menutxt[0]=width;
   menutxt[1]=0;
   
   ln=histTab.strings;
   while(ln)
   {  
      sscanf(ln->line,"%[^|]|%*[^|]|%*[^|]|%[^|]",histStr1,histStr2);
      strcat(menutxt,histStr1);
      strcpy(histStr1,histStr2);
      trim(histStr1);
      if(histStr1[0]==0) strcat(menutxt," "); else strcat(menutxt,"|"); 
      strcat(menutxt,histStr2); 
      ln=ln->next;
   }
   
   for(;;)
   {  
      menu1(X,Y,"Distributions",menutxt,"",&pscr,&mode);

      switch(mode)
      {
      case 0: free(menutxt);return;
      default: 
      {  histRec * hist=histPtr;
         int nBin1,nBin2;
         ln=histTab.strings;
         for(npos=1;npos<mode;npos++) ln=ln->next; 
         for( ;hist && hist->mother!= ln;hist=hist->next){;}
         if(hist)
         {  
            char xname[80],yname[80],units[80];                                    
                                                                                   
            if( hist->nPoints == 0) messanykey(10,10,"Distibution is empty");     
            else
            if(hist->key[1]=='0')
            while(nBin1=nBinMenu(X,Y+4))                                                                   
            {  double f[300],df[300],coeff;                                        
               int i;
               coeff=nBin1/(hist->nPoints*(hist->hMax[0] - hist->hMin[0]));               

               for(i=0;i<nBin1;i++)                                                 
               {  int k;                                                           
                  f[i]=0;                                                          
                  df[i]=0;                                                         
                  for(k=0;k<300/nBin1;k++)                                          
	          {  f[i] += coeff*hist->f[i*300/nBin1+k];            
                    df[i] += coeff*coeff*hist->ff[i*300/nBin1+k];                   
                  }                                                                
                  df[i]=sqrt(df[i] - f[i]*f[i]/hist->nPoints);                      
               }                                                                                   
               if(nin_int==2) strcpy(yname,"Diff. cross section [pb");                 
               else       strcpy(yname,"Diff. width [GeV");                        
               xName(hist->key[0],hist->plist[0],xname,units);                           
               if(units[0]) { strcat(yname,"/");strcat(yname,units);}              
               strcat(yname,"]");                                                  
                                                                                   
               plot_1(hist->hMin[0],hist->hMax[0],nBin1,f,df,procName,xname,yname);       
            } else
            while(nBinMenu2(X,Y+4,&nBin1,&nBin2))                                                                   
            {  double f[900],df[900],coeff;                                        
               int i,j;                     
               coeff=nBin1*nBin2/(hist->nPoints*(hist->hMax[0]-hist->hMin[0])
                                               *(hist->hMax[1]-hist->hMin[1]));               

               for(i=0;i<nBin1;i++)  for(j=0;j<nBin2;j++)
               {  int k,l,pos;
                  pos=i*nBin2+j;                                                           
                  f[pos]=0;                                                          
                  df[pos]=0;                                                         
                  for(k=0;k<30/nBin1;k++) for(l=0;l<30/nBin2;l++)                                         
	          {  f[pos] += coeff*hist->f[30*(i*30/nBin1+k)+j*30/nBin2+l];
                    df[pos] += coeff*coeff*hist->ff[30*(i*30/nBin1+k)+j*30/nBin2+l];                   
                  }
                  df[pos]=sqrt(df[pos] - f[pos]*f[pos]/hist->nPoints);                      
               }                                                                                                                  
               xName(hist->key[0],hist->plist[0],xname,units);
               xName(hist->key[1],hist->plist[1],yname,units);                           
               if(units[0]) { strcat(yname,"/");strcat(yname,units);}                                                          
                                                                                   
               plot_2(hist->hMin[0],hist->hMax[0],nBin1,
                      hist->hMin[1],hist->hMax[1],nBin2,
                       f,df,procName,xname,yname);       
            }                                                                                  
         }
      }       
      }
   }
}

void editHist(void) {do  edittable(1,4,&histTab,1,"n_distrib",0); while(correctHistList());} 


