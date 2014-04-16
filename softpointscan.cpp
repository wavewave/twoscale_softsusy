#include <iostream>
#include <fstream>
#include <string> 

#include <softpoint.h>

#include "micromegas.h"
#include "pmodel.h"


#define MGUTSCALE 2e16

int numscan;

int l1, l2, l3 ; 
double nQ, nL, nU, nD, nE, nHu, nHd ; 
int N ; 

double global_g1 , global_g2 , global_g3 ;

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


void gaugegravityBcs0( MssmSoftsusy & m, 
		       const DoubleVector & inputParameters ) { 
  double M_moduli_local, M_gauge_local, M_mess_local ; 
  M_moduli_local = inputParameters.display(1) ;

  double m1, m2, m3 ; 


  m1 = l1 * M_moduli_local ; 
  m2 = l2 * M_moduli_local ;
  m3 = l3 * M_moduli_local ; 
  m.setGauginoMass( 1, m1 ) ; 
  m.setGauginoMass( 2, m2 ) ; 
  m.setGauginoMass( 3, m3 ) ;
  
  double mqlsq , mllsq, mursq, mdrsq, mersq ; 
  double mhusq , mhdsq; 
  double M_moduli_sqr_local; 
  M_moduli_sqr_local = M_moduli_local*M_moduli_local ;

  mqlsq = ( 1 - nQ ) * M_moduli_sqr_local ;
  mllsq = ( 1 - nL ) * M_moduli_sqr_local ; 
  mursq = ( 1 - nU ) * M_moduli_sqr_local ;
  mdrsq = ( 1 - nD ) * M_moduli_sqr_local ;
  mersq = ( 1 - nE ) * M_moduli_sqr_local ; 
  mhusq = ( 1 - nHu) * M_moduli_sqr_local ; 
  mhdsq = ( 1 - nHd) * M_moduli_sqr_local ; 

  DoubleMatrix id(3, 3);
  id(1, 1) = 1.0; id(2, 2) = 1.0; id(3, 3) = 1.0;

  m.setSoftMassMatrix(mQl, mqlsq * id);
  m.setSoftMassMatrix(mUr, mursq * id);
  m.setSoftMassMatrix(mDr, mdrsq * id);
  m.setSoftMassMatrix(mLl, mllsq * id);
  m.setSoftMassMatrix(mEr, mersq * id); 
  m.setMh1Squared(mhdsq);
  m.setMh2Squared(mhusq);


  double A_HuQU , A_HdQD, A_HdLE ; 

  A_HuQU = ( 3 - nHu - nQ - nU ) * M_moduli_local ;
  A_HdQD = ( 3 - nHd - nQ - nD ) * M_moduli_local ; 
  A_HdLE = ( 3 - nHd - nL - nE ) * M_moduli_local ; 

  m.setTrilinearElement(UA, 1, 1, m.displayYukawaElement(YU, 1, 1) * A_HuQU);
  m.setTrilinearElement(UA, 2, 2, m.displayYukawaElement(YU, 2, 2) * A_HuQU);
  m.setTrilinearElement(UA, 3, 3, m.displayYukawaElement(YU, 3, 3) * A_HuQU);
  m.setTrilinearElement(DA, 1, 1, m.displayYukawaElement(YD, 1, 1) * A_HdQD);
  m.setTrilinearElement(DA, 2, 2, m.displayYukawaElement(YD, 2, 2) * A_HdQD);
  m.setTrilinearElement(DA, 3, 3, m.displayYukawaElement(YD, 3, 3) * A_HdQD);
  m.setTrilinearElement(EA, 1, 1, m.displayYukawaElement(YE, 1, 1) * A_HdLE);
  m.setTrilinearElement(EA, 2, 2, m.displayYukawaElement(YE, 2, 2) * A_HdLE);
  m.setTrilinearElement(EA, 3, 3, m.displayYukawaElement(YE, 3, 3) * A_HdLE);

}

