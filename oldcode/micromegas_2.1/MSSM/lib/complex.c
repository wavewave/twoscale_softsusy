#include<stdio.h>
#include "complex.h"

const complex icomp ={0,1};

void affichec(complex a)
{
printf("%e +i %e \n",a.r,a.i); 
}

complex prod(complex a, complex b)
{
complex temp;
temp.r=a.r*b.r-a.i*b.i;
temp.i=a.r*b.i+b.r*a.i;
return temp;
}

complex conjug(complex a)
{
complex temp;
temp.r=a.r;
temp.i=-a.i;
return temp;
}

complex prodscal(double a,complex b)

{
complex temp;
temp.r=a*b.r;
temp.i=a*b.i;
return temp;
}

complex somme(complex a,complex b)
{
complex temp;
temp.r=a.r+b.r;
temp.i=a.i+b.i;
return temp;
}

complex diff(complex a,complex b)
{
complex temp;
temp.r=a.r-b.r;
temp.i=a.i-b.i;
return temp;
}
