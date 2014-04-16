#include"../sources/micromegas.h"
#include"lib/pmodel.h"
                                                                                    

#define SUGRA suspectSUGRA 
/*#define SUGRA isajetSUGRA   */   /*=====for ISAJET   ======*/
/*#define SUGRA softSusySUGRA */   /*=====for SOFTSUSY ======*/
/*#define SUGRA sphenoSUGRA   */   /*=====for SPHENO   ======*/

extern double bglu_(void);

extern double deltaMs(void);
extern double deltaMd(void);

int main(void)
{
  int fast=0;  
  double Omega,Xf;
  double Beps=1.E-6;
  char mess[10]; 
  int err,i;  
  double m0,mhf,a0,tb;

  double   gMG1, gMG2, gMG3,
           gAl,  gAt,  gAb,  sgn,  gMHu,  gMHd,
           gMl2, gMl3, gMr2, gMr3,
           gMq2, gMq3, gMu2, gMd2, gMu3, gMd3;
                     
  struct msugraData
  { char label;
    double m0;
    double mhf;
    double a0;
    double tb;
    double sgn;
    double mtop; } testData[10]=
    {
/*     { 'A',  107,   600, 0,  5,  1, 174.3 },*/
      { 'A',  100,   100, 0,  10,  1, 174.3 },
      { 'B',   57,   250, 0, 10,  1, 174.3 },
      { 'C',   80,   400, 0, 10,  1, 174.3 },
      { 'D',  101,   525, 0, 10, -1, 174.3 },
      { 'G',  113,   375, 0, 20,  1, 174.3 },
      { 'H',  244,   935, 0, 20,  1, 174.3 },
      { 'I',  181,   350, 0, 35,  1, 174.3 },
      { 'J',  299,   750, 0, 35,  1, 174.3 },
      { 'K', 1001,  1300, 0, 46, -1, 174.3 },
      { 'L',  303,   450, 0, 47,  1, 174.3 }
  };
  
  for(i=0;i<10;i++)
  {      
    m0= testData[i].m0;
    mhf=testData[i].mhf;
    a0= testData[i].a0;
    tb= testData[i].tb;
    sgn=testData[i].sgn;
    assignVal("Mtp",testData[i].mtop);

    printf("point '%c' :",testData[i].label);      

    gMG1=mhf, gMG2=mhf,gMG3=mhf; gAl=a0,  gAt=a0,  gAb=a0;
    gMHu=m0,  gMHd=m0, gMl2=m0,  gMl3=m0, gMr2=m0, gMr3=m0,
    gMq2=m0,  gMq3=m0, gMu2=m0,  gMd2=m0, gMu3=m0, gMd3=m0;

    err=SUGRA(tb,  
      gMG1, gMG2, gMG3, gAl, gAt, gAb, sgn, gMHu, gMHd,
      gMl2, gMl3, gMr2, gMr3, gMq2, gMq3, gMu2, gMd2, gMu3, gMd3);

    if(err<0){ printf(" No RGE solution \n"); continue; }
     
    assignValW("dMb", deltaMb());
    assignValW("dMs", deltaMs());
    assignValW("dMd", deltaMd()); 
    
printf("deltaMb=%E deltaMs=%E   deltaMd=%E\n", deltaMb(),deltaMs(),deltaMd());

    err=sortOddParticles(mess);
    if(err) { printf("Can't calculate %s\n",mess); continue;}
    if(strcmp(mess,"~o1")) { printf(" ~o1 is not LSP\n"); continue;}
/*
    Omega=darkOmega(&Xf,fast,Beps);
    printf("Omega=%.2E\n", Omega);
*/    
  { double pA0[2],pA5[2],nA0[2],nA5[2];
    double bglu=0;
    double Nmass=0.939; /*nucleon mass*/
    double ffS0P[3]={0.026,0.020,0.118},
/*            ffS0P[3]={0.034,0.023,0.14}, */
           ffS0N[3]={0.036,0.014,0.118},
           ffV5P[3]={-0.48, 0.78,-0.15},
           ffV5N[3]={0.78 ,-0.48,-0.15}; 
    double SCcoeff;
          
/*     bglu=bglu_(); */ 

         

    setProtonFF(ffS0P,ffV5P, NULL);
    setNeutronFF(ffS0N,ffV5N,NULL);

    nucleonAmplitudes(bglu, pA0,pA5,nA0,nA5);
    
    SCcoeff=4/M_PI*3.8937966E8*pow(Nmass*lopmass_()/(Nmass+ lopmass_()),2.);

printf("SI:%E\n", SCcoeff*pA0[0]*pA0[0]);
    
/*    printf(" proton/neutron SI %E %E ( %E %E)\n", 
        SCcoeff*pA0[0]*pA0[0],SCcoeff*nA0[0]*nA0[0],
        SCcoeff*pA0[1]*pA0[1],SCcoeff*nA0[1]*nA0[1]);
    printf(" proton/neutron SD %E %E ( %E %E)\n", 
        SCcoeff*pA5[0]*pA5[0],SCcoeff*nA5[0]*nA5[0],
        SCcoeff*pA5[1]*pA5[1],SCcoeff*nA5[1]*nA5[1]); 
*/        
  }
    
    
  }
  return 0;
}