void gaugegravityBcs1( MssmSoftsusy & m, 
		       const DoubleVector & inputParameters ) { 
  double M_moduli_local, M_gauge_local, M_mess_local ; 
  M_moduli_local = inputParameters.display(1) ;

  double m1, m2, m3 ; 

  m.setGaugeCoupling( 1, global_g1 ); 
  m.setGaugeCoupling( 2, global_g2 ); 
  m.setGaugeCoupling( 3, global_g3 ); 

  m1 = l1 * M_moduli_local ; 
  m2 = l2 * M_moduli_local ;
  m3 = l3 * M_moduli_local ; 
  m.setGauginoMass( 1, m1 ) ; 
  m.setGauginoMass( 2, m2 ) ; 
  m.setGauginoMass( 3, m3 ) ;
  
  double mqlsq , mllsq, mursq, mdrsq, mersq ; 
  double mhusq , mhdsq; 
  double M_moduli_sqr_local; 
  M_moduli_sqr_local = M_moduli_local*M_moduli_local ;

  mqlsq = ( 1 - nQ ) * M_moduli_sqr_local ;
  mllsq = ( 1 - nL ) * M_moduli_sqr_local ; 
  mursq = ( 1 - nU ) * M_moduli_sqr_local ;
  mdrsq = ( 1 - nD ) * M_moduli_sqr_local ;
  mersq = ( 1 - nE ) * M_moduli_sqr_local ; 
  mhusq = ( 1 - nHu) * M_moduli_sqr_local ; 
  mhdsq = ( 1 - nHd) * M_moduli_sqr_local ; 

  DoubleMatrix id(3, 3);
  id(1, 1) = 1.0; id(2, 2) = 1.0; id(3, 3) = 1.0;

  m.setSoftMassMatrix(mQl, mqlsq * id);
  m.setSoftMassMatrix(mUr, mursq * id);
  m.setSoftMassMatrix(mDr, mdrsq * id);
  m.setSoftMassMatrix(mLl, mllsq * id);
  m.setSoftMassMatrix(mEr, mersq * id); 
  m.setMh1Squared(mhdsq);
  m.setMh2Squared(mhusq);


  double A_HuQU , A_HdQD, A_HdLE ; 

  A_HuQU = ( 3 - nHu - nQ - nU ) * M_moduli_local ;
  A_HdQD = ( 3 - nHd - nQ - nD ) * M_moduli_local ; 
  A_HdLE = ( 3 - nHd - nL - nE ) * M_moduli_local ; 

  m.setTrilinearElement(UA, 1, 1, m.displayYukawaElement(YU, 1, 1) * A_HuQU);
  m.setTrilinearElement(UA, 2, 2, m.displayYukawaElement(YU, 2, 2) * A_HuQU);
  m.setTrilinearElement(UA, 3, 3, m.displayYukawaElement(YU, 3, 3) * A_HuQU);
  m.setTrilinearElement(DA, 1, 1, m.displayYukawaElement(YD, 1, 1) * A_HdQD);
  m.setTrilinearElement(DA, 2, 2, m.displayYukawaElement(YD, 2, 2) * A_HdQD);
  m.setTrilinearElement(DA, 3, 3, m.displayYukawaElement(YD, 3, 3) * A_HdQD);
  m.setTrilinearElement(EA, 1, 1, m.displayYukawaElement(YE, 1, 1) * A_HdLE);
  m.setTrilinearElement(EA, 2, 2, m.displayYukawaElement(YE, 2, 2) * A_HdLE);
  m.setTrilinearElement(EA, 3, 3, m.displayYukawaElement(YE, 3, 3) * A_HdLE);

}

