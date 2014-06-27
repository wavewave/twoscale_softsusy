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
     1    7.00000000e+02   # m0
     2    6.00000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.84442776e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.30306816e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03892150e+01   # MW
        25     1.18044336e+02   # h0
        35     8.07413862e+02   # H0
        36     8.07405578e+02   # A0
        37     8.11722812e+02   # H+
   1000021     1.38443719e+03   # ~g
   1000022     2.51958970e+02   # ~neutralino(1)
   1000023     4.79886527e+02   # ~neutralino(2)
   1000024     4.80022397e+02   # ~chargino(1)
   1000025    -8.00378628e+02   # ~neutralino(3)
   1000035     8.08687279e+02   # ~neutralino(4)
   1000037     8.09619121e+02   # ~chargino(2)
   1000001     1.41605872e+03   # ~d_L
   1000002     1.41397732e+03   # ~u_L
   1000003     1.41601732e+03   # ~s_L
   1000004     1.41393585e+03   # ~c_L
   1000005     1.17796190e+03   # ~b_1
   1000006     1.00406386e+03   # ~t_1
   1000011     8.05718035e+02   # ~e_L
   1000012     8.01474038e+02   # ~nue_L
   1000013     8.05519669e+02   # ~mu_L
   1000014     8.01276196e+02   # ~numu_L
   1000015     5.63302642e+02   # ~stau_1
   1000016     7.33671390e+02   # ~nu_tau_L
   2000001     1.37095588e+03   # ~d_R
   2000002     1.37464398e+03   # ~u_R
   2000003     1.37087451e+03   # ~s_R
   2000004     1.37463867e+03   # ~c_R
   2000005     1.25363511e+03   # ~b_2
   2000006     1.23008115e+03   # ~t_2
   2000011     7.35512239e+02   # ~e_R
   2000013     7.35077049e+02   # ~mu_R
   2000015     7.48886184e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.59483449e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97721926e-01   # N_{1,1}
  1  2    -7.90296468e-03   # N_{1,2}
  1  3     6.33754025e-02   # N_{1,3}
  1  4    -2.17269185e-02   # N_{1,4}
  2  1     1.94559193e-02   # N_{2,1}
  2  2     9.83846377e-01   # N_{2,2}
  2  3    -1.51734188e-01   # N_{2,3}
  2  4     9.29758590e-02   # N_{2,4}
  3  1    -2.90076553e-02   # N_{3,1}
  3  2     4.23546953e-02   # N_{3,2}
  3  3     7.04589626e-01   # N_{3,3}
  3  4     7.07755674e-01   # N_{3,4}
  4  1    -5.77146482e-02   # N_{4,1}
  4  2     1.73752496e-01   # N_{4,2}
  4  3     6.90299756e-01   # N_{4,3}
  4  4    -6.99975240e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.76349973e-01   # U_{1,1}
  1  2    -2.16196048e-01   # U_{1,2}
  2  1     2.16196048e-01   # U_{2,1}
  2  2     9.76349973e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.91117432e-01   # V_{1,1}
  1  2    -1.32989605e-01   # V_{1,2}
  2  1     1.32989605e-01   # V_{2,1}
  2  2     9.91117432e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.86661702e-01   # F_{11}
  1  2     9.22221626e-01   # F_{12}
  2  1     9.22221626e-01   # F_{21}
  2  2    -3.86661702e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.07905168e-01   # F_{11}
  1  2     4.19175626e-01   # F_{12}
  2  1    -4.19175626e-01   # F_{21}
  2  2     9.07905168e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     2.53754438e-01   # F_{11}
  1  2     9.67268673e-01   # F_{12}
  2  1     9.67268673e-01   # F_{21}
  2  2    -2.53754438e-01   # F_{22}
Block gauge Q= 1.07990047e+03  # SM gauge couplings
     1     3.62460504e-01   # g'(Q)MSSM DRbar
     2     6.41121253e-01   # g(Q)MSSM DRbar
     3     1.04982793e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.07990047e+03  
  3  3     8.49358378e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.07990047e+03  
  3  3     4.96030944e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.07990047e+03  
  3  3     4.23699153e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.07990047e+03 # Higgs mixing parameters
     1     7.95944394e+02    # mu(Q)MSSM DRbar
     2     3.91838294e+01    # tan beta(Q)MSSM DRbar
     3     2.43766103e+02    # higgs vev(Q)MSSM DRbar
     4     8.33216064e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.07990047e+03  # MSSM DRbar SUSY breaking parameters
     1     2.54876033e+02      # M_1(Q)
     2     4.70868872e+02      # M_2(Q)
     3     1.31978251e+03      # M_3(Q)
    21     3.00560917e+04      # mH1^2(Q)
    22    -6.19235176e+05      # mH2^2(Q)
    31     8.01543495e+02      # meL(Q)
    32     8.01345605e+02      # mmuL(Q)
    33     7.36149737e+02      # mtauL(Q)
    34     7.32531625e+02      # meR(Q)
    35     7.32095127e+02      # mmuR(Q)
    36     5.77375461e+02      # mtauR(Q)
    41     1.37567340e+03      # mqL1(Q)
    42     1.37563057e+03      # mqL2(Q)
    43     1.15995076e+03      # mqL3(Q)
    44     1.33677100e+03      # muR(Q)
    45     1.33676553e+03      # mcR(Q)
    46     9.99597965e+02      # mtR(Q)
    47     1.33211499e+03      # mdR(Q)
    48     1.33203103e+03      # msR(Q)
    49     1.20515185e+03      # mbR(Q)
Block au Q= 1.07990047e+03  
  1  1    -1.68092114e+03      # Au(Q)MSSM DRbar
  2  2    -1.68088127e+03      # Ac(Q)MSSM DRbar
  3  3    -1.17384138e+03      # At(Q)MSSM DRbar
Block ad Q= 1.07990047e+03  
  1  1    -1.94211328e+03      # Ad(Q)MSSM DRbar
  2  2    -1.94201175e+03      # As(Q)MSSM DRbar
  3  3    -1.63436368e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.07990047e+03  
  1  1    -6.62570195e+02      # Ae(Q)MSSM DRbar
  2  2    -6.62244111e+02      # Amu(Q)MSSM DRbar
  3  3    -5.54937904e+02      # Atau(Q)MSSM DRbar
