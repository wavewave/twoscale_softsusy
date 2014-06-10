#include"../sources/micromegas.h"

void DAMA_NAI( double vRotation, double vSun, double vEsc,
double Mwimp, double csSIp,double csSIn,double csSDp,double csSDn )
{ double dNdE[200];
  double pNa, pI ,Exposure,NaQF,IQF;
  double A4,A5,A6,A14, Y4,Y5,Y6,Y14, 
  Na4_s,Na5_s,Na6_s,Na14_s, Na4_w,Na5_w,Na6_w,Na14_w,
  I4_s,I5_s,I6_s,I14_s,     I4_w,I5_w,I6_w,I14_w;
/*
     arXiv:astro-ph/0307403v1
     arXiv:astro-ph/0501412
     arXiv:astro-ph/0804.2741
*/ 
   pNa=(23./150.);
   pI =(127./150.);  
   NaQF=0.3;    /* Quenching factor:  E_e/E_Na */     
   IQF=0.09;    /* Quenching factor:  E_e/E_I  */
   SetfMaxwell(vRotation,vSun+15,vEsc);  /* Summer  signal */
   
    nucleusRecoilAux(0.3,fDvMaxwell,23,Z_Na,J_Na23,S00Na23,S01Na23,S11Na23,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE); 
     Na4_s =cutRecoilResult(dNdE,2/NaQF, 4/NaQF);
     Na5_s =cutRecoilResult(dNdE,2/NaQF, 5/NaQF);
     Na6_s =cutRecoilResult(dNdE,2/NaQF, 6/NaQF);
     Na14_s=cutRecoilResult(dNdE,6/NaQF,14/NaQF);

    nucleusRecoilAux(0.3,fDvMaxwell,127,Z_I,J_I127,S00I127,S01I127,S11I127,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE); 
     I4_s =cutRecoilResult(dNdE,2/IQF, 4/IQF);
     I5_s =cutRecoilResult(dNdE,2/IQF, 5/IQF);
     I6_s =cutRecoilResult(dNdE,2/IQF, 6/IQF);
     I14_s=cutRecoilResult(dNdE,6/IQF,14/IQF);
    
   SetfMaxwell(vRotation,vSun-15,vEsc);  /* winter signal */

    nucleusRecoil0Aux(0.3,fDvMaxwell,23,Z_Na,J_Na23,Sp_Na23,Sn_Na23,  
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE); 
     Na4_w =cutRecoilResult(dNdE,2/NaQF, 4/NaQF);
     Na5_w =cutRecoilResult(dNdE,2/NaQF, 5/NaQF);
     Na6_w =cutRecoilResult(dNdE,2/NaQF, 6/NaQF);
     Na14_w=cutRecoilResult(dNdE,6/NaQF,14/NaQF);

    nucleusRecoilAux(0.3,fDvMaxwell,127,Z_I,J_I127,S00I127,S01I127,S11I127,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE); 
     I4_w =cutRecoilResult(dNdE,2/IQF, 4/IQF);
     I5_w =cutRecoilResult(dNdE,2/IQF, 5/IQF);
     I6_w =cutRecoilResult(dNdE,2/IQF, 6/IQF);
     I14_w=cutRecoilResult(dNdE,6/IQF,14/IQF);
/* Modulation */
   A4= 0.5*( (Na4_s -Na4_w )*pNa+ (I4_s -I4_w)*pI )/2;
   A5= 0.5*( (Na5_s -Na5_w )*pNa+ (I5_s -I5_w)*pI )/3;
   A6= 0.5*( (Na6_s -Na6_w )*pNa+ (I6_s -I6_w)*pI )/4;
   A14=0.5*( (Na14_s-Na14_w)*pNa+ (I14_s-I14_w)*pI)/8;
/* Yield */
   Y4= 0.5*( (Na4_s +Na4_w )*pNa+ (I4_s +I4_w)*pI )/2;
   Y5= 0.5*( (Na5_s +Na5_w )*pNa+ (I5_s +I5_w)*pI )/3;
   Y6= 0.5*( (Na6_s +Na6_w )*pNa+ (I6_s +I6_w)*pI )/4;
   Y14=0.5*( (Na14_s+Na14_w)*pNa+ (I14_s+I14_w)*pI)/8;

   
   printf("DAMA_NaI signal\n");
   printf(" A4 =%.2E  A5 =%.2E A6 =%.2E A14 =%.2E\n",A4,A5,A6,A14);
   printf(" Y4 =%.2E  Y5 =%.2E Y6 =%.2E Y14 =%.2E\n",Y4,Y5,Y6,Y14);
   printf("xi^2(LIBRA)=%.2E\n",  
    pow((A4-0.0213)/0.0032,2)+pow((A5-0.0165)/0.0024,2)+pow((A6-0.0107)/0.0019,2));
   printf("xi^2(LIBRA+NaI)=%.2E\n",  
    pow((A4-0.0223)/0.0027,2)+pow((A5-0.0178)/0.0020,2)+pow((A6-0.0131)/0.0016,2));

}


