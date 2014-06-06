#include"pmodel.h"
#include"pmodel_aux.h"
#include"pmodel_f.h"
#include"../../sources/micromegas.h"

#include <ctype.h>
#include <stdio.h>

static int delFilesKey=1;
int getdelfilesstat_(void) {return delFilesKey;}
void delFiles(int x)  { delFilesKey=x; }
void delfiles_(int *x){ delFilesKey=*x;}

static double findX0(int NX,double x0, double x1, double x2, double x3, double x4, double x5,
                            double x6, double x7, double x8, double x9, double x10,double x11)
{
   double X[12],Y[12],Xav,dX;
   int pow[12],maxPow,pos;
   int i,j,N;
  
   X[0]=x0;  X[1]=x1;  X[2]=x2;  X[3]=x3;  X[4]=x4;  X[5]=x5;  
   X[6]=x6;  X[7]=x7;  X[8]=x8;  X[9]=x9;  X[10]=x10;X[11]=x11;
  
   for(i=0,Xav=0;i<12;i++) {pow[i]=0; Xav+=X[i];}
   Xav/=NX;
   for(i=0,N=0;i<NX;i++)
   {
     for(j=0;j<N;j++) if(Y[j]==X[i]) { pow[j]++; break;}
     if(j==N) {Y[N]=X[i];pow[N]=1;N++;}  
   }
   
   pos=0;maxPow=pow[0];dX=fabs(Xav-Y[0]);
   
   for(i=1;i<N;i++)
   if(pow[i]>maxPow){ pos=i;maxPow=pow[i]; dX=fabs(Xav-Y[i]);}
   else if(pow[i]==maxPow && dX>fabs(Xav-Y[i])) {pos=i; dX=fabs(Xav-Y[i]);}
   
   return Y[pos];
}



int sugraLesH(char *fname,  double tb, double gMG1,double gMG2,double gMG3,
    double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
    double gMl2,double gMl3,double gMr2,double gMr3,
    double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3) 
{  double m0,mh,a0, m0_,mh_,a0_;
   double c=1.E-8;
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;
   
   fprintf(f,"Block MODSEL                 # Select model\n"   
           " 1    1                      # sugra\n"
           "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5); 
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));
   fprintf(f,"Block MINPAR                 # Input parameters\n");
   
   a0=findX0(3,gAl, gAt, gAb, 0,0,0,0,0,0,0,0,0);
   mh=findX0(3,gMG1,gMG2,gMG3,0,0,0,0,0,0,0,0,0); 
   m0=findX0(12,gMHu,gMHd,gMl2,gMl3,gMr2,gMr3,gMq2,gMq3,gMu2,gMu3,gMd2,gMd3);
   if(m0<0) m0=-m0;
   
   a0_=fabs(a0)*c;
   m0_=fabs(m0)*c;
   mh_=fabs(mh)*c;    

   fprintf(f," 1   %.8E       # m0\n",       m0); 
   fprintf(f," 2   %.8E       # m1/2\n",     mh);   
   fprintf(f," 3   %.8E       # tanb\n",     tb);
   fprintf(f," 4   %.0f     # sign(mu)\n", sgn);
   fprintf(f," 5   %.8E       # A0\n",       a0);


   fprintf(f,"Block EXTPAR\n");


   if(fabs(mh-gMG1)>mh_)  fprintf(f," 1   %.8E      # MG1\n",  gMG1);
   if(fabs(mh-gMG2)>mh_)  fprintf(f," 2   %.8E      # MG2\n",  gMG2);
   if(fabs(mh-gMG3)>mh_)  fprintf(f," 3   %.8E      # MG3\n",  gMG3);

   if(fabs(a0-gAt)>a0_)   fprintf(f," 11  %.8E      # At \n",  gAt);
   if(fabs(a0-gAb)>a0_)   fprintf(f," 12  %.8E      # Ab \n",  gAb);
   if(fabs(a0-gAl)>a0_)   fprintf(f," 13  %.8E      # Al\n", gAl);

   if(fabs(m0-gMHd)>m0_) fprintf(f," 21  %.8E      # MHd^2\n",gMHd*fabs(gMHd));
   if(fabs(m0-gMHu)>m0_) fprintf(f," 22  %.8E      # MHu^2\n",gMHu*fabs(gMHu));

   if(fabs(m0-gMl2)>m0_) {fprintf(f," 31  %.8E      # Ml1\n",  gMl2);
                          fprintf(f," 32  %.8E      # Ml2\n",  gMl2);}
   if(fabs(m0-gMl3)>m0_)  fprintf(f," 33  %.8E      # Ml3\n",  gMl3);
   if(fabs(m0-gMr2)>m0_) {fprintf(f," 34  %.8E      # MR1\n",  gMr2);
                          fprintf(f," 35  %.8E      # MR2\n",  gMr2);}
   if(fabs(m0-gMr3)>m0_)  fprintf(f," 36  %.8E      # MR3\n",  gMr3);

   if(fabs(m0-gMq2)>m0_) {fprintf(f," 41  %.8E      # Mq1\n",  gMq2);
                          fprintf(f," 42  %.8E      # Mq2\n",  gMq2);}
   if(fabs(m0-gMq3)>m0_)  fprintf(f," 43  %.8E      # Mq3\n",  gMq3);
   if(fabs(m0-gMu2)>m0_) {fprintf(f," 44  %.8E      # Mu1\n",  gMu2);
                          fprintf(f," 45  %.8E      # Mu2\n",  gMu2);}
   if(fabs(m0-gMu3)>m0_)  fprintf(f," 46  %.8E      # Mu3\n",  gMu3);
   if(fabs(m0-gMd2)>m0_) {fprintf(f," 47  %.8E      # Md1\n",  gMd2);
                          fprintf(f," 48  %.8E      # Md2\n",  gMd2);}
   if(fabs(m0-gMd3)>m0_)  fprintf(f," 49  %.8E      # Md3\n",  gMd3);
   fclose(f);
   assignValW("tb",tb);
   return 0;
}



