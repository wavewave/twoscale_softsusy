#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{ char buff[500]; 
  FILE * f=fopen("models/prtcls1.mdl","r");
  int n,i;
  FILE *out; 
  long pos;
   
  if(f==NULL) exit(1);
  out=fopen("odd_particles.c","w");  
  fgets(buff,500, f); fgets(buff,500, f); fgets(buff,500, f);
  fprintf(out,"#include\"../../sources/micromegas_aux.h\"\n");
  fprintf(out,"#define NODD ");
  pos=ftell(out);
  fprintf(out,"           \n");
  fprintf(out,"OddPrtclsSTR OddPrtcls[NODD]=\n{\n");
  fprintf(out,"/*{ char* name; char* aname; int NPDG;char* mass; char* width; int spin2; int cdim;}*/\n");  
  for(n=0;1==fscanf(f,"%[^|]%*c",buff);)
  { char name[20],aname[20],mass[20],width[20],rest[200];
    long num;
    int spin,color,l;
    if(buff[0]=='=') break;
    fgets(buff,500, f);
    for(i=0;buff[i];i++) if(buff[i]=='|' || buff[i]=='!') buff[i]=' ';
    l=sscanf(buff,"%s %s %ld %d %s %s %d %s",name,aname,&num,&spin,mass,width,&color,rest);
    if(l<7) break;
    if(l==8 && rest[0]=='*') continue;
    if(name[0]=='~' && aname[0]=='~' && mass[0]!='0')
    { 
      if(n)fprintf(out,","); n++;
      fprintf(out,"{\"%s\",\"%s\",%ld,\"%s\",\"%s\",%d,%d}\n",
      name,aname,num,mass,width,spin,color);
    }
  }
  fprintf(out,"};\n");
  fprintf(out,"int Nodd=NODD;\n");
  fseek(out, pos, SEEK_SET); fprintf(out,"%d",n); 
  fclose(f); fclose(out);
  return 0;
}
