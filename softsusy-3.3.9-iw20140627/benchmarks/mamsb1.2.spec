# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    3   # amsb
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
     1    3.75000000e+02   # m0
     2    5.00000000e+04   # m3/2
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.44371796e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.12009080e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03946733e+01   # MW
        25     1.14138882e+02   # h0
        35     8.96362584e+02   # H0
        36     8.96177832e+02   # A0
        37     9.00002951e+02   # H+
   1000021    -1.08704798e+03   # ~g
   1000022     1.64195819e+02   # ~neutralino(1)
   1000023     4.56142595e+02   # ~neutralino(2)
   1000024     1.64369431e+02   # ~chargino(1)
   1000025    -8.62660425e+02   # ~neutralino(3)
   1000035     8.69334637e+02   # ~neutralino(4)
   1000037     8.68131634e+02   # ~chargino(2)
   1000039     5.00000000e+04   # ~gravitino
   1000001     1.07982095e+03   # ~d_L
   1000002     1.07706746e+03   # ~u_L
   1000003     1.07981445e+03   # ~s_L
   1000004     1.07706093e+03   # ~c_L
   1000005     9.39009041e+02   # ~b_1
   1000006     7.80251474e+02   # ~t_1
   1000011     3.23425945e+02   # ~e_L
   1000012     3.13391162e+02   # ~nue_L
   1000013     3.23411810e+02   # ~mu_L
   1000014     3.13376633e+02   # ~numu_L
   1000015     2.87181277e+02   # ~stau_1
   1000016     3.08923321e+02   # ~nu_tau_L
   2000001     1.09077196e+03   # ~d_R
   2000002     1.08264423e+03   # ~u_R
   2000003     1.09076498e+03   # ~s_R
   2000004     1.08263827e+03   # ~c_R
   2000005     1.07629389e+03   # ~b_2
   2000006     9.78136110e+02   # ~t_2
   2000011     3.13332090e+02   # ~e_R
   2000013     3.13302902e+02   # ~mu_R
   2000015     3.34580633e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.06403494e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1    -5.33079944e-03   # N_{1,1}
  1  2     9.95024722e-01   # N_{1,2}
  1  3    -9.57811189e-02   # N_{1,3}
  1  4     2.68954017e-02   # N_{1,4}
  2  1     9.96224620e-01   # N_{2,1}
  2  2     1.36040915e-02   # N_{2,2}
  2  3     7.34686680e-02   # N_{2,3}
  2  4    -4.42017007e-02   # N_{2,4}
  3  1    -2.12455472e-02   # N_{3,1}
  3  2     4.86010372e-02   # N_{3,2}
  3  3     7.04737268e-01   # N_{3,3}
  3  4     7.07482826e-01   # N_{3,4}
  4  1    -8.40042625e-02   # N_{4,1}
  4  2     8.58991890e-02   # N_{4,2}
  4  3     6.99123533e-01   # N_{4,3}
  4  4    -7.04833951e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.90903930e-01   # U_{1,1}
  1  2    -1.34571176e-01   # U_{1,2}
  2  1     1.34571176e-01   # U_{2,1}
  2  2     9.90903930e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.99282995e-01   # V_{1,1}
  1  2    -3.78615292e-02   # V_{1,2}
  2  1     3.78615292e-02   # V_{2,1}
  2  2     9.99282995e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1    -4.03399895e-01   # F_{11}
  1  2     9.15023784e-01   # F_{12}
  2  1     9.15023784e-01   # F_{21}
  2  2     4.03399895e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.98278545e-01   # F_{11}
  1  2     5.86510504e-02   # F_{12}
  2  1    -5.86510504e-02   # F_{21}
  2  2     9.98278545e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     5.86352866e-01   # F_{11}
  1  2     8.10055749e-01   # F_{12}
  2  1     8.10055749e-01   # F_{21}
  2  2    -5.86352866e-01   # F_{22}
Block gauge Q= 8.41433931e+02  # SM gauge couplings
     1     3.62168686e-01   # g'(Q)MSSM DRbar
     2     6.44985548e-01   # g(Q)MSSM DRbar
     3     1.06272965e+00   # g3(Q)MSSM DRbar
Block yu Q= 8.41433931e+02  
  3  3     8.63492337e-01   # Yt(Q)MSSM DRbar
Block yd Q= 8.41433931e+02  
  3  3     1.49017858e-01   # Yb(Q)MSSM DRbar
Block ye Q= 8.41433931e+02  
  3  3     9.93543072e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 8.41433931e+02 # Higgs mixing parameters
     1     8.61465313e+02    # mu(Q)MSSM DRbar
     2     9.67927953e+00    # tan beta(Q)MSSM DRbar
     3     2.44436951e+02    # higgs vev(Q)MSSM DRbar
     4     8.03304615e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 8.41433931e+02  # MSSM DRbar SUSY breaking parameters
     1     4.65558580e+02      # M_1(Q)
     2     1.59472708e+02      # M_2(Q)
     3    -1.03437809e+03      # M_3(Q)
    21     4.93764055e+04      # mH1^2(Q)
    22    -7.27136830e+05      # mH2^2(Q)
    31     3.19021334e+02      # meL(Q)
    32     3.19007049e+02      # mmuL(Q)
    33     3.14812704e+02      # mtauL(Q)
    34     3.06006577e+02      # meR(Q)
    35     3.05976779e+02      # mmuR(Q)
    36     2.97157621e+02      # mtauR(Q)
    41     1.04655485e+03      # mqL1(Q)
    42     1.04654814e+03      # mqL2(Q)
    43     9.07849793e+02      # mqL3(Q)
    44     1.05268653e+03      # muR(Q)
    45     1.05268039e+03      # mcR(Q)
    46     7.69257215e+02      # mtR(Q)
    47     1.06023135e+03      # mdR(Q)
    48     1.06022412e+03      # msR(Q)
    49     1.04518971e+03      # mbR(Q)
Block au Q= 8.41433931e+02  
  1  1     1.62907551e+03      # Au(Q)MSSM DRbar
  2  2     1.62906180e+03      # Ac(Q)MSSM DRbar
  3  3     9.24487452e+02      # At(Q)MSSM DRbar
Block ad Q= 8.41433931e+02  
  1  1     2.30319609e+03      # Ad(Q)MSSM DRbar
  2  2     2.30318338e+03      # As(Q)MSSM DRbar
  3  3     2.05129225e+03      # Ab(Q)MSSM DRbar
Block ae Q= 8.41433931e+02  
  1  1     4.90564485e+02      # Ae(Q)MSSM DRbar
  2  2     4.90532742e+02      # Amu(Q)MSSM DRbar
  3  3     4.81170776e+02      # Atau(Q)MSSM DRbar