int amsbLesH(char * fname, double m0,double m32, double  tb, int  sgn)
{
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;

   fprintf(f,"Block MODSEL                 # Select model\n"
             " 1    3                      # amsb\n"
             "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5);
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));

   fprintf(f,"Block MINPAR                 # Input parameters\n");
   fprintf(f," 1   %.8E       # m0\n",       m0);    
   fprintf(f," 2   %.8E       # m3/2\n",     m32);
   fprintf(f," 3   %.8E       # tanb\n",     tb);
   fprintf(f," 4   %d         # sign(mu)\n", sgn);
   fclose(f);
   assignValW("tb",tb);
   return 0;
}

int gmsbLesH(char *fname, double L, double Mmess, double tb, int sgn,int  N5, double cGrav)
{
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;
   fprintf(f,"Block MODSEL                 # Select model\n"
             " 1    3                      # gmsb\n"
             "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5);
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f,"Block MINPAR                 # Input parameters\n");
   fprintf(f," 1   %.8E       # Scale \n",   L);    
   fprintf(f," 2   %.8E       # Mmess\n",    Mmess);
   fprintf(f," 3   %.8E       # tanb\n",     tb);
   fprintf(f," 4   %d         # sign(mu)\n", sgn);
   fprintf(f," 5   %d         # index\n",    N5);
   fprintf(f," 6   %.8E       # cGrav\n",    cGrav);
   fclose(f);
   assignValW("tb",tb);
   return 0;
}

int EWSBLesH(char * fname)
{  
   int i;
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;
                                    
   fprintf(f,"Block MODSEL                 # Select model\n"   
           " 1    0                        # Low energy MSSM\n"
           "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5); 
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));

   fprintf(f,"Block MINPAR                 # Input parameters\n");
   fprintf(f," 3   %.8E       # tanb\n",     findValW("tb"));

   fprintf(f,"Block EXTPAR\n");
   fprintf(f," 0   -1        # EWSB\n"); 
   fprintf(f," 1   %.8E      # MG1\n",findValW("MG1"));
   fprintf(f," 2   %.8E      # MG2\n",findValW("MG2"));
   fprintf(f," 3   %.8E      # MG3\n",findValW("MG3"));

   fprintf(f," 11  %.8E      # At \n",findValW("At"));
   fprintf(f," 12  %.8E      # Ab \n",findValW("Ab"));
   fprintf(f," 13  %.8E      # Atau\n",findValW("Al"));
         
   fprintf(f," 23  %.8E      # mu\n",findValW("mu"));
