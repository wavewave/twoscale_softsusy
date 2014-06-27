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
     1    1.20000000e+05   # lambda
     2    1.00000000e+09   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.81521222e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03996337e+01   # MW
        25     1.13648339e+02   # h0
        35     7.55830464e+02   # H0
        36     7.55717382e+02   # A0
        37     7.60222009e+02   # H+
   1000021     9.32918258e+02   # ~g
   1000022     1.60214168e+02   # ~neutralino(1)
   1000023     3.10279314e+02   # ~neutralino(2)
   1000024     3.10369337e+02   # ~chargino(1)
   1000025    -6.28408570e+02   # ~neutralino(3)
   1000035     6.37684663e+02   # ~neutralino(4)
   1000037     6.38576892e+02   # ~chargino(2)
   1000039     2.84400000e-05   # ~gravitino
   1000001     1.19299350e+03   # ~d_L
   1000002     1.19049782e+03   # ~u_L
   1000003     1.19299004e+03   # ~s_L
   1000004     1.19049435e+03   # ~c_L
   1000005     1.09055892e+03   # ~b_1
   1000006     9.33014872e+02   # ~t_1
   1000011     4.67133847e+02   # ~e_L
   1000012     4.60048206e+02   # ~nue_L
   1000013     4.67128209e+02   # ~mu_L
   1000014     4.60042511e+02   # ~numu_L
   1000015     2.48020171e+02   # ~stau_1
   1000016     4.58040913e+02   # ~nu_tau_L
   2000001     1.10934055e+03   # ~d_R
   2000002     1.11760151e+03   # ~u_R
   2000003     1.10933560e+03   # ~s_R
   2000004     1.11759900e+03   # ~c_R
   2000005     1.11148314e+03   # ~b_2
   2000006     1.12036194e+03   # ~t_2
   2000011     2.58432849e+02   # ~e_R
   2000013     2.58412389e+02   # ~mu_R
   2000015     4.67062527e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.12176749e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96417035e-01   # N_{1,1}
  1  2    -1.53270705e-02   # N_{1,2}
  1  3     7.91813364e-02   # N_{1,3}
  1  4    -2.54654616e-02   # N_{1,4}
  2  1     3.05940317e-02   # N_{2,1}
  2  2     9.81525390e-01   # N_{2,2}
  2  3    -1.66070215e-01   # N_{2,3}
  2  4     8.99588617e-02   # N_{2,4}
  3  1    -3.69131541e-02   # N_{3,1}
  3  2     5.51827958e-02   # N_{3,2}
  3  3     7.02941590e-01   # N_{3,3}
  3  4     7.08142217e-01   # N_{3,4}
  4  1    -6.96743651e-02   # N_{4,1}
  4  2     1.82559162e-01   # N_{4,2}
  4  3     6.87040116e-01   # N_{4,3}
  4  4    -6.99852495e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.71493563e-01   # U_{1,1}
  1  2    -2.37065934e-01   # U_{1,2}
  2  1     2.37065934e-01   # U_{2,1}
  2  2     9.71493563e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.91654856e-01   # V_{1,1}
  1  2    -1.28921084e-01   # V_{1,2}
  2  1     1.28921084e-01   # V_{2,1}
  2  2     9.91654856e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.30326895e-01   # F_{11}
  1  2     9.73113314e-01   # F_{12}
  2  1     9.73113314e-01   # F_{21}
  2  2    -2.30326895e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     6.54403710e-01   # F_{11}
  1  2     7.56145346e-01   # F_{12}
  2  1     7.56145346e-01   # F_{21}
  2  2    -6.54403710e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.05650152e-01   # F_{11}
  1  2     9.94403362e-01   # F_{12}
  2  1     9.94403362e-01   # F_{21}
  2  2    -1.05650152e-01   # F_{22}
Block gauge Q= 9.98328964e+02  # SM gauge couplings
     1     3.62766260e-01   # g'(Q)MSSM DRbar
     2     6.43403103e-01   # g(Q)MSSM DRbar
     3     1.06114331e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.98328964e+02  
  3  3     8.61411362e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.98328964e+02  
  3  3     1.99687275e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.98328964e+02  
  3  3     1.50923116e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.98328964e+02 # Higgs mixing parameters
     1     6.21293093e+02    # mu(Q)MSSM DRbar
     2     1.44999108e+01    # tan beta(Q)MSSM DRbar
     3     2.43889171e+02    # higgs vev(Q)MSSM DRbar
     4     6.02175552e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.98328964e+02  # MSSM DRbar SUSY breaking parameters
     1     1.63983386e+02      # M_1(Q)
     2     3.06651963e+02      # M_2(Q)
     3     8.44108696e+02      # M_3(Q)
    21     1.80507771e+05      # mH1^2(Q)
    22    -3.69088782e+05      # mH2^2(Q)
    31     4.62963124e+02      # meL(Q)
    32     4.62957454e+02      # mmuL(Q)
    33     4.61229790e+02      # mtauL(Q)
    34     2.50797160e+02      # meR(Q)
    35     2.50776071e+02      # mmuR(Q)
    36     2.44275825e+02      # mtauR(Q)
    41     1.16509053e+03      # mqL1(Q)
    42     1.16508698e+03      # mqL2(Q)
    43     1.07974011e+03      # mqL3(Q)
    44     1.09143622e+03      # muR(Q)
    45     1.09143364e+03      # mcR(Q)
    46     9.07009150e+02      # mtR(Q)
    47     1.08159054e+03      # mdR(Q)
    48     1.08158543e+03      # msR(Q)
    49     1.07202751e+03      # mbR(Q)
Block au Q= 9.98328964e+02  
  1  1    -5.61117830e+02      # Au(Q)MSSM DRbar
  2  2    -5.61115929e+02      # Ac(Q)MSSM DRbar
  3  3    -4.83606746e+02      # At(Q)MSSM DRbar
Block ad Q= 9.98328964e+02  
  1  1    -6.38610010e+02      # Ad(Q)MSSM DRbar
  2  2    -6.38607368e+02      # As(Q)MSSM DRbar
  3  3    -6.09415770e+02      # Ab(Q)MSSM DRbar
Block ae Q= 9.98328964e+02  
  1  1    -8.31166827e+01      # Ae(Q)MSSM DRbar
  2  2    -8.31150342e+01      # Amu(Q)MSSM DRbar
  3  3    -8.26135338e+01      # Atau(Q)MSSM DRbar
