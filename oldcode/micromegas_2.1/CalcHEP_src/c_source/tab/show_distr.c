
#include <dirent.h>
#include "histogram.h"
#include "chep_crt.h"
#include "files.h" 
#include "rootDir.h"    
#include "subproc.h"
#include "viewdir.h"
#include "interface.h"
/*
#define const
#include"num_out.h"
#undef const

int  nvar_ext=0;
char * varName_ext[1];
double  va_ext[1];
int nfunc_ext=0; 

int nin_ext, nout_ext;
*/
static char* pinf_ext(int nsub,int num , double * mass, long *N ){ return NULL;}


static void f6_key_prog (int x){  viewDir("."); }

static void f10_key_prog (int x)
{ if( mess_y_n(15,15," Quit session? ")) { finish(); exit(0);} }    
    

 
int main(int np, char ** par)
{ 
  FILE*f;

   f3_key[3]=f6_key_prog;   f3_mess[3]="Results";
   f3_key[7]=f10_key_prog;  f3_mess[7]="Quit";

   blind=0;
   nvar_int=0;
   nfunc_int=0; 
   pinf_int=&pinf_ext;
   
  if(np!=2) 
  { printf(" This  routine is intended to display distributions produced\n" 
           " in  calcHEP numerical sessions (files dist_#).\n"
           " The name of file should submited to this routine as paramete\n");
    return 1;
  }
  { char *p=getenv("CALCHEP");
    if(!p) p=rootDir;  
    sprintf(pathtocomphep,"%s%c",p,f_slash);
    sprintf(pathtohelp,"%s%chelp%c",p,f_slash,f_slash);
  }                          
              
  f=fopen(par[1],"r");
   
  if(!f)
  {  printf("Can not open the '%s' file\n",par[1]);
     exit(1);
  }   

  if(rdr_hist2(f,proces_1.proces))
  {  printf("Wrong  format for %s \n",par[1]);
         exit(1);
  }else     
  {  char*c1,*c2;
     c1=strstr(proces_1.proces,",");
     c2=strstr(proces_1.proces,"->");
     if(c1>c2) nin_int=1; else nin_int=2;
     nout_int=2; 
  }
  fclose(f);

  { char txt[80];
    sprintf(txt," %s Viewer for  distributions ",version);   
    start1(txt,pathtocomphep,"calchep.ini;../calchep.ini",NULL);
  }    
    
  goto_xy(20,2);  
  scrcolor(Blue,LightGray);     print(" File:"); 
  scrcolor(Red,LightGray);      print(" %s     ",par[1]);     
  scrcolor(Blue,BGmain);        print(" Process: ");
  scrcolor(Red,LightGray);      print(" %s",proces_1.proces);

  showHist(54,5);
  
  finish();

  return 0;
}
