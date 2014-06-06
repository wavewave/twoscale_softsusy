
#ifdef __cplusplus

#include <cmath>
#include <complex>
using std::complex;

typedef complex<double> Complex;
#define creal real 
#define cimag imag
#define carg  arg
#define clog  log
#define cexp  exp
#define cpow  pow
const Complex I=Complex(0,1);

#else 

#include <complex.h>
#define Complex double complex

#endif

#include"../../sources/micromegas_aux.h"
#include"../../sources/micromegas.h"

#include"pmodel.h"


#include<math.h>
#include<stdlib.h>
#include"../../sources/micromegas.h"
#include"../../sources/micromegas_aux.h"
#define SQ(x)  ((x)*(x))

extern double2double  MNE1,MbEff,McEff,MbEff,MtEff,
MSb1,MSb2,Zb11r,Zb12r,Zb21r,Zb22r,Zb11i,Zb12i,Zb21i,Zb22i,  
MSt1,MSt2,Zt11r,Zt12r,Zt21r,Zt22r,Zt11i,Zt12i,Zt21i,Zt22i;


static double cnorm2(Complex C) { return creal(C)*creal(C)+cimag(C)*cimag(C);}


double  qbox_(void)
{
  double  T3Q[6],EQ[6],mq[6],msq[2][6];
  char buffName[10];
  double  ALPE,SW,CW,MW,MZ,E,G,mne,beta,sb,cb,BD,B1D,BS,B1S,B2S;
  int i,II,IQ,i1,i2;

  Complex MI[2][2][6],NL[5],AQI[2][6],BQI[2][6]; 
/*ccccccccccccccccccc CONSTANTS ccccccc*/
   
/*  ALPE=findValW("alfEMZ");*/
  SW=findValW("SW");
  CW=sqrt(1.-SW*SW);
  MZ=findValW("MZ");
  MW=MZ*CW;  
  E=findValW("EE");
  G =E/SW;
printf("OK1\n");
  mne=fabs(MNE1(1.));
printf("OK2\n");
/*=======*/
  beta=atan(findValW("tb"));
  sb=sin(beta);
  cb=cos(beta);
/*========  Quark,SQUARK masses and mixing  ======*/

//  c-quark:
  msq[0][3]=findParamW("MScL");
  msq[1][3]=findParamW("MScR");

  MI[0][0][3]= MI[1][1][3]=findParamW("Zc11r");
  MI[1][0][3]=findParamW("Zc21r")+I*findParamW("Zc21i");
  MI[0][1][3]=-MI[1][0][3];

printf("c-quark OK\n");
//  b-quark:
    msq[0][4]=MSb1(1.);
    msq[1][4]=MSb2(1.);
    MI[0][0][4]=Zb11r(1.)+I*Zb11i(1.);
    MI[0][1][4]=Zb12r(1.)+I*Zb12i(1.);
    MI[1][0][4]=Zb21r(1.)+I*Zb21i(1.);
    MI[1][1][4]=Zb22r(1.)+I*Zb22i(1.);
// t-quark:
    msq[0][5]=MSt1(1.);
    msq[1][5]=MSt2(1.);
    MI[0][0][5]=Zt11r(1.)+I*Zt11i(1.);
    MI[0][1][5]=Zt12r(1.)+I*Zt12i(1.);
    MI[1][0][5]=Zt21r(1.)+I*Zt21i(1.);
    MI[1][1][5]=Zt22r(1.)+I*Zt22i(1.);

  mq[3]=McEff(2*mne);
  mq[4]=MbEff(2*mne);
  mq[5]=MtEff(2*mne);

  NL[1]=Zn11r(1.)+I*Zn11i(1.);
  NL[2]=Zn12r(1.)+I*Zn12i(1.);
  NL[3]=Zn13r(1.)+I*Zn13i(1.);
  NL[4]=Zn14r(1.)+I*Zn14i(1.); 
  
  for(i=0;i<6;i++)if(i&1){T3Q[i]=0.5; EQ[i]=2/3.;}else{T3Q[i]=-0.5; EQ[i]=-1/3.;}
  
  for(IQ=3;IQ<6;IQ++) for( II=0;II<2;II++)
  {  Complex X,Y,Z;
     X=-(T3Q[IQ]*NL[2]+SW/CW*NL[1]/6.);
     Y=SW/CW*EQ[IQ]*NL[1];
     if(IQ&1) Z= -0.5*mq[IQ]*NL[4]/MW/sb; else Z= -0.5*mq[IQ]*NL[3]/MW/cb;
     
     AQI[II][IQ]  =G*(MI[II][0][IQ]*(X+Z)+MI[II][1][IQ]*(Y+Z))/sqrt(2.);
     BQI[II][IQ]  =G*(MI[II][0][IQ]*(X-Z)+MI[II][1][IQ]*(-Y+Z))/sqrt(2.);
  }

  for(IQ=3,BD=BS=B1D=B1S=B2S=0.;IQ<6;IQ++) for(II=0;II<2;II++)
  {  double AplusB =cnorm2(AQI[II][IQ])+cnorm2(BQI[II][IQ]);  
     double AminusB=cnorm2(AQI[II][IQ])-cnorm2(BQI[II][IQ]);
     BD  +=AminusB*mq[IQ]*LintIk(1,msq[II][IQ],mq[IQ],mne)/32./M_PI;	  
     B1D +=AminusB*mq[IQ]*LintIk(3,msq[II][IQ],mq[IQ],mne)/12./M_PI;	 
     BS +=AplusB*mne*LintIk(2,msq[II][IQ],mq[IQ],mne)/32./M_PI;
     B1S+=AplusB*mne*LintIk(4,msq[II][IQ],mq[IQ],mne)/12./M_PI;	
     B2S+=AplusB*LintIk(5,msq[II][IQ],mq[IQ],mne)/48./M_PI;
  } 
  return      BD+BS-mne*B2S/2-mne*mne*(B1D+B1S)/4;         
}
