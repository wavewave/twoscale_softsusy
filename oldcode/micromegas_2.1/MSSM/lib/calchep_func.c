#include "pmodel.h"
#include "../../sources/micromegas.h"
#include "../../sources/micromegas_aux.h"
/* ============================================================
   The function presented in this file are used only in calchep 
   interactive session. Thus the prototipes are never  checked.
   So we present them below only to avoid warnings at compilaton
   ============================================================= */
     
                                                                                                 
extern forCalchep1 dMb,deltarho,gmuon,bsgnlo,bsmumu,masslimits,slha;

extern double saveSM(double MbMb,double Mtp,double SW,double alfSMZ,
       double alfEMZ,double MZ,double Ml);
       
extern double  Omega(double qcdOk);

/* =====  end of header part ========= */

double saveSM(double MbMb,double Mtp,double SW,double alfSMZ,double alfEMZ,double MZ,double Ml)
{
  double Qmin;
  assignValW("MbMb",  MbMb); 
  assignValW("Mtp",   Mtp);
  assignValW("SW",    SW);
  assignValW("alfSMZ",alfSMZ);
  assignValW("alfEMZ",alfEMZ);
  assignValW("MZ",    MZ);
  assignValW("Ml",    Ml);
  Qmin=initQCD(alfSMZ,1.4,MbMb,Mtp);
  if(Qmin<0 || Qmin>MbMb) return 0; else return 1;
}

double  dMb(double ok)     {return deltaMb();    }
double  deltarho(double ok){ return  deltarho_();} 
double  gmuon(double ok)   { return  gmuon_();   }
double  bsgnlo(double ok)  { return  bsgnlo_();  }
double  bsmumu(double ok)  { return  bsmumu_();  }
double  masslimits(double ok) {return masslimits_();}

double  Omega(double qcdOk)
{ double omega;

  sortOddParticles(NULL);
  omega=darkOmega(NULL,1,1.E-6);

  return omega;
}

                                                                             
NTOF(MH3)  NTOF(Mh)   NTOF(MHH)  NTOF(MHc)   NTOF(tb)  NTOF(alpha) NTOF(mu)
NTOF(Am)   NTOF(Al)   NTOF(Ab)   NTOF(At)   NTOF(MNE1) NTOF(MNE2)  NTOF(MNE3)
NTOF(MNE4) NTOF(MC1)  NTOF(MC2)  NTOF(MSG)  NTOF(MSne) NTOF(MSnm)  NTOF(MSnl)
NTOF(MSeL) NTOF(MSeR) NTOF(MSmL) NTOF(MSmR) NTOF(MSl1) NTOF(MSl2)  NTOF(MSuL)
NTOF(MSuR) NTOF(MSsL) NTOF(MSsR) NTOF(MSt1) NTOF(MSt2) NTOF(MSdL)  NTOF(MSdR)
NTOF(MScL) NTOF(MScR) NTOF(MSb1) NTOF(MSb2) NTOF(Zn11) NTOF(Zn21)  NTOF(Zn31)
NTOF(Zn41) NTOF(Zn12) NTOF(Zn22) NTOF(Zn32) NTOF(Zn42) NTOF(Zn13)  NTOF(Zn23)
NTOF(Zn33) NTOF(Zn43) NTOF(Zn14) NTOF(Zn24) NTOF(Zn34) NTOF(Zn44)  NTOF(Zu11)
NTOF(Zu21) NTOF(Zu12) NTOF(Zu22) NTOF(Zv11) NTOF(Zv21) NTOF(Zv12)  NTOF(Zv22)
NTOF(Zl11) NTOF(Zl21) NTOF(Zl12) NTOF(Zl22) NTOF(Zt11) NTOF(Zt21)  NTOF(Zt12)
NTOF(Zt22) NTOF(Zb11) NTOF(Zb21) NTOF(Zb12) NTOF(Zb22) NTOF(MG1)   NTOF(MG2)
NTOF(MG3)  NTOF(Ml1)  NTOF(Ml2)  NTOF(Ml3)  NTOF(Mr1)  NTOF(Mr2)   NTOF(Mr3)
NTOF(Mq1)  NTOF(Mq2)  NTOF(Mq3)  NTOF(Mu1)  NTOF(Mu2)  NTOF(Mu3)   NTOF(Md1)
NTOF(Md2)  NTOF(Md3)



extern int nSess;
double slha(double mssmOK)
{ char fname[20];
  sprintf(fname,"slha_%d.txt",nSess);
  writeLesH(fname);
  return 1.;
}

extern double  saveSLHA(double x);
double  saveSLHA(double x) { if(x)  delFiles(0) ; else   delFiles(1); return 1;}

