#include <iostream>
#include <fstream>
#include <string> 

#include <softpoint.h>

#include "micromegas.h"
#include "pmodel.h"


#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_roots.h>

#include <gsl/gsl_sf_lambert.h>



//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
////                                              ////
////         DEFINE GLOBAL VARIABLES              ////
////                                              ////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

#define MGUTSCALE 2e16
const double Mpl = 2.4e18 ; 
//const double MZ = 91.2 ; 

int numscan;

int l1, l2, l3 ; 
double nQ, nL, nU, nD, nE, nHu, nHd ; 
int N ; 

double global_g1 , global_g2 , global_g3 ;

double global_yt, global_yb, global_ytau; 

double M_moduli, M_gauge, M_mess ;

double m32; 

double mgut0, mgut1, mgut2; 

double inter_gaugino1 ,inter_gaugino2, inter_gaugino3 ; 
DoubleMatrix inter_massmQl(3,3) ;
DoubleMatrix inter_massmUr(3,3) ;
DoubleMatrix inter_massmDr(3,3) ;
DoubleMatrix inter_massmLl(3,3) ;
DoubleMatrix inter_massmEr(3,3) ;
double inter_massmHu ;
double inter_massmHd ; 
DoubleMatrix inter_A_HuQU(3,3); 
DoubleMatrix inter_A_HdQD(3,3);
DoubleMatrix inter_A_HdLE(3,3); 


///////////////////////////////////////
///////////////////////////////////////
/////                              ////
////  USEFUL FUNCTIONS             ////
////                               ////
///////////////////////////////////////
///////////////////////////////////////

double randomgenerator( double from, double to ) 
{
  double r ; 
  r = ((double)rand()) / ((double)RAND_MAX) * (to-from) + from; 
  return r ;
}

double lograndomgenerator( double from , double to ) 
{
  double logfrom, logto ;
  double logr ;
  logfrom = log(from); 
  logto = log(to); 
  logr = ((double)rand()) / ((double)RAND_MAX) * (logto-logfrom) + logfrom ; 
  return exp(logr) ; 
}

double MZ2( double mu2, double tanb, double mHu2 , double mHd2 ) 
{
  double cotb = 1.0 / tanb ; 
  double tan2b = tanb / (1.0 - tanb * tanb)  ;
  double result ; 

  result = - 2.0 * mu2 + tan2b * ( mHu2 * tanb - mHd2 * cotb ) ; 

  return result; 
}

