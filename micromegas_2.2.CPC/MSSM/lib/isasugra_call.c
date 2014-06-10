#include"isajet_path.h"

/*===================================*/
#include"pmodel.h"
#include"pmodel_aux.h"
#include"../../sources/micromegas_aux.h"
#include<sys/wait.h>
#include<unistd.h>

#define FIN  "slha.in" 
#define FOUT "slha.out"

static int SystemCall(int mode)
{ 
  char buff[2000];
  int err,del=getdelfilesstat_();

  if(!access(FOUT,R_OK)) unlink(FOUT);

  sprintf(buff,"%s/isajet_slha",ISAJET);
  if(access( buff,X_OK))
  { printf("Executable \n %s\n is not found. Program stops.\n",buff);
    exit(13);
  }
    
  sprintf(buff+strlen(buff)," %s %s",FIN, FOUT);
  err=system(buff);   
  
  if(WIFSIGNALED(err) ||WEXITSTATUS(err) )
  { printf("Problem in execution of \n %s\n", buff);
    return -1;
  }  
   
  err=readLesH(FOUT,mode);
  if(del){unlink(FIN);unlink(FOUT);}
          
  return err;
}


int  isajetSUGRA(double tb, double gMG1,double gMG2,double gMG3,
             double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
             double gMl2,double gMl3,double gMr2,double gMr3,
             double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3)
{ 
   int  err=sugraLesH("slha.in", tb, gMG1,gMG2,gMG3,
             gAl, gAt, gAb, sgn, gMHu, gMHd,
             gMl2,gMl3,gMr2,gMr3,
             gMq2,gMq3,gMu2,gMu3,gMd2,gMd3);
             
             

   if(err) {printf("can not write down LesHouches.in file\n"); exit(10);}
   
   err=SystemCall(1);

   return err;
}

#define xxxSUGRAc  isajetSUGRAc
#define xxxSUGRA   isajetSUGRA
#define xxxsugra_  isajetsugra_
#include "sugrac.inc"


int  isajetAMSB(double m0,double m32, double tb, double sgn)
{ 
   int err;

   err=amsbLesH(FIN, m0,m32, tb, (int)sgn);
   if(err) {printf("can not write down LesHouches.in file\n"); exit(10);}

   err=SystemCall(1);

   return err;
}

int  isajetEwsbMSSM(void)
{  int err;          
   if(EWSBLesH(FIN)){printf("can not write down LesHouches.in file\n"); exit(10);}
   err=SystemCall(0);
   return err;        
}

#define xxxEwsbMSSMc  isajetEwsbMSSMc
#define xxxEwsbMSSM   isajetEwsbMSSM
#define xxxewsbmssm_  isajetewsbmssm_
#include "pmssm.inc"
