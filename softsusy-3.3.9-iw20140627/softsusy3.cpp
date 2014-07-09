///
/// newly added routine for two scale models. 
/// this file contains iteration and spectrum calculation.  
///


#include "softsusy.h"

Dmm_discrete_param dmm_discrete_param ; 


void deflectedmirageBcsUV( MssmSoftsusy& m, const DoubleVector &pars )
{
  double alpha, beta; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 
  double m32 ; 
 

  aHu = 1.0 - dmm_discrete_param.nHu ; 
  aHd = 1.0 - dmm_discrete_param.nHd ; 
  aQ = 1.0 - dmm_discrete_param.nQ ; 
  aU = 1.0 - dmm_discrete_param.nU ; 
  aD = 1.0 - dmm_discrete_param.nD ; 
  aL = 1.0 - dmm_discrete_param.nL ; 
  aE = 1.0 - dmm_discrete_param.nE ; 

  alpha = pars.display(1);
  beta  = pars.display(2); 
  M0    = pars.display(3); 

  m32 = find_out_m32_in_mirage( alpha, M0, 1e-3 );  

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = m.displayGaugeCoupling(1); 
  g2 = m.displayGaugeCoupling(2); 
  g3 = m.displayGaugeCoupling(3); 
  gY = sqrt(3./5.) * g1 ; 
  yt = m.displayYukawaElement(YU,3,3); 
  yb = m.displayYukawaElement(YD,3,3); 
  ytau = m.displayYukawaElement(YE,3,3); 

  double b3p, b2p , b1p ; 
  b3p =      -3 + dmm_discrete_param.N5pair ; 
  b2p=        1 + dmm_discrete_param.N5pair ; 
  b1p = 33./ 5. + dmm_discrete_param.N5pair  ;

  double gammaHu , gammaHd  ;
  double gammaQ[4], gammaU[4], gammaD[4] ; 
  double gammaL[4], gammaE[4] ; 

  gammaHu = 3./2. *g2*g2 + 1./2. * gY * gY  - 3. * yt *yt ;
  gammaHd = 3./2. *g2*g2 + 1./2. * gY * gY - 3. * yb *yb - ytau*ytau  ;
  
  for( int i = 1;  i <= 3 ; i++ ) { 
    gammaQ[i] = 8./3. *g3*g3 + 3./2.*g2*g2 + 1./18. *gY *gY 
      -  ( i==3 ? (yt*yt + yb*yb ) :0 )  ; 
    gammaU[i] = 8./3. *g3*g3 + 8./9.*gY*gY 
       - ( i==3 ? (2.*yt*yt): 0 )   ; 
    gammaD[i] = 8./3. *g3*g3 + 2./9.*gY*gY
        - ( i==3 ? (2.*yb*yb): 0 )   ; 
    gammaL[i] = 3./2. *g2*g2 + 1./2.*gY*gY
        - ( i==3 ? (ytau*ytau) : 0 ) ;
    gammaE[i] = 2. * gY*gY  - ( i==3 ? (2.*ytau*ytau) : 0 )  ; 
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



void dmm_Threshold( MssmSoftsusy & m, const DoubleVector & pars,
		    double& dm1,    double& dm2,    double& dm3,  
		    double& dmqlsq, double& dmursq, double& dmdrsq, 
		    double& dmllsq, double& dmersq, 
		    double& dmhusq, double& dmhdsq
		    ) 
{ 
  double alpha, beta ; 
  double aHu, aHd, aQ, aU, aD, aL, aE ;
  double M0 ; 
  double m32; 

  aHu = 1.0 - dmm_discrete_param.nHu ; 
  aHd = 1.0 - dmm_discrete_param.nHd ; 
  aQ = 1.0  - dmm_discrete_param.nQ ; 
  aU = 1.0  - dmm_discrete_param.nU ; 
  aD = 1.0  - dmm_discrete_param.nD ; 
  aL = 1.0  - dmm_discrete_param.nL ; 
  aE = 1.0  - dmm_discrete_param.nE ; 

  alpha = pars.display(1); 
  beta  = pars.display(2); 
  M0    = pars.display(3); 

  m32 = find_out_m32_in_mirage( alpha, M0, 1e-3);  

  double g1 , g2, g3 , gY , yt, yb, ytau ; 

  g1 = m.displayGaugeCoupling(1); 
  g2 = m.displayGaugeCoupling(2); 
  g3 = m.displayGaugeCoupling(3); 
  gY = sqrt(3./5.) * g1 ; 
  yt =   m.displayYukawaElement(YU,3,3); 
  yb =   m.displayYukawaElement(YD,3,3); 
  ytau = m.displayYukawaElement(YE,3,3); 

  double Mgauge ; 
  
  Mgauge = beta * m32 ;


  double alpha1, alpha2 , alpha3 ; 
  alpha1 = sqr(g1) / ( 4.0 * PI ) ; 
  alpha2 = sqr(g2) / ( 4.0 * PI ) ; 
  alpha3 = sqr(g3) / ( 4.0 * PI ) ; 
  
  double N = dmm_discrete_param.N5pair; 

  dm1 = - N * alpha1 / (4.0*PI) * Mgauge + (-N) * alpha1 / (4.0*PI) * m32;
  dm2 = - N * alpha2 / (4.0*PI) * Mgauge + (-N) * alpha2 / (4.0*PI) * m32;
  dm3 = - N * alpha3 / (4.0*PI) * Mgauge + (-N) * alpha3 / (4.0*PI) * m32;

  double ddgammaHu , ddgammaHd , ddgammaQ , ddgammaU, ddgammaD, ddgammaL, ddgammaE ; 

  ddgammaHu = 3./2. * (-N) * g2*g2*g2*g2 + 3./10.* (-N) * g1*g1*g1*g1 ; 
  ddgammaHd = 3./2. * (-N) * g2*g2*g2*g2 + 3./10.* (-N) * g1*g1*g1*g1 ;
  ddgammaQ  = 8./3.* (-N) *g3*g3*g3*g3 + 3./2.* (-N) *g2*g2*g2*g2 
    + 1./30.* (-N) *g1*g1*g1*g1 ; 
  ddgammaU  = 8./3.* (-N) *g3*g3*g3*g3 + 8./15.* (-N) *g1*g1*g1*g1; 
  ddgammaD  = 8./3.* (-N) *g3*g3*g3*g3 + 2./15.* (-N) *g1*g1*g1*g1;
  ddgammaL  = 3./2.* (-N) *g2*g2*g2*g2 + 3./10.* (-N) *g1*g1*g1*g1;
  ddgammaE  = 6./5.* (-N) *g1*g1*g1*g1; 

  double deltamqlsq , deltamllsq, deltamursq, deltamdrsq, deltamersq ; 
  double deltamhusq , deltamhdsq; 

  dmursq = 2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 4.0/3.0 * sqr(alpha3) + 0.6 * 4.0 / 9.0 * sqr(alpha1) ) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaU ; 

  dmdrsq =  2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 )  * 
    ( 4.0/3.0 * sqr(alpha3) + 0.6 * 1.0 / 9.0 * sqr(alpha1) ) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaD ; 

  dmersq =  2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 0.6 * sqr(alpha1) ) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaE ; 

  dmqlsq =  2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 4.0/3.0 * sqr(alpha3) + 0.75 * sqr(alpha2) + 0.6 /36.0 * sqr(alpha1)) 
     - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaQ ; 

  dmllsq = 2.0/sqr( 4.0 * PI )*N * (sqr(Mgauge) + 2.0 * Mgauge * m32 ) * 
    ( 0.75 * sqr(alpha2) + 0.6*0.25 * sqr(alpha1) )
    - m32*m32/(256.*M_PI*M_PI*M_PI*M_PI)*ddgammaL ; 
 
  dmhusq = dmllsq; 
  dmhdsq = dmllsq; 

}


