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
     1    2.50000000e+02   # m0
     2    6.00000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.79640106e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.10527160e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03941528e+01   # MW
        25     1.16115004e+02   # h0
        35     8.71235572e+02   # H0
        36     8.70996144e+02   # A0
        37     8.74940343e+02   # H+
   1000021     1.35966333e+03   # ~g
   1000022     2.48142081e+02   # ~neutralino(1)
   1000023     4.69490092e+02   # ~neutralino(2)
   1000024     4.69552947e+02   # ~chargino(1)
   1000025    -7.45756716e+02   # ~neutralino(3)
   1000035     7.58195271e+02   # ~neutralino(4)
   1000037     7.58436176e+02   # ~chargino(2)
   1000001     1.26232750e+03   # ~d_L
   1000002     1.25998333e+03   # ~u_L
   1000003     1.26232438e+03   # ~s_L
   1000004     1.25998021e+03   # ~c_L
   1000005     1.15391480e+03   # ~b_1
   1000006     9.66349346e+02   # ~t_1
   1000011     4.75467842e+02   # ~e_L
   1000012     4.68672407e+02   # ~nue_L
   1000013     4.75463151e+02   # ~mu_L
   1000014     4.68667669e+02   # ~numu_L
   1000015     3.32173830e+02   # ~stau_1
   1000016     4.67065451e+02   # ~nu_tau_L
   2000001     1.20942984e+03   # ~d_R
   2000002     1.21380013e+03   # ~u_R
   2000003     1.20942659e+03   # ~s_R
   2000004     1.21379678e+03   # ~c_R
   2000005     1.20456803e+03   # ~b_2
   2000006     1.19226012e+03   # ~t_2
   2000011     3.38923527e+02   # ~e_R
   2000013     3.38910221e+02   # ~mu_R
   2000015     4.75571149e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05842934e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96957884e-01   # N_{1,1}
  1  2    -1.26842120e-02   # N_{1,2}
  1  3     7.07642831e-02   # N_{1,3}
  1  4    -3.01081987e-02   # N_{1,4}
  2  1     2.87272562e-02   # N_{2,1}
  2  2     9.76041549e-01   # N_{2,2}
  2  3    -1.77870337e-01   # N_{2,3}
  2  4     1.21982714e-01   # N_{2,4}
  3  1    -2.81054942e-02   # N_{3,1}
  3  2     4.07291954e-02   # N_{3,2}
  3  3     7.04490832e-01   # N_{3,3}
  3  4     7.07985792e-01   # N_{3,4}
  4  1    -6.67817533e-02   # N_{4,1}
  4  2     2.13361519e-01   # N_{4,2}
  4  3     6.83408536e-01   # N_{4,3}
  4  4    -6.94960310e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.67161718e-01   # U_{1,1}
  1  2    -2.54161782e-01   # U_{1,2}
  2  1     2.54161782e-01   # U_{2,1}
  2  2     9.67161718e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.84593425e-01   # V_{1,1}
  1  2    -1.74859337e-01   # V_{1,2}
  2  1     1.74859337e-01   # V_{2,1}
  2  2     9.84593425e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.76448055e-01   # F_{11}
  1  2     9.26437727e-01   # F_{12}
  2  1     9.26437727e-01   # F_{21}
  2  2    -3.76448055e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.85006225e-01   # F_{11}
  1  2     1.72518801e-01   # F_{12}
  2  1    -1.72518801e-01   # F_{21}
  2  2     9.85006225e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.17730505e-01   # F_{11}
  1  2     9.93045582e-01   # F_{12}
  2  1     9.93045582e-01   # F_{21}
  2  2    -1.17730505e-01   # F_{22}
Block gauge Q= 1.04161501e+03  # SM gauge couplings
     1     3.62710173e-01   # g'(Q)MSSM DRbar
     2     6.41986407e-01   # g(Q)MSSM DRbar
     3     1.05179421e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.04161501e+03  
  3  3     8.55317353e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.04161501e+03  
  3  3     1.34167850e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.04161501e+03  
  3  3     1.00383725e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.04161501e+03 # Higgs mixing parameters
     1     7.40241106e+02    # mu(Q)MSSM DRbar
     2     9.65267453e+00    # tan beta(Q)MSSM DRbar
     3     2.43904270e+02    # higgs vev(Q)MSSM DRbar
     4     7.85370619e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.04161501e+03  # MSSM DRbar SUSY breaking parameters
     1     2.53210588e+02      # M_1(Q)
     2     4.67952583e+02      # M_2(Q)
     3     1.31890252e+03      # M_3(Q)
    21     1.95209038e+05      # mH1^2(Q)
    22    -5.27291655e+05      # mH2^2(Q)
    31     4.68054896e+02      # meL(Q)
    32     4.68050140e+02      # mmuL(Q)
    33     4.66612734e+02      # mtauL(Q)
    34     3.32675955e+02      # meR(Q)
    35     3.32662390e+02      # mmuR(Q)
    36     3.28542172e+02      # mtauR(Q)
    41     1.21952882e+03      # mqL1(Q)
    42     1.21952563e+03      # mqL2(Q)
    43     1.12139917e+03      # mqL3(Q)
    44     1.17420463e+03      # muR(Q)
    45     1.17420122e+03      # mcR(Q)
    46     9.60717025e+02      # mtR(Q)
    47     1.16867958e+03      # mdR(Q)
    48     1.16867628e+03      # msR(Q)
    49     1.16264256e+03      # mbR(Q)
Block au Q= 1.04161501e+03  
  1  1    -1.34254408e+03      # Au(Q)MSSM DRbar
  2  2    -1.34253810e+03      # Ac(Q)MSSM DRbar
  3  3    -1.03867287e+03      # At(Q)MSSM DRbar
Block ad Q= 1.04161501e+03  
  1  1    -1.63918488e+03      # Ad(Q)MSSM DRbar
  2  2    -1.63917934e+03      # As(Q)MSSM DRbar
  3  3    -1.53251996e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.04161501e+03  
  1  1    -3.56268858e+02      # Ae(Q)MSSM DRbar
  2  2    -3.56262527e+02      # Amu(Q)MSSM DRbar
  3  3    -3.54349961e+02      # Atau(Q)MSSM DRbar
