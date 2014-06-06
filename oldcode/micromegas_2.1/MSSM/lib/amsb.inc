#include"pmodel_aux.h"


double xxxAMSBc(double m0,double m32, double tb, double sgn)
{
  int err=0,i,j;
  
  double MbMb=findValW("MbMb");
  double Mtp =findValW("Mtp"); 
  double alfSMZ=findValW("alfSMZ");
  double Ml=findValW("Ml");

#define TOT 8 
  static double mem[TOT]={0,0,0,0,0,0,0,0};  
  double *prt[TOT];
  
  prt[0] =&m0,  prt[1] =&m32, prt[2] =&tb,  prt[3] =&sgn,  
  prt[4] =&MbMb,prt[5] =&Mtp, prt[6] =&alfSMZ, prt[7] =&Ml;

  for(i=0;i<TOT;i++) if(mem[i] != *(prt[i]))
  { err=xxxAMSB(m0,m32,tb,sgn);
    if(err<0) FError=1; else for(j=0;j<TOT;j++) mem[j] = *(prt[j]);
    break;
  }   
  return err;
}
#undef TOT

int  xxxamsb_(double* m0,double* m32, double* tb, double* sgn)
{ return  xxxAMSB(* m0,* m32, *tb, *sgn  );
}
