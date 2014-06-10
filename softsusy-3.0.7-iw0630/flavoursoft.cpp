/** \file flavoursoft.cpp
   Project:     SOFTSUSY 
   Author:      Ben Allanach 
   Manual:      hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
   Webpage:     http://hepforge.cedar.ac.uk/softsusy/

*/

#include "flavoursoft.h"

extern double sw2, gnuL, guL, gdL, geL, guR, gdR, geR, yuL, yuR, ydL, 
  ydR, yeL, yeR, ynuL;

void convertFromWolfenstein(double lambda, double A, double rhobar, 
			    double etabar, double & sin12, double & sin23, 
			    double & sin13) {
  sin12 = lambda;
  sin23 = A * sqr(lambda);
  Complex x; ///< sin theta13 e^i delta
  Complex i(0., 1.);
  double a2Lambda4 = sqr(A) * sqr(sqr(lambda));
  x = A * lambda * sqr(lambda) * (rhobar + i * etabar) * 
    sqrt(1.0 - a2Lambda4) / sqrt(1.0 - sqr(lambda)) /
    (1.0 - a2Lambda4 * (rhobar + i * etabar));
  sin13 = x.mod();
}

int positionOfSym(int i, int j) {
  switch (i) {
  case 1: return j;   break;
  case 2: return j+2; break;
  case 3: return j+3; break;
  default: 
    cout << " # WARNING: can't convert position in 3 by 3 matrix" 
	 << i << j << endl; 
    return 0;
  }
}

void flavourBcs2(MssmSoftsusy & m, 
		 const DoubleVector & inputParameters) {
  int i, count = 0;
  for (i=1; i<=3; i++) {
    count++;
    m.setGauginoMass(i, inputParameters.display(count));
  }
 
  /// Find the Yukawa rotation matrices such that the super-CKM basis may be
  /// defined
  DoubleMatrix Ud(3, 3), Vd(3, 3), Uu(3, 3), Vu(3, 3);
  DoubleVector yu(3), yd(3);
  //  m.displayYukawaMatrix(YU).diagonalise(Uut, Vu, yu);
  m.displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
  m.displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
  ckmNormalise(Vu, Vd, Uu, Ud); 

  DoubleMatrix Ue(3, 3), Ve(3, 3);
  DoubleVector ye(3);
  m.displayYukawaMatrix(YE).diagonalise(Ve, Ue, ye);

  DoubleMatrix msq2in(3, 3), msu2in(3, 3), msd2in(3, 3), 
    msl2in(3, 3), mse2in(3, 3);

  int j; for (i=1; i<=3; i++)
    for (j=i; j<=3; j++) {
      count++;
      msq2in(i, j) = inputParameters.display(count);
    }
   for (i=1; i<=3; i++)
    for (j=i; j<=3; j++) {
      count++;
      msu2in(i, j) = inputParameters.display(count);
    }
   for (i=1; i<=3; i++)
    for (j=i; j<=3; j++) {
      count++;
      msd2in(i, j) = inputParameters.display(count);
    }
   for (i=1; i<=3; i++)
    for (j=i; j<=3; j++) {
      count++;
      msl2in(i, j) = inputParameters.display(count);
    }
   for (i=1; i<=3; i++)
    for (j=i; j<=3; j++) {
      count++;
      mse2in(i, j) = inputParameters.display(count);
    }
  msq2in.symmetrise();
  msu2in.symmetrise();
  msd2in.symmetrise();
  msl2in.symmetrise();
  mse2in.symmetrise();

  m.setSoftMassMatrix(mLl, Ve * msl2in * Ve.transpose());
  m.setSoftMassMatrix(mEr, Ue * mse2in.transpose() * Ue.transpose());
  m.setSoftMassMatrix(mQl, Vd * msq2in * Vd.transpose());
  m.setSoftMassMatrix(mUr, Uu * msu2in.transpose() * Uu.transpose());
  m.setSoftMassMatrix(mDr, Ud * msd2in.transpose() * Ud.transpose());

  DoubleMatrix tuin(3, 3), tdin(3, 3), tein(3, 3);
   for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      count++;
      tuin(i, j) = inputParameters.display(count);
    }
   for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      count++;
      tdin(i, j) = inputParameters.display(count);
    }
  for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      count++;
      tein(i, j) = inputParameters.display(count);
    }

  m.universalTrilinears(inputParameters.display(62));
  
  m.setTrilinearMatrix(UA, m.displayTrilinear(UA) + 
		       Vu * tuin.transpose() * Uu.transpose());
  m.setTrilinearMatrix(DA, m.displayTrilinear(DA) + 
		       Vd * tdin.transpose() * Ud.transpose());
  m.setTrilinearMatrix(EA, m.displayTrilinear(EA) + 
		       Ve * tein.transpose() * Ue.transpose());

  m.setMh1Squared(inputParameters.display(63));
  m.setMh2Squared(inputParameters.display(64));

}

ComplexMatrix FlavourMssmSoftsusy::displayComplexCkm() const {
  double d   = displayDelta();
  Complex eID(cos(d), sin(d));
  double s12 = sin(displayTheta12());
  double s13 = sin(displayTheta13());
  double s23 = sin(displayTheta23());
  
  double c12 = cos(displayTheta12());
  double c13 = cos(displayTheta13());
  double c23 = cos(displayTheta23());

  ComplexMatrix ckmMatrix(3, 3);
  ckmMatrix(1, 1) = c12 * c13;      
  ckmMatrix(1, 2) = s12 * c13; 
  ckmMatrix(1, 3) = (s13 / eID);            
  ckmMatrix(2, 1) = (-s12 * c23 - c12 * s23 * s13 * eID);
  ckmMatrix(2, 2) = (c12 * c23 - s12 * s23 * s13 * eID);
  ckmMatrix(2, 3) = s23 * c13; 
  ckmMatrix(3, 1) = (s12 * s23 - c12 * c23 * s13 * eID); 
  ckmMatrix(3, 2) = (-c12 * s23 - s12 * c23 * s13 * eID); 
  ckmMatrix(3, 3) = c23 * c13; 

  return ckmMatrix;
}

DoubleMatrix FlavourMssmSoftsusy::displayCkm() const {
  double d   = displayDelta();
  Complex eID(cos(d), sin(d));
  double s12 = sin(displayTheta12());
  double s13 = sin(displayTheta13());
  double s23 = sin(displayTheta23());
  
  double c12 = cos(displayTheta12());
  double c13 = cos(displayTheta13());
  double c23 = cos(displayTheta23());

  DoubleMatrix ckmMatrix(3, 3);
  ckmMatrix(1, 1) = c12 * c13;      
  ckmMatrix(1, 2) = s12 * c13; 
  /* ckmMatrix(1, 3) = (s13 / eID).real();            
  ckmMatrix(2, 1) = (-s12 * c23 - c12 * s23 * s13 * eID).real();
  ckmMatrix(2, 2) = (c12 * c23 - s12 * s23 * s13 * eID).real();
  ckmMatrix(2, 3) = s23 * c13; 
  ckmMatrix(3, 1) = (s12 * s23 - c12 * c23 * s13 * eID).real(); 
  ckmMatrix(3, 2) = (-c12 * s23 - s12 * c23 * s13 * eID).real(); 
  ckmMatrix(3, 3) = c23 * c13; explicitly setting delta to zero */

  /// phase factor e^i delta: we'll set it to + or - 1 depending on the sign
  /// of s13
  int pf = 1;
  if (s13 < 0.) pf = -1;
  
  ckmMatrix(1, 3) = pf * s13;
  ckmMatrix(2, 1) = (-s12 * c23 - pf * c12 * s23 * s13);
  ckmMatrix(2, 2) = (c12 * c23 - pf * s12 * s23 * s13);
  ckmMatrix(2, 3) = s23 * c13; 
  ckmMatrix(3, 1) = (s12 * s23 - pf * c12 * c23 * s13); 
  ckmMatrix(3, 2) = (-c12 * s23 - pf * s12 * c23 * s13); 
  ckmMatrix(3, 3) = c23 * c13;

  return ckmMatrix;
}

DoubleMatrix FlavourMssmSoftsusy::displayMns() const {
  double s12 = sin(displayThetaB12());
  double s13 = sin(displayThetaB13());
  double s23 = sin(displayThetaB23());
  
  double c12 = cos(displayThetaB12());
  double c13 = cos(displayThetaB13());
  double c23 = cos(displayThetaB23());

  DoubleMatrix mnsMatrix(3, 3);
  mnsMatrix(1, 1) = c12 * c13;      
  mnsMatrix(1, 2) = s12 * c13; 
  mnsMatrix(1, 3) = s13;            
  mnsMatrix(2, 1) = -s12 * c23 - c12 * s23 * s13;
  mnsMatrix(2, 2) = c12 * c23 - s12 * s23 * s13;
  mnsMatrix(2, 3) = s23 * c13; 
  mnsMatrix(3, 1) = s12 * s23 - c12 * c23 * s13; 
  mnsMatrix(3, 2) = -c12 * s23 - s12 * c23 * s13; 
  mnsMatrix(3, 3) = c23 * c13;

  return mnsMatrix;
}

#define HR "----------------------------------------------------------"

ostream & operator <<(ostream & left, const FlavourMssmSoftsusy & m) {
  left << m.displayMssmSoft();
  left << "Flavour violating parameters:\n";
  left << "CKM data: 12=" << m.displayTheta12() 
       << " 23=" << m.displayTheta23() 
       << " 13=" << m.displayTheta13() << endl;
  left << "m_nue: " << m.displayMnuE() << " m_numu: " << m.displayMnuMu()
       << "m_nutau: " << m.displayMnuTau() << endl;
  left << "MNS data: 12=" << m.displayThetaB12() 
       << " 23=" << m.displayThetaB23() 
       << " 13=" << m.displayThetaB13() << endl;
  left << "uSqMix" << m.displayFlavourPhysical().uSqMix;
  left << "dSqMix" << m.displayFlavourPhysical().dSqMix;
  left << "eSqMix" << m.displayFlavourPhysical().eSqMix;
  left << "nuSqMix" << m.displayFlavourPhysical().nuSqMix;

  left << HR;
  return left;
}

