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
     1    6.00000000e+02   # m0
     2    5.00000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.95484156e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=6.15435178e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03905663e+01   # MW
        25     1.17110152e+02   # h0
        35     6.90304464e+02   # H0
        36     6.90308950e+02   # A0
        37     6.95366435e+02   # H+
   1000021     1.17095710e+03   # ~g
   1000022     2.08190367e+02   # ~neutralino(1)
   1000023     3.97021380e+02   # ~neutralino(2)
   1000024     3.97146431e+02   # ~chargino(1)
   1000025    -6.97378960e+02   # ~neutralino(3)
   1000035     7.05939710e+02   # ~neutralino(4)
   1000037     7.07079953e+02   # ~chargino(2)
   1000001     1.20234556e+03   # ~d_L
   1000002     1.19986762e+03   # ~u_L
   1000003     1.20230845e+03   # ~s_L
   1000004     1.19983042e+03   # ~c_L
   1000005     9.90190321e+02   # ~b_1
   1000006     8.35836542e+02   # ~t_1
   1000011     6.86803181e+02   # ~e_L
   1000012     6.81870215e+02   # ~nue_L
   1000013     6.86623557e+02   # ~mu_L
   1000014     6.81690634e+02   # ~numu_L
   1000015     4.70489727e+02   # ~stau_1
   1000016     6.20896363e+02   # ~nu_tau_L
   2000001     1.16514057e+03   # ~d_R
   2000002     1.16787315e+03   # ~u_R
   2000003     1.16506770e+03   # ~s_R
   2000004     1.16786843e+03   # ~c_R
   2000005     1.06486201e+03   # ~b_2
   2000006     1.05016644e+03   # ~t_2
   2000011     6.29304529e+02   # ~e_R
   2000013     6.28911751e+02   # ~mu_R
   2000015     6.38898567e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.60195374e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97049736e-01   # N_{1,1}
  1  2    -1.03720243e-02   # N_{1,2}
  1  3     7.22823043e-02   # N_{1,3}
  1  4    -2.36540189e-02   # N_{1,4}
  2  1     2.44496579e-02   # N_{2,1}
  2  2     9.81284428e-01   # N_{2,2}
  2  3    -1.64907886e-01   # N_{2,3}
  2  4     9.63767292e-02   # N_{2,4}
  3  1    -3.37038527e-02   # N_{3,1}
  3  2     4.95651300e-02   # N_{3,2}
  3  3     7.03696398e-01   # N_{3,3}
  3  4     7.07968027e-01   # N_{3,4}
  4  1    -6.44832347e-02   # N_{4,1}
  4  2     1.85786408e-01   # N_{4,2}
  4  3     6.87307818e-01   # N_{4,3}
  4  4    -6.99237646e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.71990340e-01   # U_{1,1}
  1  2    -2.35020806e-01   # U_{1,2}
  2  1     2.35020806e-01   # U_{2,1}
  2  2     9.71990340e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.90449001e-01   # V_{1,1}
  1  2    -1.37879574e-01   # V_{1,2}
  2  1     1.37879574e-01   # V_{2,1}
  2  2     9.90449001e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.28731082e-01   # F_{11}
  1  2     9.03432156e-01   # F_{12}
  2  1     9.03432156e-01   # F_{21}
  2  2    -4.28731082e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     8.95882485e-01   # F_{11}
  1  2     4.44291091e-01   # F_{12}
  2  1    -4.44291091e-01   # F_{21}
  2  2     8.95882485e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     2.91479005e-01   # F_{11}
  1  2     9.56577226e-01   # F_{12}
  2  1     9.56577226e-01   # F_{21}
  2  2    -2.91479005e-01   # F_{22}
Block gauge Q= 9.09330047e+02  # SM gauge couplings
     1     3.62083238e-01   # g'(Q)MSSM DRbar
     2     6.41966865e-01   # g(Q)MSSM DRbar
     3     1.05866877e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.09330047e+02  
  3  3     8.55106943e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.09330047e+02  
  3  3     4.96923620e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.09330047e+02  
  3  3     4.23632990e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.09330047e+02 # Higgs mixing parameters
     1     6.92874164e+02    # mu(Q)MSSM DRbar
     2     3.92246833e+01    # tan beta(Q)MSSM DRbar
     3     2.43967083e+02    # higgs vev(Q)MSSM DRbar
     4     6.09295735e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.09330047e+02  # MSSM DRbar SUSY breaking parameters
     1     2.10820269e+02      # M_1(Q)
     2     3.91199545e+02      # M_2(Q)
     3     1.11446202e+03      # M_3(Q)
    21     6.23650595e+03      # mH1^2(Q)
    22    -4.71933976e+05      # mH2^2(Q)
    31     6.83025339e+02      # meL(Q)
    32     6.82846000e+02      # mmuL(Q)
    33     6.24231034e+02      # mtauL(Q)
    34     6.26405332e+02      # meR(Q)
    35     6.26011157e+02      # mmuR(Q)
    36     4.86861937e+02      # mtauR(Q)
    41     1.16778472e+03      # mqL1(Q)
    42     1.16774630e+03      # mqL2(Q)
    43     9.77869085e+02      # mqL3(Q)
    44     1.13585014e+03      # muR(Q)
    45     1.13584528e+03      # mcR(Q)
    46     8.39352996e+02      # mtR(Q)
    47     1.13206955e+03      # mdR(Q)
    48     1.13199426e+03      # msR(Q)
    49     1.01996473e+03      # mbR(Q)
Block au Q= 9.09330047e+02  
  1  1    -1.47786168e+03      # Au(Q)MSSM DRbar
  2  2    -1.47782544e+03      # Ac(Q)MSSM DRbar
  3  3    -1.01691192e+03      # At(Q)MSSM DRbar
Block ad Q= 9.09330047e+02  
  1  1    -1.71621011e+03      # Ad(Q)MSSM DRbar
  2  2    -1.71611780e+03      # As(Q)MSSM DRbar
  3  3    -1.43757698e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.09330047e+02  
  1  1    -6.22555538e+02      # Ae(Q)MSSM DRbar
  2  2    -6.22242059e+02      # Amu(Q)MSSM DRbar
  3  3    -5.19361484e+02      # Atau(Q)MSSM DRbar
