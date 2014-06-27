# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    0   # nonUniversal
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
Block EXTPAR               # non-universal SUSY breaking parameters
     0    -1.00000000e+00  # Set MX=MSUSY
     1     7.50000000e+01  # M_1(MX)
     2     2.50000000e+03  # M_2(MX)
     3     2.50000000e+03  # M_3(MX)
     11    0.00000000e+00  # At(MX)
     12    0.00000000e+00  # Ab(MX)
     13    0.00000000e+00  # Atau(MX)
     23    2.50000000e+03  # mu(MX)
     26    2.50000000e+03  # mA(pole)
     31    1.00000000e+02  # meL(MX)
     32    1.00000000e+02  # mmuL(MX)
     33    2.50000000e+03  # mtauL(MX)
     34    1.00000000e+02  # meR(MX)
     35    1.00000000e+02  # mmuR(MX)
     36    2.50000000e+03  # mtauR(MX)
     41    2.50000000e+03  # mqL1(MX)
     42    2.50000000e+03  # mqL2(MX)
     43    2.50000000e+03  # mqL3(MX)
     44    2.50000000e+03  # muR(MX)
     45    2.50000000e+03  # mcR(MX)
     46    2.50000000e+03  # mtR(MX)
     47    2.50000000e+03  # mdR(MX)
     48    2.50000000e+03  # msR(MX)
     49    2.50000000e+03  # mbR(MX)
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.19376894e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04071006e+01   # MW
        25     1.17003975e+02   # h0
        35     2.50009597e+03   # H0
        36     2.49999204e+03   # A0
        37     2.50164385e+03   # H+
   1000021     2.64698287e+03   # ~g
   1000022     7.27716565e+01   # ~neutralino(1)
   1000023     2.44326636e+03   # ~neutralino(2)
   1000024     2.44346508e+03   # ~chargino(1)
   1000025    -2.50013969e+03   # ~neutralino(3)
   1000035     2.56134242e+03   # ~neutralino(4)
   1000037     2.56152245e+03   # ~chargino(2)
   1000001     2.60389112e+03   # ~d_L
   1000002     2.60285677e+03   # ~u_L
   1000003     2.60389112e+03   # ~s_L
   1000004     2.60285677e+03   # ~c_L
   1000005     2.58009019e+03   # ~b_1
   1000006     2.58129044e+03   # ~t_1
   1000011     2.39965285e+02   # ~e_L
   1000012     2.26869382e+02   # ~nue_L
   1000013     2.39965285e+02   # ~mu_L
   1000014     2.26869382e+02   # ~numu_L
   1000015     2.49907528e+03   # ~stau_1
   1000016     2.51704613e+03   # ~nu_tau_L
   2000001     2.58612182e+03   # ~d_R
   2000002     2.58540651e+03   # ~u_R
   2000003     2.58612182e+03   # ~s_R
   2000004     2.58540651e+03   # ~c_R
   2000005     2.60787525e+03   # ~b_2
   2000006     2.61220934e+03   # ~t_2
   2000011     1.30891216e+02   # ~e_R
   2000013     1.30891216e+02   # ~mu_R
   2000015     2.52249837e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.04707055e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.99840523e-01   # N_{1,1}
  1  2    -4.96829257e-04   # N_{1,2}
  1  3     1.76938458e-02   # N_{1,3}
  1  4    -2.36846653e-03   # N_{1,4}
  2  1     8.93256192e-03   # N_{2,1}
  2  2     8.03353869e-01   # N_{2,2}
  2  3    -4.26597223e-01   # N_{2,3}
  2  4     4.15400505e-01   # N_{2,4}
  3  1    -1.08296445e-02   # N_{3,1}
  3  2     9.83267482e-03   # N_{3,2}
  3  3     7.06895668e-01   # N_{3,3}
  3  4     7.07166566e-01   # N_{3,4}
  4  1    -1.10388763e-02   # N_{4,1}
  4  2     5.95420551e-01   # N_{4,2}
  4  3     5.63915110e-01   # N_{4,3}
  4  4    -5.72147061e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -6.86459952e-01   # U_{1,1}
  1  2     7.27167611e-01   # U_{1,2}
  2  1    -7.27167611e-01   # U_{2,1}
  2  2    -6.86459952e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -7.00707793e-01   # V_{1,1}
  1  2     7.13448379e-01   # V_{1,2}
  2  1    -7.13448379e-01   # V_{2,1}
  2  2    -7.00707793e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.20671202e-01   # F_{11}
  1  2     9.07213172e-01   # F_{12}
  2  1     9.07213172e-01   # F_{21}
  2  2    -4.20671202e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.95733148e-01   # F_{11}
  1  2     9.18365546e-01   # F_{12}
  2  1     9.18365546e-01   # F_{21}
  2  2    -3.95733148e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     4.02889536e-01   # F_{11}
  1  2     9.15248612e-01   # F_{12}
  2  1     9.15248612e-01   # F_{21}
  2  2    -4.02889536e-01   # F_{22}
