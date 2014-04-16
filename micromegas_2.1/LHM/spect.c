#include"../sources/micromegas.h"
#include"../sources/micromegas_aux.h" 
#include"lib/pmodel.h"


int main(int argc,char** argv)
{ 
  int err,outP;
  double M,Emin,Ntot,Etot,sigmaV,v=0.001,fi,tab[250];
  
  char mess[100];
  char txt[100];

  if(argc==1)
  {
     printf(" The program needs 1 argument:\n"
            "name of file with parameters\n");
     exit(1);
  }

  err=readVar(argv[1]);
  if(err==-1)     {printf("Can not open the file\n"); exit(2);}
  else if(err>0)  { printf("Wrong file contents at line %d\n",err);exit(3);}


  outP=0;    /* for gamma rays */  
  Emin=0.1;  /* Erergy cut     */
  fi=0;      /* angle of sight */                                                                                                                                                                         

  err=sortOddParticles(mess); 
   if(err) { printf("Can't calculate %s\n",mess); return 1;}  

  sigmaV=calcSpectrum(v,outP,tab,&err);  /* sigma*v in cm^3/sec */    
  
  M=lopmass_();

  spectrInfo(Emin/M,tab, &Ntot,&Etot); 
  sprintf(txt,"%s: N=%.2e,<E/2M>=%.2f,vsc=%.2e sm^3/sec,M(%s)=%.2e", 
  outNames[outP],Ntot,Etot,sigmaV,mess,M); 

  spectrTable(tab,"tab",txt, Emin/M ,300);

  system("../CalcHEP_src/bin/tab_view < tab&");

  
  printf("gamma flux [ph/cm^2/s/sr] =%.2E\n",
        HaloFactor(fi,rhoQisotermic)*sigmaV*Ntot/M/M);
        
{ double e[6];
  int i;
  printf("Check of energy conservation:\n"); 
  for(i=0;i<6;i++)
  {    
     sigmaV=calcSpectrum(v,i,tab,&err);
     spectrInfo(Emin/M,tab, NULL,e+i);
  } 
  printf("1 = %.2f\n",e[0]+2*(e[1]+e[2]+e[3]+e[4]+e[5]) );
}     

  return 0;
}
