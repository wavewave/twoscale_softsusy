#include "bc.h"

#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>

const double Mpl = 2.4e18 ; 


void EW_higgsino_BC2( MssmSoftsusy& m, double m0, 
		      double mhiggsino,  
		      double m12 , double A, double tanb, double sgnMu ) 
{
  //  double m0, mhiggsino, m12 ; 
  //  double A ;
  double M1, M2, M3, M2Q3, M2U3, M2D3, M2L3, M2E3, M2Hu, M2Hd;
  double At, Atau, Ab; 
  
  //  m0 = pars.display(1); 
  // mhiggsino = pars.display(2); 
  // m12 = pars.display(3); 
  // A = pars.display(4); 
  
  const double MZ = 90 ;
  double tan2b, Mu; 

  M1 = m12; 
  M2 = m12;
  M3 = m12; 

  M2Q3 = m0*m0 ;
  M2U3 = m0*m0 ;
  M2D3 = m0*m0 ; 
  M2L3 = m0*m0 ; 
  M2E3 = m0*m0 ; 

  M2Hu = -mhiggsino * mhiggsino ; 
  M2Hd = -mhiggsino * mhiggsino ; 

  tan2b = 2. * tanb / ( 1- tanb * tanb ) ; 
  Mu = sqrt( 0.5 * (tan2b * ( M2Hu * tanb - M2Hd / tanb ) - MZ * MZ) ) 
    * sgnMu ;
  m.setSusyMu( Mu ); 
  m.setHvev( 246 ) ;
  m.setTanb(tanb ); 
  m.setMu( MZ ); 
  
  At =   A; 
  Ab=    A;  
  Atau = A;  

  m.setGauginoMass(1, M1 );
  m.setGauginoMass(2, M2 ); 
  m.setGauginoMass(3, M3 ); 
  m.setMh2Squared( M2Hu ); 
  m.setMh1Squared( M2Hd ); 


  m.setSoftMassElement(mQl, 3, 3, M2Q3 );
  m.setSoftMassElement(mUr, 3, 3, M2U3 );
  m.setSoftMassElement(mDr, 3, 3, M2D3 );
  m.setSoftMassElement(mLl, 3, 3, M2L3 );
  m.setSoftMassElement(mEr, 3, 3, M2E3 );


  m.setSoftMassElement(mQl, 2, 2, M2Q3 );
  m.setSoftMassElement(mUr, 2, 2, M2U3 );
  m.setSoftMassElement(mDr, 2, 2, M2D3 );
  m.setSoftMassElement(mLl, 2, 2, M2L3 );
  m.setSoftMassElement(mEr, 2, 2, M2E3 );


  m.setSoftMassElement(mQl, 1, 1, M2Q3 );
  m.setSoftMassElement(mUr, 1, 1, M2U3 );
  m.setSoftMassElement(mDr, 1, 1, M2D3 );
  m.setSoftMassElement(mLl, 1, 1, M2L3 );
  m.setSoftMassElement(mEr, 1, 1, M2E3 );

  m.setTrilinearMatrix(UA,   
			m.displayYukawaMatrix(YU) * At);
  m.setTrilinearMatrix(DA,   
		       m.displayYukawaMatrix(YD) * Ab);
  m.setTrilinearMatrix(EA,   
		       m.displayYukawaMatrix(YE) * Atau);


}

