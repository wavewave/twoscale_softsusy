#include"../../sources/micromegas.h"
#include"pmodel.h"

void HiggsMasses(FILE *f)
{
  char * imass[4]= {"Mh","MHH","MH3","MHc"};
  char * iwidth[4]={"wh","wHh","wH3","wHc"};
  int i;
  double mass,width;

  fprintf(f,"\nHiggs masses and widths\n");
     
  for(i=0;i<4;i++) if(!findVal(imass[i],&mass))
  { int err;
    fprintf(f,"%-6.6s=%7.2f ",imass[i] ,mass);
    width=findParam(iwidth[i],&err);
    if(err==0)fprintf(f,"(%-6.6s=%.1E)",iwidth[i],width);
    fprintf(f,"\n");
  }
}

void o1Contents(FILE * f)
{  
  fprintf(f,"\n~o1 = %.3f*bino %+.3f*wino %+.3f*higgsino1 %+.3f*higgsino2\n",
      findValW("Zn11"), findValW("Zn12"), findValW("Zn13"), findValW("Zn14"));
}
