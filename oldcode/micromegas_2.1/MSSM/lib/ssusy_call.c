#include"ssusy_path.h"

/*===================================*/
#include"../../sources/micromegas_aux.h"
#include"pmodel.h"
#include"pmodel_aux.h"
#include<sys/wait.h>

#include<unistd.h>

#define FIN  "LesHin"
#define FOUT "LesHout"

static int SystemCall()
{ 
  char buff[2000];
  int err,del=getdelfilesstat_();

  if(!access(FOUT,R_OK)) unlink(FOUT);

  sprintf(buff,"%s/softpoint.x",SOFTSUSY);
  if(access( buff,X_OK))
  { printf("Executable \n %s\n is not found. Program stops.\n",buff);
    exit(13);
  }
    
  { FILE *f=fopen(FIN,"a");
     fprintf(f,"%s\n%s\n","Block SOFTSUSY               # SOFTSUSY specific inputs",
     "         2   0                    # quark mixing option");
     fclose(f);
  }  


  sprintf(buff,"pwd=`pwd`; cd %s ;  ./softpoint.x leshouches < $pwd/%s > $pwd/%s",SOFTSUSY,FIN,FOUT);
 
  err=system(buff);   
  
  if(WIFSIGNALED(err) ||WEXITSTATUS(err) )
  { printf("Problem in execution of \n %s\n", buff);
    return -1;
  }  
   
  err=readLesH(FOUT,0);
  if(del){unlink(FIN);unlink(FOUT);}
  assignValW("dMb",deltaMb());
  assignValW("dMs", deltaMs());
  assignValW("dMd", deltaMd());
          
  return err;
}


int  softSusySUGRA(double tb, double gMG1,double gMG2,double gMG3,
             double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
             double gMl2,double gMl3,double gMr2,double gMr3,
             double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3)
{ 

   int err=sugraLesH(FIN, tb, gMG1,gMG2,gMG3,
             gAl, gAt, gAb, sgn, gMHu, gMHd,
             gMl2,gMl3,gMr2,gMr3,
             gMq2,gMq3,gMu2,gMu3,gMd2,gMd3);

   if(err) {printf("can not write down LesHin  file\n"); exit(10);} 
    
   return SystemCall();
}



int  softSusyAMSB(double m0,double m32, double tb, double sgn)
{ 
   int err=amsbLesH(FIN, m0,m32, tb, (int)sgn);

   if(err) {printf("can not write down LesHin  file\n"); exit(10);}


   return SystemCall();
}

#define xxxAMSBc softSusyAMSBc
#define xxxAMSB  softSusyAMSB
#define xxxamsb_ softsusyamsb_ 
#include "amsb.inc"


int  softSusyGMSB(double L,double Mmess,  double tb, double sgn, int N5,double cGrav)
{ 
   int err=gmsbLesH(FIN,  L, Mmess, tb, (int)sgn, N5, cGrav);
   if(err) {printf("can not write down LesHin  file\n"); exit(10);}
          
   return SystemCall();
}

int  softSusyEwsbMSSM(void)
{  int err;
   double Au,Ad,Am;
   Au=findValW("Au");Ad=findValW("Ad");Am=findValW("Am");
   if(EWSBLesH(FIN)){printf("can not write down LesHin  file\n"); exit(10);}
   err= SystemCall();
   assignValW("Au",Au);assignValW("Ad",Ad);assignValW("Am",Am);
   return err; 
}

#define xxxEwsbMSSMc softSusyEwsbMSSMc
#define xxxEwsbMSSM  softSusyEwsbMSSM
#define xxxewsbmssm_ softsusyewsbmssm_ 
#include "pmssm.inc"
