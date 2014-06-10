#include"pmodel.h"
#include"pmodel_aux.h"
#include"pmodel_f.h"
#include<math.h>
#include"../../sources/micromegas.h"
#include"../../CalcHEP_src/c_source/model_aux/include/SLHAreader.h"

#include <ctype.h>
#include <stdio.h>

static int delFilesKey=1;
int getdelfilesstat_(void) {return delFilesKey;}
void delFiles(int x)  { delFilesKey=x; }
void delfiles_(int *x){ delFilesKey=*x;}

int sugraLesH(char *fname,  double m0, double mhf, double a0,
double tb, double sgn, double  Lambda, double aLambda, double aKappa)
{  
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;
   
   fprintf(f,
           "Block MODSEL       # Select model\n"
           "  1    1            # SUGRA\n"   
           "  3    1            # NMSSM PARTICLE CONTENT\n"
           "  9    0            # FLAG FOR MICROMEGAS (0=NO)\n" 
           " 10    0            # No scan, no ...\n"
           "Block SMINPUTS               # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5); 
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));
   fprintf(f,"Block MINPAR                 # Input parameters\n");
   
   fprintf(f," 1   %.8E       # m0\n",       m0); 
   fprintf(f," 2   %.8E       # m1/2\n",     mhf);   
   fprintf(f," 3   %.8E       # tanb\n",     tb);
   fprintf(f," 4   %.0f       # sign(mu)\n", sgn);
   fprintf(f," 5   %.8E       # A0\n",       a0);

   fprintf(f,"Block EXTPAR\n");
   fprintf(f," 61  %.8E        # L \n",  Lambda);
   fprintf(f," 63  %.8E        # A_LAMBDA\n", aLambda);
   fprintf(f," 64  %.8E        # A_K\n", aKappa);
   fclose(f);
   assignValW("tb",tb);
   return 0;
}



int EWSBLesH(char * fname)
{  
   int i;
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;
                                    
   fprintf(f,"Block MODSEL    # Select model\n"   
             "  1    0           # EWSB input\n"
             "  3    1           # NMSSM PARTICLE CONTENT\n"
             "  9    0           # FLAG FOR MICROMEGAS (0=NO, 1=YES\n"
             " 10    0           # No scan, no ...\n"
           "Block SMINPUTS    # Standard Model inputs\n");
   fprintf(f," 1   %.8E       # alpha_em^(-1)(MZ) SM MSbar\n",1/findValW("alfEMZ"));
   fprintf(f," 2   %.8E       # G_Fermi \n",1.16637E-5); 
   fprintf(f," 3   %.8E       # alpha_s(MZ) SM MSbar\n",findValW("alfSMZ"));
   fprintf(f," 5   %.8E       # mb(mb) SM MSbar\n", findValW("MbMb"));
   fprintf(f," 6   %.8E       # mtop(pole)\n",      findValW("Mtp"));
   fprintf(f," 7   %.8E       #  Mtau     \n",      findValW("Ml"));

   fprintf(f,"Block MINPAR                 # Input parameters\n");
   fprintf(f," 3   %.8E       # tanb\n",     findValW("tb"));

   fprintf(f,"Block EXTPAR\n");
   fprintf(f," 0   -1        # EWSB\n"); 
   fprintf(f," 1   %.8E      # MG1\n",findValW("MG1"));
   fprintf(f," 2   %.8E      # MG2\n",findValW("MG2"));
   fprintf(f," 3   %.8E      # MG3\n",findValW("MG3"));

   fprintf(f," 11  %.8E      # At \n",findValW("At"));
   fprintf(f," 12  %.8E      # Ab \n",findValW("Ab"));
   fprintf(f," 13  %.8E      # Atau\n",findValW("Al"));
   fprintf(f," 16  %.8E      # Am \n",findValW("Am")); 
/*   fprintf(f," 23  %.8E      # mu\n",findValW("mu")); */
/*   fprintf(f," 24  %.8E      # MA\n",findValW("MH3"));*/
/*   fprintf(f," 26  %.8E      # MA\n",findValW("MH3"));*/
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

   fprintf(f," 61  %.8E      # L\n",  findValW("LambdQ"));
   fprintf(f," 62  %.8E      # K\n",  findValW("KappaQ"));
   fprintf(f," 63  %.8E      # AL\n", findValW("aLmbdQ"));
   fprintf(f," 64  %.8E      # AK\n", findValW("aKappQ"));
   fprintf(f," 65  %.8E      # MU\n", findValW("mu"));
   
   fclose(f);
   return 0;
}


