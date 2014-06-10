
/** \file flavoursoft.h
   - Project:     SOFTSUSY 
   - Author:      Ben Allanach 
   - Manual:      hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
   - Webpage:     http://hepforge.cedar.ac.uk/softsusy/
   \brief Header file for RP conserving MSSM object including all 
              (real) soft SUSY breaking parameters and (real) SUSY couplings.
	      with non-trivial flavour calculation
*/

#ifndef FLAVOURSOFT_H
#define FLAVOURSOFT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <def.h>
#include <utils.h>
#include <numerics.h>
#include <physpars.h>
#include <lowe.h>
#include <softpars.h>
#include <twoloophiggs.h>
#include <softsusy.h>

/// Converts from input Wolfenstein parameterisation of a unitary matrix to
/// the mixing angles under the assumption of CP-conservation, ie no complex
/// phases. Uses the modulus of complex number to calculate sin13
void convertFromWolfenstein(double lambda, double A, double rhobar, 
			    double etabar, double & sin12, double & sin23, 
			    double & sin13);

/// returns an integer which is position of the matrix element encoded in the
/// following way:
/// [ 1 2 3 ]
/// [   4 5 ]
/// [     6 ] where the matrix is symmetric.
int positionOfSym(int i, int j);

struct flavourPhysical {
  /// SLHA2 mixing matrices and values of the root(mass squared) of sfermions
  /// in the mass basis
  DoubleMatrix dSqMix, uSqMix;
  DoubleVector msD, msU;
  DoubleMatrix eSqMix, nuSqMix;
  DoubleVector msE, msNu;

  flavourPhysical(); ///< Constructor: initialises with zeroes
  /// Constructor copies another object
  flavourPhysical(const flavourPhysical &); 
  /// Displays the object in situations where a const is required
  const flavourPhysical & displayFlavourPhysical() const { return *this; };
  /// Sets whole contents to those of another object s
  void setFlavourPhysical(const flavourPhysical &s) { *this = s; };
  /// Sets whole contents to those of another object s
  const flavourPhysical & operator = (const flavourPhysical & s);
};

/// Formatted printout
ostream & operator <<(ostream &, const flavourPhysical &); 
/// Formatted input of physical parameters
istream & operator >>(istream & left, flavourPhysical &s);

inline flavourPhysical::flavourPhysical()
  : dSqMix(6, 6), uSqMix(6, 6), msD(6), msU(6), 
    eSqMix(6, 6), nuSqMix(3, 3), msE(6), msNu(3)
{}

inline flavourPhysical::flavourPhysical(const flavourPhysical & s)
  : dSqMix(s.dSqMix), uSqMix(s.uSqMix), msD(s.msD), msU(s.msU),
    eSqMix(s.eSqMix), nuSqMix(s.nuSqMix), 
    msE(s. msE), msNu(s.msNu)
{}

/// This object is intended to be a flavoursome version of MssmSoftsusy
class FlavourMssmSoftsusy: public MssmSoftsusy {
private:
  flavourPhysical fv; ///< Contains 6x6 squark mixing parameters and masses
  /// angles in CKM; PDG parameterisation
  double theta12, theta23, theta13, deltaCkm; 
  double thetaB12, thetaB23, thetaB13; ///< angles in MNS; PDG parameterisation
  double mNuE, mNuMu, mNuTau; ///< pole neutrino masses
public:
  /// Flag for SLHA output
  int numFV; 
  /// constructor functions
  inline FlavourMssmSoftsusy();

  /// standard set and display functions
  inline double displayTheta12() const { return theta12; };
  inline double displayTheta13() const { return theta13; };
  inline double displayTheta23() const { return theta23; };
  inline double displayDelta() const { return deltaCkm; };  
  inline double displayThetaB12() const { return thetaB12; };
  inline double displayThetaB13() const { return thetaB13; };
  inline double displayThetaB23() const { return thetaB23; };
  inline double displayMnuE()   const { return mNuE; };
  inline double displayMnuMu()  const { return mNuMu; };
  inline double displayMnuTau() const { return mNuTau; };
  const flavourPhysical & displayFlavourPhysical() const { return fv; };
  const FlavourMssmSoftsusy & displayFlavourSoftsusy() const { return *this; };
  
