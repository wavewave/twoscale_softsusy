/*
 Copyright (C) 1997, Alexander Pukhov 
*/
#include "interface.h"
#include<math.h>
#include"cut.h"
#include"parser.h"
#include"rd_num.h"
#include"crt_util.h"
#include"const.h"
#include"phys_val.h"
#include"read_func.h"
#include"sortarr.h"

invcut_ invcut_1[60];

table cutTab={"*** Table ***"," Cuts  ",
                   "  Parameter  |> Min bound <|> Max bound <|",NULL}; 


static void  cutInit(void){invcut_1[0].key=0;}


static int addcut(char key ,char *lv, int minonw, int maxonw,
        double  cvminw, double cvmaxw)
{
    int  ncut;


    for (ncut=0; invcut_1[ncut].key; ncut++)
    if ( key==invcut_1[ncut].key && !strcmp(lv,invcut_1[ncut].lvinvc))
    {  if (minonw && ( !invcut_1[ncut].minon || cvminw>invcut_1[ncut].cvmin) )  
       { invcut_1[ncut].minon=1; invcut_1[ncut].cvmin=cvminw;}
       if (maxonw && ( !invcut_1[ncut].maxon || cvmaxw<invcut_1[ncut].cvmax) )  
       {invcut_1[ncut].maxon=1;  invcut_1[ncut].cvmax=cvmaxw;}     
       return 0;
    } 
     
    if ( ncut >= 59) return 2;
    
    invcut_1[ncut].key   = key;
    strcpy(invcut_1[ncut].lvinvc,lv); 
    invcut_1[ncut].minon = minonw;
    invcut_1[ncut].maxon = maxonw;
    invcut_1[ncut].cvmin = cvminw;
    invcut_1[ncut].cvmax = cvmaxw;
    invcut_1[ncut+1].key=0;
   return 0;
} /* addcut_ */


int wrtcut_(FILE *nchan){ fprintf(nchan,"\n"); writetable0(&cutTab,nchan); return 0;}
int rdrcut_(FILE *nchan){ fscanf(nchan,"\n");  return readtable0(&cutTab,nchan); }

int fillCutArray(void)
{
  linelist ln=cutTab.strings;
  int lineNum=0;
  char cutStr[STRSIZ], minStr[STRSIZ], maxStr[STRSIZ];
  char keyChar;
  int minOn,maxOn;
  char fieldName[50];
  
  cutInit();
  while (ln != NULL)
  {  
    double min_=0,max_=0;
    char lv[PLISTLEN];
    int i,k;
    cutStr[0]=0;
    minStr[0]=0;
    maxStr[0]=0;    
    lineNum++;    
    sscanf(ln->line,"%[^|]%*c%[^|]%*c%[^|]",cutStr,minStr,maxStr);

/*================ MIN bound ============*/
    strcpy(fieldName,"Wrong field 'Min. bound'");
    i=0;while(minStr[i]==' ') i++;
    minOn= (minStr[i] != 0);
    if (minOn) { if(calcExpression(minStr,rd_num,&min_)) goto errorExit;}

/*============ Parameter ===========*/
    strcpy(fieldName,"Wrong field 'Parameter'");
    if(! checkPhysVal(cutStr, &keyChar,lv)) goto errorExit;

/*================== MAX bound ==========*/    
    strcpy(fieldName,"Wrong field 'Max bound'");
    i=0;while(maxStr[i]==' ') i++;
    maxOn= (maxStr[i] != 0);
    if(maxOn) {if(calcExpression(maxStr,rd_num,&max_)) goto errorExit;}

/* =========== fill array ==========*/

    if( keyChar != 'U') SORTARR(lv,strlen(lv));
    if(keyChar=='A') 
    {  int tmpOn=minOn;
       double min=max_, max=min_;
       keyChar='C';
       minOn=maxOn;
       maxOn=tmpOn;
      if(minOn) min_=cos(min*(M_PI)/180);  
      if(maxOn) max_=cos(max*(M_PI)/180);       
    }

    if(keyChar=='M') 
    {  keyChar='S';       
      if(minOn) min_=min_*fabs(min_);  
      if(maxOn) max_=max_*fabs(max_);  
    }
    if((keyChar=='S'))  coninv_(lv);

    if(minOn||maxOn)
    {  k=addcut(keyChar,lv,minOn,maxOn,min_,max_);
       if (k==2) { strcpy(fieldName,"Too many cuts "); goto errorExit;}
    }   
    ln=ln->next;
  } 
  return 0;
  errorExit:
    sprintf(errorText," Error in Cut table line %d .\n%s.",lineNum,fieldName);
    messanykey(2,10,errorText);
    return 1;  
}


int rancor_(double *vmin, double *vmax, double shift, double fmult,int nn)
{
    static double vnew;

    if (nn == 0) {
	return 0;
    }
    if (invcut_1[nn-1].minon) 
    {
	vnew = (invcut_1[nn-1].cvmin - shift) * fmult;
	if (fmult > 0.) *vmin = MAX(*vmin,vnew);
	     else        *vmax = MIN(*vmax,vnew);
    }
    if (invcut_1[nn-1].maxon) 
    {
	vnew = (invcut_1[nn-1].cvmax - shift) * fmult;
	if (fmult > 0.)  *vmax = MIN(*vmax,vnew);
	 else             *vmin = MAX(*vmin,vnew);
	
    }
    return 0;
} /* rancor_ */


double  calcCutFactor(void)
{  
  int i;
  double val;

  for(i=0; invcut_1[i].key; i++)
  { 
     val=calcPhysVal(invcut_1[i].key,invcut_1[i].lvinvc);
     if ( invcut_1[i].minon && (val < invcut_1[i].cvmin)) return 0;
     if ( invcut_1[i].maxon && (val > invcut_1[i].cvmax)) return 0;
  }

  return 1;
}  

