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
     1    1.08000000e+05   # lambda
     2    1.20000000e+05   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=3.58135393e-06
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04016700e+01   # MW
        25     1.13658782e+02   # h0
        35     5.48384096e+02   # H0
        36     5.48099574e+02   # A0
        37     5.54236921e+02   # H+
   1000021     1.01901589e+03   # ~g
   1000022     1.75659242e+02   # ~neutralino(1)
   1000023     3.24194004e+02   # ~neutralino(2)
   1000024     3.23652624e+02   # ~chargino(1)
   1000025    -4.29634154e+02   # ~neutralino(3)
   1000035     4.61877491e+02   # ~neutralino(4)
   1000037     4.61794466e+02   # ~chargino(2)
   1000039     3.07152000e-09   # ~gravitino
   1000001     1.21783609e+03   # ~d_L
   1000002     1.21541050e+03   # ~u_L
   1000003     1.21783444e+03   # ~s_L
   1000004     1.21540884e+03   # ~c_L
   1000005     1.15457455e+03   # ~b_1
   1000006     1.07656982e+03   # ~t_1
   1000011     3.79310672e+02   # ~e_L
   1000012     3.70629104e+02   # ~nue_L
   1000013     3.79309034e+02   # ~mu_L
   1000014     3.70627434e+02   # ~numu_L
   1000015     1.83227200e+02   # ~stau_1
   1000016     3.69891331e+02   # ~nu_tau_L
   2000001     1.16292505e+03   # ~d_R
   2000002     1.16640560e+03   # ~u_R
   2000003     1.16292275e+03   # ~s_R
   2000004     1.16640442e+03   # ~c_R
   2000005     1.17299783e+03   # ~b_2
   2000006     1.18361207e+03   # ~t_2
   2000011     1.88973657e+02   # ~e_R
   2000013     1.88967029e+02   # ~mu_R
   2000015     3.80111438e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.39904878e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.88401656e-01   # N_{1,1}
  1  2    -3.18395818e-02   # N_{1,2}
  1  3     1.34384941e-01   # N_{1,3}
  1  4    -6.31592860e-02   # N_{1,4}
  2  1     9.82643488e-02   # N_{2,1}
  2  2     8.72095812e-01   # N_{2,2}
  2  3    -3.76890474e-01   # N_{2,3}
  2  4     2.96220496e-01   # N_{2,4}
  3  1    -4.77037252e-02   # N_{3,1}
  3  2     6.70112700e-02   # N_{3,2}
  3  3     7.00097320e-01   # N_{3,3}
  3  4     7.09293724e-01   # N_{3,4}
  4  1    -1.05501844e-01   # N_{4,1}
  4  2     4.83678224e-01   # N_{4,2}
  4  3     5.91403416e-01   # N_{4,3}
  4  4    -6.36527089e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     8.37329505e-01   # U_{1,1}
  1  2    -5.46698546e-01   # U_{1,2}
  2  1     5.46698546e-01   # U_{2,1}
  2  2     8.37329505e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.02611275e-01   # V_{1,1}
  1  2    -4.30456601e-01   # V_{1,2}
  2  1     4.30456601e-01   # V_{2,1}
  2  2     9.02611275e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.39617162e-01   # F_{11}
  1  2     9.70867455e-01   # F_{12}
  2  1     9.70867455e-01   # F_{21}
  2  2    -2.39617162e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.09291390e-01   # F_{11}
  1  2     9.12403725e-01   # F_{12}
  2  1     9.12403725e-01   # F_{21}
  2  2    -4.09291390e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.01468264e-01   # F_{11}
  1  2     9.94838777e-01   # F_{12}
  2  1     9.94838777e-01   # F_{21}
  2  2    -1.01468264e-01   # F_{22}
Block gauge Q= 1.10540107e+03  # SM gauge couplings
     1     3.63292084e-01   # g'(Q)MSSM DRbar
     2     6.44004327e-01   # g(Q)MSSM DRbar
     3     1.05665991e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.10540107e+03  
  3  3     8.60566039e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.10540107e+03  
  3  3     2.02956148e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.10540107e+03  
  3  3     1.51292233e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.10540107e+03 # Higgs mixing parameters
     1     4.21053588e+02    # mu(Q)MSSM DRbar
     2     1.44806566e+01    # tan beta(Q)MSSM DRbar
     3     2.43457739e+02    # higgs vev(Q)MSSM DRbar
     4     3.32823510e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.10540107e+03  # MSSM DRbar SUSY breaking parameters
     1     1.82413650e+02      # M_1(Q)
     2     3.42670677e+02      # M_2(Q)
     3     9.27062325e+02      # M_3(Q)
    21     1.22018761e+05      # mH1^2(Q)
    22    -1.53570346e+05      # mH2^2(Q)
    31     3.72686921e+02      # meL(Q)
    32     3.72685256e+02      # mmuL(Q)
    33     3.72175771e+02      # mtauL(Q)
    34     1.78535428e+02      # meR(Q)
    35     1.78528408e+02      # mmuR(Q)
    36     1.76368196e+02      # mtauR(Q)
    41     1.18471497e+03      # mqL1(Q)
    42     1.18471326e+03      # mqL2(Q)
    43     1.14373751e+03      # mqL3(Q)
    44     1.13541919e+03      # muR(Q)
    45     1.13541797e+03      # mcR(Q)
    46     1.05157648e+03      # mtR(Q)
    47     1.13066309e+03      # mdR(Q)
    48     1.13066071e+03      # msR(Q)
    49     1.12602301e+03      # mbR(Q)
Block au Q= 1.10540107e+03  
  1  1    -2.82995400e+02      # Au(Q)MSSM DRbar
  2  2    -2.82994998e+02      # Ac(Q)MSSM DRbar
  3  3    -2.66576442e+02      # At(Q)MSSM DRbar
Block ad Q= 1.10540107e+03  
  1  1    -3.01191345e+02      # Ad(Q)MSSM DRbar
  2  2    -3.01190786e+02      # As(Q)MSSM DRbar
  3  3    -2.95010663e+02      # Ab(Q)MSSM DRbar
Block ae Q= 1.10540107e+03  
  1  1    -2.93107145e+01      # Ae(Q)MSSM DRbar
  2  2    -2.93104979e+01      # Amu(Q)MSSM DRbar
  3  3    -2.92442592e+01      # Atau(Q)MSSM DRbar
