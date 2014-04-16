#include"../../sources/micromegas.h"
#include"../../sources/micromegas_aux.h"
#include"pmodel.h"
#include"pmodel_f.h"

int readVarMSSM(char * fname)
{
  char*vlist[32]={
"alfEMZ","alfSMZ","SW","MZ","Ml","MbMb","Mtp","tb","MG1","MG2",
"MG3","Am","Al","At","Ab","Au","Ad","MH3","mu","Ml2",
"Ml3","Mr2","Mr3","Mq2","Mq3","Mu2","Mu3","Md2","Md3","wt",
"wZ","wW"};

  return readVarSpecial(fname,32,vlist);
} 

int  readvarmssm_(char * f_name,int len)
{
  char c_name[100];
  fName2c(f_name,c_name,len);
  
  return readVarMSSM(c_name);
}
