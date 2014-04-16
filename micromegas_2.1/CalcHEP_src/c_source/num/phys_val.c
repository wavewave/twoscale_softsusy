/*
 Copyright (C) 1997, Alexander Pukhov 
*/
#include"4_vector.h"
#include<math.h>
#include"phys_val.h"
#include "interface.h"
#include"subproc.h"
#include"ctype.h"
#include"kinaux.h"
#include"usrfun.h"
#include "const.h"

double calcPhysVal(char key,char * lv)
{
   double p1,p2,p3, q1,q2,q3, mp,mq ,cs,dl; 
   int j;


   int np1=4*(lv[0]-1), np2=4*(lv[1]-1);
   double s=0;
   int i=0;
   double pp[4]={0,0,0,0};
 
   switch(key)
   {  case 'A':
      case 'C': 
            p1 = pvect[np1+1];
            p2 = pvect[np1+2];
            p3 = pvect[np1+3];
            
            q1 = pvect[np2+1];
            q2 = pvect[np2+2];
            q3 = pvect[np2+3];

            cs = (p1*q1+p2*q2+p3*q3)/
                sqrt( (p1*p1+p2*p2+p3*p3) * (q1*q1+q2*q2+q3*q3) );
            if (key == 'A') return  acos(cs)*180/M_PI; 
            return cs;
        case 'J':
            p1 = pvect[np1+1];
            p2 = pvect[np1+2];
            p3 = pvect[np1+3];
            mp = sqrt(p1*p1 + p2*p2 + p3*p3);

            q1 = pvect[np2+1];
            q2 = pvect[np2+2];
            q3 = pvect[np2+3];
            mq = sqrt(q1*q1 + q2*q2 + q3*q3);
            
            cs = (p1*q1 + p2*q2)/sqrt( (p1*p1 + p2*p2)*(q1*q1 + q2*q2) );
            cs = acos(cs);
                   
            dl = (mp + p3) * (mq - q3)  / (mp - p3) / (mq +q3);
            dl = 0.5*log(dl);
            
            return sqrt(dl*dl + cs*cs);

        case 'P':   
	{  
	   double mtot, mtot2, ms,md, pcm,p2;
	   
	   pinf_int(proces_1.nsub, lv[0], &mp,NULL); 
           for(i=1;lv[i];i++)
           for(j=0;j<4;j++) pp[j]+=pvect[4*(lv[i]-1)+j];

	   p2 = pp[1]*pp[1] + pp[2]*pp[2] + pp[3]*pp[3];
	   mq=sqrt(fabs(pp[0]*pp[0]-p2));

	   for(j=0;j<4;j++) pp[j]+=pvect[np1+j];
	   p2 = pp[1]*pp[1] + pp[2]*pp[2] + pp[3]*pp[3];
	   
           mtot2 = fabs(pp[0]*pp[0] -p2);
           mtot=sqrt(mtot2);
           
	   ms = mp + mq;
	   md = mp - mq;

	   pcm = sqrt( (mtot2-ms*ms) * (mtot2-md*md) )/(2*mtot);
	   s =pp[1]*pvect[np1+1]+pp[2]*pvect[np1+2]+pp[3]*pvect[np1+3];
              
           return  (s*pp[0] - pvect[np1]*p2 ) /(sqrt(p2) * mtot * pcm);

        }
        case 'E':
            while(lv[i]!=0)   s += pvect[  (lv[i++]<<2)  -4];
            return s;

        case 'T':
            {  i=0; 
               do for(j=1;j<3;j++) pp[j] += pvect[4*(lv[i]-1)+j]; while(lv[++i]);
               return sqrt( pp[1]*pp[1]+pp[2]*pp[2]);        
            }
        case 'S':
        case 'M': 
            {   
               do 
               {
                  if(lv[i]>nin_int) for(j=0;j<4;j++) pp[j] += pvect[4*(lv[i]-1)+j];
                  else for(j=0;j<4;j++)           pp[j] -= pvect[4*(lv[i]-1)+j];
               } while(lv[++i]); 
               s=pp[0]*pp[0]; for(j=1;j<4;j++) s -=pp[j]*pp[j];
               if(key=='M') return sqrt(s);
               return s ;
            }
         case 'Y': 
               do for(j=0;j<4;j += 3) pp[j] += pvect[4*(lv[i]-1)+j]; while(lv[++i]); 
               return  log(( pp[0]+pp[3])/(pp[0]-pp[3]))/2; 
         case 'N':
               do for(j=0;j<4;j++) pp[j] += pvect[4*(lv[i]-1)+j]; while(lv[++i]);
               mp = sqrt(pp[1]*pp[1]+pp[2]*pp[2]+pp[3]*pp[3]);
               return  log(( mp+pp[3])/(mp-pp[3]))/2;
                                                                  
        case 'U': return usrfun(lv);
        case 'Z': 
        { int s; double res,mass, res_i;
          if(strcmp(lv,"EtMin")==0) s=0; else s=1; 
          for(i=nin_int+1;i<=nin_int+nout_int;i++) 
          {
             pinf_int(proces_1.nsub,i, &mass,NULL);    
             np1=4*(i-1);
             res_i=mass*mass+pvect[np1+1]*pvect[np1+1]+pvect[np1+2]*pvect[np1+2];
             if(nin_int==1) res_i+=pvect[np1+3]*pvect[np1+3];
             if(i==nin_int+1 || (s && res<res_i)||(!s &&res>res_i) ) res=res_i;
          }
          return sqrt(res);    
        }
    }
    return 0;
}

