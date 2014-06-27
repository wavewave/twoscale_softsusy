
/** 
   Project:     SOFTSUSY 
   File:        main.cpp
   Author:      Ben Allanach 
   Manual:      B.C. Allanach,hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
                B.C. Allanach, M.A. Bernhardt, arXiv:0903.1805, Comp. Phys. 
		Commun. 181 (2010) 232-245
   Webpage:     http://allanach.home.cern.ch/allanach/softsusy.html
   Description: main calling program example: performs a scan of tan beta 
   (starting at CMSSM10.1.1) and prints out Higgs masses as a result in
   the format
       <tan beta>      <mh0>     <mA0>    <mH0>     <mH+/->
*/

#include <iostream>
#include "mycomplex.h"
#include "def.h"
#include "linalg.h"
#include "lowe.h"
#include "rge.h"
#include "softsusy.h"
#include "softpars.h"
#include "susy.h"
#include "utils.h"
#include "numerics.h"


void RGRUN( ofstream& rgefile, MssmSoftsusy& m , 
	    double log10startscale,
	    double log10threshold,  
	    double log10endscale, 
	    const DoubleVector & pars, 
	    int number ) 
{
  double scale ; 
  double step1, step2; 
  step1 = ( log10threshold - log10startscale) / number; 
  step2 = ( log10endscale  - log10threshold ) / number;
  m.runto_low( pow( 10, log10startscale )  ) ; 
  for( int i = 0 ; i < number ; i++ ) { 
    scale = pow( 10, log10startscale + step1*i) ; 
    m.runto_low( scale) ; 
    DoubleMatrix mQlmat = m.displaySoftMassSquared(mQl); 
    DoubleMatrix mUrmat = m.displaySoftMassSquared(mUr); 
    DoubleMatrix mDrmat = m.displaySoftMassSquared(mDr); 
    DoubleMatrix mLlmat = m.displaySoftMassSquared(mLl); 
    DoubleMatrix mErmat = m.displaySoftMassSquared(mEr); 

    double At = m.displaySoftA( UA,  3, 3 ) ;
    double Ab = m.displaySoftA( DA,  3, 3 ) ; 
    double Atau = m.displaySoftA( EA, 3, 3 ) ;

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
	    << " " << At 
	    << " " << Ab 
	    << " " << Atau
	    << " " << m.displayYukawaElement(YU,3,3)
	    << " " << m.displayYukawaElement(YD,3,3)
	    << " " << m.displayYukawaElement(YE,3,3)
	    << endl ;
  }

  deflectedmirageBcsThresholdUp( m , pars ); 


  for( int i = 0 ; i < number ; i++ ) { 
    scale = pow( 10, log10threshold + step2*i) ; 
    m.runto_high( scale) ; 
    DoubleMatrix mQlmat = m.displaySoftMassSquared(mQl); 
    DoubleMatrix mUrmat = m.displaySoftMassSquared(mUr); 
    DoubleMatrix mDrmat = m.displaySoftMassSquared(mDr); 
    DoubleMatrix mLlmat = m.displaySoftMassSquared(mLl); 
    DoubleMatrix mErmat = m.displaySoftMassSquared(mEr); 

    double At = m.displaySoftA( UA,  3, 3 ) ;
    double Ab = m.displaySoftA( DA,  3, 3 ) ; 
    double Atau = m.displaySoftA( EA, 3, 3 ) ;

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
	    << " " << At 
	    << " " << Ab 
	    << " " << Atau
	    << " " << m.displayYukawaElement(YU,3,3)
	    << " " << m.displayYukawaElement(YD,3,3)
	    << " " << m.displayYukawaElement(YE,3,3)
	    << endl ;
  }
}

