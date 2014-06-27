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
     3    1.00000000e+01   # tanb
     4    1.00000000e+00   # sign(mu)
     1    2.75000000e+02   # m0
     2    6.50000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.75165627e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.44823724e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03935564e+01   # MW
        25     1.16617574e+02   # h0
        35     9.38838575e+02   # H0
        36     9.38616619e+02   # A0
        37     9.42287253e+02   # H+
   1000021     1.46434854e+03   # ~g
   1000022     2.70023779e+02   # ~neutralino(1)
   1000023     5.10928674e+02   # ~neutralino(2)
   1000024     5.11007917e+02   # ~chargino(1)
   1000025    -7.99937674e+02   # ~neutralino(3)
   1000035     8.11872170e+02   # ~neutralino(4)
   1000037     8.12085027e+02   # ~chargino(2)
   1000001     1.35934480e+03   # ~d_L
   1000002     1.35717948e+03   # ~u_L
   1000003     1.35934145e+03   # ~s_L
   1000004     1.35717612e+03   # ~c_L
   1000005     1.24287117e+03   # ~b_1
   1000006     1.04343840e+03   # ~t_1
   1000011     5.16397254e+02   # ~e_L
   1000012     5.10125288e+02   # ~nue_L
   1000013     5.16392155e+02   # ~mu_L
   1000014     5.10120152e+02   # ~numu_L
   1000015     3.62826929e+02   # ~stau_1
   1000016     5.08384223e+02   # ~nu_tau_L
   2000001     1.30193773e+03   # ~d_R
   2000002     1.30684069e+03   # ~u_R
   2000003     1.30193425e+03   # ~s_R
   2000004     1.30683708e+03   # ~c_R
   2000005     1.29649904e+03   # ~b_2
   2000006     1.27877714e+03   # ~t_2
   2000011     3.69700307e+02   # ~e_R
   2000013     3.69685918e+02   # ~mu_R
   2000015     5.16211125e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05586764e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97351445e-01   # N_{1,1}
  1  2    -1.10231902e-02   # N_{1,2}
  1  3     6.60488191e-02   # N_{1,3}
  1  4    -2.83925663e-02   # N_{1,4}
  2  1     2.53837588e-02   # N_{2,1}
  2  2     9.78161787e-01   # N_{2,2}
  2  3    -1.69516219e-01   # N_{2,3}
  2  4     1.17556089e-01   # N_{2,4}
  3  1    -2.61092740e-02   # N_{3,1}
  3  2     3.77565496e-02   # N_{3,2}
  3  3     7.04850439e-01   # N_{3,3}
  3  4     7.07869061e-01   # N_{3,4}
  4  1    -6.29608263e-02   # N_{4,1}
  4  2     2.04089318e-01   # N_{4,2}
  4  3     6.85629393e-01   # N_{4,3}
  4  4    -6.95913658e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.70260255e-01   # U_{1,1}
  1  2    -2.42064119e-01   # U_{1,2}
  2  1     2.42064119e-01   # U_{2,1}
  2  2     9.70260255e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.85720793e-01   # V_{1,1}
  1  2    -1.68387997e-01   # V_{1,2}
  2  1     1.68387997e-01   # V_{2,1}
  2  2     9.85720793e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.57321598e-01   # F_{11}
  1  2     9.33981411e-01   # F_{12}
  2  1     9.33981411e-01   # F_{21}
  2  2    -3.57321598e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.86875142e-01   # F_{11}
  1  2     1.61485149e-01   # F_{12}
  2  1    -1.61485149e-01   # F_{21}
  2  2     9.86875142e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.08385068e-01   # F_{11}
  1  2     9.94108987e-01   # F_{12}
  2  1     9.94108987e-01   # F_{21}
  2  2    -1.08385068e-01   # F_{22}
Block gauge Q= 1.12132656e+03  # SM gauge couplings
     1     3.62861325e-01   # g'(Q)MSSM DRbar
     2     6.41583007e-01   # g(Q)MSSM DRbar
     3     1.04797489e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.12132656e+03  
  3  3     8.52832113e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.12132656e+03  
  3  3     1.33666915e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.12132656e+03  
  3  3     1.00329685e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.12132656e+03 # Higgs mixing parameters
     1     7.94371187e+02    # mu(Q)MSSM DRbar
     2     9.64406370e+00    # tan beta(Q)MSSM DRbar
     3     2.43819877e+02    # higgs vev(Q)MSSM DRbar
     4     9.11703546e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.12132656e+03  # MSSM DRbar SUSY breaking parameters
     1     2.75277426e+02      # M_1(Q)
     2     5.07759777e+02      # M_2(Q)
     3     1.42089825e+03      # M_3(Q)
    21     2.31172278e+05      # mH1^2(Q)
    22    -6.06096691e+05      # mH2^2(Q)
    31     5.08677078e+02      # meL(Q)
    32     5.08671916e+02      # mmuL(Q)
    33     5.07110123e+02      # mtauL(Q)
    34     3.63435948e+02      # meR(Q)
    35     3.63421299e+02      # mmuR(Q)
    36     3.58968622e+02      # mtauR(Q)
    41     1.31370186e+03      # mqL1(Q)
    42     1.31369844e+03      # mqL2(Q)
    43     1.20807421e+03      # mqL3(Q)
    44     1.26444270e+03      # muR(Q)
    45     1.26443904e+03      # mcR(Q)
    46     1.03454090e+03      # mtR(Q)
    47     1.25841508e+03      # mdR(Q)
    48     1.25841153e+03      # msR(Q)
    49     1.25194138e+03      # mbR(Q)
Block au Q= 1.12132656e+03  
  1  1    -1.44229769e+03      # Au(Q)MSSM DRbar
  2  2    -1.44229129e+03      # Ac(Q)MSSM DRbar
  3  3    -1.11720348e+03      # At(Q)MSSM DRbar
Block ad Q= 1.12132656e+03  
  1  1    -1.75936323e+03      # Ad(Q)MSSM DRbar
  2  2    -1.75935731e+03      # As(Q)MSSM DRbar
  3  3    -1.64526123e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.12132656e+03  
  1  1    -3.84560743e+02      # Ae(Q)MSSM DRbar
  2  2    -3.84553942e+02      # Amu(Q)MSSM DRbar
  3  3    -3.82497654e+02      # Atau(Q)MSSM DRbar
