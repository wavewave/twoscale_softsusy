#include"../../sources/micromegas.h"
#include"../../sources/micromegas_aux.h"
#include"pmodel.h"
#include"pmodel_f.h"

int readVarMSSM(char * fname)
{ int rdCode;
  char*vlist[32]={
"alfEMZ","alfSMZ","SW","MZ","Ml","MbMb","Mtp","tb","MG1","MG2",
"MG3","Am","Al","At","Ab","Au","Ad","MH3","mu","Ml2",
"Ml3","Mr2","Mr3","Mq2","Mq3","Mu2","Mu3","Md2","Md3","wt",
"wZ","wW"};

  rdCode = readVarSpecial(fname,32,vlist);

  assignValW("Ml1",findValW("Ml2"));
  assignValW("Mr1",findValW("Mr2"));
  assignValW("Mq1",findValW("Mq2"));
  assignValW("Mu1",findValW("Mu2"));
  assignValW("Md1",findValW("Md2"));

  return rdCode;
} 

int  readvarmssm_(char * f_name,int len)
{
  char c_name[100];
  fName2c(f_name,c_name,len);
  
  return readVarMSSM(c_name);
}
