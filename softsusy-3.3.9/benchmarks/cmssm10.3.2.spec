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
     1    3.50000000e+02   # m0
     2    5.25000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.92117645e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.57985613e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03950359e+01   # MW
        25     1.15298830e+02   # h0
        35     8.15773847e+02   # H0
        36     8.15463190e+02   # A0
        37     8.19751581e+02   # H+
   1000021     1.20846395e+03   # ~g
   1000022     2.16027860e+02   # ~neutralino(1)
   1000023     4.08481625e+02   # ~neutralino(2)
   1000024     4.08508435e+02   # ~chargino(1)
   1000025    -6.63267005e+02   # ~neutralino(3)
   1000035     6.76696792e+02   # ~neutralino(4)
   1000037     6.76978750e+02   # ~chargino(2)
   1000001     1.14868228e+03   # ~d_L
   1000002     1.14609585e+03   # ~u_L
   1000003     1.14867931e+03   # ~s_L
   1000004     1.14609286e+03   # ~c_L
   1000005     1.04385462e+03   # ~b_1
   1000006     8.66904651e+02   # ~t_1
   1000011     4.97827712e+02   # ~e_L
   1000012     4.91298714e+02   # ~nue_L
   1000013     4.97822144e+02   # ~mu_L
   1000014     4.91293104e+02   # ~numu_L
   1000015     3.96930794e+02   # ~stau_1
   1000016     4.89476152e+02   # ~nu_tau_L
   2000001     1.10428599e+03   # ~d_R
   2000002     1.10771822e+03   # ~u_R
   2000003     1.10428291e+03   # ~s_R
   2000004     1.10771502e+03   # ~c_R
   2000005     1.09953153e+03   # ~b_2
   2000006     1.08349872e+03   # ~t_2
   2000011     4.03403594e+02   # ~e_R
   2000013     4.03389742e+02   # ~mu_R
   2000015     4.97677928e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.06063702e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96135972e-01   # N_{1,1}
  1  2    -1.60433815e-02   # N_{1,2}
  1  3     7.96387511e-02   # N_{1,3}
  1  4    -3.33677153e-02   # N_{1,4}
  2  1     3.54804861e-02   # N_{2,1}
  2  2     9.71770243e-01   # N_{2,2}
  2  3    -1.93404435e-01   # N_{2,3}
  2  4     1.30378123e-01   # N_{2,4}
  3  1    -3.17968471e-02   # N_{3,1}
  3  2     4.62077328e-02   # N_{3,2}
  3  3     7.03763809e-01   # N_{3,3}
  3  4     7.08216285e-01   # N_{3,4}
  4  1    -7.37781866e-02   # N_{4,1}
  4  2     2.30803056e-01   # N_{4,2}
  4  3     6.78946901e-01   # N_{4,3}
  4  4    -6.93049662e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.60859506e-01   # U_{1,1}
  1  2    -2.77036117e-01   # U_{1,2}
  2  1     2.77036117e-01   # U_{2,1}
  2  2     9.60859506e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.82270085e-01   # V_{1,1}
  1  2    -1.87471277e-01   # V_{1,2}
  2  1     1.87471277e-01   # V_{2,1}
  2  2     9.82270085e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.89107758e-01   # F_{11}
  1  2     9.21192245e-01   # F_{12}
  2  1     9.21192245e-01   # F_{21}
  2  2    -3.89107758e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.88022048e-01   # F_{11}
  1  2     1.54312774e-01   # F_{12}
  2  1    -1.54312774e-01   # F_{21}
  2  2     9.88022048e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.34547403e-01   # F_{11}
  1  2     9.90907158e-01   # F_{12}
  2  1     9.90907158e-01   # F_{21}
  2  2    -1.34547403e-01   # F_{22}
Block gauge Q= 9.39845519e+02  # SM gauge couplings
     1     3.62388176e-01   # g'(Q)MSSM DRbar
     2     6.42474282e-01   # g(Q)MSSM DRbar
     3     1.05746412e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.39845519e+02  
  3  3     8.59241722e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.39845519e+02  
  3  3     1.35029966e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.39845519e+02  
  3  3     1.00371917e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.39845519e+02 # Higgs mixing parameters
     1     6.57540755e+02    # mu(Q)MSSM DRbar
     2     9.66452458e+00    # tan beta(Q)MSSM DRbar
     3     2.44011120e+02    # higgs vev(Q)MSSM DRbar
     4     6.87275450e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.39845519e+02  # MSSM DRbar SUSY breaking parameters
     1     2.20343593e+02      # M_1(Q)
     2     4.08443517e+02      # M_2(Q)
     3     1.16409255e+03      # M_3(Q)
    21     2.20897259e+05      # mH1^2(Q)
    22    -4.15901205e+05      # mH2^2(Q)
    31     4.92130365e+02      # meL(Q)
    32     4.92124745e+02      # mmuL(Q)
    33     4.90430369e+02      # mtauL(Q)
    34     3.98915631e+02      # meR(Q)
    35     3.98901627e+02      # mmuR(Q)
    36     3.94663099e+02      # mtauR(Q)
    41     1.11001881e+03      # mqL1(Q)
    42     1.11001577e+03      # mqL2(Q)
    43     1.01395819e+03      # mqL3(Q)
    44     1.07208767e+03      # muR(Q)
    45     1.07208441e+03      # mcR(Q)
    46     8.63039463e+02      # mtR(Q)
    47     1.06750515e+03      # mdR(Q)
    48     1.06750201e+03      # msR(Q)
    49     1.06172290e+03      # mbR(Q)
Block au Q= 9.39845519e+02  
  1  1    -1.18992612e+03      # Au(Q)MSSM DRbar
  2  2    -1.18992079e+03      # Ac(Q)MSSM DRbar
  3  3    -9.18657231e+02      # At(Q)MSSM DRbar
Block ad Q= 9.39845519e+02  
  1  1    -1.45511104e+03      # Ad(Q)MSSM DRbar
  2  2    -1.45510610e+03      # As(Q)MSSM DRbar
  3  3    -1.35986738e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.39845519e+02  
  1  1    -3.13507086e+02      # Ae(Q)MSSM DRbar
  2  2    -3.13501472e+02      # Amu(Q)MSSM DRbar
  3  3    -3.11810469e+02      # Atau(Q)MSSM DRbar