// Threshold will be subtracted as the running scale goes up.
void deflectedmirageBcsThresholdUp( MssmSoftsusy & m, 
				  const DoubleVector & pars ) 
{ 
  double dm1, dm2, dm3,  
    dmqlsq, dmursq, dmdrsq, 
    dmllsq, dmersq, 
    dmhusq, dmhdsq ; 

  dmm_Threshold( m, pars, 
		 dm1, dm2, dm3,  
		 dmqlsq, dmursq, dmdrsq, 
		 dmllsq, dmersq, 
		 dmhusq, dmhdsq ) ; 

  double m1, m2, m3 ;

  m1 = m.displayGaugino(1); 
  m2 = m.displayGaugino(2); 
  m3 = m.displayGaugino(3); 

  m.setGauginoMass(1, m1-dm1) ;
  m.setGauginoMass(2, m2-dm2) ;
  m.setGauginoMass(3, m3-dm3) ;

  DoubleMatrix massmQl = m.displaySoftMassSquared(mQl); 
  DoubleMatrix massmUr = m.displaySoftMassSquared(mUr); 
  DoubleMatrix massmDr = m.displaySoftMassSquared(mDr); 
  DoubleMatrix massmLl = m.displaySoftMassSquared(mLl); 
  DoubleMatrix massmEr = m.displaySoftMassSquared(mEr); 

  double massmHu = m.displayMh2Squared(); 
  double massmHd = m.displayMh1Squared(); 


  DoubleMatrix id(3, 3);
  id(1, 1) = 1.0; id(2, 2) = 1.0; id(3, 3) = 1.0;

  m.setSoftMassMatrix(mQl, massmQl - dmqlsq * id);
  m.setSoftMassMatrix(mUr, massmUr - dmursq * id);
  m.setSoftMassMatrix(mDr, massmDr - dmdrsq * id);
  m.setSoftMassMatrix(mLl, massmLl - dmllsq * id);  
  m.setSoftMassMatrix(mEr, massmEr - dmersq * id);
  m.setMh2Squared(massmHu - dmhusq);
  m.setMh1Squared(massmHd - dmhdsq);

}

