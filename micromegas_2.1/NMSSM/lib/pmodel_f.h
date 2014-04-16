#ifndef __NMSSN_F_ 
#define __NMSSN_F_
 
/*extern int nmhwarn_(int *N);*/
/* 
  integer function NMHwarn(N)
  interger N
*/

extern void  nmhdecay_(void);
extern void  nmspec_(double*m0,double*mhf,double*a0,double*tb,
                    double*sgn,double*Lambda,double*aKappa);
extern int nmhwarn_(int *file);                    
extern void higgsmasses_(int * file);
/*
      subroutine HiggsMasses(file)
      integer file
 */ 

extern void o1contents_(int *file);
/*   
       subroutine o1Contents(file)
       integer file
*/ 

extern int nmssmewsb_(void);
extern int  nmssmsugra_(double *m0, double* mhf, double* a0, double* tb,
double*sgn, double*Lambda, double *aLambda, double*aKappa);

extern int readvarnmssm_(char *fname, int len);

#endif
