#include"../../sources/micromegas.h"
#include"pmodel.h"

void HiggsMasses(FILE *f)
{
  char * imass[4]= {"Mh1","Mh2","Mh3","MHc"};
  char * iwidth[4]={"wh1","wh2","wh3","wHc"};
  int i;
  double mass[4],width;
  double ok=0;

  mass[0]=Mh1(ok),mass[1]=Mh2(ok),mass[2]=Mh3(ok),mass[3]=MHc(ok); 
     
  fprintf(f,"\nHiggs masses and widths\n");
     
  for(i=0;i<4;i++)
  { int err; 
    fprintf(f,"%-6.6s=%7.2f ",imass[i] ,mass[i]);
    width=findParam(iwidth[i],&err);     
    if(err==0) fprintf(f,"(%-6.6s=%.1E)",iwidth[i],width);
    fprintf(f,"\n");   
  }
}

void o1Contents(FILE * f)
{ double ok=0; 
  fprintf(f,"\n~o1 = ");

  fprintf(f,"(%.3f%+.3f*i)*bino+",Zn11r(ok),Zn11i(ok)); 
  fprintf(f,"(%.3f%+.3f*i)*wino+",Zn12r(ok),Zn12i(ok)); 
  fprintf(f,"(%.3f%+.3f*i)*higgsino1+",Zn13r(ok),Zn13i(ok)); 
  fprintf(f,"(%.3f%+.3f*i)*higgsino2",Zn14r(ok),Zn14i(ok)); 
  fprintf(f,"\n");
}