// Threshold will be added as the running scale goes down. 
void deflectedmirageBcsThresholdDown( MssmSoftsusy & m, 
				      const DoubleVector & pars ) 
{ 
  double dm1, dm2, dm3,  
    dmqlsq, dmursq, dmdrsq, 
    dmllsq, dmersq, 
    dmhusq, dmhdsq ; 

  dmm_Threshold( m, pars, 
		 dm1, dm2, dm3,  
		 dmqlsq, dmursq, dmdrsq, 
		 dmllsq, dmersq, 
		 dmhusq, dmhdsq ) ; 

  double m1, m2, m3 ;

  m1 = m.displayGaugino(1); 
  m2 = m.displayGaugino(2); 
  m3 = m.displayGaugino(3); 

  m.setGauginoMass(1, m1+dm1) ;
  m.setGauginoMass(2, m2+dm2) ;
  m.setGauginoMass(3, m3+dm3) ;

  DoubleMatrix massmQl = m.displaySoftMassSquared(mQl); 
  DoubleMatrix massmUr = m.displaySoftMassSquared(mUr); 
  DoubleMatrix massmDr = m.displaySoftMassSquared(mDr); 
  DoubleMatrix massmLl = m.displaySoftMassSquared(mLl); 
  DoubleMatrix massmEr = m.displaySoftMassSquared(mEr); 

  double massmHu = m.displayMh2Squared(); 
  double massmHd = m.displayMh1Squared(); 


  DoubleMatrix id(3, 3);
  id(1, 1) = 1.0; id(2, 2) = 1.0; id(3, 3) = 1.0;

  m.setSoftMassMatrix(mQl, massmQl + dmqlsq * id);
  m.setSoftMassMatrix(mUr, massmUr + dmursq * id);
  m.setSoftMassMatrix(mDr, massmDr + dmdrsq * id);
  m.setSoftMassMatrix(mLl, massmLl + dmllsq * id);  
  m.setSoftMassMatrix(mEr, massmEr + dmersq * id);
  m.setMh2Squared(massmHu + dmhusq);
  m.setMh1Squared(massmHd + dmhdsq);

}

double m32func( double alpha, double M0, double m32) 
{
  const double MPLANCK = 2.4e18; 
  return alpha * M0 * log( MPLANCK / m32 ) ;  

}

