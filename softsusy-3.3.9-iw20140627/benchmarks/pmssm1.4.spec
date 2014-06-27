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
     1     6.00000000e+02  # M_1(MX)
     2     2.50000000e+03  # M_2(MX)
     3     7.20000000e+02  # M_3(MX)
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
     41    7.20000000e+02  # mqL1(MX)
     42    7.20000000e+02  # mqL2(MX)
     43    2.50000000e+03  # mqL3(MX)
     44    7.20000000e+02  # muR(MX)
     45    7.20000000e+02  # mcR(MX)
     46    2.50000000e+03  # mtR(MX)
     47    7.20000000e+02  # mdR(MX)
     48    7.20000000e+02  # msR(MX)
     49    2.50000000e+03  # mbR(MX)
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.58979821e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04031906e+01   # MW
        25     1.16643080e+02   # h0
        35     2.50009764e+03   # H0
        36     2.49999186e+03   # A0
        37     2.50164814e+03   # H+
   1000021     8.30992052e+02   # ~g
   1000022     5.91053523e+02   # ~neutralino(1)
   1000023     2.43221517e+03   # ~neutralino(2)
   1000024     2.43234465e+03   # ~chargino(1)
   1000025    -2.50022602e+03   # ~neutralino(3)
   1000035     2.55216011e+03   # ~neutralino(4)
   1000037     2.55226486e+03   # ~chargino(2)
   1000001     8.15373782e+02   # ~d_L
   1000002     8.11839628e+02   # ~u_L
   1000003     8.15373782e+02   # ~s_L
   1000004     8.11839628e+02   # ~c_L
   1000005     2.52140508e+03   # ~b_1
   1000006     2.52454257e+03   # ~t_1
   1000011     2.51893165e+03   # ~e_L
   1000012     2.51739011e+03   # ~nue_L
   1000013     2.51893165e+03   # ~mu_L
   1000014     2.51739011e+03   # ~numu_L
   1000015     2.49932706e+03   # ~stau_1
   1000016     2.51716829e+03   # ~nu_tau_L
   2000001     7.78980611e+02   # ~d_R
   2000002     7.75653605e+02   # ~u_R
   2000003     7.78980611e+02   # ~s_R
   2000004     7.75653605e+02   # ~c_R
   2000005     2.55056286e+03   # ~b_2
   2000006     2.55234943e+03   # ~t_2
   2000011     2.50366747e+03   # ~e_R
   2000013     2.50366747e+03   # ~mu_R
   2000015     2.52264343e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.04712884e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.99794648e-01   # N_{1,1}
  1  2    -3.29664849e-04   # N_{1,2}
  1  3     1.92211592e-02   # N_{1,3}
  1  4    -6.41092312e-03   # N_{1,4}
  2  1     1.06103409e-02   # N_{2,1}
  2  2     8.24133129e-01   # N_{2,2}
  2  3    -4.06137880e-01   # N_{2,3}
  2  4     3.94644180e-01   # N_{2,4}
  3  1    -9.05274736e-03   # N_{3,1}
  3  2     9.85380750e-03   # N_{3,2}
  3  3     7.06916401e-01   # N_{3,3}
  3  4     7.07170525e-01   # N_{3,4}
  4  1    -1.47013607e-02   # N_{4,1}
  4  2     5.66310321e-01   # N_{4,2}
  4  3     5.78750180e-01   # N_{4,3}
  4  4    -5.86621445e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     7.50559269e-01   # U_{1,1}
  1  2    -6.60803135e-01   # U_{1,2}
  2  1     6.60803135e-01   # U_{2,1}
  2  2     7.50559269e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     7.63504189e-01   # V_{1,1}
  1  2    -6.45802875e-01   # V_{1,2}
  2  1     6.45802875e-01   # V_{2,1}
  2  2     7.63504189e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.54781933e-01   # F_{11}
  1  2     9.34949079e-01   # F_{12}
  2  1     9.34949079e-01   # F_{21}
  2  2    -3.54781933e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.97361521e-01   # F_{11}
  1  2     9.17662150e-01   # F_{12}
  2  1     9.17662150e-01   # F_{21}
  2  2    -3.97361521e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     4.04950152e-01   # F_{11}
  1  2     9.14338763e-01   # F_{12}
  2  1     9.14338763e-01   # F_{21}
  2  2    -4.04950152e-01   # F_{22}
Block gauge Q= 2.50363676e+03  # SM gauge couplings
     1     3.64601821e-01   # g'(Q)MSSM DRbar
     2     6.37162670e-01   # g(Q)MSSM DRbar
     3     1.04226809e+00   # g3(Q)MSSM DRbar
Block yu Q= 2.50363676e+03  
  3  3     8.30390847e-01   # Yt(Q)MSSM DRbar
Block yd Q= 2.50363676e+03  
  3  3     1.28731189e-01   # Yb(Q)MSSM DRbar
Block ye Q= 2.50363676e+03  
  3  3     9.96863765e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 2.50363676e+03 # Higgs mixing parameters
     1     2.50000000e+03    # mu(Q)MSSM DRbar
     2     9.54808968e+00    # tan beta(Q)MSSM DRbar
     3     2.43773080e+02    # higgs vev(Q)MSSM DRbar
     4     6.16433068e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 2.50363676e+03  # MSSM DRbar SUSY breaking parameters
     1     6.00000000e+02      # M_1(Q)
     2     2.50000000e+03      # M_2(Q)
     3     7.20000000e+02      # M_3(Q)
    21    -1.69162421e+05      # mH1^2(Q)
    22    -6.07189293e+06      # mH2^2(Q)
    31     2.50000000e+03      # meL(Q)
    32     2.50000000e+03      # mmuL(Q)
    33     2.50000000e+03      # mtauL(Q)
    34     2.50000000e+03      # meR(Q)
    35     2.50000000e+03      # mmuR(Q)
    36     2.50000000e+03      # mtauR(Q)
    41     7.19999998e+02      # mqL1(Q)
    42     7.19999998e+02      # mqL2(Q)
    43     2.50000000e+03      # mqL3(Q)
    44     7.19999998e+02      # muR(Q)
    45     7.19999998e+02      # mcR(Q)
    46     2.50000000e+03      # mtR(Q)
    47     7.19999998e+02      # mdR(Q)
    48     7.19999998e+02      # msR(Q)
    49     2.50000000e+03      # mbR(Q)
Block au Q= 2.50363676e+03  
  1  1     2.62271975e-06      # Au(Q)MSSM DRbar
  2  2     2.62273447e-06      # Ac(Q)MSSM DRbar
  3  3     3.86222609e-06      # At(Q)MSSM DRbar
Block ad Q= 2.50363676e+03  
  1  1     1.48633973e-06      # Ad(Q)MSSM DRbar
  2  2     1.48635187e-06      # As(Q)MSSM DRbar
  3  3     1.83681704e-06      # Ab(Q)MSSM DRbar
Block ae Q= 2.50363676e+03  
  1  1     0.00000000e+00      # Ae(Q)MSSM DRbar
  2  2     3.46345113e-08      # Amu(Q)MSSM DRbar
  3  3     3.45580609e-08      # Atau(Q)MSSM DRbar
