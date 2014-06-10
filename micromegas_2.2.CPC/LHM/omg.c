#include"../sources/micromegas.h"
#include"lib/pmodel.h"
 
int main(int argc,char** argv)
{
  int    fast=1; 
  double Beps=1.E-4;
  double cut=0.01;
  double Omega,Xf;
  
  int err;  
  char mess[10];
  
  if(argc==1)
  { 
      printf(" Correct usage:  ./omg <file with parameters> \n");
      exit(1);
  }
                               

  err=readVar(argv[1]);
  if(err==-1)     {printf("Can not open the file\n"); exit(1);}
  else if(err>0)  { printf("Wrong file contents at line %d\n",err);exit(1);}
           

  err=sortOddParticles(mess);
  if(err) { printf("Can't calculate %s\n",mess); exit(1);}


  printMasses(stdout,1);


  printf("Dark Matter candidate is %s\n",mess);
  
  Omega=darkOmega(&Xf,fast,Beps);
  printf("Xf=%.2E Omega=%.2E  \n", Xf, Omega);
  printChannels(Xf,cut,Beps,1,stdout); 
  
  { double pA0[2],pA5[2],nA0[2],nA5[2];
    double bglu=0;
    
    double ffS0P[3]={0.026,0.020,0.118},
           ffS0N[3]={0.036,0.014,0.118},
           ffV5P[3]={-0.48, 0.78,-0.15},
           ffV5N[3]={0.78 ,-0.48,-0.15}; 
            
          
/*     bglu=bglu_();*/
printf("bglu=%E\n",bglu);

printf("============================\n");

    setProtonFF(ffS0P,ffV5P, NULL);
    setNeutronFF(ffS0N,ffV5N,NULL);

    nucleonAmplitudes(bglu, pA0,pA5,nA0,nA5);
    printf(" proton/neutron SI %E %E ( %E %E)\n", pA0[0],nA0[0],pA0[1],nA0[1]);
    printf(" proton/neutron SD %E %E ( %E %E)\n", pA5[0],nA5[0],pA5[1],nA5[1]); 
  }
  
  
}
