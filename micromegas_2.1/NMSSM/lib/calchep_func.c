#include "pmodel.h"
#include "../../sources/micromegas.h"
#include "../../sources/micromegas_aux.h"
/* ============================================================
   The function presented in this file are used only in calchep 
   interactive session. Thus the prototipes are never  checked.
   So we present them below only to avoid warnings at compilaton
   ============================================================= */
     
/* =====  end of header part ========= */

  double ewsbNMSSM(double alfSMZ, double MbMb,  double Mtp ,  double tb,    double MG1,
                   double MG2,    double MG3,   double Ml2,   double Ml3,   double Mr2,
                   double Mr3,    double Mq2,   double Mq3,   double Mu2,   double Mu3, 
                   double Md2,    double Md3,   double At,    double Ab,    double Al, 
                   double mu,     double LambdQ,double KappaQ,double aLmbdQ,double aKappQ)
{ 
#define TOT 25
  static double mem[TOT]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char names[TOT][10]={"alfSMZ","MbMb","Mtp","tb","MG1",
    "MG2","MG3","Ml2","Ml3","Mr2","Mr3","Mq2","Mq3","Mu2","Mu3",
   "Md2","Md3","At","Ab","Al","mu","LambdQ","KappaQ","aLmbdQ","aKappQ"};  
  static int nw=0;
    
  double arg[TOT]={
 alfSMZ, MbMb,  Mtp,   tb,    MG1,
 MG2,    MG3,   Ml2,   Ml3,   Mr2,
 Mr3,    Mq2,   Mq3,    Mu2,   Mu3,
 Md2,    Md3,   At,    Ab,     Al, 
 mu,     LambdQ,KappaQ,aLmbdQ,aKappQ};  

  int i,err;

  for(i=0;i<TOT;i++) if(mem[i]!=arg[i])
  {
    for(i=0;i<TOT;i++) { assignValW(names[i],arg[i]); mem[i]=arg[i];} 
    err=nmssmEWSB();
    if(err) {FError=1; nw=-1; return -1;} 
    nw=NMHwarn(NULL);
    return nw;
  }
  if(nw==-1) FError=1;
  return nw;  
}
#undef TOT

#define TOT 10
double sugraNMSSM(double alfSMZ, double MbMb, double Mtp, 
                  double m0,     double mhf,  double a0,
                  double tb,     double sgn,  double Lambda,double aKappa)
{
  static double mem[TOT]={0,0,0,0,0,0,0,0,0,0};
  char names[3][10]={"alfSMZ","MbMb","Mtp"};
  static int nw=0;
    
  double arg[TOT]={ alfSMZ,  MbMb,  Mtp, m0,   mhf,   a0,
                     tb, sgn, Lambda, aKappa};                    
  int i,err;
  
  for(i=0;i<TOT;i++) if(mem[i]!=arg[i])
  {
    for(i=0;i<TOT;i++) mem[i]=arg[i]; 
    for(i=0;i<3;i++) assignValW( names[i],arg[i]);
    
    err=nmssmSUGRA( m0, mhf,a0, tb, sgn, Lambda,a0, aKappa);
    if(err) {FError=1; nw=-1; return -1;} 
    nw=NMHwarn(NULL);
    return nw;
  }
  if(nw==-1) FError=1;
  return nw;  
}
#undef TOT


/*
double  bsgnlo(double ok)  { return  bsgnlo_();  }
*/

NTOF(Mh1)   NTOF(Mh2)   NTOF(Mh3)   NTOF(Mha)   NTOF(Mhb)   NTOF(MHc)   NTOF(Zh11) 
NTOF(Zh12)  NTOF(Zh13)  NTOF(Zh21)  NTOF(Zh22)  NTOF(Zh23)  NTOF(Zh31)  NTOF(Zh32)
NTOF(Zh33)  NTOF(Pa11)  NTOF(Pa12)  NTOF(Pa21)  NTOF(Pa22)  NTOF(MNE1)  NTOF(MNE2)
NTOF(MNE3)  NTOF(MNE4)  NTOF(MNE5)  NTOF(NMM55) NTOF(NMM34) NTOF(NMM35) NTOF(NMM45)
NTOF(NMM13) NTOF(NMM14) NTOF(NMM23) NTOF(NMM24) NTOF(Zn11)  NTOF(Zn12)  NTOF(Zn13)  
NTOF(Zn14)  NTOF(Zn15)  NTOF(Zn21)  NTOF(Zn22)  NTOF(Zn23)  NTOF(Zn24)  NTOF(Zn25)
NTOF(Zn31)  NTOF(Zn32)  NTOF(Zn33)  NTOF(Zn34)  NTOF(Zn35)  NTOF(Zn41)  NTOF(Zn42)
NTOF(Zn43)  NTOF(Zn44)  NTOF(Zn45)  NTOF(Zn51)  NTOF(Zn52)  NTOF(Zn53)  NTOF(Zn54)
NTOF(Zn55)  NTOF(MSl1)  NTOF(MSl2)  NTOF(Zl11)  NTOF(Zl21)  NTOF(Zl12)  NTOF(Zl22)
NTOF(MSt1)  NTOF(MSt2)  NTOF(MSb1)  NTOF(MSb2)  NTOF(Zb11)  NTOF(Zb21)  NTOF(Zb12)
NTOF(Zb22)  NTOF(Zt11)  NTOF(Zt21)  NTOF(Zt12)  NTOF(Zt22)  NTOF(MSeL)  NTOF(MSeR)
NTOF(MSmL)  NTOF(MSmR)  NTOF(MSne)  NTOF(MSnm)  NTOF(MSnl)  NTOF(MSuL)  NTOF(MSuR)
NTOF(MSdL)  NTOF(MSdR)  NTOF(MScL)  NTOF(MScR)  NTOF(MSsL)  NTOF(MSsR)  NTOF(Am)
NTOF(vev)   NTOF(la1)   NTOF(la2)   NTOF(la3)   NTOF(la4)   NTOF(la5)   NTOF(la1s)
NTOF(la2s)  NTOF(lass)  NTOF(MC1)   NTOF(MC2)   NTOF(Zv11)  NTOF(Zv21)  NTOF(Zv12)
NTOF(Zv22)  NTOF(Zu11)  NTOF(Zu21)  NTOF(Zu12)  NTOF(Zu22)  

NTOF(Lambda) NTOF(Kappa) NTOF(aLmbda) NTOF(aKappa) NTOF(xvev)   
NTOF(At) NTOF(Ab) NTOF(Al)
NTOF(bsg) NTOF(dMb)  NTOF(mu)
