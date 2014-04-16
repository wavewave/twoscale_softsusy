#include<math.h>
#include"../sources/micromegas_aux.h"

/*=================================================================*/

#define a (0.52)

typedef struct 
{
double A,r2,r4,r6;
} mom;
/* Data for momenta of charge distribution on various nuclei[G.Fricke et al]*/
mom data[20]=
{
{ 12, 2.4777, 2.7722, 3.0397},
{ 15, 2.6130, 2.9689, 3.3164},
{ 26, 2.9610, 3.2339, 3.4594},
{ 30, 3.1932, 3.5507, 3.8977},
{ 31, 3.1913, 3.5241, 3.8251},
{ 32, 3.2295, 3.5439, 3.8086},
{ 90, 4.2796, 4.6035, 4.8695},
{ 92, 4.3118, 4.6399, 4.9091},
{ 94, 4.3319, 4.6619, 4.9313},
{ 92, 4.3058, 4.6253, 4.8884},
{ 94, 4.3462, 4.6719, 4.9407},
{ 96, 4.3766, 4.7061, 4.9765},
{ 98, 4.4077, 4.7417, 5.0167},
{100, 4.4466, 4.7852, 5.0657},
{198, 5.4369, 5.7615, 6.0079},
{204, 5.4717, 5.8157, 6.0975},
{204, 5.4603, 5.8034, 6.0721},
{206, 5.4742, 5.8173, 6.0852},
{207, 5.4838, 5.8280, 6.0978},
{208, 5.4785, 5.8224, 6.0909}
};


double FExp(double p,double r2,double r4,double r6)
{
/* Momenta of charge distribution  correspond to coefficients of Tailor 
   expantion of  form factor. We resum Tailor series in form 
      F(p)= exp( polynomial(p^2)) 
   and calculate form factor.
*/   
 double pp=p*p,r22=r2*r2,r44=pow(r4,4),r66=pow(r6,6);
 
 return exp(
 pp*(-7560*r22 +pp*(-630*r22*r22 + 378*r44 +pp*(-70*r22*r22*r22+63*r22*r44-9*r66)))
 /45360
            );
}


double dFExp(double p,double r2,double r4,double r6)
{
/* returns the contribution of last term p^6 in exponent */
 return pow(p,6)*( - 70*pow(r2,6) + 63*pow(r2,2)*pow(r4,4) - 9*pow(r6,6) 
                )/45360;
}

double findR(double A,double r2,double r4,double r6,double E0)
{ 
/* finds Fermi radius which gives the same form factor at recoil 
   energy E0 as momenta 
*/   
   
  double p=sqrt(2*A*0.939*E0)/0.197327;
  double FFexp=FExp(p,r2,r4,r6);
  
  double R=0.5;
   
  for(;;R+=0.5)   { SetFermi(0,R,a); if(FFexp>FermiFF(1,p))break;}
  for(;;R-=0.1)   { SetFermi(0,R,a); if(FFexp<FermiFF(1,p))break;}
  for(;;R+=0.01)  { SetFermi(0,R,a); if(FFexp>FermiFF(1,p))break;}
  for(;;R-=0.001) { SetFermi(0,R,a); if(FFexp<FermiFF(1,p))break;}
  return R;

}


int main(void)
{
 int i;

 printf("plot [2.:6.0] \"-\",1.23*x - 0.6,\"-\", (0.84*x+0.55),sqrt(3./5.)*x*(1.15+1.8/x**2-1.2/x**4) \n");

 printf("#Fermi half radius\n");
 for(i=0;i<20;i++)
 {
   double R= findR(data[i].A,data[i].r2,data[i].r4,data[i].r6,15E-6);
   printf("%E  %E \n",pow(data[i].A,1./3.),R);
 }
 printf("e\n"); 
 printf("# sqrt(<r^2>) \n");
/* standard r2 interpolation  R=0.89*x+0.3
   and R= qrt(3./5.)*x*(1.15+1.8/x**2-1.2/x**4  Myers(1983) 
*/ 
 for(i=0;i<20;i++) printf("%E %E\n",pow(data[i].A,1./3.),data[i].r2); 
}
