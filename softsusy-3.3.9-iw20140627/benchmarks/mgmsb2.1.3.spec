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
     1    9.00000000e+04   # lambda
     2    1.00000000e+05   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=4.58517312e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04035161e+01   # MW
        25     1.12333753e+02   # h0
        35     4.62224635e+02   # H0
        36     4.61890783e+02   # A0
        37     4.69151330e+02   # H+
   1000021     8.64571985e+02   # ~g
   1000022     1.45061602e+02   # ~neutralino(1)
   1000023     2.65580926e+02   # ~neutralino(2)
   1000024     2.64825782e+02   # ~chargino(1)
   1000025    -3.68262807e+02   # ~neutralino(3)
   1000035     4.01173558e+02   # ~neutralino(4)
   1000037     4.01217244e+02   # ~chargino(2)
   1000039     2.13300000e-09   # ~gravitino
   1000001     1.03056741e+03   # ~d_L
   1000002     1.02767022e+03   # ~u_L
   1000003     1.03056600e+03   # ~s_L
   1000004     1.02766881e+03   # ~c_L
   1000005     9.76792839e+02   # ~b_1
   1000006     9.13291428e+02   # ~t_1
   1000011     3.17799689e+02   # ~e_L
   1000012     3.07429563e+02   # ~nue_L
   1000013     3.17798328e+02   # ~mu_L
   1000014     3.07428161e+02   # ~numu_L
   1000015     1.52910784e+02   # ~stau_1
   1000016     3.06808058e+02   # ~nu_tau_L
   2000001     9.85001532e+02   # ~d_R
   2000002     9.87536529e+02   # ~u_R
   2000003     9.84999577e+02   # ~s_R
   2000004     9.87535529e+02   # ~c_R
   2000005     9.93416453e+02   # ~b_2
   2000006     1.00616438e+03   # ~t_2
   2000011     1.58936992e+02   # ~e_R
   2000013     1.58931503e+02   # ~mu_R
   2000015     3.19080256e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.59178039e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.83916723e-01   # N_{1,1}
  1  2    -4.32827635e-02   # N_{1,2}
  1  3     1.57617674e-01   # N_{1,3}
  1  4    -7.20496631e-02   # N_{1,4}
  2  1     1.21894012e-01   # N_{2,1}
  2  2     8.64319902e-01   # N_{2,2}
  2  3    -3.88782562e-01   # N_{2,3}
  2  4     2.94857723e-01   # N_{2,4}
  3  1    -5.62221675e-02   # N_{3,1}
  3  2     7.93621044e-02   # N_{3,2}
  3  3     6.97353540e-01   # N_{3,3}
  3  4     7.10097715e-01   # N_{3,4}
  4  1    -1.17850756e-01   # N_{4,1}
  4  2     4.94751823e-01   # N_{4,2}
  4  3     5.81122043e-01   # N_{4,3}
  4  4    -6.35318034e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     8.23293324e-01   # U_{1,1}
  1  2    -5.67616158e-01   # U_{1,2}
  2  1     5.67616158e-01   # U_{2,1}
  2  2     8.23293324e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.02286555e-01   # V_{1,1}
  1  2    -4.31136838e-01   # V_{1,2}
  2  1     4.31136838e-01   # V_{2,1}
  2  2     9.02286555e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.77262009e-01   # F_{11}
  1  2     9.60794348e-01   # F_{12}
  2  1     9.60794348e-01   # F_{21}
  2  2    -2.77262009e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.75885297e-01   # F_{11}
  1  2     8.79507353e-01   # F_{12}
  2  1     8.79507353e-01   # F_{21}
  2  2    -4.75885297e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.22958597e-01   # F_{11}
  1  2     9.92411801e-01   # F_{12}
  2  1     9.92411801e-01   # F_{21}
  2  2    -1.22958597e-01   # F_{22}
Block gauge Q= 9.37893983e+02  # SM gauge couplings
     1     3.62940589e-01   # g'(Q)MSSM DRbar
     2     6.44931693e-01   # g(Q)MSSM DRbar
     3     1.06542074e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.37893983e+02  
  3  3     8.66418651e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.37893983e+02  
  3  3     2.04715633e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.37893983e+02  
  3  3     1.51454053e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.37893983e+02 # Higgs mixing parameters
     1     3.59448962e+02    # mu(Q)MSSM DRbar
     2     1.45087755e+01    # tan beta(Q)MSSM DRbar
     3     2.43650306e+02    # higgs vev(Q)MSSM DRbar
     4     2.36650718e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.37893983e+02  # MSSM DRbar SUSY breaking parameters
     1     1.51689604e+02      # M_1(Q)
     2     2.86308746e+02      # M_2(Q)
     3     7.85300395e+02      # M_3(Q)
    21     8.47389571e+04      # mH1^2(Q)
    22    -1.13696802e+05      # mH2^2(Q)
    31     3.11339118e+02      # meL(Q)
    32     3.11337730e+02      # mmuL(Q)
    33     3.10913691e+02      # mtauL(Q)
    34     1.48353914e+02      # meR(Q)
    35     1.48348028e+02      # mmuR(Q)
    36     1.46540306e+02      # mtauR(Q)
    41     1.00167354e+03      # mqL1(Q)
    42     1.00167208e+03      # mqL2(Q)
    43     9.66802607e+02      # mqL3(Q)
    44     9.60964095e+02      # muR(Q)
    45     9.60963059e+02      # mcR(Q)
    46     8.89691741e+02      # mtR(Q)
    47     9.57082721e+02      # mdR(Q)
    48     9.57080691e+02      # msR(Q)
    49     9.53122810e+02      # mbR(Q)
Block au Q= 9.37893983e+02  
  1  1    -2.41594329e+02      # Au(Q)MSSM DRbar
  2  2    -2.41593985e+02      # Ac(Q)MSSM DRbar
  3  3    -2.27470304e+02      # At(Q)MSSM DRbar
Block ad Q= 9.37893983e+02  
  1  1    -2.57312702e+02      # Ad(Q)MSSM DRbar
  2  2    -2.57312220e+02      # As(Q)MSSM DRbar
  3  3    -2.51992391e+02      # Ab(Q)MSSM DRbar
Block ae Q= 9.37893983e+02  
  1  1    -2.43961763e+01      # Ae(Q)MSSM DRbar
  2  2    -2.43959958e+01      # Amu(Q)MSSM DRbar
  3  3    -2.43408983e+01      # Atau(Q)MSSM DRbar
