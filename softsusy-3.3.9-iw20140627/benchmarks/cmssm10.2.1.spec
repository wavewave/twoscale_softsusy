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
     1    2.00000000e+02   # m0
     2    5.00000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.90436448e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=6.91609594e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03961812e+01   # MW
        25     1.14918128e+02   # h0
        35     7.34344012e+02   # H0
        36     7.34054534e+02   # A0
        37     7.38710665e+02   # H+
   1000021     1.14926213e+03   # ~g
   1000022     2.04560011e+02   # ~neutralino(1)
   1000023     3.86568443e+02   # ~neutralino(2)
   1000024     3.86580810e+02   # ~chargino(1)
   1000025    -6.35556949e+02   # ~neutralino(3)
   1000035     6.49237039e+02   # ~neutralino(4)
   1000037     6.49558273e+02   # ~chargino(2)
   1000001     1.06658702e+03   # ~d_L
   1000002     1.06378132e+03   # ~u_L
   1000003     1.06658438e+03   # ~s_L
   1000004     1.06377867e+03   # ~c_L
   1000005     9.74449331e+02   # ~b_1
   1000006     8.10437676e+02   # ~t_1
   1000011     3.93674544e+02   # ~e_L
   1000012     3.85495248e+02   # ~nue_L
   1000013     3.93670673e+02   # ~mu_L
   1000014     3.85491311e+02   # ~numu_L
   1000015     2.70926618e+02   # ~stau_1
   1000016     3.84159625e+02   # ~nu_tau_L
   2000001     1.02261638e+03   # ~d_R
   2000002     1.02590029e+03   # ~u_R
   2000003     1.02261362e+03   # ~s_R
   2000004     1.02589746e+03   # ~c_R
   2000005     1.01898783e+03   # ~b_2
   2000006     1.01866462e+03   # ~t_2
   2000011     2.77580058e+02   # ~e_R
   2000013     2.77568946e+02   # ~mu_R
   2000015     3.94459162e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.06644142e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.95798943e-01   # N_{1,1}
  1  2    -1.74987627e-02   # N_{1,2}
  1  3     8.29972354e-02   # N_{1,3}
  1  4    -3.44922745e-02   # N_{1,4}
  2  1     3.81874608e-02   # N_{2,1}
  2  2     9.70342262e-01   # N_{2,2}
  2  3    -1.98486588e-01   # N_{2,3}
  2  4     1.32592183e-01   # N_{2,4}
  3  1    -3.32446036e-02   # N_{3,1}
  3  2     4.84110343e-02   # N_{3,2}
  3  3     7.03441840e-01   # N_{3,3}
  3  4     7.08322487e-01   # N_{3,4}
  4  1    -7.62953403e-02   # N_{4,1}
  4  2     2.36190728e-01   # N_{4,2}
  4  3     6.77409855e-01   # N_{4,3}
  4  4    -6.92465775e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.58755322e-01   # U_{1,1}
  1  2    -2.84232707e-01   # U_{1,2}
  2  1     2.84232707e-01   # U_{2,1}
  2  2     9.58755322e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.81681045e-01   # V_{1,1}
  1  2    -1.90531691e-01   # V_{1,2}
  2  1     1.90531691e-01   # V_{2,1}
  2  2     9.81681045e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.19845189e-01   # F_{11}
  1  2     9.07595735e-01   # F_{12}
  2  1     9.07595735e-01   # F_{21}
  2  2    -4.19845189e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.79703928e-01   # F_{11}
  1  2     2.00450029e-01   # F_{12}
  2  1    -2.00450029e-01   # F_{21}
  2  2     9.79703928e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.41744763e-01   # F_{11}
  1  2     9.89903239e-01   # F_{12}
  2  1     9.89903239e-01   # F_{21}
  2  2    -1.41744763e-01   # F_{22}
Block gauge Q= 8.80961485e+02  # SM gauge couplings
     1     3.62367712e-01   # g'(Q)MSSM DRbar
     2     6.42915589e-01   # g(Q)MSSM DRbar
     3     1.06063788e+00   # g3(Q)MSSM DRbar
Block yu Q= 8.80961485e+02  
  3  3     8.61079303e-01   # Yt(Q)MSSM DRbar
Block yd Q= 8.80961485e+02  
  3  3     1.35327506e-01   # Yb(Q)MSSM DRbar
Block ye Q= 8.80961485e+02  
  3  3     1.00504610e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 8.80961485e+02 # Higgs mixing parameters
     1     6.30002145e+02    # mu(Q)MSSM DRbar
     2     9.67255682e+00    # tan beta(Q)MSSM DRbar
     3     2.44102883e+02    # higgs vev(Q)MSSM DRbar
     4     5.58452533e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 8.80961485e+02  # MSSM DRbar SUSY breaking parameters
     1     2.09313876e+02      # M_1(Q)
     2     3.88521132e+02      # M_2(Q)
     3     1.11326213e+03      # M_3(Q)
    21     1.32421915e+05      # mH1^2(Q)
    22    -3.83913722e+05      # mH2^2(Q)
    31     3.86766802e+02      # meL(Q)
    32     3.86762866e+02      # mmuL(Q)
    33     3.85575765e+02      # mtauL(Q)
    34     2.71213473e+02      # meR(Q)
    35     2.71202091e+02      # mmuR(Q)
    36     2.67751434e+02      # mtauR(Q)
    41     1.02951507e+03      # mqL1(Q)
    42     1.02951237e+03      # mqL2(Q)
    43     9.46561381e+02      # mqL3(Q)
    44     9.92026007e+02      # muR(Q)
    45     9.92023130e+02      # mcR(Q)
    46     8.11739863e+02      # mtR(Q)
    47     9.87495751e+02      # mdR(Q)
    48     9.87492939e+02      # msR(Q)
    49     9.82346990e+02      # mbR(Q)
Block au Q= 8.80961485e+02  
  1  1    -1.14046730e+03      # Au(Q)MSSM DRbar
  2  2    -1.14046218e+03      # Ac(Q)MSSM DRbar
  3  3    -8.79883062e+02      # At(Q)MSSM DRbar
Block ad Q= 8.80961485e+02  
  1  1    -1.39538692e+03      # Ad(Q)MSSM DRbar
  2  2    -1.39538217e+03      # As(Q)MSSM DRbar
  3  3    -1.30389361e+03      # Ab(Q)MSSM DRbar
Block ae Q= 8.80961485e+02  
  1  1    -2.99346731e+02      # Ae(Q)MSSM DRbar
  2  2    -2.99341353e+02      # Amu(Q)MSSM DRbar
  3  3    -2.97719924e+02      # Atau(Q)MSSM DRbar