#undef HR

void FlavourMssmSoftsusy::lesHouchesAccordOutput(ostream & out, char model[], 
						 const DoubleVector & pars, 
						 int sgnMu, double tanb, 
						 double qMax, 
						 int numPoints, double mgut, 
						 const QedQcd & twoset,
						 bool altEwsb) {

  outputCharacteristics(8);

  out << "# SOFTSUSY" << SOFTSUSY_VERSION << endl;
  out << "# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331,";
  out << " hep-ph/0104145\n";
  
  out << "Block SPINFO         # Program information\n"
      << "     1   SOFTSUSY    # spectrum calculator\n";
  out << "     2   " << SOFTSUSY_VERSION << "         # version number\n";
  if (displayProblem().noConvergence)
    out << "     3   Possible problem: Not achieved desired accuracy to factor of 10\n";
  if (displayProblem().testSeriousProblem()) 
    out << "     4   Point invalid: " << displayProblem() << endl;

  out << "Block MODSEL  # Select model\n";
  int modsel = 1;
  if (!strcmp(model, "sugra")) modsel = 1;
  if (!strcmp(model, "gmsb")) modsel = 2;
  if (!strcmp(model, "amsb")) modsel = 3;
  out << "     1    " << modsel << "   # " << model << "\n"; // SLHA code
  out << "     6    " << numFV << "   # flavour violating MSSM\n"; 

  QedQcd d(displayDataSet());

  out << "Block SMINPUTS   # Standard Model inputs\n";
  out << "     1   "; printRow(out, 1.0 / d.displayAlpha(ALPHA)); 
  out << "   # alpha_em^(-1)(MZ) SM MSbar\n";
  out << "     2   "; printRow(out, GMU); out << "   # G_Fermi\n";
  out << "     3   "; printRow(out, d.displayAlpha(ALPHAS)); 
  out << "   # alpha_s(MZ)MSbar\n";
  out << "     4   "; printRow(out, displayMz()); out << "   # MZ(pole)\n";
  d.runto(d.displayMass(mBottom));
  d.runto(d.displayMass(mBottom));
  d.runto(d.displayMass(mBottom));
  out << "     5   "; printRow(out, twoset.displayMass(mBottom)); 
  out << "   # mb(mb)\n";
  out << "     6   "; printRow(out, d.displayPoleMt()); 
  out << "   # Mtop(pole)\n";
  out << "     7   "; printRow(out, twoset.displayMass(mTau)); 
  out << "   # Mtau(pole)\n";
  out << "     8   "; printRow(out, displayMnuTau()); 
  out << "   # Mnu3(pole)\n";
  out << "    14   "; printRow(out, displayMnuMu()); 
  out << "   # Mnu2(pole)\n";
  out << "    15   "; printRow(out, displayMnuE()); 
  out << "   # Mnu1(pole)\n";

  d.runto(2.);

  out << "    21   ";  printRow(out, d.displayMass(mDown)); 
  out << "   # Mdown(2 GeV) MSbar\n";
  out << "    22   ";  printRow(out, d.displayMass(mUp)); 
  out << "   # Mup(2 GeV) MSbar\n";
  out << "    23   ";  printRow(out, d.displayMass(mStrange)); 
  out << "   # Mstrange(2 GeV) MSbar\n";
  d.runto(maximum(d.displayMass(mCharm), 1.0));
  out << "    24   ";  printRow(out, d.displayMass(mCharm)); 
  out << "   # Mcharm(Mcharm) MSbar\n";
  d.runto(1.);
  out << "    11   "; printRow(out, twoset.displayMass(mElectron)); 
  out << "   # Me(pole)\n";
  out << "    13   "; printRow(out, twoset.displayMass(mMuon)); 
  out << "   # Mmu(pole)\n";

  /// these come from 2006 PDG
  double s12 = sin(theta12);
  double s23 = sin(theta23);
  double s13 = sin(theta13);
  
  out << "Block VCKMIN               # input CKM mixing matrix parameters\n";
  double lambda = s12; 
  double aCkm;
  if (s23 == 0.) aCkm = 0.; 
    else aCkm = s23 / sqr(lambda);
  double c = sqrt((1.0 - sqr(s23)) / (1.0 - sqr(lambda)));
  Complex eid(cos(deltaCkm), sin(deltaCkm));
  Complex r;
  if (s13 == 0.) r = Complex(0., 0.);
  else r = (s13 * eid / 
	    (c * aCkm * lambda * sqr(lambda) + s13 * eid * sqr(s23)));
  
  out << "     1    " << lambda << "      # lambda\n";
  out << "     2    " << aCkm << "      # A\n";
  out << "     3    " << r.real() << "      # rhobar\n";  
  out << "     4    " << r.imag() 
      << "      # etabar (no phases used in SOFTSUSY yet though)\n";    
  
  out << "Block MINPAR  # SUSY breaking input parameters\n";
  out << "     3   "; printRow(out, tanb); out << "   # tanb" << endl;
  if (!altEwsb) {
    out << "     4   "; 
    printRow(out, double(sgnMu)); 
    out << "   # sign(mu)"<< endl;
  }
  if (!strcmp(model, "sugra")) {
    out << "     1   "; printRow(out, sqrt(pars.display(4))); out << "   # m0" << endl;
    out << "     2   "; printRow(out, pars.display(1)) ; out << "   # m12" << endl;
    out << "     5   "; printRow(out, pars.display(62)) ; out << "   # A0" << endl;
  }
  else if (!strcmp(model, "gmsb")) {
    out << "     1   "; printRow(out, pars.display(3)); 
    out << "   # lambda" << endl;
    out << "     2   "; printRow(out, pars.display(2)) ; 
    out << "   # M_mess" << endl;
    out << "     5   "; printRow(out, pars.display(1)) ; 
    out << "   # N5" << endl;
    out << "     6   "; 
    printRow(out, pars.display(4)) ; out << "   # cgrav" << endl;
  }
  else if (!strcmp(model, "amsb")) {
    out << "     1   "; printRow(out, pars.display(2)) ; 
    out << "   # m0" << endl;
    out << "     2   "; printRow(out, pars.display(1)); 
    out << "   # m3/2" << endl;
  }
  else if (!strcmp(model, "nonUniversal")) {
    out << "Block EXTPAR          # non-universal SUSY breaking parameters\n";
    int count = 0, i;
    for (i=1; i<=3; i++) {
      count++;
      out << "     " << i << "   ";
      printRow(out, pars.display(count)); 
      out << "         # M_" << count << "(MX)" << endl;      
    }

    if (!altEwsb) {
      out << "     21  "; printRow(out, pars.display(63)) ; 
      out << "         # mHd^2(MX)" << endl;    
      out << "     22  "; printRow(out, pars.display(64)) ; 
      out << "         # mHu^2(MX)" << endl;    
    } else throw("Not yet implement alternative EWSB conditions with FV\n");

    out << "Block MSQ2IN # GUT-scale input for DRbar mass^2 parameter\n";
    int j; for (i=1; i<=3; i++)
      for (j=i; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block MSU2IN # GUT-scale input for DRbar mass^2 parameter\n";
    for (i=1; i<=3; i++)
      for (j=i; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block MSD2IN # GUT-scale input for DRbar mass^2 parameter\n";
    for (i=1; i<=3; i++)
      for (j=i; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block MSL2IN # GUT-scale input for DRbar mass^2 parameter\n";
    for (i=1; i<=3; i++)
      for (j=i; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block MSE2IN # GUT-scale input for DRbar mass^2 parameter\n";
    for (i=1; i<=3; i++)
      for (j=i; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block TUIN # GUT-scale input for DRbar mass parameter\n";    
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block TDIN # GUT-scale input for DRbar mass parameter\n";    
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    out << "Block TEIN # GUT-scale input for DRbar mass parameter\n";    
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	count++;
	out << "   " << i << " " << j << "   ";
	printRow(out, pars.display(count));
	out << endl;
      }
    if (fabs(pars.display(62)) > EPSTOL) 
      out << "# CAUTION: a universal A0=" << pars.display(62) 
	  << " was set in addition. It has been added on to trilinears\n";
  }
  else {
    ostringstream ii;
    ii << "Attempting to use SUSY Les Houches Accord for model " 
       << model << " - cannot do at present\n";
    throw ii.str();
  }
  
  headerHiggsSLHA(out, model, pars, sgnMu, tanb, qMax, numPoints, 
			 mgut, altEwsb);

  /// SLHA2 flavour sector defined in increasing order of mass
  DoubleVector m(6); int count = 0;
  sPhysical s(displayPhys());
  int i, j; for (i=1; i<=2; i++)
    for (j=1; j<=3; j++) {
      count++;
      m(count) = s.me(i, j);
    }
  m = m.sort();
  out << "   1000011    "; printRow(out, m(1)); out << "   # ~e_1\n";
  out << "   1000013    "; printRow(out, m(2)); out << "   # ~e_2\n";
  out << "   1000015    "; printRow(out, m(3)); out << "   # ~e_3\n";
  out << "   2000011    "; printRow(out, m(4)); out << "   # ~e_4\n";
  out << "   2000013    "; printRow(out, m(5)); out << "   # ~e_5\n";
  out << "   2000015    "; printRow(out, m(6)); out << "   # ~e_6\n";
      
  count = 0;
  for (i=1; i<=2; i++)
    for (j=1; j<=3; j++) {
      count++;
      m(count) = s.md(i, j);
    }
  m = m.sort();
  out << "   1000001    "; printRow(out, m(1)); out << "   # ~d_1\n";
  out << "   1000003    "; printRow(out, m(2)); out << "   # ~d_2\n";
  out << "   1000005    "; printRow(out, m(3)); out << "   # ~d_3\n";
  out << "   2000001    "; printRow(out, m(4)); out << "   # ~d_4\n";
  out << "   2000003    "; printRow(out, m(5)); out << "   # ~d_5\n";
  out << "   2000005    "; printRow(out, m(6)); out << "   # ~d_6\n";
      
  count = 0;
  for (i=1; i<=2; i++)
    for (j=1; j<=3; j++) {
      count++;
      m(count) = s.mu(i, j);
    }
  m = m.sort();
  out << "   1000002    "; printRow(out, m(1)); out << "   # ~u_1\n";
  out << "   1000004    "; printRow(out, m(2)); out << "   # ~u_2\n";
  out << "   1000006    "; printRow(out, m(3)); out << "   # ~u_3\n";
  out << "   2000002    "; printRow(out, m(4)); out << "   # ~u_4\n";
  out << "   2000004    "; printRow(out, m(5)); out << "   # ~u_5\n";
  out << "   2000006    "; printRow(out, m(6)); out << "   # ~u_6\n";
      
  m.setEnd(3); 
  for (i=1; i<=3; i++) m(i) = s.msnu(i);
  m.sort();
  out << "   1000012    "; printRow(out, m(1)); out << "   # ~nu_1\n";
  out << "   1000014    "; printRow(out, m(2)); out << "   # ~nu_2\n";
  out << "   1000016    "; printRow(out, m(3)); out << "   # ~nu_3\n";

  mixingSLHA(out, model, pars, sgnMu, tanb, qMax, numPoints, 
	     mgut, altEwsb);

  out << "Block USQMIX  # super CKM squark mass squared matrix\n";
  for (i=1; i<=6; i++)
    for (j=1; j<=6; j++) {
      out << "  " << i << "  " << j << "    "; 
      printRow(out, displayFlavourPhysical().uSqMix.display(i, j));
      out << "   # (USQMIX)_{" << i << j << "}" << endl;
    }
  
  out << "Block DSQMIX  # super CKM squark mass squared matrix\n";
  for (i=1; i<=6; i++)
    for (j=1; j<=6; j++) {
      out << "  " << i << "  " << j << "    "; 
      printRow(out, displayFlavourPhysical().dSqMix.display(i, j));
      out << "   # (DSQMIX)_{" << i << j << "}" << endl;
    }
  
  out << "Block SELMIX  # super MNS slepton mass squared matrix\n";
  for (i=1; i<=6; i++)
    for (j=1; j<=6; j++) {
      out << "  " << i << "  " << j << "    "; 
      printRow(out, displayFlavourPhysical().eSqMix.display(i, j));
      out << "   # (SELMIX)_{" << i << j << "}" << endl;
    }
  
  out << "Block SNUMIX  # super MNS slepton mass squared matrix\n";
  for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      out << "  " << i << "  " << j << "    "; 
      printRow(out, displayFlavourPhysical().nuSqMix.display(i, j));
      out << "   # (SNUMIX)_{" << i << j << "}" << endl;
    }
  
  int n = 0;
  
  while (n < numPoints) {
    n++;
    // Starting non-essential information. The following decides what scale to
    // output the running parameters at. It depends upon what qMax is and how
    // many points the user has requested.
    // For qMax = 0 and 1 point (defaults), Q=MSUSY is printed out.
    // For qMax = 0 and n points, points are spaced logarithmically between MZ
    // and MSUSY.
    // For qMax != 0 and 1 point, Q=qMax is printed.
    // For qMax != 0 and n points, points are log spaced between MZ and qMax.
    double ms = displayMsusy();
    double q = ms;
    if (numPoints == 1 && qMax < EPSTOL) q = ms;
    else if (numPoints == 1 && qMax > EPSTOL) q = qMax;
    else if (numPoints > 1 && qMax < EPSTOL) qMax = ms;

    if (numPoints > 1) { 
      if (n > 1) {
	double logq = (log(qMax) - log(MZ)) * double(n-1) / 
	  double(numPoints-1) + log(MZ);
	q = exp(logq);
      }
      else q = MZ;
    }
    
    runto(q); 
    double gp = displayGaugeCoupling(1) * sqrt(0.6);
    out << "Block gauge Q= " << q << "  \n";
    out << "     1     " << gp << "   # g'(Q)MSSM DRbar"
	 << endl;   
    out << "     2     " << displayGaugeCoupling(2) 
	 << "   # g(Q)MSSM DRbar" << endl;   
    out << "     3     " << displayGaugeCoupling(3) << "   # g3(Q)MSSM DRbar" 
	 << endl;   
    
    /// Find the Yukawa rotation matrices such that the super-CKM basis may be
    /// defined
    DoubleMatrix Ud(3, 3), Vd(3, 3), Uu(3, 3), Vu(3, 3);
    DoubleVector yu(3), yd(3);
    displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
    displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
    ckmNormalise(Vu, Vd, Uu, Ud); 
  
    DoubleMatrix Ue(3, 3), Ve(3, 3);
    DoubleVector ye(3);
    displayYukawaMatrix(YE).diagonalise(Ve, Ue, ye);
    
    DoubleMatrix tuSckm(3, 3), muSqSckm(3, 3);
    DoubleMatrix mqSqSckm(3, 3), tdSckm(3, 3), mdSqSckm(3, 3);
    mqSqSckm  = Vd.transpose() * displaySoftMassSquared(mQl) * Vd;
    tdSckm    = Ud.transpose() * displayTrilinear(DA).transpose() * Vd;
    mdSqSckm  = Ud.transpose() * displaySoftMassSquared(mDr).transpose() * 
      Ud; 

    tuSckm    = Uu.transpose() * displayTrilinear(UA).transpose() * Vu;
    muSqSckm  = Uu.transpose() * displaySoftMassSquared(mUr).transpose() * 
      Uu; 
    
    DoubleMatrix mlSqSckm(3, 3), teSckm(3, 3), meSqSckm(3, 3);
    mlSqSckm  = Ve.transpose() * displaySoftMassSquared(mLl) * Ve;
    teSckm    = Ue.transpose() * displayTrilinear(EA).transpose() * Ve;
    meSqSckm  = Ue.transpose() * displaySoftMassSquared(mEr).transpose() * 
      Ue; 

    /// There are often high degrees of cancellation in these matrices,
    /// meaning that at the 5th significant figure, one can have
    /// asymmetries. In order to avoid problems with users' codes, these are
    /// just symmetrised.
    mdSqSckm.symmetrise();
    muSqSckm.symmetrise();
    meSqSckm.symmetrise();   
    mqSqSckm.symmetrise();
    mlSqSckm.symmetrise();

    out << "Block msq2 Q= " << q << " # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, mqSqSckm(i, j));
	out << "   # (m^_Q^2)_{" << i << j << "}" << endl;
      }
    
    out << "Block msl2 Q= " << q << " # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, mlSqSckm(i, j));
	out << "   # (m^_L^2)_{" << i << j << "}" << endl;
      }
    
    out << "Block msd2 Q= " << q << " # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, mdSqSckm(i, j));
	out << "   # (m^_d^2)_{" << i << j << "}" << endl;
      }
    
    out << "Block msu2 Q= " << q << " # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, muSqSckm(i, j));
	out << "   # (m^_u^2)_{" << i << j << "}" << endl;
      }
    
    out << "Block mse2 Q= " << q << " # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, meSqSckm(i, j));
	out << "   # (m^_e^2)_{" << i << j << "}" << endl;
      }
    
    out << "Block tu Q= " << q << "  # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, tuSckm(i, j));
	out << "   # (T^_u)_{" << i << j << "}" << endl;
      }
    
    out << "Block td Q= " << q << "  # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, tdSckm(i, j));
	out << "   # (T^_d)_{" << i << j << "}" << endl;
      }
    
    out << "Block te Q= " << q << "  # super CKM squark mass squared matrix"
	<< " - DRbar" << endl;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; 
	printRow(out, teSckm(i, j));
	out << "   # (T^_e)_{" << i << j << "}" << endl;
      }
  
    out << "Block yu Q= " << q << "  # diagonal Up Yukawa matrix\n";
    for (i=1; i<=3; i++) {
      out << "  " << i << "  " << i << "     " << yu(i)
	  << "    # YU_{" << i << i << "}(Q)MSSM DRbar" << endl;
    }
    
    out << "Block yd Q= " << q << "  # diagonal down Yukawa matrix\n";
    for (i=1; i<=3; i++) {
      out << "  " << i << "  " << i << "     " << yd(i)
	  << "    # YD_{" << i << i << "}(Q)MSSM DRbar" << endl;
    }
    
    out << "Block ye Q= " << q << "  # diagonal lepton Yukawa matrix\n";
    for (i=1; i<=3; i++) {
      out << "  " << i << "  " << i << "     " << ye(i)
	  << "    # YE_{" << i << i << "}(Q)MSSM DRbar" << endl;
    }
    
    DoubleMatrix vCkm(Vu.transpose() * Vd);

    out << "Block VCKM Q= " << q << " # DRbar CKM mixing matrix\n";
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; printRow(out, vCkm(i, j));
	out << " # CKM_{" << i << j << "} matrix element" << endl;
      }
    
    out << "Block UPMNS Q= " << q << " # DRbar MNS mixing matrix:"
	<< " currently not running\n";
    DoubleMatrix uMns(displayMns());
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++) {
	out << "  " << i << "  " << j << "    "; printRow(out, uMns(i, j));
	out << " # UPMNS_{" << i << j << "} matrix element" << endl;
      }

    out << "Block hmix Q= " << q << 
      "  # Higgs mixing parameters\n";
    out << "     1    "; printRow(out, displaySusyMu()); 
    out << "   # mu(Q)MSSM DRbar\n";
    out << "     2    "; printRow(out, displayTanb()); 
    out << "   # tan beta(Q)MSSM DRbar\n";
    out << "     3    "; printRow(out, displayHvev()); 
    out << "   # higgs vev(Q)MSSM DRbar\n";
    out << "     4    "; 
    printRow(out, displayM3Squared() / 
	     (sin(atan(displayTanb())) * cos(atan(displayTanb())))); 
    out << "   # mA^2(Q)MSSM DRbar\n";

    out << "Block msoft Q= " << q 
	 << " # MSSM DRbar SUSY breaking parameters\n"; 
    int i;
    for (i=1; i<=3; i++) {
      out << "     " << i << "    "; 
      printRow(out, displayGaugino(i)); 
      out << "   # M_" << i << "(Q)" << endl;      
    }

    out << "    21    "; printRow(out, displayMh1Squared()); 
    out << "   # mH1^2(Q)" << endl;    
    out << "    22    "; printRow(out, displayMh2Squared()); 
    out << "   # mH2^2(Q)" << endl;    
  }
}