/*   fprintf(f," 24  %.8E      # MA\n",findValW("MH3"));   */
   fprintf(f," 26  %.8E      # MA\n",findValW("MH3"));
   fprintf(f," 31  %.8E      # Ml1\n",findValW("Ml2"));
   fprintf(f," 32  %.8E      # Ml2\n",findValW("Ml2")); 
   fprintf(f," 33  %.8E      # Ml3\n",findValW("Ml3"));
   fprintf(f," 34  %.8E      # MR2\n",findValW("Mr2"));
   fprintf(f," 35  %.8E      # MR2\n",findValW("Mr2")); 
   fprintf(f," 36  %.8E      # MR3\n",findValW("Mr3"));

   fprintf(f," 41  %.8E      # Mq1\n",findValW("Mq2"));
   fprintf(f," 42  %.8E      # Mq2\n",findValW("Mq2")); 
   fprintf(f," 43  %.8E      # Mq3\n",findValW("Mq3"));
   fprintf(f," 44  %.8E      # Mu1\n",findValW("Mu2"));
   fprintf(f," 45  %.8E      # Mu2\n",findValW("Mu2")); 
   fprintf(f," 46  %.8E      # Mu3\n",findValW("Mu3"));
   fprintf(f," 47  %.8E      # Md1\n",findValW("Md2"));
   fprintf(f," 48  %.8E      # Md2\n",findValW("Md2")); 
   fprintf(f," 49  %.8E      # Md3\n",findValW("Md3"));
   fclose(f);
   return 0;
}



static int nfscanf(FILE*f,int *n1, int*n2, double* val )
{  
  long pos=ftell(f);
  for(;;)
  { char c;
    int r;

    
    fscanf(f,"%c",&c);
    
    if(c=='#') 
    { 
      do{ r=fscanf(f,"%c",&c);} while( r==1 && c!='\n');   
      if( r!=1 ) return r;
      continue;
    }
    else if(c==' ') 
    {
       if(val)
       {
         if(n1&&n2) r=fscanf(f,"%d %d %lf%*[^\n]",n1,n2,val);
         else if(n1)r=fscanf(f,"%d %lf%*[^\n]",n1,val);
         else r=fscanf(f,"%lf%*[^\n]",val);
       } else    r=fscanf(f,"%d%*[^\n]",n1);  
       fscanf(f,"%c",&c); 
       return r;
    }else
    { fseek(f,pos,SEEK_SET); 
      return 0;    
    }
  }  
}

