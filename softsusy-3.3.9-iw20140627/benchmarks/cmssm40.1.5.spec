# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
     3   # Warning: stau LSP
Block MODSEL  # Select model
     1    1   # sugra
Block SMINPUTS             # Standard Model inputs
     1    1.27934000e+02   # alpha_em^(-1)(MZ) SM MSbar
     2    1.16637000e-05   # G_Fermi
     3    1.17200000e-01   # alpha_s(MZ)MSbar
     4    9.11876000e+01   # MZ(pole)
     5    4.25000000e+00   # mb(mb)
     6    1.73300000e+02   # Mtop(pole)
     7    1.77700000e+00   # Mtau(pole)
Block MINPAR               # SUSY breaking input parameters
     3    4.00000000e+01   # tanb
     4    1.00000000e+00   # sign(mu)
     1    3.90000000e+02   # m0
     2    7.00000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.67496266e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.20641566e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03883200e+01   # MW
        25     1.18671904e+02   # h0
        35     8.06859142e+02   # H0
        36     8.06862471e+02   # A0
        37     8.11134129e+02   # H+
   1000021     1.57094185e+03   # ~g
   1000022     2.94221541e+02   # ~neutralino(1)
   1000023     5.59328512e+02   # ~neutralino(2)
   1000024     5.59472734e+02   # ~chargino(1)
   1000025    -9.12542038e+02   # ~neutralino(3)
   1000035     9.20022920e+02   # ~neutralino(4)
   1000037     9.20855864e+02   # ~chargino(2)
   1000001     1.47782240e+03   # ~d_L
   1000002     1.47580161e+03   # ~u_L
   1000003     1.47778269e+03   # ~s_L
   1000004     1.47576183e+03   # ~c_L
   1000005     1.25367621e+03   # ~b_1
   1000006     1.08845330e+03   # ~t_1
   1000011     6.10397355e+02   # ~e_L
   1000012     6.04954719e+02   # ~nue_L
   1000013     6.10253013e+02   # ~mu_L
   1000014     6.04809967e+02   # ~numu_L
   1000015     2.93076039e+02   # ~stau_1
   1000016     5.54505499e+02   # ~nu_tau_L
   2000001     1.41690714e+03   # ~d_R
   2000002     1.42222737e+03   # ~u_R
   2000003     1.41682811e+03   # ~s_R
   2000004     1.42222233e+03   # ~c_R
   2000005     1.31847904e+03   # ~b_2
   2000006     1.31752950e+03   # ~t_2
   2000011     4.71619807e+02   # ~e_R
   2000013     4.71242432e+02   # ~mu_R
   2000015     5.78489728e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.59709534e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.98236580e-01   # N_{1,1}
  1  2    -6.14398623e-03   # N_{1,2}
  1  3     5.57115049e-02   # N_{1,3}
  1  4    -1.95502145e-02   # N_{1,4}
  2  1     1.53975837e-02   # N_{2,1}
  2  2     9.86734028e-01   # N_{2,2}
  2  3    -1.36975805e-01   # N_{2,3}
  2  4     8.57700451e-02   # N_{2,4}
  3  1    -2.52714799e-02   # N_{3,1}
  3  2     3.67780129e-02   # N_{3,2}
  3  3     7.05185532e-01   # N_{3,3}
  3  4     7.07617196e-01   # N_{3,4}
  4  1    -5.14587014e-02   # N_{4,1}
  4  2     1.58005021e-01   # N_{4,2}
  4  3     6.93431484e-01   # N_{4,3}
  4  4    -7.01098561e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.80820242e-01   # U_{1,1}
  1  2    -1.94914476e-01   # U_{1,2}
  2  1     1.94914476e-01   # U_{2,1}
  2  2     9.80820242e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.92473346e-01   # V_{1,1}
  1  2    -1.22460837e-01   # V_{1,2}
  2  1     1.22460837e-01   # V_{2,1}
  2  2     9.92473346e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.01236072e-01   # F_{11}
  1  2     9.15974680e-01   # F_{12}
  2  1     9.15974680e-01   # F_{21}
  2  2    -4.01236072e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     8.06975404e-01   # F_{11}
  1  2     5.90585047e-01   # F_{12}
  2  1    -5.90585047e-01   # F_{21}
  2  2     8.06975404e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     2.87754671e-01   # F_{11}
  1  2     9.57704155e-01   # F_{12}
  2  1     9.57704155e-01   # F_{21}
  2  2    -2.87754671e-01   # F_{22}
Block gauge Q= 1.16478050e+03  # SM gauge couplings
     1     3.62839382e-01   # g'(Q)MSSM DRbar
     2     6.40796362e-01   # g(Q)MSSM DRbar
     3     1.04507689e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.16478050e+03  
  3  3     8.45800849e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.16478050e+03  
  3  3     4.89469495e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.16478050e+03  
  3  3     4.27982912e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.16478050e+03 # Higgs mixing parameters
     1     9.09602664e+02    # mu(Q)MSSM DRbar
     2     3.91596199e+01    # tan beta(Q)MSSM DRbar
     3     2.43663958e+02    # higgs vev(Q)MSSM DRbar
     4     8.26566788e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.16478050e+03  # MSSM DRbar SUSY breaking parameters
     1     2.98760417e+02      # M_1(Q)
     2     5.50316849e+02      # M_2(Q)
     3     1.52737184e+03      # M_3(Q)
    21    -1.79446278e+05      # mH1^2(Q)
    22    -8.09970344e+05      # mH2^2(Q)
    31     6.03178278e+02      # meL(Q)
    32     6.03032606e+02      # mmuL(Q)
    33     5.56022335e+02      # mtauL(Q)
    34     4.66340535e+02      # meR(Q)
    35     4.65958815e+02      # mmuR(Q)
    36     3.26028830e+02      # mtauR(Q)
    41     1.43151694e+03      # mqL1(Q)
    42     1.43147648e+03      # mqL2(Q)
    43     1.24317382e+03      # mqL3(Q)
    44     1.37920885e+03      # muR(Q)
    45     1.37920374e+03      # mcR(Q)
    46     1.08720238e+03      # mtR(Q)
    47     1.37283117e+03      # mdR(Q)
    48     1.37275087e+03      # msR(Q)
    49     1.25718343e+03      # mbR(Q)
Block au Q= 1.16478050e+03  
  1  1    -1.88756440e+03      # Au(Q)MSSM DRbar
  2  2    -1.88752070e+03      # Ac(Q)MSSM DRbar
  3  3    -1.33467386e+03      # At(Q)MSSM DRbar
Block ad Q= 1.16478050e+03  
  1  1    -2.17630609e+03      # Ad(Q)MSSM DRbar
  2  2    -2.17619482e+03      # As(Q)MSSM DRbar
  3  3    -1.84323050e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.16478050e+03  
  1  1    -7.06310035e+02      # Ae(Q)MSSM DRbar
  2  2    -7.05970645e+02      # Amu(Q)MSSM DRbar
  3  3    -5.91870588e+02      # Atau(Q)MSSM DRbar
