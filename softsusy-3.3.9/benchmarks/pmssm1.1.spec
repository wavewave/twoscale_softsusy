# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    0   # nonUniversal
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
Block EXTPAR               # non-universal SUSY breaking parameters
     0    -1.00000000e+00  # Set MX=MSUSY
     1     3.00000000e+02  # M_1(MX)
     2     2.50000000e+03  # M_2(MX)
     3     3.60000000e+02  # M_3(MX)
     11    0.00000000e+00  # At(MX)
     12    0.00000000e+00  # Ab(MX)
     13    0.00000000e+00  # Atau(MX)
     23    2.50000000e+03  # mu(MX)
     26    2.50000000e+03  # mA(pole)
     31    2.50000000e+03  # meL(MX)
     32    2.50000000e+03  # mmuL(MX)
     33    2.50000000e+03  # mtauL(MX)
     34    2.50000000e+03  # meR(MX)
     35    2.50000000e+03  # mmuR(MX)
     36    2.50000000e+03  # mtauR(MX)
     41    3.60000000e+02  # mqL1(MX)
     42    3.60000000e+02  # mqL2(MX)
     43    2.50000000e+03  # mqL3(MX)
     44    3.60000000e+02  # muR(MX)
     45    3.60000000e+02  # mcR(MX)
     46    2.50000000e+03  # mtR(MX)
     47    3.60000000e+02  # mdR(MX)
     48    3.60000000e+02  # msR(MX)
     49    2.50000000e+03  # mbR(MX)
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.22584593e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04004437e+01   # MW
        25     1.15865172e+02   # h0
        35     2.50009779e+03   # H0
        36     2.49999194e+03   # A0
        37     2.50163867e+03   # H+
   1000021     4.35004506e+02   # ~g
   1000022     2.93970644e+02   # ~neutralino(1)
   1000023     2.43466932e+03   # ~neutralino(2)
   1000024     2.43484254e+03   # ~chargino(1)
   1000025    -2.50051828e+03   # ~neutralino(3)
   1000035     2.55434401e+03   # ~neutralino(4)
   1000037     2.55450202e+03   # ~chargino(2)
   1000001     4.61808567e+02   # ~d_L
   1000002     4.55513340e+02   # ~u_L
   1000003     4.61808567e+02   # ~s_L
   1000004     4.55513340e+02   # ~c_L
   1000005     2.51854339e+03   # ~b_1
   1000006     2.52237252e+03   # ~t_1
   1000011     2.51891179e+03   # ~e_L
   1000012     2.51737876e+03   # ~nue_L
   1000013     2.51891179e+03   # ~mu_L
   1000014     2.51737876e+03   # ~numu_L
   1000015     2.49914487e+03   # ~stau_1
   1000016     2.51715676e+03   # ~nu_tau_L
   2000001     4.01193728e+02   # ~d_R
   2000002     3.93069788e+02   # ~u_R
   2000003     4.01193728e+02   # ~s_R
   2000004     3.93069788e+02   # ~c_R
   2000005     2.54809848e+03   # ~b_2
   2000006     2.54911097e+03   # ~t_2
   2000011     2.50346179e+03   # ~e_R
   2000013     2.50346179e+03   # ~mu_R
   2000015     2.52259934e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.04669229e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.99827380e-01   # N_{1,1}
  1  2    -1.74734452e-04   # N_{1,2}
  1  3     1.81446625e-02   # N_{1,3}
  1  4    -3.99382882e-03   # N_{1,4}
  2  1     7.87622285e-03   # N_{2,1}
  2  2     8.72880906e-01   # N_{2,2}
  2  3    -3.51019683e-01   # N_{2,3}
  2  4     3.38824543e-01   # N_{2,4}
  3  1    -1.00022573e-02   # N_{3,1}
  3  2     9.86453581e-03   # N_{3,2}
  3  3     7.06905613e-01   # N_{3,3}
  3  4     7.07168367e-01   # N_{3,4}
  4  1    -1.35325511e-02   # N_{4,1}
  4  2     4.87833562e-01   # N_{4,2}
  4  3     6.13791827e-01   # N_{4,3}
  4  4    -6.20560133e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     7.38754369e-01   # U_{1,1}
  1  2    -6.73974764e-01   # U_{1,2}
  2  1     6.73974764e-01   # U_{2,1}
  2  2     7.38754369e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     7.51977430e-01   # V_{1,1}
  1  2    -6.59188854e-01   # V_{1,2}
  2  1     6.59188854e-01   # V_{2,1}
  2  2     7.51977430e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.23652577e-01   # F_{11}
  1  2     9.46175993e-01   # F_{12}
  2  1     9.46175993e-01   # F_{21}
  2  2    -3.23652577e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.98213290e-01   # F_{11}
  1  2     9.17292852e-01   # F_{12}
  2  1     9.17292852e-01   # F_{21}
  2  2    -3.98213290e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     4.02378374e-01   # F_{11}
  1  2     9.15473453e-01   # F_{12}
  2  1     9.15473453e-01   # F_{21}
  2  2    -4.02378374e-01   # F_{22}