double findmu2( double tanb, double mHu2, double mHd2 ) 
{
  double cotb = 1.0 / tanb ; 
  double tan2b = tanb / (1.0 - tanb * tanb)  ;
  double result ; 

  result = 0.5*( tan2b * ( mHu2 * tanb - mHd2 * cotb ) - MZ *MZ ) ; 

  return result; 
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////                                               ////
////      FOR DEFLECTED MIRAGE MEDIATION           ////
////                                               ////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


double alpha_M0_m32_function( double x, double M0, double alpha ) 
{
  double result ;
  result = alpha * M0 - x / log( Mpl / x ) ; 
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
  double result ;
  result = alpha*M0 * gsl_sf_lambert_W0( Mpl / (alpha*M0 ) ) ;
  return result; 

}

void mirage_simple_BC0( MssmSoftsusy& m, const DoubleVector &pars )
{
  double alpha, beta ; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 
  //  double cHu, cHd, cQ, cU, cD, cL, cE ; 

  //  aHu = aHd = 0; 
  //  aQ = aU = aD = aL = aE = 0.5 ; 

  aHu = 1.0 - nHu ; aHd = 1.0 - nHd ; 
  aQ = 1.0 - nQ ; aU = 1.0 - nU ; aD = 1.0 - nD ; 
  aL = 1.0 - nL ; aE = 1.0 - nE ; 

  alpha = pars.display(1); 
  beta = pars.display(2); 
  M0 = pars.display(3); 

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = m.displayGaugeCoupling(1); 
  g2 = m.displayGaugeCoupling(2); 
  g3 = m.displayGaugeCoupling(3); 
  gY = sqrt(3./5.) * g1 ; 
  yt = m.displayYukawaElement(YU,3,3); 
  yb = m.displayYukawaElement(YD,3,3); 
  ytau = m.displayYukawaElement(YE,3,3); 
  

  double b3p, b2p , b1p ; 
  b3p = -3 +N  ; b2p= 1 + N ; b1p = 33./ 5. + N  ;

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
  
  
  dgammaHu = 3./2. * b2p * g2*g2*g2*g2 + 3./10.* b1p * g1*g1*g1*g1 
    - 3. * yt*yt * byt ; 
  dgammaHd = 3./2. * b2p * g2*g2*g2*g2 + 3./10.* b1p * g1*g1*g1*g1 
    - 3. * yb*yb *byb - ytau*ytau*bytau ;
  for( int i = 1 ; i <=3 ; i++ ) {
    dgammaQ[i] = 8./3.*b3p *g3*g3*g3*g3 + 3./2.* b2p *g2*g2*g2*g2 
      + 1./30.*b1p *g1*g1*g1*g1 
      - ( i==3 ? (yt*yt*byt + yb*yb*byb) : 0 ) ; 
    dgammaU[i] = 8./3.*b3p *g3*g3*g3*g3 + 8./15.*b1p *g1*g1*g1*g1
      - ( i==3 ? (2.*yt*yt*byt) : 0 ) ; 
    dgammaD[i] = 8./3.*b3p *g3*g3*g3*g3 + 2./15.*b1p *g1*g1*g1*g1
      - ( i==3 ? (2.*yb*yb*byb) : 0 ) ; 
    dgammaL[i] = 3./2.*b2p *g2*g2*g2*g2 + 3./10.*b1p *g1*g1*g1*g1
      - ( i==3 ? (ytau*ytau*bytau) : 0 ) ; 
    dgammaE[i] = 6./5.*b1p *g1*g1*g1*g1 
      - ( i==3 ? (2.*ytau*ytau*bytau) : 0 ) ; 
  }


  double M1, M2, M3; 
  double M2Q[4], M2U[4], M2D[4], M2L[4], M2E[4], M2Hu, M2Hd;
  double At[4], Atau[4], Ab[4];  
  //  double m32 ; 


  // m32 =  find_out_m32_in_mirage( alpha, M0 ) ; 
  M1 = M0 + m32/ (16.* M_PI * M_PI ) * b1p * g1 * g1; 
  M2 = M0 + m32/ (16.* M_PI * M_PI ) * b2p * g2 * g2; 
  M3 = M0 + m32/ (16.* M_PI * M_PI ) * b3p * g3 * g3; 

  for( int i = 1; i<= 3 ; i++ ) {
    At[i] = -(aHu+aQ+aU) * M0 
      +m32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaU[i]+gammaHu); 
    Ab[i] = -(aHd+aQ+aD) * M0 
      +m32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaD[i]+gammaHd); 
    Atau[i] = -(aHd+aL+aE) * M0 
      + m32/(16.*M_PI*M_PI)*(gammaL[i]+gammaE[i]+gammaHd);
  }  
  M2Hu = aHu*M0*M0 - m32/(16.*M_PI*M_PI)*M0*thetaHu 
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHu ; 
  M2Hd = aHd*M0*M0 - m32/(16.*M_PI*M_PI)*M0*thetaHd
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHd ; 

  for( int i = 1 ; i <= 3 ; i++ ) {
    M2Q[i] = aQ*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaQ[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaQ[i] ;
    M2U[i] = aU*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaU[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaU[i] ;
    M2D[i] = aD*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaD[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaD[i] ;
    M2L[i] = aL*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaL[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaL[i] ;
    M2E[i] = aE*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaE[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaE[i] ;
  }

  m.setGauginoMass(1, M1 );
  m.setGauginoMass(2, M2 ); 
  m.setGauginoMass(3, M3 ); 
  m.setMh2Squared( M2Hu ); 
  m.setMh1Squared( M2Hd ); 

  for( int i = 1 ; i <= 3 ; i++ ) { 
    m.setSoftMassElement(mQl, i, i, M2Q[i]);
    m.setSoftMassElement(mUr, i, i, M2U[i] );
    m.setSoftMassElement(mDr, i, i, M2D[i] );
    m.setSoftMassElement(mLl, i, i, M2L[i] );
    m.setSoftMassElement(mEr, i, i, M2E[i] );
  } 

  for( int i = 1 ; i <= 3 ; i++ ) {
    m.setTrilinearElement(UA, i,i, 
			  m.displayYukawaElement(YU,i,i) * At[i]);
    m.setTrilinearElement(DA, i,i,   
			  m.displayYukawaElement(YD,i,i) * Ab[i]);
    m.setTrilinearElement(EA, i,i,   
			  m.displayYukawaElement(YE,i,i) * Atau[i]);
  }
}

void mirage_simple_BC1( MssmSoftsusy& m, const DoubleVector &pars )
{
  double alpha, beta; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 
  //  double cHu, cHd, cQ, cU, cD, cL, cE ; 

  //  aHu = aHd = 0; 
  //  aQ = aU = aD = aL = aE = 0.5 ; 

  aHu = 1.0 - nHu ; aHd = 1.0 - nHd ; 
  aQ = 1.0 - nQ ; aU = 1.0 - nU ; aD = 1.0 - nD ; 
  aL = 1.0 - nL ; aE = 1.0 - nE ; 

  alpha = pars.display(1);
  beta = pars.display(2); 
  M0 = pars.display(3); 

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = global_g1 ; /* m.displayGaugeCoupling(1); */
  g2 = global_g2 ; /* m.displayGaugeCoupling(2); */
  g3 = global_g3 ; /* m.displayGaugeCoupling(3); */
  gY = sqrt(3./5.) * g1 ; 
  //  yt = m.displayYukawaElement(YU,3,3); 
  //  yb = m.displayYukawaElement(YD,3,3); 
  //  ytau = m.displayYukawaElement(YE,3,3); 
  yt = global_yt ; 
  yb = global_yb ; 
  ytau = global_ytau; 
  
  /////////////////////////// IMPORTANT /////////////////////////////////

  m.setGaugeCoupling( 1, global_g1 ); 
  m.setGaugeCoupling( 2, global_g2 ); 
  m.setGaugeCoupling( 3, global_g3 ); 

  m.setYukawaElement( YU, 3, 3, global_yt ); 
  m.setYukawaElement( YD, 3, 3, global_yb ); 
  m.setYukawaElement( YE, 3, 3, global_ytau ); 

  ///////////////////////////////////////////////////////////////////////

  double b3p, b2p , b1p ; 
  b3p = -3 +N  ; b2p= 1 + N ; b1p = 33./ 5. + N  ;

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
  
  
  dgammaHu = 3./2. * b2p * g2*g2*g2*g2 + 3./10.* b1p * g1*g1*g1*g1 
    - 3. * yt*yt * byt ; 
  dgammaHd = 3./2. * b2p * g2*g2*g2*g2 + 3./10.* b1p * g1*g1*g1*g1 
    - 3. * yb*yb *byb - ytau*ytau*bytau ;
  for( int i = 1 ; i <=3 ; i++ ) {
    dgammaQ[i] = 8./3.*b3p *g3*g3*g3*g3 + 3./2.* b2p *g2*g2*g2*g2 
      + 1./30.*b1p *g1*g1*g1*g1 
      - ( i==3 ? (yt*yt*byt + yb*yb*byb) : 0 ) ; 
    dgammaU[i] = 8./3.*b3p *g3*g3*g3*g3 + 8./15.*b1p *g1*g1*g1*g1
      - ( i==3 ? (2.*yt*yt*byt) : 0 ) ; 
    dgammaD[i] = 8./3.*b3p *g3*g3*g3*g3 + 2./15.*b1p *g1*g1*g1*g1
      - ( i==3 ? (2.*yb*yb*byb) : 0 ) ; 
    dgammaL[i] = 3./2.*b2p *g2*g2*g2*g2 + 3./10.*b1p *g1*g1*g1*g1
      - ( i==3 ? (ytau*ytau*bytau) : 0 ) ; 
    dgammaE[i] = 6./5.*b1p *g1*g1*g1*g1 
      - ( i==3 ? (2.*ytau*ytau*bytau) : 0 ) ; 
  }


  double M1, M2, M3; 
  double M2Q[4], M2U[4], M2D[4], M2L[4], M2E[4], M2Hu, M2Hd;
  double At[4], Atau[4], Ab[4];  
  //  double m32 ; 


  // m32 =  find_out_m32_in_mirage( alpha, M0 ) ; 
  M1 = M0 + m32/ (16.* M_PI * M_PI ) * b1p * g1 * g1; 
  M2 = M0 + m32/ (16.* M_PI * M_PI ) * b2p * g2 * g2; 
  M3 = M0 + m32/ (16.* M_PI * M_PI ) * b3p * g3 * g3; 

  for( int i = 1; i <= 3 ; i++ ) {
    At[i] = -(aHu+aQ+aU) * M0 
      +m32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaU[i]+gammaHu); 
    Ab[i] = -(aHd+aQ+aD) * M0 
      +m32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaD[i]+gammaHd);
    Atau[i] = -(aHd+aL+aE) * M0 
      +m32/(16.*M_PI*M_PI)*(gammaL[i]+gammaE[i]+gammaHd);
        /* TEST IWKIM */
    /* cout << "gammaU[" <<i<<"] = " << gammaU[i] << endl; 
    cout << "gammaD[" <<i<<"] = " << gammaD[i] << endl; 
    cout << "gammaHu" << gammaHu << endl; 
    //    cout << "gammaHd
    cout << "(gammaQ[i]+gammaU[i]+gammaHu) = " << (gammaQ[i]+gammaU[i]+gammaHu)
	 << endl; 
    cout << "(gammaQ[i]+gammaD[i]*gammaHd) = " << (gammaQ[i]+gammaD[i]*gammaHd)
	 << endl; 
    cout << " -5.0 *yt * yt*m32/(16*MPI*MPI )= " <<  -5.0 *yt * yt *m32/(16*M_PI*M_PI )<< endl;   
    cout << " +2./3. * gY*gY *m32/(16*M_PI*M_PI )  =" << 2./3. *gY*gY  *m32/(16*M_PI*M_PI ) << endl; 
    cout << " (aHu+aQ+aU) * M0 = " <<  (aHu+aQ+aU) * M0 << endl ;
    cout << " (aHd+aQ+aD) * M0 = " << (aHd+aQ+aD) * M0  << endl; 
    cout << " (aHd+aL+aE) * M0 = " << (aHd+aL+aE) * M0  << endl;
    cout << - m32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaU[i]+gammaHu) << endl; 
    cout <<       - m32/(16.*M_PI*M_PI)*(gammaL[i]+gammaE[i]+gammaHd) << endl;
    cout << "g1 = " << g1 << endl; 
    cout << "gY = " << gY << endl; 
    cout << "g3 = " << g3 << endl; 
    cout << "yt = " << yt << endl ; 
    cout << "yb = " << yb << endl; 
    cout << "ytau = " <<  ytau << endl; 
    cout << "At[" << i << "]= " << At[i] << endl; 
    cout << "Ab[" << i << "]=" << Ab[i] << endl; 
    cout << "Atau[" << i << "] = " << Atau[i] << endl;  */
    /* TEST IWKIM */
  }

  M2Hu = aHu*M0*M0 - m32/(16.*M_PI*M_PI)*M0*thetaHu 
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHu ; 
  M2Hd = aHd*M0*M0 - m32/(16.*M_PI*M_PI)*M0*thetaHd
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHd ; 
  for( int i = 1 ; i <= 3 ; i++ ) { 
    M2Q[i] = aQ*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaQ[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaQ[i] ;
    M2U[i] = aU*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaU[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaU[i] ;
    M2D[i] = aD*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaD[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaD[i] ;
    M2L[i] = aL*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaL[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaL[i] ;
    M2E[i] = aE*M0*M0  - m32/(16.*M_PI*M_PI)*M0*thetaE[i]
      - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaE[i] ;
  }
  m.setGauginoMass(1, M1 );
  m.setGauginoMass(2, M2 ); 
  m.setGauginoMass(3, M3 ); 
  m.setMh2Squared( M2Hu ); 
  m.setMh1Squared( M2Hd ); 


  for( int i = 1; i <= 3 ; i++ ) {
    m.setSoftMassElement(mQl, i, i, M2Q[i] );
    m.setSoftMassElement(mUr, i, i, M2U[i] );
    m.setSoftMassElement(mDr, i, i, M2D[i] );
    m.setSoftMassElement(mLl, i, i, M2L[i] );
    m.setSoftMassElement(mEr, i, i, M2E[i] );
  }

  for( int i = 1 ; i <= 3 ; i++ ) {
    m.setTrilinearElement(UA, i,i, 
			  m.displayYukawaElement(YU,i,i) * At[i]);
    m.setTrilinearElement(DA, i,i,   
			  m.displayYukawaElement(YD,i,i) * Ab[i]);
    m.setTrilinearElement(EA, i,i,   
			  m.displayYukawaElement(YE,i,i) * Atau[i]);
  }

}



void deflectedmirage2( MssmSoftsusy & m, 
		       const DoubleVector & pars ) { 
  double alpha, beta ; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 

  aHu = 1.0 - nHu ; aHd = 1.0 - nHd ; 
  aQ = 1.0 - nQ ; aU = 1.0 - nU ; aD = 1.0 - nD ; 
  aL = 1.0 - nL ; aE = 1.0 - nE ; 

  alpha = pars.display(1); 
  beta = pars.display(2); 
  M0 = pars.display(3); 

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = m.displayGaugeCoupling(1); 
  g2 = m.displayGaugeCoupling(2); 
  g3 = m.displayGaugeCoupling(3); 
  gY = sqrt(3./5.) * g1 ; 
  yt = m.displayYukawaElement(YU,3,3); 
  yb = m.displayYukawaElement(YD,3,3); 
  ytau = m.displayYukawaElement(YE,3,3); 

  // double m32 ; 

  //  m32 =  find_out_m32_in_mirage( alpha, M0 ) ; 

  double Mgauge ; 

  //  cout << "m32 = " << m32 << endl ;
  // cout << "M0 = " << M0 << endl ; 
  
  Mgauge = beta * m32 ;


  m.setGaugeCoupling( 1, global_g1 ); 
  m.setGaugeCoupling( 2, global_g2 ); 
  m.setGaugeCoupling( 3, global_g3 ); 

  m.setYukawaElement( YU, 3, 3, global_yt ); 
  m.setYukawaElement( YD, 3, 3, global_yb ); 
  m.setYukawaElement( YE, 3, 3, global_ytau ); 

  double alpha1, alpha2 , alpha3 ; 
  alpha1 = sqr(global_g1) / ( 4.0 * PI ) ; 
  alpha2 = sqr(global_g2) / ( 4.0 * PI ) ; 
  alpha3 = sqr(global_g3) / ( 4.0 * PI ) ; 

  
  double m1 , m2 , m3 ;

  m1 = inter_gaugino1 - N * alpha1 / (4.0*PI) * Mgauge + (-N) * alpha1 / (4.0*PI) * m32 ;
  m2 = inter_gaugino2 - N * alpha2 / (4.0*PI) * Mgauge + (-N) * alpha2 / (4.0*PI) * m32 ; 
  m3 = inter_gaugino3 - N * alpha3 / (4.0*PI) * Mgauge + (-N) * alpha3 / (4.0*PI) * m32 ; 

  m.setGauginoMass(1, m1) ;
  m.setGauginoMass(2, m2) ;
  m.setGauginoMass(3, m3) ;

  double ddgammaHu , ddgammaHd , ddgammaQ , ddgammaU, ddgammaD, ddgammaL, ddgammaE ; 

  ddgammaHu = 3./2. * (-N) * g2*g2*g2*g2 + 3./10.* (-N) * g1*g1*g1*g1 ; 
  ddgammaHd = 3./2. * (-N) * g2*g2*g2*g2 + 3./10.* (-N) * g1*g1*g1*g1 ;
  ddgammaQ  = 8./3.* (-N) *g3*g3*g3*g3 + 3./2.* (-N) *g2*g2*g2*g2 
    + 1./30.* (-N) *g1*g1*g1*g1 ; 
  ddgammaU  = 8./3.* (-N) *g3*g3*g3*g3 + 8./15.* (-N) *g1*g1*g1*g1; 
  ddgammaD  = 8./3.* (-N) *g3*g3*g3*g3 + 2./15.* (-N) *g1*g1*g1*g1;
  ddgammaL  = 3./2.* (-N) *g2*g2*g2*g2 + 3./10.* (-N) *g1*g1*g1*g1;
  ddgammaE  = 6./5.* (-N) *g1*g1*g1*g1; 




  double mqlsq , mllsq, mursq, mdrsq, mersq ; 
  double mhusq , mhdsq; 
  //  double M_gauge_sqr_local; 
  //  M_gauge_sqr_local = sqr( M_gauge_local ) ;

  mursq = 2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 4.0/3.0 * sqr(alpha3) + 0.6 * 4.0 / 9.0 * sqr(alpha1) ) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaU ; 

  mdrsq =  2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 )  * 
    ( 4.0/3.0 * sqr(alpha3) + 0.6 * 1.0 / 9.0 * sqr(alpha1) ) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaD ; 

  mersq =  2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 0.6 * sqr(alpha1) ) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaE ; 

  mqlsq =  2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 4.0/3.0 * sqr(alpha3) + 0.75 * sqr(alpha2) + 0.6 /36.0 * sqr(alpha1)) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaQ ; 

  mllsq = 2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 0.75 * sqr(alpha2) + 0.6*0.25 * sqr(alpha1) )
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaL ; 
 
  mhusq = mllsq; 
  mhdsq = mllsq; 

  DoubleMatrix id(3, 3);
  id(1, 1) = 1.0; id(2, 2) = 1.0; id(3, 3) = 1.0;

 
  m.setSoftMassMatrix(mQl, inter_massmQl + mqlsq * id);
  m.setSoftMassMatrix(mUr, inter_massmUr + mursq * id);
  m.setSoftMassMatrix(mDr, inter_massmDr + mdrsq * id);
  m.setSoftMassMatrix(mLl, inter_massmLl + mllsq * id);  
  m.setSoftMassMatrix(mEr, inter_massmEr + mersq * id);
  m.setMh2Squared(inter_massmHu+ mhusq);
  m.setMh1Squared(inter_massmHd+ mhdsq);

  m.setTrilinearElement(UA, 1, 1, m.displayYukawaElement(YU, 1, 1) 
			* inter_A_HuQU(1,1));
  m.setTrilinearElement(UA, 2, 2, m.displayYukawaElement(YU, 2, 2) 
			* inter_A_HuQU(2,2));
  m.setTrilinearElement(UA, 3, 3, m.displayYukawaElement(YU, 3, 3) 
			* inter_A_HuQU(3,3));
  m.setTrilinearElement(DA, 1, 1, m.displayYukawaElement(YD, 1, 1) 
			* inter_A_HdQD(1,1));
  m.setTrilinearElement(DA, 2, 2, m.displayYukawaElement(YD, 2, 2) 
			* inter_A_HdQD(2,2));
  m.setTrilinearElement(DA, 3, 3, m.displayYukawaElement(YD, 3, 3) 
			* inter_A_HdQD(3,3));
  m.setTrilinearElement(EA, 1, 1, m.displayYukawaElement(YE, 1, 1) 
			* inter_A_HdLE(1,1));
  m.setTrilinearElement(EA, 2, 2, m.displayYukawaElement(YE, 2, 2) 
			* inter_A_HdLE(2,2));
  m.setTrilinearElement(EA, 3, 3, m.displayYukawaElement(YE, 3, 3) 
			* inter_A_HdLE(3,3));
  /*
  cout << "In deflectedMirage" << endl; 
  cout << "gaugino(1) = " << inter_gaugino1 << " " << m1 << endl 
       << "gaugino(2) = " << inter_gaugino2 << " " << m2 << endl 
       << "gaugino(3) = " << inter_gaugino3 << " " << m3 << endl; 
  cout << "mqlsq * id (3,3) = " << mqlsq
  << endl; */
  //  m.setSoftMassMatrix(mUr, inter_massmUr + mursq * id);
  //  m.setSoftMassMatrix(mDr, inter_massmDr + mdrsq * id);
  //  m.setSoftMassMatrix(mLl, inter_massmLl + mllsq * id);  
  //  m.setSoftMassMatrix(mEr, inter_massmEr + mersq * id);
  //  m.setMh2Squared(inter_massmHu+ mhusq);
  //  m.setMh1Squared(inter_massmHd+ mhdsq);


}

void finetuneparameter_at_gut( MssmSoftsusy& m,
			       const DoubleVector& pars, 
			       const DoubleVector &deltapars )
{
  double alpha, beta; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 

  double dalpha, dbeta; 
  double dM0; 
  //  double cHu, cHd, cQ, cU, cD, cL, cE ; 

  //  aHu = aHd = 0; 
  //  aQ = aU = aD = aL = aE = 0.5 ; 

  m.runto(mgut0) ; 

  aHu = 1.0 - nHu ; aHd = 1.0 - nHd ; 
  aQ = 1.0 - nQ ; aU = 1.0 - nU ; aD = 1.0 - nD ; 
  aL = 1.0 - nL ; aE = 1.0 - nE ; 

  alpha  = pars.display(1);
  beta   = pars.display(2); 
  M0     = pars.display(3); 

  dalpha = deltapars.display(1); 
  dbeta  = deltapars.display(2); 
  dM0    = deltapars.display(3); 

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = global_g1 ; /* m.displayGaugeCoupling(1); */
  g2 = global_g2 ; /* m.displayGaugeCoupling(2); */
  g3 = global_g3 ; /* m.displayGaugeCoupling(3); */
  gY = sqrt(3./5.) * g1 ; 
  yt = global_yt ; /* m.displayYukawaElement(YU,3,3); */
  yb = global_yb ; /* m.displayYukawaElement(YD,3,3); */
  ytau = global_ytau ; /* m.displayYukawaElement(YE,3,3); */
  
  /////////////////////////// IMPORTANT /////////////////////////////////

  m.setGaugeCoupling( 1, global_g1 ); 
  m.setGaugeCoupling( 2, global_g2 ); 
  m.setGaugeCoupling( 3, global_g3 ); 

  m.setYukawaElement( YU, 3, 3, global_yt ); 
  m.setYukawaElement( YD, 3, 3, global_yb ); 
  m.setYukawaElement( YE, 3, 3, global_ytau ); 

  ///////////////////////////////////////////////////////////////////////

  double b3p, b2p , b1p ; 
  b3p = -3 +N  ; b2p= 1 + N ; b1p = 33./ 5. + N  ;

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
  
  
  dgammaHu = 3./2. * b2p * g2*g2*g2*g2 + 3./10.* b1p * g1*g1*g1*g1 
    - 3. * yt*yt * byt ; 
  dgammaHd = 3./2. * b2p * g2*g2*g2*g2 + 3./10.* b1p * g1*g1*g1*g1 
    - 3. * yb*yb *byb - ytau*ytau*bytau ;
  for( int i = 1 ; i <=3 ; i++ ) {
    dgammaQ[i] = 8./3.*b3p *g3*g3*g3*g3 + 3./2.* b2p *g2*g2*g2*g2 
      + 1./30.*b1p *g1*g1*g1*g1 
      - ( i==3 ? (yt*yt*byt + yb*yb*byb) : 0 ) ; 
    dgammaU[i] = 8./3.*b3p *g3*g3*g3*g3 + 8./15.*b1p *g1*g1*g1*g1
      - ( i==3 ? (2.*yt*yt*byt) : 0 ) ; 
    dgammaD[i] = 8./3.*b3p *g3*g3*g3*g3 + 2./15.*b1p *g1*g1*g1*g1
      - ( i==3 ? (2.*yb*yb*byb) : 0 ) ; 
    dgammaL[i] = 3./2.*b2p *g2*g2*g2*g2 + 3./10.*b1p *g1*g1*g1*g1
      - ( i==3 ? (ytau*ytau*bytau) : 0 ) ; 
    dgammaE[i] = 6./5.*b1p *g1*g1*g1*g1 
      - ( i==3 ? (2.*ytau*ytau*bytau) : 0 ) ; 
  }

  double M1, M2, M3 ;   

  DoubleMatrix massmQl(3,3) ;
  DoubleMatrix massmUr(3,3) ;
  DoubleMatrix massmDr(3,3) ;
  DoubleMatrix massmLl(3,3) ;
  DoubleMatrix massmEr(3,3) ;
  double massmHu ;
  double massmHd ; 
  DoubleMatrix A_HuQU(3,3); 
  DoubleMatrix A_HdQD(3,3);
  DoubleMatrix A_HdLE(3,3); 

  M1 = m.displayGaugino(1); 
  M2 = m.displayGaugino(2); 
  M3 = m.displayGaugino(3); 
  
  massmQl = m.displaySoftMassSquared(mQl) ;
  massmUr = m.displaySoftMassSquared(mUr) ;
  massmDr = m.displaySoftMassSquared(mDr) ;
  massmLl = m.displaySoftMassSquared(mLl) ;
  massmEr = m.displaySoftMassSquared(mEr) ;
  massmHu = m.displayMh2Squared(); 
  massmHd = m.displayMh1Squared(); 
      
  A_HuQU(1,1) = m.displaySoftA( UA, 1, 1); 
  A_HuQU(2,2) = m.displaySoftA( UA, 2, 2); 
  A_HuQU(3,3) = m.displaySoftA( UA, 3, 3); 
  A_HdQD(1,1) = m.displaySoftA( DA, 1, 1); 
  A_HdQD(2,2) = m.displaySoftA( DA, 2, 2); 
  A_HdQD(3,3) = m.displaySoftA( DA, 3, 3); 
  A_HdLE(1,1) = m.displaySoftA( EA, 1, 1); 
  A_HdLE(2,2) = m.displaySoftA( EA, 2, 2); 
  A_HdLE(3,3) = m.displaySoftA( EA, 3, 3); 
  
  

  double dM1, dM2, dM3 ;
  double dM2Q[4], dM2U[4], dM2D[4], dM2L[4], dM2E[4]; 
  double dM2Hu, dM2Hd;
  double dAt[4], dAtau[4], dAb[4];  
  double newm32 ;
  double dm32 ;

  newm32 =  find_out_m32_in_mirage( alpha+dalpha, M0+dM0 ) ;
  dm32 = newm32 - m32; 
  

  dM1 = dM0 + dm32/ (16.* M_PI * M_PI ) * b1p * g1 * g1; 
  dM2 = dM0 + dm32/ (16.* M_PI * M_PI ) * b2p * g2 * g2; 
  dM3 = dM0 + dm32/ (16.* M_PI * M_PI ) * b3p * g3 * g3; 



  dM2Hu = aHu*(2.0*M0*dM0) 
    - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaHu 
    - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHu ; 
  dM2Hd = aHd*(2.0*M0*dM0)
    - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaHd
    - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaHd ; 
  
  for( int i = 1 ; i <= 3 ; i++ ) { 
    dM2Q[i] = aQ*(2.0*M0*dM0)
      - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaQ[i]
      - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaQ[i] ;
    dM2U[i] = aU*(2.0*M0*dM0)
      - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaU[i]
      - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaU[i] ;
    dM2D[i] = aD*(2.0*M0*dM0)
      - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaD[i]
      - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaD[i] ;
    dM2L[i] = aL*(2.0*M0*dM0)
      - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaL[i]
      - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaL[i] ;
    dM2E[i] = aE*(2.0*M0*dM0)
      - 1.0/(16.*M_PI*M_PI)*(dm32*M0 + m32*dM0)*thetaE[i]
      - (2.0*m32*dm32)/(256.*M_PI*M_PI*M_PI*M_PI)*dgammaE[i] ;

    
    dAt[i] = -(aHu+aQ+aU)*dM0 
      + dm32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaU[i]+gammaHu); 
    dAb[i] = -(aHd+aQ+aD)*dM0 
      + dm32/(16.*M_PI*M_PI)*(gammaQ[i]+gammaD[i]+gammaHd); 
    dAtau[i] = -(aHd+aL+aE)*dM0 
      + dm32/(16.*M_PI*M_PI)*(gammaL[i]+gammaE[i]+gammaHd);

  }

  cout << "INSIDE FINETUNING AT GUT " << endl;
  cout << "m32 = " << m32 << endl ; 
  cout << "dM1 = " << dM1 << endl ;
  cout << "dM2 = " << dM2 << endl ;
  cout << "dM3 = " << dM3 << endl ; 
  cout << "dM0 = " << dM0 << endl ; 
  cout << "M0  = " << M0 << endl; 
  cout << "dm32 = " << dm32 << endl ;
  cout << "thetaHu = " << thetaHu << endl ;
  cout << "dgammaHu = " << dgammaHu << endl ;
  cout << "dM2Hu = " << dM2Hu << endl ; 
  cout << "dM2Hd = " << dM2Hd << endl ; 

  cout << "dM2Q[3] = " << dM2Q[3] << endl; 
  cout << "---------------" << endl; 



  M1 += dM1 ; 
  M2 += dM2 ; 
  M3 += dM3 ; 
  
  for( int i = 1 ; i <= 3; i++ ) {
    massmQl(i,i) += dM2Q[i] ;
    massmUr(i,i) += dM2U[i] ;
    massmDr(i,i) += dM2D[i] ;
    massmLl(i,i) += dM2L[i] ;
    massmEr(i,i) += dM2E[i] ;
    
    A_HuQU(i,i) += dAt[i]  ; 
    A_HdQD(i,i) += dAb[i]  ; 
    A_HdLE(i,i) += dAtau[i] ; 

  }
  massmHu += dM2Hu ;
  massmHd += dM2Hd ;  

  m.setGauginoMass(1, M1 );
  m.setGauginoMass(2, M2 ); 
  m.setGauginoMass(3, M3 ); 
  m.setMh2Squared( massmHu ); 
  m.setMh1Squared( massmHd ); 

  m.setSoftMassMatrix(mQl, massmQl );
  m.setSoftMassMatrix(mUr, massmUr );
  m.setSoftMassMatrix(mDr, massmDr );
  m.setSoftMassMatrix(mLl, massmLl );
  m.setSoftMassMatrix(mEr, massmEr );

  for( int i = 1 ; i <= 3 ; i++ ) {
    m.setTrilinearElement(UA, i, i,   
			  m.displayYukawaElement(YU, i,i) * A_HuQU(i,i) );
    m.setTrilinearElement(DA, i,i ,   
			  m.displayYukawaElement(YD, i,i) * A_HdQD(i,i) );
    m.setTrilinearElement(EA, i, i,    
			  m.displayYukawaElement(YE, i,i) * A_HdLE(i,i) );
  }
}

