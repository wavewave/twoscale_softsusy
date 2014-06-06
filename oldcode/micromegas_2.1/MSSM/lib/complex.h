
#ifndef  __COMPLEX__
#define  __COMPLEX__

typedef struct
	{double r;
	double i;
	} complex;

const complex icomp;

extern void affichec(complex a);

extern complex prod(complex a,complex b);

extern complex conjug(complex a);

extern complex prodscal(double a, complex b);

extern complex diff(complex a, complex b);

extern complex somme(complex a, complex b);

#endif
