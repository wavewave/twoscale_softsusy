
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{ char buff[500],name[500]; 
  FILE * f=fopen("models/vars1.mdl","r");
  double val;
  int n,i;
  FILE *out; 
  long pos;
   
  if(f==NULL) exit(1);
  out=fopen("variables.c","w");   
  fgets(buff,500, f); fgets(buff,500, f); fgets(buff,500, f);
  fprintf(out,"#include\"../../sources/micromegas_aux.h\"\n");
  fprintf(out,"#define NVARDEF ");
  pos=ftell(out);
  fprintf(out,"           \n");
  fprintf(out," varSTR modelVar[NVARDEF]=\n{\n");
  for(n=0;1==fscanf(f,"%[^|]%*c",buff);)
  { 
    for(i=0;buff[i]&&buff[i]==' ' ;i++);  
    if(buff[i]=='*') buff[i]=' ';
    
    sscanf(buff,"%s",name);
    if(name[0]=='=') break;
    if(name[0]!='%')
    { if(n) fprintf(out,","); else fprintf(out," "); 
      n++;
      fscanf(f,"%lf",&val);
      fprintf(out, "{\"%s\", %E}\n",name,val);
    }
    fgets(buff,500, f);
  }
  fprintf(out,"};\n");
  fprintf(out,"int NVAR=NVARDEF;\n");
  fseek(out, pos, SEEK_SET); fprintf(out,"%d",n);
  fclose(f); fclose(out);
  return 0;
}
