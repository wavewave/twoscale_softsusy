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
     1    7.50000000e+02   # m0
     2    3.50000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.31216008e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=8.47382090e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03987783e+01   # MW
        25     1.13057704e+02   # h0
        35     8.96427343e+02   # H0
        36     8.96374473e+02   # A0
        37     9.00038070e+02   # H+
   1000021     8.63752449e+02   # ~g
   1000022     1.41997318e+02   # ~neutralino(1)
   1000023     2.67295646e+02   # ~neutralino(2)
   1000024     2.67128246e+02   # ~chargino(1)
   1000025    -4.69573294e+02   # ~neutralino(3)
   1000035     4.86705313e+02   # ~neutralino(4)
   1000037     4.87085883e+02   # ~chargino(2)
   1000001     1.04977998e+03   # ~d_L
   1000002     1.04696067e+03   # ~u_L
   1000003     1.04977631e+03   # ~s_L
   1000004     1.04695699e+03   # ~c_L
   1000005     9.10481693e+02   # ~b_1
   1000006     7.24391314e+02   # ~t_1
   1000011     7.84050884e+02   # ~e_L
   1000012     7.79738834e+02   # ~nue_L
   1000013     7.84040019e+02   # ~mu_L
   1000014     7.79728002e+02   # ~numu_L
   1000015     7.53606533e+02   # ~stau_1
   1000016     7.76422192e+02   # ~nu_tau_L
   2000001     1.02993615e+03   # ~d_R
   2000002     1.03078650e+03   # ~u_R
   2000003     1.02993256e+03   # ~s_R
   2000004     1.03078255e+03   # ~c_R
   2000005     1.02305681e+03   # ~b_2
   2000006     9.40654980e+02   # ~t_2
   2000011     7.61569024e+02   # ~e_R
   2000013     7.61546743e+02   # ~mu_R
   2000015     7.81845893e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05405485e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.91945473e-01   # N_{1,1}
  1  2    -3.20299241e-02   # N_{1,2}
  1  3     1.13885676e-01   # N_{1,3}
  1  4    -4.52583285e-02   # N_{1,4}
  2  1     6.60393348e-02   # N_{2,1}
  2  2     9.54709558e-01   # N_{2,2}
  2  3    -2.44855365e-01   # N_{2,3}
  2  4     1.55609496e-01   # N_{2,4}
  3  1    -4.58692666e-02   # N_{3,1}
  3  2     6.71712137e-02   # N_{3,2}
  3  3     7.00264343e-01   # N_{3,3}
  3  4     7.09234720e-01   # N_{3,4}
  4  1    -9.78723464e-02   # N_{4,1}
  4  2     2.88082924e-01   # N_{4,2}
  4  3     6.60837161e-01   # N_{4,3}
  4  4    -6.86092909e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.35272128e-01   # U_{1,1}
  1  2    -3.53929438e-01   # U_{1,2}
  2  1     3.53929438e-01   # U_{2,1}
  2  2     9.35272128e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.74108823e-01   # V_{1,1}
  1  2    -2.26079635e-01   # V_{1,2}
  2  1     2.26079635e-01   # V_{2,1}
  2  2     9.74108823e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.08918949e-01   # F_{11}
  1  2     9.51088367e-01   # F_{12}
  2  1     9.51088367e-01   # F_{21}
  2  2    -3.08918949e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.98229798e-01   # F_{11}
  1  2     5.94749553e-02   # F_{12}
  2  1    -5.94749553e-02   # F_{21}
  2  2     9.98229798e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.99330090e-01   # F_{11}
  1  2     9.79932403e-01   # F_{12}
  2  1     9.79932403e-01   # F_{21}
  2  2    -1.99330090e-01   # F_{22}
Block gauge Q= 8.02092300e+02  # SM gauge couplings
     1     3.61745533e-01   # g'(Q)MSSM DRbar
     2     6.43484752e-01   # g(Q)MSSM DRbar
     3     1.06904005e+00   # g3(Q)MSSM DRbar
Block yu Q= 8.02092300e+02  
  3  3     8.69011341e-01   # Yt(Q)MSSM DRbar
Block yd Q= 8.02092300e+02  
  3  3     1.37635998e-01   # Yb(Q)MSSM DRbar
Block ye Q= 8.02092300e+02  
  3  3     9.97653208e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 8.02092300e+02 # Higgs mixing parameters
     1     4.61996183e+02    # mu(Q)MSSM DRbar
     2     9.68063925e+00    # tan beta(Q)MSSM DRbar
     3     2.44050682e+02    # higgs vev(Q)MSSM DRbar
     4     8.20640069e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 8.02092300e+02  # MSSM DRbar SUSY breaking parameters
     1     1.45252574e+02      # M_1(Q)
     2     2.70916262e+02      # M_2(Q)
     3     7.89951133e+02      # M_3(Q)
    21     5.83323822e+05      # mH1^2(Q)
    22    -1.98095969e+05      # mH2^2(Q)
    31     7.81417672e+02      # meL(Q)
    32     7.81406882e+02      # mmuL(Q)
    33     7.78205536e+02      # mtauL(Q)
    34     7.59369333e+02      # meR(Q)
    35     7.59347018e+02      # mmuR(Q)
    36     7.52709963e+02      # mtauR(Q)
    41     1.02501556e+03      # mqL1(Q)
    42     1.02501178e+03      # mqL2(Q)
    43     8.88829644e+02      # mqL3(Q)
    44     1.00893183e+03      # muR(Q)
    45     1.00892777e+03      # mcR(Q)
    46     7.09011814e+02      # mtR(Q)
    47     1.00708182e+03      # mdR(Q)
    48     1.00707813e+03      # msR(Q)
    49     9.99953409e+02      # mbR(Q)
Block au Q= 8.02092300e+02  
  1  1    -8.13408614e+02      # Au(Q)MSSM DRbar
  2  2    -8.13404945e+02      # Ac(Q)MSSM DRbar
  3  3    -6.24368796e+02      # At(Q)MSSM DRbar
Block ad Q= 8.02092300e+02  
  1  1    -9.98740026e+02      # Ad(Q)MSSM DRbar
  2  2    -9.98736621e+02      # As(Q)MSSM DRbar
  3  3    -9.32302496e+02      # Ab(Q)MSSM DRbar
Block ae Q= 8.02092300e+02  
  1  1    -2.11356059e+02      # Ae(Q)MSSM DRbar
  2  2    -2.11352217e+02      # Amu(Q)MSSM DRbar
  3  3    -2.10214431e+02      # Atau(Q)MSSM DRbar
