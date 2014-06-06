#include"pmodel.h"
#include"../../sources/micromegas_aux.h"
#include"pmodel_f.h"

int nmhwarn_(int *file)
{ 
  char fname[100];
  FILE*f;
  int r;

  if(*file==0) return NMHwarn(NULL);
                                                                                
  sprintf(fname,"%d.tmptxt",getpid());
  f=fopen(fname,"w");
  r=NMHwarn(f);
  fclose(f);
  fortreread_(file,fname,strlen(fname));
  unlink(fname);
  return r;
}

void higgsmasses_(int * Nch)
{
  char fname[20];
  FILE*f;
                                                                                
  sprintf(fname,"%d.tmptxt",getpid());
  f=fopen(fname,"w");
  HiggsMasses(f);
  fclose(f);
  fortreread_(Nch,fname,strlen(fname));
  unlink(fname);
}

void o1contents_(int *Nch)
{
  char fname[20];
  FILE*f;

  sprintf(fname,"%d.tmptxt",getpid());
  f=fopen(fname,"w");
  o1Contents(f);
  fclose(f);
  fortreread_(Nch,fname,strlen(fname));
  unlink(fname);
}
int nmssmewsb_(void){ return nmssmEWSB();}

int  nmssmsugra_(double *m0, double* mhf, double* a0, double* tb,
double*sgn, double*Lambda, double *aLambda, double*aKappa)
{
  return  nmssmSUGRA(*m0, *mhf, *a0, *tb, *sgn, *Lambda,*aLambda, *aKappa);
} 
