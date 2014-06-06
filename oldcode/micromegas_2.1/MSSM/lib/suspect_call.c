#include"suspect_path.h"

/*===================================*/
#include"pmodel.h"
#include"pmodel_aux.h"
#include"../../sources/micromegas_aux.h"
#include<sys/wait.h>
#include<unistd.h>

#define FIN  "suspect2_lha.in"
#define FOUT "suspect2_lha.out"

static int SystemCall()
{ 
  char buff[2000];
  int err,del=getdelfilesstat_();

  if(!access(FOUT,R_OK)) unlink(FOUT);

  sprintf(buff,"%s/suspect.exe",SUSPECT);
  if(access( buff,X_OK))
  { printf("Executable \n %s\n is not found. Program stops.\n",buff);
    exit(13);
  }  

  err=system(buff);   
  
  if(WIFSIGNALED(err) ||WEXITSTATUS(err) )
  { printf("Problem in execution of \n %s\n", buff);
    return -1;
  }  
   
  err=readLesH(FOUT,0);
  if(del){unlink(FIN);unlink(FOUT);unlink("suspect2.out");}
 
  assignValW("dMb",deltaMb());
  assignValW("dMs", deltaMs());
  assignValW("dMd", deltaMd());
          
  return err;
}


static int SuSpectSugraLesH(double tb, double gMG1,double gMG2,double gMG3,
    double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
    double gMl2,double gMl3,double gMr2,double gMr3,
    double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3) 
{  double m0,mh,a0;
   double MHu2, MHd2;
   int i,ichoice[11]={1,21, 1, 1, 1, 1, 2, 1, 2, 2,  0};
   
   FILE*  f=fopen("suspect2_lha.in","w");
   if(f==NULL) return -1;
   
   fprintf(f,"Block MODSEL                 # Select model\n"   
           " 1    1                        # sugra\n"
           "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5); 
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));
   fprintf(f,"Block MINPAR                 # Input parameters\n");

   a0=gAl;
   mh=gMG2; 

   MHu2=gMHu*fabs(gMHu);
   MHd2=gMHd*fabs(gMHd);
   m0=fabs(gMHu);

   fprintf(f," 1   %.8E       # m0\n",       m0); 
   fprintf(f," 2   %.8E       # m1/2\n",     mh);   
   fprintf(f," 3   %.8E       # tanb\n",     tb);
   fprintf(f," 4   %.0f     # sign(mu)\n", sgn);
   fprintf(f," 5   %.8E       # A0\n",       a0);

   fprintf(f,"Block SU_ALGO # ichoice \n");
   for(i=0;i<11;i++) fprintf(f," %d   %d  # \n", i+1, ichoice[i]);
   fprintf(f,"Block EXTPAR\n");
   fprintf(f," 1   %.8E      # MG1\n",  gMG1);
   fprintf(f," 2   %.8E      # MG2\n",  gMG2);
   fprintf(f," 3   %.8E      # MG3\n",  gMG3);

   fprintf(f," 11  %.8E      # At \n",  gAt);
   fprintf(f," 12  %.8E      # Ab \n",  gAb);
   fprintf(f," 13  %.8E      # Atau\n", gAl);

   fprintf(f," 14  %.8E      # Au \n",  gAt);
   fprintf(f," 15  %.8E      # Ad \n",  gAb);
   fprintf(f," 16  %.8E      # Al \n", gAl);
         
   fprintf(f," 21  %.8E      # MHd^2\n",MHd2);
   fprintf(f," 22  %.8E      # MHu^2\n",MHu2);   

   fprintf(f," 25  %.8E      # tb\n",tb); 
   fprintf(f," 26  %.8E      # sgn(mu)\n",sgn);

   fprintf(f," 31  %.8E      # Ml1\n",  gMl2);
   fprintf(f," 32  %.8E      # Ml2\n",  gMl2); 
   fprintf(f," 33  %.8E      # Ml3\n",  gMl3);
   fprintf(f," 34  %.8E      # MR2\n",  gMr2);
   fprintf(f," 35  %.8E      # MR2\n",  gMr2); 
   fprintf(f," 36  %.8E      # MR3\n",  gMr3);

   fprintf(f," 41  %.8E      # Mq1\n",  gMq2);
   fprintf(f," 42  %.8E      # Mq2\n",  gMq2); 
   fprintf(f," 43  %.8E      # Mq3\n",  gMq3);
   fprintf(f," 44  %.8E      # Mu1\n",  gMu2);
   fprintf(f," 45  %.8E      # Mu2\n",  gMu2); 
   fprintf(f," 46  %.8E      # Mu3\n",  gMu3);
   fprintf(f," 47  %.8E      # Md1\n",  gMd2);
   fprintf(f," 48  %.8E      # Md2\n",  gMd2); 
   fprintf(f," 49  %.8E      # Md3\n",  gMd3);
   fclose(f);
   assignValW("tb",tb);
   return 0;
}

