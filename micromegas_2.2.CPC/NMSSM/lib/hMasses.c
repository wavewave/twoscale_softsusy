#include"../../sources/micromegas.h"
#include"pmodel.h"

void HiggsMasses(FILE *f)
{
  char * imass[6]= {"Mh1","Mh2","Mh3","Mha","Mhb","MHc"};
  int i;
  double mass,width;
  int err;
  fprintf(f,"\nHiggs masses\n");
     
  for(i=0;i<6;i++)
  {
    err=findVal(imass[i],&mass);
    if(err==0) { fprintf(f,"%-6.6s=%7.2f\n",imass[i] ,mass); }   
  }
}

void o1Contents(FILE * f)
{ double val; 
  int err; 
 
  fprintf(f,"\n~o1 = ");
  err=findVal("Zn11",&val);
  if(err==0) fprintf(f,"%.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"bino");

  err=findVal("Zn12",&val);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"wino");
  
  err=findVal("Zn13",&val);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"higgsino1");
  
  err=findVal("Zn14",&val);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"higgsino2");
  
  err=findVal("Zn15",&val);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"singlino\n");
}