void finetune_messscale( MssmSoftsusy& mupper,
			 MssmSoftsusy& muppernew, 
			 MssmSoftsusy& mlower, 
			 double M_mess , 
			 double dM_mess,
			 double &dM1, 
			 double &dM2, 
			 double &dM3, 
			 DoubleMatrix& dmassmQl,
			 DoubleMatrix& dmassmUr,
			 DoubleMatrix& dmassmDr,
			 DoubleMatrix& dmassmLl,
			 DoubleMatrix& dmassmEr,
			 double& dmassmHu,
			 double& dmassmHd, 
			 DoubleMatrix& dA_HuQU, 
			 DoubleMatrix& dA_HdQD,
			 DoubleMatrix& dA_HdLE ) 
{
  double upper0M1;
  double upper0M2; 
  double upper0M3; 
  DoubleMatrix upper0massmQl(3,3);
  DoubleMatrix upper0massmUr(3,3);
  DoubleMatrix upper0massmDr(3,3);
  DoubleMatrix upper0massmLl(3,3);
  DoubleMatrix upper0massmEr(3,3);
  double upper0massmHu;
  double upper0massmHd; 
  DoubleMatrix upper0A_HuQU(3,3);
  DoubleMatrix upper0A_HdQD(3,3);
  DoubleMatrix upper0A_HdLE(3,3);  

  double upper1M1;
  double upper1M2; 
  double upper1M3; 
  DoubleMatrix upper1massmQl(3,3);
  DoubleMatrix upper1massmUr(3,3);
  DoubleMatrix upper1massmDr(3,3);
  DoubleMatrix upper1massmLl(3,3);
  DoubleMatrix upper1massmEr(3,3);
  double upper1massmHu;
  double upper1massmHd; 
  DoubleMatrix upper1A_HuQU(3,3);
  DoubleMatrix upper1A_HdQD(3,3);
  DoubleMatrix upper1A_HdLE(3,3);  

  double uppernewM1;
  double uppernewM2; 
  double uppernewM3; 
  DoubleMatrix uppernewmassmQl(3,3);
  DoubleMatrix uppernewmassmUr(3,3);
  DoubleMatrix uppernewmassmDr(3,3);
  DoubleMatrix uppernewmassmLl(3,3);
  DoubleMatrix uppernewmassmEr(3,3);
  double uppernewmassmHu;
  double uppernewmassmHd; 
  DoubleMatrix uppernewA_HuQU(3,3);
  DoubleMatrix uppernewA_HdQD(3,3);
  DoubleMatrix uppernewA_HdLE(3,3);  

  double lower0M1;
  double lower0M2; 
  double lower0M3; 
  DoubleMatrix lower0massmQl(3,3);
  DoubleMatrix lower0massmUr(3,3);
  DoubleMatrix lower0massmDr(3,3);
  DoubleMatrix lower0massmLl(3,3);
  DoubleMatrix lower0massmEr(3,3);
  double lower0massmHu;
  double lower0massmHd; 
  DoubleMatrix lower0A_HuQU(3,3);
  DoubleMatrix lower0A_HdQD(3,3);
  DoubleMatrix lower0A_HdLE(3,3);  

  double lower1M1;
  double lower1M2; 
  double lower1M3; 
  DoubleMatrix lower1massmQl(3,3);
  DoubleMatrix lower1massmUr(3,3);
  DoubleMatrix lower1massmDr(3,3);
  DoubleMatrix lower1massmLl(3,3);
  DoubleMatrix lower1massmEr(3,3);
  double lower1massmHu;
  double lower1massmHd; 
  DoubleMatrix lower1A_HuQU(3,3);
  DoubleMatrix lower1A_HdQD(3,3);
  DoubleMatrix lower1A_HdLE(3,3);  

  mupper.N = N ;  
  mupper.Nflag = true; 
  mupper.beta2();  
  mupper.Nflag = false ;
  
  muppernew.N = N ;  
  muppernew.Nflag = true; 
  muppernew.beta2(); 
  muppernew.Nflag = false ;

  mupper.runto( M_mess ) ; 
  muppernew.runto( M_mess ); 

  mlower.N = 0 ;  
  mlower.Nflag = true; 
  mlower.beta2();  
  mlower.Nflag = false ; 

  mlower.runto( M_mess ) ; 

  lower0M1 = mlower.displayGaugino(1); 
  lower0M2 = mlower.displayGaugino(2); 
  lower0M3 = mlower.displayGaugino(3); 
  
  lower0massmQl = mlower.displaySoftMassSquared(mQl) ;
  lower0massmUr = mlower.displaySoftMassSquared(mUr) ;
  lower0massmDr = mlower.displaySoftMassSquared(mDr) ;
  lower0massmLl = mlower.displaySoftMassSquared(mLl) ;
  lower0massmEr = mlower.displaySoftMassSquared(mEr) ;
  lower0massmHu = mlower.displayMh2Squared(); 
  lower0massmHd = mlower.displayMh1Squared(); 
      
  lower0A_HuQU(1,1) = mlower.displaySoftA( UA, 1, 1); 
  lower0A_HuQU(2,2) = mlower.displaySoftA( UA, 2, 2); 
  lower0A_HuQU(3,3) = mlower.displaySoftA( UA, 3, 3); 
  lower0A_HdQD(1,1) = mlower.displaySoftA( DA, 1, 1); 
  lower0A_HdQD(2,2) = mlower.displaySoftA( DA, 2, 2); 
  lower0A_HdQD(3,3) = mlower.displaySoftA( DA, 3, 3); 
  lower0A_HdLE(1,1) = mlower.displaySoftA( EA, 1, 1); 
  lower0A_HdLE(2,2) = mlower.displaySoftA( EA, 2, 2); 
  lower0A_HdLE(3,3) = mlower.displaySoftA( EA, 3, 3); 

  upper0M1 = mupper.displayGaugino(1); 
  upper0M2 = mupper.displayGaugino(2); 
  upper0M3 = mupper.displayGaugino(3); 
  
  upper0massmQl = mupper.displaySoftMassSquared(mQl) ;
  upper0massmUr = mupper.displaySoftMassSquared(mUr) ;
  upper0massmDr = mupper.displaySoftMassSquared(mDr) ;
  upper0massmLl = mupper.displaySoftMassSquared(mLl) ;
  upper0massmEr = mupper.displaySoftMassSquared(mEr) ;
  upper0massmHu = mupper.displayMh2Squared(); 
  upper0massmHd = mupper.displayMh1Squared(); 
      
  upper0A_HuQU(1,1) = mupper.displaySoftA( UA, 1, 1); 
  upper0A_HuQU(2,2) = mupper.displaySoftA( UA, 2, 2); 
  upper0A_HuQU(3,3) = mupper.displaySoftA( UA, 3, 3); 
  upper0A_HdQD(1,1) = mupper.displaySoftA( DA, 1, 1); 
  upper0A_HdQD(2,2) = mupper.displaySoftA( DA, 2, 2); 
  upper0A_HdQD(3,3) = mupper.displaySoftA( DA, 3, 3); 
  upper0A_HdLE(1,1) = mupper.displaySoftA( EA, 1, 1); 
  upper0A_HdLE(2,2) = mupper.displaySoftA( EA, 2, 2); 
  upper0A_HdLE(3,3) = mupper.displaySoftA( EA, 3, 3); 

  uppernewM1 = muppernew.displayGaugino(1); 
  uppernewM2 = muppernew.displayGaugino(2); 
  uppernewM3 = muppernew.displayGaugino(3); 
  
  uppernewmassmQl = muppernew.displaySoftMassSquared(mQl) ;
  uppernewmassmUr = muppernew.displaySoftMassSquared(mUr) ;
  uppernewmassmDr = muppernew.displaySoftMassSquared(mDr) ;
  uppernewmassmLl = muppernew.displaySoftMassSquared(mLl) ;
  uppernewmassmEr = muppernew.displaySoftMassSquared(mEr) ;
  uppernewmassmHu = muppernew.displayMh2Squared(); 
  uppernewmassmHd = muppernew.displayMh1Squared(); 
      
  uppernewA_HuQU(1,1) = muppernew.displaySoftA( UA, 1, 1); 
  uppernewA_HuQU(2,2) = muppernew.displaySoftA( UA, 2, 2); 
  uppernewA_HuQU(3,3) = muppernew.displaySoftA( UA, 3, 3); 
  uppernewA_HdQD(1,1) = muppernew.displaySoftA( DA, 1, 1); 
  uppernewA_HdQD(2,2) = muppernew.displaySoftA( DA, 2, 2); 
  uppernewA_HdQD(3,3) = muppernew.displaySoftA( DA, 3, 3); 
  uppernewA_HdLE(1,1) = muppernew.displaySoftA( EA, 1, 1); 
  uppernewA_HdLE(2,2) = muppernew.displaySoftA( EA, 2, 2); 
  uppernewA_HdLE(3,3) = muppernew.displaySoftA( EA, 3, 3); 

  mupper.N = N ;  
  mupper.Nflag = true; 
  mupper.beta2();  
  mupper.Nflag = false ;
  
  mupper.runto( M_mess + dM_mess ) ; 
  
  mlower.N = 0 ;  
  mlower.Nflag = true; 
  mlower.beta2();  
  mlower.Nflag = false ;   

  mlower.runto( M_mess + dM_mess ) ; 

  lower1M1 = mlower.displayGaugino(1); 
  lower1M2 = mlower.displayGaugino(2); 
  lower1M3 = mlower.displayGaugino(3); 
  
  lower1massmQl = mlower.displaySoftMassSquared(mQl) ;
  lower1massmUr = mlower.displaySoftMassSquared(mUr) ;
  lower1massmDr = mlower.displaySoftMassSquared(mDr) ;
  lower1massmLl = mlower.displaySoftMassSquared(mLl) ;
  lower1massmEr = mlower.displaySoftMassSquared(mEr) ;
  lower1massmHu = mlower.displayMh2Squared(); 
  lower1massmHd = mlower.displayMh1Squared(); 
      
  lower1A_HuQU(1,1) = mlower.displaySoftA( UA, 1, 1); 
  lower1A_HuQU(2,2) = mlower.displaySoftA( UA, 2, 2); 
  lower1A_HuQU(3,3) = mlower.displaySoftA( UA, 3, 3); 
  lower1A_HdQD(1,1) = mlower.displaySoftA( DA, 1, 1); 
  lower1A_HdQD(2,2) = mlower.displaySoftA( DA, 2, 2); 
  lower1A_HdQD(3,3) = mlower.displaySoftA( DA, 3, 3); 
  lower1A_HdLE(1,1) = mlower.displaySoftA( EA, 1, 1); 
  lower1A_HdLE(2,2) = mlower.displaySoftA( EA, 2, 2); 
  lower1A_HdLE(3,3) = mlower.displaySoftA( EA, 3, 3); 

  upper1M1 = mupper.displayGaugino(1); 
  upper1M2 = mupper.displayGaugino(2); 
  upper1M3 = mupper.displayGaugino(3); 
  
  upper1massmQl = mupper.displaySoftMassSquared(mQl) ;
  upper1massmUr = mupper.displaySoftMassSquared(mUr) ;
  upper1massmDr = mupper.displaySoftMassSquared(mDr) ;
  upper1massmLl = mupper.displaySoftMassSquared(mLl) ;
  upper1massmEr = mupper.displaySoftMassSquared(mEr) ;
  upper1massmHu = mupper.displayMh2Squared(); 
  upper1massmHd = mupper.displayMh1Squared(); 
      
  upper1A_HuQU(1,1) = mupper.displaySoftA( UA, 1, 1); 
  upper1A_HuQU(2,2) = mupper.displaySoftA( UA, 2, 2); 
  upper1A_HuQU(3,3) = mupper.displaySoftA( UA, 3, 3); 
  upper1A_HdQD(1,1) = mupper.displaySoftA( DA, 1, 1); 
  upper1A_HdQD(2,2) = mupper.displaySoftA( DA, 2, 2); 
  upper1A_HdQD(3,3) = mupper.displaySoftA( DA, 3, 3); 
  upper1A_HdLE(1,1) = mupper.displaySoftA( EA, 1, 1); 
  upper1A_HdLE(2,2) = mupper.displaySoftA( EA, 2, 2); 
  upper1A_HdLE(3,3) = mupper.displaySoftA( EA, 3, 3); 


  
  dM1 = (upper1M1 - upper0M1) - (lower1M1 - lower0M1 ) 
       + (uppernewM1 - upper0M1 ) ; 
  dM2 = (upper1M2 - upper0M2) - (lower1M2 - lower0M2 ) 
     + (uppernewM2 - upper0M2 ) ;
  dM3 = (upper1M3 - upper0M3) - (lower1M3 - lower0M3 )
     + (uppernewM3 - upper0M3 ) ;

  
  dmassmQl = (upper1massmQl - upper0massmQl) 
    - (lower1massmQl - lower0massmQl ) + ( uppernewmassmQl - upper0massmQl) ;  
  dmassmUr = (upper1massmUr - upper0massmUr) 
    - (lower1massmUr - lower0massmUr ) + ( uppernewmassmUr - upper0massmUr) ;
  dmassmDr = (upper1massmDr - upper0massmDr) 
    - (lower1massmDr - lower0massmDr ) + ( uppernewmassmDr - upper0massmDr) ;
  dmassmLl = (upper1massmLl - upper0massmLl)
    - (lower1massmLl - lower0massmLl ) + ( uppernewmassmLl - upper0massmLl) ; 
  dmassmEr = (upper1massmEr - upper0massmEr) 
    - (lower1massmEr - lower0massmEr ) + ( uppernewmassmEr - upper0massmEr); 
  dmassmHu = (upper1massmHu - upper0massmHu) 
    - (lower1massmHu - lower0massmHu ) + ( uppernewmassmHu - upper0massmHu); 
  dmassmHd = (upper1massmHd - upper0massmHd) 
    - (lower1massmHd - lower0massmHd ) + ( uppernewmassmHd - upper0massmHd);  

    
  for( int i = 1 ; i <= 3 ; i++ ) {
    dA_HuQU(i,i) = (upper1A_HuQU(i,i) - upper0A_HuQU(i,i) ) 
      - ( lower1A_HuQU(i,i) - lower0A_HuQU(i,i) ) 
      + ( uppernewA_HuQU(i,i) - upper0A_HuQU(i,i) );  
    dA_HdQD(i,i) = (upper1A_HdQD(i,i) - upper0A_HdQD(i,i) ) 
      - ( lower1A_HdQD(i,i) - lower0A_HdQD(i,i) ) 
      + ( uppernewA_HdQD(i,i) - upper0A_HdQD(i,i) );  
    dA_HdLE(i,i) = (upper1A_HdLE(i,i) - upper0A_HdLE(i,i) ) 
      - ( lower1A_HdLE(i,i) - lower0A_HdLE(i,i) ) 
      - ( uppernewA_HdLE(i,i) - upper0A_HdLE(i,i) );    
  } 

    
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
       << "***********************************" << endl ; 
  cout << " dM1 = " << dM1 << endl
       << " dM2 = " << dM2 << endl 
       << " dM3 = " << dM3 << endl ; 
  cout << " dmassmQl" << dmassmQl << endl 
       << " dmassmUr" << dmassmUr << endl 
       << " dmassmDr" << dmassmDr << endl  
       << " dmassmLl" << dmassmLl << endl 
       << " dmassmEr" << dmassmEr << endl  
       << " dmassmHu" << dmassmHu << endl 
       << "( uppernewmassmHu - upper0massmHu)" << ( uppernewmassmHu - upper0massmHu) << endl
       << " dmassmHd" << dmassmHd << endl ; 
  cout << " dA_HuQU" << dA_HuQU << endl 
       << " dA_HdQD" << dA_HdQD << endl 
       << " dA_HdLE" << dA_HdLE << endl ;


  cout << "*********************************" << endl
  << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;  
  
  mupper.N = N ;  
  mupper.Nflag = true; 
  mupper.beta2();  
  mupper.Nflag = false ;

  mupper.runto(M_mess); 

  mlower.N = 0 ;  
  mlower.Nflag = true; 
  mlower.beta2();  
  mlower.Nflag = false ;   

  mlower.runto(M_mess); 

}


