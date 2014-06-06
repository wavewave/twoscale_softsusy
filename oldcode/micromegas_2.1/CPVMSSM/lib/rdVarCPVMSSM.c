#include"../../sources/micromegas.h"
#include"../../sources/micromegas_aux.h"
#include"pmodel.h"
#include"pmodel_f.h"

int readVarCPVMSSM(char * fname)
{
  char*vlist[46]={"alfSMZ","Mtp","MbMb","McMc","EE","SW","Ml","MHc",
  "aMu","fiMu","aM1","aM2","aM3","fiM1","fiM2","fiM3","Ml1","Ml2","Ml3",
  "Mr1","Mr2","Mr3","aAt","fiAt","aAb","fiAb","aAl","fiAl","aAe","fiAe",
  "Mq1","Mq2","Mq3","Mu1","Mu2","Mu3","Md1","Md2","Md3","wt","wZ","wW",
  "MZ","tb","Au","Ad"};

  return readVarSpecial(fname,46,vlist);
} 

int  readvarcpvmssm_(char * f_name,int len)
{
  char c_name[100];
  fName2c(f_name,c_name,len);
  
  return readVarCPVMSSM(c_name);
}