double find_out_m32_in_mirage( double alpha, double M0, double eps ) 
{
  double x = 30000 ; 
  double xnew ; 
  
  xnew = x ; 

  do {  
    x = xnew; 
    xnew = m32func( alpha, M0, x )  ; 

  } while(abs(xnew-x) > x*eps ) ; 

  return x; 
}

 
/// Returns low energy softsusy object consistent with BC's m0 etc at MGUT.
/// oneset should be at MZ and contains the SM data to fit the model to.
/// If the running comes into difficulty, eg if a Landau pole is reached, it
/// returns a ZERO object: no result is possible!
/// Boundary condition is the theoretical condition on parameters at the high
/// energy scale mx: the parameters themselves are contained within the vector.
double MssmSoftsusy::lowOrgTwoScale
(void (*bcUV)(MssmSoftsusy &, const DoubleVector &),
 void (*bcThresholdUp)(MssmSoftsusy &, const DoubleVector &),
 void (*bcThresholdDown)(MssmSoftsusy &, const DoubleVector &),
 double mxGuess, double mThreshold,
 const DoubleVector & pars, int sgnMu, double tanb, const QedQcd &
 oneset, bool gaugeUnification) {

  double mx = 0.0;

  try {

    const static MssmSoftsusy empty;

    double muFirst = displaySusyMu(); /// Remember initial values
    bool setTbAtMXflag = displaySetTbAtMX(); 
    bool altFlag = displayAltEwsb();
    double m32 = displayGravitino();
    double muCondFirst = displayMuCond();
    double maCondFirst = displayMaCond();

    setSoftsusy(empty); /// Always starts from an empty object
    /// These are things that are re-written by the new initialisation
    setSetTbAtMX(setTbAtMXflag); 
    if (altFlag) useAlternativeEwsb();
    setData(oneset); 
    setMw(MW); 
    setM32(m32);
    setMuCond(muCondFirst);
    setMaCond(maCondFirst);

    double mz = displayMz();

    /// Here all was same
    if (mxGuess > 0.0) 
      mx = mxGuess; 
    else {
      string ii("Trying to use negative mx in MssmSoftsusy::lowOrg.\n");
      ii = ii + "Now illegal! Use positive mx for first guess of mx.\n";
      throw ii;
    }
    
    if (oneset.displayMu() != mz) {
      cout << "WARNING: lowOrg in softsusy.cpp called with oneset at scale\n" 
	   << oneset.displayMu() << "\ninstead of " << mz << endl;
    }
    
    int maxtries = 100; 
    double tol = TOLERANCE;
    
    MssmSusy t(guessAtSusyMt(tanb, oneset));
    
    t.setLoops(2); /// 2 loops should protect against ht Landau pole 
    t.runto(mx); 
    
    setSusy(t);
    
    /// Initial guess: B=0, 
    // IWKIM
    bcUV(*this, pars); // old // boundaryCondition(*this, pars);
    // END IWKIM

    if (sgnMu == 1 || sgnMu == -1) { // old // ((sgnMu == 1 || sgnMu == -1) && !ewsbBCscale) {
      setSusyMu(sgnMu * MZ);
      setM3Squared(1.0e6);
    }
    else {
      if (altEwsb) {
   	    setSusyMu(displayMuCond());
	    setM3Squared(displayMaCond());
      }
      else {
	    setSusyMu(muFirst);
	    setM3Squared(muFirst); 
      }
    }
    // IWKIM
    run_high(mx, mThreshold) ; 
    bcThresholdDown(*this,pars);
    run_low(mThreshold,mz);
    // END IWKIM
    // old // run(mx, mz);
    
    if (sgnMu == 1 || sgnMu == -1) rewsbTreeLevel(sgnMu); 
      
    physical(0);
    
    setThresholds(3); setLoops(2);
    
    // IWKIM
    itLowsoftTwoScale(maxtries, mx, mThreshold, sgnMu, tol, tanb, 
		      bcUV, bcThresholdUp, bcThresholdDown, pars, 
		      gaugeUnification );
    // END IWKIM

    // old // itLowsoft(maxtries, mx, sgnMu, tol, tanb, boundaryCondition, pars, 
	// 	gaugeUnification, ewsbBCscale);
    
    if (displayProblem().nonperturbative 
	|| displayProblem().higgsUfb || displayProblem().tachyon 
	|| displayProblem().noRhoConvergence)
      return mx;
    // IWKIM
    runto_low(maximum(displayMsusy(), MZ));
    // END IWKIM
    // old // runto(maximum(displayMsusy(), mz));
    // old // if (ewsbBCscale) boundaryCondition(*this, pars); 
    
    physical(3);

    // IWKIM
    runto_low(mz);
    // END IWKIM
    // old // runto(mz);
    
    if (PRINTOUT) cout << " end of iteration" << endl;
  }
    catch(const char *a) {
    ostringstream ii;
    ii << "SOFTSUSY problem: " << a << " pars=" << pars << " tanb=" << tanb 
       << " oneset=" << oneset << endl;
    flagProblemThrown(true);
    throw(ii.str());
  }
  catch(const string & a) {
    ostringstream ii;
    ii << "SOFTSUSY problem: " << a << " pars=" << pars << " tanb=" << tanb 
	 << " oneset=" << oneset << endl;
    flagProblemThrown(true);
    throw ii.str();
  }
  catch(...) {
    ostringstream ii;
    ii << "SOFTSUSY problem: " << endl;
    ii << "pars=" << pars << " tanb=" << tanb
       << " oneset=" << oneset << endl;
    flagProblemThrown(true);
    throw ii.str();
  }
  
  return mx;
}

