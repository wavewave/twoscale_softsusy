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
     1    3.45000000e+02   # m0
     2    5.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.81392338e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=8.77331545e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03898648e+01   # MW
        25     1.17476646e+02   # h0
        35     6.59482559e+02   # H0
        36     6.59487658e+02   # A0
        37     6.64708847e+02   # H+
   1000021     1.25838621e+03   # ~g
   1000022     2.28730213e+02   # ~neutralino(1)
   1000023     4.35808922e+02   # ~neutralino(2)
   1000024     4.35941905e+02   # ~chargino(1)
   1000025    -7.56033195e+02   # ~neutralino(3)
   1000035     7.63934465e+02   # ~neutralino(4)
   1000037     7.65007572e+02   # ~chargino(2)
   1000001     1.19426777e+03   # ~d_L
   1000002     1.19173248e+03   # ~u_L
   1000003     1.19423289e+03   # ~s_L
   1000004     1.19169751e+03   # ~c_L
   1000005     9.98869291e+02   # ~b_1
   1000006     8.55784217e+02   # ~t_1
   1000011     5.06813456e+02   # ~e_L
   1000012     5.00297151e+02   # ~nue_L
   1000013     5.06675843e+02   # ~mu_L
   1000014     5.00158550e+02   # ~numu_L
   1000015     2.30312657e+02   # ~stau_1
   1000016     4.52843845e+02   # ~nu_tau_L
   2000001     1.14726408e+03   # ~d_R
   2000002     1.15095746e+03   # ~u_R
   2000003     1.14719475e+03   # ~s_R
   2000004     1.15095309e+03   # ~c_R
   2000005     1.06615670e+03   # ~b_2
   2000006     1.07143936e+03   # ~t_2
   2000011     4.04032485e+02   # ~e_R
   2000013     4.03683888e+02   # ~mu_R
   2000015     4.81586689e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.60821125e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97489794e-01   # N_{1,1}
  1  2    -8.89581754e-03   # N_{1,2}
  1  3     6.66744730e-02   # N_{1,3}
  1  4    -2.21244136e-02   # N_{1,4}
  2  1     2.11230631e-02   # N_{2,1}
  2  2     9.83534647e-01   # N_{2,2}
  2  3    -1.54453021e-01   # N_{2,3}
  2  4     9.14203356e-02   # N_{2,4}
  3  1    -3.09652222e-02   # N_{3,1}
  3  2     4.54572522e-02   # N_{3,2}
  3  3     7.04209853e-01   # N_{3,3}
  3  4     7.07858232e-01   # N_{3,4}
  4  1    -6.00756341e-02   # N_{4,1}
  4  2     1.74682855e-01   # N_{4,2}
  4  3     6.89773341e-01   # N_{4,3}
  4  4    -7.00063966e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.75522995e-01   # U_{1,1}
  1  2    -2.19897443e-01   # U_{1,2}
  2  1     2.19897443e-01   # U_{2,1}
  2  2     9.75522995e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.91433764e-01   # V_{1,1}
  1  2    -1.30610460e-01   # V_{1,2}
  2  1     1.30610460e-01   # V_{2,1}
  2  2     9.91433764e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.53873897e-01   # F_{11}
  1  2     8.91065927e-01   # F_{12}
  2  1     8.91065927e-01   # F_{21}
  2  2    -4.53873897e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     8.11889847e-01   # F_{11}
  1  2     5.83810651e-01   # F_{12}
  2  1    -5.83810651e-01   # F_{21}
  2  2     8.11889847e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     3.36907653e-01   # F_{11}
  1  2     9.41537696e-01   # F_{12}
  2  1     9.41537696e-01   # F_{21}
  2  2    -3.36907653e-01   # F_{22}
Block gauge Q= 9.30213835e+02  # SM gauge couplings
     1     3.62334629e-01   # g'(Q)MSSM DRbar
     2     6.41902530e-01   # g(Q)MSSM DRbar
     3     1.05658763e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.30213835e+02  
  3  3     8.53303813e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.30213835e+02  
  3  3     4.90760239e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.30213835e+02  
  3  3     4.27547451e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.30213835e+02 # Higgs mixing parameters
     1     7.52810822e+02    # mu(Q)MSSM DRbar
     2     3.92129603e+01    # tan beta(Q)MSSM DRbar
     3     2.43913997e+02    # higgs vev(Q)MSSM DRbar
     4     5.49709575e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.30213835e+02  # MSSM DRbar SUSY breaking parameters
     1     2.32434304e+02      # M_1(Q)
     2     4.30638439e+02      # M_2(Q)
     3     1.22095050e+03      # M_3(Q)
    21    -1.31761946e+05      # mH1^2(Q)
    22    -5.58041559e+05      # mH2^2(Q)
    31     5.00868988e+02      # meL(Q)
    32     5.00730041e+02      # mmuL(Q)
    33     4.56304521e+02      # mtauL(Q)
    34     3.99322078e+02      # meR(Q)
    35     3.98969394e+02      # mmuR(Q)
    36     2.69819024e+02      # mtauR(Q)
    41     1.15646544e+03      # mqL1(Q)
    42     1.15642984e+03      # mqL2(Q)
    43     9.94480848e+02      # mqL3(Q)
    44     1.11628233e+03      # muR(Q)
    45     1.11627789e+03      # mcR(Q)
    46     8.65717845e+02      # mtR(Q)
    47     1.11145206e+03      # mdR(Q)
    48     1.11138154e+03      # msR(Q)
    49     1.01169757e+03      # mbR(Q)
Block au Q= 9.30213835e+02  
  1  1    -1.58553701e+03      # Au(Q)MSSM DRbar
  2  2    -1.58549871e+03      # Ac(Q)MSSM DRbar
  3  3    -1.10088022e+03      # At(Q)MSSM DRbar
Block ad Q= 9.30213835e+02  
  1  1    -1.83988432e+03      # Ad(Q)MSSM DRbar
  2  2    -1.83978678e+03      # As(Q)MSSM DRbar
  3  3    -1.54936409e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.30213835e+02  
  1  1    -6.45839496e+02      # Ae(Q)MSSM DRbar
  2  2    -6.45519158e+02      # Amu(Q)MSSM DRbar
  3  3    -5.38388435e+02      # Atau(Q)MSSM DRbar
