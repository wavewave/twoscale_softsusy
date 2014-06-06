#include"../../sources/micromegas.h"
#include"../../sources/micromegas_aux.h"
#include"pmodel.h"
#include"pmodel_f.h"

int readVarNMSSM(char * fname)
{
  char*vlist[36]={"alfEMZ","alfSMZ","McMc","MbMb","Mtp","tb","MG1","MG2","MG3",
  "Ml2","Ml3","Mr2","Mr3","Mq2","Mq3","Mu2","Mu3","Md2","Md3","At","Ab","Al",
  "Au","Ad","Am","mu","LambdQ","KappaQ","aLmbdQ","aKappQ","MZ","Mm","Ml","wt",
  "wZ","wW"};
  return readVarSpecial(fname,36,vlist);
} 

int  readvarnmssm_(char * f_name,int len)
{
  char c_name[100];
  fName2c(f_name,c_name,len);
  
  return readVarNMSSM(c_name);
}
