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
     1    3.50000000e+04   # lambda
     2    7.00000000e+04   # M_mess
     5    3.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.61733918e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04108408e+01   # MW
        25     1.10110738e+02   # h0
        35     3.39344511e+02   # H0
        36     3.38941841e+02   # A0
        37     3.48642611e+02   # H+
   1000021     8.39053651e+02   # ~g
   1000022     1.40797727e+02   # ~neutralino(1)
   1000023     2.32120218e+02   # ~neutralino(2)
   1000024     2.28417624e+02   # ~chargino(1)
   1000025    -2.81439801e+02   # ~neutralino(3)
   1000035     3.48502816e+02   # ~neutralino(4)
   1000037     3.48282746e+02   # ~chargino(2)
   1000039     5.80650000e-10   # ~gravitino
   1000001     7.99294119e+02   # ~d_L
   1000002     7.95445895e+02   # ~u_L
   1000003     7.99293111e+02   # ~s_L
   1000004     7.95444881e+02   # ~c_L
   1000005     7.59952802e+02   # ~b_1
   1000006     7.14433027e+02   # ~t_1
   1000011     2.31279767e+02   # ~e_L
   1000012     2.16884110e+02   # ~nue_L
   1000013     2.31278858e+02   # ~mu_L
   1000014     2.16883142e+02   # ~numu_L
   1000015     1.09009277e+02   # ~stau_1
   1000016     2.16445585e+02   # ~nu_tau_L
   2000001     7.68369056e+02   # ~d_R
   2000002     7.69254349e+02   # ~u_R
   2000003     7.68367646e+02   # ~s_R
   2000004     7.69253634e+02   # ~c_R
   2000005     7.74570296e+02   # ~b_2
   2000006     7.93599340e+02   # ~t_2
   2000011     1.16277177e+02   # ~e_R
   2000013     1.16273506e+02   # ~mu_R
   2000015     2.33641522e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -8.19982774e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.55291006e-01   # N_{1,1}
  1  2    -8.09364542e-02   # N_{1,2}
  1  3     2.47863404e-01   # N_{1,3}
  1  4    -1.39399129e-01   # N_{1,4}
  2  1    -2.62569225e-01   # N_{2,1}
  2  2    -6.53313846e-01   # N_{2,2}
  2  3     5.37962757e-01   # N_{2,3}
  2  4    -4.63502419e-01   # N_{2,4}
  3  1    -6.79291116e-02   # N_{3,1}
  3  2     9.21950342e-02   # N_{3,2}
  3  3     6.92496108e-01   # N_{3,3}
  3  4     7.12274421e-01   # N_{3,4}
  4  1    -1.17737552e-01   # N_{4,1}
  4  2     7.47081244e-01   # N_{4,2}
  4  3     4.11836066e-01   # N_{4,3}
  4  4    -5.08329164e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -5.81561883e-01   # U_{1,1}
  1  2     8.13502168e-01   # U_{1,2}
  2  1    -8.13502168e-01   # U_{2,1}
  2  2    -5.81561883e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -7.19859427e-01   # V_{1,1}
  1  2     6.94119878e-01   # V_{1,2}
  2  1    -6.94119878e-01   # V_{2,1}
  2  2    -7.19859427e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.95228701e-01   # F_{11}
  1  2     9.18582753e-01   # F_{12}
  2  1     9.18582753e-01   # F_{21}
  2  2    -3.95228701e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     5.99488661e-01   # F_{11}
  1  2     8.00383249e-01   # F_{12}
  2  1     8.00383249e-01   # F_{21}
  2  2    -5.99488661e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.73858840e-01   # F_{11}
  1  2     9.84770584e-01   # F_{12}
  2  1     9.84770584e-01   # F_{21}
  2  2    -1.73858840e-01   # F_{22}
Block gauge Q= 7.29474231e+02  # SM gauge couplings
     1     3.62409659e-01   # g'(Q)MSSM DRbar
     2     6.45744587e-01   # g(Q)MSSM DRbar
     3     1.07446073e+00   # g3(Q)MSSM DRbar
Block yu Q= 7.29474231e+02  
  3  3     8.72937122e-01   # Yt(Q)MSSM DRbar
Block yd Q= 7.29474231e+02  
  3  3     2.07499154e-01   # Yb(Q)MSSM DRbar
Block ye Q= 7.29474231e+02  
  3  3     1.52182158e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 7.29474231e+02 # Higgs mixing parameters
     1     2.71989332e+02    # mu(Q)MSSM DRbar
     2     1.45563669e+01    # tan beta(Q)MSSM DRbar
     3     2.44078956e+02    # higgs vev(Q)MSSM DRbar
     4     1.31664934e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 7.29474231e+02  # MSSM DRbar SUSY breaking parameters
     1     1.51185264e+02      # M_1(Q)
     2     2.86912202e+02      # M_2(Q)
     3     7.98376682e+02      # M_3(Q)
    21     4.26438159e+04      # mH1^2(Q)
    22    -6.75544110e+04      # mH2^2(Q)
    31     2.22469664e+02      # meL(Q)
    32     2.22468722e+02      # mmuL(Q)
    33     2.22179941e+02      # mtauL(Q)
    34     1.03663240e+02      # meR(Q)
    35     1.03659130e+02      # mmuR(Q)
    36     1.02392387e+02      # mtauR(Q)
    41     7.67259988e+02      # mqL1(Q)
    42     7.67258948e+02      # mqL2(Q)
    43     7.42570912e+02      # mqL3(Q)
    44     7.40596870e+02      # muR(Q)
    45     7.40596138e+02      # mcR(Q)
    46     6.90530892e+02      # mtR(Q)
    47     7.38232312e+02      # mdR(Q)
    48     7.38230865e+02      # msR(Q)
    49     7.35399710e+02      # mbR(Q)
Block au Q= 7.29474231e+02  
  1  1    -2.43801934e+02      # Au(Q)MSSM DRbar
  2  2    -2.43801587e+02      # Ac(Q)MSSM DRbar
  3  3    -2.29653866e+02      # At(Q)MSSM DRbar
Block ad Q= 7.29474231e+02  
  1  1    -2.59648985e+02      # Ad(Q)MSSM DRbar
  2  2    -2.59648499e+02      # As(Q)MSSM DRbar
  3  3    -2.54310868e+02      # Ab(Q)MSSM DRbar
Block ae Q= 7.29474231e+02  
  1  1    -2.38599084e+01      # Ae(Q)MSSM DRbar
  2  2    -2.38597341e+01      # Amu(Q)MSSM DRbar
  3  3    -2.38063694e+01      # Atau(Q)MSSM DRbar