Block gauge Q= 2.50358161e+03  # SM gauge couplings
     1     3.64901067e-01   # g'(Q)MSSM DRbar
     2     6.37826617e-01   # g(Q)MSSM DRbar
     3     1.05821999e+00   # g3(Q)MSSM DRbar
Block yu Q= 2.50358161e+03  
  3  3     8.24485803e-01   # Yt(Q)MSSM DRbar
Block yd Q= 2.50358161e+03  
  3  3     1.30494250e-01   # Yb(Q)MSSM DRbar
Block ye Q= 2.50358161e+03  
  3  3     9.97303434e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 2.50358161e+03 # Higgs mixing parameters
     1     2.50000000e+03    # mu(Q)MSSM DRbar
     2     9.55198428e+00    # tan beta(Q)MSSM DRbar
     3     2.43862381e+02    # higgs vev(Q)MSSM DRbar
     4     6.16677272e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 2.50358161e+03  # MSSM DRbar SUSY breaking parameters
     1     3.00000000e+02      # M_1(Q)
     2     2.50000000e+03      # M_2(Q)
     3     3.60000000e+02      # M_3(Q)
    21    -1.68923886e+05      # mH1^2(Q)
    22    -6.07439331e+06      # mH2^2(Q)
    31     2.50000000e+03      # meL(Q)
    32     2.50000000e+03      # mmuL(Q)
    33     2.50000000e+03      # mtauL(Q)
    34     2.50000000e+03      # meR(Q)
    35     2.50000000e+03      # mmuR(Q)
    36     2.50000000e+03      # mtauR(Q)
    41     3.59999999e+02      # mqL1(Q)
    42     3.59999999e+02      # mqL2(Q)
    43     2.50000000e+03      # mqL3(Q)
    44     3.59999999e+02      # muR(Q)
    45     3.59999999e+02      # mcR(Q)
    46     2.50000000e+03      # mtR(Q)
    47     3.59999999e+02      # mdR(Q)
    48     3.59999999e+02      # msR(Q)
    49     2.50000000e+03      # mbR(Q)
Block au Q= 2.50358161e+03  
  1  1     1.74114599e-06      # Au(Q)MSSM DRbar
  2  2     1.74114498e-06      # Ac(Q)MSSM DRbar
  3  3     2.20563225e-06      # At(Q)MSSM DRbar
Block ad Q= 2.50358161e+03  
  1  1     1.40268672e-06      # Ad(Q)MSSM DRbar
  2  2     1.40268136e-06      # As(Q)MSSM DRbar
  3  3     1.47320037e-06      # Ab(Q)MSSM DRbar
Block ae Q= 2.50358161e+03  
  1  1     0.00000000e+00      # Ae(Q)MSSM DRbar
  2  2     8.93936688e-09      # Amu(Q)MSSM DRbar
  3  3     8.78141136e-09      # Atau(Q)MSSM DRbar
