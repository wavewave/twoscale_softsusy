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
     1    4.00000000e+02   # m0
     2    6.00000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.83946813e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.10694508e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03937842e+01   # MW
        25     1.16164156e+02   # h0
        35     9.23280439e+02   # H0
        36     9.22978828e+02   # A0
        37     9.26811592e+02   # H+
   1000021     1.36684199e+03   # ~g
   1000022     2.48797067e+02   # ~neutralino(1)
   1000023     4.70791624e+02   # ~neutralino(2)
   1000024     4.70853223e+02   # ~chargino(1)
   1000025    -7.45330819e+02   # ~neutralino(3)
   1000035     7.57877114e+02   # ~neutralino(4)
   1000037     7.58103059e+02   # ~chargino(2)
   1000001     1.29906510e+03   # ~d_L
   1000002     1.29679723e+03   # ~u_L
   1000003     1.29906174e+03   # ~s_L
   1000004     1.29679386e+03   # ~c_L
   1000005     1.18104749e+03   # ~b_1
   1000006     9.85308977e+02   # ~t_1
   1000011     5.67741477e+02   # ~e_L
   1000012     5.61991971e+02   # ~nue_L
   1000013     5.67735156e+02   # ~mu_L
   1000014     5.61985624e+02   # ~numu_L
   1000015     4.53532753e+02   # ~stau_1
   1000016     5.59924300e+02   # ~nu_tau_L
   2000001     1.24817990e+03   # ~d_R
   2000002     1.25239707e+03   # ~u_R
   2000003     1.24817644e+03   # ~s_R
   2000004     1.25239346e+03   # ~c_R
   2000005     1.24251656e+03   # ~b_2
   2000006     1.21665211e+03   # ~t_2
   2000011     4.60309679e+02   # ~e_R
   2000013     4.60293972e+02   # ~mu_R
   2000015     5.67110599e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05593944e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96942392e-01   # N_{1,1}
  1  2    -1.26899146e-02   # N_{1,2}
  1  3     7.09250917e-02   # N_{1,3}
  1  4    -3.02401171e-02   # N_{1,4}
  2  1     2.88567064e-02   # N_{2,1}
  2  2     9.75788675e-01   # N_{2,2}
  2  3    -1.78670386e-01   # N_{2,3}
  2  4     1.22803276e-01   # N_{2,4}
  3  1    -2.81259705e-02   # N_{3,1}
  3  2     4.07272572e-02   # N_{3,2}
  3  3     7.04493534e-01   # N_{3,3}
  3  4     7.07982402e-01   # N_{3,4}
  4  1    -6.69483945e-02   # N_{4,1}
  4  2     2.14515075e-01   # N_{4,2}
  4  3     6.83180346e-01   # N_{4,3}
  4  4    -6.94813507e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.66790659e-01   # U_{1,1}
  1  2    -2.55569603e-01   # U_{1,2}
  2  1     2.55569603e-01   # U_{2,1}
  2  2     9.66790659e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.84337252e-01   # V_{1,1}
  1  2    -1.76295704e-01   # V_{1,2}
  2  1     1.76295704e-01   # V_{2,1}
  2  2     9.84337252e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.57651930e-01   # F_{11}
  1  2     9.33854966e-01   # F_{12}
  2  1     9.33854966e-01   # F_{21}
  2  2    -3.57651930e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.90452940e-01   # F_{11}
  1  2     1.37851275e-01   # F_{12}
  2  1    -1.37851275e-01   # F_{21}
  2  2     9.90452940e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.17335315e-01   # F_{11}
  1  2     9.93092354e-01   # F_{12}
  2  1     9.93092354e-01   # F_{21}
  2  2    -1.17335315e-01   # F_{22}
Block gauge Q= 1.06239732e+03  # SM gauge couplings
     1     3.62643976e-01   # g'(Q)MSSM DRbar
     2     6.41805736e-01   # g(Q)MSSM DRbar
     3     1.05103316e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.06239732e+03  
  3  3     8.55048355e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.06239732e+03  
  3  3     1.34181347e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.06239732e+03  
  3  3     1.00282256e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.06239732e+03 # Higgs mixing parameters
     1     7.39582662e+02    # mu(Q)MSSM DRbar
     2     9.65005152e+00    # tan beta(Q)MSSM DRbar
     3     2.43866458e+02    # higgs vev(Q)MSSM DRbar
     4     8.79927173e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.06239732e+03  # MSSM DRbar SUSY breaking parameters
     1     2.53306384e+02      # M_1(Q)
     2     4.68050045e+02      # M_2(Q)
     3     1.31801372e+03      # M_3(Q)
    21     2.88430573e+05      # mH1^2(Q)
    22    -5.24233417e+05      # mH2^2(Q)
    31     5.61678089e+02      # meL(Q)
    32     5.61671718e+02      # mmuL(Q)
    33     5.59748177e+02      # mtauL(Q)
    34     4.55804864e+02      # meR(Q)
    35     4.55789006e+02      # mmuR(Q)
    36     4.50982900e+02      # mtauR(Q)
    41     1.25607355e+03      # mqL1(Q)
    42     1.25607012e+03      # mqL2(Q)
    43     1.14766483e+03      # mqL3(Q)
    44     1.21245302e+03      # muR(Q)
    45     1.21244934e+03      # mcR(Q)
    46     9.76379788e+02      # mtR(Q)
    47     1.20714919e+03      # mdR(Q)
    48     1.20714566e+03      # msR(Q)
    49     1.20065992e+03      # mbR(Q)
Block au Q= 1.06239732e+03  
  1  1    -1.34098822e+03      # Au(Q)MSSM DRbar
  2  2    -1.34098226e+03      # Ac(Q)MSSM DRbar
  3  3    -1.03739471e+03      # At(Q)MSSM DRbar
Block ad Q= 1.06239732e+03  
  1  1    -1.63731694e+03      # Ad(Q)MSSM DRbar
  2  2    -1.63731141e+03      # As(Q)MSSM DRbar
  3  3    -1.53074400e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.06239732e+03  
  1  1    -3.56142031e+02      # Ae(Q)MSSM DRbar
  2  2    -3.56135705e+02      # Amu(Q)MSSM DRbar
  3  3    -3.54227371e+02      # Atau(Q)MSSM DRbar
