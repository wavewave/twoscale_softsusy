
/** \file softpoint.cpp
   - Project:     SOFTSUSY 
   - Authors:     Ben Allanach, Markus Bernhardt 
   - Manual:      hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 

   - Webpage:     http://hepforge.cedar.ac.uk/softsusy/
   - Description: main calling program: command line interface
*/ 

#include <softpoint.h>

void extendedSugraBcs2(MssmSoftsusy & m, 
		       const DoubleVector & inputParameters) {
  int i;
  for (i=1; i<=3; i++) m.setGauginoMass(i, inputParameters.display(i));
  m.setTrilinearElement(UA, 1, 1, m.displayYukawaElement(YU, 1, 1) * 
			inputParameters.display(11));
  m.setTrilinearElement(UA, 2, 2, m.displayYukawaElement(YU, 2, 2) * 
			inputParameters.display(11));
  m.setTrilinearElement(UA, 3, 3, m.displayYukawaElement(YU, 3, 3) * 
			inputParameters.display(11));
  m.setTrilinearElement(DA, 1, 1, m.displayYukawaElement(YD, 1, 1) * 
			inputParameters.display(12));
  m.setTrilinearElement(DA, 2, 2, m.displayYukawaElement(YD, 2, 2) * 
			inputParameters.display(12));
  m.setTrilinearElement(DA, 3, 3, m.displayYukawaElement(YD, 3, 3) * 
			inputParameters.display(12));
  m.setTrilinearElement(EA, 1, 1, m.displayYukawaElement(YE, 1, 1) * 
			inputParameters.display(13));
  m.setTrilinearElement(EA, 2, 2, m.displayYukawaElement(YE, 2, 2) * 
			inputParameters.display(13));
  m.setTrilinearElement(EA, 3, 3, m.displayYukawaElement(YE, 3, 3) * 
			inputParameters.display(13));
  m.setSoftMassElement(mLl, 1, 1, sqr(inputParameters.display(31)));
  m.setSoftMassElement(mLl, 2, 2, sqr(inputParameters.display(32)));
  m.setSoftMassElement(mLl, 3, 3, sqr(inputParameters.display(33)));
  m.setSoftMassElement(mEr, 1, 1, sqr(inputParameters.display(34)));
  m.setSoftMassElement(mEr, 2, 2, sqr(inputParameters.display(35)));
  m.setSoftMassElement(mEr, 3, 3, sqr(inputParameters.display(36)));
  m.setSoftMassElement(mQl, 1, 1, sqr(inputParameters.display(41)));
  m.setSoftMassElement(mQl, 2, 2, sqr(inputParameters.display(42)));
  m.setSoftMassElement(mQl, 3, 3, sqr(inputParameters.display(43)));
  m.setSoftMassElement(mUr, 1, 1, sqr(inputParameters.display(44)));
  m.setSoftMassElement(mUr, 2, 2, sqr(inputParameters.display(45)));
  m.setSoftMassElement(mUr, 3, 3, sqr(inputParameters.display(46)));
  m.setSoftMassElement(mDr, 1, 1, sqr(inputParameters.display(47)));
  m.setSoftMassElement(mDr, 2, 2, sqr(inputParameters.display(48)));
  m.setSoftMassElement(mDr, 3, 3, sqr(inputParameters.display(49)));
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
  ii << "Any of the above can be extended by r parity violation of one coupling by\n";
  ii << "softpoint.x <non RPV model parameters as above> lambda <i> <j> <k> <coupling> \n";
  ii << "the word lambda replaceable with lambdaP or lambdaPP for LLE, LQD, UDD coupling, respectively \n\n";
  ii << "Other possibilities:\n";
  ii << "softpoint.x sugra <m0> <m12> <a0> <tanb> <mgut> <sgnMu> <mb(mb)> ";
  ii << " <mt> <as(MZ)> <1/a(MZ)>\n";
  ii << "softpoint.x leshouches < lesHouchesInput \n\n";
  ii << "Bracketed entries are numerical values.\n";
  ii << "<mgut> denotes the scale at which the SUSY breaking ";
  ii << "parameters are specified. \n";
  ii << "Enter <mgut>=unified to define MGUT by g1(MGUT)=g2(MGUT), otherwise";
  ii << "\nit will be fixed at the numerical value input.\n";
  ii << "For SUSY breaking terms set at MSUSY, enter <mgut>=msusy.\n";
  ii << "lesHouchesInput contains the SUSY Les Houches Accord 2";
  ii << " input.\n";
  throw ii.str();
}

