/*=== default RGE is SuSpect === 
   To use another package change 'define' setting and 
   define path to the corresponding package via lib/Makefile
================================*/ 
#define SUGRA suspectSUGRA 
/*#define SUGRA  isajetSUGRA */     /*=====for ISAJET   ======*/
/*#define SUGRA  softSusySUGRA */   /*=====for SOFTSUSY ======*/
/*#define SUGRA  sphenoSUGRA   */   /*=====for SPHENO   ======*/

#include"../sources/micromegas.h"
#include"lib/pmodel.h"

extern double bglu_(void);
extern double deltaMb(void), deltaMs(void),deltaMd(void);

int main(int argc,char** argv)
{
  int fast=1;
  double Beps=1.E-5, cut=0.01;
  double Omega,Xf;   
  int err; 
  char mess[10]; 
  double m0,mhf,a0,tb;
  double gMG1, gMG2, gMG3,  gAl, gAt, gAb,  sgn, gMHu,  gMHd,
         gMl2, gMl3, gMr2, gMr3, gMq2, gMq3, gMu2, gMu3, gMd2, gMd3;

/* to save RGE input/output files uncomment the next line */
/* delFiles(0);  */

  if(argc<5) 
  { 
    printf(" This program needs 4 parameters:\n"
           "   m0      common scalar mass at GUT scale\n"
           "   mhf     common gaugino mass at GUT scale\n"
           "   a0      trilinear soft breaking parameter at GUT scale\n"
           "   tb      tan(beta) \n");
    printf(" Auxiliary parameters are:\n"
           "   sgn     +/-1,  sign of Higgsino mass term (default 1)\n"    
           "   Mtp     top quark pole mass\n"
           "   MbMb    Mb(Mb) scale independent b-quark mass\n"
           "   alfSMZ  strong coupling at MZ\n");                        
      exit(1); 
  } else  
  {  double Mtp,MbMb,alfSMZ;
     sscanf(argv[1],"%lf",&m0);
     sscanf(argv[2],"%lf",&mhf);
     sscanf(argv[3],"%lf",&a0);
     sscanf(argv[4],"%lf",&tb);
     if(argc>5)sscanf(argv[5],"%lf",&sgn); else sgn=1;
     if(argc>6){ sscanf(argv[6],"%lf",&Mtp);    assignValW("Mtp",Mtp);      }
     if(argc>7){ sscanf(argv[7],"%lf",&MbMb);   assignValW("MbMb",MbMb);    }
     if(argc>8){ sscanf(argv[8],"%lf",&alfSMZ); assignValW("alfSMZ",alfSMZ);}
  }

/*==== simulation of mSUGRA =====*/
  gMG1=mhf, gMG2=mhf,gMG3=mhf;
  gAl=a0,   gAt=a0,  gAb=a0;  gMHu=m0,  gMHd=m0;
  gMl2=m0,  gMl3=m0, gMr2=m0, gMr3=m0;
  gMq2=m0,  gMq3=m0, gMu2=m0, gMd2=m0, gMu3=m0, gMd3=m0;

  err=SUGRA(tb,  
    gMG1, gMG2, gMG3,  gAl,  gAt, gAb,  sgn, gMHu, gMHd,
    gMl2, gMl3, gMr2, gMr3, gMq2,  gMq3, gMu2, gMu3, gMd2, gMd3);

  if(err<0){ printf(" No RGE solution \n");  return err;} 
  if(err>0){ printf(" non fatal problems in RGE\n");}
  
  err=sortOddParticles(mess);
  
  if(err) { printf("Can't calculate %s\n",mess); return 1;}

/* to print input parameters uncomment */
/* 
  printVar(stdout);  
*/
/* to print model in SLHA format uncomment */
/*  
   writeLesH("slha.out"); 
*/

  HiggsMasses(stdout);
  printMasses(stdout,1);
  
  if(strcmp(mess,"~o1")) { printf(" ~o1 is not LSP\n"); return 2; }

  o1Contents(stdout);

  Omega=darkOmega(&Xf,fast,Beps);
  printf("Xf=%.2e Omega=%.2e\n",Xf,Omega);

  printChannels(Xf,cut,Beps,1,stdout);

  printf("deltartho=%.2E\n",deltarho_());
  printf("gmuon=%.2E\n", gmuon_());
  printf("bsgnlo=%.2E\n", bsgnlo_());
  printf("bsmumu=%.2E\n", bsmumu_());

  
  printf("====================\n");    
  if(masslimits_()==0) printf("MassLimits OK\n");

  { double pA0[2],pA5[2],nA0[2],nA5[2];
    double bglu=0;
    double Nmass=0.939; /*nucleon mass*/
    double ffS0P[3]={0.026,0.020,0.118},
           ffS0N[3]={0.036,0.014,0.118},
           ffV5P[3]={-0.48, 0.78,-0.15},
           ffV5N[3]={0.78 ,-0.48,-0.15}; 
    double SCcoeff;        
          
/*     bglu=bglu_(); */

    getSalarFF(0.553,18.9,55.,35.,ffS0P, ffS0N);

printf("protonFF %E %E %E\n",ffS0P[0],ffS0P[1],ffS0P[2]);                           
printf("neutronFF %E %E %E\n",ffS0N[0],ffS0N[1],ffS0N[2]);

    setProtonFF(ffS0P,ffV5P, NULL);
    setNeutronFF(ffS0N,ffV5N,NULL);

    nucleonAmplitudes(bglu, pA0,pA5,nA0,nA5);
    
    SCcoeff=4/M_PI*3.8937966E8*pow(Nmass*lopmass_()/(Nmass+ lopmass_()),2.);
    
    printf(" proton/neutron SI %E %E ( %E %E)\n", 
        SCcoeff*pA0[0]*pA0[0],SCcoeff*nA0[0]*nA0[0],
        SCcoeff*pA0[1]*pA0[1],SCcoeff*nA0[1]*nA0[1]);
    printf(" proton/neutron SD %E %E ( %E %E)\n", 
        SCcoeff*pA5[0]*pA5[0],SCcoeff*nA5[0]*nA5[0],
        SCcoeff*pA5[1]*pA5[1],SCcoeff*nA5[1]*nA5[1]); 
  }
  { double dNdE[200];
    double nEvents;
    double bglu;
    
    SetfMaxwell(220.,244.4,2500.);
     bglu=bglu_();
    nEvents=nucleusRecoil0(0.3,fDvMaxwell,207,68 , 0, 0.,0.,bglu,dNdE);
    printf("nEvents=%E(%E)\n",nEvents,cutRecoilResult(dNdE,0,199));
    displayRecoilPlot(dNdE,"Distribution of recoil energy of nuclear",0,199);
  }
                           
  return 0;
}
