#include"pmodel.h"
#include"pmodel_aux.h"
#include"pmodel_f.h"
#include"../../sources/micromegas.h"

#include <ctype.h>
#include <stdio.h>

static int delFilesKey=1;
int getdelfilesstat_(void) {return delFilesKey;}
void delFiles(int x)  { delFilesKey=x; }
void delfiles_(int *x){ delFilesKey=*x;}

char * errTXTslha=NULL;

int sugraLesH(char *fname,  double m0, double mhf, double a0,
double tb, double sgn, double  Lambda, double aLambda, double aKappa)
{  
   FILE*  f=fopen(fname,"w");
   if(f==NULL) return -1;
   
   fprintf(f,"Block MODSEL                 # Select model\n"   
           " 3    1                      # SUGRA NMSSM\n"
           " 9    0                      # FLAG FOR MICROMEGAS (0=NO)\n" 
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
           " 3    1           # NMSSM PARTICLE CONTENT\n"
           " 9    0           # FLAG FOR MICROMEGAS (0=NO, 1=YES\n"
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


static int nfscanf(FILE*f,int *n1, int*n2, double* val )
{  
  long pos=ftell(f);
  for(;;)
  { char c;
    int r;

    
    fscanf(f,"%c",&c);
    
    if(c=='#') 
    { 
      do{ r=fscanf(f,"%c",&c);} while( r==1 && c!='\n');   
      if( r!=1 ) return r;
      continue;
    }
    else if(c==' ') 
    {
       if(val)
       {
         if(n1&&n2) r=fscanf(f,"%d %d %lf%*[^\n]",n1,n2,val);
         else if(n1)r=fscanf(f,"%d %lf%*[^\n]",n1,val);
         else r=fscanf(f,"%lf%*[^\n]",val);
       } else    r=fscanf(f,"%d%*[^\n]",n1);  
       fscanf(f,"%c",&c); 
       return r;
    }else
    { fseek(f,pos,SEEK_SET); 
      return 0;    
    }
  }  
}

int readLesH(char *fname, int SMplus)
{
  FILE *f;
  char buff[100], mess[200],name[20];
  int n1,n2,i,err=-4;
  double val;
  char Zf[3][3]={"Zb","Zt","Zl"};
  int MG1ok=0, MG2ok=0, AmOK=0,AuOK=0,AdOK=0;
  double Pa[2][3]={{0,0,0},{0,0,0}};

  f=fopen(fname,"r");
  if(f==NULL) return -2;
  if(errTXTslha) {free(errTXTslha); errTXTslha=NULL;}
  for(;;) 
  { if(fscanf(f,"%s", buff)== EOF) break; 
    if(buff[0]=='#') { fscanf(f,"%*[^\n]\n"); continue;}
    for(i=0;buff[i];i++) buff[i]=toupper(buff[i]);
    if(strcmp(buff,"BLOCK")==0)
    { char rest[200];
      char *c;
      fscanf(f,"%s",buff);
      if(fscanf(f,"%[^\n]",rest))
      { c=strchr(rest,'#');
        if(c) c[0]=0;
        c=strchr(rest,'=');
        if(c && 1==sscanf(c+1,"%lf",&val))/*assignValW("QSUSY",val)*/;
      } 
      fscanf(f,"%*c");       
      
      for(i=0;buff[i];i++) buff[i]=toupper(buff[i]);    
      if(strcmp(buff,"MASS")==0)
      {  
         for(;nfscanf(f,&n1,NULL,&val)==2;)
         {  
         switch(n1)
         {
           case         24   : break; assignValW("MW",   val);   /* MW*/
           case         25   : assignValW("Mh1",   val); break;  /* h0*/
           case         35   : assignValW("Mh2",  val); break;  /* H0*/
           case         45   : assignValW("Mh3",  val); break;  /* H0*/
           case         36   : assignValW("Mha",  val); break;  /* A0*/
           case         46   : assignValW("Mhb",  val); break;  /* A0*/
           case         37   : assignValW("MHc",  val); break;  /* H+*/
           case    1000001   : assignValW("MSdL",val);  break;  /* ~d_L*/
           case    1000002   : assignValW("MSuL",val);  break;  /* ~u_L*/
           case    1000003   : assignValW("MSsL",val);  break;  /* ~s_L*/
           case    1000004   : assignValW("MScL",val);  break;  /* ~c_L*/
           case    1000005   : assignValW("MSb1",val);  break;  /* ~b_1*/
           case    1000006   : assignValW("MSt1",val);  break;  /* ~t_1*/
           case    1000011   : assignValW("MSeL",val);  break;  /* ~e_L*/
           case    1000012   : assignValW("MSne",val);  break;  /* ~nue_L*/
           case    1000013   : assignValW("MSmL",val);  break;  /* ~mu_L*/
           case    1000014   : assignValW("MSnm",val);  break;  /* ~numu_L*/
           case    1000015   : assignValW("MSl1",val);  break;  /* ~stau_1*/
           case    1000016   : assignValW("MSnl",val);  break;  /* ~nu_tau_L*/
           case    1000021   : assignValW("MSG", val);  break;  /* ~g*/
           case    1000022   : assignValW("MNE1",val);  break;  /* ~neutralino(1)*/
           case    1000023   : assignValW("MNE2",val);  break;  /* ~neutralino(2)*/
           case    1000024   : assignValW("MC1", val);  break;  /* ~chargino(1)*/
           case    1000025   : assignValW("MNE3",val);  break;  /* ~neutralino(3)*/
           case    1000035   : assignValW("MNE4",val);  break;  /* ~neutralino(4)*/
           case    1000045   : assignValW("MNE5",val);  break;  /* ~neutralino(5)*/
           case    1000037   : assignValW("MC2", val);  break;  /* ~chargino(2)*/
           case    2000001   : assignValW("MSdR",val);  break;  /* ~d_R*/
           case    2000002   : assignValW("MSuR",val);  break;  /* ~u_R*/
           case    2000003   : assignValW("MSsR",val);  break;  /* ~s_R*/
           case    2000004   : assignValW("MScR",val);  break;  /* ~c_R*/
           case    2000005   : assignValW("MSb2",val);  break;  /* ~b_2*/
           case    2000006   : assignValW("MSt2",val);  break;  /* ~t_2*/
           case    2000011   : assignValW("MSeR",val);  break;  /* ~e_R*/
           case    2000013   : assignValW("MSmR",val);  break;  /* ~mu_R*/
           case    2000015   : assignValW("MSl2",val);  break;  /* ~stau_2*/
         }
         }
      }   
      else if(strcmp(buff,"ALPHA")==0)
          { nfscanf(f,NULL,NULL,&val); assignValW("alpha",val); }
      else if(strcmp(buff,"HMIX")==0) while(2==nfscanf(f,&n1,NULL,&val))    
          switch(n1)
          { case 1: assignValW("mu",val);  break; 
//            case 2: assignValW("tb_Q",val);break;
            case 3: assignValW("vev",val); break;
//            case 4: assignValW("mA_2",val); break;
          }
      else if(strcmp(buff,"NMHMIX")==0)while(3==nfscanf(f,&n1,&n2,&val))    
          { sprintf(name,"Zh%d%d",n1,n2); assignValW(name,val);}
      else if(strcmp(buff,"NMAMIX")==0)while(3==nfscanf(f,&n1,&n2,&val))
                { Pa[n1-1][n2-1]=val;}
      else if(strcmp(buff,"STOPMIX")==0)  while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zt%d%d",n1,n2); assignValW(name,val);}
      else if(strcmp(buff,"SBOTMIX")==0)  while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zb%d%d",n1,n2); assignValW(name,val);} 
      else if(strcmp(buff,"STAUMIX")==0)  while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zl%d%d",n1,n2); assignValW(name,val);} 
      else if(strcmp(buff,"NMNMIX")==0)     while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zn%d%d",n1,n2); assignValW(name,val);} 
      else if(strcmp(buff,"UMIX")==0)     while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zu%d%d",n1,n2); assignValW(name,val);}  
      else if(strcmp(buff,"VMIX")==0)     while(3==nfscanf(f,&n1,&n2,&val))
          { sprintf(name,"Zv%d%d",n1,n2); assignValW(name,val);}  
      else if(strcmp(buff,"AU")==0)       while(3==nfscanf(f,&n1,&n2,&val))
          {       if(n1==3 && n2==3) assignValW("At",val);
            else if(n1==2 && n2==2) {assignValW("Au",val); AuOK=1;}
          } 
      else if(strcmp(buff,"AD")==0)       while(3==nfscanf(f,&n1,&n2,&val))
          {      if(n1==3 && n2==3) assignValW("Ab",val);
            else if(n1==2 && n2==2) {assignValW("Ad",val); AdOK=1;}
          } 
      else if(strcmp(buff,"AE")==0)       while(3==nfscanf(f,&n1,&n2,&val)) 
          {      if(n1==3 && n2==3) assignValW("Al",val);
            else if(n1==2 && n2==2) {assignValW("Am",val); AmOK=1;}
          }
      else if(strcmp(buff,"SMINPUTS")==0 && SMplus) while(2==nfscanf(f,&n1,NULL,&val))
           switch(n1)
           { case 1: assignValW("alfEMZ", 1/val); break;
             case 3: assignValW("alfSMZ",val); break;
             case 4: assignValW("MZ",val); break;
             case 5: assignValW("MbMb",val); break;
             case 6: assignValW("Mtp",val); break;  
             case 7: assignValW("Ml",val); break; 
           }
      else if(strcmp(buff,"MINPAR")==0 && SMplus) while(2==nfscanf(f,&n1,NULL,&val))
           { if(n1==3) assignValW("tb", val); }   
      else if(strcmp(buff,"SPINFO")==0) 
           {if(err==-4) err=0;
            while(2==fscanf(f," %d %[^\n]\n",&n1,mess))
            {  if(n1==3 && err==0) err=1; else if(n1==4) err=-1;
               if(n1==3||n1==4)
               {
                 if(errTXTslha==NULL)
                 { errTXTslha=malloc(2+strlen(mess));
                   strcpy(errTXTslha,mess);
                 } else
                 { errTXTslha=realloc(errTXTslha,2+strlen(mess)+strlen(errTXTslha));
                   strcat(errTXTslha,mess);
                 }
                 strcat(errTXTslha,"\n");
               } 
            }
           }          
      else if(strcmp(buff,"MSOFT")==0)  
            while(2==nfscanf(f,&n1,NULL,&val)) 
            switch(n1) 
            {  
             case  1: assignValW("MG1",val); 
                                  MG1ok=1;    break; /*  M_1(Q)  */
             case  2: assignValW("MG2",val); 
                                  MG2ok=1;    break; /*  M_2(Q)  */
             case  3: assignValW("MG3",val);  break; /*  M_3(Q)  */
//             case 21: assignValW("mH1_2",val);break; /*  mH1^2(Q)  */
//             case 22: assignValW("mH2_2",val);break; /*  mH2^2(Q)  */
//             case 31: assignValW("Ml1",val);  break; /*  meL(Q)  */
             case 32: assignValW("Ml2",val);  break; /*  mmuL(Q) */
             case 33: assignValW("Ml3",val);  break; /*  mtauL(Q)*/
//             case 34: assignValW("Mr1",val);  break; /*  meR(Q)  */
             case 35: assignValW("Mr2",val);  break; /*  mmuR(Q) */
             case 36: assignValW("Mr3",val);  break; /*  mtauR(Q)*/
//             case 41: assignValW("Mq1",val);  break; /*  mqL1(Q) */
             case 42: assignValW("Mq2",val);  break; /*  mqL2(Q) */
             case 43: assignValW("Mq3",val);  break; /*  mqL3(Q) */
//             case 44: assignValW("Mu1",val);  break; /*  muR(Q)  */
             case 45: assignValW("Mu2",val);  break; /*  mcR(Q)  */
             case 46: assignValW("Mu3",val);  break; /*  mtR(Q)  */
//             case 47: assignValW("Md1",val);  break; /*  mdR(Q)  */
             case 48: assignValW("Md2",val);  break; /*  msR(Q)  */
             case 49: assignValW("Md3",val);  break; /*  mbR(Q)  */
            }
//      else if(strcmp(buff,"GAUGE")==0)  while(2==nfscanf(f,&n1,NULL,&val))
//        switch(n1)
//        { case 1: assignValW("gY", val); break; 
//          case 2: assignValW("g2", val); break;
//          case 3: assignValW("g3", val); break;
//        }
//      else if(strcmp(buff,"YU")==0) while(3==nfscanf(f,&n1,&n2,&val)) 
//        {  if(n1==3 && n2==3) assignValW("Yt",val); }
//      else if(strcmp(buff,"YD")==0)  while(3==nfscanf(f,&n1,&n2,&val)) 
//        { if(n1==3 && n2==3) assignValW("Yb",val);}
//      else if(strcmp(buff,"YE")==0)  while(3==nfscanf(f,&n1,&n2,&val)) 
//        { if(n1==3 && n2==3) assignValW("Yl",val);}
        else if(strcmp(buff,"MO_HIGGS")==0)while(2==nfscanf(f,&n1,NULL,&val))   
          switch(n1)
          { case 1: assignValW("Lambda",val); break;
            case 2: assignValW("Kappa",val); break;
            case 3: assignValW("aLmbd0",val); break;
            case 4: assignValW("dMb",val); break;
            case 5: assignValW("vev",val); break;
            case  25 : assignValW("Mh1R", val); break;  /* h0*/
            case  35 : assignValW("Mh2R",  val); break;  /* H0*/
            case  45 : assignValW("Mh3R",  val); break;  /* H0*/
            case  36 : assignValW("MhaR",  val); break;  /* A0*/
            case  46 : assignValW("MhbR",  val); break;  /* A0*/
            case  37 : assignValW("MHcR",  val); break;  /* H+*/                
          }       
        else if(strcmp(buff,"LOWEN")==0)  while(2==nfscanf(f,&n1,NULL,&val))
         switch(n1)
           { case 1:  assignValW("BSG0",val); break;
             case 11: assignValW("BSGP",val); break;
             case 12: assignValW("BSGM",val); break;

             case 2:  assignValW("DMD0",val); break;
             case 21: assignValW("DMDP",val); break;
             case 22: assignValW("DMDM",val); break;

             case 3:  assignValW("DMS0",val); break;
             case 31: assignValW("DMSP",val); break;
             case 32: assignValW("DMSM",val); break;

             case 4:  assignValW("BsMM0",val); break;
             case 41: assignValW("BsMMP",val); break;
             case 42: assignValW("BsMMM",val); break;

             case 5:  assignValW("Bln0",val); break;
             case 51: assignValW("BlnP",val); break;
             case 52: assignValW("BlnM",val); break;
             
            }
                                                     
         
    }          
  }
  for(i=0;i<3;i++) 
  { char name[10];
    double M[2];
    for(n2=0;n2<2;n2++){sprintf(name,"%s1%d",Zf[i],n2+1); M[n2]=findValW(name);}
    M[1]=-M[1];
    for(n2=0;n2<2;n2++){sprintf(name,"%s2%d",Zf[i],n2+1); assignValW(name,M[1-n2]);}
  }
  fclose(f);
//  if(!(MG1ok && MG2ok)) 
//  { double mg1,mg2;
//    CheckNCsector(NULL, &mg1, &mg2,NULL,NULL,NULL,NULL);
//    assignValW("MG1",mg1);
//    assignValW("MG2",mg2);
//  }
  if(!AmOK) assignValW("Am",findValW("Al"));
//  if(!AuOK) assignValW("Au",findValW("At"));
//  if(!AdOK) assignValW("Ad",findValW("Ab"));
  
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
  
  return err;
}


