/*=========   NMSSM scenario  ==========
  One can define SUGRA  for GUT scale scenario.
  Otherwise the program uses low scale input.
=======================================*/ 

//#define SUGRA

/*====== Modules ===============
   Keys to switch on 
   various modules of micrOMEGAs
================================*/

#define MASSES_INFO      
      /* Display information about SUSY and Higgs masses 
      */
#define CONSTRAINTS     
      /* Display  deltarho, B_>sgamma, Bs->mumu, gmuon and
         check LEP mass limits 
      */ 
#define OMEGA            
      /* Calculate relic density and display contribution of
         individual channels 
      */
#define INDIRECT_DETECTION  
      /* Compute spectra of gamma/positron/neutrinos
         for DM annihilation; calculate <sigma*v> and
         integrate gamma signal over DM galactic squared
         density for given line of sight.  
      */
//#define RESET_FORMFACTORS
      /* Modify default nucleus form factors, 
         DM velocity distribution,
         A-dependence of Fermi-dencity
      */     
#define WIMP_NUCLEON     
      /* Calculate amplitudes and cross-sections for 
         WIMP-mucleon collisions 
      */  
#define WIMP_NUCLEUS      
      /* Calculate number of events for 1kg*day 
         and recoil energy distibution for various nuclei
      */
//#define CROSS_SECTIONS 
      /* Calculate cross sections and widths for 
         reactions specified by the user
      */
/*===== end of Modules  ======*/

/*===== Options ========*/
//#define SHOWPLOTS
     /* Display  graphical plots on the screen */ 

/*===== End of DEFINE  settings ===== */


#include"../sources/micromegas.h"
#include"lib/pmodel.h"