/// global variable declaration
/// no quark mixing (dominant third family approx), and no verbose output
int MIXING = 1, PRINTOUT = 0;
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
/// number of loops used to calculate Higgs mass and tadpoles. They should be
/// identical for a consistent calculation
int numHiggsMassLoops = 2, numRewsbLoops = 2;
/// global pole mass of MZ in GeV - MZCENT is defined in def.h
double MZ = MZCENT;
/// end of global variable declaration


int main(int argc, char *argv[]) {

  double lambda = 0., aCkm = 0., rhobar = 0., etabar = 0.;

  bool flavourViolation = false;
  bool quarkFlavourViolation = false;
  bool leptonFlavourViolation = false;

  int numPoints = 1;

  double qMax = 0.;

  // Sets format of output: 4 decimal places
  outputCharacteristics(6);

  void (*boundaryCondition)(MssmSoftsusy &, const DoubleVector &)=sugraBcs;

  MssmSoftsusy m; MssmSoftsusyAltEwsb l; FlavourMssmSoftsusy k;
  MssmSoftsusy * r = &m; 
  RpvSoftsusy kw; bool RPVflag = false;

  try {
    QedQcd oneset;

  if (argc !=1 && strcmp(argv[1],"leshouches") != 0) {
    cerr << "SOFTSUSY" << SOFTSUSY_VERSION << endl;
    cerr << "B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331,";
    cerr << " hep-ph/0104145\n";
    cerr << "For RPV aspects, B.C. Allanach and M.A. Bernhardt, ";
    cerr << "arXiv:0903.1805.\n\n";
    cerr << "Low energy data in SOFTSUSY: MIXING=" << MIXING << " TOLERANCE=" 
	 << TOLERANCE << endl;
    cerr << "G_F=" << GMU << " GeV^2" << endl;
  }
  
  double mgutGuess = 2.0e16, tanb = 10., mbmb = MBOTTOM, mtau = MTAU;
  int sgnMu = 1;
  bool gaugeUnification = true, ewsbBCscale = false, altEwsb = false;

    // If there are no arguments, give error message,
    // or if none of the options are called, then go to error message
    if (argc == 1 || (strcmp(argv[1], "sugra") && strcmp(argv[1], "amsb") &&
		      strcmp(argv[1], "gmsb") && 
		      strcmp(argv[1], "runto") && 
		      strcmp(argv[1], "leshouches")))
      errorCall();
    
    DoubleVector pars(3); 
    
    char * modelIdent = "";  

    if (!strcmp(argv[1], "sugra")) {
      cout << "SOFTSUSY SUGRA calculation" << endl;
      boundaryCondition = &sugraBcs;
      if (argc == 8) {
	double m0 = atof(argv[2]);
	double m12 = atof(argv[3]);
	double a0 = atof(argv[4]);
	tanb = atof(argv[5]);
	mgutGuess = mgutCheck(argv[6], gaugeUnification, ewsbBCscale);
	sgnMu =  atoi(argv[7]);
	pars(1) = m0; pars(2) = m12; pars(3) = a0;
	r = &m;
      } else if (argc == 9) {
	double m0 = atof(argv[2]);
	double m12 = atof(argv[3]);
	double a0 = atof(argv[4]);
	tanb = atof(argv[5]);
	mgutGuess = mgutCheck(argv[6], gaugeUnification, ewsbBCscale);
	sgnMu =  atoi(argv[7]);
	pars(1) = m0; pars(2) = m12; pars(3) = a0;
	QEWSB = atof(argv[8]);
	r = &m;
      } else if (argc == 12) {
	double m0 = atof(argv[2]);
	double m12 = atof(argv[3]);
	double a0 = atof(argv[4]);
	tanb = atof(argv[5]);
	mgutGuess = mgutCheck(argv[6], gaugeUnification, ewsbBCscale);
	sgnMu =  atoi(argv[7]);
	double mbrun = atof(argv[8]);
	double mtpole = atof(argv[9]);
	double as = atof(argv[10]);
	double aInv = atof(argv[11]);
	oneset.setMass(mBottom, mbrun);
	oneset.setPoleMt(mtpole);
	oneset.setAlpha(ALPHA, 1.0 / aInv);
	oneset.setAlpha(ALPHAS, as);
	pars(1) = m0; pars(2) = m12; pars(3) = a0;
	r = &m;
      } else if (argc == 13) {
	RPVflag = true;
	double m0 = atof(argv[2]);
	double m12 = atof(argv[3]);
	double a0 = atof(argv[4]);
	tanb = atof(argv[5]);
	mgutGuess = mgutCheck(argv[6], gaugeUnification, ewsbBCscale);
	sgnMu =  atoi(argv[7]);
	pars(1) = m0; pars(2) = m12; pars(3) = a0;
	// check which lambda is set nonzero at MGUT
	if (!strcmp(argv[8], "lambda")) {
	  int i= int(atof(argv[9]));
	  int j= int(atof(argv[10]));
	  int k= int(atof(argv[11]));
	  double d = atof(argv[12]);
	  kw.setLambda(LE, k, i, j, d);
	} else if (!strcmp(argv[8], "lambdaP")) {
	  int i= int(atof(argv[9]));
	  int j= int(atof(argv[10]));
	  int k= int(atof(argv[11]));
	  double d = atof(argv[12]);
	  kw.setLambda(LD, k, i, j, d);
	} else if (!strcmp(argv[8], "lambdaPP")) {
	  int i= int(atof(argv[9]));
	  int j= int(atof(argv[10]));
	  int k= int(atof(argv[11]));
	  double d = atof(argv[12]);
	  kw.setLambda(LU, i, j, k, d);
	}
	r = &m;
      } else if (argc == 11) {
	RPVflag = true;
	double m0 = atof(argv[2]);
	double m12 = atof(argv[3]);
	double a0 = atof(argv[4]);
	tanb = atof(argv[5]);
	mgutGuess = mgutCheck(argv[6], gaugeUnification, ewsbBCscale);
	sgnMu =  atoi(argv[7]);
	pars(1) = m0; pars(2) = m12; pars(3) = a0;
	// check which lambda is set nonzero at MGUT
	if (!strcmp(argv[8], "kappa")) {
	  int i = int(atof(argv[9]));
	  double d = atof(argv[10]);
	  kw.setKappa(i, d);
	}
	r = &m;
      } 
      else {
	errorCall();
	// end of SUGRA option
      }
    }
    if (!strcmp(argv[1], "amsb")) {
      cout << "SOFTSUSY mAMSB calculation" << endl;
      boundaryCondition = &amsbBcs;
      if (argc == 7 | argc == 12) {
	double m0 = atof(argv[2]);
	double m32 = atof(argv[3]);
	tanb = atof(argv[4]);
	mgutGuess = mgutCheck(argv[5], gaugeUnification, ewsbBCscale);
	sgnMu =  atoi(argv[6]);
	pars(1) = m32; pars(2) = m0;
	// check if RPV
	if (argc == 12) {
	  if (!strcmp(argv[7], "lambda")) {
	    RPVflag = true;
	    int i= int(atof(argv[8]));
	    int j= int(atof(argv[9]));
	    int k= int(atof(argv[10]));
	    double d = atof(argv[11]);
	    kw.setLambda(LE, k, i, j, d);
	  }	
	  else if (!strcmp(argv[7], "lambdaP")) {
	    RPVflag = true;
	    int i= int(atof(argv[8]));
	    int j= int(atof(argv[9]));
	    int k= int(atof(argv[10]));
	    double d = atof(argv[11]);
	    kw.setLambda(LD, k, i, j, d);
	  } else if (!strcmp(argv[7], "lambdaPP")) {
	    RPVflag = true;
	    int i= int(atof(argv[8]));
	    int j= int(atof(argv[9]));
	    int k= int(atof(argv[10]));
	    double d = atof(argv[11]);
	    kw.setLambda(LU, i, j, k, d);
	  }
	}
	r = &m;
      }
      else 
	errorCall();
    }
    if (!strcmp(argv[1], "gmsb")) {
      cout << "SOFTSUSY mGMSB calculation" << endl;
      
      boundaryCondition = &gmsbBcs;
      
      if (argc == 8) {
	  double n5 = atof(argv[2]);
	  double mMess = atof(argv[3]);
	  double lambda = atof(argv[4]);
	  double cgrav = atof(argv[5]);
	  tanb = atof(argv[6]);
	  sgnMu =  atoi(argv[7]);
	  mgutGuess = mMess;
	  gaugeUnification = false;
	  pars.setEnd(4);
	  pars(1) = n5; pars(2) = mMess; pars(3) = lambda; pars(4) = cgrav;
	  r = &m;
	  if (lambda > mMess) {
	  ostringstream ii;
	  ii << "Input lambda=" << lambda << " should be less than mMess="
	     << mMess << endl;
	  throw ii.str();
	}
	if (cgrav > 1.0) {
	  ostringstream ii;
	  ii << "Input cgrav=" << cgrav << " a real number bigger than or "
	     << " equal to 1 (you can use 1 as a default value).\n";
	  throw ii.str();
	}
      }
      // for RPV GMSB
      else if (argc == 13) {
	RPVflag = true;
	double n5 = atof(argv[2]);
	double mMess = atof(argv[3]);
	double lambda = atof(argv[4]);
	double cgrav = atof(argv[5]);
	tanb = atof(argv[6]);
	sgnMu =  atoi(argv[7]);
	mgutGuess = mMess;
	gaugeUnification = false;
	pars.setEnd(4);
	pars(1) = n5; pars(2) = mMess; pars(3) = lambda; pars(4) = cgrav;
	// check which lambda is set nonzero at MGUT
	if (!strcmp(argv[8], "lambda")) {
	  int i= int(atof(argv[9]));
	  int j= int(atof(argv[10]));
	  int k= int(atof(argv[11]));
	  double d = atof(argv[12]);
	  kw.setLambda(LE, k, i, j, d);
	} else if (!strcmp(argv[8], "lambdaP")) {
	  int i= int(atof(argv[9]));
	  int j= int(atof(argv[10]));
	  int k= int(atof(argv[11]));
	  double d = atof(argv[12]);
	  kw.setLambda(LD, k, i, j, d);
	} else if (!strcmp(argv[8], "lambdaPP")) {
	  int i= int(atof(argv[9]));
	  int j= int(atof(argv[10]));
	  int k= int(atof(argv[11]));
	  double d = atof(argv[12]);
	  kw.setLambda(LU, i, j, k, d);
	}
	r = &m;
	if (lambda < mMess) {
	  ostringstream ii;
	  ii << "Input lambda=" << lambda << " should be greater than mMess="
	     << mMess << endl;
	  throw ii.str();
	}
	if (cgrav > 1.0) {
	  ostringstream ii;
	  ii << "Input cgrav=" << cgrav << " a real number bigger than or "
	     << " equal to 1 (you can use 1 as a default value).\n";
	  throw ii.str();
	}
      }
      else 
	errorCall();
    }
    
    bool flag = false;
    if (!strcmp(argv[1], "leshouches")) {
      if (argc == 2) {
	string line, block;
	int model;
	
	while (getline(cin,line)) {
	  //	  mgutGuess = mgutCheck("unified", gaugeUnification);

	  //	cout << line << endl;
	  istringstream input(line); 
	  string word1, word2;
	  input >> word1;
	  
	  if (word1.find("#") == string::npos) { 
	    // read in another word if there's no comment
	    input >> word2; 
	    
	    if (ToUpper(word1) == "BLOCK")  { 
	      block = ToUpper(word2);
	      
	    } else { // ought to be data
	      istringstream kk(line);
	      if (block == "MODSEL") {
		int i; kk >> i; 
		
		switch(i) {
		case 1: kk >> model; 
		  switch(model) {
		  case 0: boundaryCondition = &extendedSugraBcs;
		    modelIdent = "nonUniversal"; r=&m;
		    break;
		  case 1: 
		    if (!flavourViolation) {
		      pars.setEnd(3); 
		      boundaryCondition = &sugraBcs; 
		    }
		    modelIdent = "sugra";
		    break;
		  case 2: 
		    if (!flavourViolation) {
		      boundaryCondition = &gmsbBcs; 
		      pars.setEnd(4); 
		    } 
		    modelIdent = "gmsb";
		    break;
		  case 3: 		    
		      boundaryCondition = &amsbBcs; 
		      pars.setEnd(2); 
		    modelIdent = "amsb";
		    break;
		  default: 
		    ostringstream ii;
		    ii << "SOFTSUSY" << SOFTSUSY_VERSION 
		       << " cannot yet do model " 
		       << model << ": terminal error\n";
		    throw ii.str();
		  }
		  break;
		case 4: int i; kk >> i;
		  switch(i) {
		  case 0: RPVflag = false;
		    break;
		  case 1: RPVflag = true;
		    break;
		  default:
		    ostringstream ii;
		    ii << "MODSEL 4 choosing silly RPV switch\n"
		       << "(" << i << ") not a valid switch" << endl;
		    throw ii.str();
		  }
		  break;
		case 6: int j; kk >> j;
		  switch(j) {
		  case 0: flavourViolation = false; 
		    break;
		  case 1: quarkFlavourViolation = true; r=&k;
		    flavourViolation = true; k.numFV = 1;
		    if (boundaryCondition != & amsbBcs) {
		      pars.setEnd(64); boundaryCondition = &flavourBcs2;
		    }
		    break;
		  case 2: leptonFlavourViolation = true; r=&k;
		    flavourViolation = true; k.numFV=2;
		    if (boundaryCondition != & amsbBcs) {
		      pars.setEnd(64); boundaryCondition = &flavourBcs2;
		    }
		    break;
		  case 3: quarkFlavourViolation = true; r=&k;
		    leptonFlavourViolation = true; k.numFV = 3;
		    flavourViolation = true; 
		    if (boundaryCondition != & amsbBcs) {
		      pars.setEnd(64); boundaryCondition = &flavourBcs2;
		    }
		    break;
		  default:
		    ostringstream ii;
		    cout << "WANRNING: MODSEL 6 " << j 
			 << " not recognised. Ignoring." << endl;
		    break;
		  }
		  break;
		case 11: kk >> numPoints;
		  if (numPoints < 1) {
		    ostringstream ii;
		    ii << "MODSEL 11 selecting silly number of points"
		       << "(" << numPoints << ") to output" << endl;
		    throw ii.str();
		  }
		  break;
		case 12: double d; kk >> d;
		  if (d < MZ) {
		    ostringstream ii;
		    ii << "MODSEL 12 selecting silly scale Qmax"
		       << "(" << d << ") < MZ to output" << endl;
		    throw ii.str();
		  }
		  qMax = d; break;
		default:
		  cout << "# WARNING: don't understand first integer " 
		       << word1 << " " << word2 << " in block " << block
		       << ": ignoring it\n";
		  break;
		}
	      }
	      else if (block == "MINPAR") {
		int i; double d; kk >> i >> d; 
		switch (i) {
		case 3: tanb = d; break;
		case 4: sgnMu = int(d); break;
		default: 
		  switch(model) {
		  case 0:
		    // SUGRA inputs to fill out the pheno MSSM case
		    switch(i) {
		    case 1: pars(1) = d; break;
		    case 2: pars(2) = d; break;
		    case 5: pars(3) = d; break;
		    default: 
		      ostringstream ii;
		      ii << "Didn't understand pheno MSSM input " << i << endl;
		      break;
		    } break;
		  case 1: // SUGRA inputs
		    switch(i) {
		    case 1: 
		      if (flavourViolation) {
			double d2 = sqr(d);
			pars(4) = d2;  pars(7) = d2;  pars(9) = d2;
			pars(10) = d2; pars(13) = d2; pars(15) = d2;
			pars(16) = d2; pars(19) = d2; pars(21) = d2;
			pars(22) = d2; pars(25) = d2; pars(27) = d2;
			pars(28) = d2; pars(31) = d2; pars(33) = d2;
			pars(63) = d2; pars(64) = d2;
		      } else pars(1) = d; 
		      break;
		    case 2: 
		      if (flavourViolation) {
			pars(1) = d; pars(2) = d; pars(3) = d;
		      } else pars(2) = d; 
		      break;
		    case 5: 
		      if (flavourViolation) pars(62) = d;
		      else pars(3) = d; 
		      break;
		    default: 
		      ostringstream ii;
		      ii << "Didn't understand SUGRA input " << i << endl;
		      break;
		    } break;
		  case 2: // GMSB inputs
		    switch(i) {
		    case 1: pars(3) = d; break;
		    case 2: pars(2) = d; mgutGuess = d;
		      gaugeUnification = false; break;
		    case 5: pars(1) = d; break;
		    case 6: pars(4) = d; break;
		    default: 
		      ostringstream ii;
			ii << "Didn't understand GMSB input " << i << endl;
			break;
		    } break;
		  case 3: // AMSB inputs
		    switch(i) {
		    case 1: pars(2) = d; break;
		    case 2: pars(1) = d; break;
		    default: 
		      ostringstream ii;
		      ii << "Didn't understand AMSB input " << i << endl;
		      break;
		    } break;
		  default: 
		    ostringstream ii;
		    ii << "Didn't understand model input " << model << endl;
		    break;
		  }
		  break;
		}
	      }
	      // Adding non-minimal options. However, mA and mu option is not
	      // yet supported. Also, we assume the initial model was mSUGRA
	      // (for now).
	      else if (block == "EXTPAR") {
		if (!strcmp(modelIdent, "sugra") || 
		    !strcmp(modelIdent, "nonUniversal")) {
		  if (pars.displayEnd() != 49) { // initialise vector
		    modelIdent = "nonUniversal";
		    if (!flavourViolation) {
		      boundaryCondition = &extendedSugraBcs;
		      r=&m; pars.setEnd(49);
		      double m0 = pars(1), m12 = pars(2), a0 = pars(3);
		      int i; for (i=1; i<=3; i++) pars(i) = m12;
		      for (i=11; i<=13; i++) pars(i) = a0;
		      pars(21) = m0*m0; pars(22) = m0*m0;
		      for (i=31; i<=36; i++) pars(i) = m0;		    
		      for (i=41; i<=49; i++) pars(i) = m0;		    
		    }
		    else boundaryCondition = &flavourBcs2;
		  }
		  int i; double d; kk >> i >> d;  
		  if ((i > 0 && i <=  3) || (i >= 11 && i <= 13) || 
		      (i >= 21 && i <= 23) || (i == 26) 
		      || (i >= 31 && i <= 36) || 
		      (i >= 41 && i <= 49)) {
		    if (!flavourViolation) pars(i) = d;
		    else {
		      if (i == 21) pars(63) = d;
		      if (i == 22) pars(64) = d;
		    }
		  }
		  if (i == 0) { 
		    mgutGuess = d;
		    gaugeUnification = false;
		    // setting Minput=-1 should yield MSSM BCs at MSUSY
		    if ((d - 1.0) < EPSTOL) {
		      mgutGuess = 1.0e3;
		      ewsbBCscale = true;
		      QEWSB = 1.0;
		      if (gaugeUnification) 
			cout << "# Gauge unification ignored since pheno MSSM"
			     << " assumes BC set at QEWSB\n"; 
		      gaugeUnification = false;
		    }
		  }
		  if (i == 23 || i == 26) altEwsb = true; 
		  if (!((i >= -1 && i <=  3) || (i >= 11 && i <= 13) || 
		      (i >= 21 && i <= 23) || (i == 26)
			|| (i >= 31 && i <= 36) || 
			(i >= 41 && i <= 49)))		  
		    cout << "# Didn't understand extra parameter " << i 
			    << " - ignoring it" << endl;
		}
		else cout << "# Can't yet handle extra parameters in " 
			  << modelIdent << ": ignoring them" << endl;
	      }
	      else if (block == "VCKMIN") {
		int i; double d; kk >> i >> d;
		switch(i) {
		case 1: lambda = d; break;
		case 2: aCkm = d;   break;		  
		case 3: rhobar = d; break;
		case 4: etabar = d; break;
		default:
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << d << " in block "
		       << block << ": ignoring it\n";
		  break;
		}
	      }
	      else if (block == "UMNSIN") {
		int i; double d; kk >> i >> d;
		switch(i) {
		case 1: k.setThetaB12(asin(d)); break;
		case 2: k.setThetaB23(asin(d)); break;		  
		case 3: k.setThetaB13(asin(d)); break;
		case 4: cout << "# Cannot yet do complex phases: ";
		  cout << "setting it to zero" << endl; break;
		case 5: cout << "# Cannot yet do complex phases: ";
		  cout << "setting it to zero" << endl; break;
		case 6: cout << "# Cannot yet do complex phases: ";
		  cout << "setting it to zero" << endl; break;
		default:
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << d << " in block "
		       << block << ": ignoring it\n";
		  break;
		}
	      }
	      else if (block == "SMINPUTS") {
		int i; double d; kk >> i >> d; 
		switch (i) {
		case 1: oneset.setAlpha(ALPHA, 1.0 / d); break;
		case 2: GMU = d; break;
		case 3: oneset.setAlpha(ALPHAS, d); break; 
		case 4: oneset.setMu(d); m.setData(oneset); MZ = d; break;
		case 5: oneset.setMass(mBottom, d); mbmb = d; flag = true; 
		  break;
		case 6: oneset.setPoleMt(d); break;
		case 7: oneset.setMass(mTau, d); mtau = d; break;
		case 8: k.setMnuTau(d); break;
		case 11: oneset.setMass(mElectron, d); break;
		case 12: k.setMnuMu(d); break;
		case 13: oneset.setMass(mMuon, d); break;
		case 14: k.setMnuTau(d); break;
		case 21: oneset.setMass(mDown, d); break;
		case 22: oneset.setMass(mUp, d); break;
		case 23: oneset.setMass(mStrange, d); break;
		case 24: oneset.setMass(mCharm, d); break;
		default: 
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      } 
	      else if (block == "MSQ2IN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars(positionOfSym(i, j) + 3) = d;
	      }
	      else if (block == "MSU2IN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars(positionOfSym(i, j) + 9) = d;
	      }
	      else if (block == "MSD2IN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars(positionOfSym(i, j) + 15) = d;
	      }
	      else if (block == "MSL2IN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars(positionOfSym(i, j) + 21) = d;
	      }
	      else if (block == "MSE2IN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars(positionOfSym(i, j) + 27) = d;
	      }
	      else if (block == "TUIN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars((i-1) * 3 + j + 33) = d;
	      }
	      else if (block == "TDIN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars((i-1) * 3 + j + 42) = d;
	      }
	      else if (block == "TEIN") {
		modelIdent = "nonUniversal";
		//		strcpy(modelIdent, "nonUniversal");
		int i, j; double d; kk >> i >> j >> d;
		pars((i-1) * 3 + j + 51) = d;
	      }
	      else if (block == "RVLAMLLEIN") {
		int i,j,k; double d; kk >> i >> j >> k >> d;
		if ((i > 0 && i <=  3) || (j > 0 && j <=  3) ||
		    (k > 0 && k <=  3)) {
		  kw.setLambda(LE, k, i, j, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << j << " " << k << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "RVLAMLQDIN") {
		int i,j,k; double d; kk >> i >> j >> k >> d;
		if((i > 0 && i <=  3) || (j > 0 && j <=  3) ||
		   (k > 0 && k <=  3)) {
		  kw.setLambda(LD, k, i, j, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << j << " " << k << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "RVLAMUDDIN") {
		int i,j,k; double d; kk >> i >> j >> k >> d;
		if((i > 0 && i <=  3) || (j > 0 && j <=  3) || 
		   (k > 0 && k <=  3)) {
		  kw.setLambda(LU, i, j, k, d);
		}
	      }
	      else if (block == "RVTIN") {
		int i,j,k; double d; kk >> i >> j >> k >> d;
		if((i > 0 && i <=  3) || (j > 0 && j <=  3) || 
		   (k > 0 && k <=  3)) {
		  kw.setHr(LE, k, i, j, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << j << " " << k << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "RVTPIN") {
		int i,j,k; double d; kk >> i >> j >> k >> d;
		if((i > 0 && i <=  3) || (j > 0 && j <=  3) || 
		   (k > 0 && k <=  3)) {
		  kw.setHr(LD, k, i, j, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << j << " " << k << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "RVTPPIN") {
		int i,j,k; double d; kk >> i >> j >> k >> d;
		if((i > 0 && i <=  3) || (j > 0 && j <=  3) || (k > 0 && k <=  3)) {
		  kw.setHr(LU, i, j, k, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << j << " " << k << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "RVKAPPAIN") {
		int i; double d; kk >> i >> d;
		if (i > 0 && i <=  3) {
		  kw.setKappa(i, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " << i << d 
		       << " in block " << block << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "RVDIN") {
		int i; double d; kk >> i >> d;
		if (i > 0 && i <=  3) {
		  kw.setD(i, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " 
		       << i << d << " in block " << block 
		       << ": ignoring it\n"; break;
		}
	      }
	      // input of sneutrino VEVs not supported yet
	      else if (block == "RVSNUVEVIN") {
		int i; double d; kk >> i >> d;
		cout << "# WARNING: in block " << block 
		     << ": SOFTSUSY does not support setting of sneutrino VEVs"
		     << " yet : ignoring them\n"; break;
	      }
	      else if (block == "RVMLH1SQIN") {
		int i; double d; kk >> i >> d;
		if ((i > 0 && i <=  3)) {
		  kw.setMh1lSquared(i, d);
		}
		else {
		  cout << "# WARNING: Don't understand data input " 
		       << i << d << " in block " << block 
		       << ": ignoring it\n"; break;
		}
	      }
	      else if (block == "SOFTSUSY") {
		int i; double d; kk >> i >> d;
		switch(i) {
		case 1: TOLERANCE = d; break;
		case 2: 
		  MIXING = int(d); if (MIXING > 0) flavourViolation = true;
		  break;
		case 3: PRINTOUT = int(d); break;
		case 4: QEWSB = d; break;
		case 5: INCLUDE_2_LOOP_SCALAR_CORRECTIONS = 
			  bool(int(d+EPSTOL)); 
		  break;  
		default:
		  cout << "# WARNING: Don't understand data input " << i 
		       << " " << d << " in block "
		       << block << ": ignoring it\n"; break;
		}
	      }
	      //	      else if (block == "SPCFILE") 
	      //	kk >> fileName;
	      else {
		cout << "# WARNING: don't recognise block " << block 
		   << ": ignoring all data in it" << endl;
	      }
	      // end if blocks
	      
	    } // end of data
	  } // end of no-comment
	  
	} // end of file
	
      }
      else errorCall();
    }

    /// prepare CKM angles
    if (flavourViolation) k.setAngles(lambda, aCkm, rhobar, etabar);

    if (altEwsb) {
      boundaryCondition = &extendedSugraBcs2;
      l.setAltEwsb(pars(26), pars(23));
      //      l.muCond = pars(23);
      //      l.mAcond = pars(26);
      l.setSusyMu(pars(23));
      sgnMu = 0; // Flags different BCs
      r = &l; 
    }

    if (RPVflag) {
      if (boundaryCondition == &sugraBcs) {
	boundaryCondition = &rpvSugraBcs;
	  }
      else if (boundaryCondition == &amsbBcs) {
	boundaryCondition = &rpvAmsbBcs;
	  }
      else if (boundaryCondition == &gmsbBcs) {
	boundaryCondition = &rpvGmsbBcs;
	  }
      else {
	cout << "# WARNING: there is no RPV version for selected "
	     << " boundary condition!" << endl;
      }

      kw.rpvDisplay(pars);
      r = &kw;
    }
    // intput error checking  
    if (sgnMu != 1 && sgnMu != -1 && sgnMu != 0) {
      ostringstream ii;
      ii << "Incorrect input for sign(mu)=" << sgnMu <<endl;
      throw ii.str();
    }
    if (tanb < 1.0 || tanb > 1.0e2)  {
      ostringstream ii;
      ii << "Incorrect input for tan beta=" << tanb <<endl;
      throw ii.str();
    }
    
    QedQcd twoset(oneset); ///< save a copy of the input parameters

    oneset.toMz();
    
    double mgut =  r->lowOrg(boundaryCondition, mgutGuess, pars, sgnMu,
			     tanb, oneset, gaugeUnification, ewsbBCscale);

    if (strcmp(argv[1],"leshouches") != 0) {
      if (RPVflag) {
	cout << "mgut = " << mgut << endl << kw;
      } 
      else{
	cout << "mgut = " << mgut << endl << *r;
      }
    }
    else {
      r->lesHouchesAccordOutput(cout, modelIdent, pars, sgnMu, tanb, qMax,  
				numPoints, mgut, twoset, altEwsb);
    }
  }
  
  catch(const string & a) {
    cout << a;
  }
  
  if (r->displayProblem().test()) {
    cout << "# SOFTSUSY problem with point: " << r->displayProblem() << endl;
  }

  exit(0);
}

