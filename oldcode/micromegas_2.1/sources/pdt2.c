#include<math.h>
#include<stdio.h>
#include"micromegas.h"
#include"micromegas_aux.h"

#include"../CalcHEP_src/c_source/num/pdt.c"

static  pdtStr *data[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

static  pdtStr *data_;
static  double q_;

static double x_integrand(double x)
{  if(x==0) return 0; else return  x*interFunc(x, q_, data_);  }


static int pos(int pNum)
{ switch(pNum) 
  { case  5: case -5: return 1;
    case  4: case -4: return 2;
    case  3: case -3: return 3;
    case -1:          return 4;
    case -2:          return 5;
    case 21:          return 6;
    case  2:          return 7;
    case  1:          return 8;      
    default:          return 0;
  }  
}

static pdtStr * checkdata(int pp)
{ 
  if(data[pp] == NULL) 
  { pdtStr * DT;
    static char*pdtFile=NULL;
    const char pdt_file[]="../../CalcHEP_src/pdTables/cteq6l.pdt";
  
    if(pdtFile==NULL)
    { pdtFile=malloc(2+strlen(WORK)+strlen(pdt_file));
      sprintf(pdtFile,"%s/%s",WORK,pdt_file);  
    }  
    DT=malloc(sizeof(pdtStr));
    if(getPdtData(pdtFile,  pp+1, DT )==0) data[pp]=DT; else
    {    
       printf("error in reading PDT file\n");
       free(DT);
    }
  }
  return data[pp];
}

double parton_x( int pNum, double  Q)
{
  int pp=pos(pNum)-1;
  double x1;
  q_=Q;

  if(pp<0) return 0;
  data_=checkdata(pp); 
  if(data_ == NULL || q_< data_->q_min ) return 0;
  
  x1=simpson(x_integrand,data_->x_min,1.,1.E-4);  
  if(pNum==21) return x1;
  if(abs(pNum)>2) return 2*x1;
  pp=pos(-pNum)-1;
  
  data_=checkdata(pp);
  if(data_ == NULL) return 0;  
  return x1+simpson(x_integrand,data_->x_min,1.,1.E-4);
}
