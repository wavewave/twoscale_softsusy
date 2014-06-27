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
     1    3.00000000e+02   # m0
     2    4.50000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.02230641e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=5.21264817e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03968306e+01   # MW
        25     1.14250072e+02   # h0
        35     7.06800422e+02   # H0
        36     7.06476908e+02   # A0
        37     7.11367315e+02   # H+
   1000021     1.04852564e+03   # ~g
   1000022     1.83393476e+02   # ~neutralino(1)
   1000023     3.46113331e+02   # ~neutralino(2)
   1000024     3.46084596e+02   # ~chargino(1)
   1000025    -5.79635234e+02   # ~neutralino(3)
   1000035     5.94171013e+02   # ~neutralino(4)
   1000037     5.94535211e+02   # ~chargino(2)
   1000001     9.96863834e+02   # ~d_L
   1000002     9.93856673e+02   # ~u_L
   1000003     9.96861239e+02   # ~s_L
   1000004     9.93854068e+02   # ~c_L
   1000005     9.05366777e+02   # ~b_1
   1000006     7.47233098e+02   # ~t_1
   1000011     4.27902330e+02   # ~e_L
   1000012     4.20330276e+02   # ~nue_L
   1000013     4.27897521e+02   # ~mu_L
   1000014     4.20325406e+02   # ~numu_L
   1000015     3.40314911e+02   # ~stau_1
   1000016     4.18756693e+02   # ~nu_tau_L
   2000001     9.58873225e+02   # ~d_R
   2000002     9.61497965e+02   # ~u_R
   2000003     9.58870536e+02   # ~s_R
   2000004     9.61495186e+02   # ~c_R
   2000005     9.55091133e+02   # ~b_2
   2000006     9.49938943e+02   # ~t_2
   2000011     3.46576745e+02   # ~e_R
   2000013     3.46564769e+02   # ~mu_R
   2000015     4.28318324e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.06820158e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.94898182e-01   # N_{1,1}
  1  2    -2.10736386e-02   # N_{1,2}
  1  3     9.12656352e-02   # N_{1,3}
  1  4    -3.74712420e-02   # N_{1,4}
  2  1     4.51567045e-02   # N_{2,1}
  2  2     9.66232966e-01   # N_{2,2}
  2  3    -2.11865376e-01   # N_{2,3}
  2  4     1.39527019e-01   # N_{2,4}
  3  1    -3.66384016e-02   # N_{3,1}
  3  2     5.34659438e-02   # N_{3,2}
  3  3     7.02663078e-01   # N_{3,3}
  3  4     7.08564478e-01   # N_{3,4}
  4  1    -8.24385101e-02   # N_{4,1}
  4  2     2.51179516e-01   # N_{4,2}
  4  3     6.73088586e-01   # N_{4,3}
  4  4    -6.90698558e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.52608737e-01   # U_{1,1}
  1  2    -3.04198280e-01   # U_{1,2}
  2  1     3.04198280e-01   # U_{2,1}
  2  2     9.52608737e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.79557115e-01   # V_{1,1}
  1  2    -2.01166245e-01   # V_{1,2}
  2  1     2.01166245e-01   # V_{2,1}
  2  2     9.79557115e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.24992426e-01   # F_{11}
  1  2     9.05196906e-01   # F_{12}
  2  1     9.05196906e-01   # F_{21}
  2  2    -4.24992426e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.84456190e-01   # F_{11}
  1  2     1.75630321e-01   # F_{12}
  2  1    -1.75630321e-01   # F_{21}
  2  2     9.84456190e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.57094071e-01   # F_{11}
  1  2     9.87583643e-01   # F_{12}
  2  1     9.87583643e-01   # F_{21}
  2  2    -1.57094071e-01   # F_{22}
Block gauge Q= 8.16308063e+02  # SM gauge couplings
     1     3.62094177e-01   # g'(Q)MSSM DRbar
     2     6.43255453e-01   # g(Q)MSSM DRbar
     3     1.06501876e+00   # g3(Q)MSSM DRbar
Block yu Q= 8.16308063e+02  
  3  3     8.64179136e-01   # Yt(Q)MSSM DRbar
Block yd Q= 8.16308063e+02  
  3  3     1.36027165e-01   # Yb(Q)MSSM DRbar
Block ye Q= 8.16308063e+02  
  3  3     1.00473583e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 8.16308063e+02 # Higgs mixing parameters
     1     5.73787717e+02    # mu(Q)MSSM DRbar
     2     9.68146299e+00    # tan beta(Q)MSSM DRbar
     3     2.44182794e+02    # higgs vev(Q)MSSM DRbar
     4     5.16298122e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 8.16308063e+02  # MSSM DRbar SUSY breaking parameters
     1     1.87573068e+02      # M_1(Q)
     2     3.48988558e+02      # M_2(Q)
     3     1.00878370e+03      # M_3(Q)
    21     1.62329943e+05      # mH1^2(Q)
    22    -3.18361308e+05      # mH2^2(Q)
    31     4.22482193e+02      # meL(Q)
    32     4.22477332e+02      # mmuL(Q)
    33     4.21013837e+02      # mtauL(Q)
    34     3.42012303e+02      # meR(Q)
    35     3.42000171e+02      # mmuR(Q)
    36     3.38334188e+02      # mtauR(Q)
    41     9.62551116e+02      # mqL1(Q)
    42     9.62548458e+02      # mqL2(Q)
    43     8.78997623e+02      # mqL3(Q)
    44     9.30280343e+02      # muR(Q)
    45     9.30277512e+02      # mcR(Q)
    46     7.48587857e+02      # mtR(Q)
    47     9.26410736e+02      # mdR(Q)
    48     9.26407992e+02      # msR(Q)
    49     9.21348537e+02      # mbR(Q)
Block au Q= 8.16308063e+02  
  1  1    -1.03670530e+03      # Au(Q)MSSM DRbar
  2  2    -1.03670063e+03      # Ac(Q)MSSM DRbar
  3  3    -7.98466902e+02      # At(Q)MSSM DRbar
Block ad Q= 8.16308063e+02  
  1  1    -1.27001386e+03      # Ad(Q)MSSM DRbar
  2  2    -1.27000953e+03      # As(Q)MSSM DRbar
  3  3    -1.18634927e+03      # Ab(Q)MSSM DRbar
Block ae Q= 8.16308063e+02  
  1  1    -2.70595286e+02      # Ae(Q)MSSM DRbar
  2  2    -2.70590395e+02      # Amu(Q)MSSM DRbar
  3  3    -2.69119754e+02      # Atau(Q)MSSM DRbar
