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
     1    7.50000000e+02   # m0
     2    6.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.79840904e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=8.97838499e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03886365e+01   # MW
        25     1.18446743e+02   # h0
        35     8.65272588e+02   # H0
        36     8.65264758e+02   # A0
        37     8.69290790e+02   # H+
   1000021     1.49024605e+03   # ~g
   1000022     2.73950091e+02   # ~neutralino(1)
   1000023     5.21375652e+02   # ~neutralino(2)
   1000024     5.21515289e+02   # ~chargino(1)
   1000025    -8.51062187e+02   # ~neutralino(3)
   1000035     8.59250484e+02   # ~neutralino(4)
   1000037     8.60103386e+02   # ~chargino(2)
   1000001     1.52213618e+03   # ~d_L
   1000002     1.52020992e+03   # ~u_L
   1000003     1.52209262e+03   # ~s_L
   1000004     1.52016630e+03   # ~c_L
   1000005     1.27098639e+03   # ~b_1
   1000006     1.08717131e+03   # ~t_1
   1000011     8.65185307e+02   # ~e_L
   1000012     8.61213863e+02   # ~nue_L
   1000013     8.64977236e+02   # ~mu_L
   1000014     8.61006530e+02   # ~numu_L
   1000015     6.09215054e+02   # ~stau_1
   1000016     7.89894860e+02   # ~nu_tau_L
   2000001     1.47304582e+03   # ~d_R
   2000002     1.47720363e+03   # ~u_R
   2000003     1.47296016e+03   # ~s_R
   2000004     1.47719802e+03   # ~c_R
   2000005     1.34731013e+03   # ~b_2
   2000006     1.31986897e+03   # ~t_2
   2000011     7.88645472e+02   # ~e_R
   2000013     7.88188423e+02   # ~mu_R
   2000015     8.03985855e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.59197922e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97966685e-01   # N_{1,1}
  1  2    -7.00756460e-03   # N_{1,2}
  1  3     5.98012968e-02   # N_{1,3}
  1  4    -2.09091966e-02   # N_{1,4}
  2  1     1.75995563e-02   # N_{2,1}
  2  2     9.84843526e-01   # N_{2,2}
  2  3    -1.46321838e-01   # N_{2,3}
  2  4     9.14516522e-02   # N_{2,4}
  3  1    -2.71357299e-02   # N_{3,1}
  3  2     3.95011763e-02   # N_{3,2}
  3  3     7.04907075e-01   # N_{3,3}
  3  4     7.07678829e-01   # N_{3,4}
  4  1    -5.49217930e-02   # N_{4,1}
  4  2     1.68741757e-01   # N_{4,2}
  4  3     6.91462031e-01   # N_{4,3}
  4  4    -7.00278570e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.78024771e-01   # U_{1,1}
  1  2    -2.08488722e-01   # U_{1,2}
  2  1     2.08488722e-01   # U_{2,1}
  2  2     9.78024771e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.91406572e-01   # V_{1,1}
  1  2    -1.30816698e-01   # V_{1,2}
  2  1     1.30816698e-01   # V_{2,1}
  2  2     9.91406572e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.67724514e-01   # F_{11}
  1  2     9.29934773e-01   # F_{12}
  2  1     9.29934773e-01   # F_{21}
  2  2    -3.67724514e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.13089813e-01   # F_{11}
  1  2     4.07758499e-01   # F_{12}
  2  1    -4.07758499e-01   # F_{21}
  2  2     9.13089813e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     2.37669688e-01   # F_{11}
  1  2     9.71346035e-01   # F_{12}
  2  1     9.71346035e-01   # F_{21}
  2  2    -2.37669688e-01   # F_{22}
Block gauge Q= 1.16443043e+03  # SM gauge couplings
     1     3.62625131e-01   # g'(Q)MSSM DRbar
     2     6.40749660e-01   # g(Q)MSSM DRbar
     3     1.04601377e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.16443043e+03  
  3  3     8.46875214e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.16443043e+03  
  3  3     4.95567039e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.16443043e+03  
  3  3     4.23709286e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.16443043e+03 # Higgs mixing parameters
     1     8.46595740e+02    # mu(Q)MSSM DRbar
     2     3.91663556e+01    # tan beta(Q)MSSM DRbar
     3     2.43680675e+02    # higgs vev(Q)MSSM DRbar
     4     9.57106490e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.16443043e+03  # MSSM DRbar SUSY breaking parameters
     1     2.77018430e+02      # M_1(Q)
     2     5.10792771e+02      # M_2(Q)
     3     1.42163472e+03      # M_3(Q)
    21     4.46850724e+04      # mH1^2(Q)
    22    -6.99015954e+05      # mH2^2(Q)
    31     8.60786195e+02      # meL(Q)
    32     8.60578691e+02      # mmuL(Q)
    33     7.91995865e+02      # mtauL(Q)
    34     7.85602254e+02      # meR(Q)
    35     7.85143917e+02      # mmuR(Q)
    36     6.22395670e+02      # mtauR(Q)
    41     1.47887380e+03      # mqL1(Q)
    42     1.47882875e+03      # mqL2(Q)
    43     1.25025187e+03      # mqL3(Q)
    44     1.43647433e+03      # muR(Q)
    45     1.43646856e+03      # mcR(Q)
    46     1.07896198e+03      # mtR(Q)
    47     1.43137624e+03      # mdR(Q)
    48     1.43128791e+03      # msR(Q)
    49     1.29697416e+03      # mbR(Q)
Block au Q= 1.16443043e+03  
  1  1    -1.78111535e+03      # Au(Q)MSSM DRbar
  2  2    -1.78107369e+03      # Ac(Q)MSSM DRbar
  3  3    -1.25136020e+03      # At(Q)MSSM DRbar
Block ad Q= 1.16443043e+03  
  1  1    -2.05354983e+03      # Ad(Q)MSSM DRbar
  2  2    -2.05344376e+03      # As(Q)MSSM DRbar
  3  3    -1.73151971e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.16443043e+03  
  1  1    -6.82580290e+02      # Ae(Q)MSSM DRbar
  2  2    -6.82247877e+02      # Amu(Q)MSSM DRbar
  3  3    -5.72739849e+02      # Atau(Q)MSSM DRbar