static void FillVal(int mode)
{ char name[10];
  int i,j,k;
  char* Zf[3]={"Zb","Zt","Zl"};
  char* Qmix[3]={"SBOTMIX","STOPMIX","STAUMIX"};
  double Pa[2][3]={{0,0,0},{0,0,0}};
  double Q;
  
  char* massName[35]={"Mha","Mhb","Mh1","Mh2","Mh3","MHc", "MNE1", "MNE2", "MNE3", "MNE4", "MNE5",    "MC1",  "MC2",  "MSG", "MSne", "MSnm", "MSnl", "MSeL", "MSeR", "MSmL", "MSmR", "MSl1", "MSl2", "MSdL", "MSdR", "MSuL", "MSuR", "MSsL", "MSsR", "MScL", "MScR", "MSb1", "MSb2", "MSt1","MSt2"};
  int   massId[35]  ={ 36  ,  46,  25,   35,   45,     37,1000022,1000023,1000025,1000035, 1000045, 1000024,1000037,1000021,1000012,1000014,1000016,1000011,2000011,1000013,2000013,1000015,2000015,1000001,2000001,1000002,2000002,1000003,2000003,1000004,2000004,1000005,2000005,1000006,2000006};   

  char * softName[13]={"MG1","MG2","MG3","Ml2","Ml3","Mr2","Mr3","Mq2","Mq3","Mu2","Mu3","Md2","Md3"};
  int      softId[13]={   1 ,   2 ,   3 ,  32 ,  33 ,  35 ,  36 ,  42 ,  43 ,  45 ,  46 ,  48 ,  49};

  char * mohName[11]={"Lambda","Kappa","aLmbd0","dMb","vev","Mh1R","Mh2R","Mh3R","MhaR","MhbR","MHcR"};
  int    mohId[11]  ={      1 ,     2 ,      3 ,   4 ,   5 ,   25 ,   35 ,   45 ,   36 ,   46 , 37 };

  for(i=0;i<35;i++) assignValW(massName[i],slhaVal("MASS",0.,1,massId[i]));
  Q=sqrt(fabs(findValW("MSt1")*findValW("MSt2"))); 
  for(i=0;i<11;i++) assignValW(mohName[i],slhaVal("MO_HIGGS",Q,1,mohId[i]));
  
  for(i=1;i<=5;i++) for(j=1;j<=5;j++) 
  { sprintf(name,"Zn%d%d",i,j); assignValW(name,slhaVal("NMNMIX",Q,2,i,j));}
  for(i=1;i<=3;i++) for(j=1;j<=3;j++) 
  { sprintf(name,"Zh%d%d",i,j); assignValW(name,slhaVal("NMHMIX",Q,2,i,j));}

  for(i=1;i<=2;i++) for(j=1;j<=3;j++) Pa[i-1][j-1]=slhaVal("NMAMIX",Q,2,i,j);
  { double tb;
    assignValW("Pa12",Pa[0][2]);
    assignValW("Pa22",Pa[1][2]);
    if(Pa[0][1]==0)  assignValW("Pa11",0); else
    {
      tb=Pa[0][0]/Pa[0][1];
      assignValW("Pa11",Pa[0][1]*sqrt(1+tb*tb));
    }
    if(Pa[1][1]==0)  assignValW("Pa21",0); else
    {
      tb=Pa[1][0]/Pa[1][1];
      assignValW("Pa21",Pa[1][1]*sqrt(1+tb*tb));
    }
  }
  
  for(i=1;i<=2;i++) for(j=1;j<=2;j++)
  { sprintf(name,"Zu%d%d",i,j);assignValW(name,slhaVal("UMIX",Q,2,i,j));
    sprintf(name,"Zv%d%d",i,j);assignValW(name,slhaVal("VMIX",Q,2,i,j));
  }
   
  for(k=0;k<3;k++)
  { double M[3];
    for(i=1;i<=2;i++) 
    {M[i]=slhaVal(Qmix[k],Q,2,1,i);
     sprintf(name,"%s1%d",Zf[k],i); assignValW(name,M[i]);
    }  
    M[2]*=-1;
    for(i=1;i<=2;i++) 
    { sprintf(name,"%s2%d",Zf[k],i); assignValW(name,M[3-i]); }  
  }   
  
  if(mode>0)
  {  
    for(i=0;i<13;i++) assignValW(softName[i],slhaVal("MSOFT",Q,1,softId[i])); 
    assignValW("mu", slhaVal("HMIX",Q,1,1));    
    assignValW("Al", slhaVal("Ae",Q,2,3,3));
    assignValW("Ab", slhaVal("Ad",Q,2,3,3));
    assignValW("At", slhaVal("Au",Q,2,3,3));
    assignValW("Am", slhaValExists("Ae",2,2,2)>0 ? slhaVal("Ae",Q,2,2,2):slhaVal("Ae",Q,2,3,3));
    assignValW("Au", slhaValExists("Au",2,2,2)>0 ? slhaVal("Au",0.,2,2,2):slhaVal("Au",0.,2,3,3));
    assignValW("Ad", slhaValExists("Ad",2,2,2)>0 ? slhaVal("Ad",0.,2,2,2):slhaVal("Ad",0.,2,3,3));
  }
  
  if(mode==2)
  { assignValW("tb",slhaVal("MINPAR",Q,1,3) );
    assignValW("alfSMZ",slhaVal("SMINPUTS",Q,1,3) );
    assignValW("MbMb",  slhaVal("SMINPUTS",Q,1,5) );
    assignValW("Mtp",   slhaVal("SMINPUTS",Q,1,6) );
    assignValW("Ml",    slhaVal("SMINPUTS",Q,1,7) );
  }   

}

int readLesH(char *fname, int mode)
{
  int err;
  err=slhaRead(fname,2);
  if(err) return err;
  FillVal(mode);
  return 0;
}