void finetuneparameter_at_mess( MssmSoftsusy& mupper,
				MssmSoftsusy& muppernew, 
				MssmSoftsusy& mlower,
			       const DoubleVector& pars, 
			       const DoubleVector &deltapars )
{
  double alpha, beta; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 
  double M_mess ; 
  double Mgauge; 

  double dalpha, dbeta; 
  double dM0; 
  double dM_mess; 
  double dMgauge; 



   //  double cHu, cHd, cQ, cU, cD, cL, cE ; 

  //  aHu = aHd = 0; 
  //  aQ = aU = aD = aL = aE = 0.5 ; 

  aHu = 1.0 - nHu ; aHd = 1.0 - nHd ; 
  aQ = 1.0 - nQ ; aU = 1.0 - nU ; aD = 1.0 - nD ; 
  aL = 1.0 - nL ; aE = 1.0 - nE ; 

  alpha  = pars.display(1);
  beta   = pars.display(2); 
  M0     = pars.display(3); 
  M_mess = pars.display(4);
  Mgauge = beta * m32 ; 

  dalpha = deltapars.display(1); 
  dbeta  = deltapars.display(2); 
  dM0    = deltapars.display(3); 
  dM_mess= deltapars.display(4); 

  double newm32 ;
  double dm32 ;
  newm32 =  find_out_m32_in_mirage( alpha+dalpha, M0+dM0 ) ;
  dm32 = newm32 - m32; 

  dMgauge = dbeta * m32 + beta* dm32 ; 

  /*  cout << "dbeta" << dbeta << endl  
       << " dMgauge = " << dMgauge << endl
       << " dm32 = " << dm32 << endl;  */

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  mlower.runto(M_mess); 
  mupper.runto(M_mess); 
  muppernew.runto(M_mess); 

  cout << "mupper.displayMh2Squared()= " << mupper.displayMh2Squared() << endl;
  cout << "mlower.displayMh2Squared()= " << mlower.displayMh2Squared() << endl;
  cout << "muppernew.displayMh2Squared()= " << muppernew.displayMh2Squared() << endl;
 
  g1 = mlower.displayGaugeCoupling(1); 
  g2 = mlower.displayGaugeCoupling(2); 
  g3 = mlower.displayGaugeCoupling(3); 
  gY = sqrt(3./5.) * g1 ; 
  yt = mlower.displayYukawaElement(YU,3,3); 
  yb = mlower.displayYukawaElement(YD,3,3); 
  ytau = mlower.displayYukawaElement(YE,3,3); 

  double alpha1, alpha2 , alpha3 ; 
  alpha1 = sqr(g1) / ( 4.0 * PI ) ; 
  alpha2 = sqr(g2) / ( 4.0 * PI ) ; 
  alpha3 = sqr(g3) / ( 4.0 * PI ) ; 
  
  /////////////////////////// IMPORTANT /////////////////////////////////
  //
  //  m.setGaugeCoupling( 1, global_g1 ); 
  //  m.setGaugeCoupling( 2, global_g2 ); 
  //  m.setGaugeCoupling( 3, global_g3 ); 
  //
  ///////////////////////////////////////////////////////////////////////

  double dM1mess;  
  double dM2mess ;
  double dM3mess ;  
  DoubleMatrix dmassmQlmess(3,3);
  DoubleMatrix dmassmUrmess(3,3);
  DoubleMatrix dmassmDrmess(3,3);
  DoubleMatrix dmassmLlmess(3,3);
  DoubleMatrix dmassmErmess(3,3);
  double dmassmHumess;
  double dmassmHdmess; 
  DoubleMatrix dA_HuQUmess(3,3); 
  DoubleMatrix dA_HdQDmess(3,3);
  DoubleMatrix dA_HdLEmess(3,3);
    
  finetune_messscale( mupper, muppernew, mlower,
		      M_mess, 
		      dM_mess,
		      dM1mess,  
		      dM2mess,
		      dM3mess, 
		      dmassmQlmess,
		      dmassmUrmess,
		      dmassmDrmess,
		      dmassmLlmess,
		      dmassmErmess,
		      dmassmHumess,
		      dmassmHdmess,
		      dA_HuQUmess,
		      dA_HdQDmess,
		      dA_HdLEmess ); 

  cout << "After finetune_messscale" << endl; 
  cout << "mupper.displayMh2Squared()= " << mupper.displayMh2Squared() << endl;
  cout << "mlower.displayMh2Squared()= " << mlower.displayMh2Squared() << endl;
  cout << "muppernew.displayMh2Squared()= " << muppernew.displayMh2Squared() << endl;


  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
       << "***********************************" << endl ; 
  cout << " dM1mess = " << dM1mess << endl
       << " dM2mess = " << dM2mess << endl 
       << " dM3mess = " << dM3mess << endl ; 
  cout << "*********************************" << endl
  << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;  





  ////////////////////////////////////////////////////////////////////



  double b3, b2, b1 ; 
  b3 = -3   ; b2= 1  ; b1 = 33./ 5. ;

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
  
  
  dgammaHu = 3./2. * b2 * g2*g2*g2*g2 + 3./10.* b1 * g1*g1*g1*g1 
    - 3. * yt*yt * byt ; 
  dgammaHd = 3./2. * b2 * g2*g2*g2*g2 + 3./10.* b1 * g1*g1*g1*g1 
    - 3. * yb*yb *byb - ytau*ytau*bytau ;
  for( int i = 1 ; i <=3 ; i++ ) {
    dgammaQ[i] = 8./3.*b3 *g3*g3*g3*g3 + 3./2.* b2 *g2*g2*g2*g2 
      + 1./30.*b1 *g1*g1*g1*g1 
      - ( i==3 ? (yt*yt*byt + yb*yb*byb) : 0 ) ; 
    dgammaU[i] = 8./3.*b3 *g3*g3*g3*g3 + 8./15.*b1 *g1*g1*g1*g1
      - ( i==3 ? (2.*yt*yt*byt) : 0 ) ; 
    dgammaD[i] = 8./3.*b3 *g3*g3*g3*g3 + 2./15.*b1 *g1*g1*g1*g1
      - ( i==3 ? (2.*yb*yb*byb) : 0 ) ; 
    dgammaL[i] = 3./2.*b2 *g2*g2*g2*g2 + 3./10.*b1 *g1*g1*g1*g1
      - ( i==3 ? (ytau*ytau*bytau) : 0 ) ; 
    dgammaE[i] = 6./5.*b1 *g1*g1*g1*g1 
      - ( i==3 ? (2.*ytau*ytau*bytau) : 0 ) ; 
  }

  double ddgammaHu , ddgammaHd , ddgammaQ , ddgammaU, ddgammaD, ddgammaL, ddgammaE ; 
  
  ddgammaHu = 3./2. * (-N) * g2*g2*g2*g2 + 3./10.* (-N) * g1*g1*g1*g1 ; 
  ddgammaHd = 3./2. * (-N) * g2*g2*g2*g2 + 3./10.* (-N) * g1*g1*g1*g1 ;
  ddgammaQ  = 8./3.* (-N) *g3*g3*g3*g3 + 3./2.* (-N) *g2*g2*g2*g2 
    + 1./30.* (-N) *g1*g1*g1*g1 ; 
  ddgammaU  = 8./3.* (-N) *g3*g3*g3*g3 + 8./15.* (-N) *g1*g1*g1*g1; 
  ddgammaD  = 8./3.* (-N) *g3*g3*g3*g3 + 2./15.* (-N) *g1*g1*g1*g1;
  ddgammaL  = 3./2.* (-N) *g2*g2*g2*g2 + 3./10.* (-N) *g1*g1*g1*g1;
  ddgammaE  = 6./5.* (-N) *g1*g1*g1*g1; 
  


  double M1, M2, M3, M2Q3, M2U3, M2D3, M2L3, M2E3, M2Hu, M2Hd;
  double At, Atau, Ab;  

  DoubleMatrix massmQl(3,3) ;
  DoubleMatrix massmUr(3,3) ;
  DoubleMatrix massmDr(3,3) ;
  DoubleMatrix massmLl(3,3) ;
  DoubleMatrix massmEr(3,3) ;
  double massmHu ;
  double massmHd ; 
  DoubleMatrix A_HuQU(3,3); 
  DoubleMatrix A_HdQD(3,3);
  DoubleMatrix A_HdLE(3,3); 

  M1 = mlower.displayGaugino(1); 
  M2 = mlower.displayGaugino(2); 
  M3 = mlower.displayGaugino(3); 
  
  massmQl = mlower.displaySoftMassSquared(mQl) ;
  massmUr = mlower.displaySoftMassSquared(mUr) ;
  massmDr = mlower.displaySoftMassSquared(mDr) ;
  massmLl = mlower.displaySoftMassSquared(mLl) ;
  massmEr = mlower.displaySoftMassSquared(mEr) ;
  massmHu = mlower.displayMh2Squared(); 
  massmHd = mlower.displayMh1Squared(); 
      
  A_HuQU(1,1) = mlower.displaySoftA( UA, 1, 1); 
  A_HuQU(2,2) = mlower.displaySoftA( UA, 2, 2); 
  A_HuQU(3,3) = mlower.displaySoftA( UA, 3, 3); 
  A_HdQD(1,1) = mlower.displaySoftA( DA, 1, 1); 
  A_HdQD(2,2) = mlower.displaySoftA( DA, 2, 2); 
  A_HdQD(3,3) = mlower.displaySoftA( DA, 3, 3); 
  A_HdLE(1,1) = mlower.displaySoftA( EA, 1, 1); 
  A_HdLE(2,2) = mlower.displaySoftA( EA, 2, 2); 
  A_HdLE(3,3) = mlower.displaySoftA( EA, 3, 3); 
  
  

  double dM1, dM2, dM3 ;
  double dM2Q[4], dM2U[4], dM2D[4], dM2L[4], dM2E[4]; 
  double dM2Hu, dM2Hd;
  double dAt[4], dAtau[4], dAb[4];  

  dM1 = -N * g1* g1 / (16. * M_PI * M_PI ) * ( dMgauge + dm32 ) ;
  dM2 = -N * g2* g2 / (16. * M_PI * M_PI ) * ( dMgauge + dm32 ) ;  
  dM3 = -N * g3* g3 / (16. * M_PI * M_PI ) * ( dMgauge + dm32 ) ; 

  for( int i = 1 ; i <= 3 ; i++ ) {
    dM2U[i] = 2.0/sqr( 4.0 * PI )*N 
      * (2.0* Mgauge*dMgauge + 2.0 * (dMgauge * m32 + Mgauge*dm32) ) 
      * ( 4.0/3.0 * sqr(alpha3) + 0.6 * 4.0 / 9.0 * sqr(alpha1) ) 
      - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaU ; 
    
    dM2D[i] =  2.0/sqr( 4.0 * PI )*N 
      * (2.0* Mgauge*dMgauge + 2.0 * (dMgauge * m32 + Mgauge*dm32) )  
      * ( 4.0/3.0 * sqr(alpha3) + 0.6 * 1.0 / 9.0 * sqr(alpha1) ) 
      - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaD ; 
    
    dM2E[i] =  2.0/sqr( 4.0 * PI )*N 
      * (2.0* Mgauge*dMgauge + 2.0 * (dMgauge * m32 + Mgauge*dm32) ) 
      * ( 0.6 * sqr(alpha1) ) 
      - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaE ; 
    
    dM2Q[i] =  2.0/sqr( 4.0 * PI )*N 
      * (2.0* Mgauge*dMgauge + 2.0 * (dMgauge * m32 + Mgauge*dm32) ) 
      * ( 4.0/3.0 * sqr(alpha3) + 0.75 * sqr(alpha2)+ 0.6 /36.0 * sqr(alpha1)) 
      - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaQ ; 
    
    dM2L[i] = 2.0/sqr( 4.0 * PI )*N 
      * (2.0*Mgauge*dMgauge +  2.0 * (dMgauge * m32 + Mgauge*dm32) ) 
      * ( 0.75 * sqr(alpha2) + 0.6*0.25 * sqr(alpha1) )
      - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaL ; 
  }

  dM2Hu = 2.0/sqr( 4.0 * PI )*N 
    * (2.0*Mgauge*dMgauge +  2.0 * (dMgauge * m32 + Mgauge*dm32) ) 
    * ( 0.75 * sqr(alpha2) + 0.6*0.25 * sqr(alpha1) )
    - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaL ;

  dM2Hd = 2.0/sqr( 4.0 * PI )*N 
      * (2.0*Mgauge*dMgauge +  2.0 * (dMgauge * m32 + Mgauge*dm32) ) 
      * ( 0.75 * sqr(alpha2) + 0.6*0.25 * sqr(alpha1) )
    - 2.0*m32*dm32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaL ;


  /********************************************/
  /*
  cout << "========================================" << endl ;
  cout << " dM1 = " << dM1 << endl
       << " dM2 = " << dM2 << endl
       << " dM3 = " << dM3 << endl;
    

  cout << "========================================" << endl; 
  */



  /*******************************************/




  M1 += dM1 + dM1mess ; 
  M2 += dM2 + dM2mess ; 
  M3 += dM3 + dM3mess ; 
  
  for( int i = 1 ; i <= 3; i++ ) {
    massmQl(i,i) += dM2Q[i] + dmassmQlmess(i,i) ;
    massmUr(i,i) += dM2U[i] + dmassmUrmess(i,i) ;
    massmDr(i,i) += dM2D[i] + dmassmDrmess(i,i) ;
    massmLl(i,i) += dM2L[i] + dmassmLlmess(i,i) ;
    massmEr(i,i) += dM2E[i] + dmassmErmess(i,i) ;
    A_HuQU(i,i) += dA_HuQUmess(i,i); 
    A_HdQD(i,i) += dA_HdQDmess(i,i); 
    A_HdLE(i,i) += dA_HdLEmess(i,i); 
  }

  massmHu += dM2Hu + dmassmHumess;
  massmHd += dM2Hd + dmassmHdmess;  


  cout << "dM2Hu = " << dM2Hu << endl; 
  cout << "dM2Hd = " << dM2Hd << endl; 
  cout << "dmassmHumess = " << dmassmHumess << endl; 
  cout << "dmassmHdmess = " << dmassmHdmess << endl; 
  cout << "massmHu = " << massmHu << endl; 
  cout << "massmHd = " << massmHd << endl; 

  mlower.setGauginoMass(1, M1 );
  mlower.setGauginoMass(2, M2 ); 
  mlower.setGauginoMass(3, M3 ); 
  mlower.setMh2Squared( massmHu ); 
  mlower.setMh1Squared( massmHd ); 

  mlower.setSoftMassMatrix(mQl, massmQl );
  mlower.setSoftMassMatrix(mUr, massmUr );
  mlower.setSoftMassMatrix(mDr, massmDr );
  mlower.setSoftMassMatrix(mLl, massmLl );
  mlower.setSoftMassMatrix(mEr, massmEr );

  for( int i = 1 ; i <= 3 ; i++ ) {
    mlower.setTrilinearElement(UA, i, i,   
			       mlower.displayYukawaElement(YU, i,i) * A_HuQU(i,i) );
    mlower.setTrilinearElement(DA, i,i ,   
			  mlower.displayYukawaElement(YD, i,i) * A_HdQD(i,i) );
    mlower.setTrilinearElement(EA, i, i,    
			  mlower.displayYukawaElement(YE, i,i) * A_HdLE(i,i) );
  }
}





