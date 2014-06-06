#include"spheno_path.h"

/*===================================*/
#include"pmodel.h"
#include"pmodel_aux.h"
#include"../../sources/micromegas_aux.h"
#include<sys/wait.h>
#include<unistd.h>

#define FIN  "LesHouches.in"
#define FOUT "SPheno.spc"

static int SystemCall()
{ 
  char buff[2000];
  int err,del=getdelfilesstat_();
  FILE*f;

  if(!access(FOUT,R_OK)) unlink(FOUT);

  sprintf(buff,"%s/SPheno",SPHENO);
  if(access( buff,X_OK))
  { printf("Executable \n %s\n is not found. Program stops.\n",buff);
    exit(13);
  }  

   f=fopen("Control.in","w");
   fprintf(f,"0       | ErrorLevel\n"
             ".false. ! Calculation of branching ratios\n"
             ".false. ! Calculation of cross sections\n");
   fclose(f);

  err=system(buff);   
  
  if(WIFSIGNALED(err) ||WEXITSTATUS(err) )
  { printf("Problem in execution of \n %s\n", buff);
    return -1;
  }  
   
  err=readLesH(FOUT,0);
  if(del){ unlink(FIN);unlink(FOUT);  
           unlink("Control.in");unlink("Messages.out");unlink("SPheno.out");
         }
  assignValW("dMb",deltaMb());
  assignValW("dMs", deltaMs());
  assignValW("dMd", deltaMd());
          
  return err;
}


int  sphenoSUGRA(double tb, double gMG1,double gMG2,double gMG3,
             double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
             double gMl2,double gMl3,double gMr2,double gMr3,
             double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3)
{ 
   int err;

   err=sugraLesH(FIN, tb, gMG1,gMG2,gMG3,
             gAl, gAt, gAb, sgn, gMHu, gMHd,
             gMl2,gMl3,gMr2,gMr3,
             gMq2,gMq3,gMu2,gMu3,gMd2,gMd3);
              
   if(err) {printf("can not write down LesHouches.in file\n"); exit(10);}

   return SystemCall();
}

#define xxxSUGRAc  sphenoSUGRAc
#define xxxSUGRA   sphenoSUGRA
#define xxxsugra_  sphenosugra_
#include "sugrac.inc"


int  sphenoAMSB(double m0,double m32, double tb, double sgn)
{ 
   int err;
   err=amsbLesH(FIN, m0,m32, tb, (int)sgn);
   if(err) { printf("can not write down LesHouches.in file\n"); exit(10);}

   return SystemCall();
}

#define xxxAMSBc  sphenoAMSBc
#define xxxAMSB   sphenoAMSB
#define xxxamsb_  sphenoamsb_
#include "amsb.inc"


int  sphenoEwsbMSSM(void)
{  int err;
   double Au,Ad,Am;
   Au=findValW("Au");Ad=findValW("Ad");Am=findValW("Am");
   if(EWSBLesH(FIN)){ printf("can not write down LesHouches.in file\n"); exit(10);}
   err=SystemCall();
   assignValW("Au",Au);assignValW("Ad",Ad);assignValW("Am",Am);
   return err;
}

#define xxxEwsbMSSMc  sphenoEwsbMSSMc
#define xxxEwsbMSSM   sphenoEwsbMSSM
#define xxxewsbmssm_  sphenoewsbmssm_
#include "pmssm.inc"
