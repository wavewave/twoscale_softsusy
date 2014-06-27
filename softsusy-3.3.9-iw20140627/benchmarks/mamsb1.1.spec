# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    3   # amsb
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
     2    4.00000000e+04   # m3/2
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.64784710e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=3.40036780e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04004781e+01   # MW
        25     1.12475812e+02   # h0
        35     7.25678870e+02   # H0
        36     7.25453182e+02   # A0
        37     7.30106589e+02   # H+
   1000021    -8.88554595e+02   # ~g
   1000022     1.30622295e+02   # ~neutralino(1)
   1000023     3.63264100e+02   # ~neutralino(2)
   1000024     1.30804557e+02   # ~chargino(1)
   1000025    -7.02189049e+02   # ~neutralino(3)
   1000035     7.10002481e+02   # ~neutralino(4)
   1000037     7.08658535e+02   # ~chargino(2)
   1000039     4.00000000e+04   # ~gravitino
   1000001     8.80778948e+02   # ~d_L
   1000002     8.77360478e+02   # ~u_L
   1000003     8.80773692e+02   # ~s_L
   1000004     8.77355196e+02   # ~c_L
   1000005     7.66903779e+02   # ~b_1
   1000006     6.31832899e+02   # ~t_1
   1000011     2.59783242e+02   # ~e_L
   1000012     2.47229296e+02   # ~nue_L
   1000013     2.59771900e+02   # ~mu_L
   1000014     2.47217424e+02   # ~numu_L
   1000015     2.25925056e+02   # ~stau_1
   1000016     2.43593236e+02   # ~nu_tau_L
   2000001     8.89128060e+02   # ~d_R
   2000002     8.82344979e+02   # ~u_R
   2000003     8.89122390e+02   # ~s_R
   2000004     8.82340173e+02   # ~c_R
   2000005     8.77492122e+02   # ~b_2
   2000006     8.12731542e+02   # ~t_2
   2000011     2.52006890e+02   # ~e_R
   2000013     2.51983481e+02   # ~mu_R
   2000015     2.73092625e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.07945421e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1    -8.12328325e-03   # N_{1,1}
  1  2     9.92465905e-01   # N_{1,2}
  1  3    -1.17815803e-01   # N_{1,3}
  1  4     3.26324464e-02   # N_{1,4}
  2  1     9.94606465e-01   # N_{2,1}
  2  2     2.02368568e-02   # N_{2,2}
  2  3     8.75455498e-02   # N_{2,3}
  2  4    -5.18095103e-02   # N_{2,4}
  3  1    -2.62795559e-02   # N_{3,1}
  3  2     6.00278287e-02   # N_{3,2}
  3  3     7.03490453e-01   # N_{3,3}
  3  4     7.07677347e-01   # N_{3,4}
  4  1    -1.00006881e-01   # N_{4,1}
  4  2     1.04874006e-01   # N_{4,2}
  4  3     6.95382194e-01   # N_{4,3}
  4  4    -7.03877596e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.86297745e-01   # U_{1,1}
  1  2    -1.64975026e-01   # U_{1,2}
  2  1     1.64975026e-01   # U_{2,1}
  2  2     9.86297745e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.98948779e-01   # V_{1,1}
  1  2    -4.58403310e-02   # V_{1,2}
  2  1     4.58403310e-02   # V_{2,1}
  2  2     9.98948779e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1    -4.53187552e-01   # F_{11}
  1  2     8.91415191e-01   # F_{12}
  2  1     8.91415191e-01   # F_{21}
  2  2     4.53187552e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.97280717e-01   # F_{11}
  1  2     7.36964842e-02   # F_{12}
  2  1    -7.36964842e-02   # F_{21}
  2  2     9.97280717e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     6.14220014e-01   # F_{11}
  1  2     7.89134827e-01   # F_{12}
  2  1     7.89134827e-01   # F_{21}
  2  2    -6.14220014e-01   # F_{22}
Block gauge Q= 6.89368699e+02  # SM gauge couplings
     1     3.61743628e-01   # g'(Q)MSSM DRbar
     2     6.46140352e-01   # g(Q)MSSM DRbar
     3     1.07367129e+00   # g3(Q)MSSM DRbar
Block yu Q= 6.89368699e+02  
  3  3     8.70671659e-01   # Yt(Q)MSSM DRbar
Block yd Q= 6.89368699e+02  
  3  3     1.50880465e-01   # Yb(Q)MSSM DRbar
Block ye Q= 6.89368699e+02  
  3  3     9.94849635e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 6.89368699e+02 # Higgs mixing parameters
     1     7.00123801e+02    # mu(Q)MSSM DRbar
     2     9.70362151e+00    # tan beta(Q)MSSM DRbar
     3     2.44684700e+02    # higgs vev(Q)MSSM DRbar
     4     5.26199931e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 6.89368699e+02  # MSSM DRbar SUSY breaking parameters
     1     3.71695222e+02      # M_1(Q)
     2     1.28383161e+02      # M_2(Q)
     3    -8.44098129e+02      # M_3(Q)
    21     3.01064158e+04      # mH1^2(Q)
    22    -4.82300627e+05      # mH2^2(Q)
    31     2.54921618e+02      # meL(Q)
    32     2.54910085e+02      # mmuL(Q)
    33     2.51532463e+02      # mtauL(Q)
    34     2.44771522e+02      # meR(Q)
    35     2.44747489e+02      # mmuR(Q)
    36     2.37652575e+02      # mtauR(Q)
    41     8.52464933e+02      # mqL1(Q)
    42     8.52459497e+02      # mqL2(Q)
    43     7.40265223e+02      # mqL3(Q)
    44     8.57466874e+02      # muR(Q)
    45     8.57461911e+02      # mcR(Q)
    46     6.28464661e+02      # mtR(Q)
    47     8.63409067e+02      # mdR(Q)
    48     8.63403197e+02      # msR(Q)
    49     8.51106626e+02      # mbR(Q)
Block au Q= 6.89368699e+02  
  1  1     1.32582451e+03      # Au(Q)MSSM DRbar
  2  2     1.32581339e+03      # Ac(Q)MSSM DRbar
  3  3     7.52882100e+02      # At(Q)MSSM DRbar
Block ad Q= 6.89368699e+02  
  1  1     1.87473621e+03      # Ad(Q)MSSM DRbar
  2  2     1.87472588e+03      # As(Q)MSSM DRbar
  3  3     1.66978225e+03      # Ab(Q)MSSM DRbar
Block ae Q= 6.89368699e+02  
  1  1     3.92882702e+02      # Ae(Q)MSSM DRbar
  2  2     3.92857175e+02      # Amu(Q)MSSM DRbar
  3  3     3.85348204e+02      # Atau(Q)MSSM DRbar
