#ifndef __NMSSM__
#define __NMSSM__

#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void   HiggsMasses(FILE *f);
extern void   o1Contents(FILE * f);
extern double qbox_(void);
extern void   savemess_(int * code, char*mess, int len);
extern int    nmssmEWSB(void); 
extern int    nmssmSUGRA(double m0, double mhf,   double a0, double tb,
                         double sgn,double Lambda,double aLambda, double aKappa);
extern int    readVarNMSSM(char *fname);
extern int    readSLHA(char * fname);
extern int    NMHwarn(FILE * f);

extern double  b2sg_(double *M, double*P);
extern double  deltamd_(double *M, double*P);
extern double  deltams_(double *M, double*P);
extern double  bsmumu_(double *M, double*P);
extern double  btaunu_(double *M, double*P);
extern double  gmuon_(double *M, double*P);


#ifdef __cplusplus
}
#endif

#endif