void mSUGRA_BC( MssmSoftsusy& m, const DoubleVector &pars )
{

  double m0, m12 , A0; 
  double M1, M2, M3, M2Q3, M2U3, M2D3, M2L3, M2E3, M2Hu, M2Hd;
  double At, Atau, Ab; 

  
  m0 =  pars.display(1); 
  m12  =  pars.display(2); 
  A0 = pars.display(3);

	
  M1 = m12; 
  M2 = m12;
  M3 = m12; 

  M2Q3 = m0*m0 ;
  M2U3 = m0*m0 ;
  M2D3 = m0*m0 ; 
  M2L3 = m0*m0 ; 
  M2E3 = m0*m0 ; 

  M2Hu = m0*m0 ; 
  M2Hd = m0*m0 ; 
 
  At =   A0; 
  Ab=    A0;  
  Atau = A0;  

  m.setGauginoMass(1, M1 );
  m.setGauginoMass(2, M2 ); 
  m.setGauginoMass(3, M3 ); 
  m.setMh2Squared( M2Hu ); 
  m.setMh1Squared( M2Hd ); 


  m.setSoftMassElement(mQl, 3, 3, M2Q3 );
  m.setSoftMassElement(mUr, 3, 3, M2U3 );
  m.setSoftMassElement(mDr, 3, 3, M2D3 );
  m.setSoftMassElement(mLl, 3, 3, M2L3 );
  m.setSoftMassElement(mEr, 3, 3, M2E3 );


  m.setSoftMassElement(mQl, 2, 2, M2Q3 );
  m.setSoftMassElement(mUr, 2, 2, M2U3 );
  m.setSoftMassElement(mDr, 2, 2, M2D3 );
  m.setSoftMassElement(mLl, 2, 2, M2L3 );
  m.setSoftMassElement(mEr, 2, 2, M2E3 );


  m.setSoftMassElement(mQl, 1, 1, M2Q3 );
  m.setSoftMassElement(mUr, 1, 1, M2U3 );
  m.setSoftMassElement(mDr, 1, 1, M2D3 );
  m.setSoftMassElement(mLl, 1, 1, M2L3 );
  m.setSoftMassElement(mEr, 1, 1, M2E3 );

  m.setTrilinearMatrix(UA,   
			m.displayYukawaMatrix(YU) * At);
  m.setTrilinearMatrix(DA,   
		       m.displayYukawaMatrix(YD) * Ab);
  m.setTrilinearMatrix(EA,   
		       m.displayYukawaMatrix(YE) * Atau);
  
  
}

double alpha_M0_m32_function( double x, double M0, double alpha ) 
{
  double result , m32;
  m32 = x; 
  result = alpha * M0 - m32 / log( Mpl / m32 ) ; 
  return result; 
}

struct mirageparams {
  double alpha;
  double M0 ;  
}; 

double my_alpha_M0_m32_function( double x, void* params ) 
{
  struct mirageparams *p = (struct mirageparams *)params ;
  
  double alpha = p->alpha; 
  double M0 = p->M0; 

  return alpha_M0_m32_function( x, M0, alpha ); 
}

double find_out_m32_in_mirage( double alpha, double M0 )
{
  int status ; 
  int iter = 0 , max_iter = 100 ;
  const gsl_root_fsolver_type *T ; 
  gsl_root_fsolver *s ;
  

  static double m32 = 100;
  static double alpha_t = 0 ; 
  static double M0_t = 0; 

  if( (alpha == alpha_t) && ( M0 == M0_t ) ) 
    return m32 ; 
 
  double r ;
  double x_lo = 1 ; 
  double x_hi = 100000 ; 
  gsl_function F; 
  struct mirageparams params = { alpha , M0 } ; 

  F.function = &my_alpha_M0_m32_function; 
  F.params = &params; 

  T = gsl_root_fsolver_brent; 
  s = gsl_root_fsolver_alloc(T); 
  gsl_root_fsolver_set( s, &F , x_lo , x_hi )  ; 

  do { 
    iter++ ; 
    status = gsl_root_fsolver_iterate(s); 
    r = gsl_root_fsolver_root(s); 
    x_lo = gsl_root_fsolver_x_lower(s); 
    x_hi = gsl_root_fsolver_x_upper(s); 
    status = gsl_root_test_interval( x_lo, x_hi, 0, 0.001 ) ; 
  }
  while( status == GSL_CONTINUE && iter < max_iter ) ; 
  
  if( status == GSL_SUCCESS ) { 
  
    printf("The answer m32 = %g\n" , r )  ; 
    
    m32 = r ; 
  }

  gsl_root_fsolver_free(s); 

  return m32 ;
}