Block gauge Q= 2.50366832e+03  # SM gauge couplings
     1     3.64763775e-01   # g'(Q)MSSM DRbar
     2     6.36112361e-01   # g(Q)MSSM DRbar
     3     1.01384480e+00   # g3(Q)MSSM DRbar
Block yu Q= 2.50366832e+03  
  3  3     8.33728125e-01   # Yt(Q)MSSM DRbar
Block yd Q= 2.50366832e+03  
  3  3     1.25703385e-01   # Yb(Q)MSSM DRbar
Block ye Q= 2.50366832e+03  
  3  3     9.97657085e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 2.50366832e+03 # Higgs mixing parameters
     1     2.50000000e+03    # mu(Q)MSSM DRbar
     2     9.54821379e+00    # tan beta(Q)MSSM DRbar
     3     2.43714819e+02    # higgs vev(Q)MSSM DRbar
     4     6.15805305e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 2.50366832e+03  # MSSM DRbar SUSY breaking parameters
     1     7.50000000e+01      # M_1(Q)
     2     2.50000000e+03      # M_2(Q)
     3     2.50000000e+03      # M_3(Q)
    21    -1.66555946e+05      # mH1^2(Q)
    22    -6.06897615e+06      # mH2^2(Q)
    31     9.99999988e+01      # meL(Q)
    32     9.99999988e+01      # mmuL(Q)
    33     2.50000000e+03      # mtauL(Q)
    34     1.00000001e+02      # meR(Q)
    35     1.00000001e+02      # mmuR(Q)
    36     2.50000000e+03      # mtauR(Q)
    41     2.49999999e+03      # mqL1(Q)
    42     2.49999999e+03      # mqL2(Q)
    43     2.49999999e+03      # mqL3(Q)
    44     2.49999999e+03      # muR(Q)
    45     2.49999999e+03      # mcR(Q)
    46     2.49999999e+03      # mtR(Q)
    47     2.49999999e+03      # mdR(Q)
    48     2.49999999e+03      # msR(Q)
    49     2.49999999e+03      # mbR(Q)
Block au Q= 2.50366832e+03  
  1  1     6.10880554e-06      # Au(Q)MSSM DRbar
  2  2     6.10887829e-06      # Ac(Q)MSSM DRbar
  3  3     1.02292149e-05      # At(Q)MSSM DRbar
Block ad Q= 2.50366832e+03  
  1  1     2.09475878e-06      # Ad(Q)MSSM DRbar
  2  2     2.09483363e-06      # As(Q)MSSM DRbar
  3  3     3.43556928e-06      # Ab(Q)MSSM DRbar
Block ae Q= 2.50366832e+03  
  1  1     0.00000000e+00      # Ae(Q)MSSM DRbar
  2  2     1.21812880e-07      # Amu(Q)MSSM DRbar
  3  3     1.22120554e-07      # Atau(Q)MSSM DRbar
