#include"pmodel_aux.h"

double xxxSUGRAc(double smOk,double tb, double gMG1,double gMG2,double gMG3,
             double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
             double gMl2,double gMl3,double gMr2,double gMr3,
             double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3)
{
  int err=0,i,j;
  
  double MbMb=findValW("MbMb");
  double Mtp =findValW("Mtp"); 
  double alfSMZ=findValW("alfSMZ");
  double alfEMZ=findValW("alfEMZ");
  double Ml=findValW("Ml");

#define TOT 25 
  static double mem[TOT]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  
  double *prt[TOT];
  
  prt[0] =&tb,  prt[1] =&gMG1,prt[2] =&gMG2,  prt[3] =&gMG3,  prt[4] =&gAl,
  prt[5] =&gAt, prt[6] =&gAb, prt[7] =&sgn,   prt[8] =&gMHu,  prt[9] =&gMHd,
  prt[10]=&gMl2,prt[11]=&gMl3,prt[12]=&gMr2,  prt[13]=&gMr3,  prt[14]=&gMq2,
  prt[15]=&gMq3,prt[16]=&gMu2,prt[17]=&gMd2,  prt[18]=&gMu3,  prt[19]=&gMd3,
  prt[20]=&MbMb,prt[21]=&Mtp, prt[22]=&alfSMZ,prt[23]=&alfEMZ,prt[24]=&Ml;

/*  delFiles(0); */
  for(i=0;i<TOT;i++) if(mem[i] != *(prt[i]))
  { err=xxxSUGRA( tb,gMG1,gMG2,gMG3,gAl,gAt,gAb,sgn,gMHu,gMHd,
               gMl2,gMl3,gMr2,gMr3,gMq2, gMq3, gMu2, gMu3, gMd2, gMd3);
    if(err<0) FError=1; else for(j=0;j<TOT;j++) mem[j] = *(prt[j]);
    break;
  }   
  return err;
}

#undef TOT

int  xxxsugra_(double* tb, double* gMG1,double* gMG2,double* gMG3,
   double* gAl, double* gAt, double* gAb, double* sgn, double* gMHu, double* gMHd,
   double* gMl2,double* gMl3,double* gMr2,double* gMr3,
   double* gMq2,double* gMq3,double* gMu2,double* gMd2,double* gMu3,double* gMd3)
{ return  xxxSUGRA(*tb, *gMG1,*gMG2,*gMG3,         
   *gAl, *gAt, *gAb, *sgn, *gMHu,*gMHd,
   *gMl2,*gMl3,*gMr2,*gMr3,
   *gMq2,*gMq3,*gMu2,*gMd2,*gMu3,*gMd3);
}