int readLesH(char *fname, int SMplus)
{
  FILE *f;
  char buff[100], name[20];
  int n1,n2,i,err=-4;
  double val;
  char Zf[3][3]={"Zb","Zt","Zl"};
  int MG1ok=0, MG2ok=0, AmOK=0,AuOK=0,AdOK=0;

  f=fopen(fname,"r");
  if(f==NULL) return -2;
  for(;;) 
  { if(fscanf(f,"%s", buff)== EOF) break; 
    if(buff[0]=='#') { fscanf(f,"%*[^\n]\n"); continue;}
    for(i=0;buff[i];i++) buff[i]=toupper(buff[i]);
    if(strcmp(buff,"BLOCK")==0)
    { char rest[200];
      char *c;
      fscanf(f,"%s",buff);
      if(fscanf(f,"%[^\n]",rest))
      { c=strchr(rest,'#');
        if(c) c[0]=0;
        c=strchr(rest,'=');
        if(c && 1==sscanf(c+1,"%lf",&val))assignValW("QSUSY",val);
      } 
      fscanf(f,"%*c");       
      
      for(i=0;buff[i];i++) buff[i]=toupper(buff[i]); 
      if(strcmp(buff,"MASS")==0)
      {  
         for(;nfscanf(f,&n1,NULL,&val)==2;)
         {  
         switch(n1)
         {
           case         24   : break; assignValW("MW",   val);   /* MW*/
           case         25   : assignValW("Mh",   val); break;  /* h0*/
           case         35   : assignValW("MHH",  val); break;  /* H0*/
           case         36   : assignValW("MH3",  val); break;  /* A0*/
           case         37   : assignValW("MHc",  val); break;  /* H+*/
           case    1000001   : assignValW("MSdL",val);  break;  /* ~d_L*/
           case    1000002   : assignValW("MSuL",val);  break;  /* ~u_L*/
           case    1000003   : assignValW("MSsL",val);  break;  /* ~s_L*/
           case    1000004   : assignValW("MScL",val);  break;  /* ~c_L*/
           case    1000005   : assignValW("MSb1",val);  break;  /* ~b_1*/
           case    1000006   : assignValW("MSt1",val);  break;  /* ~t_1*/
           case    1000011   : assignValW("MSeL",val);  break;  /* ~e_L*/
           case    1000012   : assignValW("MSne",val);  break;  /* ~nue_L*/
           case    1000013   : assignValW("MSmL",val);  break;  /* ~mu_L*/
           case    1000014   : assignValW("MSnm",val);  break;  /* ~numu_L*/
           case    1000015   : assignValW("MSl1",val);  break;  /* ~stau_1*/
           case    1000016   : assignValW("MSnl",val);  break;  /* ~nu_tau_L*/
           case    1000021   : assignValW("MSG", val);  break;  /* ~g*/
           case    1000022   : assignValW("MNE1",val);  break;  /* ~neutralino(1)*/
           case    1000023   : assignValW("MNE2",val);  break;  /* ~neutralino(2)*/
           case    1000024   : assignValW("MC1", val);  break;  /* ~chargino(1)*/
           case    1000025   : assignValW("MNE3",val);  break;  /* ~neutralino(3)*/
           case    1000035   : assignValW("MNE4",val);  break;  /* ~neutralino(4)*/
           case    1000037   : assignValW("MC2", val);  break;  /* ~chargino(2)*/
           case    2000001   : assignValW("MSdR",val);  break;  /* ~d_R*/
           case    2000002   : assignValW("MSuR",val);  break;  /* ~u_R*/
           case    2000003   : assignValW("MSsR",val);  break;  /* ~s_R*/
           case    2000004   : assignValW("MScR",val);  break;  /* ~c_R*/
           case    2000005   : assignValW("MSb2",val);  break;  /* ~b_2*/
           case    2000006   : assignValW("MSt2",val);  break;  /* ~t_2*/
           case    2000011   : assignValW("MSeR",val);  break;  /* ~e_R*/
           case    2000013   : assignValW("MSmR",val);  break;  /* ~mu_R*/
           case    2000015   : assignValW("MSl2",val);  break;  /* ~stau_2*/
         }
         }
      }   
      else if(strcmp(buff,"ALPHA")==0)
          { nfscanf(f,NULL,NULL,&val); assignValW("alpha",val); }
      else if(strcmp(buff,"HMIX")==0) while(2==nfscanf(f,&n1,NULL,&val))    
          switch(n1)
          { case 1: assignValW("mu",val);  break; 
            case 2: assignValW("tb_Q",val);break;
            case 3: assignValW("vev",val); break;
            case 4: assignValW("mA_2",val); break;
          }
      else if(strcmp(buff,"STOPMIX")==0)  while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zt%d%d",n1,n2); assignValW(name,val);}
      else if(strcmp(buff,"SBOTMIX")==0)  while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zb%d%d",n1,n2); assignValW(name,val);} 
      else if(strcmp(buff,"STAUMIX")==0)  while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zl%d%d",n1,n2); assignValW(name,val);} 
      else if(strcmp(buff,"NMIX")==0)     while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zn%d%d",n1,n2); assignValW(name,val);} 
      else if(strcmp(buff,"UMIX")==0)     while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zu%d%d",n1,n2); assignValW(name,val);}  
      else if(strcmp(buff,"VMIX")==0)     while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zv%d%d",n1,n2); assignValW(name,val);}  
      else if(strcmp(buff,"AU")==0)       while(3==nfscanf(f,&n1,&n2,&val))
          {       if(n1==3 && n2==3) assignValW("At",val);
             else if(n1==2 && n2==2) {assignValW("Au",val); AuOK=1;} 
          } 
      else if(strcmp(buff,"AD")==0)       while(3==nfscanf(f,&n1,&n2,&val))
          {      if(n1==3 && n2==3) assignValW("Ab",val);
            else if(n1==2 && n2==2) {assignValW("Ad",val); AdOK=1;} 
          } 
      else if(strcmp(buff,"AE")==0)       while(3==nfscanf(f,&n1,&n2,&val)) 
          {      if(n1==3 && n2==3) assignValW("Al",val);
            else if(n1==2 && n2==2) {assignValW("Am",val); AmOK=1;}
          }
      else if(strcmp(buff,"SMINPUTS")==0 && SMplus) while(2==nfscanf(f,&n1,NULL,&val))
           switch(n1)
           { case 1: assignValW("alfEMZ", 1/val); break;
             case 3: assignValW("alfSMZ",val); break;
             case 4: assignValW("MZ",val); break;
             case 5: assignValW("MbMb",val); break;
             case 6: assignValW("Mtp",val); break;  
             case 7: assignValW("Ml",val); break; 
           }
      else if(strcmp(buff,"MINPAR")==0 && SMplus) while(2==nfscanf(f,&n1,NULL,&val))
           { if(n1==3) assignValW("tb", val); }   
      else if(strcmp(buff,"SPINFO")==0) 
           {if(err==-4) err=0;
             while(1==nfscanf(f,&n1,NULL,NULL))
            { if(n1==3 && err==0) err=1; else if(n1==4) err=-1;}
           }  
      else if(strcmp(buff,"MSOFT")==0)  
            while(2==nfscanf(f,&n1,NULL,&val)) 
            switch(n1) 
            {  
             case  1: assignValW("MG1",val); 
                                  MG1ok=1;    break; /*  M_1(Q)  */
             case  2: assignValW("MG2",val); 
                                  MG2ok=1;    break; /*  M_2(Q)  */
             case  3: assignValW("MG3",val);  break; /*  M_3(Q)  */
             case 21: assignValW("mH1_2",val);break; /*  mH1^2(Q)  */
             case 22: assignValW("mH2_2",val);break; /*  mH2^2(Q)  */
             case 31: assignValW("Ml1",val);  break; /*  meL(Q)  */
             case 32: assignValW("Ml2",val);  break; /*  mmuL(Q) */
             case 33: assignValW("Ml3",val);  break; /*  mtauL(Q)*/
             case 34: assignValW("Mr1",val);  break; /*  meR(Q)  */
             case 35: assignValW("Mr2",val);  break; /*  mmuR(Q) */
             case 36: assignValW("Mr3",val);  break; /*  mtauR(Q)*/
             case 41: assignValW("Mq1",val);  break; /*  mqL1(Q) */
             case 42: assignValW("Mq2",val);  break; /*  mqL2(Q) */
             case 43: assignValW("Mq3",val);  break; /*  mqL3(Q) */
             case 44: assignValW("Mu1",val);  break; /*  muR(Q)  */
             case 45: assignValW("Mu2",val);  break; /*  mcR(Q)  */
             case 46: assignValW("Mu3",val);  break; /*  mtR(Q)  */
             case 47: assignValW("Md1",val);  break; /*  mdR(Q)  */
             case 48: assignValW("Md2",val);  break; /*  msR(Q)  */
             case 49: assignValW("Md3",val);  break; /*  mbR(Q)  */
            }
      else if(strcmp(buff,"GAUGE")==0)  while(2==nfscanf(f,&n1,NULL,&val))
        switch(n1)
        { case 1: assignValW("gY", val); break; 
          case 2: assignValW("g2", val); break;
          case 3: assignValW("g3", val); break;
        }
      else if(strcmp(buff,"YU")==0) while(3==nfscanf(f,&n1,&n2,&val)) 
        {  if(n1==3 && n2==3) assignValW("Yt",val); }
      else if(strcmp(buff,"YD")==0)  while(3==nfscanf(f,&n1,&n2,&val)) 
        { if(n1==3 && n2==3) assignValW("Yb",val);}
      else if(strcmp(buff,"YE")==0)  while(3==nfscanf(f,&n1,&n2,&val)) 
        { if(n1==3 && n2==3) assignValW("Yl",val);}
    }          
  }
  for(i=0;i<3;i++) 
  { char name[10];
    double M[2];
    for(n2=0;n2<2;n2++){sprintf(name,"%s1%d",Zf[i],n2+1); M[n2]=findValW(name);}
    M[1]=-M[1];
    for(n2=0;n2<2;n2++){sprintf(name,"%s2%d",Zf[i],n2+1); assignValW(name,M[1-n2]);}
  }
  fclose(f);
  if(!(MG1ok && MG2ok)) 
  { double mg1,mg2;
    CheckNCsector(NULL, &mg1, &mg2,NULL,NULL,NULL,NULL);
    assignValW("MG1",mg1);
    assignValW("MG2",mg2);
  }

  if(!AmOK) assignValW("Am",findValW("Al"));
  if(!AuOK) assignValW("Au",findValW("At"));
  if(!AdOK) assignValW("Ad",findValW("Ab"));
  
  return err;
}



