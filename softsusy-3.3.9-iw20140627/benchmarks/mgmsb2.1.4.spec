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
     1    9.90000000e+04   # lambda
     2    1.10000000e+05   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.27404696e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04010841e+01   # MW
        25     1.13035158e+02   # h0
        35     5.05567611e+02   # H0
        36     5.05261209e+02   # A0
        37     5.11909021e+02   # H+
   1000021     9.42100512e+02   # ~g
   1000022     1.60375784e+02   # ~neutralino(1)
   1000023     2.94943878e+02   # ~neutralino(2)
   1000024     2.94310416e+02   # ~chargino(1)
   1000025    -3.99213264e+02   # ~neutralino(3)
   1000035     4.31731925e+02   # ~neutralino(4)
   1000037     4.31703746e+02   # ~chargino(2)
   1000039     2.58093000e-09   # ~gravitino
   1000001     1.12450618e+03   # ~d_L
   1000002     1.12186557e+03   # ~u_L
   1000003     1.12450465e+03   # ~s_L
   1000004     1.12186403e+03   # ~c_L
   1000005     1.06602282e+03   # ~b_1
   1000006     9.95197056e+02   # ~t_1
   1000011     3.48546173e+02   # ~e_L
   1000012     3.39098772e+02   # ~nue_L
   1000013     3.48544674e+02   # ~mu_L
   1000014     3.39097236e+02   # ~numu_L
   1000015     1.68048488e+02   # ~stau_1
   1000016     3.38418878e+02   # ~nu_tau_L
   2000001     1.07428795e+03   # ~d_R
   2000002     1.07729988e+03   # ~u_R
   2000003     1.07428582e+03   # ~s_R
   2000004     1.07729879e+03   # ~c_R
   2000005     1.08347617e+03   # ~b_2
   2000006     1.09504820e+03   # ~t_2
   2000011     1.73903730e+02   # ~e_R
   2000013     1.73897670e+02   # ~mu_R
   2000015     3.49570531e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.48156729e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.86480484e-01   # N_{1,1}
  1  2    -3.68338515e-02   # N_{1,2}
  1  3     1.44863104e-01   # N_{1,3}
  1  4    -6.71878195e-02   # N_{1,4}
  2  1     1.08692054e-01   # N_{2,1}
  2  2     8.68792762e-01   # N_{2,2}
  2  3    -3.82239390e-01   # N_{2,3}
  2  4     2.95428880e-01   # N_{2,4}
  3  1    -5.15877633e-02   # N_{3,1}
  3  2     7.26362575e-02   # N_{3,2}
  3  3     6.98903454e-01   # N_{3,3}
  3  4     7.09645432e-01   # N_{3,4}
  4  1    -1.11269918e-01   # N_{4,1}
  4  2     4.88432573e-01   # N_{4,2}
  4  3     5.86891550e-01   # N_{4,3}
  4  4    -6.36090351e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     8.31210697e-01   # U_{1,1}
  1  2    -5.55957532e-01   # U_{1,2}
  2  1     5.55957532e-01   # U_{2,1}
  2  2     8.31210697e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.02628843e-01   # V_{1,1}
  1  2    -4.30419762e-01   # V_{1,2}
  2  1     4.30419762e-01   # V_{2,1}
  2  2     9.02628843e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.57030756e-01   # F_{11}
  1  2     9.66403223e-01   # F_{12}
  2  1     9.66403223e-01   # F_{21}
  2  2    -2.57030756e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.42009280e-01   # F_{11}
  1  2     8.97010477e-01   # F_{12}
  2  1     8.97010477e-01   # F_{21}
  2  2    -4.42009280e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.11288814e-01   # F_{11}
  1  2     9.93788106e-01   # F_{12}
  2  1     9.93788106e-01   # F_{21}
  2  2    -1.11288814e-01   # F_{22}
Block gauge Q= 1.02185056e+03  # SM gauge couplings
     1     3.63124134e-01   # g'(Q)MSSM DRbar
     2     6.44443735e-01   # g(Q)MSSM DRbar
     3     1.06081871e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.02185056e+03  
  3  3     8.63361230e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.02185056e+03  
  3  3     2.03794086e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.02185056e+03  
  3  3     1.51373897e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.02185056e+03 # Higgs mixing parameters
     1     3.90557709e+02    # mu(Q)MSSM DRbar
     2     1.44940069e+01    # tan beta(Q)MSSM DRbar
     3     2.43544491e+02    # higgs vev(Q)MSSM DRbar
     4     2.82980421e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.02185056e+03  # MSSM DRbar SUSY breaking parameters
     1     1.67043470e+02      # M_1(Q)
     2     3.14505527e+02      # M_2(Q)
     3     8.56450150e+02      # M_3(Q)
    21     1.02532884e+05      # mH1^2(Q)
    22    -1.33073010e+05      # mH2^2(Q)
    31     3.42029459e+02      # meL(Q)
    32     3.42027932e+02      # mmuL(Q)
    33     3.41561140e+02      # mtauL(Q)
    34     1.63434564e+02      # meR(Q)
    35     1.63428109e+02      # mmuR(Q)
    36     1.61443794e+02      # mtauR(Q)
    41     1.09349600e+03      # mqL1(Q)
    42     1.09349442e+03      # mqL2(Q)
    43     1.05555482e+03      # mqL3(Q)
    44     1.04850241e+03      # muR(Q)
    45     1.04850128e+03      # mcR(Q)
    46     9.70911551e+02      # mtR(Q)
    47     1.04418581e+03      # mdR(Q)
    48     1.04418360e+03      # msR(Q)
    49     1.03988375e+03      # mbR(Q)
Block au Q= 1.02185056e+03  
  1  1    -2.62414911e+02      # Au(Q)MSSM DRbar
  2  2    -2.62414538e+02      # Ac(Q)MSSM DRbar
  3  3    -2.47133743e+02      # At(Q)MSSM DRbar
Block ad Q= 1.02185056e+03  
  1  1    -2.79383927e+02      # Ad(Q)MSSM DRbar
  2  2    -2.79383407e+02      # As(Q)MSSM DRbar
  3  3    -2.73629742e+02      # Ab(Q)MSSM DRbar
Block ae Q= 1.02185056e+03  
  1  1    -2.68534911e+01      # Ae(Q)MSSM DRbar
  2  2    -2.68532925e+01      # Amu(Q)MSSM DRbar
  3  3    -2.67926198e+01      # Atau(Q)MSSM DRbar
