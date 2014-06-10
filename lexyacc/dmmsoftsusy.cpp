
/** 
   Project:     SOFTSUSY 3.0
   File:        main.cpp
   Author:      Ben Allanach 
   Manual:      B.C. Allanach,hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
   Webpage:     http://allanach.home.cern.ch/allanach/softsusy.html
   Description: main calling program example: performs a scan of tan beta 
   (starting at mSUGRA point SPS1a) and prints out Higgs masses as a result in
   the format
       <tan beta>      <mh0>     <mA0>    <mH0>     <mH+/->
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>

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

#include "micromegas.h"
#include "pmodel.h"

extern "C"
{
  #include "action.h"
  #include "dmmyacc.tab.h"
}


/// global variable declaration
/// no quark mixing (dominant third family approx), and no verbose output
int MIXING = 0, PRINTOUT = 0;
/// fractional accuracy required
double TOLERANCE = 1.0e-3;
/// decay constant of muon
double GMU = 1.16637e-5; 
/// there are two possible conventions: if QEWSB > MZ, its value is assumed
/// in GeV and used as a constant MSUSY. Otherwise, it MULTIPLIES the usual 
/// MSUSY value, of root(mstop1 mstop2)
double QEWSB = 1.0; 
/// Do we include 2-loop RGEs of *all* scalar masses and A-terms, or only the
/// scalar mass Higgs parameters? (Other quantities all 2-loop anyway): the
/// default in SOFTSUSY 3 is to include all 2-loop terms
bool INCLUDE_2_LOOP_SCALAR_CORRECTIONS = true;
/// number of loops used to calculate Higgs ass and tadpoles. They should be
/// identical for a consistent calculation
int numHiggsMassLoops = 2, numRewsbLoops = 2;
/// global pole mass of MZ in GeV - MZCENT is defined in def.h
double MZ = MZCENT;
/// end of global variable declaration

struct param_set { 
  double alpha_m; 
  double alpha_g; 
  double M0; 
  double Mmess ;
  double tanb ;
  int    sgnMu; 
  
  int N5pair, N10pair, N24 ; 
  double nHu, nHd ;
  double nQ, nU, nD, nL, nE ; 

} ; 


double get_value( int index ) 
{
  if( typevar[index] == PairType ) {
    return valuelist[index].pair.value; 
  }
  else if( typevar[index] == TripleType ) {
    return valuelist[index].triple.value; 
  }
  else 
    return valuelist[index].real;

}

void insert_value_to_param( param_set& param ) 
{

  param.alpha_m = get_value ( C_ALPHAM ); 
  param.alpha_g = get_value ( C_ALPHAG );
  param.M0      = get_value ( C_M0     ); 
  param.Mmess   = get_value ( C_MMESS  ); 
  param.tanb    = get_value ( C_TANB   ); 

  param.sgnMu   = valuelist[C_SGNMU].integer; 

  param.N5pair = valuelist[C_N5].integer ;
  param.N10pair = valuelist[C_N10].integer ;
  param.N24 = valuelist[C_N24].integer ; 

  param.nHu = valuelist[C_NHU].real;
  param.nHd = valuelist[C_NHD].real    ; 
  param.nQ  = valuelist[C_NQ].real    ;
  param.nU  = valuelist[C_NU].real    ; 
  param.nD  = valuelist[C_ND].real ;
  param.nL  = valuelist[C_NL].real ; 
  param.nE  = valuelist[C_NE].real ;

}

double generate_random( double from, double to )
{
  double r ; 
  r = ((double)rand()) / ((double)RAND_MAX) * (to-from) + from; 
  cout << " from = " << from << endl; 
  cout << " to = " << to << endl; 
  cout << " r=  " << r << endl; 
  return r ;
}
double generate_lograndom( double from , double to ) 
{
  double logfrom, logto ;
  double logr ;
  logfrom = log(from); 
  logto = log(to); 
  logr = ((double)rand()) / ((double)RAND_MAX) * (logto-logfrom) + logfrom ; 
  return exp(logr) ; 
}




void print_param( param_set& param ) 
{
  cout << "alpha_m = " << param.alpha_m << endl;
  cout << "alpha_g = " << param.alpha_g << endl; 
  cout << "M0      = " << param.M0      << endl; 
  cout << "Mmess   = " << param.Mmess   << endl; 
  cout << "tanb    = " << param.tanb    << endl; 

}

int generate_single_random_set( param_set& param ) 
{
  for( int i = 0 ; i < numpair ; i++ ) { 
    int paramindex = pairlist[i] ; 
    double from = valuelist[paramindex].pair.first; 
    double to   = valuelist[paramindex].pair.second; 
 
    if( paramindex != C_MMESS ) { 
      valuelist[paramindex].pair.value = generate_random( from, to ); 
    }
    else 
      valuelist[paramindex].pair.value = generate_lograndom( from, to ); 
  }

  insert_value_to_param( param ) ; 

}




void initialize_lattice_set( param_set& param ) 
{
  for( int i = 0 ; i < numtriple ; i++ ) { 
    int paramindex = triplelist[i] ; 
    valuelist[paramindex].triple.value = valuelist[paramindex].triple.first; 
  }

  insert_value_to_param( param ) ; 

}

bool generate_next_lattice_set( param_set& param ) 
{
  for( int i = 0 ; i < numtriple ; i++ ) { 
    int paramindex = triplelist[i] ; 
    double currentvalue = valuelist[paramindex].triple.value; 
    double from = valuelist[paramindex].triple.first ; 
    double to   = valuelist[paramindex].triple.second; 
    double inc  = valuelist[paramindex].triple.third ; 

    if( paramindex != C_MMESS ) { 

      if( currentvalue + inc <= to ) {
	valuelist[paramindex].triple.value = currentvalue + inc; 
	insert_value_to_param( param ) ; 
	return false; 
      }
      else 
	valuelist[paramindex].triple.value = from ;
    }
    else { // for M_mess, we multiply incremental. 
      if( currentvalue * inc <= to ) {
	valuelist[C_MMESS].triple.value = currentvalue * inc; 
	insert_value_to_param( param ) ; 
	return false; 
      }
      else 
	valuelist[C_MMESS].triple.value = from ;
      
    }


  }
  insert_value_to_param( param ) ; 
  return true; 

}


bool checkNAN( MssmSoftsusy& m ) 
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
		     
void scanrecord( ofstream& spectrumfile, param_set& param, MssmSoftsusy& m,
		 double bsg_value, double gmuon_value, 
		 double bsmumu_value, double Omega, string mess )  
{
  sPhysical p = m.displayPhys() ;

  spectrumfile << " " << param.alpha_m 
	       << " " << param.alpha_g
	       << " " << param.M0
	       << " " << param.Mmess
	       << " " << param.tanb
	       << " " << param.sgnMu
	       << " " << param.N5pair
	       << " " << param.N10pair
	       << " " << param.N24
	       << " " << param.nHu
	       << " " << param.nHd
	       << " " << param.nQ
	       << " " << param.nU
	       << " " << param.nD
	       << " " << param.nL
	       << " " << param.nE
	       << " " << p.mhiggs(1)
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
	       << " " << bsg_value 
	       << " " << gmuon_value 
	       << " " << bsmumu_value
	       << " " << Omega
               << " " << m.displayProblem().test() 
	       << " " << mess
    //////////Yongyan change//////////
	       << " " << p.mixNeut(1,1)
	       << " " << p.mixNeut(2,1)
	       << " " << p.mixNeut(3,1)
	       << " " << p.mixNeut(4,1)
	       << " " << p.mixNeut(1,2)
	       << " " << p.mixNeut(2,2)
	       << " " << p.mixNeut(3,2)
	       << " " << p.mixNeut(4,2)
    //////////Yongyan change//////////
	       << endl ; 

	spectrumfile << flush ;

}


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

int enterMicrOmegas( QedQcd& q, MssmSoftsusy& m, param_set& param ) 
{
  sPhysical p = m.displayPhys() ; 
  

 
  assignVal( "alfEMZ" ,  q.displayAlpha(ALPHA) ) ;
  assignVal( "alfSMZ" ,  q.displayAlpha(ALPHAS) ) ; 

  assignVal( "Q" ,  m.displayMu() ); 


  assignVal( "MH3" , p.mhiggs(2) ); 
  assignVal( "Mh"  , p.mhiggs(1) );
  assignVal( "MHH" , p.mhiggs(3) );
  assignVal( "MHc" , p.mhiggs(4) ); 

  assignVal( "tb",   param.tanb );
  assignVal( "alpha" , p.thetaH ); 
  assignVal( "mu",  m.displaySusyMu() ); 

  assignVal( "Au", m.displaySoftA( UA, 2,2 ) ); 
  assignVal( "Ad", m.displaySoftA( DA, 2,2 ) ); 

  assignVal( "Am", m.displaySoftA( EA, 2,2 ) ); 
  assignVal( "Al", m.displaySoftA( EA, 3,3 ) ); 
  assignVal( "Ab", m.displaySoftA( DA, 3,3 ) ); 
  assignVal( "At", m.displaySoftA( UA, 3,3 ) ) ; 


  assignVal( "MNE1" , p.mneut(1) ); 
  assignVal( "MNE2" , p.mneut(2) ); 
  assignVal( "MNE3" , p.mneut(3) ); 
  assignVal( "MNE4" , p.mneut(4) ); 

  assignVal( "MC1"  , p.mch(1) ); 
  assignVal( "MC2"  , p.mch(2) );

  assignVal( "MSG"  , p.mGluino ); 

  assignVal( "MSne" , p.msnu(1) ); 
  assignVal( "MSnm" , p.msnu(2) ); 
  assignVal( "MSnl" , p.msnu(3) ); 

  assignVal( "MSeL" , p.me(1,1) );
  assignVal( "MSeR" , p.me(2,1) ); 
  assignVal( "MSmL" , p.me(1,2) );
  assignVal( "MSmR" , p.me(2,2) ); 
  assignVal( "MSl1" , p.me(1,3) > p.me(2,3) ? p.me(2,3) : p.me(1,3) );
  assignVal( "MSl2" , p.me(1,3) > p.me(2,3) ? p.me(1,3) : p.me(2,3) ); 

  assignVal( "MSuL" , p.mu(1,1) );
  assignVal( "MSuR" , p.mu(2,1) ); 
  assignVal( "MSsL" , p.md(1,2) );
  assignVal( "MSsR" , p.md(2,2) ); 
  assignVal( "MSt1" , p.mu(1,3) > p.mu(2,3) ? p.mu(2,3) : p.mu(1,3) );
  assignVal( "MSt2" , p.mu(1,3) > p.mu(2,3) ? p.mu(1,3) : p.mu(2,3) ); 
  assignVal( "MSdL" , p.md(1,1) );
  assignVal( "MSdR" , p.md(2,1) ); 
  assignVal( "MScL" , p.mu(1,2) );
  assignVal( "MScR" , p.mu(2,2) ); 
  assignVal( "MSb1" , p.md(1,3) > p.md(2,3) ? p.md(2,3) : p.md(1,3) );
  assignVal( "MSb2" , p.md(1,3) > p.md(2,3) ? p.md(1,3) : p.md(2,3) ); 

  assignVal( "Zn11" , p.mixNeut(1,1) ); 
  assignVal( "Zn21" , p.mixNeut(1,2) ); 
  assignVal( "Zn31" , p.mixNeut(1,3) ); 
  assignVal( "Zn41" , p.mixNeut(1,4) ); 

  assignVal( "Zn12" , p.mixNeut(2,1) ); 
  assignVal( "Zn22" , p.mixNeut(2,2) ); 
  assignVal( "Zn32" , p.mixNeut(2,3) ); 
  assignVal( "Zn42" , p.mixNeut(2,4) ); 

  assignVal( "Zn13" , p.mixNeut(3,1) ); 
  assignVal( "Zn23" , p.mixNeut(3,2) ); 
  assignVal( "Zn33" , p.mixNeut(3,3) ); 
  assignVal( "Zn43" , p.mixNeut(3,4) ); 

  assignVal( "Zn14" , p.mixNeut(4,1) ); 
  assignVal( "Zn24" , p.mixNeut(4,2) ); 
  assignVal( "Zn34" , p.mixNeut(4,3) ); 
  assignVal( "Zn44" , p.mixNeut(4,4) ); 
  
  assignVal( "Zu11" , cos( p.thetaL ) ) ; 
  assignVal( "Zu21" ,-sin( p.thetaL ) ) ;
  assignVal( "Zu12" , sin( p.thetaL ) ) ; 
  assignVal( "Zu22" , cos( p.thetaL ) ) ; 

  assignVal( "Zv11" , cos( p.thetaR ) ) ; 
  assignVal( "Zv21" ,-sin( p.thetaR ) ) ;
  assignVal( "Zv12" , sin( p.thetaR ) ) ; 
  assignVal( "Zv22" , cos( p.thetaR ) ) ; 

  assignVal( "Zl11" ,-sin( p.thetatau ) ) ; 
  assignVal( "Zl21" ,-cos( p.thetatau ) ) ;
  assignVal( "Zl12" , cos( p.thetatau ) ) ; 
  assignVal( "Zl22" ,-sin( p.thetatau ) ) ; 

  assignVal( "Zt11" ,-sin( p.thetat ) ) ; 
  assignVal( "Zt21" ,-cos( p.thetat ) ) ;
  assignVal( "Zt12" , cos( p.thetat ) ) ; 
  assignVal( "Zt22" ,-sin( p.thetat ) ) ; 

  assignVal( "Zb11" , cos( p.thetab ) ) ; 
  assignVal( "Zb21" ,-sin( p.thetab ) ) ;
  assignVal( "Zb12" , sin( p.thetab ) ) ; 
  assignVal( "Zb22" , cos( p.thetab ) ) ; 

  assignVal( "MG1"  , m.displayGaugino(1) ); 
  assignVal( "MG2"  , m.displayGaugino(2) ); 
  assignVal( "MG3"  , m.displayGaugino(3) ); 

  double dmb, dms, dmd ; 
  
  dmb = deltaMb() ; 
  dms = deltaMs() ; 
  dmd = deltaMd() ; 
  
  if( dmb != dmb )
    return IFAIL; 
  if( dms != dms ) 
    return IFAIL; 
  if( dmd != dmd ) 
    return IFAIL; 

  assignValW("dMb",dmb);
  assignValW("dMs",dms);
  assignValW("dMd",dmd);


  return ISUCCESS;
}



int main( int argc, char** argv) {
 /// Sets format of output: 6 decimal places
  char* infilename; 
  char* outfilename; 
  outputCharacteristics(6);

  cerr << "SOFTSUSY" << SOFTSUSY_VERSION 
       << " test program, Ben Allanach 2002\n";
  cerr << "If you use SOFTSUSY, please refer to B.C. Allanach,\n";
  cerr << "Comput. Phys. Commun. 143 (2002) 305, hep-ph/0104145\n";
  cerr << "B.C. Allanach and M. Bernhardt, arxiv:0903.1805 [hep-ph]\n\n";


  if( argc != 3 ) {
    cerr << "Usage: dmmsoftsusy inputfile outputfile " << endl; 
    exit(-1); 
  }
  
  infilename  = argv[1]; 
  outfilename = argv[2]; 


  QedQcd oneset;      ///< See "lowe.h" for default definitions parameters

  /// most important Standard Model inputs: you may change these and recompile
  double alphasMZ = ALPHASMZ, mtop = 171.3, mbmb =MBOTTOM;
  double mtau = MTAU; 
  oneset.setAlpha(ALPHAS, alphasMZ);
  oneset.setPoleMt(mtop);
  oneset.setMass(mBottom, mbmb);

  oneset.toMz();      ///< Runs SM fermion masses to MZ

  /// Print out the SM data being used, as well as quark mixing assumption and
  /// the numerical accuracy of the solution
  cout << "# Low energy data in SOFTSUSY: MIXING=" << MIXING << " TOLERANCE=" 
       << TOLERANCE << endl << oneset << endl;


  int i; 
  /// Set limits of tan beta scan
  double startTanb = 3.0, endTanb = 50.0;
  /// Cycle through different points in the scan



  ifstream infile( infilename ); 

  cout << "starting reading input file " << endl; 

  FILE* savestdin = stdin; 
  stdin = fopen( infilename , "r" ); 

  if( yaccmain() == IFAIL ) {
    cout << " Wrong input file ! " << endl; 
    return -1; 
  }
  fclose(stdin);
  stdin = savestdin; 
 

  cout << "successfully read input file. " << endl; 

  if( valuelist[C_METHOD].method == SingleMethod ) { 

    cout << "Single is chosen!" << endl; 

    double tanb; 
    double alpha_m, alpha_g, M0, Mmess ; 
    int sgnMu ; 

    alpha_m = valuelist[C_ALPHAM].real; 
    alpha_g = valuelist[C_ALPHAG].real ;
    M0      = valuelist[C_M0].real; 
    Mmess   = valuelist[C_MMESS].real; 
    sgnMu   = valuelist[C_SGNMU].integer; 


    dmm_discrete_param.N5pair = valuelist[C_N5].integer ;
    dmm_discrete_param.nHu = valuelist[C_NHU].real;
    dmm_discrete_param.nHd = valuelist[C_NHD].real    ; 
    dmm_discrete_param.nQ  = valuelist[C_NQ].real    ;
    dmm_discrete_param.nU  = valuelist[C_NU].real    ; 
    dmm_discrete_param.nD  = valuelist[C_ND].real ;
    dmm_discrete_param.nL  = valuelist[C_NL].real ; 
    dmm_discrete_param.nE  = valuelist[C_NE].real ;
    
    N5pair = dmm_discrete_param.N5pair ; 
    N10pair = valuelist[C_N10].integer ; 
    N24 = valuelist[C_N24].integer; 
    
    tanb = valuelist[C_TANB].real  ; 

    /// Preparation for calculation: set up object and input parameters
    MssmSoftsusy r; 
    DoubleVector pars(3); 
    pars(1) = alpha_m; pars(2) = alpha_g; pars(3) = M0;
    bool uni = true; // MGUT defined by g1(MGUT)=g2(MGUT)
    
    /// Calculate the spectrum
    r.lowOrgTwoScale( deflectedmirageBcsUV, 
		      deflectedmirageBcsThresholdUp, 
		      deflectedmirageBcsThresholdDown, 
		      2e16, Mmess, 
		      pars, sgnMu, tanb, oneset, uni );  
    
    
    cout << r.displayPhys() << endl; 

    ofstream spectrumfile ; 
    spectrumfile.open(outfilename); 

    spectrumrecord( spectrumfile, r ); 

    spectrumfile.close(); 





  }
  else if( valuelist[C_METHOD].method == RGRunMethod ) { 

    cout << "RGRun is chosen!" << endl; 
    
    double tanb; 
    double alpha_m, alpha_g, M0, Mmess ; 
    int sgnMu ; 
    
    alpha_m = valuelist[C_ALPHAM].real; 
    alpha_g = valuelist[C_ALPHAG].real ;
    M0      = valuelist[C_M0].real; 
    Mmess   = valuelist[C_MMESS].real; 
    sgnMu   = valuelist[C_SGNMU].integer; 


    dmm_discrete_param.N5pair = valuelist[C_N5].integer ;
    dmm_discrete_param.nHu = valuelist[C_NHU].real;
    dmm_discrete_param.nHd = valuelist[C_NHD].real    ; 
    dmm_discrete_param.nQ  = valuelist[C_NQ].real    ;
    dmm_discrete_param.nU  = valuelist[C_NU].real    ; 
    dmm_discrete_param.nD  = valuelist[C_ND].real ;
    dmm_discrete_param.nL  = valuelist[C_NL].real ; 
    dmm_discrete_param.nE  = valuelist[C_NE].real ;
    
    N5pair = dmm_discrete_param.N5pair ; 
    N10pair = valuelist[C_N10].integer ; 
    N24 = valuelist[C_N24].integer; 
    
    tanb = valuelist[C_TANB].real  ; 

    /// Preparation for calculation: set up object and input parameters
    MssmSoftsusy r; 
    DoubleVector pars(3); 
    pars(1) = alpha_m; pars(2) = alpha_g; pars(3) = M0;
    bool uni = true; // MGUT defined by g1(MGUT)=g2(MGUT)
    
    /// Calculate the spectrum
    r.lowOrgTwoScale( deflectedmirageBcsUV, 
		      deflectedmirageBcsThresholdUp, 
		      deflectedmirageBcsThresholdDown, 
		      2e16, Mmess, 
		      pars, sgnMu, tanb, oneset, uni );  
    
    //    cout << r.displayPhys() << endl; 

    ofstream rgefile ; 
    rgefile.open(outfilename); 
    
    RGRUN( rgefile ,  r, 2, log(Mmess) / log(10.0) , 16, pars, 100 ) ;
    
    rgefile.close();  
    
  }
  else if(  valuelist[C_METHOD].method == ScanMethod  &&
	    valuelist[C_SCANMETHOD].scan == RandomScan ) {
    cout << "Scan:Random is chosen!" << endl; 
    cout << " Number of shots : " << valuelist[C_SHOTS].integer << endl ; 
    
    
    ofstream scanfile ; 
    scanfile.open(outfilename); 
    
    
    for( int i = 0; i < valuelist[C_SHOTS].integer ; i++ ) {
      param_set param ; 
      
      generate_single_random_set( param ); 
      
      
      dmm_discrete_param.N5pair = param.N5pair ;
      dmm_discrete_param.nHu = param.nHu;
      dmm_discrete_param.nHd = param.nHd; 
      dmm_discrete_param.nQ  = param.nQ;
      dmm_discrete_param.nU  = param.nU; 
      dmm_discrete_param.nD  = param.nD;
      dmm_discrete_param.nL  = param.nL; 
      dmm_discrete_param.nE  = param.nE;
      
      N5pair = dmm_discrete_param.N5pair ; 
      N10pair = param.N10pair ; 
      N24 = param.N24; 
      
      cout << i << " th set : " << endl; 
      print_param( param );
      
      /// Preparation for calculation: set up object and input parameters
      MssmSoftsusy r; 
      DoubleVector pars(3); 
      pars(1) = param.alpha_m; pars(2) = param.alpha_g; pars(3) = param.M0;
      bool uni = true; // MGUT defined by g1(MGUT)=g2(MGUT)
      
      /// Calculate the spectrum
      double MGUTSCALE = r.lowOrgTwoScale( deflectedmirageBcsUV, 
					   deflectedmirageBcsThresholdUp, 
					   deflectedmirageBcsThresholdDown, 
					   2e16, param.Mmess, 
					   pars, param.sgnMu, param.tanb, oneset, uni );  
      

      cout << oneset << endl; 
      cout << r.displayPhys() << endl; 


      
      //ofstream tempfile("LesHouches.dat"); 
    
      //       r.lesHouchesAccordOutput(tempfile, "amsb", pars, 
      //			       param.sgnMu, param.tanb,
      //		       100000. , 1,  MGUTSCALE , 
      //			       oneset,
      //		       false ) ; 
      //tempfile << flush; 
      
      //cout << "------------------------------" << endl; 
      //sleep(1); 
      //      cout << flush; 
      //      cout.rdbuf(strm_buffer); 
      //      tempfile.close(); 
      //      tempfile.close(); 

      cout << "enterMircOmegas" << endl; 
      int fMicro = enterMicrOmegas( oneset, r, param ); 


      if( checkNAN( r ) ) { 

		
	//////////////////////////////////////////////////
	//                micrOmegas                    //
	//////////////////////////////////////////////////
	
	double Xf=0, Omega=0, Omega2=0, bsg_value=0,
	  bsmumu_value=0, gmuon_value=0; 
	string mess; 
	double mtop ;
	
	int err ; 
	int fast = 1; 
	double Beps = 1E-6 ; 
	
	double cut = 0.01; 
	


	//
	///printVar(stdout); 
	//

	//	cout << "LesHouches" << endl; 
	//	err = readLesH("LesHouches.dat",1); 
	
	//
	//	printVar(stdout); 
	//



	char messtemp[20]; 
	
	err=sortOddParticles(messtemp);
	mess = messtemp; 
	
	//	HiggsMasses(stdout);     
	//	printMasses(stdout,1);
	
	Omega = 0;
        bsg_value = 0; 
	bsmumu_value = 0; 
	gmuon_value = 0; 
      
        if( fMicro == ISUCCESS ) {

   	  if(valuelist[C_OMEGA].integer == 1) {
	    Omega=darkOmega(&Xf,fast,Beps);
	    cout << "Omega h^2 = " << Omega << endl; 
  	  }
	
	//	o1Contents(stdout);
	//	printChannels(Xf,cut,Beps,1,stdout); 
	  bsg_value= bsgnlo_(); 
	  bsmumu_value = bsmumu_(); 
	  gmuon_value = gmuon_(); 
	}

	scanrecord( scanfile, param, r, 
		    bsg_value, gmuon_value, bsmumu_value, Omega, mess ) ; 
	
      }
      else {
	scanrecord( scanfile, param, r, 
		    0, 0, 0, 0, "" ) ; 

      }
      
    }
    scanfile.close(); 
  }
  else if(  valuelist[C_METHOD].method == ScanMethod  &&
	    valuelist[C_SCANMETHOD].scan == LatticeScan ) {
    cout << "Scan:Lattice is chosen!" << endl; 

    ofstream scanfile ; 
    scanfile.open(outfilename); 
    
    param_set param ; 
    int count = 0; 

    initialize_lattice_set( param) ; 
    
    do { 
      cout << count << " th set : " << endl; 
      count ++ ; 
      cout << "-------------------------------" << endl; 
      print_param( param ); 
      cout << "-------------------------------" << endl; 


      dmm_discrete_param.N5pair = param.N5pair ;
      dmm_discrete_param.nHu = param.nHu;
      dmm_discrete_param.nHd = param.nHd; 
      dmm_discrete_param.nQ  = param.nQ;
      dmm_discrete_param.nU  = param.nU; 
      dmm_discrete_param.nD  = param.nD;
      dmm_discrete_param.nL  = param.nL; 
      dmm_discrete_param.nE  = param.nE;
      
      N5pair = dmm_discrete_param.N5pair ; 
      N10pair = param.N10pair ; 
      N24 = param.N24; 

      
      /// Preparation for calculation: set up object and input parameters
      MssmSoftsusy r; 
      DoubleVector pars(3); 
      pars(1) = param.alpha_m; pars(2) = param.alpha_g; pars(3) = param.M0;
      bool uni = true; // MGUT defined by g1(MGUT)=g2(MGUT)
      
      /// Calculate the spectrum
      double MGUTSCALE = r.lowOrgTwoScale( deflectedmirageBcsUV, 
					   deflectedmirageBcsThresholdUp, 
					   deflectedmirageBcsThresholdDown, 
					   2e16, param.Mmess, 
					   pars, param.sgnMu, param.tanb, oneset, uni );  
      

      cout << oneset << endl; 
      cout << r.displayPhys() << endl; 


      
      //ofstream tempfile("LesHouches.dat"); 
    
      //       r.lesHouchesAccordOutput(tempfile, "amsb", pars, 
      //			       param.sgnMu, param.tanb,
      //		       100000. , 1,  MGUTSCALE , 
      //			       oneset,
      //		       false ) ; 
      //tempfile << flush; 
      
      //cout << "------------------------------" << endl; 
      //sleep(1); 
      //      cout << flush; 
      //      cout.rdbuf(strm_buffer); 
      //      tempfile.close(); 
      //      tempfile.close(); 

      cout << "enterMircOmegas" << endl; 
      int fMicro = enterMicrOmegas( oneset, r, param ); 


      if( checkNAN( r ) ) { 

		
	//////////////////////////////////////////////////
	//                micrOmegas                    //
	//////////////////////////////////////////////////
	
	double Xf=0, Omega=0, Omega2=0, bsg_value=0,
	  bsmumu_value=0, gmuon_value=0; 
	string mess; 
	double mtop ;
	
	int err ; 
	int fast = 1; 
	double Beps = 1E-6 ; 
	
	double cut = 0.01; 
	


	//
	///printVar(stdout); 
	//

	//	cout << "LesHouches" << endl; 
	//	err = readLesH("LesHouches.dat",1); 
	
	//
	//	printVar(stdout); 
	//



	char messtemp[20]; 
	
	err=sortOddParticles(messtemp);
	mess = messtemp; 
	
	//	HiggsMasses(stdout);     
	//	printMasses(stdout,1);
	
	Omega = 0;
	bsg_value = 0 ; 
	bsmumu_value = 0; 
	gmuon_value = 0; 

	if( fMicro == ISUCCESS ) {

	  if(valuelist[C_OMEGA].integer == 1) {
	    Omega=darkOmega(&Xf,fast,Beps);
	    cout << "Omega h^2 = " << Omega << endl; 
	  }
	
	//	o1Contents(stdout);
	//	printChannels(Xf,cut,Beps,1,stdout); 
	  bsg_value= bsgnlo_(); 
	  bsmumu_value = bsmumu_(); 
	  gmuon_value = gmuon_(); 
	}
	scanrecord( scanfile, param, r, 
		    bsg_value, gmuon_value, bsmumu_value, Omega, mess ) ; 
	
      }
      else {
	scanrecord( scanfile, param, r, 
		    0, 0, 0, 0, "" ) ; 
      }
      
    } while( !generate_next_lattice_set( param ) );
    scanfile.close(); 
  }

  
  
  
  
  
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