static int SuSpectEWSBLesH(void)
{  
   int i,ichoice[11]={0, 21, 1, 1, 0, 0, 2, 1, 2, 2, 0};
   
   FILE*  f=fopen("suspect2_lha.in","w");
   if(f==NULL) return -1;
                                      
   fprintf(f,"Block MODSEL                 # Select model\n"   
           " 1    0                        # Low energy MSSM\n"
           "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5); 
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));

   fprintf(f,"Block MINPAR                 # Input parameters\n");
   fprintf(f," 3   %.8E       # tanb\n",     findValW("tb"));

   fprintf(f,"Block SU_ALGO # ichoice\n");
   for(i=0;i<11;i++) fprintf(f," %d   %d  \n", i+1, ichoice[i]);

   fprintf(f,"Block EXTPAR\n");
   fprintf(f," 0   -1        # EWSB\n"); 
   fprintf(f," 1   %.8E      # MG1\n",findValW("MG1"));
   fprintf(f," 2   %.8E      # MG2\n",findValW("MG2"));
   fprintf(f," 3   %.8E      # MG3\n",findValW("MG3"));

   fprintf(f," 11  %.8E      # At \n",findValW("At"));
   fprintf(f," 12  %.8E      # Ab \n",findValW("Ab"));
   fprintf(f," 13  %.8E      # Atau\n",findValW("Al"));

   fprintf(f," 14  0         # Au\n"); 
   fprintf(f," 15  0         # Ad \n");
   fprintf(f," 16  0         # Al \n");
         
   fprintf(f," 23  %.8E      # mu\n",findValW("mu"));
   fprintf(f," 24  %.8E      # MA\n",findValW("MH3"));   
   fprintf(f," 25  %.8E      # tb\n",findValW("tb")); 
   fprintf(f," 31  %.8E      # Ml1\n",findValW("Ml2"));
   fprintf(f," 32  %.8E      # Ml2\n",findValW("Ml2")); 
   fprintf(f," 33  %.8E      # Ml3\n",findValW("Ml3"));
   fprintf(f," 34  %.8E      # MR2\n",findValW("Mr2"));
   fprintf(f," 35  %.8E      # MR2\n",findValW("Mr2")); 
   fprintf(f," 36  %.8E      # MR3\n",findValW("Mr3"));

   fprintf(f," 41  %.8E      # Mq1\n",findValW("Mq2"));
   fprintf(f," 42  %.8E      # Mq2\n",findValW("Mq2")); 
   fprintf(f," 43  %.8E      # Mq3\n",findValW("Mq3"));
   fprintf(f," 44  %.8E      # Mu1\n",findValW("Mu2"));
   fprintf(f," 45  %.8E      # Mu2\n",findValW("Mu2")); 
   fprintf(f," 46  %.8E      # Mu3\n",findValW("Mu3"));
   fprintf(f," 47  %.8E      # Md1\n",findValW("Md2"));
   fprintf(f," 48  %.8E      # Md2\n",findValW("Md2")); 
   fprintf(f," 49  %.8E      # Md3\n",findValW("Md3"));
   fclose(f);
   return 0;
}

static int SuSpectAmsbLesH(char * fname, double m0,double m32, double  tb, int  sgn)
{
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;

   fprintf(f,"Block MODSEL                 # Select model\n"
             " 1    12                     # amsb\n"
             "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5);
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));

   fprintf(f,"Block MINPAR                 # Input parameters\n");
   fprintf(f," 1   %.8E       # m0\n",       m0);    
   fprintf(f," 2   %.8E       # m3/2\n",     m32);
   fprintf(f," 3   %.8E       # tanb\n",     tb);
   fprintf(f," 4   %d         # sign(mu)\n", sgn);
   { int i;
     for(i=5;i<12;i++)
     fprintf(f," %d    1         #\n",i);
   }                
   fclose(f);
   assignValW("tb",tb);
   return 0;
}




int  suspectSUGRA(double tb, double gMG1,double gMG2,double gMG3,
             double gAl, double gAt, double gAb, double sgn, double gMHu, double gMHd,
             double gMl2,double gMl3,double gMr2,double gMr3,
             double gMq2,double gMq3,double gMu2,double gMu3,double gMd2,double gMd3)
{ 

   if(SuSpectSugraLesH(tb, gMG1,gMG2,gMG3,
             gAl, gAt, gAb, sgn, gMHu, gMHd,
             gMl2,gMl3,gMr2,gMr3,
             gMq2,gMq3,gMu2,gMu3,gMd2,gMd3))
   {printf("can not write down %s file\n",FIN); exit(10);}
   return SystemCall();
}

#define xxxSUGRAc  suspectSUGRAc
#define xxxSUGRA   suspectSUGRA
#define xxxsugra_  suspectsugra_ 
#include "sugrac.inc"


int  suspectAMSB(double m0,double m32, double tb, double sgn)
{    
   if(SuSpectAmsbLesH(FIN,m0,m32,tb, (int)sgn))
   { printf("can not write down %s file\n",FIN); exit(10);}
       
   return SystemCall();
}

#define xxxAMSBc  suspectAMSBc
#define xxxAMSB   suspectAMSB
#define xxxamsb_  suspectamsb_ 
#include "amsb.inc"


int suspectEwsbMSSM(void)
{ 
   int err;
   double Au,Ad,Am;
   Au=findValW("Au");Ad=findValW("Ad");Am=findValW("Am");
   
   if(SuSpectEWSBLesH()){printf("can not write down %s file\n",FIN); exit(10);}
   err= SystemCall();
   
   assignValW("Au",Au);assignValW("Ad",Ad);assignValW("Am",Am);
   return err;
}

#define xxxEwsbMSSMc  suspectEwsbMSSMc
#define xxxEwsbMSSM   suspectEwsbMSSM
#define xxxewsbmssm_  suspectewsbmssm_ 
#include "pmssm.inc"

