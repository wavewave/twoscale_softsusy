
#include"../sources/micromegas.h"
#include"lib/pmodel.h"
int main(int argc,char** argv)
{
  double Pcm,Xf;
  int err; 
  numout* cc;
  double cosmin, cosmax;
  
  if(argc==1)
  {
     printf(" The program needs 1 argument:\n"
            "name of file with MSSM parameters\n");
     exit(1);
  }
  
  err=readVar(argv[1]);
  if(err==-1)     {printf("Can not open the file\n"); exit(2);}
  else if(err>0)  { printf("Wrong file contents at line %d\n",err);exit(3);}


  printf("\nExamples of calculations of particle widths\n");
  decay2Info("Z",stdout);
  decay2Info("W+",stdout);


  printf("\nExamples of calculations of cross sections\n");
  Pcm=500;
  cosmin=-0.99;
  cosmax=0.99;
  printf("Process e,E->2*x at Pcm=%.3E GeV\n",Pcm);
  cc=newProcess("e,E->2*x","eE_2x");
  if(cc)
  { int ntot,l;
    char * name[4];
    procInfo1(cc,&ntot,NULL,NULL);
    for(l=1;l<=ntot; l++)
    { int err;
      double cs;
      procInfo2(cc,l,name,NULL);
      printf("%3s,%3s -> %3s %3s  ",name[0],name[1],name[2],name[3]);
      cs= cs22(cc,l,Pcm,cosmin,cosmax,&err);
      if(err) printf("Error\n");
      else if(cs==0.) printf("Zero\n");
      else printf("%.2E [pb]\n",cs); 
    }
  } 

  printf("\nNeutralino annihilation at freez-out");
  Xf=25;
 
  cc=newProcess("","omg_to1___to1");
  if(cc)
  { int ntot,l;
    char * name[4];
    double mass[4];
    procInfo1(cc,&ntot,NULL,NULL);
    for(l=1;l<=ntot; l++)
    { int err;
      double cs;
      procInfo2(cc,l,name,mass);
      if(l==1) { Pcm=mass[0]*sqrt(3/(2*Xf)); printf("(Pcm=%.2E)\n",Pcm);}
      printf("%3s,%3s -> %3s %3s  ",name[0],name[1],name[2],name[3]);
      cs= cs22(cc,l,Pcm,-0.9,0.9,&err);
      if(err) printf("Error\n");
      else if(cs==0.) printf("Zero\n");
      else printf("%.2E [pb]\n",cs); 
    }
  }
}
