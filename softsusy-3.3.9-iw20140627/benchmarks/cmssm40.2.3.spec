# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
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
     1    6.00000000e+02   # m0
     2    5.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.88704267e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.86817411e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03897995e+01   # MW
        25     1.17595713e+02   # h0
        35     7.31019466e+02   # H0
        36     7.31025444e+02   # A0
        37     7.35790932e+02   # H+
   1000021     1.27464321e+03   # ~g
   1000022     2.29843476e+02   # ~neutralino(1)
   1000023     4.38018923e+02   # ~neutralino(2)
   1000024     4.38150449e+02   # ~chargino(1)
   1000025    -7.50577739e+02   # ~neutralino(3)
   1000035     7.58905632e+02   # ~neutralino(4)
   1000037     7.59941495e+02   # ~chargino(2)
   1000001     1.28682554e+03   # ~d_L
   1000002     1.28451651e+03   # ~u_L
   1000003     1.28678720e+03   # ~s_L
   1000004     1.28447808e+03   # ~c_L
   1000005     1.06783453e+03   # ~b_1
   1000006     9.07725540e+02   # ~t_1
   1000011     7.03599292e+02   # ~e_L
   1000012     6.98786593e+02   # ~nue_L
   1000013     7.03419833e+02   # ~mu_L
   1000014     6.98607231e+02   # ~numu_L
   1000015     4.72303518e+02   # ~stau_1
   1000016     6.37453051e+02   # ~nu_tau_L
   2000001     1.24462198e+03   # ~d_R
   2000002     1.24793468e+03   # ~u_R
   2000003     1.24454621e+03   # ~s_R
   2000004     1.24792978e+03   # ~c_R
   2000005     1.14078610e+03   # ~b_2
   2000006     1.12642243e+03   # ~t_2
   2000011     6.35100603e+02   # ~e_R
   2000013     6.34701915e+02   # ~mu_R
   2000015     6.55540159e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.59913743e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97437122e-01   # N_{1,1}
  1  2    -8.97951682e-03   # N_{1,2}
  1  3     6.73132978e-02   # N_{1,3}
  1  4    -2.25272356e-02   # N_{1,4}
  2  1     2.15746087e-02   # N_{2,1}
  2  2     9.82862114e-01   # N_{2,2}
  2  3    -1.57140024e-01   # N_{2,3}
  2  4     9.39340934e-02   # N_{2,4}
  3  1    -3.11261939e-02   # N_{3,1}
  3  2     4.56199551e-02   # N_{3,2}
  3  3     7.04199524e-01   # N_{3,3}
  3  4     7.07850980e-01   # N_{3,4}
  4  1    -6.07032490e-02   # N_{4,1}
  4  2     1.78382322e-01   # N_{4,2}
  4  3     6.89114623e-01   # N_{4,3}
  4  4    -6.99725589e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.74610110e-01   # U_{1,1}
  1  2    -2.23908763e-01   # U_{1,2}
  2  1     2.23908763e-01   # U_{2,1}
  2  2     9.74610110e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.90932020e-01   # V_{1,1}
  1  2    -1.34364174e-01   # V_{1,2}
  2  1     1.34364174e-01   # V_{2,1}
  2  2     9.90932020e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.16090722e-01   # F_{11}
  1  2     9.09323106e-01   # F_{12}
  2  1     9.09323106e-01   # F_{21}
  2  2    -4.16090722e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     8.88642039e-01   # F_{11}
  1  2     4.58601490e-01   # F_{12}
  2  1    -4.58601490e-01   # F_{21}
  2  2     8.88642039e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     2.82879738e-01   # F_{11}
  1  2     9.59155386e-01   # F_{12}
  2  1     9.59155386e-01   # F_{21}
  2  2    -2.82879738e-01   # F_{22}
Block gauge Q= 9.81985398e+02  # SM gauge couplings
     1     3.62276455e-01   # g'(Q)MSSM DRbar
     2     6.41583980e-01   # g(Q)MSSM DRbar
     3     1.05451478e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.81985398e+02  
  3  3     8.52295841e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.81985398e+02  
  3  3     4.95397938e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.81985398e+02  
  3  3     4.24552003e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.81985398e+02 # Higgs mixing parameters
     1     7.46393277e+02    # mu(Q)MSSM DRbar
     2     3.92051622e+01    # tan beta(Q)MSSM DRbar
     3     2.43879110e+02    # higgs vev(Q)MSSM DRbar
     4     6.83734244e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.81985398e+02  # MSSM DRbar SUSY breaking parameters
     1     2.32721305e+02      # M_1(Q)
     2     4.30923110e+02      # M_2(Q)
     3     1.21817756e+03      # M_3(Q)
    21    -1.33709199e+04      # mH1^2(Q)
    22    -5.46547287e+05      # mH2^2(Q)
    31     6.99420159e+02      # meL(Q)
    32     6.99240820e+02      # mmuL(Q)
    33     6.40421647e+02      # mtauL(Q)
    34     6.32007153e+02      # meR(Q)
    35     6.31606905e+02      # mmuR(Q)
    36     4.89458646e+02      # mtauR(Q)
    41     1.24910241e+03      # mqL1(Q)
    42     1.24906277e+03      # mqL2(Q)
    43     1.05428765e+03      # mqL3(Q)
    44     1.21280743e+03      # muR(Q)
    45     1.21280240e+03      # mcR(Q)
    46     9.08903107e+02      # mtR(Q)
    47     1.20847781e+03      # mdR(Q)
    48     1.20839998e+03      # msR(Q)
    49     1.09287194e+03      # mbR(Q)
Block au Q= 9.81985398e+02  
  1  1    -1.58110852e+03      # Au(Q)MSSM DRbar
  2  2    -1.58107041e+03      # Ac(Q)MSSM DRbar
  3  3    -1.09681785e+03      # At(Q)MSSM DRbar
Block ad Q= 9.81985398e+02  
  1  1    -1.83179020e+03      # Ad(Q)MSSM DRbar
  2  2    -1.83169314e+03      # As(Q)MSSM DRbar
  3  3    -1.53899671e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.81985398e+02  
  1  1    -6.43164683e+02      # Ae(Q)MSSM DRbar
  2  2    -6.42844780e+02      # Amu(Q)MSSM DRbar
  3  3    -5.37278948e+02      # Atau(Q)MSSM DRbar
