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
     1     9.00000000e+01  # M_1(MX)
     2     2.50000000e+03  # M_2(MX)
     3     2.50000000e+03  # M_3(MX)
     11    0.00000000e+00  # At(MX)
     12    0.00000000e+00  # Ab(MX)
     13    0.00000000e+00  # Atau(MX)
     23    2.50000000e+03  # mu(MX)
     26    2.50000000e+03  # mA(pole)
     31    1.20000000e+02  # meL(MX)
     32    1.20000000e+02  # mmuL(MX)
     33    2.50000000e+03  # mtauL(MX)
     34    1.20000000e+02  # meR(MX)
     35    1.20000000e+02  # mmuR(MX)
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
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.22661917e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04070222e+01   # MW
        25     1.17055387e+02   # h0
        35     2.50009586e+03   # H0
        36     2.49999203e+03   # A0
        37     2.50164516e+03   # H+
   1000021     2.64698287e+03   # ~g
   1000022     8.75257244e+01   # ~neutralino(1)
   1000023     2.44324490e+03   # ~neutralino(2)
   1000024     2.44344184e+03   # ~chargino(1)
   1000025    -2.50013793e+03   # ~neutralino(3)
   1000035     2.56131858e+03   # ~neutralino(4)
   1000037     2.56149717e+03   # ~chargino(2)
   1000001     2.60389154e+03   # ~d_L
   1000002     2.60285603e+03   # ~u_L
   1000003     2.60389154e+03   # ~s_L
   1000004     2.60285603e+03   # ~c_L
   1000005     2.58009030e+03   # ~b_1
   1000006     2.58129034e+03   # ~t_1
   1000011     2.49220030e+02   # ~e_L
   1000012     2.36602396e+02   # ~nue_L
   1000013     2.49220030e+02   # ~mu_L
   1000014     2.36602396e+02   # ~numu_L
   1000015     2.49907710e+03   # ~stau_1
   1000016     2.51704552e+03   # ~nu_tau_L
   2000001     2.58612210e+03   # ~d_R
   2000002     2.58540698e+03   # ~u_R
   2000003     2.58612210e+03   # ~s_R
   2000004     2.58540698e+03   # ~c_R
   2000005     2.60787594e+03   # ~b_2
   2000006     2.61220960e+03   # ~t_2
   2000011     1.46951309e+02   # ~e_R
   2000013     1.46951309e+02   # ~mu_R
   2000015     2.52249904e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.04707468e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.99839872e-01   # N_{1,1}
  1  2    -3.68550860e-04   # N_{1,2}
  1  3     1.77192112e-02   # N_{1,3}
  1  4    -2.47475135e-03   # N_{1,4}
  2  1     9.01612884e-03   # N_{2,1}
  2  2     7.96260873e-01   # N_{2,2}
  2  3    -4.33233038e-01   # N_{2,3}
  2  4     4.22133234e-01   # N_{2,4}
  3  1    -1.07736838e-02   # N_{3,1}
  3  2     9.83264250e-03   # N_{3,2}
  3  3     7.06896281e-01   # N_{3,3}
  3  4     7.07166809e-01   # N_{3,4}
  4  1    -1.10845761e-02   # N_{4,1}
  4  2     6.04873380e-01   # N_{4,2}
  4  3     5.58831650e-01   # N_{4,3}
  4  4    -5.67197067e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -6.86614852e-01   # U_{1,1}
  1  2     7.27021352e-01   # U_{1,2}
  2  1    -7.27021352e-01   # U_{2,1}
  2  2    -6.86614852e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -7.00859672e-01   # V_{1,1}
  1  2     7.13299180e-01   # V_{1,2}
  2  1    -7.13299180e-01   # V_{2,1}
  2  2    -7.00859672e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.20705276e-01   # F_{11}
  1  2     9.07197371e-01   # F_{12}
  2  1     9.07197371e-01   # F_{21}
  2  2    -4.20705276e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.95734114e-01   # F_{11}
  1  2     9.18365129e-01   # F_{12}
  2  1     9.18365129e-01   # F_{21}
  2  2    -3.95734114e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     4.02904897e-01   # F_{11}
  1  2     9.15241850e-01   # F_{12}
  2  1     9.15241850e-01   # F_{21}
  2  2    -4.02904897e-01   # F_{22}
Block gauge Q= 2.50366832e+03  # SM gauge couplings
     1     3.64752474e-01   # g'(Q)MSSM DRbar
     2     6.36107774e-01   # g(Q)MSSM DRbar
     3     1.01384480e+00   # g3(Q)MSSM DRbar
Block yu Q= 2.50366832e+03  
  3  3     8.33727951e-01   # Yt(Q)MSSM DRbar
Block yd Q= 2.50366832e+03  
  3  3     1.25706199e-01   # Yb(Q)MSSM DRbar
Block ye Q= 2.50366832e+03  
  3  3     9.97636468e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 2.50366832e+03 # Higgs mixing parameters
     1     2.50000000e+03    # mu(Q)MSSM DRbar
     2     9.54821467e+00    # tan beta(Q)MSSM DRbar
     3     2.43714776e+02    # higgs vev(Q)MSSM DRbar
     4     6.15835862e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 2.50366832e+03  # MSSM DRbar SUSY breaking parameters
     1     9.00000000e+01      # M_1(Q)
     2     2.50000000e+03      # M_2(Q)
     3     2.50000000e+03      # M_3(Q)
    21    -1.66547241e+05      # mH1^2(Q)
    22    -6.06898094e+06      # mH2^2(Q)
    31     1.19999999e+02      # meL(Q)
    32     1.19999999e+02      # mmuL(Q)
    33     2.50000000e+03      # mtauL(Q)
    34     1.20000001e+02      # meR(Q)
    35     1.20000001e+02      # mmuR(Q)
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
  1  1     6.10913275e-06      # Au(Q)MSSM DRbar
  2  2     6.10920509e-06      # Ac(Q)MSSM DRbar
  3  3     1.02291179e-05      # At(Q)MSSM DRbar
Block ad Q= 2.50366832e+03  
  1  1     2.09531512e-06      # Ad(Q)MSSM DRbar
  2  2     2.09538984e-06      # As(Q)MSSM DRbar
  3  3     3.43596453e-06      # Ab(Q)MSSM DRbar
Block ae Q= 2.50366832e+03  
  1  1     0.00000000e+00      # Ae(Q)MSSM DRbar
  2  2     1.21813492e-07      # Amu(Q)MSSM DRbar
  3  3     1.22120266e-07      # Atau(Q)MSSM DRbar