bool checktheresult( MssmSoftsusy& m ) 
{
  sPhysical p = m.displayPhys(); 
  
  if( p.mhiggs(1) != p.mhiggs(1) ) return false; 
  if( p.mhiggs(2) != p.mhiggs(2) ) return false; 
  if( p.mhiggs(3) != p.mhiggs(3) ) return false; 
  if( p.mhiggs(4) != p.mhiggs(4) ) return false; 
  if( p.msnu(1)   != p.msnu(1)   ) return false;
  if( p.msnu(2)   != p.msnu(2)   ) return false;
  if( p.msnu(3)   != p.msnu(3)   ) return false;
  if( p.mch(1)    != p.mch(1)    ) return false;
  if( p.mch(2)    != p.mch(2)    ) return false;
  if( p.mneut(1)  != p.mneut(1)  ) return false;
  if( p.mneut(2)  != p.mneut(2)  ) return false;
  if( p.mneut(3)  != p.mneut(3)  ) return false;
  if( p.mneut(4)  != p.mneut(4)  ) return false;
  if( p.mGluino   != p.mGluino   ) return false; 

  return true; 
}

void recordphysics( ofstream& outputfile, MssmSoftsusy& m, 
		    double alpha, double beta, double M_moduli, double M_mess,
		    double m32 , double tanb, 
		    double btosgamma, double muong2, double bsmumu, double oh2,
		    string LSP , 
		    double Delta1, double Delta2, 
		    double Delta3, double Delta4 ) 
{
  sPhysical p = m.displayPhys(); 

  outputfile << alpha 
	     << " " << beta
	     << " " << M_moduli 
	     << " " << M_mess
	     << " " << m32
	     << " " << tanb ; 

  outputfile << " " << p.mhiggs(1)
	     << " " << p.mhiggs(2)
	     << " " << p.mhiggs(3)
	     << " " << p.mhiggs(4) 
	     << " " << p.msnu(1) 
	     << " " << p.msnu(2)
	     << " " << p.msnu(3)
	     << " " << p.mch(1)
	     << " " << p.mch(2)
	     << " " << p.mneut(1)
	     << " " << p.mneut(2)
	     << " " << p.mneut(3)
	     << " " << p.mneut(4)
	     << " " << p.mGluino
	     << " " << p.mu(1,1)
	     << " " << p.mu(2,1)
	     << " " << p.mu(1,2)
	     << " " << p.mu(2,2)
	     << " " << p.mu(1,3)
	     << " " << p.mu(2,3)
	     << " " << p.md(1,1)
	     << " " << p.md(2,1)
	     << " " << p.md(1,2)
	     << " " << p.md(2,2)
	     << " " << p.md(1,3)
	     << " " << p.md(2,3)
	     << " " << p.me(1,1)
	     << " " << p.me(2,1)
	     << " " << p.me(1,2)
	     << " " << p.me(2,2)
	     << " " << p.me(1,3)
	     << " " << p.me(2,3) ; 

  outputfile << " " << btosgamma
	     << " " << muong2 
	     << " " << bsmumu
	     << " " << oh2 
	     << " " << m.displayProblem().test()
	     << " " << LSP
	     << " " << Delta1 
	     << " " << Delta2
	     << " " << Delta3
	     << " " << Delta4
	     << endl ; 

}

