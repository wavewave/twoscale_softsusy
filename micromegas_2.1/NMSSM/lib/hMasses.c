#include"../../sources/micromegas.h"
#include"pmodel.h"

void HiggsMasses(FILE *f)
{
  char * imass[6]= {"Mh1","Mh2","Mh3","Mha","Mhb","MHc"};
  char * iwidth[6]={"wh1","wh2","wh3","wha","whb","wHc"};
  int i;
  double mass,width;
  int err;
  fprintf(f,"\nHiggs masses and widths\n");
     
  for(i=0;i<6;i++)
  {
    mass=findParam(imass[i],&err);
    if(err==0)
    {  fprintf(f,"%-6.6s=%7.2f ",imass[i] ,mass);
       width=findParam(iwidth[i],&err);     
       if(err==0) fprintf(f,"(%-6.6s=%.1E)",iwidth[i],width);
       fprintf(f,"\n");
    }   
  }
}

void o1Contents(FILE * f)
{ double val; 
  fprintf(f,"\n~o1 = ");
  int err;
  val=findParam("Zn11",&err);
  if(err==0) fprintf(f,"%.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"bino");

  val=findParam("Zn12",&err);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"wino");
  
  val=findParam("Zn13",&err);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"higgsino1");
  
  val=findParam("Zn14",&err);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"higgsino2");
  
  val=findParam("Zn15",&err);
  if(err==0) fprintf(f,"%+.3f*",val); else  fprintf(f,"???*");  
  fprintf(f,"singlino\n");
}
