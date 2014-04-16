#ifndef __CUT__
#define __CUT__

#include<stdio.h>
#include "file_scr.h"
#include "kinaux.h"

extern int fillCutArray(void);
extern int rdrcut_(FILE *);
extern int wrtcut_(FILE *);

extern double  calcCutFactor(void);

extern int rancor_(double *vmin, double *vmax, double shift, double fmult, int n);

extern table cutTab;


typedef struct {
       char key;
       char lvinvc[PLISTLEN];
       int minon, maxon;
       double  cvmin, cvmax;
} invcut_;
 
extern invcut_ invcut_1[60];

#endif