void gaugegravityBcs2( MssmSoftsusy & m, 
		       const DoubleVector & inputParameters ) { 
  double alpha1, alpha2 , alpha3 ; 
  alpha1 = sqr(m.displayGaugeCoupling(1)) / ( 4.0 * PI ) ; 
  alpha2 = sqr(m.displayGaugeCoupling(2)) / ( 4.0 * PI ) ; 
  alpha3 = sqr(m.displayGaugeCoupling(3)) / ( 4.0 * PI ) ; 

  double M_gauge_local ;
  M_gauge_local = inputParameters.display(2); 

  m.setGaugeCoupling( 1, global_g1 ); 
  m.setGaugeCoupling( 2, global_g2 ); 
  m.setGaugeCoupling( 3, global_g3 ); 

  
  double m1 , m2 , m3 ;

  m1 = inter_gaugino1 - N * alpha1 / (4.0*PI) * M_gauge_local ;
  m2 = inter_gaugino2 - N * alpha2 / (4.0*PI) * M_gauge_local ; 
  m3 = inter_gaugino3 - N * alpha3 / (4.0*PI) * M_gauge_local ; 

  m.setGauginoMass(1, m1) ;
  m.setGauginoMass(2, m2) ;
  m.setGauginoMass(3, m3) ;

  double mqlsq , mllsq, mursq, mdrsq, mersq ; 
  double mhusq , mhdsq; 
  double M_gauge_sqr_local; 
  M_gauge_sqr_local = sqr( M_gauge_local ) ;

  mursq = 2.0/sqr( 4.0 * PI )*N * M_gauge_sqr_local * 
    ( 4.0/3.0 * sqr(alpha3) + 0.6 * 4.0 / 9.0 * sqr(alpha1) ) ;
  mdrsq =  2.0/sqr( 4.0 * PI )*N * M_gauge_sqr_local * 
    ( 4.0/3.0 * sqr(alpha3) + 0.6 * 1.0 / 9.0 * sqr(alpha1) ) ;  
  mersq =  2.0/sqr( 4.0 * PI )*N * M_gauge_sqr_local * 
    ( 0.6 * sqr(alpha1) ) ;
  mqlsq =  2.0/sqr( 4.0 * PI )*N * M_gauge_sqr_local * 
    ( 4.0/3.0 * sqr(alpha3) + 0.75 * sqr(alpha2) + 0.6 /36.0 * sqr(alpha1)) ;
  mllsq = 2.0/sqr( 4.0 * PI )*N * M_gauge_sqr_local * 
    ( 0.75 * sqr(alpha2) + 0.6*0.25 * sqr(alpha1) ) ; 
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

  //  cout << "In gaugegravityBcs2" << endl; 
  //  cout << "gaugino(1) = " << inter_gaugino1 << " " << m1 << endl 
  //       << "gaugino(2) = " << inter_gaugino2 << " " << m2 << endl 
  //       << "gaugino(3) = " << inter_gaugino3 << " " << m3 << endl; 
  //  cout << "inter_massmQl + mqlsq * id (3,3) = " << inter_massmQl(3,3) + mqlsq
  //       << endl;
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
		    double M_moduli, double M_gauge, double M_mess, 
		    double tanb, 
		    double btosgamma, double muong2, double bsmumu, double oh2  ) 
{
  sPhysical p = m.displayPhys(); 

  outputfile << M_moduli 
	     << " " << M_gauge 
	     << " " << M_mess
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



  double M_moduli_start, M_moduli_end ;
  double M_gauge_start, M_gauge_end ; 
  double M_mess_start, M_mess_end ; 
  
  double M_moduli, M_gauge, M_mess ;
  
  double tanb_start, tanb_end ; 
  double tanb = 10; 
  DoubleVector pars(3); 
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

    cout << varname << endl; 

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
    inputfile >> varname >> M_moduli_start ; 
    inputfile >> varname >> M_moduli_end ; 
    inputfile >> varname >> M_gauge_start ; 
    inputfile >> varname >> M_gauge_end ; 
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
	 << "M_moduli_start = " << M_moduli_start << endl
	 << "M_moduli_end = " << M_moduli_end << endl
	 << "M_gauge_start = " << M_gauge_start << endl 
	 << "M_gauge_end = " << M_gauge_end << endl 
	 << "M_mess_start = " << M_mess_start << endl 
	 << "M_mess_end = " << M_mess_end << endl 
	 << "tanb_start =  " << tanb_start << endl 
	 << "tanb_end = " << tanb_end << endl
	 << "sgnMu = " << sgnMu << endl; 


    for( int i = 0 ; i < numscan ; i++ ) { 
      QedQcd oneset0, oneset1, oneset2;

      M_moduli = randomgenerator( M_moduli_start, M_moduli_end ) ; 
      M_gauge  = randomgenerator( M_gauge_start,  M_gauge_end ) ; 
      M_mess   = lograndomgenerator( M_mess_start,   M_mess_end ) ;
      tanb     = randomgenerator( tanb_start,     tanb_end ) ; 
      
      cout << i << "th run : " << endl ;  
      cout << "M_moduli = " << M_moduli << endl 
	   << "M_gauge  = " << M_gauge  << endl 
	   << "M_mess   = " << M_mess   << endl 
	   << "tanb     = " << tanb     << endl ; 
      
      mgutGuess = 2e16;
      gaugeUnification = false;
      pars.setEnd(3);
      pars(1) = M_moduli; pars(2) = M_gauge; pars(3) = M_mess;
      //      r = &m;
      
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
      cout << "Starting" << endl; 
      r0.N= 0 ; 
      r0.Nflag = true; 
      r0.beta2() ;
      r0.Nflag = false; 
      
      double mgut =  r0.lowOrg(gaugegravityBcs0, mgutGuess, pars, sgnMu,
			       tanb, oneset0, gaugeUnification, ewsbBCscale);
      
      r0.runto( M_mess );
      
      cout << "starting phase 2 " << endl; 
      r0.N = N ;
      r0.Nflag = true; 
      r0.beta2() ; 
      r0.Nflag = false; 
      
      r0.runto( mgutGuess ) ; 
      
      global_g1 = r0.displayGaugeCoupling(1); 
      global_g2 = r0.displayGaugeCoupling(2); 
      global_g3 = r0.displayGaugeCoupling(3); 

      MssmSoftsusy r1 ; //, r2;// MssmSoftsusy2 l;
     
      r1.N = N ; 
      r1.Nflag = true; 
      r1.beta2(); 
      r1.Nflag = false ; 
      
      mgut =  r1.lowOrg(gaugegravityBcs1, mgutGuess, pars, sgnMu,
			tanb, oneset1, gaugeUnification, ewsbBCscale);
      
      
        cout << "Here comes r1" << endl; 
        cout << r1 ; 
      
    //  RGRUN( rgefile, r1 , log(mgutGuess) / log(10) , log( M_mess) / log( 10 ) , 20 ) ; 
      
      r1.runto( M_mess );
      
      global_g1 = r1.displayGaugeCoupling(1); 
      global_g2 = r1.displayGaugeCoupling(2); 
      global_g3 = r1.displayGaugeCoupling(3); 
      
      
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
      
      
      cout << "Here comes r2" << endl; 
      MssmSoftsusy r2 ;
      r2.N = 0; 
      r2.Nflag = true; 
      r2.beta2(); 
      r2.Nflag = false ;
      
      mgut =  r2.lowOrg(gaugegravityBcs2, mgutGuess, pars, sgnMu, 
			tanb, oneset2, gaugeUnification, ewsbBCscale); 
      //    cout << r2 ; 
      
      //      RGRUN( rgefile, r2 , log(M_mess) / log(10),  log(100) / log(10), 20 ) ; 
      
      //rgefile.close(); 
      
      //spectrumrecord( spectrumfile, r2 ) ;
      
      // spectrumfile.close(); 
      
      cout << r2 ; 
      //  sPhysical p = r2.displayPhys() ;
      
      //  cout << p ; 
      
      ofstream tempfile("LesHouches.dat"); 
      streambuf* strm_buffer = cout.rdbuf(); 
      
      cout.rdbuf( tempfile.rdbuf() ) ; 
      
      r2.lesHouchesAccordOutput("nonUniversal", pars, 
				sgnMu, tanb, 0, 1, mbmb, 
				mtau, MGUTSCALE , 0 ) ; 
      cout << flush; 
      cout.rdbuf(strm_buffer); 
      tempfile.close(); 

      if (r2.displayProblem().test()) {
	cout << "# SOFTSUSY problem with point: " << r2.displayProblem();
      }      

      if( checktheresult( r2 ) ) { 
	
	//////////////////////////////////////////////////
	//                micrOmegas                    //
	//////////////////////////////////////////////////
	
	double Xf, Omega, Omega2, bsg_value, bsmumu_value, gmuon_value; 
	string mess; 
	double mtop ;
	
	int err ; 
	int fast = 1; 
	double Beps = 1E-6 ; 
	
	double cut = 0.01; 
	
	
	
	err = readLesH("LesHouches.dat",1); 
	
	//
	//  printVar(stdout); 
	//
	char messtemp[20]; 
	
	err=sortOddParticles(messtemp);
	mess = messtemp; 
	
	//	HiggsMasses(stdout);     
	//	printMasses(stdout,1);
	
	
	Omega=darkOmega(&Xf,fast,Beps);
	
	o1Contents(stdout);
	printChannels(Xf,cut,Beps,1,stdout); 
	bsg_value= bsgnlo_(); 
	bsmumu_value = bsmumu_(); 
	gmuon_value = gmuon_(); 
      
	recordphysics( outputfile, r2, M_moduli, M_gauge, M_mess, tanb, 
		       bsg_value, gmuon_value, bsmumu_value, Omega ) ; 
      }
      else {
	recordphysics( outputfile, r2, M_moduli, M_gauge, M_mess, tanb,
		       0, 0 , 0, 0 ) ; 
      }

    }

  }

  
  //  if (r2.displayProblem().test()) {
  //   cout << "# SOFTSUSY problem with point: " << r2.displayProblem();
  //  }
  
  exit(0);

  
}
