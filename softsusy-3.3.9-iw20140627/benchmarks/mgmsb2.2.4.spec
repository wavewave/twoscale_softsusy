# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    2   # gmsb
Block SMINPUTS             # Standard Model inputs
     1    1.27934000e+02   # alpha_em^(-1)(MZ) SM MSbar
     2    1.16637000e-05   # G_Fermi
     3    1.17200000e-01   # alpha_s(MZ)MSbar
     4    9.11876000e+01   # MZ(pole)
     5    4.25000000e+00   # mb(mb)
     6    1.73300000e+02   # Mtop(pole)
     7    1.77700000e+00   # Mtau(pole)
Block MINPAR               # SUSY breaking input parameters
     3    1.50000000e+01   # tanb
     4    1.00000000e+00   # sign(mu)
     1    1.50000000e+05   # lambda
     2    1.00000000e+14   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.27167195e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03963038e+01   # MW
        25     1.15376757e+02   # h0
        35     9.95991956e+02   # H0
        36     9.95946967e+02   # A0
        37     9.99387749e+02   # H+
   1000021     1.12760637e+03   # ~g
   1000022     2.00228073e+02   # ~neutralino(1)
   1000023     3.85868610e+02   # ~neutralino(2)
   1000024     3.85994302e+02   # ~chargino(1)
   1000025    -7.85245682e+02   # ~neutralino(3)
   1000035     7.92419427e+02   # ~neutralino(4)
   1000037     7.93233319e+02   # ~chargino(2)
   1000039     3.55500000e+00   # ~gravitino
   1000001     1.38334507e+03   # ~d_L
   1000002     1.38122025e+03   # ~u_L
   1000003     1.38333958e+03   # ~s_L
   1000004     1.38121476e+03   # ~c_L
   1000005     1.22296672e+03   # ~b_1
   1000006     9.72562022e+02   # ~t_1
   1000011     6.66690747e+02   # ~e_L
   1000012     6.61648213e+02   # ~nue_L
   1000013     6.66676558e+02   # ~mu_L
   1000014     6.61634013e+02   # ~numu_L
   1000015     4.37465630e+02   # ~stau_1
   1000016     6.57004183e+02   # ~nu_tau_L
   2000001     1.24421149e+03   # ~d_R
   2000002     1.26945729e+03   # ~u_R
   2000003     1.24420334e+03   # ~s_R
   2000004     1.26945327e+03   # ~c_R
   2000005     1.25298378e+03   # ~b_2
   2000006     1.26541796e+03   # ~t_2
   2000011     4.52937179e+02   # ~e_R
   2000013     4.52895372e+02   # ~mu_R
   2000015     6.63425257e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.01806692e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97757192e-01   # N_{1,1}
  1  2    -1.00961062e-02   # N_{1,2}
  1  3     6.29910750e-02   # N_{1,3}
  1  4    -2.02676922e-02   # N_{1,4}
  2  1     1.98803927e-02   # N_{2,1}
  2  2     9.88256489e-01   # N_{2,2}
  2  3    -1.33384132e-01   # N_{2,3}
  2  4     7.18509261e-02   # N_{2,4}
  3  1    -2.96458477e-02   # N_{3,1}
  3  2     4.42087575e-02   # N_{3,2}
  3  3     7.04404167e-01   # N_{3,3}
  3  4     7.07800452e-01   # N_{3,4}
  4  1    -5.66257886e-02   # N_{4,1}
  4  2     1.45920412e-01   # N_{4,2}
  4  3     6.94302216e-01   # N_{4,3}
  4  4    -7.02456537e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.81797104e-01   # U_{1,1}
  1  2    -1.89932742e-01   # U_{1,2}
  2  1     1.89932742e-01   # U_{2,1}
  2  2     9.81797104e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.94711433e-01   # V_{1,1}
  1  2    -1.02709126e-01   # V_{1,2}
  2  1     1.02709126e-01   # V_{2,1}
  2  2     9.94711433e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     1.98694379e-01   # F_{11}
  1  2     9.80061500e-01   # F_{12}
  2  1     9.80061500e-01   # F_{21}
  2  2    -1.98694379e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.33850009e-01   # F_{11}
  1  2     9.00985111e-01   # F_{12}
  2  1     9.00985111e-01   # F_{21}
  2  2    -4.33850009e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     8.40930420e-02   # F_{11}
  1  2     9.96457907e-01   # F_{12}
  2  1     9.96457907e-01   # F_{21}
  2  2    -8.40930420e-02   # F_{22}
Block gauge Q= 1.07751830e+03  # SM gauge couplings
     1     3.62679619e-01   # g'(Q)MSSM DRbar
     2     6.42046518e-01   # g(Q)MSSM DRbar
     3     1.05440286e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.07751830e+03  
  3  3     8.56066932e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.07751830e+03  
  3  3     1.97557680e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.07751830e+03  
  3  3     1.50746909e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.07751830e+03 # Higgs mixing parameters
     1     7.78954643e+02    # mu(Q)MSSM DRbar
     2     1.44899390e+01    # tan beta(Q)MSSM DRbar
     3     2.43886468e+02    # higgs vev(Q)MSSM DRbar
     4     1.03559355e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.07751830e+03  # MSSM DRbar SUSY breaking parameters
     1     2.03515827e+02      # M_1(Q)
     2     3.77151041e+02      # M_2(Q)
     3     1.03575570e+03      # M_3(Q)
    21     3.75820916e+05      # mH1^2(Q)
    22    -5.86942231e+05      # mH2^2(Q)
    31     6.63046248e+02      # meL(Q)
    32     6.63032074e+02      # mmuL(Q)
    33     6.58708788e+02      # mtauL(Q)
    34     4.47997552e+02      # meR(Q)
    35     4.47955312e+02      # mmuR(Q)
    36     4.34919997e+02      # mtauR(Q)
    41     1.35162976e+03      # mqL1(Q)
    42     1.35162412e+03      # mqL2(Q)
    43     1.22017930e+03      # mqL3(Q)
    44     1.23816843e+03      # muR(Q)
    45     1.23816427e+03      # mcR(Q)
    46     9.39831573e+02      # mtR(Q)
    47     1.21078540e+03      # mdR(Q)
    48     1.21077694e+03      # msR(Q)
    49     1.19534878e+03      # mbR(Q)
Block au Q= 1.07751830e+03  
  1  1    -9.62128978e+02      # Au(Q)MSSM DRbar
  2  2    -9.62124136e+02      # Ac(Q)MSSM DRbar
  3  3    -7.65578422e+02      # At(Q)MSSM DRbar
Block ad Q= 1.07751830e+03  
  1  1    -1.14931646e+03      # Ad(Q)MSSM DRbar
  2  2    -1.14930977e+03      # As(Q)MSSM DRbar
  3  3    -1.07532186e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.07751830e+03  
  1  1    -2.13502864e+02      # Ae(Q)MSSM DRbar
  2  2    -2.13495539e+02      # Amu(Q)MSSM DRbar
  3  3    -2.11267670e+02      # Atau(Q)MSSM DRbar
