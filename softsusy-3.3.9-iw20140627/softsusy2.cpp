///
/// newly added routine for two scale models. 
/// this file contains beta function modification. 
///


#include "softsusy.h"



static MssmSoftsusy *tempMssm ; 

int N5pair  = 0; 
int N10pair = 0; 
int N24     = 0;

int MssmSoftsusy::run_low( double x1, double x2, double eps ) {
  double tol ;

  if (eps < 0.0) tol = TOLERANCE; 
  else if (eps < EPSTOL) tol = EPSTOL; 
  else tol = eps; 
  
  tempMssm = this ; 
  DoubleVector y(this -> display()); 
  int err = RGE::callRK(x1, x2, y, allDerivs_low, tol); 
  if( err == 0 ) {
    this -> set(y); 
    tempMssm -> setMu(x2); 
  }
  return err;  
}

int MssmSoftsusy::run_high( double x1, double x2, double eps ) {
  double tol; 

  if (eps < 0.0) tol = TOLERANCE; 
  else if (eps < EPSTOL) tol = EPSTOL; 
  else tol = eps; 
  
  tempMssm = this ; 
  DoubleVector y(this -> display()); 
  int err = RGE::callRK(x1, x2, y, allDerivs_high, tol); 
  if( err == 0 ) {
    this -> set(y); 
    tempMssm -> setMu(x2); 
  }
  return err;  

}

int MssmSoftsusy::runto_low( double x2, double eps ) {
  double tol; 
  if (eps < 0.0) tol = TOLERANCE; 
  else if (eps < EPSTOL ) tol = EPSTOL ; 
  else tol = eps ; 
  double x1 = this -> displayMu(); 
  return run_low(x1, x2, tol ); 
}

int MssmSoftsusy::runto_high( double x2, double eps ) {
  double tol; 
  if (eps < 0.0) tol = TOLERANCE; 
  else if (eps < EPSTOL ) tol = EPSTOL ; 
  else tol = eps ; 
  double x1 = this -> displayMu(); 
  return run_high(x1, x2, tol );   
}

DoubleVector allDerivs_low(double x, const DoubleVector& y ) {
  tempMssm->setMu(exp(x)); 
  tempMssm->set(y); 
  return tempMssm->beta_low();
}

DoubleVector allDerivs_high(double x, const DoubleVector& y ) {
  tempMssm->setMu(exp(x)); 
  tempMssm->set(y); 
  return tempMssm->beta_high();
}

DoubleVector MssmSoftsusy::beta_low() {
  return beta(); 
}

DoubleVector MssmSoftsusy::beta_high() {
  // calculate the derivatives
  static SoftParsMssm dsoft; dsoft = SoftParsMssm_beta2_high();

  return dsoft.display(); // convert to a long vector
}

