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
     1    1.10000000e+03   # m0
     2    4.00000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.16983960e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=3.16534241e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03920291e+01   # MW
        25     1.16236245e+02   # h0
        35     8.61531996e+02   # H0
        36     8.61649039e+02   # A0
        37     8.65546923e+02   # H+
   1000021     9.89071440e+02   # ~g
   1000022     1.66665506e+02   # ~neutralino(1)
   1000023     3.18506514e+02   # ~neutralino(2)
   1000024     3.18604061e+02   # ~chargino(1)
   1000025    -5.72304372e+02   # ~neutralino(3)
   1000035     5.82855192e+02   # ~neutralino(4)
   1000037     5.84122259e+02   # ~chargino(2)
   1000001     1.36943706e+03   # ~d_L
   1000002     1.36725422e+03   # ~u_L
   1000003     1.36938881e+03   # ~s_L
   1000004     1.36720590e+03   # ~c_L
   1000005     1.06957228e+03   # ~b_1
   1000006     8.83941693e+02   # ~t_1
   1000011     1.12883145e+03   # ~e_L
   1000012     1.12568733e+03   # ~nue_L
   1000013     1.12854801e+03   # ~mu_L
   1000014     1.12540601e+03   # ~numu_L
   1000015     9.09362467e+02   # ~stau_1
   1000016     1.03381418e+03   # ~nu_tau_L
   2000001     1.35073733e+03   # ~d_R
   2000002     1.35164047e+03   # ~u_R
   2000003     1.35064514e+03   # ~s_R
   2000004     1.35163419e+03   # ~c_R
   2000005     1.19068071e+03   # ~b_2
   2000006     1.10339989e+03   # ~t_2
   2000011     1.10966060e+03   # ~e_R
   2000013     1.10908757e+03   # ~mu_R
   2000015     1.04054565e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.59715666e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.95557674e-01   # N_{1,1}
  1  2    -1.50008011e-02   # N_{1,2}
  1  3     8.85386078e-02   # N_{1,3}
  1  4    -2.82985696e-02   # N_{1,4}
  2  1     3.52671124e-02   # N_{2,1}
  2  2     9.73576593e-01   # N_{2,2}
  2  3    -1.95743426e-01   # N_{2,3}
  2  4     1.12202317e-01   # N_{2,4}
  3  1    -4.13841900e-02   # N_{3,1}
  3  2     6.10236050e-02   # N_{3,2}
  3  3     7.02059484e-01   # N_{3,3}
  3  4     7.08290865e-01   # N_{3,4}
  4  1    -7.68667532e-02   # N_{4,1}
  4  2     2.19544331e-01   # N_{4,2}
  4  3     6.78938810e-01   # N_{4,3}
  4  4    -6.96371942e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.60183686e-01   # U_{1,1}
  1  2    -2.79369449e-01   # U_{1,2}
  2  1     2.79369449e-01   # U_{2,1}
  2  2     9.60183686e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.87003209e-01   # V_{1,1}
  1  2    -1.60700546e-01   # V_{1,2}
  2  1     1.60700546e-01   # V_{2,1}
  2  2     9.87003209e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.17867623e-01   # F_{11}
  1  2     9.48135103e-01   # F_{12}
  2  1     9.48135103e-01   # F_{21}
  2  2    -3.17867623e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.81685114e-01   # F_{11}
  1  2     1.90510725e-01   # F_{12}
  2  1    -1.90510725e-01   # F_{21}
  2  2     9.81685114e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.65750759e-01   # F_{11}
  1  2     9.86167676e-01   # F_{12}
  2  1     9.86167676e-01   # F_{21}
  2  2    -1.65750759e-01   # F_{22}
Block gauge Q= 9.64465709e+02  # SM gauge couplings
     1     3.62031034e-01   # g'(Q)MSSM DRbar
     2     6.42228082e-01   # g(Q)MSSM DRbar
     3     1.05942698e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.64465709e+02  
  3  3     8.57737737e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.64465709e+02  
  3  3     5.17479727e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.64465709e+02  
  3  3     4.12655259e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.64465709e+02 # Higgs mixing parameters
     1     5.64441589e+02    # mu(Q)MSSM DRbar
     2     3.92312849e+01    # tan beta(Q)MSSM DRbar
     3     2.43738504e+02    # higgs vev(Q)MSSM DRbar
     4     8.94418843e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.64465709e+02  # MSSM DRbar SUSY breaking parameters
     1     1.68500662e+02      # M_1(Q)
     2     3.13075306e+02      # M_2(Q)
     3     8.93584723e+02      # M_3(Q)
    21     4.44470746e+05      # mH1^2(Q)
    22    -3.06145328e+05      # mH2^2(Q)
    31     1.12606067e+03      # meL(Q)
    32     1.12578019e+03      # mmuL(Q)
    33     1.03648267e+03      # mtauL(Q)
    34     1.10757474e+03      # meR(Q)
    35     1.10700147e+03      # mmuR(Q)
    36     9.14609003e+02      # mtauR(Q)
    41     1.34463281e+03      # mqL1(Q)
    42     1.34458375e+03      # mqL2(Q)
    43     1.05342923e+03      # mqL3(Q)
    44     1.32993416e+03      # muR(Q)
    45     1.32992778e+03      # mcR(Q)
    46     8.71832812e+02      # mtR(Q)
    47     1.32831404e+03      # mdR(Q)
    48     1.32822014e+03      # msR(Q)
    49     1.16645139e+03      # mbR(Q)
Block au Q= 9.64465709e+02  
  1  1    -1.25023379e+03      # Au(Q)MSSM DRbar
  2  2    -1.25020209e+03      # Ac(Q)MSSM DRbar
  3  3    -8.39781750e+02      # At(Q)MSSM DRbar
Block ad Q= 9.64465709e+02  
  1  1    -1.45064481e+03      # Ad(Q)MSSM DRbar
  2  2    -1.45056409e+03      # As(Q)MSSM DRbar
  3  3    -1.19477348e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.64465709e+02  
  1  1    -5.72726479e+02      # Ae(Q)MSSM DRbar
  2  2    -5.72428072e+02      # Amu(Q)MSSM DRbar
  3  3    -4.79649248e+02      # Atau(Q)MSSM DRbar