int writeLesH(char *fname)
{
  FILE *f;
  char name[20];
  int n1,n2;
  double Q;

  f=fopen(fname,"w");
  if(f==NULL) return -2;
  
 
  Q=findValW("QSUSY");
  
  fprintf(f,"Block SPINFO\n");
  fprintf(f,"   1  *\n");
  fprintf(f,"   2  *\n"); 
  
  fprintf(f,"Block MASS   # Mass spectrum\n");
  fprintf(f,"#PDG code      mass           particle\n");
  fprintf(f,"       24   %16.8E    # MW\n",              80.423);
  fprintf(f,"       25   %16.8E    # h0\n",              findValW("Mh")); 
  fprintf(f,"       35   %16.8E    # H0\n",              findValW("MHH" )); 
  fprintf(f,"       36   %16.8E    # A0\n",              findValW("MH3" )); 
  fprintf(f,"       37   %16.8E    # H+\n",              findValW("MHc" )); 
  fprintf(f,"  1000001   %16.8E    # ~d_L\n",            findValW("MSdL")); 
  fprintf(f,"  1000002   %16.8E    # ~u_L\n",            findValW("MSuL")); 
  fprintf(f,"  1000003   %16.8E    # ~s_L\n",            findValW("MSsL")); 
  fprintf(f,"  1000004   %16.8E    # ~c_L\n",            findValW("MScL")); 
  fprintf(f,"  1000005   %16.8E    # ~b_1\n",            findValW("MSb1")); 
  fprintf(f,"  1000006   %16.8E    # ~t_1\n",            findValW("MSt1")); 
  fprintf(f,"  1000011   %16.8E    # ~e_L\n",            findValW("MSeL")); 
  fprintf(f,"  1000012   %16.8E    # ~nue_L\n",          findValW("MSne")); 
  fprintf(f,"  1000013   %16.8E    # ~mu_L\n",           findValW("MSmL")); 
  fprintf(f,"  1000014   %16.8E    # ~numu_L\n",         findValW("MSnm")); 
  fprintf(f,"  1000015   %16.8E    # ~stau_1\n",         findValW("MSl1")); 
  fprintf(f,"  1000016   %16.8E    # ~nu_tau_L\n",       findValW("MSnl")); 
  fprintf(f,"  1000021   %16.8E    # ~g\n",              findValW("MSG")); 
  fprintf(f,"  1000022   %16.8E    # ~neutralino(1)\n",  findValW("MNE1")); 
  fprintf(f,"  1000023   %16.8E    # ~neutralino(2)\n",  findValW("MNE2")); 
  fprintf(f,"  1000024   %16.8E    # ~chargino(1)\n",    findValW("MC1")); 
  fprintf(f,"  1000025   %16.8E    # ~neutralino(3)\n",  findValW("MNE3")); 
  fprintf(f,"  1000035   %16.8E    # ~neutralino(4)\n",  findValW("MNE4")); 
  fprintf(f,"  1000037   %16.8E    # ~chargino(2)\n",    findValW("MC2")); 
  fprintf(f,"  2000001   %16.8E    # ~d_R\n",            findValW("MSdR")); 
  fprintf(f,"  2000002   %16.8E    # ~u_R\n",            findValW("MSuR")); 
  fprintf(f,"  2000003   %16.8E    # ~s_R\n",            findValW("MSsR")); 
  fprintf(f,"  2000004   %16.8E    # ~c_R\n",            findValW("MScR")); 
  fprintf(f,"  2000005   %16.8E    # ~b_2\n",            findValW("MSb2")); 
  fprintf(f,"  2000006   %16.8E    # ~t_2\n",            findValW("MSt2")); 
  fprintf(f,"  2000011   %16.8E    # ~e_R\n",            findValW("MSeR")); 
  fprintf(f,"  2000013   %16.8E    # ~mu_R\n",           findValW("MSmR")); 
  fprintf(f,"  2000015   %16.8E    # ~stau_2\n",         findValW("MSl2")); 

  fprintf(f,"# Higgs mixing\n");
  fprintf(f,"Block ALPHA\n");
  fprintf(f,"     %16.8E\n",findValW("alpha"));

  fprintf(f,"Block GAUGE Q= %16.8E\n",Q);
  fprintf(f,"  1  %16.8E  # U(1)  coupling  \n", findValW("gY") );
  fprintf(f,"  2  %16.8E  # SU(2) coupling\n", findValW("g2") );
  fprintf(f,"  3  %16.8E  # SU(3) coupling\n", findValW("g3") );

  fprintf(f,"Block YU Q= %16.8E\n",Q);
  fprintf(f,"  3   3  %16.8E  # Yt\n", findValW("Yt") );
  fprintf(f,"Block YD Q= %16.8E\n",Q);
  fprintf(f,"  3   3  %16.8E  # Yb\n", findValW("Yb") );
  fprintf(f,"Block YE Q= %16.8E\n",Q);
  fprintf(f,"  3   3  %16.8E  # Yl\n", findValW("Yl") );
    
  fprintf(f,"Block HMIX Q= %16.8E\n",Q);
  fprintf(f,"  1  %16.8E  # mu(Q)MSSM DRbar\n",findValW("mu"));
  fprintf(f,"  2  %16.8E  # tan beta(Q)MSSM DRbar\n",findValW("tb_Q"));
  fprintf(f,"  3  %16.8E  # vev\n",findValW("vev"));
  fprintf(f,"  4  %16.8E  # mA^2\n",findValW("mA_2"));
  
  fprintf(f,"Block MSOFT Q= %16.8E\n",Q);
    fprintf(f,"    1   %16.8E # %s\n", findValW("MG1"  ),"MG1"  );  
    fprintf(f,"    2   %16.8E # %s\n", findValW("MG2"  ),"MG2"  );  
    fprintf(f,"    3   %16.8E # %s\n", findValW("MG3"  ),"MG3"  );  
    fprintf(f,"   21   %16.8E # %s\n", findValW("mH1_2"),"mH1_2");
    fprintf(f,"   22   %16.8E # %s\n", findValW("mH2_2"),"mH2_2");
    fprintf(f,"   31   %16.8E # %s\n", findValW("Ml1"  ),"Ml1"  );  
    fprintf(f,"   32   %16.8E # %s\n", findValW("Ml2"  ),"Ml2"  );  
    fprintf(f,"   33   %16.8E # %s\n", findValW("Ml3"  ),"Ml3"  );  
    fprintf(f,"   34   %16.8E # %s\n", findValW("Mr1"  ),"Mr1"  );  
    fprintf(f,"   35   %16.8E # %s\n", findValW("Mr2"  ),"Mr2"  );  
    fprintf(f,"   36   %16.8E # %s\n", findValW("Mr3"  ),"Mr3"  );  
    fprintf(f,"   41   %16.8E # %s\n", findValW("Mq1"  ),"Mq1"  );  
    fprintf(f,"   42   %16.8E # %s\n", findValW("Mq2"  ),"Mq2"  );  
    fprintf(f,"   43   %16.8E # %s\n", findValW("Mq3"  ),"Mq3"  );  
    fprintf(f,"   44   %16.8E # %s\n", findValW("Mu1"  ),"Mu1"  );  
    fprintf(f,"   45   %16.8E # %s\n", findValW("Mu2"  ),"Mu2"  );  
    fprintf(f,"   46   %16.8E # %s\n", findValW("Mu3"  ),"Mu3"  );  
    fprintf(f,"   47   %16.8E # %s\n", findValW("Md1"  ),"Md1"  );  
    fprintf(f,"   48   %16.8E # %s\n", findValW("Md2"  ),"Md2"  );  
    fprintf(f,"   49   %16.8E # %s\n", findValW("Md3"  ),"Md3"  );  
    
  fprintf(f,"Block STOPMIX\n");
  for(n1=1;n1<=2;n1++)for(n2=1;n2<=2;n2++)
  { sprintf(name,"Zt%d%d",n1,n2);
    fprintf(f,"  %d %d %16.8E # %s\n",n1,n2,findValW(name),name);
  }
  fprintf(f,"Block SBOTMIX\n"); 
  for(n1=1;n1<=2;n1++)for(n2=1;n2<=2;n2++)
  { sprintf(name,"Zb%d%d",n1,n2);
    fprintf(f,"  %d %d %16.8E # %s\n",n1,n2,findValW(name),name);
  }
  fprintf(f,"Block STAUMIX\n");
  for(n1=1;n1<=2;n1++)for(n2=1;n2<=2;n2++)
  { sprintf(name,"Zl%d%d",n1,n2);
    fprintf(f,"  %d %d %16.8E # %s\n",n1,n2,findValW(name),name);
  }
  fprintf(f,"Block NMIX\n");  
    for(n1=1;n1<=4;n1++)for(n2=1;n2<=4;n2++)
  { sprintf(name,"Zn%d%d",n1,n2);
    fprintf(f,"  %d %d %16.8E # %s\n",n1,n2,findValW(name),name);
  }
  fprintf(f,"Block UMIX\n");
  for(n1=1;n1<=2;n1++)for(n2=1;n2<=2;n2++)
  { sprintf(name,"Zu%d%d",n1,n2);
    fprintf(f,"  %d %d %16.8E # %s\n",n1,n2,findValW(name),name);
  }

  fprintf(f,"Block VMIX\n");
  for(n1=1;n1<=2;n1++)for(n2=1;n2<=2;n2++)
  { sprintf(name,"Zv%d%d",n1,n2);
    fprintf(f,"  %d %d %16.8E # %s\n",n1,n2,findValW(name),name);
  }

  fprintf(f,"Block AU Q= %16.8E\n",Q);
  fprintf(f,"  3 3 %16.8E # At\n",findValW("At"));
  fprintf(f,"Block AD Q= %16.8E\n",Q); 
  fprintf(f,"  3 3 %16.8E # Ab\n",findValW("Ab"));
  fprintf(f,"Block AE Q= %16.8E\n",Q);
  fprintf(f,"  3 3 %16.8E # Al\n",findValW("Al"));
  fprintf(f,"  2 2 %16.8E # Am\n",findValW("Am"));
  fprintf(f,"Block SMINPUTS\n"); 
  fprintf(f,"  1  %16.8E # 1/alfEMZ\n",1/ findValW("alfEMZ")); 
  fprintf(f,"  2  %16.8E # G_Fermi\n",1.16637E-5);
  fprintf(f,"  3  %16.8E # alfSMZ\n", findValW("alfSMZ")); 
  fprintf(f,"  4  %16.8E # MZ\n",findValW("MZ"));
  fprintf(f,"  5  %16.8E # MbMb\n", findValW("MbMb"));
  fprintf(f,"  6  %16.8E # Mtp\n", findValW("Mtp"));
  fprintf(f,"  7  %16.8E # Mtau\n",findValW("Ml"));
  fprintf(f,"Block MODSEL\n");
  fprintf(f,"  1    0    # General MSSM\n");
  fprintf(f,"Block MINPAR\n"); 
  fprintf(f,"  3  %16.8E # tb\n",findValW("tb")); 
  fclose(f);
  return 0;
}



