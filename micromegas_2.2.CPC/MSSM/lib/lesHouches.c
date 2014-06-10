#include<math.h>
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
   fprintf(f," 31  %.8E      # Ml1\n",findValW("Ml1"));
   fprintf(f," 32  %.8E      # Ml2\n",findValW("Ml2")); 
   fprintf(f," 33  %.8E      # Ml3\n",findValW("Ml3"));
   fprintf(f," 34  %.8E      # MR2\n",findValW("Mr1"));
   fprintf(f," 35  %.8E      # MR2\n",findValW("Mr2")); 
   fprintf(f," 36  %.8E      # MR3\n",findValW("Mr3"));

   fprintf(f," 41  %.8E      # Mq1\n",findValW("Mq1"));
   fprintf(f," 42  %.8E      # Mq2\n",findValW("Mq2")); 
   fprintf(f," 43  %.8E      # Mq3\n",findValW("Mq3"));
   fprintf(f," 44  %.8E      # Mu1\n",findValW("Mu1"));
   fprintf(f," 45  %.8E      # Mu2\n",findValW("Mu2")); 
   fprintf(f," 46  %.8E      # Mu3\n",findValW("Mu3"));
   fprintf(f," 47  %.8E      # Md1\n",findValW("Md1"));
   fprintf(f," 48  %.8E      # Md2\n",findValW("Md2")); 
   fprintf(f," 49  %.8E      # Md3\n",findValW("Md3"));
   fclose(f);
   return 0;
}


static void FillVal(int mode) 
{ char name[10];
  int i,j,k;
  char* Zf[3]={"Zb","Zt","Zl"};
  char* Qmix[3]={"SBOTMIX","STOPMIX","STAUMIX"};
  char* massName[32]={"MH3","Mh","MHH","MHc", "MNE1", "MNE2", "MNE3", "MNE4",  "MC1",  "MC2",  "MSG", "MSne", "MSnm", "MSnl", "MSeL", "MSeR", "MSmL", "MSmR", "MSl1", "MSl2", "MSdL", "MSdR", "MSuL", "MSuR", "MSsL", "MSsR", "MScL", "MScR", "MSb1", "MSb2", "MSt1","MSt2"};
  int   massId[32]  ={ 36  ,  25,   35,   37,1000022,1000023,1000025,1000035,1000024,1000037,1000021,1000012,1000014,1000016,1000011,2000011,1000013,2000013,1000015,2000015,1000001,2000001,1000002,2000002,1000003,2000003,1000004,2000004,1000005,2000005,1000006,2000006};   
  double Q;
  if(mode==0)i=1; else i=0; 
  for(;i<32;i++) assignValW(massName[i],slhaVal("MASS",0.,1,massId[i]));
  Q=sqrt(fabs(findValW("MSt1")*findValW("MSt2")));
    
  for(i=1;i<=4;i++) for(j=1;j<=4;j++) 
  { sprintf(name,"Zn%d%d",i,j); assignValW(name,slhaVal("NMIX",Q,2,i,j));}
  
  for(i=1;i<=2;i++) for(j=1;j<=2;j++)
  { sprintf(name,"Zu%d%d",i,j);assignValW(name,slhaVal("UMIX",Q,2,i,j));
    sprintf(name,"Zv%d%d",i,j);assignValW(name,slhaVal("VMIX",Q,2,i,j));
  }
   
  for(k=0;k<3;k++)
  { double M[3];
    for(i=1;i<=2;i++) 
    {M[i]=slhaVal(Qmix[k],Q,2,1,i);
     sprintf(name,"%s1%d",Zf[k],i); assignValW(name,M[i]);
    }  
    M[2]*=-1;
    for(i=1;i<=2;i++) 
    {
     sprintf(name,"%s2%d",Zf[k],i); assignValW(name,M[3-i]);
    }  
  }   
  assignValW("alpha", slhaVal("ALPHA",Q,0));
  
  if(mode>0)
  { int MGok[3];
    assignValW("mu", slhaVal("HMIX",Q,1,1));
    assignValW("Am", slhaValExists("Ae",2,2,2)>0 ? slhaVal("Ae",Q,2,2,2):slhaVal("Ae",Q,2,3,3));
    assignValW("Al", slhaVal("Ae",Q,2,3,3));
    assignValW("Ab", slhaVal("Ad",Q,2,3,3));
    assignValW("Ad", slhaValExists("Ad",2,2,2)>0 ? slhaVal("Ad",Q,2,2,2):slhaVal("Ad",Q,2,3,3));
    assignValW("At", slhaVal("Au",Q,2,3,3));
    assignValW("Au", slhaValExists("Au",2,2,2)>0 ? slhaVal("Au",Q,2,2,2):slhaVal("Au",Q,2,3,3));

    for(i=1;i<=2;i++) 
    { MGok[i]=(slhaValExists("MSOFT",1,i)>0);
      if(MGok[i]){ sprintf(name,"MG%d",i);assignValW(name,slhaVal("MSOFT",Q,1,i));}
    } 
    if(!(MGok[1] && MGok[2])) 
    { double mg1,mg2;
      CheckNCsector(NULL, &mg1, &mg2,NULL,NULL,NULL,NULL);
      assignValW("MG1",mg1);
      assignValW("MG2",mg2);
    }
  }
  
  if(mode==2)
  { assignValW("tb",    slhaVal("MINPAR",Q,1,3) );
    assignValW("alfSMZ",slhaVal("SMINPUTS",Q,1,3) );
    assignValW("MbMb",  slhaVal("SMINPUTS",Q,1,5) );
    assignValW("Mtp",   slhaVal("SMINPUTS",Q,1,6) );
    assignValW("Ml",    slhaVal("SMINPUTS",Q,1,7) );
  }   
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


int readLesH(char *fname, int mode)
{ /* mode 0 - EWSB;  1 - SUGRA/AMBS; 2 - FILE */
  int err;  
  err=slhaRead(fname,0);
  if(err) return err;
  FillVal(mode);

  assignValW("dMb",deltaMb());
  assignValW("dMs",deltaMs());
  assignValW("dMd",deltaMd());


#ifdef IMPROVED
{ 
  double zero,m1,m2,mu,tb,mz,sw;                                                                                   
  CheckNCsector(&zero,&m1,&m2,&mu,&tb,&mz,&sw);
  printf("IMPROVED!\n");   
  printf("zero=%e  m1=%e ,m2=%E,mu=%E ,tb=%E,mz=%E,sw=%E\n",
    zero,m1,m2,mu,tb,mz,sw);

  assignValW("mu",mu);
  assignValW("tb",tb); 
  assignValW("MZ",mz);
  assignValW("SW",sw);
}
#endif

  return 0;
}