void Xenon10(double Mwimp, double csSIp,double csSIn,double csSDp,double csSDn )
{ 
/*
   astro-ph/0706.0039v2   
*/   
  double dNdE[200]; 
  double N129,N131,N129_,N131_,NXX,NXX_,N,N_;
  double Emin=4.5;      
   nucleusRecoilAux(0.3,fDvMaxwell,129,Z_Xe,J_Xe129,S00Xe129,S01Xe129,S11Xe129,
   Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  

    N129=cutRecoilResult(dNdE,Emin,26.9);
    N129_=cutRecoilResult(dNdE,Emin,15.);

   nucleusRecoilAux(0.3,fDvMaxwell,131,Z_Xe,J_Xe131,S00Xe131,S01Xe131,S11Xe131,
   Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  

    N131=cutRecoilResult(dNdE,Emin,26.9);
    N131_=cutRecoilResult(dNdE,Emin,15.);

   nucleusRecoil0Aux(0.3,fDvMaxwell,132,Z_Xe,0,0.,0.,
   Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  

    NXX=cutRecoilResult(dNdE,Emin,26.9);
    NXX_=cutRecoilResult(dNdE,Emin,15.);


    N= 136*(N129 *0.264 + N131 *0.212 + NXX *(1-0.264-0.212) );
    N_=136*(N129_*0.264 + N131_*0.212 + NXX_*(1-0.264-0.212) );

    printf("Xenon10 signal:\n");

    printf(" Events expected: [4.5-26.9]KeV=%.2E  [4.5-15.]KeV=%.2E \n",N,N_ );

   if(N < 2 ) printf(" Not excluded\n");
   else  printf(" Excluded with probability %.2E\n", MaxGapLim(N_,N));  
}

void CDMS_123(double Mwimp, double csSIp,double csSIn,double csSDp,double csSDn )
{ 
/* 
   astro-ph/0808.3530v2
*/
  double dNdE[200]; 
  double NevSD,NevSI, Nev;
    
  nucleusRecoilAux(0.3,fDvMaxwell,73,Z_Ge,J_Ge73,S00Ge73A,S01Ge73A,S11Ge73A,
     Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);
  NevSD=cutRecoilResult(dNdE,10.,100.)*0.0773;
 
  nucleusRecoil0Aux(0.3,fDvMaxwell,73,Z_Ge,0,0,0,
      Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);
  NevSI=cutRecoilResult(dNdE,10.,100.)*(1-0.0773);   
  Nev=121.3*(NevSD+NevSI);
  printf("CDMS_123 events %.2E\n", Nev); 
}     

void CDMS_2006(double Mwimp, double csSIp,double csSIn,double csSDp,double csSDn )
{ 
/* astro-ph/0509269v2 */
  double dNdE[200]; 
  double NevGe,NevSi;

    nucleusRecoilAux(0.3,fDvMaxwell,73,Z_Ge,J_Ge73,S00Ge73,S01Ge73,S11Ge73,
      Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);        
    NevGe=11.5*cutRecoilResult(dNdE,10.,20);

    nucleusRecoilAux(0.3,fDvMaxwell,73,Z_Ge,0,S00Ge73,S01Ge73,S11Ge73,
      Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);        
    NevGe+=11.5*(1/0.0773-1)*cutRecoilResult(dNdE,10.,20);
    
    
    nucleusRecoilAux(0.3,fDvMaxwell,29,Z_Si,J_Si29,S00Si29,S01Si29,S11Si29,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  
    
    NevSi=1.7*cutRecoilResult(dNdE,10.,20);

    nucleusRecoilAux(0.3,fDvMaxwell,29,Z_Si,0.,S00Si29,S01Si29,S11Si29,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  
    
    NevSi+=1.7*(1/0.0468-1)*cutRecoilResult(dNdE,10.,20);
    
    printf("CDMS_2006 events:= %.2E (%.2E Ge, %.2E Si)\n",NevGe+NevSi, NevGe,NevSi);
}     

void He3_100g(double Emin, int nMonths, double Mwimp, double csSIp,double csSIn,double csSDp,double csSDn )
{ 
  double dNdE[200]; 
  double Yield;

  nucleusRecoil0Aux(0.3,fDvMaxwell,3,Z_He,J_He3,Sp_He3,Sn_He3,
      Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);        
  Yield=cutRecoilResult(dNdE,Emin,6.);
    
  printf("He3 signal  events:= %.2E (100g x %d months)\n",0.1*30*nMonths*Yield,
  nMonths);
}     

void Ge_(double Mwimp, double csSIp,double csSIn,double csSDp,double csSDn )
{ 
  double dNdE[200]; 
  double Yield;

  nucleusRecoilAux(0.3,fDvMaxwell,73,Z_Ge,J_Ge73,S00Ge73A,S01Ge73A,S11Ge73A,
       Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);
       
     
  Yield=8.5*cutRecoilResult(dNdE,1.5,6.);
    
  printf("Ge signal  events:= %.2E (8.5 kg*day)\n",Yield);
}     



void COUPP(double Mwimp, double csSIp,double csSIn, double csSDp,double csSDn)
{ /*
    astro-ph/0804.2886v1
  */  
  double dNdE[200]; 
  double pC,pF,pI,NC,NF,NI;
  double Emin=10, Exposure=52; /* GeV*Day */ 
 
  pC=12 /(12.+3*19.+127.);
  pF=19*3/(12.+3*19.+127.);
  pI=127/(12.+3*19.+127.);

  nucleusRecoil0Aux(0.3,fDvMaxwell,12,6,0,0,0,
     Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);
  NC=cutRecoilResult(dNdE,Emin,30);

  nucleusRecoilAux(0.3,fDvMaxwell,19,Z_F,J_F19,S00F19,S01F19,S11F19,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  
  NF=cutRecoilResult(dNdE,Emin,30);


  nucleusRecoil0Aux(0.3,fDvMaxwell,19,Z_F,J_F19,Sp_F19,Sn_F19,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  
  NF=cutRecoilResult(dNdE,Emin,30);
 
  nucleusRecoilAux(0.3,fDvMaxwell,127,Z_I,J_I127,S00I127,S01I127,S11I127,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE);  
  NI=cutRecoilResult(dNdE,Emin,30);
  
  printf("COUP events:=%.2E\n", (NC*pC+NF*pF+NI*pI)*Exposure);
   
}


int main(int narg, char** args)
{ double Mwimp, csSIp,csSIn,csSDp,csSDn;
  double vRotation=220, vSun=225.2,vEsc=550.;

  if(narg < 6)
  {
    printf("Parameters expected: Mwinp[GeV], csSIp, csSIn, csSDp,csSDn[pb]\n"); 
    return 1;
  }   

  if(sscanf(args[1],"%lf",&Mwimp)==1 &&
     sscanf(args[2],"%lf",&csSIp)==1 &&
     sscanf(args[3],"%lf",&csSIn)==1 &&
     sscanf(args[4],"%lf",&csSDp)==1 &&
     sscanf(args[5],"%lf",&csSDn)==1) 
    printf("Model parameters:\n Mwimp=%.2E csSIp=%.2E, csSIn=%.2E,csSDp=%.2E,csSDn=%.2E\n",
                          Mwimp, csSIp, csSIn,csSDp,csSDn);
  else { printf("Wrong parameters\n"); return 2;}  

  DAMA_NAI(vRotation, vSun, vEsc,Mwimp, csSIp,csSIn,csSDp,csSDn);

  SetfMaxwell(vRotation,vSun,vEsc); 
  Xenon10(Mwimp, csSIp,csSIn,csSDp,csSDn );
  CDMS_123(Mwimp, csSIp,csSIn,csSDp,csSDn ); 
  CDMS_2006(Mwimp, csSIp,csSIn,csSDp,csSDn);
  COUPP(Mwimp, csSIp,csSIn,csSDp,csSDn);   

  Ge_(Mwimp, csSIp,csSIn,csSDp,csSDn);   
  
  He3_100g(1., 2, Mwimp, csSIp,csSIn,csSDp,csSDn);

}