// Outputs derivatives (DRbar scheme) in the form of dsoft
// thresholds = 0 and NOTHING is decoupled.
// thresholds = 2 and SUSY params/gauge couplings are decoupled at sparticle
// thresholds.
// CHECKED: 24/05/02
SoftParsMssm SoftParsMssm::SoftParsMssm_beta2_high() const {
  //  susypars beta functions are defined in the
  //  Allanach, Dedes, Dreiner hep-ph/0309196 paper notation 
  //  W=  LL Y^E H1 ER + QL Y^D H1 DR + QL Y^U H2 UR + smu H2 H1, 
  //  (implicit epsilonAb phi^a phi^b a,b=Su(2) indices present where
  //  epsilon12 = +1, epsilon21 = -1, other components zero
  //  The following equations are for our conventions
  //  VTri = QL ua ur H2 + QL da dr H1 + LL ea Er H1 + hc
  //  VBi  = mH1sq |H1|^2 + mH2sq |H2|^2 + Q^* mQLsq Q + L^* mLLsq L +
  //          UR MuR UR^* + DR MDR DR^* + ER MER ER^* + m3sq H2 H1
  // Note in particular that ua(3,3) is NOT AT. AT = ua(3, 3) / ht.
  // Compared to M+V hep-ph/9311340, SOFTSUSY has the SAME mass squareds and
  // TRANSPOSED Yukawas and trilinears - the signs are wrong in M+V for these
  // terms (typo).
  
  // Constants for gauge running
  static DoubleVector bBeta(3), cuBeta(3), cdBeta(3), ceBeta(3);
  static DoubleMatrix babBeta(3, 3);
  
  if (bBeta(1) < 1.0e-5) // Constants not set yet
    setBetas_high(babBeta, cuBeta, cdBeta, ceBeta, bBeta);
  
  // For calculational brevity: 
  static sBrevity a;
  // convert to beta functions
  static MssmSusy dsb;
  
  // calculate derivatives for full SUSY spectrum. Brevity calculations come
  // out encoded in a
  dsb = MssmSusy_beta_high(a);
  
  // To keep this a const function: TIME SAVINGS
  DoubleMatrix &u1=a.u1, &d1=a.d1, &e1=a.e1;
  DoubleMatrix &u2=a.u2, &d2=a.d2, &e2=a.e2,
    &u2t=a.u2t, &d2t=a.d2t, &e2t=a.e2t, &dt=a.dt, &ut=a.ut, &et=a.et;      
  double &uuT = a.uuT, &ddT = a.ddT, &eeT = a.eeT;
  DoubleVector &gsq=a.gsq;
  
  // Best to make these const DoubleMatrix & type
  const DoubleMatrix &hu = displayTrilinear(UA), &hd = displayTrilinear(DA),
    &he = displayTrilinear(EA);

  static DoubleMatrix hut(3, 3), hdt(3, 3), het(3, 3);
  static DoubleMatrix hu2(3, 3), hd2(3, 3), he2(3, 3);
  static DoubleMatrix hu2t(3, 3), hd2t(3, 3), he2t(3, 3);
  const DoubleMatrix &mq = displaySoftMassSquared(mQl),
    &mu = displaySoftMassSquared(mUr), &md = displaySoftMassSquared(mDr),
    &ml = displaySoftMassSquared(mLl), &me = displaySoftMassSquared(mEr); 
  static DoubleVector mG(displayGaugino()); 
  static DoubleVector msq(1, 3), gsqM(1, 3), gMsq(1, 3);
  
  hut = hu.transpose(); hdt = hd.transpose(); het = he.transpose();
  hu2 = hu * hut; hd2 = hd * hdt; he2 = he * het;
  double huT = hu2.trace(), hdT = hd2.trace(), heT = he2.trace();
  hu2t = hut * hu; hd2t = hdt * hd; he2t = het * he;
  double mqT = mq.trace(), muT = mu.trace(), mdT = md.trace(), meT =
    me.trace(), mlT = ml.trace();
  
  double huuT = (hu * ut).trace(), hddT = (hd * dt).trace(), 
    heeT = (he * et).trace(); 
  mG = mGaugino; msq = mG * mG; gsqM = gsq * mG; gMsq = gsq * msq;
  
  double m3sq = displayM3Squared();

  // derivatives of soft parameters
  static DoubleVector dmG(1, 3);
  static double dmH1sq, dmH2sq, dm3sq;
  static DoubleMatrix dmq(3, 3), dmu(3, 3), dmd(3, 3), dme(3, 3), dml(3, 3);
  static DoubleMatrix dhu(3, 3), dhd(3, 3), dhe(3, 3);
  
  const double ONEO16Pisq = 1.0 / (16.0 * sqr(PI));
  if (displayLoops() > 0) {
    const static double sixteenO3 = 16.0 / 3.0, oneO15 = 1.0 /
      15.0;
    
    dmG = gsqM * 2.0 * bBeta;
    
    double curlyS = mH2sq - mH1sq + mqT - mlT - 2.0 * muT + mdT + meT;
    
    dm3sq = 2.0 * displaySusyMu() * (0.6 * gsqM(1) + 3.0 * gsqM(2) + 
			3.0 * huuT  +  3.0 * hddT + heeT) 
      + m3sq * (3.0 * uuT + 3.0 * ddT + eeT - 0.6 * gsq(1) - 3.0 * gsq(2));

    dmH1sq = 2.0 * 
      (-0.3 * gsq(1) * curlyS - 0.6 * gMsq(1) - 3.0 * gMsq(2) +
       3.0 * (mH1sq * ddT + (d2 * mq).trace() + (d2t * md).trace() + hdT) +
       (mH1sq * eeT + (e2 * ml).trace() + (e2t * me).trace() + heT));
    
    dmH2sq = 2.0 * 
      (0.3 * gsq(1) * curlyS - 0.6 * gMsq(1) - 3.0 * gMsq(2) +
       3.0 * (mH2sq * uuT + (u2 * mq).trace() + (u2t * mu).trace() + huT));

    dmq = 2.0 *
      (0.1 * gsq(1) * curlyS - oneO15 * gMsq(1) - 3.0 * gMsq(2) -
       sixteenO3 * gMsq(3) +
       0.5 * (u2 * mq + mq * u2 + 2.0 * (u1 * mu * ut + mH2sq * u2 + hu2))
       + 0.5 * (d2 * mq + mq * d2 + 2.0 * (d1 * md * dt + mH1sq * d2 +
					   hd2)));
    
    dml = 2.0 *
      ( -0.3 * gsq(1) * curlyS - 0.6 * gMsq(1) - 3.0 * gMsq(2) + 
	0.5 * (e2 * ml + ml * e2 + 2.0 * (e1 * me * et + mH1sq * e2 + he2)));
    
    dmu = 2.0 *
      (-0.4 * gsq(1) * curlyS - 16.0 * oneO15 * gMsq(1) - sixteenO3 *
       gMsq(3) + 
       (u2t * mu + mu * u2t + 2.0 * (ut * mq * u1 + mH2sq * u2t + hu2t)));
    
    dmd = 2.0 * (0.2 * gsq(1) * curlyS 
		 - 4.0 * oneO15 * gMsq(1) - sixteenO3 * gMsq(3) + 
		 (d2t * md + md * d2t + 2.0 * (dt * mq * d1 + mH1sq * d2t +
					       hd2t)));
    
    dme = 2.0 *
      (0.6 * gsq(1) * curlyS - 36.0 * oneO15 * gMsq(1) +
       e2t * me + me * e2t + 2.0 * (et * ml * e1 + mH1sq * e2t + he2t));
    
    dhu = (3.0 * uuT 
	   - sixteenO3 * gsq(3) - 3.0 * gsq(2) - 13.0 * oneO15 * gsq(1))
      * hu
      + 2.0 * (3.0 * huuT + 13.0 * oneO15 * gsqM(1) + 3 * gsqM(2) + sixteenO3
	     * gsqM(3)) * u1 +
      4.0 * hu * u2t + 5.0 * u2 * hu + 2.0 * hd * dt * u1 + d2 * hu;
    
    dhd = (eeT + 3.0 * ddT -sixteenO3 * gsq(3) - 3.0 * gsq(2) - 
	   7.0 * oneO15 * gsq(1)) * hd 
      + 2.0 * (7.0 * oneO15 * gsqM(1) + 3.0 * gsqM(2) + sixteenO3
	     * gsqM(3) + heeT + 3.0 * hddT) * d1 +
      4.0 * hd * d2t + 5.0 * d2 * hd + 
      2.0 * hu * ut * d1 + u2 * hd;
    
    dhe = (eeT + 3.0 * ddT - 3.0 * gsq(2) - 1.8 * gsq(1)) * he
      + (3.6 * gsqM(1) + 6.0 * gsqM(2) + 2.0 * heeT + 6.0 * hddT) * e1 +
      4.0 * he * e2t + 5.0 * e2 * he;

    // convert to proper derivatives: 
    dmG    = ONEO16Pisq * dmG;
    dm3sq  *= ONEO16Pisq;
    dmH1sq *= ONEO16Pisq;
    dmH2sq *= ONEO16Pisq;
    dmq    *= ONEO16Pisq;
    dml    *= ONEO16Pisq;
    dmu    *= ONEO16Pisq;
    dmd    *= ONEO16Pisq;
    dme    *= ONEO16Pisq;
    dhu    *= ONEO16Pisq;
    dhd    *= ONEO16Pisq;
    dhe    *= ONEO16Pisq;
  }
  
  // two-loop contributions. I got these from hep-ph/9311340. WIth respect to
  // their notation, the Yukawas and h's are TRANSPOSED. Gaugino masses are
  // identical, as are soft masses. B(mV) = mu(BBO) B(BBO)
  if (displayLoops() > 1) {
    static DoubleVector dmG2(1, 3);
    static DoubleMatrix dmq2(3, 3), dmu2(3, 3), dmd2(3, 3), dme2(3, 3), 
      dml2(3, 3);
    static DoubleMatrix dhu2(3, 3), dhd2(3, 3), dhe2(3, 3);
    static DoubleVector sigma(3);

    const double oneO16Pif = sqr(ONEO16Pisq);
    
    DoubleVector &g4=a.g4;

    double mq3 = displaySoftMassSquared(mQl, 3, 3);
    double mu3 = displaySoftMassSquared(mUr, 3, 3);
    double md3 = displaySoftMassSquared(mDr, 3, 3);
    double ml3 = displaySoftMassSquared(mLl, 3, 3);
    double me3 = displaySoftMassSquared(mEr, 3, 3);
    double ht = displayYukawaElement(YU, 3, 3), ht2 = sqr(ht), ht4 = sqr(ht2);
    double htau = displayYukawaElement(YE, 3, 3), htau2 = sqr(htau), 
      htau4 = sqr(htau2);
    double hb = displayYukawaElement(YD, 3, 3), hb2 = sqr(hb), hb4 = sqr(hb2);
    double Ut = displayTrilinear(UA, 3, 3), Ut2 = sqr(Ut);
    double Ub = displayTrilinear(DA, 3, 3), Ub2 = sqr(Ub);
    double Utau = displayTrilinear(EA, 3, 3), Utau2 = sqr(Utau);

    double sP;
    if (MIXING < 1) {
      sP = ///< dominant 3rd family approximation
	-(3.0 * mH2sq + mq3 - 4.0 * mu3) * ht2 +  
	(3.0 * mH1sq - mq3 - 2.0 * md3) * hb2 + 
	(mH1sq + ml3 - 2.0 * me3) * htau2 +
	(1.5 * gsq(2) + 0.3 * gsq(1)) * (mH2sq - mH1sq - mlT) +
	(8.0 / 3.0 * gsq(3) + 1.5 * gsq(2) + gsq(1) / 30.0) * mqT -
	(16.0 / 3.0 * gsq(3) + 16.0 / 15.0 * gsq(1)) * muT +
	(8.0 / 3.0 * gsq(3) + 2.0 / 15.0 * gsq(1)) * mdT +       
	1.2 * gsq(1) * meT;  //checked
    } else {
      sP = ///< fully mixed case -- slower
	-(3.0 * mH2sq * uuT + (mq * u2).trace()) 
	+ 4.0 * (u1 * mu * ut).trace() + 
	3.0 * mH1sq * ddT - (mq * d2).trace() - 2.0 * (d1 * md * dt).trace() + 
	mH1sq * eeT + (ml * e2).trace() -
	(2.0 * e1 * me * et).trace() +
	(1.5 * gsq(2) + 0.3 * gsq(1)) * (mH2sq - mH1sq - mlT) +
	(8.0 / 3.0 * gsq(3) + 1.5 * gsq(2) + gsq(1) / 30.0) * mqT -
	(16.0 / 3.0 * gsq(3) + 16.0 / 15.0 * gsq(1)) * muT +
	(8.0 / 3.0 * gsq(3) + 2.0 / 15.0 * gsq(1)) * mdT +       
	1.2 * gsq(1) * meT;  //checked
    }
    
    sigma(1) = 0.2 * gsq(1) *
      (3.0 * (mH1sq + mH2sq) + mqT + 3.0 * mlT + 8.0 * muT + 2.0 * mdT + 6.0 *
       meT);
    sigma(2) = gsq(2) * (mH1sq + mH2sq + (3.0 * mqT + mlT));
    sigma(3) = gsq(3) * (2.0 * mqT + muT + mdT); // these 3 checked

    DoubleMatrix u4(u2 * u2), d4(d2 * d2), u4t(u2t * u2t), d4t(d2t * d2t);

    if (INCLUDE_2_LOOP_SCALAR_CORRECTIONS) {
    /* new dominant 3-family version */
      if (MIXING < 1) {
	dmq2 = -(2.0 * mq + 8.0 * mH2sq) * u4 - 
	  4.0 * u1 * mu * u2t * ut - 
	  4.0 * u2 * mq * u2 - 4.0 * u2 * u1 * mu * ut - 2.0 * u4 * mq -
	  (2.0 * mq + 8.0 * mH1sq) * d4 - 4.0 * d1 * md * d2t * dt - 
	  4.0 * d2 * mq * d2 - 4.0 * d2 * d1 * md * dt - 2.0 * d4 * mq -
	  ((mq + 4.0 * mH2sq) * u2 + 2.0 * u1 * mu * ut + u2 * mq) * uuT 
	  * 3.0 -
	  ((mq + 4.0 * mH1sq) * d2 + 2.0 * d1 * md * dt + d2 * mq) * 
	  (3.0 * ddT + eeT) -
	  6.0 * u2 * ((mq * u2).trace() + (u1 * mu * ut).trace()) -
	  d2 * ((6.0 * mq * d2).trace() + (6.0 * d1 * md * dt).trace() + 
		(2.0 * ml * e2).trace() + (2.0 * e1 * me * et).trace()) -
	  4.0 * (u2 * hu2 + hu2 * u2 + u1 * hu2t * ut + hu * u2t * hut) -
	  4.0 * (d2 * hd2 + hd2 * d2 + d1 * hd2t * dt + hd * d2t * hdt) -
	  hu2 * uuT * 6.0 - u2 * 6.0 * Ut2 - hu * ut * 6.0 * huuT -
	  u1 * hut * 6.0 * huuT - hd2 * (6.0 * ddT + 2.0 * eeT) - 
	  d2 * (6.0 * Ub2 + 2.0 * Utau2) -
	  hd * dt * (6.0 * hddT + 2.0 * heeT) - 
	  d1 * hdt * (6.0 * hddT + 2.0 * heeT) + 0.4 * gsq(1) * 
	  ((2.0 * mq +  4.0 * mH2sq) * u2 + 4.0 * u1 * mu * ut +
	   2.0 * u2 * mq + 4.0 * hu2 - 4.0 * mG(1) * hu * ut - 4.0
	   * mG(1) * u1 * hut + 8.0 * msq(1) * u2 +
	   (mq + 2.0 * mH1sq) * d2 + 2.0 * d1 * md * dt +
	   d2 * mq + 2.0 * hd2 - 2.0 * mG(1) * hd * dt - 
	   2.0 * mG(1) * d1 * hdt + 4.0 * msq(1) * d2) +
	  0.4 * gsq(1) * sP - 128.0 / 3.0 * g4(3) * msq(3) + 32.0 * gsq(3) *
	  gsq(2) * (msq(3) + msq(2) + mG(2) * mG(3)) +
	  32.0 / 45.0 * gsq(3) * gsq(1) * 
	  (msq(3) + msq(1) + mG(1) * mG(3)) + 33.0
	  * g4(2) * msq(2) + 0.4 * gsq(2) * gsq(1) * (msq(2) + msq(1) + mG(1) *
						      mG(2)) +
	  199.0 / 75.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(2.0/5.0*g4(1)*msq(1)+18.0*g4(2)*msq(2)+32.0*g4(3)*msq(3)) // IWKIM

	  + 16.0 / 3.0 * gsq(3) * sigma(3) +
	  3.0 * gsq(2) * sigma(2) + gsq(1) * sigma(1) / 15.0; // checked

	dml2 = -(2.0 * ml + 8.0 * mH1sq) * e2 * e2 - 4.0 * e1 * me * e2t * et -
	  4.0 * e2 * ml * e2 - 4.0 * e2 * e1 * me * et - 2.0 * e2 * e2 * ml -
	  ((ml + 4.0 * mH1sq) * e2 + 2.0 * e1 * me * et + e2 * ml) * 
	  (3.0 * ddT + eeT) -
	  e2 * (6.0 * mq * d2 + 6.0 * d1 * md * dt + 2.0 * ml * e2 + 
		2.0 * e1 * me * et).trace() -
	  4.0 * (e2 * he2 + he2 * e2 + e1 * he2t * et + he * e2t * het) -
	  he2 * (6.0 * ddT + 2.0 * eeT) - e2 * (6.0 * Ub2 + 2.0 * Utau2) -
	  he * et * (6.0 * hddT + 2.0 * heeT) - 
	  e1 * het * (6.0 * hddT + 2.0 * heeT) +
	  1.2 * gsq(2) * 
	  ((ml + 2.0 * mH1sq) * e2 + 2.0 * e1 * me * et + e2 * ml +
	   2.0 * he2 - 2.0 * mG(1) * he * et - 2.0 * mG(1) * e1 *
			  het + 4.0 * msq(1) * e2) -
	  1.2 * gsq(1) * sP + 33.0 * g4(2) * msq(2) + 3.6 * gsq(2) * gsq(1) *
	  (msq(2) + msq(1) + mG(1) * mG(2)) + 621.0 / 25.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(18.0/5.0*g4(1)*msq(1)+18.0*g4(2)*msq(2))   // IWKIM

	  + 3.0 * gsq(2) * sigma(2) + 0.6 * gsq(1) * sigma(1); //checked

	dmu2 = -(2.0 * mu + 8.0 * mH2sq) * u4t - 4.0 * ut * mq * u2 * u1 
	  - 4.0 * u2t * mu * u2t - 4.0 * u2t * ut * mq * u1 - 
	  2.0 * u4t * mu - (2.0 * mu + 4.0 * mH2sq + 4.0 * mH1sq) 
	  * ut * d2 * u1 - 4.0 * ut * mq * d2 * u1 - 
	  4.0 * ut * d1 * md * dt * u1 -
	  4.0 * ut * d2 * mq * u1 - 2.0 * ut * d2 * u1 * mu -
	  ((mu + 4.0 * mH2sq) * u2t + 2.0 * ut * mq * u1 + u2t * mu) * 
	  6.0 * uuT -
	  12.0 * u2t * (mq * u2 + u1 * mu * ut).trace() -
	  4.0 * (hu2t * u2t + u2t * hu2t + hut * u2 * hu + ut * hu2 * u1) -
	  4.0 * (hut * hd * dt * u1 + ut * d1 * hdt * hu + hut * d2 * hu + 
	     ut * hd2 * u1) -
	  12.0 * (hu2t * uuT + u2t * Ut2 + hut * u1 * huuT +
		  ut * hu * huuT) +
	  (6.0 * gsq(2) - 0.4 * gsq(1)) * 
	  ((mu + 2.0 * mH2sq) * u2t + 2.0 * ut * mq * u1 + u2t * mu + 
	   2.0 * hu2t) +
	  12.0 * gsq(2) * (2.0 * msq(2) * u2t - mG(2) * hut * u1 - 
			   mG(2) * ut * hu) -
	  0.8 * gsq(1) * (2.0 * msq(1) * u2t - mG(1) * hut * u1 - 
			  mG(1) * ut * hu)-
	  1.6 * gsq(1) * sP - 128.0 / 3.0 * g4(3) * msq(3) + 
	  512.0 / 45.0 * gsq(1) * gsq(3) * (msq(3) + msq(1) + mG(1) * mG(3)) +
	  3424.0 / 75.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(32.0/5.0*g4(1)*msq(1)+32.0*g4(3)*msq(3)) // IWKIM

	  + 16.0 / 3.0 * gsq(3) * sigma(3) +
	  16.0 / 15.0 * gsq(1) * sigma(1); // checked

	dmd2 = -(2.0 * md + 8.0 * mH1sq) * d4t - 
	  4.0 * dt * mq * d1 * d2t -
	  4.0 * d2t * md * d2t - 4.0 * d2t * dt * mq * d1 - 
	  2.0 * d4t * md -
	  (2.0 * md + 4.0 * mH2sq + 4.0 * mH1sq) * dt * u2 * d1 -
	  4.0 * dt * mq * u2 * d1 - 4.0 * dt * u1 * mu * ut * d1 - 
	  4.0 * dt * u2 * mq * d1 - 2.0 * dt * u2 * d1 * md - 
	  ((md + 4.0 * mH1sq) * d2t + 2.0 * dt * mq * d1 + d2t * md) * 
	  (6.0 * ddT + 2.0 * eeT) -
	  4.0 * d2t * (3.0 * mq * d2 + 3.0 * d1 * md * dt + ml * e2 
		       + e1 * me * et).trace() -
	  4.0 * (hd2t * d2t + d2t * hd2t + hdt * d2 * hd + dt * hd2 * d1) -
	  4.0 * (hdt * hu * ut * d1 + dt * u1 * hut * hd + hdt * u2 * hd + 
		 dt * hu2 * d1) -
	  4.0 * hd2t * (3.0 * ddT + eeT) - 4.0 * d2t * (3.0 * hdT + heT) -
	  4.0 * hdt * d1 * (3.0 * hddT + heeT) - 
	  4.0 * dt * hd * (3.0 * hddT + heeT) +
	  (6.0 * gsq(2) + 0.4 * gsq(1)) * 
	  ((md + 2.0 * mH1sq) * d2t + 2.0 * dt * mq * d1 + d2t * md + 
	   2.0 * hd2t) +
	  12.0 * gsq(2) * (2.0 * msq(2) * d2t - mG(2) * hdt * d1 
			   - mG(2) * dt * hd) +
	  0.8 * gsq(1) * (2.0 * msq(1) * d2t - mG(1) * hdt * d1 - 
			  mG(1) * dt * hd)+
	  0.8 * gsq(1) * sP - 128.0 / 3.0 * g4(3) * msq(3) + 
	  128.0 / 45.0 * gsq(3) * gsq(1) * (msq(3) + msq(1) + mG(1) * mG(3)) +
	  808.0 / 75.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(8.0/5.0*g4(1)*msq(1)+32.0*g4(3)*msq(3)) // IWKIM

	  + 16.0 / 3.0 * gsq(3) * sigma(3) +
	  4.0 / 15.0 * gsq(1) * sigma(1); // checked

	dme2 = -(2.0 * me + 8.0 * mH1sq) * e2t * e2t - 
	  4.0 * et * ml * e2 * e1 -
	  4.0 * e2t * me * e2t - 4.0 * e2t * et * ml * e1 - 
	  2.0 * e2t * e2t * me -
	  ((me + 4.0 * mH1sq) * e2t + 2.0 * et * ml * e1 + e2t * me) *
	  (6.0 * ddT + 2.0 * eeT) - 4.0 * e2t * 
	  (3.0 * mq * d2 + 3.0 * d1 * md * dt + ml * e2 + 
	   e1 * me * et).trace() -
	  4.0 * (he2t * e2t + e2t * he2t + het * e2 * he + et * he2 * e1) -
	  4.0 * he2t * (3.0 * ddT + eeT) - 4.0 * e2t * (3.0 * Ub2 + Utau2) -
	  4.0 * het * e1 * (3.0 * hddT + heeT) - 4.0 * et * he * 
	  (3.0 * hddT + heeT) + (6.0 * gsq(2) - 1.2 * gsq(1)) * 
	  ((me + 2.0 * mH1sq) * e2t + 2.0 * et * ml * e1 + e2t * me + 
	   2.0 * he2t) +
	  12.0 * gsq(2) * (2.0 * msq(2) * e2t - mG(2) * het * e1 
			   - mG(2) * et * he) -
	  2.4 * gsq(1) * (2.0 * msq(1) * e2t - mG(1) * het * e1 - 
			  mG(1) * et * he)
	  + 2.4 * gsq(1) * sP + 2808. / 25.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(72.0/5.0*g4(1)*msq(1)) // IWKIM

	  + 2.4 * gsq(1) * sigma(1); // checked

	dhu2 = 
	  (-3.0 * (3.0 * ht4 + ht2 * hb2) - d2 * (3.0 * ddT + eeT)
	   -15.0 * u2 * uuT - 6.0 * u4 - 2.0 * d4 -
	   4.0 * u2 * d2 + (16.0 * gsq(3) + 0.8 * gsq(1)) * uuT +
	   12.0 * gsq(2) * u2 + 0.4 * gsq(1) * d2 - 16.0 / 9.0 * g4(3) +
	   8.0 * gsq(3) * gsq(2) + 136.0 / 45.0 * gsq(3) * gsq(1) + 
	   7.5 * g4(2) + 
	   gsq(2) * gsq(1) + 2743.0 / 450.0 * g4(1)
	   + (N5pair + 3.0*N10pair + 5.0*N24) *(13.0/15.0 * g4(1) + 3.0 * g4(2) + 16.0 /3.0 * g4(3) ) // IWKIM
	   ) * hu +
	  (-6.0 * (6.0 * Ut * ht2 * ht + Ut * hb2 * ht + Ub * ht2 * hb) -
	   18.0 * u2 * huuT - d2 * (6.0 * hddT + 2.0 * heeT) - 
	   12.0 * hu * ut * uuT - hd * dt * (6.0 * ddT + 2.0 * eeT) - 
	   6.0 * hu * u2t * ut - 8.0 * u2 * hu * ut - 4.0 * hd * d2t * dt -
	   4.0 * d2 * hd * dt - 2.0 * hu * ut * d2 - 4.0 * u2 * hd * dt +
	   (32.0 * gsq(3) + 1.6 * gsq(1)) * huuT + 
	   (6.0 * gsq(2) + 1.2 * gsq(1)) * hu * ut + 0.8 * gsq(1) * hd * dt -
	   (32.0 * gsq(3) * mG(3) + 1.6 * gsq(1) * mG(1)) * uuT -
	   (12.0 * gsq(2) * mG(2) + 0.8 * gsq(1) * mG(1)) * u2 -
	   0.8 * gsq(1) * mG(1) * d2 + 64.0 / 9.0 * g4(3) * mG(3) - 
	   16.0 * gsq(3) * gsq(2) * (mG(3) + mG(2)) - 
	   272.0 / 45.0 * gsq(3) * gsq(1) * (mG(1) + mG(3)) - 
	   30.0 * g4(2) * mG(2) - 2.0 * gsq(2) * gsq(1) * (mG(2) + mG(1)) - 
	   5486.0 / 225.0 * g4(1) * mG(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(-52.0/15.0*g4(1)*mG(1)-12.0*g4(2)*mG(2)-64.0/3.0*g4(3)*mG(3)) // IWKIM
	   ) * u1; // checked

	dhd2 =  // checked + debugged 19.05.04 by M R Ramage (thanks Mike!)
	  (-3.0 * (3.0 * hb4 + ht2 * hb2 + htau4) -
	   3.0 * u2 * uuT - 5.0 * d2 * (3.0 * ddT + eeT) - 6.0 * d4 -
	   2.0 * u4 - 4.0 * d2 * u2 + (16.0 * gsq(3) - 
					    0.4 * gsq(1)) * ddT +
	   1.2 * gsq(1) * eeT + 0.8 * gsq(1) * u2 + 
	   (12.0 * gsq(2) + 1.2 * gsq(1)) * d2 - 16.0 / 9.0 * g4(3) + 
	   8.0 * gsq(3) * gsq(2) + 8.0 / 9.0 * gsq(3) * gsq(1) + 7.5 * g4(2) +
	   gsq(2) * gsq(1) + 287.0 / 90.0 * g4(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(7.0/15.0*g4(1)+3.0*g4(2)+16.0/3.0*g4(3)) //IWKIM
	   ) * hd +
	  (-6.0 * (6.0 * Ub * hb2 * hb + Ut * hb2 * ht + Ub * ht2 * hb +
		   2.0 * Utau * htau2 * htau) - 6.0 * u2 * huuT -
	   6.0 * d2 * (3.0 * hddT + heeT) - 6.0 * hu * ut * uuT -
	   4.0 * hd * dt * (3.0 * ddT + eeT) - 6.0 * hd * d2t * dt -
	   8.0 * d2 * hd * dt - 4.0 * u2 * hu * ut - 4.0 * hu * u2t * ut -
	   4.0 * d2 * hu * ut - 2.0 * hd * dt * u2 + 
	   (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT + 2.4 * gsq(1) * heeT +
	   1.6 * gsq(1) * hu * ut + (6.0 * gsq(2) + 1.2 * gsq(1)) * hd * dt -
	   (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT - 
	   2.4 * gsq(1) * mG(1) * eeT - 
	   (12.0 * gsq(2) * mG(2) + 1.6 * gsq(1) * mG(1)) * d2 -
	   1.6 * gsq(1) * mG(1) * u2 + 64.0 / 9.0 * g4(3) * mG(3) - 
	   16.0 * gsq(3) * gsq(2) * (mG(3) + mG(2)) - 
	   16.0 / 9.0 * gsq(3) * gsq(1) * (mG(3) + mG(1)) - 
	   30.0 * g4(2) * mG(2) - 
	   2.0 * gsq(2) * gsq(1) * (mG(2) + mG(1)) - 
	   574.0 / 45.0 * g4(1) * mG(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(-28.0/15.0*g4(1)*mG(1)-12.0*g4(2)*mG(2) -64.0/3.0*g4(3)*mG(3)) // IWKIM
	   ) * d1;

	dhe2 = 
	  (-3.0 * (3.0 * hb4 + ht2 * hb2 + htau4) -
	   5.0 * e2 * (3.0 * ddT + eeT) - 6.0 * e2 * e2 + 
	   (16.0 * gsq(3) - 0.4 * gsq(1)) * ddT + 1.2 * gsq(1) * eeT +
	   (12.0 * gsq(2) - 1.2 * gsq(1)) * eeT + 7.5 * g4(2) + 
	   1.8 * gsq(2) * gsq(1) + 13.5 * g4(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(9.0/5.0*g4(1)+3.0*g4(2)) // IWKIM
	   ) * he +
	  (-6.0 * (6.0 * Ub * hb2 * hb + Ut * hb2 * ht + Ub * ht2 * hb +
		   2.0 * Utau * htau2 * htau) - 
	   4.0 * he * et * (3.0 * ddT + eeT) - 6.0 * e2 * (3.0 * hddT + heeT) -
	   6.0 * he * e2t * et - 8.0 * e2 * he * et + 
	   (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT - 2.4 * gsq(1) * heeT + 
	   (6.0 * gsq(2) + 1.2 * gsq(1)) * he * et -
	   (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT - 
	   2.4 * gsq(1) * mG(1) * eeT - 12.0 * gsq(2) * mG(2) * e2 -
	   30.0 * g4(2) * mG(2) - 3.6 * gsq(2) * gsq(1) * (mG(1) + mG(2)) -
	   54.0 * g4(1) * mG(1)
	   + (N5pair+3.0*N10pair+5.0*N24)*(-36.0/5.0*g4(1)*mG(1)-12.0*g4(2)*mG(2)) // IWKIM
	   ) * e1; // checked
      } else {
	// NB you should introduce speedy computation here. For example sum
	// traces, not add then trace. Also surely some of the products are
	// repeated, eg u2 * u2 = u4, d2 * d2 = d4, u1 * mu * ut, d1 * md *
	// dt, d2 * d1, d2 * mq
	dmq2 = -(2.0 * mq + 8.0 * mH2sq) * u4 - 4.0 * u1 * mu * u2t * ut 
	  - 4.0 * u2 * mq * u2 - 4.0 * u2 * u1 * mu * ut - 2.0 * u4 * mq -
	  (2.0 * mq + 8.0 * mH1sq) * d4 - 4.0 * d1 * md * d2t * dt - 
	  4.0 * d2 * mq * d2 - 4.0 * d2 * d1 * md * dt - 2.0 * d4 * mq -
	  ((mq + 4.0 * mH2sq) * u2 + 2.0 * u1 * mu * ut + u2 * mq) * uuT * 3.0 
	  -((mq + 4.0 * mH1sq) * d2 + 2.0 * d1 * md * dt + d2 * mq) * 
	  (3.0 * ddT + eeT) -
	  6.0 * u2 * ((mq * u2).trace() + (u1 * mu * ut).trace()) -
	  d2 * (6.0 * (mq * d2).trace() + 6.0 * (d1 * md * dt).trace() + 
		2.0 * (ml * e2).trace() + 2.0 * (e1 * me * et).trace()) -
	  4.0 * (u2 * hu2 + hu2 * u2 + u1 * hu2t * ut + hu * u2t * hut) -
	  4.0 * (d2 * hd2 + hd2 * d2 + d1 * hd2t * dt + hd * d2t * hdt) -
	  hu2 * uuT * 6.0 - u2 * 6.0 * huT - 
	  hu * ut * 6.0 * huuT - u1 * hut * 6.0 * huuT - hd2 * 
	  (6.0 * ddT + 2.0 * eeT) - 
	  d2 * (6.0 * hdT + 2.0 * heT) -
	  hd * dt * (6.0 * hddT + 2.0 * heeT) - 
	  d1 * hdt * (6.0 * hddT + 2.0 * heeT) +
	  0.4 * gsq(1) * 
	  ((2.0 * mq +  4.0 * mH2sq) * u2 + 4.0 * u1 * mu * ut +
	   2.0 * u2 * mq + 4.0 * hu2 - 4.0 * mG(1) * hu * ut - 4.0
	   * mG(1) * u1 * hut + 8.0 * msq(1) * u2 +
	   (mq + 2.0 * mH1sq) * d2 + 2.0 * d1 * md * dt +
	   d2 * mq + 2.0 * hd2 - 2.0 * mG(1) * hd * dt - 
	   2.0 * mG(1) * d1 * hdt + 4.0 * msq(1) * d2) +
	  0.4 * gsq(1) * sP - 128.0 / 3.0 * g4(3) * msq(3) + 32.0 * gsq(3) *
	  gsq(2) * (msq(3) + msq(2) + mG(2) * mG(3)) +
	  32.0 / 45.0 * gsq(3) * gsq(1) * (msq(3) + msq(1) + 
					   mG(1) * mG(3)) + 33.0
	  * g4(2) * msq(2) + 0.4 * gsq(2) * gsq(1) * (msq(2) + msq(1) + mG(1) *
						      mG(2)) +
	  199.0 / 75.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(2.0/5.0*g4(1)*msq(1)+18.0*g4(2)*msq(2)+32.0*g4(3)*msq(3)) // IWKIM

	  + 16.0 / 3.0 * gsq(3) * sigma(3) +
	  3.0 * gsq(2) * sigma(2) + gsq(1) * sigma(1) / 15.0; // checked

	dml2 = -(2.0 * ml + 8.0 * mH1sq) * e2 * e2 - 4.0 * e1 * me * e2t * et -
	  4.0 * e2 * ml * e2 - 4.0 * e2 * e1 * me * et - 2.0 * e2 * e2 * ml -
	  ((ml + 4.0 * mH1sq) * e2 + 2.0 * e1 * me * et + e2 * ml) * 
	  (3.0 * ddT + eeT) -
	  e2 * (6.0 * mq * d2 + 6.0 * d1 * md * dt + 2.0 * ml * e2 + 
		2.0 * e1 * me * et).trace() -
	  4.0 * (e2 * he2 + he2 * e2 + e1 * he2t * et + he * e2t * het) -
	  he2 * (6.0 * ddT + 2.0 * eeT) - 
	  e2 * (6.0 * hdT + 2.0 * heT) -
	  he * et * (6.0 * hddT + 2.0 * heeT) - 
	  e1 * het * (6.0 * hddT + 2.0 * heeT) +
	  1.2 * gsq(1) * ((ml + 2.0 * mH1sq) * e2 + 2.0 * e1 * me * et + 
			  e2 * ml +
			  2.0 * he2 - 2.0 * mG(1) * he * et - 
			  2.0 * mG(1) * e1 *
			  het + 4.0 * msq(1) * e2) -
	  1.2 * gsq(1) * sP + 33.0 * g4(2) * msq(2) + 3.6 * gsq(2) * gsq(1) *
	  (msq(2) + msq(1) + mG(1) * mG(2)) + 621.0 / 25.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(18.0/5.0*g4(1)*msq(1)+18.0*g4(2)*msq(2))   // IWKIM

	  + 3.0 * gsq(2) * sigma(2) + 0.6 * gsq(1) * sigma(1); //checked
	
	dmu2 = -(2.0 * mu + 8.0 * mH2sq) * u4t - 
	  4.0 * ut * mq * u2 * u1 -
	  4.0 * u2t * mu * u2t - 4.0 * u2t * ut * mq * u1 - 
	  2.0 * u4t * mu - (2.0 * mu + 4.0 * mH2sq + 
				  4.0 * mH1sq) * ut * d2
	  * u1 - 4.0 * ut * mq * d2 * u1 - 4.0 * ut * d1 * md * dt * u1 -
	  4.0 * ut * d2 * mq * u1 - 2.0 * ut * d2 * u1 * mu -
	  ((mu + 4.0 * mH2sq) * u2t + 2.0 * ut * mq * u1 + 
	   u2t * mu) * 6.0 * uuT -
	  12.0 * u2t * (mq * u2 + u1 * mu * ut).trace() -
	  4.0 * (hu2t * u2t + u2t * hu2t + hut * u2 * hu + ut * hu2 * u1) -
	  4.0 * (hut * hd * dt * u1 + ut * d1 * hdt * hu + hut * d2 * hu + 
		 ut * hd2 * u1) -
	  12.0 * (hu2t * uuT + u2t * huT + hut * u1 * huuT +
		  ut * hu * huuT) +
	  (6.0 * gsq(2) - 0.4 * gsq(1)) * 
	  ((mu + 2.0 * mH2sq) * u2t + 2.0 * ut * mq * u1 + u2t * mu + 
	   2.0 * hu2t) +
	  12.0 * gsq(2) * (2.0 * msq(2) * u2t - mG(2) * hut * u1 - 
			   mG(2) * ut * hu) -
	  0.8 * gsq(1) * (2.0 * msq(1) * u2t - mG(1) * hut * u1 - 
			  mG(1) * ut * hu)-
	  1.6 * gsq(1) * sP - 128.0 / 3.0 * g4(3) * msq(3) + 
	  512.0 / 45.0 * gsq(1) * gsq(3) * (msq(3) + msq(1) + mG(1) * mG(3)) +
	  3424.0 / 75.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(32.0/5.0*g4(1)*msq(1)+32.0*g4(3)*msq(3)) // IWKIM

	  + 16.0 / 3.0 * gsq(3) * sigma(3) +
	  16.0 / 15.0 * gsq(1) * sigma(1); // checked

	dmd2 = -(2.0 * md + 8.0 * mH1sq) * d4t - 
	  4.0 * dt * mq * d1 * d2t -
	  4.0 * d2t * md * d2t - 4.0 * d2t * dt * mq * d1 - 
	  2.0 * d4t * md -
	  (2.0 * md + 4.0 * mH2sq + 4.0 * mH1sq) * dt * u2 * d1 -
	  4.0 * dt * mq * u2 * d1 - 4.0 * dt * u1 * mu * ut * d1 - 
	  4.0 * dt * u2 * mq * d1 - 2.0 * dt * u2 * d1 * md - 
	  ((md + 4.0 * mH1sq) * d2t + 2.0 * dt * mq * d1 + d2t * md) * 
	  (6.0 * ddT + 2.0 * eeT) -
	  4.0 * d2t * (3.0 * mq * d2 + 3.0 * d1 * md * dt + ml * e2 
		       + e1 * me * et).trace() -
	  4.0 * (hd2t * d2t + d2t * hd2t + hdt * d2 * hd + dt * hd2 * d1) -
	  4.0 * (hdt * hu * ut * d1 + dt * u1 * hut * hd + hdt * u2 * hd + 
		 dt * hu2 * d1) -
	  4.0 * hd2t * (3.0 * ddT + eeT) - 4.0 * d2t * (3.0 * hdT + heT) -
	  4.0 * hdt * d1 * (3.0 * hddT + heeT) - 
	  4.0 * dt * hd * (3.0 * hddT + heeT) +
	  (6.0 * gsq(2) + 0.4 * gsq(1)) * 
	  ((md + 2.0 * mH1sq) * d2t + 2.0 * dt * mq * d1 + d2t * md + 
	   2.0 * hd2t) +
	  12.0 * gsq(2) * (2.0 * msq(2) * d2t - mG(2) * hdt * d1 
			   - mG(2) * dt * hd) +
	  0.8 * gsq(1) * (2.0 * msq(1) * d2t - mG(1) * hdt * d1 - 
			  mG(1) * dt * hd)+
	  0.8 * gsq(1) * sP - 128.0 / 3.0 * g4(3) * msq(3) + 
	  128.0 / 45.0 * gsq(3) * gsq(1) * (msq(3) + msq(1) + mG(1) * mG(3)) +
	  808.0 / 75.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(8.0/5.0*g4(1)*msq(1)+32.0*g4(3)*msq(3)) // IWKIM

	  + 16.0 / 3.0 * gsq(3) * sigma(3) +
	  4.0 / 15.0 * gsq(1) * sigma(1); // checked

	dme2 = -(2.0 * me + 8.0 * mH1sq) * e2t * e2t - 
	  4.0 * et * ml * e2 * e1 -
	  4.0 * e2t * me * e2t - 4.0 * e2t * et * ml * e1 - 
	  2.0 * e2t * e2t * me -
	  ((me + 4.0 * mH1sq) * e2t + 2.0 * et * ml * e1 + e2t * me) *
	  (6.0 * ddT + 2.0 * eeT) - 4.0 * e2t * 
	  (3.0 * mq * d2 + 3.0 * d1 * md * dt + ml * e2 + 
	   e1 * me * et).trace() -
	  4.0 * (he2t * e2t + e2t * he2t + het * e2 * he + et * he2 * e1) -
	  4.0 * he2t * (3.0 * ddT + eeT) - 4.0 * e2t * (3.0 * hdT + heT) -
	  4.0 * het * e1 * (3.0 * hddT + heeT) - 4.0 * et * he * 
	  (3.0 * hddT + heeT) + (6.0 * gsq(2) - 1.2 * gsq(1)) * 
	  ((me + 2.0 * mH1sq) * e2t + 2.0 * et * ml * e1 + e2t * me + 
	   2.0 * he2t) +
	  12.0 * gsq(2) * (2.0 * msq(2) * e2t - mG(2) * het * e1 
			   - mG(2) * et * he) -
	  2.4 * gsq(1) * (2.0 * msq(1) * e2t - mG(1) * het * e1 - 
			  mG(1) * et * he)
	  + 2.4 * gsq(1) * sP + 2808. / 25.0 * g4(1) * msq(1) 

	  + (N5pair + 3*N10pair + 5*N24)*(72.0/5.0*g4(1)*msq(1)) // IWKIM

	  + 2.4 * gsq(1) * sigma(1); // checked

    /* Old full 3-family version 
    dhd2 =  // checked + debugged 19.05.04 by M R Ramage (thanks Mike!)
      (-3.0 * (3.0 * d2t * d2t + ut * d2 * u1 + e2t * e2t).trace() -
       3.0 * u2 * uuT - 5.0 * d2 * (3.0 * ddT + eeT) - 6.0 * d2 * d2 -
       2.0 * u2 * u2 - 4.0 * d2 * u2 + (16.0 * gsq(3) - 0.4 * gsq(1)) * ddT +
       1.2 * gsq(1) * eeT + 0.8 * gsq(1) * u2 + 
       (12.0 * gsq(2) + 1.2 * gsq(1)) * d2 - 16.0 / 9.0 * g4(3) + 
       8.0 * gsq(3) * gsq(2) + 8.0 / 9.0 * gsq(3) * gsq(1) + 7.5 * g4(2) +
       gsq(2) * gsq(1) + 287.0 / 90.0 * g4(1)) * hd +
      (-6.0 * (6.0 * hdt * d2 * d1 + hut * d2 * u1 + hdt * u2 * d1 +
	       2.0 * het * e2 * e1).trace() - 6.0 * u2 * huuT -
       6.0 * d2 * (3.0 * hddT + heeT) - 6.0 * hu * ut * uuT -
       4.0 * hd * dt * (3.0 * ddT + eeT) - 6.0 * hd * d2t * dt -
       8.0 * d2 * hd * dt - 4.0 * u2 * hu * ut - 4.0 * hu * u2t * ut -
       4.0 * d2 * hu * ut - 2.0 * hd * dt * u2 + 
       (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT + 2.4 * gsq(1) * heeT +
       1.6 * gsq(1) * hu * ut + (6.0 * gsq(2) + 1.2 * gsq(1)) * hd * dt -
       (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT - 
       2.4 * gsq(1) * mG(1) * eeT - 
       (12.0 * gsq(2) * mG(2) + 1.6 * gsq(1) * mG(1)) * d2 -
       1.6 * gsq(1) * mG(1) * u2 + 64.0 / 9.0 * g4(3) * mG(3) - 
       16.0 * gsq(3) * gsq(2) * (mG(3) + mG(2)) - 
       16.0 / 9.0 * gsq(3) * gsq(1) * (mG(3) + mG(1)) - 30.0 * g4(2) * mG(2) - 
       2.0 * gsq(2) * gsq(1) * (mG(2) + mG(1)) - 574.0 / 45.0 * g4(1) * mG(1)) 
       * d1; 
    */      

	dhu2 = 
	  (-3.0 * (3.0 * u4 + ut * d2 * u1).trace() - 
	   d2 * (3.0 * ddT + eeT)
	   -15.0 * u2 * uuT - 6.0 * u4 - 2.0 * d4 -
	   4.0 * u2 * d2 + (16.0 * gsq(3) + 0.8 * gsq(1)) * uuT +
	   12.0 * gsq(2) * u2 + 0.4 * gsq(1) * d2 - 16.0 / 9.0 * g4(3) +
	   8.0 * gsq(3) * gsq(2) + 136.0 / 45.0 * gsq(3) * gsq(1) + 
	   7.5 * g4(2) + 
	   gsq(2) * gsq(1) + 2743.0 / 450.0 * g4(1)
	   + (N5pair + 3.0*N10pair + 5.0*N24) *(13.0/15.0 * g4(1) + 3.0 * g4(2) + 16.0 /3.0 * g4(3) ) // IWKIM
	   ) * hu +
	  (-6.0 * (6.0 * hut * u2 * u1 + hut * d2 * u1 + 
		   hdt * u2 * d1).trace() -
	   18.0 * u2 * huuT - d2 * (6.0 * hddT + 2.0 * heeT) - 
	   12.0 * hu * ut * uuT - hd * dt * (6.0 * ddT + 2.0 * eeT) - 
	   6.0 * hu * u2t * ut - 8.0 * u2 * hu * ut - 4.0 * hd * d2t * dt -
	   4.0 * d2 * hd * dt - 2.0 * hu * ut * d2 - 4.0 * u2 * hd * dt +
	   (32.0 * gsq(3) + 1.6 * gsq(1)) * huuT + 
	   (6.0 * gsq(2) + 1.2 * gsq(1)) * hu * ut + 0.8 * gsq(1) * hd * dt -
	   (32.0 * gsq(3) * mG(3) + 1.6 * gsq(1) * mG(1)) * uuT -
	   (12.0 * gsq(2) * mG(2) + 0.8 * gsq(1) * mG(1)) * u2 -
	   0.8 * gsq(1) * mG(1) * d2 + 64.0 / 9.0 * g4(3) * mG(3) - 
	   16.0 * gsq(3) * gsq(2) * (mG(3) + mG(2)) - 
	   272.0 / 45.0 * gsq(3) * gsq(1) * (mG(1) + mG(3)) - 
	   30.0 * g4(2) * mG(2) - 2.0 * gsq(2) * gsq(1) * (mG(2) + mG(1)) - 
	   5486.0 / 225.0 * g4(1) * mG(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(-52.0/15.0*g4(1)*mG(1)-12.0*g4(2)*mG(2)-64.0/3.0*g4(3)*mG(3)) // IWKIM
	   ) * u1; // checked

	dhd2 =  // checked + debugged 19.05.04 by M R Ramage (thanks Mike!)
	  (-3.0 * (3.0 * d4t + ut * d2 * u1 + e2t * e2t).trace() -
	   3.0 * u2 * uuT - 5.0 * d2 * (3.0 * ddT + eeT) - 6.0 * d4 -
	   2.0 * u4 - 4.0 * d2 * u2 + (16.0 * gsq(3) 
					    - 0.4 * gsq(1)) * ddT +
	   1.2 * gsq(1) * eeT + 0.8 * gsq(1) * u2 + 
	   (12.0 * gsq(2) + 1.2 * gsq(1)) * d2 - 16.0 / 9.0 * g4(3) + 
	   8.0 * gsq(3) * gsq(2) + 8.0 / 9.0 * gsq(3) * gsq(1) + 7.5 * g4(2) +
	   gsq(2) * gsq(1) + 287.0 / 90.0 * g4(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(7.0/15.0*g4(1)+3.0*g4(2)+16.0/3.0*g4(3)) //IWKIM
	   ) * hd +
	  (-6.0 * (6.0 * hdt * d2 * d1 + hut * d2 * u1 + hdt * u2 * d1 +
		   2.0 * het * e2 * e1).trace() - 6.0 * u2 * huuT -
	   6.0 * d2 * (3.0 * hddT + heeT) - 6.0 * hu * ut * uuT -
	   4.0 * hd * dt * (3.0 * ddT + eeT) - 6.0 * hd * d2t * dt -
	   8.0 * d2 * hd * dt - 4.0 * u2 * hu * ut - 4.0 * hu * u2t * ut -
	   4.0 * d2 * hu * ut - 2.0 * hd * dt * u2 + 
	   (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT + 2.4 * gsq(1) * heeT +
	   1.6 * gsq(1) * hu * ut + (6.0 * gsq(2) + 1.2 * gsq(1)) * hd * dt -
	   (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT - 
	   2.4 * gsq(1) * mG(1) * eeT - 
	   (12.0 * gsq(2) * mG(2) + 1.6 * gsq(1) * mG(1)) * d2 -
	   1.6 * gsq(1) * mG(1) * u2 + 64.0 / 9.0 * g4(3) * mG(3) - 
	   16.0 * gsq(3) * gsq(2) * (mG(3) + mG(2)) - 
	   16.0 / 9.0 * gsq(3) * gsq(1) * (mG(3) + mG(1)) - 
	   30.0 * g4(2) * mG(2) - 
	   2.0 * gsq(2) * gsq(1) * (mG(2) + mG(1)) - 
	   574.0 / 45.0 * g4(1) * mG(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(-28.0/15.0*g4(1)*mG(1)-12.0*g4(2)*mG(2) -64.0/3.0*g4(3)*mG(3)) // IWKIM
	   ) 
	  * d1; 

	dhe2 = 
	  (-3.0 * (3.0 * d4t + ut * d2 * u1 + e2t * e2t).trace() -
	   5.0 * e2 * (3.0 * ddT + eeT) - 6.0 * e2 * e2 + 
	   (16.0 * gsq(3) - 0.4 * gsq(1)) * ddT + 1.2 * gsq(1) * eeT +
	   (12.0 * gsq(2) - 1.2 * gsq(1)) * eeT + 7.5 * g4(2) + 
	   1.8 * gsq(2) * gsq(1) + 13.5 * g4(1)
	   +(N5pair+3.0*N10pair+5.0*N24)*(9.0/5.0*g4(1)+3.0*g4(2)) // IWKIM
	   ) * he +
	  (-6.0 * (6.0 * hdt * d2 * d1 + hut * d2 * u1 + hdt * u2 * d1 +
		   2.0 * het * e2 * e1).trace() - 
	   4.0 * he * et * (3.0 * ddT + eeT) - 6.0 * e2 * (3.0 * hddT + heeT) -
	   6.0 * he * e2t * et - 8.0 * e2 * he * et + 
	   (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT - 2.4 * gsq(1) * heeT + 
	   (6.0 * gsq(2) + 1.2 * gsq(1)) * he * et -
	   (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT - 
	   2.4 * gsq(1) * mG(1) * eeT - 12.0 * gsq(2) * mG(2) * e2 -
	   30.0 * g4(2) * mG(2) - 3.6 * gsq(2) * gsq(1) * (mG(1) + mG(2)) -
	   54.0 * g4(1) * mG(1)
	   + (N5pair+3.0*N10pair+5.0*N24)*(-36.0/5.0*g4(1)*mG(1)-12.0*g4(2)*mG(2)) // IWKIM
	   ) * e1; // checked
      }	
    
    // add onto one-loop beta functions
    dmq2 *= oneO16Pif; dmq += dmq2;
    dml2 *= oneO16Pif; dml += dml2;
    dmu2 *= oneO16Pif; dmu += dmu2;
    dmd2 *= oneO16Pif; dmd += dmd2;
    dme2 *= oneO16Pif; dme += dme2;
    dhu2 *= oneO16Pif; dhu += dhu2;
    dhd2 *= oneO16Pif; dhd += dhd2;
    dhe2 *= oneO16Pif; dhe += dhe2;
    }

    // Default is to include these 2-loop corrections anyhow because they can 
    // be so important: gauginos + higgs 
    dmG2 = 2.0 * gsq * 
      (babBeta * gsqM + mG * (babBeta * gsq) + 
       cuBeta * huuT - cuBeta * mG * uuT + 
       cdBeta * hddT - cdBeta * mG * ddT + 
       ceBeta * heeT - ceBeta * mG * eeT); // checked

    double dmH1sq2, dm3sq2, dmH2sq2;
    if (MIXING < 1) {
      /// The following are valid in the third-family approximation -- they are
      /// much faster, and should be a good approximation to the no-mixed case
      dm3sq2 = m3sq * 
	(-3.0 * (3.0 * ht4 + 3.0 * hb4 + 2.0 * hb2 * ht2 + htau4) +
	 (16.0 * gsq(3) + 0.8 * gsq(1)) * uuT + 
	 (16.0 * gsq(3) - 0.4 * gsq(1)) * ddT + 
	 1.2 * gsq(1) * eeT + 7.5 * g4(2) + 1.8 * gsq(1) * gsq(2) + 
	 207. / 50. * g4(1)
	 + (N5pair + 3.0 * N10pair + 5.0 * N24 ) * (3.0/5.0 * g4(1) + 3.0 * g4(2) ) // IWKIM
) +
	displaySusyMu() * 
	(-12.0 * (3.0 * Ut * ht * ht2 + 3.0 * Ub * hb * hb2 + Ut * hb2 * ht +
		  Ub * ht2 * hb + Utau * htau2 * htau) +
	 (32.0 * gsq(3) + 1.9 * gsq(1)) * huuT + 
	 (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT + 2.4 * gsq(1) * heeT -
	 (32.0 * gsq(3) * mG(3) + 1.6 * gsq(1) * mG(1)) * uuT -
	 (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT -
	 2.4 * gsq(1) * mG(1) * eeT - 30.0 * g4(2) * mG(2) - 
	 18.0 / 5.0 * gsq(1)
	 * gsq(2) * (mG(1) + mG(2)) - 414. / 25.0 * g4(1) * mG(1)
	 + (N5pair + 3.0 * N10pair + 5.0 * N24 ) * ( -12.0/5.0 * g4(1) * mG(1)- 12.0 * g4(2) * mG(2) )// IWKIM
	 ); // checked
      
      dmH2sq2 = -6.0 * 
	(6.0 * (mH2sq + mq3 + mu3) * ht4 + 
	 hb2 * ht2 * (mH1sq + mH2sq + 2.0 * mq3 + mu3 + md3) + 
	 ht2 * 12.0 * Ut2 + ht2 * Ub2 + hb2 * Ut2 + 2.0 * hb * ht * Ut * Ub) +
	(32.0 * gsq(3) + 1.6 * gsq(1)) * 
	((mH2sq + mq3 + mu3) * ht2 + Ut2) +
	32.0 * gsq(3) * (2.0 * msq(3) * ht2 - 2.0 * mG(3) * ht * Ut) +
	1.6 * gsq(1) * (2.0 * msq(1) * ht2 - 2.0 * mG(1) * ht * Ut) +
	1.2 * gsq(1) * sP + 33.0 * g4(2) * msq(2) + 
	18.0 / 5.0 * gsq(2) * gsq(1) * (msq(2) + msq(1) + mG(1) * mG(2)) +
	621.0 / 25.0 * g4(1) * msq(1) 
        + (N5pair + 3.0 *N10pair + 5.0 * N24 )* (18.0/5.0 * g4(1) *msq(1) + 18.0 * g4(2) * msq(2) )  // IWKIM
        + 3.0 * gsq(2) * sigma(2) +
	0.6 * gsq(1) * sigma(1); // checked
    
      dmH1sq2 = -6.0 *
	(6.0 * (mH1sq + mq3 + md3) * hb4 + 
	 (mH1sq + mH2sq + 2.0 * mq3 + mu3 + md3) * ht2 * hb2 + 
	 2.0 * (mH1sq + ml3 + me3) * htau4 +
	 12.0 * Ub2 * hb2 + hb2 * Ut2 + ht2 * Ub2 + 2.0 * Ut * ht * Ub * hb +
	 4.0 * htau2 * Utau2) +
	(32.0 * gsq(3) - 0.8 * gsq(1)) * ((mH1sq + mq3 + md3) * hb2 + Ub2) +
	32.0 * gsq(3) * (2.0 * msq(3) * ddT - 2.0 * mG(3) * hddT) -
	0.8 * gsq(1) * (2.0 * msq(1) * ddT - 2.0 * mG(1) * hddT) +
	2.4 * gsq(1) * (((mH1sq + ml3 + me3) * htau2 + Utau2) +
			2.0 * msq(1) * eeT - 2.0 * mG(1) * heeT) 
	- 1.2 * gsq(1) * sP +
	33.0 * g4(2) * msq(2) + 
	3.6 * gsq(2) * gsq(1) * (msq(2) + msq(1) + mG(1) * mG(2)) +
	621.0 / 25.0 * g4(1) * msq(1) 
        + (N5pair + 3.0 *N10pair + 5.0 * N24 )* (18.0/5.0 * g4(1) *msq(1) + 18.0 * g4(2) * msq(2) )  // IWKIM
        + 3.0 * gsq(2) * sigma(2) + 
	0.6 * gsq(1) * sigma(1); // checked
    } else {
      /// In the mixed case, we need to use the slower full 3-family
      /// expressions
      dmH2sq2 = -6.0 * 
	(6.0 * (mH2sq + mq) * u4 + 6.0 * u1 * mu * u2t * ut +
	 (mH1sq + mH2sq + mq) * u2 * d2 + u1 * mu * ut * d2 +
	 u2 * mq * d2 + u2 * d1 * md * dt + 6.0 * hu2 * u2 +
	 6.0 * hu * u2t * hut + hd2 * u2 + d2 * hu2 + 
	 hd * dt * u1 * hut + d1 * hdt * hu * ut).trace() +
	(32.0 * gsq(3) + 1.6 * gsq(1)) * 
	((mH2sq + mq) * u2 + u1 * mu * ut + hu2).trace() +
	32.0 * gsq(3) * (2.0 * msq(3) * uuT - 2.0 * mG(3) * huuT) +
	1.6 * gsq(1) * (2.0 * msq(1) * uuT - 2.0 * mG(1) * huuT) +
	1.2 * gsq(1) * sP + 33.0 * g4(2) * msq(2) + 
	18.0 / 5.0 * gsq(2) * gsq(1) * (msq(2) + msq(1) + mG(1) * mG(2)) +
	621.0 / 25.0 * g4(1) * msq(1) 
        + (N5pair + 3.0 *N10pair + 5.0 * N24 )* (18.0/5.0 * g4(1) *msq(1) + 18.0 * g4(2) * msq(2) )  // IWKIM
	+ 3.0 * gsq(2) * sigma(2) +
	0.6 * gsq(1) * sigma(1); // checked
      
      dmH1sq2 = -6.0 *
	(6.0 * (mH1sq + mq) * d4 + 6.0 * dt * md * d2 * d1 +
	 (mH1sq + mH2sq + mq) * u2 * d2 + u1 * mu * ut * d2 +
	 u2 * mq * d2 + u2 * d1 * md * dt + 2.0 * (mH1sq + ml) * e2 * e2 +
	 2.0 * e1 * me * e2t * et + 6.0 * hd2 * d2 + 6.0 * hd * d2t * hdt + 
	 hu2 * d2 + u2 * hd2 + hu * ut * d1 * hdt + u1 * hut * hd * dt +
	 2.0 * he2 * e2 + 2.0 * he * e2t * het).trace() +
	(32.0 * gsq(3) - 0.8 * gsq(1)) * ((mH1sq + mq) * d2 + d1 * md * dt +
					  hd2).trace() +
	32.0 * gsq(3) * (2.0 * msq(3) * ddT - 2.0 * mG(3) * hddT) -
	0.8 * gsq(1) * (2.0 * msq(1) * ddT - 2.0 * mG(1) * hddT) +
	2.4 * gsq(1) * (((mH1sq + ml) * e2 + e1 * me * et + he2).trace() +
			2.0 * msq(1) * eeT - 2.0 * mG(1) * heeT) - 
	1.2 * gsq(1) * sP +
	33.0 * g4(2) * msq(2) + 
	3.6 * gsq(2) * gsq(1) * (msq(2) + msq(1) + mG(1) * mG(2)) +
	621.0 / 25.0 * g4(1) * msq(1) 
        + (N5pair + 3.0 *N10pair + 5.0 * N24 )* (18.0/5.0 * g4(1) *msq(1) + 18.0 * g4(2) * msq(2) )  // IWKIM
	+ 3.0 * gsq(2) * sigma(2) + 
	0.6 * gsq(1) *
	sigma(1); // checked+corrected 27/9/05

      dm3sq2 = m3sq * 
	(-3.0 * (3.0 * u4t + 3.0 * d4t + 2.0 * ut * d2
		 * u1 + e2t * e2t).trace() +
	 (16.0 * gsq(3) + 0.8 * gsq(1)) * uuT + 
	 (16.0 * gsq(3) - 0.4 * gsq(1)) * ddT + 
	 1.2 * gsq(1) * eeT + 7.5 * g4(2) + 1.8 * gsq(1) * gsq(2) + 
	 207. / 50. * g4(1)
	 + (N5pair + 3.0 * N10pair + 5.0 * N24 ) * (3.0/5.0 * g4(1) + 3.0 * g4(2) ) // IWKIM
	 ) +
	displaySusyMu() * 
	(-12.0 * (3.0 * hut * u2 * u1 + 3.0 * hdt * d2 * d1 + hut * d2 * u1 +
		  hdt * u2 * d1 + het * e2 * e1).trace() +
	 (32.0 * gsq(3) + 1.9 * gsq(1)) * huuT + 
	 (32.0 * gsq(3) - 0.8 * gsq(1)) * hddT + 2.4 * gsq(1) * heeT -
	 (32.0 * gsq(3) * mG(3) + 1.6 * gsq(1) * mG(1)) * uuT -
	 (32.0 * gsq(3) * mG(3) - 0.8 * gsq(1) * mG(1)) * ddT -
	 2.4 * gsq(1) * mG(1) * eeT - 30.0 * g4(2) * mG(2) 
	 - 18.0 / 5.0 * gsq(1)
	 * gsq(2) * (mG(1) + mG(2)) - 414. / 25.0 * g4(1) * mG(1)
	 + (N5pair + 3.0 * N10pair + 5.0 * N24 ) * ( -12.0/5.0 * g4(1) * mG(1)- 12.0 * g4(2) * mG(2) )// IWKIM
	 ); // checked
    }    

    dmG = dmG + dmG2 * oneO16Pif;
    dm3sq = dm3sq + dm3sq2 * oneO16Pif;
    dmH1sq = dmH1sq + dmH1sq2 * oneO16Pif;
    dmH2sq = dmH2sq + dmH2sq2 * oneO16Pif;
  }

  SoftParsMssm dsoft(dsb, dmG, dhu, dhd, dhe, dmq, dmu,
		     dmd, dml, dme, dm3sq, dmH1sq, dmH2sq, 
		     displayGravitino(), displayMu(),
		     displayLoops(), displayThresholds());

  return dsoft;
}


// Outputs derivatives (DRbar scheme) in the form of ds. a contains the
// matrices calculated that are handy for computation.
// W=  LL Y^E H1 ER + QL Y^D H1 DR + QL Y^U H2 UR + smu H2 H1
// is the superpotential. Consistent with Allanach, Dedes, Dreiner
// hep-ph/9902251 and Barger, Berger and Ohmann hep-ph/9209232, 9311269
// EXCEPT for the sign of smu, which is opposite. These equations are also
// valid for W=  - LL Y^E H1 ER - QL Y^D H1 DR + QL Y^U H2 UR + smu H2 H1, the
// new SOFTSUSY convention
MssmSusy MssmSusy::MssmSusy_beta_high(sBrevity & a) const {
  // Wave function renormalisations: convention for g**(i, j) is that i is the
  // LOWER index and j the upper in our paper hep-ph/9902251
  static DoubleMatrix gEE(3, 3), gLL(3, 3), gQQ(3, 3), gDD(3, 3), 
    gUU(3, 3);
  
  double gH1H1=0.0, gH2H2=0.0;
  static DoubleVector dg(1,3);
  
  // keep this option in order to interface with RPVSUSY  
  MssmSusy_anomalousDimension_high(gEE, gLL, gQQ, gUU, gDD, dg, gH1H1, gH2H2, a);
  
  // To keep this a const function
  const DoubleMatrix &u1 = u.display(), &d1 = d.display(), &e1 = e.display();
  
  // contain derivatives of up, down quarks and leptons
  static DoubleMatrix du(3, 3), dd(3, 3), de(3, 3); 
  // mu parameter derivatives
  double dmu;
  
  // RGEs of SUSY parameters
  du = u1 * (gUU + gH2H2) + gQQ * u1;
  dd = d1 * (gDD + gH1H1) + gQQ * d1;
  de = e1 * (gEE + gH1H1) + gLL * e1;
  
  dmu = smu * (gH1H1 + gH2H2);

  // Following is from hep-ph/9308335: scalar H anomalous dimensions (as
  // opposed to the chiral superfield one - see hep-ph/0111209).
  // Additional contribution from Feynman gauge running at two-loops of tan
  // beta: we need this to link up with BPMZ: hep-ph/0112251
  double &uuT = a.uuT, &ddT = a.ddT, &eeT = a.eeT;
  DoubleVector &gsq=a.gsq;
  DoubleMatrix &u2=a.u2, &d2=a.d2, &e2=a.e2, &d2t=a.d2t;
  double t = (d2 * u2).trace();
  static const double oneLoop = 1.0 / (16.0 * sqr(PI));
  double sH1H1 = oneLoop * (3.0 * ddT + eeT);
  double sH2H2 = oneLoop * 3.0 * uuT;

  const static double twolp = 4.010149318236068e-5; // 1/(16 pi^2)^2
  if (displayLoops() > 1) {
    // I don't posess the O(g^4) terms for these RGEs in the Feynman gauge
    // and consequently have neglected. They CANCEL in the RGE for tan
    // beta, but not in the RGE of the Higgs vev. 
    sH1H1 = sH1H1 + twolp * 
      (-(3.0 * (e2 * e2).trace() + 9.0 * (d2t * d2t).trace() + 3.0 * t) + 
       (16 * gsq(3) - 0.4 * gsq(1)) * ddT + 1.2 * gsq(1) * eeT);
    sH2H2 = sH2H2 + twolp *
      (- (9.0 * (u2 * u2).trace() + 3.0 * t) +
       (16 * gsq(3) + 0.8 * gsq(1)) * uuT);
  }

  double cosb2 = sqr(cos(atan(tanb))), sinb2 = 1.0 - cosb2;
  double feynman = 1.5 * gsq(2) + 0.3 * gsq(1);
  /// One-loop RGEs in Feynman gauge
  double dt = displayTanb() * (sH1H1 - sH2H2);
  double dHvev = hVev * 
    (cosb2 * (-sH1H1 + feynman * oneLoop) + 
     sinb2 * (-sH2H2 + feynman * oneLoop)); 

  if (displayLoops() > 1) {
    /// Two-loop pieces
    dt = dt + displayTanb() * twolp * (3.0 * ddT + eeT - 3.0 * uuT) * feynman;
    dHvev = dHvev - hVev * twolp * (cosb2 * (3.0 * ddT + eeT) +
				    sinb2 * 3.0 * uuT) * feynman;
  }
  
  // Contains all susy derivatives:
  MssmSusy ds(du, dd, de, dg, dmu, dt, displayMu(), displayLoops(),
	       displayThresholds(), dHvev); 

  return ds;
}


// Outputs derivatives of anomalous dimensions, from which the running can be
// derived. 
void SoftParsMssm::SoftParsMssm_anomalousDeriv_high(DoubleMatrix & gEE, DoubleMatrix & gLL,
				  DoubleMatrix & gQQ, DoubleMatrix & gUU,
				  DoubleMatrix & gDD, 
				  double & gH1H1, double & gH2H2)  const {
  // Constants for gauge running
  static DoubleVector bBeta(3), cuBeta(3), cdBeta(3), ceBeta(3);
  static DoubleMatrix babBeta(3, 3);
  
  if (bBeta(1) < 1.0e-5) // Constants not set yet
    setBetas_high(babBeta, cuBeta, cdBeta, ceBeta, bBeta);
  
  // For calculational brevity: 
  static sBrevity a;
  // convert to beta functions
  static MssmSusy dsb;
  
  // calculate derivatives for full SUSY spectrum. Brevity calculations come
  // out encoded in a
  dsb = MssmSusy::MssmSusy_beta_high(a);
  
  static DoubleVector g1(3);
  g1 = displayGauge();
  
  // To keep this a const function: TIME SAVINGS
  DoubleMatrix &dt=a.dt, &ut=a.ut, &et=a.et;      
  DoubleVector &gsq=a.gsq; // &g3=a.g3, &g4=a.g4;
  
  static DoubleMatrix hu(3, 3), hd(3, 3), he(3, 3);
  static DoubleMatrix hut(3, 3), hdt(3, 3), het(3, 3);
  static DoubleVector gsqM(1, 3);
  
  hu = displayTrilinear(UA); hd = displayTrilinear(DA); 
  he = displayTrilinear(EA); 
  hut = hu.transpose(); hdt = hd.transpose(); het = he.transpose();
  
  double huuT = (hu * ut).trace(), hddT = (hd * dt).trace(), 
    heeT = (he * et).trace(); 
  gsqM = gsq * mGaugino; 
  
  if (displayLoops() > 0) { // CHECKED: agrees with our conventions
    const static double eightO3 = 8.0 / 3.0, oneO30 = 1.0 / 30.0;
    gLL = - (he * et + 0.3 * gsqM(1) + 1.5 * gsqM(2));
    gEE = - (2.0 * (et * he) + 1.2 * gsqM(1));
    gQQ = - (hd * dt + hu * ut + oneO30 * gsqM(1) + 1.5 * gsqM(2) + 
	     eightO3 * gsqM(3));
    gDD = - (2.0 * dt * hd + 4.0 * oneO30 * gsqM(1) + 
	     eightO3 * gsqM(3));
    gUU = - (2.0 * ut * hu + 16.0 * oneO30 * gsqM(1) +
	     eightO3 * gsqM(3));
    gH1H1 = - (3.0 * hddT + heeT + 0.3 * gsqM(1) + 1.5 * gsqM(2));
    gH2H2 = - (3.0 * huuT + 0.3 * gsqM(1) + 1.5 * gsqM(2));

    const static double oneO16Pisq = 1.0 / (16.0 * sqr(PI));
    gH1H1 = gH1H1 * oneO16Pisq;
    gH2H2 = gH2H2 * oneO16Pisq;
    gEE  *= oneO16Pisq;    
    gLL  *= oneO16Pisq;
    gQQ  *= oneO16Pisq;
    gUU  *= oneO16Pisq;
    gDD  *= oneO16Pisq;
  }
}


void setBetas_high(DoubleMatrix & babBeta, DoubleVector &cuBeta, DoubleVector
	       & cdBeta, DoubleVector & ceBeta, DoubleVector & bBeta) {
  // 1 loop gauge beta fns
  bBeta(1) = 33.0 / 5.0 + N5pair + 3.0 * N10pair + 5.0 * N24;
  bBeta(2) = 1.0        + N5pair + 3.0 * N10pair + 5.0 * N24; 
  bBeta(3) = -3.0       + N5pair + 3.0 * N10pair + 5.0 * N24; 
  
  // Extra sleptons included in vectorlike rep.s: 3 ER + 2 LL
  //#ifdef SLEPTONS
  //bBeta(1) = bBeta(1) + (3.0 * 1.2 + 0.6 * 2.0);
  //bBeta(2) = bBeta(2) + 2.0;
  //#endif
  
  // Next come the two loop MSSM constants for gauge beta fns
  babBeta(1, 1) = 199.0 / 25.0 + 7.0 / 15.0 * N5pair + 23.0 / 5.0 * N10pair + 50.0 / 3.0 * N24;
  babBeta(1, 2) = 27.0 / 5.0   + 9.0 /  5.0 * N5pair +  3.0 / 5.0 * N10pair + 30.0       * N24; 
  babBeta(1, 3) = 88.0 / 5.0   + 32.0/ 15.0 * N5pair + 48.0 / 5.0 * N10pair + 160.0 / 3.0* N24; 
  babBeta(2, 1) = 9.0 / 5.0    + 3.0 /  5.0 * N5pair +  1.0 / 5.0 * N10pair + 10.0       * N24;    
  babBeta(2, 2) = 25.0         + 7.0        * N5pair + 21.0       * N10pair + 90.0       * N24;       
  babBeta(2, 3) = 24.0                               + 16.0       * N10pair + 32.0       * N24;
  babBeta(3, 1) = 11.0 / 5.0   + 4.0 / 15.0 * N5pair +  6.0 / 5.0 * N10pair + 20.0 / 3.0 * N24;   
  babBeta(3, 2) = 9.0                                +  6.0       * N10pair + 12.0       * N24;        
  babBeta(3, 3) = 14.0         + 34.0/ 3.0  * N5pair + 34.0       * N10pair + 460.0 / 3.0* N24;
  cuBeta(1) = 26.0 / 5.0; cuBeta(2) = 6.0; cuBeta(3) = 4.0;
  cdBeta(1) = 14.0 / 5.0; cdBeta(2) = 6.0; cdBeta(3) = 4.0;
  ceBeta(1) = 18.0 / 5.0; ceBeta(2) = 2.0; ceBeta(3) = 0.0;
}

// Outputs wave function renormalisation for SUSY parameters and gauge beta
// functions up to 2 loops. 
void MssmSusy::MssmSusy_anomalousDimension_high(DoubleMatrix & gEE, DoubleMatrix & gLL,
				    DoubleMatrix & gQQ, DoubleMatrix & gUU,
				    DoubleMatrix & gDD, DoubleVector & dg, 
				    double & gH1H1, double & gH2H2, 
				    sBrevity & a)  const {
  // Constants for gauge running
  static DoubleVector bBeta(3), cuBeta(3), cdBeta(3), ceBeta(3);
  static DoubleMatrix babBeta(3, 3);
  if (bBeta(1) < 1.0e-5) // Constants not set yet
    setBetas_high(babBeta, cuBeta, cdBeta, ceBeta, bBeta);
  
  //  sBrevity a contains all of the shortcutted matrices etc;
  a.calculate(u.display(), d.display(), e.display(), g.display());
  
  // For calculational brevity
  double &uuT = a.uuT, &ddT = a.ddT, &eeT = a.eeT;
  DoubleVector &gsq=a.gsq, &g3=a.g3;
  
  // 1 loop contributions: 
  if (displayLoops() > 0) {
    static const double oneO16Pisq = 1.0 / (16.0 * sqr(PI)); 
    
    MssmSusy_getOneLpAnom_high(gEE, gLL, gQQ, gDD, gUU, gH1H1, gH2H2, a);
    dg = oneO16Pisq * g3 * bBeta;  
  } 
  
  if (displayLoops() > 1) { 
    MssmSusy_getTwoLpAnom_high(gEE, gLL, gQQ, gDD, gUU, gH1H1, gH2H2, a); 
							      
    const static double twolp = 4.010149318236068e-5; 
    
    dg = dg + g3 * (babBeta * gsq - cuBeta * uuT - cdBeta *
		    ddT - ceBeta * eeT) * twolp;  
  }
}



// outputs one-loop anomlous dimensions gii given matrix inputs
// Note that we use the convention (for matrices in terms of gamma's)
// gamma^Li_Lj = M_ij for LH fields and
// gamma^Rj_Ri = M_ij for RH fields (since they are really the complex
// conjugates of the RH fields): CHECKED 23/5/02
void MssmSusy::MssmSusy_getOneLpAnom_high(DoubleMatrix & gEE, DoubleMatrix & gLL,
				DoubleMatrix & gQQ, DoubleMatrix & gDD,
				DoubleMatrix & gUU, double & gH1H1, double &
				gH2H2, sBrevity & a) const {
  // For calculational brevity
  DoubleMatrix &u2=a.u2, &d2=a.d2, &e2=a.e2, &u2t=a.u2t, &d2t=a.d2t,
    &e2t=a.e2t;      
  double &uuT = a.uuT, &ddT = a.ddT, &eeT = a.eeT;
  DoubleVector &gsq=a.gsq;
  
  static const double oneO16Pisq = 1.0 / (16.0 * sqr(PI));
  
  gEE = oneO16Pisq * (2.0 * e2t - 1.2 * gsq(1));
  gLL = oneO16Pisq * (e2 - (0.3 * gsq(1) + 1.5 * gsq(2)));
  gQQ = oneO16Pisq * (d2 + u2 - (gsq(1) / 30.0 + 1.5 * gsq(2) + 8 *
				    gsq(3) / 3.0));
  gUU = oneO16Pisq * (2.0 * u2t - (8 * gsq(1) / 15.0 + 8 * gsq(3) /
				      3.0)); 
  gDD = oneO16Pisq * (2.0 * d2t - 
			 (2 * gsq(1) / 15.0 + 8 * gsq(3) / 3.0));
  gH1H1 = oneO16Pisq * (3.0 * ddT + eeT - (0.3 * gsq(1) + 1.5 *
					      gsq(2)));
  gH2H2 = oneO16Pisq * (3.0 * uuT - (0.3 * gsq(1) + 1.5 * gsq(2)));
}

// adds two-loop anomalous dimension contribution to gii given matrix inputs
// g^Li_Lj = m_{ij} for LH fields
// g^Ei_Ej = m_{ji} for RH fields CHECKED: 23/5/02
void MssmSusy::MssmSusy_getTwoLpAnom_high(DoubleMatrix & gEE, DoubleMatrix & gLL,
				DoubleMatrix & gQQ, DoubleMatrix & gDD,
				DoubleMatrix & gUU, double & gH1H1, double &
				gH2H2, sBrevity & a) const {
  // For calculational brevity
  DoubleMatrix &dt=a.dt, &ut=a.ut, &u2=a.u2, &d2=a.d2, &e2=a.e2,
    &u2t=a.u2t, &d2t=a.d2t, &e2t=a.e2t, &u1=a.u1, &d1=a.d1;      
  double &uuT = a.uuT, &ddT = a.ddT, &eeT = a.eeT;
  DoubleVector &gsq=a.gsq, &g4=a.g4;
  
  // Everything gets the (1/16pi^2)^2 factor at the bottom
  DoubleMatrix ee(3, 3), ll(3, 3), qq(3, 3), dd(3, 3), uu(3, 3); 
  
  // Two-loop pure gauge anom dimensions
  double h1h1 = (3.75 * g4(2) + 2.07 * g4(1) + 0.9 * gsq(2) * gsq(1))
    + (N5pair + 3.0 * N10pair + 5.0 * N24 ) * (g4(1)*(3.0)/(10.0) + gsq(1)*gsq(2)*(0.0)/(1.0) + gsq(1)*gsq(3)*(0.0)/(1.0) + g4(2)*(3.0)/(2.0) + gsq(2)*gsq(3)*(0.0)/(1.0) + g4(3)*(0.0)/(1.0)); 

  double h2h2 = h1h1;
  ll = h1h1;

  ee = (234. * g4(1) / 25.0)
    + (N5pair + 3.0*N10pair + 5.0*N24) *(g4(1)*(6.0)/(5.0) + gsq(1)*gsq(2)*(0.0)/(1.0) + gsq(1)*gsq(3)*(0.0)/(1.0) + g4(2)*(0.0)/(1.0) + gsq(2)*gsq(3)*(0.0)/(1.0) + g4(3)*(0.0)/(1.0)  ) ;

  qq = (-8.0 * g4(3) / 9.0 + 3.75 * g4(2) + 199.0 * g4(1) / 900.0 + 8.0 *
	gsq(3) * gsq(2) + 8 * gsq(3) * gsq(1) / 45.0 + 0.1 * gsq(1) *
	gsq(2))
    + (N5pair + 3.0 * N10pair + 5.0 * N24 ) *(g4(1)*(1.0)/(30.0) + gsq(1)*gsq(2)*(0.0)/(1.0) + gsq(1)*gsq(3)*(0.0)/(1.0) + g4(2)*(3.0)/(2.0) + gsq(2)*gsq(3)*(0.0)/(1.0) + g4(3)*(8.0)/(3.0)); 

  dd = (-8.0 * g4(3) / 9.0 + 202.0 / 225.0 * g4(1) + 32.0 / 45.0 *
	gsq(3) * gsq(1))
    + (N5pair + 3.0 * N10pair + 5.0 * N24 ) *(g4(1)*(2.0)/(15.0) + gsq(1)*gsq(2)*(0.0)/(1.0) + gsq(1)*gsq(3)*(0.0)/(1.0) + g4(2)*(0.0)/(1.0) + gsq(2)*gsq(3)*(0.0)/(1.0) + g4(3)*(8.0)/(3.0)) ;

  uu = (-8.0 * g4(3) / 9.0 + 856.0 / 225.0 * g4(1) + 128.0 / 45.0 *
	gsq(3) * gsq(1))
    + (N5pair + 3.0 * N10pair + 5.0 *N24 ) * (g4(1)*(8.0)/(15.0) + gsq(1)*gsq(2)*(0.0)/(1.0) + gsq(1)*gsq(3)*(0.0)/(1.0) + g4(2)*(0.0)/(1.0) + gsq(2)*gsq(3)*(0.0)/(1.0) + g4(3)*(8.0)/(3.0)); 

  //////

  ll = ll + 1.2 * gsq(1) * e2;
  ee = ee + (6.0 * gsq(2) - 1.2 * gsq(1)) * e2t;
  qq = qq + 0.4 * gsq(1) * (d2 + 2.0 * u2);
  dd = dd + (6.0 * gsq(2) + 0.4 * gsq(1)) * d2t;
  uu = uu + (6.0 * gsq(2) - 0.4 * gsq(1)) * u2t;

  h1h1 = h1h1 + (16 * gsq(3) - 0.4 * gsq(1)) * ddT + 1.2 * gsq(1) * eeT; 
  h2h2 = h2h2 + (16 * gsq(3) + 0.8 * gsq(1)) * uuT;

  // Two-loop pure Yukawa contributions
  double s = (eeT + 3.0 * ddT), t = (d2 * u2).trace();

  ll = ll - (2.0 * e2 * e2 + s * e2);
  ee = ee - (2.0 * e2t * e2t + 2.0 * s * e2t);
  qq = qq - (2.0 * d2 * d2 + d2 * s + 2.0 * u2 * u2 + 3.0 * uuT * u2);
  dd = dd - (2.0 * d2t * d2t + 2.0 * (dt * u2 * d1) + 2 * s * d2t);
  uu = uu - (2.0 * u2t * u2t + 2.0 * (ut * d2 * u1) + 6.0 * uuT * u2t);
  h1h1 = h1h1 - (3.0 * (e2 * e2).trace() + 9.0 * (d2t * d2t).trace() +
		 3.0 * t);
  h2h2 = h2h2 - (9.0 * (u2 * u2).trace() + 3.0 * t);

  const static double twolp = 4.010149318236068e-5; // 1/(16 pi^2)^2
  
  gLL = gLL + twolp * ll;
  gEE = gEE + twolp * ee;
  gQQ = gQQ + twolp * qq;
  gDD = gDD + twolp * dd;
  gUU = gUU + twolp * uu;
  gH1H1 = gH1H1 + twolp * h1h1;
  gH2H2 = gH2H2 + twolp * h2h2;
}

