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
     1    1.20000000e+03   # m0
     2    4.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.08986783e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=3.61915284e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03908419e+01   # MW
        25     1.16886826e+02   # h0
        35     9.42583356e+02   # H0
        36     9.42686467e+02   # A0
        37     9.46261958e+02   # H+
   1000021     1.10074818e+03   # ~g
   1000022     1.88514968e+02   # ~neutralino(1)
   1000023     3.60117299e+02   # ~neutralino(2)
   1000024     3.60224623e+02   # ~chargino(1)
   1000025    -6.19932739e+02   # ~neutralino(3)
   1000035     6.30468391e+02   # ~neutralino(4)
   1000037     6.31566370e+02   # ~chargino(2)
   1000001     1.50618568e+03   # ~d_L
   1000002     1.50421672e+03   # ~u_L
   1000003     1.50613388e+03   # ~s_L
   1000004     1.50416486e+03   # ~c_L
   1000005     1.18351845e+03   # ~b_1
   1000006     9.83200733e+02   # ~t_1
   1000011     1.23341744e+03   # ~e_L
   1000012     1.23051498e+03   # ~nue_L
   1000013     1.23311259e+03   # ~mu_L
   1000014     1.23021264e+03   # ~numu_L
   1000015     9.95410347e+02   # ~stau_1
   1000016     1.13137940e+03   # ~nu_tau_L
   2000001     1.48466410e+03   # ~d_R
   2000002     1.48591559e+03   # ~u_R
   2000003     1.48456509e+03   # ~s_R
   2000004     1.48590883e+03   # ~c_R
   2000005     1.31116063e+03   # ~b_2
   2000006     1.21425758e+03   # ~t_2
   2000011     1.21108629e+03   # ~e_R
   2000013     1.21046948e+03   # ~mu_R
   2000015     1.13751895e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.59229980e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96171853e-01   # N_{1,1}
  1  2    -1.28130147e-02   # N_{1,2}
  1  3     8.20672307e-02   # N_{1,3}
  1  4    -2.72476778e-02   # N_{1,4}
  2  1     3.11359335e-02   # N_{2,1}
  2  2     9.75151544e-01   # N_{2,2}
  2  3    -1.88406139e-01   # N_{2,3}
  2  4     1.12308266e-01   # N_{2,4}
  3  1    -3.78244786e-02   # N_{3,1}
  3  2     5.54584956e-02   # N_{3,2}
  3  3     7.02897009e-01   # N_{3,3}
  3  4     7.08116840e-01   # N_{3,4}
  4  1    -7.23982190e-02   # N_{4,1}
  4  2     2.14101957e-01   # N_{4,2}
  4  3     6.80958069e-01   # N_{4,3}
  4  4    -6.96573728e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.63198430e-01   # U_{1,1}
  1  2    -2.68791341e-01   # U_{1,2}
  2  1     2.68791341e-01   # U_{2,1}
  2  2     9.63198430e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.86987592e-01   # V_{1,1}
  1  2    -1.60796432e-01   # V_{1,2}
  2  1     1.60796432e-01   # V_{2,1}
  2  2     9.86987592e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.95795369e-01   # F_{11}
  1  2     9.55251328e-01   # F_{12}
  2  1     9.55251328e-01   # F_{21}
  2  2    -2.95795369e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.84266227e-01   # F_{11}
  1  2     1.76691806e-01   # F_{12}
  2  1    -1.76691806e-01   # F_{21}
  2  2     9.84266227e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.51225029e-01   # F_{11}
  1  2     9.88499363e-01   # F_{12}
  2  1     9.88499363e-01   # F_{21}
  2  2    -1.51225029e-01   # F_{22}
Block gauge Q= 1.06740664e+03  # SM gauge couplings
     1     3.62258122e-01   # g'(Q)MSSM DRbar
     2     6.41713940e-01   # g(Q)MSSM DRbar
     3     1.05405453e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.06740664e+03  
  3  3     8.54178464e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.06740664e+03  
  3  3     5.16088234e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.06740664e+03  
  3  3     4.12825361e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.06740664e+03 # Higgs mixing parameters
     1     6.12069735e+02    # mu(Q)MSSM DRbar
     2     3.92071619e+01    # tan beta(Q)MSSM DRbar
     3     2.43612625e+02    # higgs vev(Q)MSSM DRbar
     4     1.07006123e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.06740664e+03  # MSSM DRbar SUSY breaking parameters
     1     1.90398249e+02      # M_1(Q)
     2     3.52809359e+02      # M_2(Q)
     3     9.97158037e+02      # M_3(Q)
    21     5.37923065e+05      # mH1^2(Q)
    22    -3.57904184e+05      # mH2^2(Q)
    31     1.23047107e+03      # meL(Q)
    32     1.23016953e+03      # mmuL(Q)
    33     1.13384691e+03      # mtauL(Q)
    34     1.20893262e+03      # meR(Q)
    35     1.20831563e+03      # mmuR(Q)
    36     1.00067197e+03      # mtauR(Q)
    41     1.47876435e+03      # mqL1(Q)
    42     1.47871164e+03      # mqL2(Q)
    43     1.16479951e+03      # mqL3(Q)
    44     1.46164056e+03      # muR(Q)
    45     1.46163368e+03      # mcR(Q)
    46     9.68011002e+02      # mtR(Q)
    47     1.45972967e+03      # mdR(Q)
    48     1.45962875e+03      # msR(Q)
    49     1.28507826e+03      # mbR(Q)
Block au Q= 1.06740664e+03  
  1  1    -1.35325120e+03      # Au(Q)MSSM DRbar
  2  2    -1.35321765e+03      # Ac(Q)MSSM DRbar
  3  3    -9.19232577e+02      # At(Q)MSSM DRbar
Block ad Q= 1.06740664e+03  
  1  1    -1.56517916e+03      # Ad(Q)MSSM DRbar
  2  2    -1.56509375e+03      # As(Q)MSSM DRbar
  3  3    -1.29428578e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.06740664e+03  
  1  1    -5.92607871e+02      # Ae(Q)MSSM DRbar
  2  2    -5.92303273e+02      # Amu(Q)MSSM DRbar
  3  3    -4.97393923e+02      # Atau(Q)MSSM DRbar
