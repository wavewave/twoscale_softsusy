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
     1    1.60000000e+05   # lambda
     2    1.00000000e+14   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.13229132e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03958348e+01   # MW
        25     1.15801435e+02   # h0
        35     1.05794748e+03   # H0
        36     1.05790381e+03   # A0
        37     1.06115317e+03   # H+
   1000021     1.19552394e+03   # ~g
   1000022     2.13897704e+02   # ~neutralino(1)
   1000023     4.12140246e+02   # ~neutralino(2)
   1000024     4.12271926e+02   # ~chargino(1)
   1000025    -8.31789358e+02   # ~neutralino(3)
   1000035     8.38639105e+02   # ~neutralino(4)
   1000037     8.39411597e+02   # ~chargino(2)
   1000039     3.79200000e+00   # ~gravitino
   1000001     1.46950093e+03   # ~d_L
   1000002     1.46750964e+03   # ~u_L
   1000003     1.46949512e+03   # ~s_L
   1000004     1.46750381e+03   # ~c_L
   1000005     1.29925270e+03   # ~b_1
   1000006     1.03325499e+03   # ~t_1
   1000011     7.09724795e+02   # ~e_L
   1000012     7.04972646e+02   # ~nue_L
   1000013     7.09709720e+02   # ~mu_L
   1000014     7.04957576e+02   # ~numu_L
   1000015     4.66290128e+02   # ~stau_1
   1000016     7.00042545e+02   # ~nu_tau_L
   2000001     1.32104331e+03   # ~d_R
   2000002     1.34815331e+03   # ~u_R
   2000003     1.32103467e+03   # ~s_R
   2000004     1.34814904e+03   # ~c_R
   2000005     1.33051158e+03   # ~b_2
   2000006     1.34216377e+03   # ~t_2
   2000011     4.82459029e+02   # ~e_R
   2000013     4.82414651e+02   # ~mu_R
   2000015     7.06079750e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.00915093e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.98006823e-01   # N_{1,1}
  1  2    -8.99227162e-03   # N_{1,2}
  1  3     5.94245253e-02   # N_{1,3}
  1  4    -1.92417609e-02   # N_{1,4}
  2  1     1.77851993e-02   # N_{2,1}
  2  2     9.89394943e-01   # N_{2,2}
  2  3    -1.26725906e-01   # N_{2,3}
  2  4     6.87159240e-02   # N_{2,4}
  3  1    -2.79406267e-02   # N_{3,1}
  3  2     4.16111316e-02   # N_{3,2}
  3  3     7.04708621e-01   # N_{3,3}
  3  4     7.07724237e-01   # N_{3,4}
  4  1    -5.37158131e-02   # N_{4,1}
  4  2     1.38871522e-01   # N_{4,2}
  4  3     6.95553758e-01   # N_{4,3}
  4  4    -7.02875723e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.83599449e-01   # U_{1,1}
  1  2    -1.80366640e-01   # U_{1,2}
  2  1     1.80366640e-01   # U_{2,1}
  2  2     9.83599449e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.95168976e-01   # V_{1,1}
  1  2    -9.81769234e-02   # V_{1,2}
  2  1     9.81769234e-02   # V_{2,1}
  2  2     9.95168976e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     1.87093795e-01   # F_{11}
  1  2     9.82342054e-01   # F_{12}
  2  1     9.82342054e-01   # F_{21}
  2  2    -1.87093795e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.10017469e-01   # F_{11}
  1  2     9.12077669e-01   # F_{12}
  2  1     9.12077669e-01   # F_{21}
  2  2    -4.10017469e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     7.87772524e-02   # F_{11}
  1  2     9.96892243e-01   # F_{12}
  2  1     9.96892243e-01   # F_{21}
  2  2    -7.87772524e-02   # F_{22}
Block gauge Q= 1.14416604e+03  # SM gauge couplings
     1     3.62806275e-01   # g'(Q)MSSM DRbar
     2     6.41730819e-01   # g(Q)MSSM DRbar
     3     1.05131142e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.14416604e+03  
  3  3     8.54040184e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.14416604e+03  
  3  3     1.96983345e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.14416604e+03  
  3  3     1.50685042e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.14416604e+03 # Higgs mixing parameters
     1     8.25429740e+02    # mu(Q)MSSM DRbar
     2     1.44798149e+01    # tan beta(Q)MSSM DRbar
     3     2.43815178e+02    # higgs vev(Q)MSSM DRbar
     4     1.16822927e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.14416604e+03  # MSSM DRbar SUSY breaking parameters
     1     2.17279029e+02      # M_1(Q)
     2     4.02026155e+02      # M_2(Q)
     3     1.09852145e+03      # M_3(Q)
    21     4.26650420e+05      # mH1^2(Q)
    22    -6.58236375e+05      # mH2^2(Q)
    31     7.06001178e+02      # meL(Q)
    32     7.05986127e+02      # mmuL(Q)
    33     7.01392162e+02      # mtauL(Q)
    34     4.77466346e+02      # meR(Q)
    35     4.77421533e+02      # mmuR(Q)
    36     4.63583911e+02      # mtauR(Q)
    41     1.43615822e+03      # mqL1(Q)
    42     1.43615224e+03      # mqL2(Q)
    43     1.29673326e+03      # mqL3(Q)
    44     1.31512796e+03      # muR(Q)
    45     1.31512355e+03      # mcR(Q)
    46     9.98572380e+02      # mtR(Q)
    47     1.28584026e+03      # mdR(Q)
    48     1.28583130e+03      # msR(Q)
    49     1.26949133e+03      # mbR(Q)
Block au Q= 1.14416604e+03  
  1  1    -1.01776162e+03      # Au(Q)MSSM DRbar
  2  2    -1.01775652e+03      # Ac(Q)MSSM DRbar
  3  3    -8.10600059e+02      # At(Q)MSSM DRbar
Block ad Q= 1.14416604e+03  
  1  1    -1.21491237e+03      # Ad(Q)MSSM DRbar
  2  2    -1.21490532e+03      # As(Q)MSSM DRbar
  3  3    -1.13693488e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.14416604e+03  
  1  1    -2.26843938e+02      # Ae(Q)MSSM DRbar
  2  2    -2.26836185e+02      # Amu(Q)MSSM DRbar
  3  3    -2.24476626e+02      # Atau(Q)MSSM DRbar