void MssmSoftsusy::itLowsoftTwoScale
(int maxTries, double & mx, double mThreshold, 
 int sgnMu, double tol, double tanb, 
 void (*bcUV)(MssmSoftsusy &, const DoubleVector &), 
 void (*bcThresholdUp)(MssmSoftsusy &, const DoubleVector &), 
 void (*bcThresholdDown)(MssmSoftsusy &, const DoubleVector &), 
 const DoubleVector & pars, bool gaugeUnification ) {

  static MssmSoftsusy old;
  static double oldMu = 0.;
  static int numTries = 0;
  double mz = displayMz();

  if (numTries != 0 && sqr(displayMu() / mz - 1.0) > TOLERANCE) {
    cout << "WARNING: itLowsoft called at inappropriate";
    cout << " scale:" << displayMu() << endl; 
    cout << "whereas it should be " << mz << endl; 
  }
  
  if (numTries - 1 > maxTries) {/// Iterating too long: bail out
    flagNoConvergence(true);
    if (PRINTOUT) cout << "itLowsoftTwoScale reached maxtries\n"; 
    numTries = 0; 
    return;
  }

  if (PRINTOUT > 1) cout << displayProblem(); 

  double mtpole, mtrun;
  
  mtpole = displayDataSet().displayPoleMt();
  /// On first iteration, don't bother with finite corrections
  
  numTries = numTries + 1;
  try {
    sparticleThresholdCorrections(tanb); 

    if (problem.noRhoConvergence && PRINTOUT) 
      cout << "No convergence in rhohat\n"; 
  
    /// precision of running/RGE integration: start off low and increase
    double eps = maximum(exp(double(- numTries) * log(10.0)), tol * 0.01); 
    
    /// first stab at MSUSY: root(mstop1(MZ) mstop2(MZ))
    if (numTries == 1) setMsusy(calcMs()); 
    
    int err = 0;
    err = runto_low(displayMsusy(), eps);
    // old // err = runto(displayMsusy(), eps);

    double tbIn; double predictedMzSq = 0.;
    predictedMzSq = predMzsq(tbIn);
    setPredMzSq(predictedMzSq);  

    // IWKIM
    err = runto_low(mThreshold,eps); 
    bcThresholdUp( (*this), pars ); 
    err = runto_high(mx, eps);
    // END IWKIM    
    // old // if (!ewsbBCscale) err = runto(mx, eps);

    /// Guard against the top Yukawa fixed point
    if (displayYukawaElement(YU, 3, 3) > 3.0 
	|| displayYukawaElement(YD, 3, 3) > 3.0 
	|| displayYukawaElement(YE, 3, 3) > 3.0) {
      setYukawaElement(YU, 3, 3, minimum(3.0, displayYukawaElement(YU, 3, 3)));
      setYukawaElement(YD, 3, 3, minimum(3.0, displayYukawaElement(YD, 3, 3)));
      setYukawaElement(YE, 3, 3, minimum(3.0, displayYukawaElement(YE, 3, 3)));
      flagIrqfp(true); 
    }
    
    if (err) {
      /// problem with running: bail out 
      flagProblemThrown(true);
      if (PRINTOUT) 
	cout << "itLowsoft can't run more approaching mgut\n"; 
      if (PRINTOUT > 1) printObj();
      numTries = 0; 
      return;
    }
  
    if (gaugeUnification) {
      sBrevity (dummy);
      MssmSusy a(this -> MssmSusy::beta(dummy));
      
      /// Equal gauge couplings: let them and their derivatives set the boundary
      /// condition scale -- linear approximation
      mx = mx * exp((displayGaugeCoupling(2) - displayGaugeCoupling(1))
		    / (a.displayGaugeCoupling(1) - a.displayGaugeCoupling(2)));

      /// if mx is too high/low, will likely get non-perturbative problems
      if (mx < 1.0e4) {
	mx = 1.0e4;
	if (PRINTOUT > 2) cout << " mx too low ";
	flagMgutOutOfBounds(true);
      }
      if (mx > 5.0e17) {
	if (PRINTOUT > 2) cout << " mx =" << mx <<" too high ";
	mx = 5.0e17;
	flagMgutOutOfBounds(true);
      }
    }

    // IWKIM    
    bcUV(*this, pars); 
    // END IWKIM
    // old // boundaryCondition(*this, pars); 

    // old // if (!ewsbBCscale) err = runto(displayMsusy(), eps);

    // IWKIM
    err = runto_high(mThreshold, eps) ;
    bcThresholdDown(*this, pars); 
    err = runto_low( displayMsusy(), eps);
    // END IWKIM

    calcDrBarPars();

    if (err) {
      // problem with running: bail out 
      flagProblemThrown(true);
      if (PRINTOUT) cout << "itLowsoft gone non-perturbative on way to MZ\n"; 
      if (PRINTOUT > 1) printObj();
      numTries = 0;
      return;
    }

    setMsusy(calcMs());
    // old // if (ewsbBCscale) mx = displayMsusy();
    if (PRINTOUT > 0) cout << " mgut=" << mx << flush;
    
    mtrun = forLoops.mt; ///< This will be at MSUSY
    //    double tbIn; double predictedMzSq = 0.;
    if (numTries < 11) {
      rewsb(sgnMu, mtrun, pars);    
    }
    else { ///< After 11 tries, we start averaging old/new mu values
      double epsi = 0.5;
      if (numTries > 20) epsi = 0.2;
      if (numTries > 30) epsi = 0.1;
      rewsb(sgnMu, mtrun, pars, oldMu, epsi);    
      } 

    oldMu = displaySusyMu();

    fracDiff = sumTol(*this, old, numTries);    
    
    if (numTries !=0 && fracDiff < tol) {///< Accuracy achieved: bail out
      numTries = 0; ///< Reset the number of iterations for the next time
      if (PRINTOUT > 0) cout << " sT=" << fracDiff << " " << flush; 
      if (displayProblem().test() && PRINTOUT > 0) 
	cout << " ***problem point***: " << displayProblem() << ".";

      return; 
    }

    // All problems should be reset since only the ones of the final iteration
    // should count (sometimes problems disappear). This can mean that problems
    // only show up as no rho convergence....
    tachyonType nil(none);
    flagAllProblems(false, nil);

    /// Old iteration is 'old': these are the parameters by which convergence is
    /// measured. 
    old.setDrBarPars(displayDrBarPars());
    /// If a print out is desired, print respectively, the difference with the
    /// last iteration (sum tol or sT), the mu parameter and m3^2 from EWSB, and
    /// the predicted MW and MZ boson masses
    if (PRINTOUT > 0) {
      cout << "\n" << numTries << ". sT=" << fracDiff << " mu=" 
	   << displaySusyMu() <<  " m3sq=" <<
	displayM3Squared() << " MWp=" << displayMw() << " Mzp=" 
	   << sqrt(displayPredMzSq()) << flush;
    }

    if (problem.noMuConvergence) {
      if (PRINTOUT) 
	cout << "itLowsoft doesn't break EWSB\n"; 
      if (PRINTOUT > 1) printObj();
    }
    
    // IWKIM
    err = runto_low(mz, eps);    
    // END IWKIM
    // old // err = runto(mz, eps);
    if (err) {
      /// problem with running: bail out 
      flagProblemThrown(true);
      if (PRINTOUT) cout << "itLowsoft gone non-perturbative on way to MZ\n"; 
      if (PRINTOUT > 1) printObj();
      ///    old = MssmSoftsusy();
      numTries = 0;
      return;
    }
    
    // IWKIM
    itLowsoftTwoScale(maxTries, 
		      mx, mThreshold, sgnMu, tol, tanb, 
		      bcUV, bcThresholdUp, bcThresholdDown, 
		      pars, gaugeUnification);
    // END IWKIM

    // old // itLowsoft(maxTries, mx, sgnMu, tol, tanb, boundaryCondition, pars, 
	//      gaugeUnification, ewsbBCscale);
  }
  catch(const char *a) {
    numTries = 0;
    throw a;
  }
  catch(const string &a) {
    numTries = 0;
    throw a;
  }
}