void mirage_simple_BC( MssmSoftsusy& m, const DoubleVector &pars )
{
  double alpha ; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 
  //  double cHu, cHd, cQ, cU, cD, cL, cE ; 

  aHu = aHd = 0; 
  aQ = aU = aD = aL = aE = 0.5 ; 

  alpha = pars.display(1); 
  M0 = pars.display(2); 

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = m.displayGaugeCoupling(1); 
  g2 = m.displayGaugeCoupling(2); 
  g3 = m.displayGaugeCoupling(3); 
  gY = sqrt(3./5.) * g1 ; 
  yt = m.displayYukawaElement(YU,3,3); 
  yb = m.displayYukawaElement(YD,3,3); 
  ytau = m.displayYukawaElement(YE,3,3); 
  

  double b3, b2 , b1 ; 
  b3 = -3 ; b2= 1 ; b1 = 33./ 5. ;

  double gammaHu , gammaHd  ;
  double gammaQ[4], gammaU[4], gammaD[4] ; 
  double gammaL[4], gammaE[4] ; 

  gammaHu = 3./2. *g2*g2 + 1./2. * gY * gY - 3. * yt *yt;
  gammaHd = 3./2. *g2*g2 + 1./2. * gY * gY - 3. * yb *yb - ytau*ytau ;
  
  for( int i = 1;  i <= 3 ; i++ ) { 
    gammaQ[i] = 8./3. *g3*g3 + 3./2.*g2*g2 + 1./18. *gY *gY 
      - ( i==3 ? (yt*yt + yb*yb ) :0 ) ; 
    gammaU[i] = 8./3. *g3*g3 + 8./9.*gY*gY 
      - ( i==3 ? (2.*yt*yt): 0 ) ; 
    gammaD[i] = 8./3. *g3*g3 + 2./9.*gY*gY
      - ( i==3 ? (2.*yb*yb): 0 ) ; 
    gammaL[i] = 3./2. *g2*g2 + 1./2.*gY*gY
      - ( i==3 ? (ytau*ytau) : 0 ) ;
    gammaE[i] = 2. * gY*gY - ( i==3 ? (2.*ytau*ytau) : 0 ) ; 
  }

  double thetaHu , thetaHd  ;
  double thetaQ[4], thetaU[4], thetaD[4];
  double thetaL[4], thetaE[4] ; 

  thetaHu = 3.*g2*g2 + gY*gY - 6.*yt*yt*(aHu + aQ + aU ) ; 
  thetaHd = 3.*g2*g2 + gY*gY - 6.*yb*yb*(aHd + aQ + aD ) 
    - 2.*ytau*ytau*(aHd + aL + aE ) ; 
  for( int i = 1 ; i <= 3 ; i++ ) {
    thetaQ[i] = 16./3. * g3*g3 + 3.*g2*g2 + 1./9.*gY*gY 
      - (i==3 ? (2.*yt*yt*(aHu+aQ+aU) + 2.*yb*yb*(aHd+aQ+aD) ): 0 ) ; 
    thetaU[i] = 16./3. * g3*g3 + 16./9.*gY*gY 
      - (i==3 ? (4.*yt*yt*(aHu+aQ+aU)) : 0 ) ; 
    thetaD[i] = 16./3. * g3*g3 + 4./9. *gY*gY
      - (i==3 ? (4.*yb*yb*(aHd+aQ+aD)) : 0 ) ; 
    thetaL[i] = 3.*g2*g2 + gY*gY 
      - (i==3 ? (2.*ytau*ytau*(aHd+aL+aE)): 0 ) ;
    thetaE[i] = 4.*gY*gY 
      - (i==3 ? (4.*ytau*ytau*(aHd+aL+aE)): 0 ) ; 
  }
 
  double dgammaHu , dgammaHd ; 
  double dgammaQ[4], dgammaU[4], dgammaD[4] ; 
  double dgammaL[4], dgammaE[4] ;

  double byt , byb , bytau ; 
  byt = -16./3.*g3*g3 - 3.*g2*g2 - 13./9.*gY*gY + 6.*yt*yt + yb*yb ; 
  byb = -16./3.*g3*g3 - 3.*g2*g2 - 7./9. *gY*gY + yt*yt + 6.*yb*yb + ytau*ytau;
  bytau = -3.*g2*g2 - 3.*gY*gY + 3.*yb*yb + 4.*ytau*ytau ;
  
  
  dgammaHu = 3./2. * g2*g2*g2*g2 + 11./2. * gY*gY*gY*gY 
    - 3. * yt*yt * byt ; 
  dgammaHd = 3./2. * g2*g2*g2*g2 + 11./2. * gY*gY*gY*gY 
    - 3. * yb*yb *byb - ytau*ytau*bytau ;
  for( int i = 1 ; i <=3 ; i++ ) {
    dgammaQ[i] = -8.*g3*g3*g3*g3 + 3./2.*g2*g2*g2*g2 
      + 11./18. *gY*gY*gY*gY 
      - ( i==3 ? (yt*yt*byt + yb*yb*byb) : 0 ) ; 
    dgammaU[i] = -8.*g3*g3*g3*g3 + 88./9.*gY*gY*gY*gY
      - ( i==3 ? (2.*yt*yt*byt) : 0 ) ; 
    dgammaD[i] = -8.*g3*g3*g3*g3 + 22./9.*gY*gY*gY*gY
      - ( i==3 ? (2.*yb*yb*byb) : 0 ) ; 
    dgammaL[i] = 3./2.*g2*g2*g2*g2 + 11./2.*gY*gY*gY*gY
      - ( i==3 ? (ytau*ytau*bytau) : 0 ) ; 
    dgammaE[i] = 22.*gY*gY*gY*gY 
      - ( i==3 ? (2.*ytau*ytau*bytau) : 0 ) ; 
  }


  double M1, M2, M3, M2Q3, M2U3, M2D3, M2L3, M2E3, M2Hu, M2Hd;
  double At, Atau, Ab;  
  double m32 ; 


  m32 =  find_out_m32_in_mirage( alpha, M0 ) ; 
  M1 = M0 + m32/ (16.* M_PI * M_PI ) * b1 * g1 * g1; 
  M2 = M0 + m32/ (16.* M_PI * M_PI ) * b2 * g2 * g2; 
  M3 = M0 + m32/ (16.* M_PI * M_PI ) * b3 * g3 * g3; 
  
  At = (aHu+aQ+aU) * M0 - m32/(16.*M_PI*M_PI)*(gammaQ[3]+gammaU[3]+gammaHu); 
  Ab = (aHd+aQ+aD) * M0 - m32/(16.*M_PI*M_PI)*(gammaQ[3]+gammaD[3]*gammaHd); 
  Atau = (aHd+aL+aE) * M0 - m32/(16.*M_PI*M_PI)*(gammaL[3]+gammaE[3]+gammaHd);

  M2Hu = aHu*M0*M0 - m32/(16.*M_PI*M_PI)*M0*thetaHu 
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHu ; 
  M2Hd = aHd*M0*M0 - m32/(16.*M_PI*M_PI)*M0*thetaHd
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHd ; 
  M2Q3 = aQ*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaQ[3]
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaQ[3] ;
  M2U3 = aU*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaU[3]
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaU[3] ;
  M2D3 = aD*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaD[3]
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaD[3] ;
  M2L3 = aL*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaL[3]
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaL[3] ;
  M2E3 = aE*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaE[3]
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaE[3] ;

  m.setGauginoMass(1, M1 );
  m.setGauginoMass(2, M2 ); 
  m.setGauginoMass(3, M3 ); 
  m.setMh2Squared( M2Hu ); 
  m.setMh1Squared( M2Hd ); 


  m.setSoftMassElement(mQl, 3, 3, M2Q3 );
  m.setSoftMassElement(mUr, 3, 3, M2U3 );
  m.setSoftMassElement(mDr, 3, 3, M2D3 );
  m.setSoftMassElement(mLl, 3, 3, M2L3 );
  m.setSoftMassElement(mEr, 3, 3, M2E3 );


  m.setSoftMassElement(mQl, 2, 2, M2Q3 );
  m.setSoftMassElement(mUr, 2, 2, M2U3 );
  m.setSoftMassElement(mDr, 2, 2, M2D3 );
  m.setSoftMassElement(mLl, 2, 2, M2L3 );
  m.setSoftMassElement(mEr, 2, 2, M2E3 );


  m.setSoftMassElement(mQl, 1, 1, M2Q3 );
  m.setSoftMassElement(mUr, 1, 1, M2U3 );
  m.setSoftMassElement(mDr, 1, 1, M2D3 );
  m.setSoftMassElement(mLl, 1, 1, M2L3 );
  m.setSoftMassElement(mEr, 1, 1, M2E3 );

  m.setTrilinearMatrix(UA,   
			m.displayYukawaMatrix(YU) * At);
  m.setTrilinearMatrix(DA,   
		       m.displayYukawaMatrix(YD) * Ab);
  m.setTrilinearMatrix(EA,   
		       m.displayYukawaMatrix(YE) * Atau);
}
