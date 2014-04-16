#include"pmodel_aux.h"

double xxxEwsbMSSMc(double smOk,double tb, double MG1,double MG2,double MG3,
    double Am, double Al, double At, double Ab, double MH3, double mu,
    double Ml2,double Ml3,double Mr2,double Mr3,
    double Mq2,double Mq3,double Mu2,double Mu3,double Md2,double Md3)
{
  int err=0,i,j;
  
  double MbMb=findValW("MbMb");
  double Mtp =findValW("Mtp"); 
  double alfSMZ=findValW("alfSMZ");
  double Ml=findValW("Ml");


#define TOT 24 
  static double mem[TOT]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  
  double *prt[TOT];
  
  prt[0] =&tb,  prt[1] =&MG1,prt[2] =&MG2,    prt[3] =&MG3,   prt[4] =&Am, 
  prt[5] =&Al,  prt[6] =&At, prt[7] =&Ab,     prt[8] =&MH3,   prt[9] =&mu,
  prt[10]=&Ml2, prt[11]=&Ml3,prt[12]=&Mr2,    prt[13]=&Mr3,   prt[14]=&Mq2,
  prt[15]=&Mq3, prt[16]=&Md2,prt[17]=&Md3,    prt[18]=&Mu2,   prt[19]=&Mu3,
  prt[20]=&MbMb,prt[21]=&Mtp,prt[22]=&alfSMZ, prt[23]=&Ml;

/*  delFiles(0); */
  for(i=0;i<TOT;i++) if(mem[i] != *(prt[i]))
  {
     assignValW("tb"  ,tb);
     assignValW("MG1" ,MG1);
     assignValW("MG2" ,MG2);
     assignValW("MG3" ,MG3);
     assignValW("Am"  ,Am);
     assignValW("Al"  ,Al);
     assignValW("At"  ,At);
     assignValW("Ab"  ,Ab);
     assignValW("MH3" ,MH3);
     assignValW("mu"  ,mu);
     assignValW("Ml2" ,Ml2);  
     assignValW("Ml3" ,Ml3);  
     assignValW("Mr2" ,Mr2);  
     assignValW("Mr3" ,Mr3); 
     assignValW("Mq2" ,Mq2);
     assignValW("Mq3" ,Mq3);
     assignValW("Md2" ,Md2);
     assignValW("Md3" ,Md3);
     assignValW("Mu2", Mu2);
     assignValW("Mu3", Mu3);

    err=xxxEwsbMSSM();
    if(err<0) FError=1; else for(j=0;j<TOT;j++) mem[j] = *(prt[j]);
    break;
  }  
  return err;
}

#undef TOT


int  xxxewsbmssm_(void){ return  xxxEwsbMSSM();}
