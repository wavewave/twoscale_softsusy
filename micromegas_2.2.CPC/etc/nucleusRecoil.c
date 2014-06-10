#include"../sources/micromegas.h"

int main(void)
{ double dNdE[200]; 
  double Mwimp, csSIp,csSIn,csSDp,csSDn,Leff;

  printf("Number of events for different nuclei ( /kg/day)\n");

  Mwimp=50;  csSIp=0; csSIn=0;  csSDp=0.01; csSDn=0.01;
  
printf("Parameters:\n Mwimp=%.2E csSIp=%.2E, csSIn=%.2E,csSDp=%.2E,csSDp=%.2E\n",
                          Mwimp, csSIp, csSIn,csSDp,csSDn);

 SetfMaxwell(220.,244.4,700.);

printf("H1    %.2E\n",nucleusRecoil0Aux(0.3,fDvMaxwell,
    1,Z_H,J_H1,Sp_H1,Sn_H1,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 

printf("He3   %.2E\n",nucleusRecoil0Aux(0.3,fDvMaxwell,
    3,Z_He,J_He3,Sp_He3,Sn_He3,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 
 
printf("F19   %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    19,Z_F,J_F19,S00F19,S01F19,S11F19,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 
/*
printf("F19   %.2E\n",nucleusRecoil0Aux(0.3,fDvMaxwell,
    19,Z_F,J_F19,Sp_F19, Sn_F19,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 
*/
    
printf("Na23  %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    23,Z_Na,J_Na23,S00Na23,S01Na23,S11Na23,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 


printf("Al27  %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    27,Z_Al,J_Al27,S00Al27,S01Al27,S11Al27,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 

printf("Si29  %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    29,Z_Si,J_Si29,S00Si29,S01Si29,S11Si29,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 

printf("K39   %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    39,Z_K,J_K39,S00K39,S01K39,S11K39,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 

printf("Ge73  %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    73,Z_Ge,J_Ge73,S00Ge73,S01Ge73,S11Ge73,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 

printf("Nb93  %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    93,Z_Nb,J_Nb93,S00Nb93,S01Nb93,S11Nb93,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE)); 

printf("Te125 %.2E\n", nucleusRecoilAux(0.3,fDvMaxwell,
    125,Z_Te,J_Te125,S00Te125,S01Te125,S11Te125,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE));  
     
printf("I127  %.2E\n",nucleusRecoilAux(0.3,fDvMaxwell,
    127,Z_I,J_I127,S00I127,S01I127,S11I127,
     Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE));
     
printf("Xe129 %.2E\n", nucleusRecoilAux(0.3,fDvMaxwell,
    129,Z_Xe,J_Xe129,S00Xe129,S01Xe129,S11Xe129,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE));  
    
printf("Xe131 %.2E\n", nucleusRecoilAux(0.3,fDvMaxwell,  
    131,Z_Xe,J_Xe131,S00Xe131,S01Xe131,S11Xe131,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE));  

printf("Cs133 %.2E\n", nucleusRecoil0Aux(0.3,fDvMaxwell,
    133,Z_Cs,J_Cs133,Sp_Cs133,Sn_Cs133,
    Mwimp, csSIp,csSIn,csSDp, csSDn, dNdE));  
}    