int main() {
  /// Sets up exception handling
  signal(SIGFPE, FPE_ExceptionHandler); 

  try {
 /// Sets format of output: 6 decimal places
  outputCharacteristics(6);

  cerr << "SOFTSUSY" << SOFTSUSY_VERSION 
       << " test program, Ben Allanach 2002\n";
  cerr << "If you use SOFTSUSY, please refer to B.C. Allanach,\n";
  cerr << "Comput. Phys. Commun. 143 (2002) 305, hep-ph/0104145\n";

  /// Parameters used: CMSSM parameters
  double m12 = 500., a0 = 0., mGutGuess = 2.0e16, tanb = 10.0, m0 = 125.;
  int sgnMu = 1;      ///< sign of mu parameter 
  int numPoints = 10; ///< number of scan points

  QedQcd oneset;      ///< See "lowe.h" for default definitions parameters

  /// most important Standard Model inputs: you may change these and recompile
  double alphasMZ = 0.1187, mtop = 173.5, mbmb = 4.18;
  oneset.setAlpha(ALPHAS, alphasMZ);
  oneset.setPoleMt(mtop);
  oneset.setMbMb(mbmb);

  oneset.toMz();      ///< Runs SM fermion masses to MZ

  /// Print out the SM data being used, as well as quark mixing assumption and
  /// the numerical accuracy of the solution
  cout << "# Low energy data in SOFTSUSY: MIXING=" << MIXING << " TOLERANCE=" 
       << TOLERANCE << endl << oneset << endl;

  /// Print out header line
  cout << "# tan beta   mh           mA           mH0          mH+-\n";

  int i; 
  /// Set limits of tan beta scan
  double startTanb = 3.0, endTanb = 50.0;

  double alpha_m, alpha_g, M0 ; 

  alpha_m = 1.0; 
  alpha_g = 0.5 ;
  M0 = 2000; 

  dmm_discrete_param.N5pair = 1 ;
  dmm_discrete_param.nHu = 1.0 ;
  dmm_discrete_param.nHd = 1.0 ; 
  dmm_discrete_param.nQ  = 0.5 ;
  dmm_discrete_param.nU  = 0.5 ; 
  dmm_discrete_param.nD  = 0.5 ;
  dmm_discrete_param.nL  = 0.5 ; 
  dmm_discrete_param.nE  = 0.5 ;

  N5pair = dmm_discrete_param.N5pair ; 
  N10pair = 0 ; 
  N24 = 0; 

  tanb = 20  ; 
  /// Preparation for calculation: set up object and input parameters
  MssmSoftsusy r; 
  DoubleVector pars(3); 
  pars(1) = alpha_m; pars(2) = alpha_g; pars(3) = M0;
  bool uni = true; // MGUT defined by g1(MGUT)=g2(MGUT)
  


  /// Calculate the spectrum
  //    r.lowOrg(sugraBcs, mGutGuess, pars, sgnMu, tanb, oneset, uni);
  r.lowOrgTwoScale( deflectedmirageBcsUV, 
		    deflectedmirageBcsThresholdUp, 
		    deflectedmirageBcsThresholdDown, 
		    2e16, 1e4, 
		    pars, sgnMu, tanb, oneset, uni );  
  
  
  cout << r.displayPhys() << endl; 

  ofstream rgefile ; 
  rgefile.open("rgefile.dat"); 

  RGRUN( rgefile ,  r, 2, 4 , 16, pars, 100 ) ;

  rgefile.close(); 

  /// check the point in question is problem free: if so print the output
  /*  if (!r.displayProblem().test()) 
    cout << tanb << " " << r.displayPhys().mhiggs.display(1) << " " 
	 << r.displayPhys().mhiggs.display(2) << " " 
	 << r.displayPhys().mhiggs.display(3) << " " 
	 << r.displayPhys().mhiggs.display(4) << endl;
  else
    /// print out what the problem(s) is(are)
    cout << tanb << " " << r.displayProblem() << endl; */
 
  }
  catch(const string & a) { cout << a; }
  catch(const char * a) { cout << a; }
  catch(...) { cout << "Unknown type of exception caught.\n"; }

  exit(0);
}