void spectrumrecord( ofstream& spectrumfile, MssmSoftsusy& m ) 
{
  sPhysical p = m.displayPhys() ;

  spectrumfile << " " << p.mhiggs(1)
	       << " " << p.mhiggs(2)
	       << " " << p.mhiggs(3)
	       << " " << p.mhiggs(4) 
	       << " " << p.msnu(1) 
	       << " " << p.msnu(2)
	       << " " << p.msnu(3)
	       << " " << p.mch(1)
	       << " " << p.mch(2)
	       << " " << p.mneut(1)
	       << " " << p.mneut(2)
	       << " " << p.mneut(3)
	       << " " << p.mneut(4)
	       << " " << p.mGluino
	       << " " << p.mu(1,1)
	       << " " << p.mu(2,1)
	       << " " << p.mu(1,2)
	       << " " << p.mu(2,2)
	       << " " << p.mu(1,3)
	       << " " << p.mu(2,3)
	       << " " << p.md(1,1)
	       << " " << p.md(2,1)
	       << " " << p.md(1,2)
	       << " " << p.md(2,2)
	       << " " << p.md(1,3)
	       << " " << p.md(2,3)
	       << " " << p.me(1,1)
	       << " " << p.me(2,1)
	       << " " << p.me(1,2)
	       << " " << p.me(2,2)
	       << " " << p.me(1,3)
	       << " " << p.me(2,3) 
	       << endl ; 

}

void RGRUN( ofstream& rgefile, MssmSoftsusy& m , 
	    double log10startscale, double log10endscale, 
	    int number ) 
{
  double scale ; 
  double step; 
  step = ( log10endscale - log10startscale) / number; 
  m.runto( pow( 10, log10startscale )  ) ; 
  for( int i = 0 ; i < number ; i++ ) { 
    scale = pow( 10, log10startscale + step*i) ; 
    m.runto( scale) ; 
    DoubleMatrix mQlmat = m.displaySoftMassSquared(mQl); 
    DoubleMatrix mUrmat = m.displaySoftMassSquared(mUr); 
    DoubleMatrix mDrmat = m.displaySoftMassSquared(mDr); 
    DoubleMatrix mLlmat = m.displaySoftMassSquared(mLl); 
    DoubleMatrix mErmat = m.displaySoftMassSquared(mEr); 
   
    double mHusqr = m.displayMh2Squared(); 
    double mHdsqr = m.displayMh1Squared(); 

    rgefile << scale 
	    << " " << m.displayGaugeCoupling(1) 
	    << " " << m.displayGaugeCoupling(2)
	    << " " << m.displayGaugeCoupling(3)
	    << " " << m.displayGaugino(1)
	    << " " << m.displayGaugino(2)
	    << " " << m.displayGaugino(3)
	    << " " << mQlmat(3,3)
	    << " " << mUrmat(3,3)
	    << " " << mDrmat(3,3)
	    << " " << mLlmat(3,3)
	    << " " << mErmat(3,3)
	    << " " << mQlmat(1,1)
	    << " " << mUrmat(1,1)
	    << " " << mDrmat(1,1)
	    << " " << mLlmat(1,1)
	    << " " << mErmat(1,1)
            << " " << mHusqr
	    << " " << mHdsqr
	    << endl ;
  }
}
 


// Returns a string with all characters in upper case: very handy
string ToUpper(const string & s) {
        string result;
        unsigned int index;
        for (index = 0; index < s.length(); index++) {
	  char a = s[index];
	  a = toupper(a);
	  result = result + a;
        }
	
	return result;
    }

void errorCall() {
  ostringstream ii;
  ii << "SOFTSUSY called with incorrect arguments. Need to put either:\n";
  ii << "softpoint.x sugra <m0> <m12> <a0> <tanb> <mgut> <sgnMu>\n";
  ii << "softpoint.x amsb <m0> <m32> <tanb> <mgut> <sgnMu>\n";
  ii << "softpoint.x gmsb <n5> <mMess> <lambda> <cgrav> <tanb> <sgnMu> \n";
  ii << "softpoint.x leshouches < lesHouchesInput \n";
  ii << "where bracketed entries are numerical values.\n";
  ii << "<mgut> denotes the scale at which the SUSY breaking ";
  ii << "parameters are specified. \n";
  ii << "Enter <mgut>=unified to define MGUT by g1(MGUT)=g2(MGUT), otherwise";
  ii << "\nit will be fixed at the numerical value input.\n";
  ii << "For SUSY breaking terms set at MSUSY, enter <mgut>=msusy.\n";
  ii << "lesHouchesInput contains the SUSY Les Houches accord";
  ii << " input.\n";
  throw ii.str();
}