void FlavourMssmSoftsusy::doUpSquarks(double mt, double pizztMS, 
				      double sinthDRbarMS, int accuracy) { 
  /// now need to re-do 6 by 6 scalar mass matrices
  DoubleMatrix massUsq(6, 6);

  /// super CKM basis mass squared matrices
  DoubleMatrix Ud(3, 3), Vd(3, 3), Uu(3, 3), Vu(3, 3);
  DoubleVector yu(3), yd(3);
  displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
  displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
  ckmNormalise(Vu, Vd, Uu, Ud); 

  DoubleMatrix mqSqSckm(3, 3), tuSckm(3, 3), muSqSckm(3, 3);
  mqSqSckm  = Vu.transpose() * displaySoftMassSquared(mQl) * Vu;
  tuSckm    = Uu.transpose() * displayTrilinear(UA).transpose() * Vu;
  muSqSckm  = Uu.transpose() * displaySoftMassSquared(mUr).transpose() * 
    Uu; 

  DoubleVector mu(3), md(3);

  double susyMu = displaySusyMu();
  double vev = displayHvev();
  double tanb = displayTanb(), beta = atan(tanb);
  double sinb = sin(beta), cosb = cos(beta);
  const double sqrt2 = sqrt(2.0);
  /// the following contributions are only calculated at tree-level:
  int i, j;   for (i=1; i<=3; i++) {
    mu(i) = yu(i) * vev / sqrt2 * sinb;
    md(i) = yd(i) * vev / sqrt2 * cosb;

    for (j=i; j<=3; j++) {
      massUsq(i, j) = mqSqSckm(i, j);
      if (i == j) {
	massUsq(i, j) = massUsq(i, j) + sqr(mu(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (0.5 - 2. / 3. * sqr(sinthDRbarMS));
      }
    }
  
    for (j=4; j<=6; j++) {
      massUsq(i, j) = vev * sinb / sqrt2 * tuSckm(j-3, i);
      if (i == j-3) massUsq(i, j) = massUsq(i, j) - susyMu * mu(i) / tanb;
    }
  }

  for (i=4; i<=6; i++)
    for (j=i; j<=6; j++) {
      massUsq(i, j) = muSqSckm(i - 3, j - 3);
      if (i == j) massUsq(i, j) = massUsq(i, j) + 
		    cos(2.0 * beta) * sqr(displayMzRun()) * 
		    sqr(sinthDRbarMS) * 2.0 / 3.0 + sqr(mu(i - 3)); 
    }

  /// add loop corrections to the family-universal pieces
  DoubleMatrix temp(2, 2);
  double p = displayMsusy();
  int family; for (family=1; family<=3; family++) {
    temp(1, 1) = massUsq(family, family);
    temp(1, 2) = massUsq(family, family + 3);
    temp(2, 2) = massUsq(family + 3, family + 3);

    if (family < 3) addSupCorrection(temp, family);
    else addStopCorrection(p, temp, mu(family));
    massUsq(family, family) = temp(1, 1);
    massUsq(family, family + 3) = temp(1, 2);
    massUsq(family + 3, family + 3) = temp(2, 2);
  }
  
  massUsq.symmetrise();

  DoubleMatrix uSqMixT(6, 6);
  DoubleVector uSqMasses(6);
  if (massUsq.diagonaliseSym(uSqMixT, uSqMasses) > EPSTOL) {
    throw("WARNING: up squark flavour diagonalisation bad accuracy\n");
  }

  fv.uSqMix = uSqMixT.transpose();
  fv.msU = uSqMasses.apply(ccbSqrt);
  if (fv.msU.min(j) < 0.) {
    flagTachyon(true);
    if (PRINTOUT > 1) cout << " up squark(" << j << ") tachyon";
  }

  // fill in the flavour conserving parts with the correct masses
  int t1Pos = 0;
  sPhysical s(displayPhys());

  for(i=1; i<=3; i++) {
    fv.uSqMix.displayCol(i).apply(fabs).max(j); 
    s.mu(1, i) = fv.msU(j);
    if (i == 3) t1Pos = j;
    fv.uSqMix.displayCol(i+3).apply(fabs).max(j); 
    s.mu(2, i) = fv.msU(j);
  }
  setPhys(s);

  s.thetat = asin(fv.uSqMix(t1Pos, 6));
  setPhys(s);

}

void FlavourMssmSoftsusy::doDownSquarks(double mb, double pizztMS, 
					double sinthDRbarMS, int accuracy, 
					double mt) { 
  /// now need to re-do 6 by 6 scalar mass matrices
  DoubleMatrix massDsq(6, 6);

  /// Find the Yukawa rotation matrices such that the super-CKM basis may be
  /// defined
  DoubleMatrix Ud(3, 3), Vd(3, 3), Uu(3, 3), Vu(3, 3);
  DoubleVector yu(3), yd(3);
  displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
  displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
  ckmNormalise(Vu, Vd, Uu, Ud); 

  DoubleMatrix mqSqSckm(3, 3), tdSckm(3, 3), mdSqSckm(3, 3);
  mqSqSckm  = Vd.transpose() * displaySoftMassSquared(mQl) * Vd;
  tdSckm    = Ud.transpose() * displayTrilinear(DA).transpose() * Vd;
  mdSqSckm  = Ud.transpose() * displaySoftMassSquared(mDr).transpose() * 
    Ud; 

  DoubleVector mu(3), md(3);

  double susyMu = displaySusyMu();
  double vev = displayHvev();
  double tanb = displayTanb(), beta = atan(tanb);
  double sinb = sin(beta), cosb = cos(beta);
  const double sqrt2 = sqrt(2.0);
  /// the following contributions are only calculated at tree-level:
  int i, j;   for (i=1; i<=3; i++) {
    mu(i) = yu(i) * vev / sqrt2 * sinb;
    md(i) = yd(i) * vev / sqrt2 * cosb;

    for (j=i; j<=3; j++) {
      massDsq(i, j) = mqSqSckm(i, j);
      if (i == j) {
	massDsq(i, j) = massDsq(i, j) + sqr(md(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (-0.5 + 1. / 3. * sqr(sinthDRbarMS));
      }
    }

    for (j=4; j<=6; j++) {
      massDsq(i, j) = vev * cosb / sqrt2 * tdSckm(j-3, i);
      if (i == j-3) massDsq(i, j) = massDsq(i, j) - susyMu * md(i) * tanb;
    }
  }

  for (i=4; i<=6; i++)
    for (j=i; j<=6; j++) {
      massDsq(i, j) = mdSqSckm(i - 3, j - 3);
	  if (i == j) massDsq(i, j) = massDsq(i, j) -
		    cos(2.0 * beta) * sqr(displayMzRun()) * 
		    sqr(sinthDRbarMS) * 1.0 / 3.0 + sqr(md(i - 3));
    }

  /// add loop corrections to the family-universal pieces
  DoubleMatrix temp(2, 2);

  /// p is for sbottom corrections
  double p = sqrt(displayDrBarPars().md.display(1, 3) * 
		  displayDrBarPars().md.display(2, 3));
  if (accuracy > 0) {
  int family; for (family=1; family<=3; family++) {
    temp(1, 1) = massDsq(family, family);
    temp(1, 2) = massDsq(family, family + 3);
    temp(2, 2) = massDsq(family + 3, family + 3);

    if (family < 3) addSdownCorrection(temp, family);
    else addSbotCorrection(p, temp, md(family));
    massDsq(family, family) = temp(1, 1);
    massDsq(family, family + 3) = temp(1, 2);
    massDsq(family + 3, family + 3) = temp(2, 2);
  }
  }

  massDsq.symmetrise();

  DoubleMatrix dSqMixT(6, 6);
  DoubleVector dSqMasses(6);
  if (massDsq.diagonaliseSym(dSqMixT, dSqMasses) > EPSTOL) {
    throw("WARNING: dn squark flavour diagonalisation bad accuracy\n");
  }

  fv.dSqMix = dSqMixT.transpose();
  fv.msD = dSqMasses.apply(ccbSqrt);

  if (fv.msD.min(j) < 0.) {
    flagTachyon(true);
    if (PRINTOUT > 1) cout << " down squark(" << j << ") tachyon";
  }

  // fill in the flavour conserving parts with the correct masses
  sPhysical s(displayPhys());
  int b1Pos = 0;
  for(i=1; i<=3; i++) {
    fv.dSqMix.displayCol(i).max(j); 
    s.md(1, i) = fv.msD(j);
    b1Pos = j;
    fv.dSqMix.displayCol(i+3).max(j); 
    s.md(2, i) = fv.msD(j);
  }

  s.thetab = asin(fv.dSqMix(b1Pos, 6));
  setPhys(s);
}

void FlavourMssmSoftsusy::doChargedSleptons(double mtau, double pizztMS, 
					    double sinthDRbarMS, 
					    int accuracy) { 
  //  MssmSoftsusy::doDownSquarks(mb, pizztMS, sinthDRbarMS, accuracy, mt); 
  /// now need to re-do 6 by 6 scalar mass matrices
  DoubleMatrix massEsq(6, 6);

  /// Find the Yukawa rotation matrices such that the super-CKM basis may be
  /// defined
  DoubleMatrix Ue(3, 3), Ve(3, 3);
  DoubleVector ye(3);
  displayYukawaMatrix(YE).diagonalise(Ue, Ve, ye);

  /// super MNS basis mass squared matrices
  DoubleMatrix mlSqSckm(3, 3), teSckm(3, 3), meSqSckm(3, 3);
  mlSqSckm  = Ve.transpose() * displaySoftMassSquared(mLl) * Ve;
  teSckm    = Ue.transpose() * displayTrilinear(EA).transpose() * Ve;
  meSqSckm  = Ue.transpose() * displaySoftMassSquared(mEr).transpose() * 
    Ue; 

  DoubleVector me(3);

  double susyMu = displaySusyMu();
  double vev = displayHvev();
  double tanb = displayTanb(), beta = atan(tanb);
  double cosb = cos(beta);
  const double sqrt2 = sqrt(2.0);
  /// the following contributions are only calculated at tree-level:
  int i, j;   for (i=1; i<=3; i++) {
    me(i) = ye(i) * vev / sqrt2 * cosb;

    for (j=i; j<=3; j++) {
      massEsq(i, j) = mlSqSckm(i, j);
      if (i == j) {
	massEsq(i, j) = massEsq(i, j) + sqr(me(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (-0.5 + sqr(sinthDRbarMS));
      }
    }
  
    for (j=4; j<=6; j++) {
      massEsq(i, j) = vev * cosb / sqrt2 * teSckm(j-3, i);
      if (i == j-3) massEsq(i, j) = massEsq(i, j) - susyMu * me(i) * tanb;
    }
  }

  for (i=4; i<=6; i++)
    for (j=i; j<=6; j++) {
      massEsq(i, j) = meSqSckm(i - 3, j - 3);
      if (i == j) massEsq(i, j) = massEsq(i, j) -
		    cos(2.0 * beta) * sqr(displayMzRun()) * 
		    sqr(sinthDRbarMS) + sqr(me(i - 3));
    }

  /// add loop corrections to the family-universal pieces
  if (accuracy > 0) {
  DoubleMatrix temp(2, 2);
  double p = displayMsusy();
  int family; for (family=1; family<=3; family++) {
    temp(1, 1) = massEsq(family, family);
    temp(1, 2) = massEsq(family, family + 3);
    temp(2, 2) = massEsq(family + 3, family + 3);

    if (family < 3) addSlepCorrection(temp, family);
    else addStauCorrection(p, temp, me(family));
    massEsq(family, family) = temp(1, 1);
    massEsq(family, family + 3) = temp(1, 2);
    massEsq(family + 3, family + 3) = temp(2, 2);
    }
  }
  
  massEsq.symmetrise();

  DoubleMatrix eSqMixT(6, 6);
  DoubleVector eSqMasses(6);
  if (massEsq.diagonaliseSym(eSqMixT, eSqMasses) > EPSTOL) {
    throw("WARNING: charged slepton flavour diagonalisation bad accuracy\n");
  }

  fv.eSqMix = eSqMixT.transpose();
  fv.msE = eSqMasses.apply(ccbSqrt);
  if (fv.msE.min(j) < 0.) {
    flagTachyon(true);
    if (PRINTOUT > 1) cout << " down slepton(" << j << ") tachyon";
  }

  // fill in the flavour conserving parts with the correct masses
  sPhysical s(displayPhys());
  int b1Pos = 0;
  for(i=1; i<=3; i++) {
    fv.eSqMix.displayCol(i).max(j); 
    s.me(1, i) = fv.msE(j);
    b1Pos = j;
    fv.eSqMix.displayCol(i+3).max(j); 
    s.me(2, i) = fv.msE(j);
  }

  s.thetatau = asin(fv.eSqMix(b1Pos, 6));
  setPhys(s);
}

void FlavourMssmSoftsusy::doSnu(double pizztMS, int accuracy) {
  
  /// Find the Yukawa rotation matrices such that the super-CKM basis may be
  /// defined
  DoubleMatrix Ue(3, 3), Ve(3, 3);
  DoubleVector ye(3);
  displayYukawaMatrix(YE).diagonalise(Ve, Ue, ye);

  DoubleMatrix uMns(displayMns());

  DoubleMatrix mNuSq(uMns.transpose() * Ve.transpose() * 
		     displaySoftMassSquared(mLl) * Ve * uMns);
  double beta = atan(displayTanb());
  int i, j; for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      if (i == j) {
	mNuSq(i, j) = mNuSq(i, j) + 0.5 * sqr(displayMzRun()) * 
	  cos(2.0 * beta);
	if (accuracy > 0) addSnuCorrection(mNuSq(i, j), i);	
      }
    }
  
  DoubleMatrix nuSqMix(3, 3);
  DoubleVector nuSqMasses(3);
  if (mNuSq.diagonaliseSym(nuSqMix, nuSqMasses) > EPSTOL) {
    throw("WARNING: up squark flavour diagonalisation bad accuracy\n");
  }
  
  fv.nuSqMix = nuSqMix.transpose();
  fv.msNu = nuSqMasses.apply(ccbSqrt);
  if (fv.msNu.min(j) < 0.) {
    flagTachyon(true);
    if (PRINTOUT > 1) cout << " down sneutrino(" << j << ") tachyon";
  }
  
  sPhysical s(displayPhys());
  for (i=1; i<=3; i++) {
    fv.nuSqMix.displayRow(i).max(j);
    s.msnu(i) = fv.msNu(j);
  }
  setPhys(s);  
}

const flavourPhysical & flavourPhysical::operator=(const flavourPhysical &s) {
  if (this == &s) return *this;
  dSqMix = s.dSqMix;
  uSqMix = s.uSqMix;
  eSqMix = s.eSqMix;
  nuSqMix = s.nuSqMix;
  msD = s.msD;
  msU = s.msU;
  msE = s.msE;
  msNu = s.msNu;
  return *this;
}

void FlavourMssmSoftsusy::doQuarkMixing(DoubleMatrix & mDon, 
						DoubleMatrix & mUpq) {
  if (MIXING < -1 || MIXING > 4) {
    ostringstream ii;
    ii << "In FlavourMssmSoftsusy::sparticleThresholdCorrections(double tb) ";
    ii << "\n MIXING=" << MIXING << " is out of range (-1 -> 4)\n";
    throw ii.str();
  }

  DoubleMatrix vCkm(displayCkm());
  switch(MIXING) {
  case 1:       
    mUpq = vCkm.transpose() * mUpq * vCkm;
    break;
  case 2: 
    mDon = vCkm * mDon * vCkm.transpose();
    break;
  case 3:
    mUpq = vCkm.transpose() * mUpq;
    break;
  case 4:
    mDon = vCkm * mDon;
    break;
  default:
    return;
  }    
}

ostream & operator <<(ostream & left, const flavourPhysical &s) {
  left << "mu: " << s.msU << "uMix: " << s.uSqMix;
  left << "md: " << s.msD << "dMix: " << s.dSqMix;
  left << "me: " << s.msE << "eMix: " << s.eSqMix;
  left << "mnu: " << s.msNu << "nuMix: " << s.nuSqMix;
  return left;
}

istream & operator >>(istream & left, flavourPhysical &s) {
  char c[70];
  left >> c >> s.msU;
  left >> c >> c >> s.uSqMix;
  
  left >> c >> s.msD; 
  left >> c >> c >> s.dSqMix;  

  left >> c >> s.msE; 
  left >> c >> c >> s.eSqMix;  

  left >> c >> s.msNu; 
  left >> c >> c >> s.nuSqMix;  

  return left;
}

// calculates masses all at tree-level in the DRbar scheme, useful for
// radiative corrections. 
void FlavourMssmSoftsusy::calcDrBarPars() {
  // First, must define mstop,sbot,stau and mixing angles in DRbar scheme
  double beta = atan(displayTanb());
  double sinthDRbar = calcSinthdrbar();
  double mz = displayMzRun(), mz2 = sqr(mz);

  sw2 = sqr(sinthDRbar);
  guL = 0.5 - 2.0 * sw2 / 3.0;
  gdL = -0.5 + sw2 / 3.0;
  geL = -0.5 + sw2;
  guR = 2.0 * sw2 / 3.0;
  gdR = -sw2 / 3.0;
  geR = -sw2;

  double vev = displayHvev();

  DoubleMatrix massUsq(6, 6), massDsq(6, 6), massEsq(6, 6);
  /// Find the Yukawa rotation matrices such that the super-CKM basis may be
  /// defined
  DoubleMatrix Ud(3, 3), Vd(3, 3), Uu(3, 3), Vu(3, 3), Ue(3, 3), Ve(3, 3);
  DoubleVector ye(3), yu(3), yd(3);
  displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
  displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
  displayYukawaMatrix(YE).diagonalise(Ue, Ve, ye);
    ckmNormalise(Vu, Vd, Uu, Ud); 

  DoubleMatrix mqSqSckm(3, 3), mqSqUckm(3, 3), tdSckm(3, 3), mdSqSckm(3, 3), 
    tuSckm(3, 3), muSqSckm(3, 3), mlSqSckm(3, 3), teSckm(3, 3), meSqSckm(3, 3);
  mqSqSckm  = Vd.transpose() * displaySoftMassSquared(mQl) * Vd;
  mqSqUckm  = Vu.transpose() * displaySoftMassSquared(mQl) * Vu;
  tdSckm    = Ud.transpose() * displayTrilinear(DA).transpose() * Vd;
  mdSqSckm  = Ud.transpose() * displaySoftMassSquared(mDr).transpose() * 
    Ud; 
  tuSckm    = Uu.transpose() * displayTrilinear(UA).transpose() * Vu;
  muSqSckm  = Uu.transpose() * displaySoftMassSquared(mUr).transpose() * 
    Uu; 
  mlSqSckm  = Ve.transpose() * displaySoftMassSquared(mLl) * Ve;
  teSckm    = Ue.transpose() * displayTrilinear(EA).transpose() * Ve;
  meSqSckm  = Ue.transpose() * displaySoftMassSquared(mEr).transpose() * Ue; 

  DoubleVector mu(3), md(3), me(3);

  double susyMu = displaySusyMu();
  double tanb = displayTanb();
  double sinb = sin(beta), cosb = cos(beta);
  const double sqrt2 = sqrt(2.0);
  /// the following contributions are only calculated at tree-level:
  int i, j;   for (i=1; i<=3; i++) {
    me(i) = ye(i) * vev / sqrt2 * cosb;
    mu(i) = yu(i) * vev / sqrt2 * sinb;
    md(i) = yd(i) * vev / sqrt2 * cosb;

    for (j=i; j<=3; j++) {
      massUsq(i, j) = mqSqUckm(i, j);
      massDsq(i, j) = mqSqSckm(i, j);
      massEsq(i, j) = mlSqSckm(i, j);
      if (i == j) {
	massUsq(i, j) = massUsq(i, j) + sqr(mu(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (0.5 - 2. / 3. * sqr(sinthDRbar));
	massDsq(i, j) = massDsq(i, j) + sqr(md(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (-0.5 + 1. / 3. * sqr(sinthDRbar));
	massEsq(i, j) = massEsq(i, j) + sqr(me(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (-0.5 + sqr(sinthDRbar));
	
      }
    }
  
    for (j=4; j<=6; j++) {
      massUsq(i, j) = vev * sinb / sqrt2 * tuSckm(j-3, i);
      massDsq(i, j) = vev * cosb / sqrt2 * tdSckm(j-3, i);
      massEsq(i, j) = vev * cosb / sqrt2 * teSckm(j-3, i);
      if (i == j-3) {
	massUsq(i, j) = massUsq(i, j) - susyMu * mu(i) / tanb;
	massDsq(i, j) = massDsq(i, j) - susyMu * md(i) * tanb;
	massEsq(i, j) = massEsq(i, j) - susyMu * me(i) * tanb;
      }
    }  
  }
    
  for (i=4; i<=6; i++)
    for (j=i; j<=6; j++) {
      massUsq(i, j) = muSqSckm(i - 3, j - 3);
      massDsq(i, j) = mdSqSckm(i - 3, j - 3);
      massEsq(i, j) = meSqSckm(i - 3, j - 3);
      if (i == j) {
	massUsq(i, j) = massUsq(i, j) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  sqr(sinthDRbar) * 2.0 / 3.0 + sqr(mu(i - 3)); 
	massDsq(i, j) = massDsq(i, j) -
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  sqr(sinthDRbar) * 1.0 / 3.0 + sqr(md(i - 3));
	massEsq(i, j) = massEsq(i, j) -
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  sqr(sinthDRbar) + sqr(me(i - 3));
      }
    }

  massUsq.symmetrise();
  massDsq.symmetrise();
  massEsq.symmetrise();

  /// These are the TRANSPOSES of the matrices defined in SLHA2. 
  DoubleMatrix uSqMixT(6, 6), dSqMixT(6, 6), eSqMixT(6, 6);
  DoubleVector uSqMasses(6), dSqMasses(6), eSqMasses(6);
  massUsq.diagonaliseSym(uSqMixT, uSqMasses);
  massDsq.diagonaliseSym(dSqMixT, dSqMasses);
  massEsq.diagonaliseSym(eSqMixT, eSqMasses);
  for (i=1; i<=6; i++) 
    if (uSqMasses(i) < 0. || eSqMasses(i) < 0. || dSqMasses(i) < 0.) {
      flagTachyon(true);
      i=7;
      if (PRINTOUT > 1) cout << " tree sfermion tachyon ";
      if (PRINTOUT > 2) cout << uSqMasses << dSqMasses << eSqMasses;
    }
  
  uSqMasses = uSqMasses.apply(ccbSqrt);
  dSqMasses = dSqMasses.apply(ccbSqrt);
  eSqMasses = eSqMasses.apply(ccbSqrt);

  drBarPars s(displayDrBarPars());
  int b1Pos = 0, t1Pos = 0, tau1Pos = 0;
  for(i=1; i<=3; i++) {
    uSqMixT.displayRow(i).max(j); 
    s.mu(1, i) = uSqMasses(j);
    if (i == 3) t1Pos = j;
    uSqMixT.displayRow(i+3).max(j); 
    s.mu(2, i) = uSqMasses(j);
    dSqMixT.displayRow(i).max(j); 
    s.md(1, i) = dSqMasses(j);
    if (i == 3) b1Pos = j;
    dSqMixT.displayRow(i+3).max(j); 
    s.md(2, i) = dSqMasses(j);
    eSqMixT.displayRow(i).max(j); 
    s.me(1, i) = eSqMasses(j);
    if (i == 3) tau1Pos = j;
    eSqMixT.displayRow(i+3).max(j); 
    s.me(2, i) = eSqMasses(j);
  }
  s.thetat   = asin(uSqMixT(6, t1Pos));
  s.thetab   = asin(dSqMixT(6, b1Pos));
  s.thetatau = asin(eSqMixT(6, tau1Pos));

  //  if (close(displayMu(), MZ, EPSTOL)) 
  //  cout << "stop calc: " << s.mu(1, 3) << " " << s.mu(2, 3) << 
  //    " " << s.thetat << " " << endl;


  DoubleMatrix uMns(displayMns());
  DoubleMatrix mNuSq(uMns.transpose() * Ve.transpose() * 
		     displaySoftMassSquared(mLl) * Ve * uMns);
  for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      if (i == j) {
	mNuSq(i, j) = mNuSq(i, j) + 0.5 * sqr(displayMzRun()) * 
	  cos(2.0 * beta);
      }
    }
  DoubleMatrix nuSqMix(3, 3);
  DoubleVector nuSqMasses(3);
  mNuSq.diagonaliseSym(nuSqMix, nuSqMasses);
  nuSqMasses = nuSqMasses.apply(ccbSqrt);
  for (i=1; i<=3; i++) {
    nuSqMix.displayRow(i).max(j);
    s.msnu(i) = nuSqMasses(j);
  }

  s.ht = yu(3);        s.hb = yd(3);        s.htau = ye(3);
  s.ut = tuSckm(3, 3); s.ub = tdSckm(3, 3); s.utau = teSckm(3, 3);

  s.mt   = s.ht   * vev * sin(beta) / root2;
  s.mb   = s.hb   * vev * cos(beta) / root2;
  s.mtau = s.htau * vev * cos(beta) / root2; 

  s.mGluino = displayGaugino(3);

  DoubleMatrix mCh(2, 2);   
  double mw = displayMwRun();
  double mw2 = sqr(mw);
  mCh(1, 1) = displayGaugino(2);
  mCh(2, 1) = root2 * mw * cos(beta); 
  mCh(1, 2) = mCh(2, 1) * displayTanb();
  mCh(2, 2) = displaySusyMu();
  s.mch = mCh.asy2by2(s.thetaL, s.thetaR);
 
  DoubleMatrix mNeut(4, 4);
  mNeut(1, 1) = displayGaugino(1);
  mNeut(2, 2) = displayGaugino(2);
  mNeut(1, 3) = - mz * cos(beta) * sinthDRbar;
  mNeut(1, 4) = - mNeut(1, 3) * displayTanb();
  mNeut(2, 3) = mw * cos(beta);
  mNeut(2, 4) = - mNeut(2, 3) * displayTanb();
  mNeut(3, 4) = - displaySusyMu();
  mNeut.symmetrise();
  if (mNeut.diagonaliseSym(s.mixNeut, s.mneut) > TOLERANCE *
      1.0e-3) { 
    ostringstream ii;
    ii << "accuracy bad in neutralino diagonalisation"<< flush;
    throw ii.str(); 
    }

  s.mw = mw;
  s.mz = mz;
  s.mpzNeutralinos();
  s.mpzCharginos();

  setDrBarPars(s); 
  double mAsq = displayM3Squared() / (sin(beta) * cos(beta));

  if (mAsq < 0.0) {
    // If it's for the EWSB BC at MZ, we simply use the one-loop corrected
    // mass for mA instead. You could indeed make this option permanent (ie
    // even for mAsq > 0) 
    double tol = EPSTOL;
    if (close(displayMu(), MZ, tol)) {
      double mApole = displayPhys().mhiggs.display(2); // physical value
      double piaa = piAA(mApole, displayMu()); 
      double t1Ov1 = doCalcTadpole1oneLoop(s.mt, sinthDRbar), 
	t2Ov2 = doCalcTadpole2oneLoop(s.mt, sinthDRbar); 
      double poleMasq = 
	(displayMh2Squared() - t2Ov2 - 
	 displayMh1Squared() + t1Ov1) / 
	cos(2.0 * beta) - mz2 - piaa +
	sqr(sin(beta)) * t1Ov1 + sqr(cos(beta)) * t2Ov2;

      if (PRINTOUT > 2) cout << "mA^2(tree)=" << mAsq << " pole=" << poleMasq 
			     << endl;

      if (mAsq < 0.) { flagTachyon(true); mAsq = fabs(poleMasq); }
    } 
    else {
      flagTachyon(true);
      if (PRINTOUT > 1) cout << " mA^2(tree)=" << mAsq << " since m3sq=" <<
			  displayM3Squared() << " @ "<< displayMu() <<
			  " " << endl; 
      mAsq = fabs(mAsq);
    }
  }

  DoubleVector mSq(2);
  DoubleMatrix mH(2, 2); 
  mH(1, 1) = mAsq * sqr(sin(beta)) + mz2 * sqr(cos(beta));
  mH(1, 2) = - sin(beta) * cos(beta) * (mAsq + mz2); 
  mH(2, 2) = mAsq * sqr(cos(beta)) + mz2 * sqr(sin(beta)); 
  mH(2, 1) = mH(1 ,2); 
  mSq = mH.sym2by2(s.thetaH);
  if (mSq(1) < 0. || mSq(2) < 0.) {
    flagTachyon(true);
    if (PRINTOUT > 1) cout << " mH/h tachyon ";
  }
  DoubleVector temp(mSq.apply(ccbSqrt));
  if (temp(2) > temp(1)) s.thetaH = s.thetaH + PI * 0.5; 

  int pos;
  s.mhiggs(1) = temp.min(pos); s.mhiggs(3) = temp.max(); 
  s.mhiggs(2) = sqrt(mAsq); s.mhiggs(4) = sqrt(mAsq + mw2);

  setDrBarPars(s);

  return;
}

MssmSusy FlavourMssmSoftsusy::guessAtSusyMt(double tanb, 
					    const QedQcd & oneset) { 

  // This bit gives a guess at a SUSY object
  QedQcd leAtMt(oneset);

  DoubleVector a(3), g(3);
  double sinth2 = 1.0 - sqr(MW / MZ);
  // Gauge couplings at mt
  a = leAtMt.getGaugeMu(oneset.displayPoleMt(), sinth2);
  
  MssmSusy t(MssmSoftsusy::guessAtSusyMt(tanb, oneset));
  DoubleMatrix yu(t.displayYukawaMatrix(YU)), yd(t.displayYukawaMatrix(YD)); 
  
  doQuarkMixing(yd, yu);
  t.setYukawaMatrix(YU, yu);
  t.setYukawaMatrix(YD, yd);

  return t;
}

/*void FlavourMssmSoftsusy::sparticleThresholdCorrections(double tb) {
  MssmSoftsusy::sparticleThresholdCorrections(tb);
  DoubleMatrix v(displayMns());
  setYukawaMatrix(YE, v * displayYukawaMatrix(YE) * v.transpose());
  }*/


void FlavourMssmSoftsusy::setAngles(double lambda, double aCkm, double rhobar, 
				    double etabar) {
  theta12 = asin(lambda);
  theta23 = asin(aCkm * sqr(lambda));

  double lambda3 = lambda * sqr(lambda);
  double lambda4 = lambda * lambda3;

  Complex rpe(rhobar, etabar);
  Complex lhs = aCkm * lambda3 * rpe * sqrt(1.0 - sqr(aCkm) * lambda4) / 
    sqrt(1.0 - sqr(lambda)) / (1.0 - sqr(aCkm) * lambda4 * rpe);

  theta13 = asin(lhs.mod());
  deltaCkm = lhs.arg();
}

void FlavourMssmSoftsusy::sCkm 
(DoubleMatrix & deltaULL, DoubleMatrix & deltaURR, DoubleMatrix & deltaULR, 
 DoubleMatrix & deltaDLL, DoubleMatrix & deltaDRR, DoubleMatrix & deltaDLR) 
  const {

  flavourPhysical fv(displayFlavourPhysical());

  DoubleMatrix mupsq(6, 6), msdsq(6, 6), mudiagsq(6, 6), mddiagsq(6, 6);
  int i; for (i=1; i<=6; i++) {
    mudiagsq(i, i) = sqr(fv.msU(i)); mddiagsq(i, i) = sqr(fv.msD(i));
  }

  mupsq = fv.uSqMix.transpose() * mudiagsq * fv.uSqMix;
  msdsq = fv.dSqMix.transpose() * mddiagsq * fv.dSqMix;

  int j;
  for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      deltaULL(i, j) = mupsq(i, j) / 
	(sqrt(fabs(mupsq(i, i) * mupsq(j, j))));
      deltaURR(i, j) = mupsq(i+3, j+3) / 
	(sqrt(fabs(mupsq(i+3, i+3) * mupsq(j+3, j+3))));
      deltaULR(i, j) = mupsq(i, j+3) / (sqrt(fabs(mupsq(i, i) * 
						 mupsq(j+3, j+3))));
      deltaDLL(i, j) = msdsq(i, j) / 
	  (sqrt(fabs(msdsq(i, i) * msdsq(j, j))));
      deltaDRR(i, j) = msdsq(i+3, j+3) / 
	(sqrt(fabs(msdsq(i+3, i+3) * msdsq(j+3, j+3))));
      deltaDLR(i, j) = msdsq(i, j+3) / 
	(sqrt(fabs(msdsq(i, i) * msdsq(j+3, j+3))));
    }
}


void FlavourMssmSoftsusy::sCkmAnalytic
(double m32, double & deltaULL23, double & deltaULR23,
 double & deltaULL12, double & deltaDLL23, double & deltaDLR23, 
 double & deltaDLL12)  const { 

  drBarPars d(displayDrBarPars());

  double mfac = m32 / (16 * sqr(PI));
  
  double beta = atan(displayTanb());
  double c2b = cos(2 * beta);
  double mt = d.mt;
  double sinth = calcSinthdrbar();
  double sinthw2 = sqr(sinth);
  double lt = d.ht, lb = d.hb, ltau = d.htau;
  //  double ls = displayYukawaElement(YD, 2, 2);
  double gs = displayGaugeCoupling(3);
  double gw = displayGaugeCoupling(2);
  double g1 = displayGaugeCoupling(1);
  double mb = d.mb;


  double vd = displayHvev() * cos(beta);
  double vu = displayHvev() * sin(beta);
  
  DoubleMatrix Vu(3, 3), Uu(3, 3); DoubleVector yu(3);
  displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
  DoubleMatrix Vd(3, 3), Ud(3, 3); DoubleVector yd(3);
  displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
  ckmNormalise(Vu, Vd, Uu, Ud); 
  DoubleMatrix V(displayCkm());
  // DoubleMatrix V(Vu.transpose() * Vd);
  double lc = yu(2), ls = yd(2);

  double ddownL = sqr(MZ) * (-1./2. + 1./3. * sinthw2) * c2b;
  double ddownR = sqr(MZ) * (-1./3.) * sinthw2 * c2b;
  double dupL = sqr(MZ) * (0.5 - 2./3. * sinthw2) * c2b;
  double dupR = sqr(MZ) * 2/3 * sinthw2 * c2b;
  double bett = -13./15. * sqr(g1) - 3. * sqr(gw) - 16/3. * sqr(gs) + 
    6. * sqr(lt) + sqr(lb);
  double betb = -7./15. * sqr(g1) - 3. * sqr(gw) - 16/3. * sqr(gs) + 
    6. * sqr(lb) + sqr(ltau) + sqr(lt);

  double mdLR23 = -vd / sqrt(2.0) * mfac * lb * sqr(lt) * V(3, 2) * V(3, 3);
  double mdL23 = sqr(mfac) * V(3, 2) * V(3, 3) * sqr(lt) * (bett);
  double mdLii = ddownL + sqr(mfac) * 
      (-11./50. * sqr(sqr(g1)) - 1.5 * sqr(sqr(gw)) + 8 * sqr(sqr(gs)));
  double mdLij = sqr(mfac) * V(3, 1) * V(3, 2) * sqr(lt) * (bett - sqr(lb));

  /// Ben's correction factor
  /*  mdLij += sqr(mfac) * V(2, 1) * V(2, 2) * sqr(lc) * 
      (bett - sqr(lb) - 3.0 * sqr(lt));*/

  double mdL33 = sqr(mb) + ddownL + 
    sqr(mfac) * (-11./50. * sqr(sqr(g1)) - 1.5 * sqr(sqr(gw)) + 
		 8 * sqr(sqr(gs)) + sqr(lt) * bett + sqr(lb) * betb);
  double mdR33 = sqr(mb) + ddownR + sqr(mfac) * 
    (-22./25. * sqr(sqr(g1)) + 8 * sqr(sqr(gs)) + 2 * sqr(lb) * betb);

  deltaDLL23 = mdL23 / sqrt(mdL33 * mdLii);
  deltaDLR23 = mdLR23 / sqrt(mdLii * mdR33);
  deltaDLL12 = mdLij / mdLii;

  double muL33 = sqr(mt) + dupL + 
    sqr(mfac) * (-11./50. * 
		 sqr(sqr(g1)) - 1.5 * sqr(sqr(gw)) + 8 * sqr(sqr(gs)) 
		 + sqr(lt) * bett + sqr(lb) * betb);
  double muLi3 = sqr(mfac) * V(2, 3) * V(3, 3) * sqr(lb) * betb;

  double muR33 = sqr(mt) + dupR + sqr(mfac) * (-88./25. * sqr(sqr(g1)) + 
					       8 * sqr(sqr(gs)) + 
					       2 * sqr(lt) * bett);
  double muRii = sqr(mfac) * (-88./25. * sqr(sqr(g1)) + 
			      8 * sqr(sqr(gs))) + dupR;
  
  double muLRi3 = -vu * mfac * lt * sqr(lb) * V(2, 3) * V(3, 3) / sqrt(2.0);

  double muLij = sqr(mfac) * V(1, 3) * V(2, 3) * sqr(lb) * (betb - sqr(lt));

  // NB this is Ben's correction factor
  /*  muLij += sqr(mfac) * V(1, 2) * V(2, 2) * sqr(ls) * 
      (betb - sqr(lt) - 3.0 * sqr(lb));*/

  double muLii = dupL + sqr(mfac) * (-11./50. * sqr(sqr(g1)) - 
				     1.5 * sqr(sqr(gw)) + 8 * sqr(sqr(gs)));
  deltaULL12 = muLij / muLii;
  deltaULL23 = muLi3 / sqrt(muL33 * muLii);
  deltaULR23 = muLRi3 / sqrt(muLii * muR33);
}

void ckmNormalise(DoubleMatrix & Vu, DoubleMatrix & Vd, DoubleMatrix & Uu,
		  DoubleMatrix & Ud) {
  if (Vu.displayRows() != 3 || Vu.displayCols() != 3 || 
      Vd.displayRows() != 3 || Vd.displayCols() != 3) {
    throw("Wrong size of matrices in flavoursoft.cpp::ckmNormalise\n");
  }

  DoubleMatrix vCkm(Vu.transpose() * Vd);
  
  DoubleMatrix signsU(3, 3), signsD(3, 3);

  int i; for (i=1; i<=3; i++) {
    if (vCkm(i, i) < 0.) {
      signsU(i, i) = -1.; 
      int j; for (j=1; j<=3; j++) vCkm(i, j) = -vCkm(i, j); 
    }
    else signsU(i, i) = 1.;
    signsD(i, i) = 1.;
  }

  /// Now, we make 12 and 23 elements positive while keeping diagonal
  /// element positive
  if (vCkm(1, 2) < 0.) {
    signsD(2, 2) = -1.; signsU(2, 2) = -signsU(2, 2);
    int j; for (j=1; j<=3; j++) {
      vCkm(2, j) = -vCkm(2, j);  
      vCkm(j, 2) = -vCkm(j, 2);
    }
  }

  if (vCkm(2, 3) < 0.) {
    signsD(3, 3) = -1.; signsU(3, 3) = -signsU(3, 3);
  }
  /// We've now exhausted the 5 re-signing degrees of freedom that we have to
  /// play with. 

  /// On the other hand, this fixes the phases definitively to avoid any
  /// problems 
  /*  if (signsU(1, 1) * Vu(1, 1) < 0.) {
    for (i = 1; i<=3; i++) {
      signsU(i, i) = -signsU(i, i);
      signsD(i, i) = -signsD(i, i);
    }
    }*/

  Vu = Vu * signsU; Uu = Uu * signsU;
  Vd = Vd * signsD; Ud = Ud * signsD;
  /// latter relations in order to obtain same sign for the fermion mass
}


void FlavourMssmSoftsusy::sCkmRunning
(DoubleMatrix & deltaULL, DoubleMatrix & deltaURR, DoubleMatrix & deltaULR, 
 DoubleMatrix & deltaDLL, DoubleMatrix & deltaDRR, DoubleMatrix & deltaDLR) 
  {

  calcDrBarPars();

  // First, must define mstop,sbot,stau and mixing angles in DRbar scheme
  double beta = atan(displayTanb());
  double sinthDRbar = calcSinthdrbar();
  double mz = displayMzRun(), mz2 = sqr(mz);

  sw2 = sqr(sinthDRbar);
  guL = 0.5 - 2.0 * sw2 / 3.0;
  gdL = -0.5 + sw2 / 3.0;
  geL = -0.5 + sw2;
  guR = 2.0 * sw2 / 3.0;
  gdR = -sw2 / 3.0;
  geR = -sw2;

  double vev = displayHvev();

  DoubleMatrix massUsq(6, 6), massDsq(6, 6), massEsq(6, 6);
  /// Find the Yukawa rotation matrices such that the super-CKM basis may be
  /// defined
  DoubleMatrix Ud(3, 3), Vd(3, 3), Uu(3, 3), Vu(3, 3), Ue(3, 3), Ve(3, 3);
  DoubleVector ye(3), yu(3), yd(3);
  displayYukawaMatrix(YU).diagonalise(Vu, Uu, yu);
  displayYukawaMatrix(YD).diagonalise(Vd, Ud, yd);
  displayYukawaMatrix(YE).diagonalise(Ue, Ve, ye);
  ckmNormalise(Vu, Vd, Uu, Ud); 

  DoubleMatrix mqSqSckm(3, 3), mqSqUckm(3, 3), tdSckm(3, 3), mdSqSckm(3, 3), 
    tuSckm(3, 3), muSqSckm(3, 3), mlSqSckm(3, 3), teSckm(3, 3), meSqSckm(3, 3);
  mqSqSckm  = Vd.transpose() * displaySoftMassSquared(mQl) * Vd;
  mqSqUckm  = Vu.transpose() * displaySoftMassSquared(mQl) * Vu;
  tdSckm    = Ud.transpose() * displayTrilinear(DA).transpose() * Vd;
  mdSqSckm  = Ud.transpose() * displaySoftMassSquared(mDr).transpose() * 
    Ud; 
  tuSckm    = Uu.transpose() * displayTrilinear(UA).transpose() * Vu;
  muSqSckm  = Uu.transpose() * displaySoftMassSquared(mUr).transpose() * 
    Uu; 
  mlSqSckm  = Ve.transpose() * displaySoftMassSquared(mLl) * Ve;
  teSckm    = Ue.transpose() * displayTrilinear(EA).transpose() * Ve;
  meSqSckm  = Ue.transpose() * displaySoftMassSquared(mEr).transpose() * Ue; 

  DoubleVector mu(3), md(3), me(3);

  double susyMu = displaySusyMu();
  double tanb = displayTanb();
  double sinb = sin(beta), cosb = cos(beta);
  const double sqrt2 = sqrt(2.0);
  /// the following contributions are only calculated at tree-level:
  int i, j;   for (i=1; i<=3; i++) {
    me(i) = ye(i) * vev / sqrt2 * cosb;
    mu(i) = yu(i) * vev / sqrt2 * sinb;
    md(i) = yd(i) * vev / sqrt2 * cosb;

    for (j=i; j<=3; j++) {
      massUsq(i, j) = mqSqUckm(i, j);
      massDsq(i, j) = mqSqSckm(i, j);
      massEsq(i, j) = mlSqSckm(i, j);
      if (i == j) {
	massUsq(i, j) = massUsq(i, j) + sqr(mu(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (0.5 - 2. / 3. * sqr(sinthDRbar));
	massDsq(i, j) = massDsq(i, j) + sqr(md(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (-0.5 + 1. / 3. * sqr(sinthDRbar));
	massEsq(i, j) = massEsq(i, j) + sqr(me(i)) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  (-0.5 + sqr(sinthDRbar));
	
      }
    }
  
    for (j=4; j<=6; j++) {
      massUsq(i, j) = vev * sinb / sqrt2 * tuSckm(j-3, i);
      massDsq(i, j) = vev * cosb / sqrt2 * tdSckm(j-3, i);
      massEsq(i, j) = vev * cosb / sqrt2 * teSckm(j-3, i);
      if (i == j-3) {
	massUsq(i, j) = massUsq(i, j) - susyMu * mu(i) / tanb;
	massDsq(i, j) = massDsq(i, j) - susyMu * md(i) * tanb;
	massEsq(i, j) = massEsq(i, j) - susyMu * me(i) * tanb;
      }
    }  
  }
    
  for (i=4; i<=6; i++)
    for (j=i; j<=6; j++) {
      massUsq(i, j) = muSqSckm(i - 3, j - 3);
      massDsq(i, j) = mdSqSckm(i - 3, j - 3);
      massEsq(i, j) = meSqSckm(i - 3, j - 3);
      if (i == j) {
	massUsq(i, j) = massUsq(i, j) + 
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  sqr(sinthDRbar) * 2.0 / 3.0 + sqr(mu(i - 3)); 
	massDsq(i, j) = massDsq(i, j) -
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  sqr(sinthDRbar) * 1.0 / 3.0 + sqr(md(i - 3));
	massEsq(i, j) = massEsq(i, j) -
	  cos(2.0 * beta) * sqr(displayMzRun()) * 
	  sqr(sinthDRbar) + sqr(me(i - 3));
      }
    }

  massUsq.symmetrise();
  massDsq.symmetrise();
  massEsq.symmetrise();

  for (i=1; i<=3; i++)
    for (j=1; j<=3; j++) {
      deltaULL(i, j) = massUsq(i, j) / 
	(sqrt(fabs(massUsq(i, i) * massUsq(j, j))));
      deltaURR(i, j) = massUsq(i+3, j+3) / 
	(sqrt(fabs(massUsq(i+3, i+3) * massUsq(j+3, j+3))));
      deltaULR(i, j) = massUsq(i, j+3) / (sqrt(fabs(massUsq(i, i) * 
						 massUsq(j+3, j+3))));
      deltaDLL(i, j) = massDsq(i, j) / 
	  (sqrt(fabs(massDsq(i, i) * massDsq(j, j))));
      deltaDRR(i, j) = massDsq(i+3, j+3) / 
	(sqrt(fabs(massDsq(i+3, i+3) * massDsq(j+3, j+3))));
      deltaDLR(i, j) = massDsq(i, j+3) / 
	(sqrt(fabs(massDsq(i, i) * massDsq(j+3, j+3))));
    }
}
