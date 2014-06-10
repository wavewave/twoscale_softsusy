     
#define WIMP_NUCLEON     
#define WIMP_NUCLEUS      
 

#include"../sources/micromegas.h"
#include"lib/pmodel.h"


int main(int argc,char** argv)
{  int err;
   char mess[10];
   int ii,iimax;
   
  int fast=1;
  double Beps=8.E-2, cut=0.01;
  double Omega,Xf;   
  double   ffS0P[3]={0.033,0.023,0.26},
           ffS0N[3]={0.042,0.018,0.26},
           ffV5P[3]={-0.427, 0.842,-0.085},
           ffV5N[3]={ 0.842,-0.427,-0.085}; 
  double spin,s0,delun,deldn,delsn;
  double mB1,mh,del,sin,sip,sdn,sdp,mlsp,mul,mtl,mbl,mw1,mz1,mlkp,fp,fn,ap,an;
  double f,kap,sa;
   FILE *f1 = fopen("lhm_all.dat","w");
FILE *f2 = fopen("lhm_wmap.dat","w");
FILE *f3 = fopen("lhm_wmap_low.dat","w");
  if(argc==1)
  { 
      printf(" Correct usage:  ./main  <file with NMSSM parameters> \n");
      printf("Example: ./main data1.par\n");
      exit(1);
  }
                               
  err=readVar(argv[1]);
  
  if(err==-1)     {printf("Can not open the file\n"); exit(1);}
  else if(err>0)  { printf("Wrong file contents at line %d\n",err);exit(1);}
           

  if(err) 
  { printf("Problem with RGE solution or spectrum calculation\n");
     exit(1);
  }

iimax=100000;

  for(ii=0;ii<iimax;ii++)
  { f=300.+drand48()*2700.;	  
    kap=0.11+drand48()*0.99;
    sa=0.1+drand48()*0.86;
    mh=120.+ drand48()*380.;
     spin=55+drand48()*18;
     s0=30.+drand48()*10;
     deldn=0.83+drand48()*0.024;
     delun=-0.44+drand48()*0.026;
     delsn=-0.103+drand48()*0.036;
double  ffV5P[3]={delun, deldn,delsn},
      ffV5N[3]={ deldn,delun,delsn}; 

   assignValW("f",f);
   assignValW("kappa",kap);
   assignValW("kappal",kap);
   assignValW("MH",mh);
   assignValW("sa",sa);
/*   
printf("input: %d %.3E  %.3E  %.3E %.3e \n",ii,f,kap,sa,mh); 
*/	  
  err=sortOddParticles(mess);
if(err) { printf("Can't calculate %s %d\n",mess,err); continue;}

mlkp=findParam("MAH",&err);
mul=findParam("Muo",&err);
mtl=findParam("Mt1",&err);
mbl=findParam("Mdo",&err);

if(ii<15866) continue;
if(err) { printf("Can't calculate %s %d\n",mess,err); continue;}

printMasses(stdout,1);
printf("LSP mass %s \n",mess);
if(strcmp(mess,"~A")) continue;

 Omega=darkOmega(&Xf,fast,Beps);
printf("Xf=%.2e Omega=%.2e\n",Xf,Omega);
 /* printChannels(Xf,cut,Beps,1,stdout);
*/
 

     
  getScalarFF(0.553,18.9,spin,s0,ffS0P, ffS0N);
 /* printf("protonFF  d %E, u %E, s %E\n",ffS0P[0],ffS0P[1],ffS0P[2]);                               
  printf("neutronFF d %E, u %E, s %E\n",ffS0N[0],ffS0N[1],ffS0N[2]);
*/
/* NULL argument signales the reassignment does not need. */
  setProtonFF(ffS0P,ffV5P, NULL);
  setNeutronFF(ffS0N,ffV5N,NULL);
 /* printf("protonFF  d %E, u %E, s %E\n",ffV5P[0],ffV5P[1],ffV5P[2]);                               
  printf("neutronFF d %E, u %E, s %E\n",ffV5N[0],ffV5N[1],ffV5N[2]);
*/
/* User has options to change parameters of DM velocity  distribution 
*/   
   SetfMaxwell(220.,244.4,600.);     
   SetfDelta(350.);

/* Parameters of Fermi nucleus distribution are reseted  by */
   SetFermi(1.23,-0.6,0.52);
/*  then half-density radius for Fermi distribution: 
          c=arg1*A^(1/3) + arg2
    and  a=arg3 is the surface thickness.
    All parameter in [fm] units.      
*/
  double pA0[2],pA5[2],nA0[2],nA5[2];
  double Nmass=0.939; /*nucleon mass*/
  double SCcoeff;        

  nucleonAmplitudes(NULL, pA0,pA5,nA0,nA5);
  
   fp=pA0[0];
   ap=pA5[0];
   fn=nA0[0];
   an=nA5[0]; 

  SCcoeff=4/M_PI*3.8937966E8*pow(Nmass*lopmass_()/(Nmass+ lopmass_()),2.);
  /*  printf("WIMP-nucleon cross sections:\n");
    */
    sip=SCcoeff*pA0[0]*pA0[0];
    sdp=SCcoeff*pA5[0]*pA5[0];
    sin=SCcoeff*nA0[0]*nA0[0];
    sdn=SCcoeff*nA5[0]*nA5[0];

/* printf("proton: SI  %.3E  SD  %.3E\n",sip,sdp); 
 printf("neutron: SI  %.3E  SD  %.3E\n",sin,sdn); 
*/
fprintf(f1," %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E\n",f,kap,mh,sa,spin,s0,deldn,delun,delsn,mlkp,mul,mtl,mbl,mw1,mz1,Omega,fp,fn,ap,an,sip,sin,sdp,sdn); 
if(Omega<0.136&&Omega>0.096)
{fprintf(f2," %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E\n",f,kap,mh,sa,spin,s0,deldn,delun,delsn,mlkp,mul,mtl,mbl,mw1,mz1,Omega,fp,fn,ap,an,sip,sin,sdp,sdn); 
}
if(Omega<0.136)
{fprintf(f3," %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E %.3E\n",f,kap,mh,sa,spin,s0,deldn,delun,delsn,mlkp,mul,mtl,mbl,mw1,mz1,Omega,fp,fn,ap,an,sip,sin,sdp,sdn); 
}

}

                            
  return 0;
}

