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
     3    1.00000000e+01   # tanb
     4    1.00000000e+00   # sign(mu)
     1    1.50000000e+02   # m0
     2    6.00000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.76385156e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.11817042e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03945125e+01   # MW
        25     1.16088741e+02   # h0
        35     8.48768796e+02   # H0
        36     8.48536298e+02   # A0
        37     8.52558101e+02   # H+
   1000021     1.35667047e+03   # ~g
   1000022     2.47689345e+02   # ~neutralino(1)
   1000023     4.68638073e+02   # ~neutralino(2)
   1000024     4.68700756e+02   # ~chargino(1)
   1000025    -7.45754622e+02   # ~neutralino(3)
   1000035     7.58165006e+02   # ~neutralino(4)
   1000037     7.58410838e+02   # ~chargino(2)
   1000001     1.24670826e+03   # ~d_L
   1000002     1.24433099e+03   # ~u_L
   1000003     1.24670525e+03   # ~s_L
   1000004     1.24432796e+03   # ~c_L
   1000005     1.14234951e+03   # ~b_1
   1000006     9.58224816e+02   # ~t_1
   1000011     4.31793892e+02   # ~e_L
   1000012     4.24322678e+02   # ~nue_L
   1000013     4.31790005e+02   # ~mu_L
   1000014     4.24318738e+02   # ~numu_L
   1000015     2.66973771e+02   # ~stau_1
   1000016     4.22941653e+02   # ~nu_tau_L
   2000001     1.19293708e+03   # ~d_R
   2000002     1.19736460e+03   # ~u_R
   2000003     1.19293393e+03   # ~s_R
   2000004     1.19736137e+03   # ~c_R
   2000005     1.18847644e+03   # ~b_2
   2000006     1.18197285e+03   # ~t_2
   2000011     2.74085255e+02   # ~e_R
   2000013     2.74072873e+02   # ~mu_R
   2000015     4.32300046e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05966381e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96965959e-01   # N_{1,1}
  1  2    -1.26756368e-02   # N_{1,2}
  1  3     7.06821416e-02   # N_{1,3}
  1  4    -3.00373201e-02   # N_{1,4}
  2  1     2.86670540e-02   # N_{2,1}
  2  2     9.76133228e-01   # N_{2,2}
  2  3    -1.77584204e-01   # N_{2,3}
  2  4     1.21679792e-01   # N_{2,4}
  3  1    -2.80976370e-02   # N_{3,1}
  3  2     4.07360572e-02   # N_{3,2}
  3  3     7.04489000e-01   # N_{3,3}
  3  4     7.07987532e-01   # N_{3,4}
  4  1    -6.66903315e-02   # N_{4,1}
  4  2     2.12940891e-01   # N_{4,2}
  4  3     6.83493331e-01   # N_{4,3}
  4  4    -6.95014707e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.67358068e-01   # U_{1,1}
  1  2    -2.53413434e-01   # U_{1,2}
  2  1     2.53413434e-01   # U_{2,1}
  2  2     9.67358068e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.84729856e-01   # V_{1,1}
  1  2    -1.74089376e-01   # V_{1,2}
  2  1     1.74089376e-01   # V_{2,1}
  2  2     9.84729856e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.84613409e-01   # F_{11}
  1  2     9.23077746e-01   # F_{12}
  2  1     9.23077746e-01   # F_{21}
  2  2    -3.84613409e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.81374273e-01   # F_{11}
  1  2     1.92105533e-01   # F_{12}
  2  1    -1.92105533e-01   # F_{21}
  2  2     9.81374273e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.18046035e-01   # F_{11}
  1  2     9.93008124e-01   # F_{12}
  2  1     9.93008124e-01   # F_{21}
  2  2    -1.18046035e-01   # F_{22}
Block gauge Q= 1.03281018e+03  # SM gauge couplings
     1     3.62766869e-01   # g'(Q)MSSM DRbar
     2     6.42082770e-01   # g(Q)MSSM DRbar
     3     1.05212450e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.03281018e+03  
  3  3     8.55437329e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.03281018e+03  
  3  3     1.34162965e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.03281018e+03  
  3  3     1.00398894e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.03281018e+03 # Higgs mixing parameters
     1     7.40337031e+02    # mu(Q)MSSM DRbar
     2     9.65379784e+00    # tan beta(Q)MSSM DRbar
     3     2.43919739e+02    # higgs vev(Q)MSSM DRbar
     4     7.46252091e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.03281018e+03  # MSSM DRbar SUSY breaking parameters
     1     2.53207001e+02      # M_1(Q)
     2     4.67936400e+02      # M_2(Q)
     3     1.31909530e+03      # M_3(Q)
    21     1.56949245e+05      # mH1^2(Q)
    22    -5.28306170e+05      # mH2^2(Q)
    31     4.23672759e+02      # meL(Q)
    32     4.23668817e+02      # mmuL(Q)
    33     4.22477606e+02      # mtauL(Q)
    34     2.66158977e+02      # meR(Q)
    35     2.66146212e+02      # mmuR(Q)
    36     2.62265732e+02      # mtauR(Q)
    41     1.20403493e+03      # mqL1(Q)
    42     1.20403185e+03      # mqL2(Q)
    43     1.11028522e+03      # mqL3(Q)
    44     1.15796862e+03      # muR(Q)
    45     1.15796534e+03      # mcR(Q)
    46     9.54084774e+02      # mtR(Q)
    47     1.15234620e+03      # mdR(Q)
    48     1.15234299e+03      # msR(Q)
    49     1.14650292e+03      # mbR(Q)
Block au Q= 1.03281018e+03  
  1  1    -1.34291479e+03      # Au(Q)MSSM DRbar
  2  2    -1.34290881e+03      # Ac(Q)MSSM DRbar
  3  3    -1.03903287e+03      # At(Q)MSSM DRbar
Block ad Q= 1.03281018e+03  
  1  1    -1.63958177e+03      # Ad(Q)MSSM DRbar
  2  2    -1.63957624e+03      # As(Q)MSSM DRbar
  3  3    -1.53291556e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.03281018e+03  
  1  1    -3.56259931e+02      # Ae(Q)MSSM DRbar
  2  2    -3.56253601e+02      # Amu(Q)MSSM DRbar
  3  3    -3.54341103e+02      # Atau(Q)MSSM DRbar
