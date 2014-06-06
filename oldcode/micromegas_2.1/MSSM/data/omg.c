#define EwsbMSSM suspectEwsbMSSM 
/*#define EwsbMSSM isajetEwsbMSSM */
/*#define EwsbMSSM sphenoEwsbMSSM */
/*#define EwsbMSSM softSusyEwsbMSSM */

#include"../sources/micromegas.h"
#include"lib/pmodel.h"

extern double varValue(numout*cc,char * name);

int main(int argc,char** argv)
{
  int    fast=1; 
  double Beps=1E-6;
  
  double cut=0.01;
  double Omega,Xf;
  char mess[20]; 
  int i,err;  
  
/* to save the SLHA  input/output file  uncomment */
/*  delFiles(0);*/

  if(argc==1) 
  { 
     printf(" The program needs parameters,\n"
            "names of files which contain MSSM parameters\n");
     exit(1);
  }

  for(i=1;i<argc;i++)
  { 
     printf("Initial file  \"%s\"\n",argv[i]);
     
     err=readVar(argv[i]);
          
     if(err==-1)     {printf("Can not open the file\n"); continue;}
     else if(err>0)  { printf("Wrong file contents at line %d\n",err);continue;}

     err=EwsbMSSM();
     if(err) 
     { printf("Problem with spectrum calculation\n");
       continue;
     }
               
     err=sortOddParticles(mess);
     if(err<0) {printf("Can't calculate %s\n",mess); continue;}

     HiggsMasses(stdout);     
     printMasses(stdout,1);

     if(strcmp(mess,"~o1")) {  printf("~o1 is not LSP\n"); continue; }
     o1Contents(stdout);     

     Omega=darkOmega(&Xf,fast,Beps);
     printf("Xf=%.2E Omega=%.2E  (file: %s)\n", Xf, Omega,  argv[i]);
     printChannels(Xf,cut,Beps,1,stdout); 

{ 
  numout *cc;
  double pv[6],sc[6],dn[6],vv[6];
  double Pcm=0.1, COScm=0;
  int Qnum;     
  double ampl[10], qMass;
  char * amplName[10];
  int dim;
  
  for(Qnum=1;Qnum<=6;Qnum++) 
  { dn[Qnum-1]=LOP_quark_AMPL("~o1",Pcm,COScm, Qnum,&dim,amplName,ampl,NULL,&qMass,&cc);
    for(i=0;i<dim;i++)
     if(strcmp(amplName[i],"S0Q0XX")==0)  sc[Qnum-1]=ampl[i]/qMass;
     else if(strcmp(amplName[i],"V5Q5XX")==0) pv[Qnum-1]=ampl[i];  
  }
  printf("micrOMEGAs  amplitudes\n");
  printf("amplitudes^2/CS-1: %9.2E %9.2E %9.2E %9.2E %9.2E %9.2E\n",
     dn[0],dn[1],dn[2],dn[3],dn[4],dn[5]);

  printf("Quark                d         u         s         c         b         t\n"); 
  printf("PV     amplitudes: %9.2E %9.2E %9.2E %9.2E %9.2E %9.2E\n",
   pv[0],pv[1],pv[2],pv[3],pv[4],pv[5]);

  printf("SS/Mq  amplitudes: %9.2E %9.2E %9.2E %9.2E %9.2E %9.2E\n",
   sc[0],sc[1],sc[2],sc[3],sc[4],sc[5]);

  printf("ELLIS amplitudes\n");
  ELLIS_AMPL(cc,Pcm,COScm,pv,sc);
  printf("PV     amplitudes: %9.2E %9.2E %9.2E %9.2E %9.2E %9.2E\n",
   pv[0],pv[1],pv[2],pv[3],pv[4],pv[5]);

  printf("SS/Mq  amplitudes: %9.2E %9.2E %9.2E %9.2E %9.2E %9.2E\n",
   sc[0],sc[1],sc[2],sc[3],sc[4],sc[5]);

}     
     
  }
  return 0;
}