/// start of definition of global variables
/// no quark mixing (dominant third family approx), and no verbose output
int MIXING = -1, PRINTOUT = 0;
/// Do we include 2-loop RGEs of *all* scalar masses and A-terms, or only the
/// scalar mass Higgs parameters? (Other quantities all 2-loop anyway): the
/// default in SOFTSUSY 2.x is to include all 2-loop terms
bool INCLUDE_2_LOOP_SCALAR_CORRECTIONS = true;
/// fractional accuracy required
double TOLERANCE = 1.0e-3;
/// there are two possible conventions: if QEWSB > MZ, its value is assumed
/// in GeV and used as a constant MSUSY. Otherwise, it MULTIPLIES the usual 
/// MSUSY value, of root(mstop1 mstop2)
double QEWSB = 1.0;
/// number of loops used to calculate Higgs mass and tadpoles. They should be
/// identical for a consistent calculation
int numRewsbLoops = 2, numHiggsMassLoops = 2;
/// decay constant of muon
double GMU = 1.16637e-5; 
/// end of global variable declaration

int main(int argc, char *argv[]) {

  int numPoints = 1;

  double qMax = 0.;
  
  // Sets format of output: 4 decimal places
  outputCharacteristics(6);

  void (*boundaryCondition)(MssmSoftsusy &, const DoubleVector &);
  

  
  if (argc !=1 ) {
    cerr << "GAUGE/GRAVITY" << endl; 
    cerr << "SOFTSUSY" << VERSION << endl;
    cerr << "B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331,";
    cerr << " hep-ph/0104145\n";
    cerr << "Low energy data in SOFTSUSY: MIXING=" << MIXING << " TOLERANCE=" 
	 << TOLERANCE << endl;
    cerr << "G_F=" << GMU << " GeV^2" << endl;
  }

  // RANDOM SEED /////////////////////
    time_t seconds;
    time( &seconds); 
    srand( (unsigned int) seconds ); 
  ////////////////////////////////////
  


  double mgutGuess = 2.0e16, mbmb = MBOTTOM, mtau = MTAU;
  int sgnMu = 1;
  bool gaugeUnification = false, ewsbBCscale = false, altEwsb = false;
  bool flag = false; 



  double alpha_start, alpha_end ;
  double beta_start, beta_end ;

  double M_moduli_start, M_moduli_end ;
  //  double M_gauge_start, M_gauge_end ; 
  double M_mess_start, M_mess_end ; 
  
  double alpha, beta , M_moduli, M_mess ;
  
  double tanb_start, tanb_end ; 
  double tanb = 10; 
  DoubleVector pars(4); 
  // My modification 
 
 
  cout << "argc = " << argc << endl; 
  cout << flush ; 


  if(argc != 3 ) {
    errorCall() ;
    exit(-1) ;
  }
  /*   if (!strcmp(argv[1], "g-gmsb")) {
    cout << "SOFTSUSY Gauge/Gravity calculation" << endl;
    cout << flush;  */

  if( argc == 3 ) { 

    ifstream inputfile(argv[1]); 
    ofstream outputfile(argv[2]); 

    string varname; 
    
    inputfile >> varname >> l1 ; 
    inputfile >> varname >> l2 ; 
    inputfile >> varname >> l3 ; 

    inputfile >> varname >> nQ ; 
    inputfile >> varname >> nU ; 
    inputfile >> varname >> nD ; 
    inputfile >> varname >> nL ; 
    inputfile >> varname >> nE ;
 
    inputfile >> varname >> nHu ; 
    inputfile >> varname >> nHd ; 

    inputfile >> varname >> N ;
 
    inputfile >> varname >> numscan;
    inputfile >> varname >> alpha_start ;
    inputfile >> varname >> alpha_end ;
    inputfile >> varname >> beta_start ; 
    inputfile >> varname >> beta_end ;
    inputfile >> varname >> M_moduli_start ; 
    inputfile >> varname >> M_moduli_end ; 
    inputfile >> varname >> M_mess_start   ; 
    inputfile >> varname >> M_mess_end   ; 
    inputfile >> varname >> tanb_start     ;
    inputfile >> varname >> tanb_end    ;

    inputfile >> varname >> sgnMu    ;
     
    inputfile.close(); 

    cout << "l1 = " << l1 << endl 
	 << "l2 = " << l2 << endl
	 << "l3 = " << l3 << endl 
	 << "nQ = " << nQ << endl 
       	 << "nU = " << nU << endl 
	 << "nD = " << nD << endl
	 << "nL = " << nL << endl 
	 << "nE = " << nE << endl 
	 << "nHu = " << nHu << endl 
	 << "nHd = " << nHd << endl 
	 << "N = " << N << endl 
	 << "numscan = " << numscan << endl
	 << "alpha_start = " << alpha_start << endl
	 << "alpha_end = " << alpha_end << endl 
	 << "beta_start = " << beta_start << endl
	 << "beta_end = " << beta_end << endl
	 << "M_moduli_start = " << M_moduli_start << endl
	 << "M_moduli_end = " << M_moduli_end << endl
	 << "M_mess_start = " << M_mess_start << endl 
	 << "M_mess_end = " << M_mess_end << endl 
	 << "tanb_start =  " << tanb_start << endl 
	 << "tanb_end = " << tanb_end << endl
	 << "sgnMu = " << sgnMu << endl; 


    for( int i = 0 ; i < numscan ; i++ ) { 
      QedQcd oneset0, oneset1, oneset2;

      alpha    = randomgenerator( alpha_start, alpha_end ) ;
      beta     = randomgenerator( beta_start, beta_end ) ; 
      M_moduli = randomgenerator( M_moduli_start, M_moduli_end ) ; 
      M_mess   = lograndomgenerator( M_mess_start,   M_mess_end ) ;
      tanb     = randomgenerator( tanb_start,     tanb_end ) ; 
      
      cout << i << "th run : " << endl ;  
      cout << "alpha = " << alpha << endl
	   << "beta  = " << beta  << endl	
	   << "M_moduli = " << M_moduli << endl 
	   << "M_mess   = " << M_mess   << endl 
	   << "tanb     = " << tanb     << endl ; 
      
      mgutGuess = 2e16;
      gaugeUnification = false;
      pars.setEnd(4);
      pars(1) = alpha; pars(2) = beta; pars(3) = M_moduli; pars(4) = M_mess; 
      //      r = &m;

      m32 =  find_out_m32_in_mirage( alpha, M_moduli ) ; 
      
      //      if (flag) oneset0.calcPoleMb();
      oneset0.toMz();
      oneset1.toMz(); 
      oneset2.toMz(); 
      
      //      ofstream  rgefile; 
      //    rgefile.open("rge.dat"); 
      
      //   ofstream  spectrumfile; 
      //   spectrumfile.open("spectrum.dat") ;
      
      //      cout << "Here comes r1 " << endl; 
      
      MssmSoftsusy r0 ; 
      //    cout << "Starting" << endl; 
      r0.N= 0 ; 
      r0.Nflag = true; 
      r0.beta2() ;
      r0.Nflag = false; 
      
      mgut0 =  r0.lowOrg(mirage_simple_BC0, mgutGuess, pars, sgnMu,
			       tanb, oneset0, gaugeUnification, ewsbBCscale);
      
      r0.runto( M_mess );
      
      //   cout << "starting phase 2 " << endl; 
      r0.N = N ;
      r0.Nflag = true; 
      r0.beta2() ; 
      r0.Nflag = false; 
      
      r0.runto( mgut0 ) ; 
      
      global_g1 = r0.displayGaugeCoupling(1); 
      global_g2 = r0.displayGaugeCoupling(2); 
      global_g3 = r0.displayGaugeCoupling(3); 

      global_yt = r0.displayYukawaElement( YU, 3,3) ;
      global_yb = r0.displayYukawaElement( YD, 3,3) ;
      global_ytau=r0.displayYukawaElement( YE, 3,3) ;

      cout << "HAHAHAHA" << endl ; 
      cout << "global_g1 = " << global_g1 << endl; 

      MssmSoftsusy r1 ; //, r2;// MssmSoftsusy2 l;
     
      r1.N = N ; 
      r1.Nflag = true; 
      r1.beta2(); 
      r1.Nflag = false ; 
      
      mgut1 =  r1.lowOrg(mirage_simple_BC1, mgutGuess, pars, sgnMu,
			tanb, oneset1, gaugeUnification, ewsbBCscale);
      
      
      //cout << "Here comes r1" << endl; 
      //  cout << r1 ; 
      
    //  RGRUN( rgefile, r1 , log(mgutGuess) / log(10) , log( M_mess) / log( 10 ) , 20 ) ; 
      
    //  r1.runto( mgut0 );
    //  cout << "BEFORE" << endl; 
    //  cout << r1 ; 

      //      r1.runto( mgut0 ) ; 
       
      //     cout << "BEFORE2" << endl; 
      //      cout << r1; 
      r1.runto( M_mess ) ;

      global_g1 = r1.displayGaugeCoupling(1); 
      global_g2 = r1.displayGaugeCoupling(2); 
      global_g3 = r1.displayGaugeCoupling(3); 

      global_yt = r1.displayYukawaElement( YU, 3,3) ;
      global_yb = r1.displayYukawaElement( YD, 3,3) ;
      global_ytau=r1.displayYukawaElement( YE, 3,3) ;

      cout << "HOHOHOHO" << endl ; 
      cout << "global_g1 = " << global_g1 << endl;       

      
      inter_gaugino1 = r1.displayGaugino(1); 
      inter_gaugino2 = r1.displayGaugino(2); 
      inter_gaugino3 = r1.displayGaugino(3); 
      
      inter_massmQl = r1.displaySoftMassSquared(mQl) ;
      inter_massmUr = r1.displaySoftMassSquared(mUr) ;
      inter_massmDr = r1.displaySoftMassSquared(mDr) ;
      inter_massmLl = r1.displaySoftMassSquared(mLl) ;
      inter_massmEr = r1.displaySoftMassSquared(mEr) ;
      inter_massmHu = r1.displayMh2Squared(); 
      inter_massmHd = r1.displayMh1Squared(); 
      
      inter_A_HuQU(1,1) = r1.displaySoftA( UA, 1, 1); 
      inter_A_HuQU(2,2) = r1.displaySoftA( UA, 2, 2); 
      inter_A_HuQU(3,3) = r1.displaySoftA( UA, 3, 3); 
      inter_A_HdQD(1,1) = r1.displaySoftA( DA, 1, 1); 
      inter_A_HdQD(2,2) = r1.displaySoftA( DA, 2, 2); 
      inter_A_HdQD(3,3) = r1.displaySoftA( DA, 3, 3); 
      inter_A_HdLE(1,1) = r1.displaySoftA( EA, 1, 1); 
      inter_A_HdLE(2,2) = r1.displaySoftA( EA, 2, 2); 
      inter_A_HdLE(3,3) = r1.displaySoftA( EA, 3, 3); 
      
      mgutGuess = M_mess ;
      
      
      //      cout << "Here comes r2" << endl; 
      MssmSoftsusy r2 ;
      r2.N = 0; 
      r2.Nflag = true; 
      r2.beta2(); 
      r2.Nflag = false ;
      
      mgut2 =  r2.lowOrg(deflectedmirage2, mgutGuess, pars, sgnMu, 
			tanb, oneset2, gaugeUnification, ewsbBCscale); 
       cout << r2 ; 
      
      //      RGRUN( rgefile, r2 , log(M_mess) / log(10),  log(100) / log(10), 20 ) ; 
      
      //rgefile.close(); 
      
      //spectrumrecord( spectrumfile, r2 ) ;
      
      // spectrumfile.close(); 
      
      //cout << r2 ; 
      //  sPhysical p = r2.displayPhys() ;
      
      //  cout << p ; 
     
      if (r2.displayProblem().test()) {
	cout << "# SOFTSUSY problem with point: " << r2.displayProblem();
      }      


      double mu = r2.displayMu(); 

      double smu2 = findmu2( r2.displayTanb(), 
			    r2.displayMh2Squared(), r2.displayMh1Squared() ); 
      cout << "mu = " << mu << endl; 
      cout << "smu2 = " << smu2 << endl; 

      r2.runto(M_mess) ;


      global_g1 = r0.displayGaugeCoupling(1); 
      global_g2 = r0.displayGaugeCoupling(2); 
      global_g3 = r0.displayGaugeCoupling(3); 

      global_yt = r0.displayYukawaElement( YU, 3,3) ;
      global_yb = r0.displayYukawaElement( YD, 3,3) ;
      global_ytau=r0.displayYukawaElement( YE, 3,3) ;


      ////////////////////////////////////////////////////

      MssmSoftsusy ft01 = r1; 
      MssmSoftsusy ft01p = r1; 
      MssmSoftsusy ft02 = r2; 

      ft01.N = N ;  
      ft01.Nflag = true; 
      ft01.beta2();  
      ft01.Nflag = false ;

      ft01p.N = N ;  
      ft01p.Nflag = true; 
      ft01p.beta2(); 
      ft01p.Nflag = false ;

      DoubleVector parsft(4); 
      parsft.setEnd(4); 
      parsft(1) = 0 ; parsft(2) = 0 ;
      parsft(3) = 0 ; parsft(4) = 0 ;
      
      r1.runto(mgut0); 
      ft01.runto(mgut0) ; 
      ft01p.runto(mgut0); 
      cout << "++++++++++++++++++++ r1 +++++++++++++++++ " << endl;
      cout << r1.N << endl; 
      cout << r1 ; 

      cout << "++++++++++++++++++++ FT01 +++++++++++++++++ " << endl;
      cout << ft01.N << endl; 
      cout << ft01 ; 

      cout << "++++++++++++++++++++ FT01p ++++++++++++++++ " << endl; 
      cout << ft01p.N << endl; 
      cout << ft01p;  

      
      finetuneparameter_at_gut( ft01, pars, parsft ) ; 

      //      ft01.runto(mgut0) ; 
      //    ft01p.runto(mgut0); 
      cout << "++++++++++++++++++++ FT01 AFTER +++++++++++++++++ " << endl;
      cout << ft01.N << endl; 
      cout << ft01 ; 

      cout << "++++++++++++++++++++ FT01p AFTER ++++++++++++++++ " << endl; 
      cout << ft01p.N << endl; 
      cout << ft01p;  

      cout << "++++++++++++++++++++ r0 AFTER +++++++++++++++++++ " << endl ;
      cout << r0 << endl ;

      finetuneparameter_at_mess( ft01p, ft01, ft02, pars, parsft );

      ft02.N = 0 ;  
      ft02.Nflag = true; 
      ft02.beta2();  
      ft02.Nflag = false ; 

      ft02.runto(mu); 
      
      double mz2 = MZ2( smu2 , ft02.displayTanb(),
			ft02.displayMh2Squared(), ft02.displayMh1Squared()  ) ;

      cout << "----------------------------------" << endl ; 
      cout << "--------- ft0 ====================" << endl ; 
      cout << "==================================" << endl ;
      cout << "mz2 = " << mz2 << endl; 
      cout << "MZ * MZ = " << MZ * MZ  << endl ; 
      cout << "sqrt(mz2) = " << sqrt(mz2) << endl; 

      ////////////////////////////////////////////////////////////      
      //      DoubleVector parsft(4); 
      //   parsft.setEnd(4); 

      MssmSoftsusy ft11 = r1; 
      MssmSoftsusy ft11p= r1;
      MssmSoftsusy ft12 = r2; 

      parsft(1) = 0.001 * pars(1); parsft(2) = 0 ;
      parsft(3) = 0 ; parsft(4) = 0 ;

      ft11.N = N ;  
      ft11.Nflag = true; 
      ft11.beta2();  
      ft11.Nflag = false ;

      ft11p.N = N ;  
      ft11p.Nflag = true; 
      ft11p.beta2(); 
      ft11p.Nflag = false ;
      
      finetuneparameter_at_gut( ft11, pars, parsft ) ; 

      finetuneparameter_at_mess( ft11p, ft11, ft12, pars, parsft );

      ft12.N = 0 ;  
      ft12.Nflag = true; 
      ft12.beta2();  
      ft12.Nflag = false ; 

      cout << "mu = " << mu << endl; 
      ft12.runto(mu); 
      
      double mz2_1 = MZ2( smu2 , ft12.displayTanb(),
			ft12.displayMh2Squared(), ft12.displayMh1Squared()  ) ;

      cout << "----------------------------------" << endl ; 
      cout << "--------- ft1 ====================" << endl ; 
      cout << "==================================" << endl ;
      cout << "mz2 = " << mz2_1 << endl; 
      cout << "MZ * MZ = " << MZ * MZ  << endl ; 
      cout << "sqrt(mz2) = " << sqrt(mz2_1) << endl; 

      cout << "smu2 = " << smu2  << endl; 
      cout << "M2HU = " << ft12.displayMh2Squared()<< endl;
      cout << "M2HD = " << ft12.displayMh1Squared()<< endl; 


      double Delta1 = 0.5 * 1000. * (mz2_1 -mz2 ) / mz2 ; 
      cout << "Delta = " << Delta1 << endl; 

      //////////////////////////////////////////////////

      MssmSoftsusy ft21 = r1;
      MssmSoftsusy ft21p= r1; 
      MssmSoftsusy ft22 = r2; 

      parsft(1) = 0 ; parsft(2) = 0.001 * pars(2) ;
      parsft(3) = 0 ; parsft(4) = 0 ;

      ft21.N = N ;  
      ft21.Nflag = true; 
      ft21.beta2();  
      ft21.Nflag = false ;

      ft21p.N = N ;  
      ft21p.Nflag = true; 
      ft21p.beta2(); 
      ft21p.Nflag = false ;
      
      finetuneparameter_at_gut( ft21, pars, parsft ) ; 

      finetuneparameter_at_mess( ft21p, ft21, ft22, pars, parsft );

      ft22.N = 0 ;  
      ft22.Nflag = true; 
      ft22.beta2();  
      ft22.Nflag = false ; 

      ft22.runto(mu); 
      
      double mz2_2 = MZ2( smu2 , ft22.displayTanb(),
			ft22.displayMh2Squared(), ft22.displayMh1Squared()  ) ;
      cout << "==============================" << endl ;
      cout << "========== ft2 ===============" << endl; 
      cout << "==============================" << endl; 
      cout << "mz2 = " << mz2_2 << endl; 
      cout << "MZ * MZ = " << MZ * MZ  << endl ; 
      cout << "sqrt(mz2) = " << sqrt(mz2_2) << endl; 

      cout << "smu2 = " << smu2  << endl; 
      cout << "M2HU = " << ft22.displayMh2Squared()<< endl;
      cout << "M2HD = " << ft22.displayMh1Squared()<< endl; 

      double Delta2 =  0.5 * 1000. * (mz2_2 -mz2 ) / mz2  ; 
      cout << "Delta = " << Delta2 << endl; 

      ///////////////////////////////////////////////////////////////////	
      //////////////////////////////////////////////////

      MssmSoftsusy ft31 = r1; 
      MssmSoftsusy ft31p= r1;
      MssmSoftsusy ft32 = r2; 

      parsft(1) = 0 ; parsft(2) = 0 ;
      parsft(3) = 0.001 * pars(3) ; parsft(4) = 0 ;

      ft31.N = N ;  
      ft31.Nflag = true; 
      ft31.beta2();  
      ft31.Nflag = false ;

      ft31p.N = N ;  
      ft31p.Nflag = true; 
      ft31p.beta2(); 
      ft31p.Nflag = false ;
  
      
      finetuneparameter_at_gut( ft31, pars, parsft ) ; 

      finetuneparameter_at_mess( ft31p, ft31, ft32, pars, parsft );

      ft32.N = 0 ;  
      ft32.Nflag = true; 
      ft32.beta2();  
      ft32.Nflag = false ; 

      cout << "mu = " << mu << endl; 
      ft32.runto(mu); 
      
      double mz2_3 = MZ2( smu2 , ft32.displayTanb(),
			  ft32.displayMh2Squared(), ft32.displayMh1Squared()  ) ;
      double mz2_3p = MZ2( smu2 * sqr(1.001) , ft32.displayTanb(),
			  ft32.displayMh2Squared(), ft32.displayMh1Squared()  ) ;

      cout << "==============================" << endl ;
      cout << "========== ft3 ===============" << endl; 
      cout << "==============================" << endl; 
      cout << "mz2 = " << mz2_3 << endl; 
      cout << "MZ * MZ = " << MZ * MZ  << endl ; 
      cout << "sqrt(mz2) = " << sqrt(mz2_3) << endl; 

      cout << "smu2 = " << smu2  << endl; 
      cout << "smu2 * 1.001^2 = " << smu2 * sqr(1.001) << endl; 
      cout << "smu2*1.001^2 - smu2 = " << smu2 * sqr(1.001) - smu2 << endl; 

      cout << "M2HU = " << ft32.displayMh2Squared()<< endl;
      cout << "M2HD = " << ft32.displayMh1Squared()<< endl; 
      
      double Delta3 = 0.5*  1000. * (mz2_3 -mz2 ) / mz2 ; 
      double Delta3p = 0.5 * 1000. * (mz2_3p - mz2 ) /mz2 ; 
      cout << "Delta = " << Delta3 << endl; 
      cout << "Delta3p = " << Delta3p << endl; 

      ///////////////////////////////////////////////////////////////////


      //////////////////////////////////////////////////

      MssmSoftsusy ft41 = r1;
      MssmSoftsusy ft41p= r1;
      MssmSoftsusy ft42 = r2;

      parsft(1) = 0 ; parsft(2) = 0 ;
      parsft(3) = 0 ; parsft(4) = 0.01 * pars(4) ;

      ft41.N = N ;  
      ft41.Nflag = true; 
      ft41.beta2();  
      ft41.Nflag = false ;

      ft41p.N = N ;  
      ft41p.Nflag = true; 
      ft41p.beta2(); 
      ft41p.Nflag = false ;
      
      finetuneparameter_at_gut( ft41, pars, parsft ) ; 

      finetuneparameter_at_mess( ft41p, ft41, ft42, pars, parsft );

      ft42.N = 0 ;  
      ft42.Nflag = true; 
      ft42.beta2();  
      ft42.Nflag = false ; 

      ft42.runto(mu); 
      
      double mz2_4 = MZ2( smu2 , ft42.displayTanb(),
			ft42.displayMh2Squared(), ft42.displayMh1Squared()  ) ;
      cout << "==============================" << endl ;
      cout << "========== ft4 ===============" << endl; 
      cout << "==============================" << endl; 
      cout << "mz2 = " << mz2_4 << endl; 
      cout << "MZ * MZ = " << MZ * MZ  << endl ; 
      cout << "sqrt(mz2) = " << sqrt(mz2_4) << endl; 

      cout << "smu2 = " << smu2  << endl; 
      cout << "M2HU = " << ft42.displayMh2Squared()<< endl;
      cout << "M2HD = " << ft42.displayMh1Squared()<< endl; 
      
      double Delta4 = 100. * (mz2_4 -mz2 ) / mz2 ; 
      cout << "Delta = " << Delta4 << endl; 

      ///////////////////////////////////////////////////////////////////

      recordphysics( outputfile, r2, 
		     alpha, beta, M_moduli, M_mess, m32, tanb, 
		     0 /* bsg_value */, 0 /* gmuon_value*/ , 
		     0 /* bsmumu_value */, 0 /* Omega */, 
		     "-" /*  mess */,Delta1, Delta2, Delta3, Delta4 ) ; 


      /*

      ofstream  rgefile; 
      rgefile.open("rge.dat"); 
	    //          ofstream  spectrumfile; 
      //     spectrumfile.open("spectrum.dat") ;
      



      r1.N = N ;  
      r1.Nflag = true; 
      r1.beta2();  
      r1.Nflag = false ;



      
      RGRUN( rgefile, r1 , log(mgut0) / log(10) , log( M_mess) / log( 10 ) , 100 ) ;       

      r2.N = 0 ;  
      r2.Nflag = true; 
      r2.beta2(); 
      r2.Nflag = false ;

      RGRUN( rgefile, r2 , log(M_mess) / log(10),  log(100) / log(10), 100 ) ;

      */


    }
  }

  
  //  if (r2.displayProblem().test()) {
  //   cout << "# SOFTSUSY problem with point: " << r2.displayProblem();
  //  }
  
  exit(0);

  
}
