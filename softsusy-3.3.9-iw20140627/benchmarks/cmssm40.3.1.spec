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
     1    1.00000000e+03   # m0
     2    3.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.26519272e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=2.70004429e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03936432e+01   # MW
        25     1.15484642e+02   # h0
        35     7.79898613e+02   # H0
        36     7.80035390e+02   # A0
        37     7.84305595e+02   # H+
   1000021     8.76446713e+02   # ~g
   1000022     1.44921489e+02   # ~neutralino(1)
   1000023     2.76971265e+02   # ~neutralino(2)
   1000024     2.77055512e+02   # ~chargino(1)
   1000025    -5.23710279e+02   # ~neutralino(3)
   1000035     5.34271462e+02   # ~neutralino(4)
   1000037     5.35754040e+02   # ~chargino(2)
   1000001     1.23232333e+03   # ~d_L
   1000002     1.22987714e+03   # ~u_L
   1000003     1.23227863e+03   # ~s_L
   1000004     1.22983235e+03   # ~c_L
   1000005     9.55133976e+02   # ~b_1
   1000006     7.84127431e+02   # ~t_1
   1000011     1.02430735e+03   # ~e_L
   1000012     1.02087141e+03   # ~nue_L
   1000013     1.02404516e+03   # ~mu_L
   1000014     1.02061094e+03   # ~numu_L
   1000015     8.23215987e+02   # ~stau_1
   1000016     9.36229233e+02   # ~nu_tau_L
   2000001     1.21640475e+03   # ~d_R
   2000002     1.21694902e+03   # ~u_R
   2000003     1.21631937e+03   # ~s_R
   2000004     1.21694323e+03   # ~c_R
   2000005     1.06982994e+03   # ~b_2
   2000006     9.92636212e+02   # ~t_2
   2000011     1.00826955e+03   # ~e_R
   2000013     1.00773999e+03   # ~mu_R
   2000015     9.43666001e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.60337741e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.94739404e-01   # N_{1,1}
  1  2    -1.79052767e-02   # N_{1,2}
  1  3     9.64551701e-02   # N_{1,3}
  1  4    -2.94842176e-02   # N_{1,4}
  2  1     4.06571137e-02   # N_{2,1}
  2  2     9.71542240e-01   # N_{2,2}
  2  3    -2.04700658e-01   # N_{2,3}
  2  4     1.12028195e-01   # N_{2,4}
  3  1    -4.57428843e-02   # N_{3,1}
  3  2     6.78983432e-02   # N_{3,2}
  3  3     7.00927594e-01   # N_{3,3}
  3  4     7.08518110e-01   # N_{3,4}
  4  1    -8.21468532e-02   # N_{4,1}
  4  2     2.26218684e-01   # N_{4,2}
  4  3     6.76383434e-01   # N_{4,3}
  4  4    -6.96119568e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.56305221e-01   # U_{1,1}
  1  2    -2.92370183e-01   # U_{1,2}
  2  1     2.92370183e-01   # U_{2,1}
  2  2     9.56305221e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.87025097e-01   # V_{1,1}
  1  2    -1.60566054e-01   # V_{1,2}
  2  1     1.60566054e-01   # V_{2,1}
  2  2     9.87025097e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.42555461e-01   # F_{11}
  1  2     9.39497608e-01   # F_{12}
  2  1     9.39497608e-01   # F_{21}
  2  2    -3.42555461e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.78457801e-01   # F_{11}
  1  2     2.06446923e-01   # F_{12}
  2  1    -2.06446923e-01   # F_{21}
  2  2     9.78457801e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.82717898e-01   # F_{11}
  1  2     9.83165383e-01   # F_{12}
  2  1     9.83165383e-01   # F_{21}
  2  2    -1.82717898e-01   # F_{22}
Block gauge Q= 8.61227778e+02  # SM gauge couplings
     1     3.61776367e-01   # g'(Q)MSSM DRbar
     2     6.42807657e-01   # g(Q)MSSM DRbar
     3     1.06554336e+00   # g3(Q)MSSM DRbar
Block yu Q= 8.61227778e+02  
  3  3     8.61790732e-01   # Yt(Q)MSSM DRbar
Block yd Q= 8.61227778e+02  
  3  3     5.19072768e-01   # Yb(Q)MSSM DRbar
Block ye Q= 8.61227778e+02  
  3  3     4.12417645e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 8.61227778e+02 # Higgs mixing parameters
     1     5.15740136e+02    # mu(Q)MSSM DRbar
     2     3.92588577e+01    # tan beta(Q)MSSM DRbar
     3     2.43883803e+02    # higgs vev(Q)MSSM DRbar
     4     7.33551840e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 8.61227778e+02  # MSSM DRbar SUSY breaking parameters
     1     1.46718263e+02      # M_1(Q)
     2     2.73432491e+02      # M_2(Q)
     3     7.89158018e+02      # M_3(Q)
    21     3.60109103e+05      # mH1^2(Q)
    22    -2.57400356e+05      # mH2^2(Q)
    31     1.02169229e+03      # meL(Q)
    32     1.02143271e+03      # mmuL(Q)
    33     9.39129306e+02      # mtauL(Q)
    34     1.00623655e+03      # meR(Q)
    35     1.00570670e+03      # mmuR(Q)
    36     8.28494598e+02      # mtauR(Q)
    41     1.21014134e+03      # mqL1(Q)
    42     1.21009592e+03      # mqL2(Q)
    43     9.41660437e+02      # mqL3(Q)
    44     1.19785216e+03      # muR(Q)
    45     1.19784628e+03      # mcR(Q)
    46     7.75203374e+02      # mtR(Q)
    47     1.19651874e+03      # mdR(Q)
    48     1.19643186e+03      # msR(Q)
    49     1.04740789e+03      # mbR(Q)
Block au Q= 8.61227778e+02  
  1  1    -1.14580161e+03      # Au(Q)MSSM DRbar
  2  2    -1.14577179e+03      # Ac(Q)MSSM DRbar
  3  3    -7.59301559e+02      # At(Q)MSSM DRbar
Block ad Q= 8.61227778e+02  
  1  1    -1.33446752e+03      # Ad(Q)MSSM DRbar
  2  2    -1.33439158e+03      # As(Q)MSSM DRbar
  3  3    -1.09385930e+03      # Ab(Q)MSSM DRbar
Block ae Q= 8.61227778e+02  
  1  1    -5.52810152e+02      # Ae(Q)MSSM DRbar
  2  2    -5.52517892e+02      # Amu(Q)MSSM DRbar
  3  3    -4.61890970e+02      # Atau(Q)MSSM DRbar