int  checkPhysVal(char * name, char * key, char *plist)
{ int i=0,j=0;
  int n,k;

  
  while(name[i]==' '&&name[i]!=0) i++;
  *key=name[i++];
  
  if(*key==0) return 0;
  
   *key= toupper(*key);
  if(strchr("ACEJMPSTUYNZ",*key)==NULL) return 0; 
   
  if(*key=='Z' && strcmp(key+1,"EtMin") && strcmp(key+1,"EtMax")) return 0;  
   
  if(*key == 'U' || *key == 'Z')
  {  for( ;name[i] && name[i] != ' '  && i<6; i++) plist[j++]=name[i];
     plist[j]=0;
     for( ;name[i];i++) if(name[i] != ' ') return 0;
     return 1;
  }
    

  for( ; name[i]&&name[i]!=' '; i++)
  {  
    n=name[i]-'0';
    if(n<=0 || n>nin_int+nout_int) return 0;
    for(k=0; k<j;k++) if(plist[k] == n ) return 0;     
    plist[j++]=n;         
  }
  plist[j]=0;                                            
  for( ;name[i];i++) if(name[i] != ' ') return 0; 


  if(strchr("CAJ",*key)!=NULL && strlen(plist)!=2 )  return 0;
  if(strchr("P",*key)!=NULL && strlen(plist)<2 )  return 0;
  
  if(strchr("MS",*key)!=NULL && strlen(plist)<1)  return 0;
  
  if(strchr("JPT",*key)!=NULL)
           for(i=0;i<strlen(plist);i++) {if(plist[i]<=nin_int) return 0;} 
   
  if(strchr("MNY",*key) && !spole_(plist)) return 0;

  if(nin_int==1)
  { if( strchr("TYN",*key)) return 0;  
    if( strchr("ACP",*key) && (plist[0]==1 || plist[1]==1)) return 0;
  }    

  return 1;
}

void xName(char key, char * plist, char * xname,char * units)
{  int i;
   
   switch(key)
   {
   case 'A': sprintf(units,"Deg");
             sprintf(xname,"Angle(p%d,p%d)",labs(plist[0]),labs(plist[1]));
             break;
   case 'C': sprintf(units,"");
             sprintf(xname,"Cosine(p%d,p%d)",labs(plist[0]),labs(plist[1]));
             break;
   case 'E': sprintf(units,"GeV");
             sprintf(xname,"E%d",labs(plist[0]));
             i=1; while(plist[i]) sprintf(xname+strlen(xname),"+E%d",labs(plist[i++]));      
             break;
   case 'J': sprintf(units,"");
             sprintf(xname,"J(p%d,p%d)",labs(plist[0]),labs(plist[1]));
             break;
   case 'M': sprintf(units,"GeV");
             sprintf(xname,"Mass{p%d",labs(plist[0]));
             i=1;while(plist[i])sprintf(xname+strlen(xname),"+p%d",labs(plist[i++]));
             strcat(xname,"}");  
             break;
   case 'P': sprintf(units,"");
             sprintf(xname,"S.M.Cosine(p%d,p%d)",labs(plist[0]),labs(plist[1]));
             break;
   case 'S': sprintf(units,"GeV^2");
             sprintf(xname,"(p%d",plist[0]);
             i=1;while(plist[i])sprintf(xname+strlen(xname),"+p%d",labs(plist[i++]));
             strcat(xname,")^2");             
             break;
   case 'T': sprintf(units,"GeV");
             sprintf(xname,"Transverse momentum Pt%d",labs(plist[0]));
             i=1;while(plist[i])sprintf(xname+strlen(xname),"+Pt%d",labs(plist[i++]));          
             break;
   case 'Y': sprintf(units,"");
             sprintf(xname,"Rapidity_");
             for(i=0;plist[i];i++) sprintf(xname+strlen(xname),"%d",labs(plist[i]));
             break;
   case 'N': sprintf(units,"");
             sprintf(xname,"pseudo-rapidity_");
             for(i=0;plist[i];i++) sprintf(xname+strlen(xname),"%d",labs(plist[i])); 
             break; 
   case 'U': sprintf(units,"?");
             strcpy(xname,plist);
             break;  
   case 'Z': sprintf(units,"GeV");
             sprintf(xname,"plist");
             break;                   
   } 
} 

