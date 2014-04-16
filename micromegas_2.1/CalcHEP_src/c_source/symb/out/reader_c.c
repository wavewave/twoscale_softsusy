/*
 Copyright (C) 1997, Alexander Pukhov 
*/
#include<string.h>
#include "syst.h"
#include "syst2.h"
#include "physics.h"
#include "procvar.h"
#include "reader_c.h"

FILE * ext_h;

int checkNaN;

static void * bact5(char ch,void * mm1,void * mm2)
{
   char   *m1, *m2, *ans;
   char   r_n,p_m;

   m1 = (char *) mm1;
   m2 = (char *) mm2;

   if (ch=='+' || ch=='-') p_m='P'; else p_m='M';
   
   r_n='R';

   if (m1[0] == 'M' || ch =='+'|| ch =='-')    lShift(m1,3); else { lShift(m1,2);m1[0]='(';strcat(m1,")"); }
   if ((m2[0] == 'M' || ch =='+')&& ch != '/') lShift(m2,3); else { lShift(m2,2);m2[0]='(';strcat(m2,")"); }

   ans= m_alloc(strlen(m1)+strlen(m2)+30);

   switch (ch)
   {
      case '+': 
              if (m1[0] == '-')        sprintf(ans,"%c%c|%s%s",p_m,r_n,m2,m1);
	      else  if (m2[0] == '-')  sprintf(ans,"%c%c|%s%s",p_m,r_n,m1,m2);
              else                     sprintf(ans,"%c%c|%s+%s",p_m,r_n,m1,m2);
      break;

      case '-': 
	      if (m2[0] == '-')  sprintf(ans,"%c%c|%s+%s",p_m,r_n,m1,m2+1);
              else               sprintf(ans,"%c%c|%s-%s",p_m,r_n,m1,m2);
      break;
      

      case '*':
              if (m2[0] != '-')        sprintf(ans,"%c%c|%s*%s",p_m,r_n,m1,m2);
              else if (m1[0] != '-')   sprintf(ans,"%c%c|%s*%s",p_m,r_n,m2,m1);
              else                     sprintf(ans,"%c%c|%s*%s",p_m,r_n,m1+1,m2+1);
      break;

      case '/':
		if (m2[0] != '-')   sprintf(ans,"%c%c|%s/%s",p_m,r_n,m1,m2);else
                {  if (m1[0] == '-') sprintf(ans,"%c%c|%s/%s",p_m,r_n,m1+1,m2+1);
                   else    sprintf(ans,"%c%c|-%s/%s",p_m,r_n,m1,m2+1);
                }
                checkNaN=1;
      break;

      case '^':
                 sprintf(ans,"%c%c|pow(%s,%s)",p_m,r_n,m1,m2);
                 checkNaN=1;
      break;
      default:  checkNaN=1;                 
   }   /* Case */
	return (void *) ans;
}


static void * uact5(char* ch,void * mm)
{ char  *m, *ans;
  m = (char *) mm;
  ans=m_alloc(strlen(m)+30);

  if (strcmp(ch,"-") == 0)
  {
     if(m[0] == 'M')
     {  if (m[3] == '-')  sprintf(ans,"M%c|%s",m[1],m+4);
	else              sprintf(ans,"M%c|-%s",m[1],m+3);
     } else sprintf(ans,"M%c|-(%s)",m[1],m+3);
  } 
  return (void *) ans;
}

void * act_c(char * name,int n, void ** args)
{ int l,i;
  char * ans;

  if(!isalpha(name[0]))
  { 
    if(n==1) return uact5(name,args[0]);
    if(n==2) return bact5(name[0],args[0],args[1]);
  } else if(strcmp(name,"one")==0)
  { ans=m_alloc(6); sprintf(ans,"MN|1"); return ans;
  } else 
  { checkNaN=1;
    if(  strcmp(name,"sqrt")&& strcmp(name,"sin")&& strcmp(name,"cos")
       &&strcmp(name,"tan")&& strcmp(name,"asin")&& strcmp(name,"acos") 
       &&strcmp(name,"atan")&& strcmp(name,"exp")&& strcmp(name,"log")    
       &&strcmp(name,"fabs")&& strcmp(name,"atan2")&& strcmp(name,"if")
      ) { fprintf(ext_h, " extern double %s(",name);
          if(strcmp(name,"rDiagonal")&&strcmp(name,"rDiagonal2"))
          { 
            for(i=1;i<n;i++)  fprintf(ext_h,"double,");
            fprintf(ext_h,"double);\n");
          }else
          { fprintf(ext_h,"double id, double dim, ...);\n");
          }
        }
  } 
  l=n+10+strlen(name);
  for(i=0;i<n;i++) l+=strlen((char*)args[i]); 
  ans=m_alloc(l);
  if(!strcmp(name,"if") && n==3)
    sprintf(ans,"MR|(%s>0 ? %s : %s)", (char*)args[0]+3, (char*)args[1]+3,
               (char*)args[2]+3);
  else     
  { sprintf(ans,"MR|%s(",name);
    for(i=0;i<n;i++) 
    { 
      strcat(ans,(char*)args[i]+3);
      strcat(ans,",");
    }
  ans[strlen(ans)-1]=')';
  }
  return ans;
}

void *  rd_c(char* s)
{  char      *p;
   int        l;
   p = m_alloc(40);
   if (isdigit(s[0])) 
   {   sprintf(p,"MN|%s",s); 
       if( !strchr(s,'.') && !strchr(s,'E') && !strchr(s,'e')) strcat(p,".");
   }                 
   else
   {
      for(l=1;l<=nmodelvar;l++)
      {
         if(!strcmp(s,modelvars[l].varname))
         {
            sprintf(p,"MR|%s",vararr[l].alias);
            return (void *) p;
         }
      }
   }
   return (void *) p;
}