int main(int argc,char** argv)
{  int err,nw;
   char mess[10];
   
/* to save RGE input/output files uncomment the next line */
/*delFiles(0);*/


#ifdef SUGRA
{
  double m0,mhf,a0,tb;
  double Lambda, aLambda,aKappa,sgn;

  if(argc<7) 
  { 
    printf(" This program needs 6 parameters:\n"
           "   m0      common scalar mass at GUT scale\n"
           "   mhf     common gaugino mass at GUT scale\n"
           "   a0      trilinear soft breaking parameter at GUT scale\n"
           "   tb      tan(beta) \n"
           "   Lambda   Lambda parameter at SUSY\n"
           "   aKappa  aKappa parameter at GUT\n"
           );
    printf(" Auxiliary parameters are:\n"
           "   sgn     +/-1,  sign of Higgsino mass term (default 1)\n" 
           "   aLambda at GUT (default aLambda=a0)\n"    
           "   Mtp     top quark pole mass\n"
           "   MbMb    Mb(Mb) scale independent b-quark mass\n"
           "   alfSMZ  strong coupling at MZ\n");
    printf("Example:  ./main 320 600 -1300 2 0.5 -1400\n");
      exit(1); 
  } else  
  {  double Mtp,MbMb,alfSMZ;
     sscanf(argv[1],"%lf",&m0);
     sscanf(argv[2],"%lf",&mhf);
     sscanf(argv[3],"%lf",&a0);
     sscanf(argv[4],"%lf",&tb);
     sscanf(argv[5],"%lf",&Lambda);
     sscanf(argv[6],"%lf",&aKappa);
     if(argc>7)  sscanf(argv[7],"%lf",&sgn); else sgn=1;
     if(argc>8)  sscanf(argv[8],"%lf",&aLambda); else aLambda=a0;

     if(argc>9){ sscanf(argv[9],"%lf",&Mtp);    assignValW("Mtp",Mtp);      }
     if(argc>10){ sscanf(argv[10],"%lf",&MbMb);   assignValW("MbMb",MbMb);    }
     if(argc>11){ sscanf(argv[11],"%lf",&alfSMZ); assignValW("alfSMZ",alfSMZ);}
  }

  err=nmssmSUGRA( m0,mhf, a0,tb, sgn,  Lambda, aLambda, aKappa);
}
#else
{
  if(argc==1)
  { 
      printf(" Correct usage:  ./omg <file with NMSSM parameters> \n");
      exit(1);
  }
                               

/*  err=readVar(argv[1]);*/
  err=readVarNMSSM(argv[1]);
  
  if(err==-1)     {printf("Can not open the file\n"); exit(1);}
  else if(err>0)  { printf("Wrong file contents at line %d\n",err);exit(1);}
            
  err=nmssmEWSB();
}
#endif

  if(err) 
  { 
     NMHwarn(stdout);
     exit(1);
  }
    
  err=sortOddParticles(mess);
  if(err) { printf("Can't calculate %s\n",mess); return 1;}

/*to print input parameters or model in SLHA format uncomment correspondingly*/
 
/*  printVar(stdout);  */


#ifdef MASSES_INFO
{
  printf("\n=== MASSES OF HIGGS AND SUSY PARTICLES: ===\n");
  HiggsMasses(stdout);
  printMasses(stdout,1);
}
#endif

#ifdef CONSTRAINTS
{ double constr0,constrM, constrP;
  printf("\n==== Physical Constraints: =====\n");
  printf("Warnings from NMSSMTools:\n");
  nw=NMHwarn(stdout);
  if(nw==0) printf("  .....  none.\n");
  
  constr0=b2sg_(&constrM,&constrP);
  printf("B->s,gamma = %.2E (%.2E ,  %.2E  ) \n",constr0,constrM, constrP );

  constr0= bsmumu_(&constrM,&constrP);
  printf("Bs->mu,mu  = %.2E (%.2E ,  %.2E  ) \n",constr0,constrM, constrP );
  
  constr0=btaunu_(&constrM,&constrP);
  printf("B+->tau+,nu= %.2E (%.2E ,  %.2E  ) \n",constr0, constrM, constrP );
  
  constr0=deltamd_(&constrM,&constrP);
  printf("deltaMd    = %.2E (%.2E ,  %.2E  ) \n",constr0,constrM, constrP );

  constr0=deltams_(&constrM,&constrP);
  printf("deltaMs    = %.2E (%.2E ,  %.2E  ) \n",constr0,constrM, constrP );
}
#endif

#ifdef OMEGA
{ int fast=1;
  double Beps=1.E-5, cut=0.01;
  double Omega,Xf;   
  printf("\n==== Calculation of relic density =====\n");  
  if(strcmp(mess,"~o1")) printf(" ~o1 is not LSP\n"); 
                    else o1Contents(stdout);
  Omega=darkOmega(&Xf,fast,Beps);
  printf("Xf=%.2e Omega=%.2e\n",Xf,Omega);
  printChannels(Xf,cut,Beps,1,stdout);
}
#endif


#ifdef INDIRECT_DETECTION
{ /* See  hep-ph/0607059 pages 10, 11 for complete explanation  */

  int err,outP;
  double Mwimp,Emin,Ntot,Etot,sigmaV,v=0.001,fi,tab[250];
  char txt[100];

printf("\n==== Indirect detection =======\n");  

  outP=0;    /* 0 for gamma rays  
                1-positron; 2-antiproton; 3,4,5 neutrinos 
                (electron, muon and tau correspondinly)
             */
  Emin=0.1;  /* Energy cut  in GeV   */
  fi=0;      /* angle of sight in radians */                                                                                                                                                                         

  sigmaV=calcSpectrum(v,outP,tab,&err);  
             /* Returns sigma*v in cm^3/sec.  
                tab could be substituted in zInterp(z,tab) to get particle distribution 
                in one collision  dN/dz, where  z=log (E/Mwinp) */
                  
  printf("sigma*v=%.2E [cm^3/sec]\n", sigmaV);
  
  Mwimp=lopmass_();

  spectrInfo(Emin/Mwimp,tab, &Ntot,&Etot); 
  printf("%.2E %s with E > %.2E are generated at one collision\n",Ntot,outNames[outP],Emin);

#ifdef SHOWPLOTS 
/*   Spectrum of photons produced in DM annihilation.   */

  sprintf(txt,"%s: N=%.2e,<E/2M>=%.2f,vsc=%.2e cm^3/sec,M(%s)=%.2e", 
  outNames[outP],Ntot,Etot,sigmaV,mess,Mwimp); 
  
  displaySpectrum(tab, txt ,Emin/Mwimp);  
#endif
  if(outP==0)
  printf("gamma flux for fi=%.2E[rad] is %.2E[ph/cm^2/s/sr]\n",
     fi, HaloFactor(fi,rhoQisotermic)*sigmaV*Ntot/Mwimp/Mwimp);

/*  Test of energy conservation  */     
/*        
{ double e[6];
  int i;
  printf("Check of energy conservation:\n"); 
  for(i=0;i<6;i++)
  {    
     sigmaV=calcSpectrum(v,i,tab,&err);
     spectrInfo(Emin/Mwimp,tab, NULL,e+i);
  } 
  printf("1 = %.2f\n",e[0]+2*(e[1]+e[2]+e[3]+e[4]+e[5]) );
}     
*/

}
#endif

#ifdef RESET_FORMFACTORS
{
/* 
   The default nucleon form factors can be completely or partially modified 
   by setProtonFF and setNeutronFF. For scalar form factors, one can first call
   getScalarFF( Mu/Md, Ms/Md, sigmaPiN[MeV], sigma0[MeV], protonFF,neutronFF)  
   or set the new coefficients by directly assigning numerical values.
*/
{ double   ffS0P[3]={0.033,0.023,0.26},
           ffS0N[3]={0.042,0.018,0.26},
           ffV5P[3]={-0.427, 0.842,-0.085},
           ffV5N[3]={ 0.842,-0.427,-0.085}; 

  printf("\n=========== Redefinition of form factors  =========\n");         
      
  getScalarFF(0.553,18.9,55.,35.,ffS0P, ffS0N);
  printf("protonFF  d %E, u %E, s %E\n",ffS0P[0],ffS0P[1],ffS0P[2]);                               
  printf("neutronFF d %E, u %E, s %E\n",ffS0N[0],ffS0N[1],ffS0N[2]);

/* Use NULL argument if there is no need for reassignment */
  setProtonFF(ffS0P,ffV5P, NULL);
  setNeutronFF(ffS0N,ffV5N,NULL);
}

/* Option to change parameters of DM velocity  distribution 
*/   
   SetfMaxwell(220.,244.4,600.);
     /* arg1- defines DM velocity distribution in Galaxy rest frame:
            ~exp(-v^2/arg1^2)d^3v
        arg2- Earth velocity with respect to Galaxy
        arg3- Maximal DM velocity in Sun orbit with respect to Galaxy.
        All parameters are  in [km/s] units.
     */
/* In case DM has velocity distribution close to delta-function 
   the DM velocity V[km/s] can be defined by
*/          
   SetfDelta(350.);

/* To reset parameters of Fermi nucleus distribution  */
   SetFermi(1.23,-0.6,0.52);
/*  with half-density radius for Fermi distribution: 
          c=arg1*A^(1/3) + arg2
    and arg3 is the surface thickness.
    All parameter in [fm].      
*/
}
#endif

#ifdef WIMP_NUCLEON
{ double pA0[2],pA5[2],nA0[2],nA5[2];
  double Nmass=0.939; /*nucleon mass*/
  double SCcoeff;        

printf("\n==== Calculation of WIMP-nucleons amplitudes  =====\n");   

  nucleonAmplitudes(FeScLoop, pA0,pA5,nA0,nA5);
    printf("WIMP-nucleon amplitudes:\n");
    printf("proton:  SI  %.3E  SD  %.3E\n",pA0[0],pA5[0]);
    printf("neutron: SI  %.3E  SD  %.3E\n",nA0[0],nA5[0]); 

  SCcoeff=4/M_PI*3.8937966E8*pow(Nmass*lopmass_()/(Nmass+ lopmass_()),2.);
    printf("WIMP-nucleon cross sections:\n");
    
    printf(" proton  SI %.3E  SD %.3E\n",SCcoeff*pA0[0]*pA0[0],SCcoeff*pA5[0]*pA5[0]);
    printf(" neutron SI %.3E  SD %.3E\n",SCcoeff*nA0[0]*nA0[0],SCcoeff*nA5[0]*nA5[0]);
}
#endif
  
#ifdef WIMP_NUCLEUS
{ double dNdE[200];
  double nEvents;
  double rho=0.3; /* DM density GeV/sm^3 */

printf("\n=========== Direct Detection =========\n");    

  nEvents=nucleusRecoil(rho,fDvMaxwell,73,Z_Ge,J_Ge73,S00Ge73,S01Ge73,S11Ge73,FeScLoop,dNdE);
      /* See '../sources/micromegas.h' for description of arguments 
     
        Instead of Maxwell (DvMaxwell) one can use 'fDvDelta' Delta-function 
        velocity distribution.
      */

  printf("73Ge: Total number of events=%.2E /day/kg\n",nEvents);
  printf("Number of events in 10 - 50 KeV region=%.2E /day/kg\n",
                                   cutRecoilResult(dNdE,10,50));                                   
#ifdef SHOWPLOTS
    displayRecoilPlot(dNdE,"Distribution of recoil energy of 73Ge",0,199);
#endif

  nEvents=nucleusRecoil(rho,fDvMaxwell,131,Z_Xe,J_Xe131,S00Xe131,S01Xe131,S11Xe131,FeScLoop,dNdE);

  printf("131Xe: Total number of events=%.2E /day/kg\n",nEvents);
  printf("Number of events in 10 - 50 KeV region=%.2E /day/kg\n",
                                   cutRecoilResult(dNdE,10,50));                                   
#ifdef SHOWPLOTS
    displayRecoilPlot(dNdE,"Distribution of recoil energy of 131Xe",0,199);
#endif

/*  If SD form factors are not known or for spin=0 nucleus one can use */
  nEvents=nucleusRecoil0(rho,fDvMaxwell,3,Z_He,J_He3,Sp_He3,Sn_He3,FeScLoop,dNdE);
  printf("\n 3^He: Total number of events=%.2E /day/kg\n",nEvents);
#ifdef SHOWPLOTS
  displayRecoilPlot(dNdE,"Distribution of recoil energy of 3He",0,50);
#endif

}
#endif 

#ifdef CROSS_SECTIONS
{
  double Pcm=500;
  numout* cc;
  double cosmin=-0.99, cosmax=0.99;
  double v=0.002;
printf("\n====== Calculation of widths and cross sections ====\n");  
  decay2Info("Z",stdout);
  decay2Info("h1",stdout);

  Helicity[0]=0.5;
  Helicity[1]=-0.5;
  printf("Process e,E->2*x at Pcm=%.3E GeV\n",Pcm);
  cc=newProcess("e%,E%->2*x","eE_2x");
  if(cc)
  { int ntot,l;
    char * name[4];
    procInfo1(cc,&ntot,NULL,NULL);
    for(l=1;l<=ntot; l++)
    { int err;
      double cs;
      procInfo2(cc,l,name,NULL);
      printf("%3s,%3s -> %3s %3s  ",name[0],name[1],name[2],name[3]);
      cs= cs22(cc,l,Pcm,cosmin,cosmax,&err);
      if(err) printf("Error\n");
      else if(cs==0.) printf("Zero\n");
      else printf("%.2E [pb]\n",cs); 
    }
  } 

  printf("\nNeutralino annihilation at V_rel=%.1E\n",v);
 
  cc=newProcess("","omg__to1__to1");
  assignValW("Q",2*findValW("MNE1"));
  if(cc)
  { int ntot,l;
    char * name[4];
    double mass[4];
    procInfo1(cc,&ntot,NULL,NULL);
    for(l=1;l<=ntot; l++)
    { int err;
      double cs;
      procInfo2(cc,l,name,mass);
      if(l==1) { Pcm=mass[0]*v/2; printf("(Pcm=%.2E)\n",Pcm);}
      printf("%3s,%3s -> %3s %3s  ",name[0],name[1],name[2],name[3]);
      cs= cs22(cc,l,Pcm,-1.,1.,&err);
      if(err) printf("Error\n");
      else if(cs==0.) printf("Zero\n");
      else printf("%.2E [pb] ( sigma*v=%.2E [cm^3/sec] ) \n",cs,cs*v*2.9979E-26); 
    }
  }
}

#endif
                          
  return 0;
}
