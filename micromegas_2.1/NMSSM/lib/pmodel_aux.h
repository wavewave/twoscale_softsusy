
#ifndef __NMSSM_AUX__
#define __NMSSM_AUX__

extern int sugraLesH(char *fname,  double m0, double mhf, double a0,
double tb, double sgn, double  Lambda, double aLambda, double aKappa);

extern char * errTXTslha;

extern int EWSBLesH(char * fname);

extern int readLesH(char *fname, int SMplus);
extern int getdelfilesstat_(void);
#endif
