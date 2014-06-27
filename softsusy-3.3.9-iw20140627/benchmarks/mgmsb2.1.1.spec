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
     1    7.20000000e+04   # lambda
     2    8.00000000e+04   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.16758093e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04112039e+01   # MW
        25     1.10612250e+02   # h0
        35     3.73635137e+02   # H0
        36     3.73218906e+02   # A0
        37     3.82168667e+02   # H+
   1000021     7.07369878e+02   # ~g
   1000022     1.14265310e+02   # ~neutralino(1)
   1000023     2.06540639e+02   # ~neutralino(2)
   1000024     2.05379261e+02   # ~chargino(1)
   1000025    -3.04618655e+02   # ~neutralino(3)
   1000035     3.38714960e+02   # ~neutralino(4)
   1000037     3.38984218e+02   # ~chargino(2)
   1000039     1.36512000e-09   # ~gravitino
   1000001     8.40579596e+02   # ~d_L
   1000002     8.36984879e+02   # ~u_L
   1000003     8.40578445e+02   # ~s_L
   1000004     8.36983722e+02   # ~c_L
   1000005     7.95991272e+02   # ~b_1
   1000006     7.47814110e+02   # ~t_1
   1000011     2.56424543e+02   # ~e_L
   1000012     2.43498005e+02   # ~nue_L
   1000013     2.56423460e+02   # ~mu_L
   1000014     2.43496869e+02   # ~numu_L
   1000015     1.22808064e+02   # ~stau_1
   1000016     2.42995657e+02   # ~nu_tau_L
   2000001     8.04159231e+02   # ~d_R
   2000002     8.05699277e+02   # ~u_R
   2000003     8.04157628e+02   # ~s_R
   2000004     8.05698461e+02   # ~c_R
   2000005     8.11379502e+02   # ~b_2
   2000006     8.27439219e+02   # ~t_2
   2000011     1.29436852e+02   # ~e_R
   2000013     1.29432523e+02   # ~mu_R
   2000015     2.58355412e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.96323971e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.75215330e-01   # N_{1,1}
  1  2    -6.35499271e-02   # N_{1,2}
  1  3     1.93876768e-01   # N_{1,3}
  1  4    -8.56052959e-02   # N_{1,4}
  2  1     1.61792215e-01   # N_{2,1}
  2  2     8.50465761e-01   # N_{2,2}
  2  3    -4.05487311e-01   # N_{2,3}
  2  4     2.93447287e-01   # N_{2,4}
  3  1    -6.88338636e-02   # N_{3,1}
  3  2     9.77375513e-02   # N_{3,2}
  3  3     6.92437925e-01   # N_{3,3}
  3  4     7.11504736e-01   # N_{3,4}
  4  1    -1.34313958e-01   # N_{4,1}
  4  2     5.12949089e-01   # N_{4,2}
  4  3     5.64377143e-01   # N_{4,3}
  4  4    -6.32709596e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     7.99953016e-01   # U_{1,1}
  1  2    -6.00062640e-01   # U_{1,2}
  2  1     6.00062640e-01   # U_{2,1}
  2  2     7.99953016e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.00655208e-01   # V_{1,1}
  1  2    -4.34534458e-01   # V_{1,2}
  2  1     4.34534458e-01   # V_{2,1}
  2  2     9.00655208e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.27995908e-01   # F_{11}
  1  2     9.44679143e-01   # F_{12}
  2  1     9.44679143e-01   # F_{21}
  2  2    -3.27995908e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     5.43483383e-01   # F_{11}
  1  2     8.39419926e-01   # F_{12}
  2  1     8.39419926e-01   # F_{21}
  2  2    -5.43483383e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.54174029e-01   # F_{11}
  1  2     9.88043708e-01   # F_{12}
  2  1     9.88043708e-01   # F_{21}
  2  2    -1.54174029e-01   # F_{22}
Block gauge Q= 7.68693772e+02  # SM gauge couplings
     1     3.62512223e-01   # g'(Q)MSSM DRbar
     2     6.46107290e-01   # g(Q)MSSM DRbar
     3     1.07638113e+00   # g3(Q)MSSM DRbar
Block yu Q= 7.68693772e+02  
  3  3     8.73707027e-01   # Yt(Q)MSSM DRbar
Block yd Q= 7.68693772e+02  
  3  3     2.06920368e-01   # Yb(Q)MSSM DRbar
Block ye Q= 7.68693772e+02  
  3  3     1.51625826e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 7.68693772e+02 # Higgs mixing parameters
     1     2.95114947e+02    # mu(Q)MSSM DRbar
     2     1.45437298e+01    # tan beta(Q)MSSM DRbar
     3     2.43902586e+02    # higgs vev(Q)MSSM DRbar
     4     1.54862133e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 7.68693772e+02  # MSSM DRbar SUSY breaking parameters
     1     1.21037430e+02      # M_1(Q)
     2     2.29808731e+02      # M_2(Q)
     3     6.41114032e+02      # M_3(Q)
    21     5.42288413e+04      # mH1^2(Q)
    22    -7.85626811e+04      # mH2^2(Q)
    31     2.49846918e+02      # meL(Q)
    32     2.49845807e+02      # mmuL(Q)
    33     2.49507369e+02      # mtauL(Q)
    34     1.18261004e+02      # meR(Q)
    35     1.18256261e+02      # mmuR(Q)
    36     1.16803614e+02      # mtauR(Q)
    41     8.15912978e+02      # mqL1(Q)
    42     8.15911785e+02      # mqL2(Q)
    43     7.87292162e+02      # mqL3(Q)
    44     7.83708463e+02      # muR(Q)
    45     7.83707617e+02      # mcR(Q)
    46     7.25286532e+02      # mtR(Q)
    47     7.80682968e+02      # mdR(Q)
    48     7.80681302e+02      # msR(Q)
    49     7.77420898e+02      # mbR(Q)
Block au Q= 7.68693772e+02  
  1  1    -1.99092972e+02      # Au(Q)MSSM DRbar
  2  2    -1.99092686e+02      # Ac(Q)MSSM DRbar
  3  3    -1.87348530e+02      # At(Q)MSSM DRbar
Block ad Q= 7.68693772e+02  
  1  1    -2.12230088e+02      # Ad(Q)MSSM DRbar
  2  2    -2.12229688e+02      # As(Q)MSSM DRbar
  3  3    -2.07802481e+02      # Ab(Q)MSSM DRbar
Block ae Q= 7.68693772e+02  
  1  1    -1.94808682e+01      # Ae(Q)MSSM DRbar
  2  2    -1.94807239e+01      # Amu(Q)MSSM DRbar
  3  3    -1.94367941e+01      # Atau(Q)MSSM DRbar