void CheckNCsector(double *zero_, double*m1_, double*m2_,double*mu_, double*tb_,
double *mz_, double* sw_)
{
 double Z[4][4], M[4],MM[4][4];
 char name[20];
 int i,j,k,l;
 double mZero,mTot;
 double w,tw,cw,sw,b,tb,cb,sb,mz;

 
 for(i=0;i<4;i++) 
 {  sprintf(name,"MNE%d",i+1);  
    M[i]=findValW(name);
 }

 for(i=0;i<4;i++) for(j=0;j<4;j++)
 {  sprintf(name,"Zn%d%d",i+1,j+1); 
    Z[j][i]=findValW(name);
 }

 mTot=0; 

 for( i=0;i<4;i++)
 { double s;

   for(l=0;l<4;l++)
   { for(s=0,k=0;k<4;k++) s+=Z[i][k]*M[k]*Z[l][k];
     MM[i][l]=s; 
     if(fabs(s)>mTot) mTot=fabs(s);
   }
 }

 mZero=0; 
 if(mZero<fabs(MM[0][1])) mZero=fabs(MM[0][1]);
 if(mZero<fabs(MM[2][2])) mZero=fabs(MM[2][2]);
 if(mZero<fabs(MM[3][3])) mZero=fabs(MM[3][3]);

 if(zero_) *zero_=mZero;


 tw=-MM[0][2]/MM[1][2];
 w=atan(tw);
 sw=sin(w);
 cw=cos(w);
 if(sw_) *sw_=sw;
 tb=-MM[0][3]/MM[0][2];
 if(tb_) *tb_=tb;
 b=atan(tb);
 sb=sin(b);
 cb=cos(b);
 mz= -MM[2][0]/cb/sw;
 if(mz_) *mz_=mz;

 if(m1_) *m1_=MM[0][0];
 if(m2_) *m2_=MM[1][1];
 if(mu_) *mu_=-MM[3][2]; 
}