  inline void setTheta12(double d) { theta12 = d; };
  inline void setTheta13(double d) { theta13 = d; };
  inline void setTheta23(double d) { theta23 = d; };
  inline void setDelta(double d) { deltaCkm = d; };
  inline void setThetaB12(double d) { thetaB12 = d; };
  inline void setThetaB13(double d) { thetaB13 = d; };
  inline void setThetaB23(double d) { thetaB23 = d; };
  inline void setMnuE(double d)   { mNuE = d; };
  inline void setMnuMu(double d)  { mNuMu = d; };
  inline void setMnuTau(double d) { mNuTau = d; };
  /// Sets all squark flavour violating physical parameters
  void setFlavourPhys(const flavourPhysical & s) { fv = s; };

  /// constructs a CKM matrix out of the magnitude of angles stored within:
  /// note that this does NOT give the running CKM matrix!
  DoubleMatrix displayCkm() const;
  /// same as displayCkm, except the phase is properly incorporated
  ComplexMatrix displayComplexCkm() const;
  /// constructs a MNS matrix out of the angles stored within
  DoubleMatrix displayMns() const;

  /// SLHA2 output format
  virtual void lesHouchesAccordOutput(ostream & out, char model[], 
				      const DoubleVector & pars, 
				      int sgnMu, double tanb, double qMax, 
				      int numPoints, double mgut, 
				      const QedQcd & t,
				      bool altEwsb = false);

  /// flavour violating squark mass/mixing calculation
  virtual void doUpSquarks(double mt, double pizztMS, double sinthDRbarMS, int
		      accuracy); 
  /// flavour violating squark mass/mixing calculation
  virtual void doDownSquarks(double mb, double pizztMS, double sinthDRbarMS, 
			     int accuracy, double mt); 
  /// flavour violating slepton mass/mixing calculation
  virtual void doChargedSleptons(double mT, double pizztMS, 
			 double sinthDRbarMS, int accuracy);
  /// flavour violating slepton mass/mixing calculation
  virtual void doSnu(double pizztMS, int accuracy = 0);

  /// Input diagonal mass matrices and it'll give you back mixed ones, based on
  /// the CKM quark mixing matrix you supplied in vCkm. 
  virtual void doQuarkMixing(DoubleMatrix & mDon, DoubleMatrix & mUpq);

  virtual void calcDrBarPars(); 

  /// Provides the first guess at a SUSY object at mt, inputting tanb and
  /// oneset (should be at MZ) - it's very crude, doesn't take radiative
  /// corrections into account etc. 
  virtual MssmSusy guessAtSusyMt(double tanb, const QedQcd & oneset);

  /// Sets lepton flavour mixed sparticles
  /// virtual void sparticleThresholdCorrections(double tb);

  /// Sets the CKM angles given some Wolfenstein parameters (PDG) - matches up
  /// the absolute values to standard parameterisation with zero phase
  void setAngles(double lambda, double aCkm, double rhobar, double etabar);

  /// Return matrices of the flavour violating mass insertion delta
  /// parameters: see hep-ph/9604387 for (old) bounds
  void sCkm(DoubleMatrix & deltaULL, DoubleMatrix & deltaURR, 
	    DoubleMatrix & deltaULR, DoubleMatrix & deltaDLL, 
	    DoubleMatrix & deltaDRR, DoubleMatrix & deltaDLR) const;


  /// This is my translation of Gudrun's attempt at analytic formulae for the
  /// various deltas
  void sCkmAnalytic(double m32, double & deltaULL23, double & deltaULR23,
		    double & deltaULL12, double & deltaDLL23, 
		    double & deltaDLR23, double & deltaDLL12) const;

  /// Calculates running deltas as a function of scale, in the real
  /// approximation 
  void sCkmRunning
  (DoubleMatrix & deltaULL, DoubleMatrix & deltaURR, DoubleMatrix & deltaULR, 
   DoubleMatrix & deltaDLL, DoubleMatrix & deltaDRR, DoubleMatrix & deltaDLR);
};

inline FlavourMssmSoftsusy::FlavourMssmSoftsusy()
  : MssmSoftsusy(), fv(), theta12(0.), theta23(0.), theta13(0.), deltaCkm(0.),
    thetaB12(0.), thetaB23(0.), thetaB13(0.), mNuE(0.), mNuMu(0.), mNuTau(0.)
{}

/// Formatted output
ostream & operator <<(ostream &, const FlavourMssmSoftsusy &); 

void flavourBcs2(MssmSoftsusy & m, const DoubleVector & inputParameters);

/// the object of this function is to make sure all diagonal entries are
/// positive, as well as 1,2 and 2,3 entries
void ckmNormalise(DoubleMatrix & Vu, DoubleMatrix & Vd, DoubleMatrix & Uu,
		  DoubleMatrix & Ud);

#endif

