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
     1     1.50000000e+02  # M_1(MX)
     2     2.50000000e+03  # M_2(MX)
     3     2.50000000e+03  # M_3(MX)
     11    0.00000000e+00  # At(MX)
     12    0.00000000e+00  # Ab(MX)
     13    0.00000000e+00  # Atau(MX)
     23    2.50000000e+03  # mu(MX)
     26    2.50000000e+03  # mA(pole)
     31    2.00000000e+02  # meL(MX)
     32    2.00000000e+02  # mmuL(MX)
     33    2.50000000e+03  # mtauL(MX)
     34    2.00000000e+02  # meR(MX)
     35    2.00000000e+02  # mmuR(MX)
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
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.28139168e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04067001e+01   # MW
        25     1.17154329e+02   # h0
        35     2.50009588e+03   # H0
        36     2.49999204e+03   # A0
        37     2.50164844e+03   # H+
   1000021     2.64698287e+03   # ~g
   1000022     1.46643519e+02   # ~neutralino(1)
   1000023     2.44313868e+03   # ~neutralino(2)
   1000024     2.44332829e+03   # ~chargino(1)
   1000025    -2.50013053e+03   # ~neutralino(3)
   1000035     2.56119867e+03   # ~neutralino(4)
   1000037     2.56137113e+03   # ~chargino(2)
   1000001     2.60389207e+03   # ~d_L
   1000002     2.60285353e+03   # ~u_L
   1000003     2.60389207e+03   # ~s_L
   1000004     2.60285353e+03   # ~c_L
   1000005     2.58009070e+03   # ~b_1
   1000006     2.58129143e+03   # ~t_1
   1000011     2.97307361e+02   # ~e_L
   1000012     2.86706429e+02   # ~nue_L
   1000013     2.97307361e+02   # ~mu_L
   1000014     2.86706429e+02   # ~numu_L
   1000015     2.49908647e+03   # ~stau_1
   1000016     2.51704463e+03   # ~nu_tau_L
   2000001     2.58612332e+03   # ~d_R
   2000002     2.58541058e+03   # ~u_R
   2000003     2.58612332e+03   # ~s_R
   2000004     2.58541058e+03   # ~c_R
   2000005     2.60787771e+03   # ~b_2
   2000006     2.61221131e+03   # ~t_2
   2000011     2.17986155e+02   # ~e_R
   2000013     2.17986155e+02   # ~mu_R
   2000015     2.52250198e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.04708257e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.99836904e-01   # N_{1,1}
  1  2    -2.32346765e-04   # N_{1,2}
  1  3     1.78237265e-02   # N_{1,3}
  1  4    -2.90265075e-03   # N_{1,4}
  2  1     9.45575844e-03   # N_{2,1}
  2  2     7.78753115e-01   # N_{2,2}
  2  3    -4.48934732e-01   # N_{2,3}
  2  4     4.38077369e-01   # N_{2,4}
  3  1    -1.05463479e-02   # N_{3,1}
  3  2     9.83248564e-03   # N_{3,2}
  3  3     7.06898920e-01   # N_{3,3}
  3  4     7.07167600e-01   # N_{3,4}
  4  1    -1.12039176e-02   # N_{4,1}
  4  2     6.27253421e-01   # N_{4,2}
  4  3     5.46290984e-01   # N_{4,3}
  4  4    -5.54971872e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -6.87369918e-01   # U_{1,1}
  1  2     7.26307507e-01   # U_{1,2}
  2  1    -7.26307507e-01   # U_{2,1}
  2  2    -6.87369918e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -7.01599928e-01   # V_{1,1}
  1  2     7.12571078e-01   # V_{1,2}
  2  1    -7.12571078e-01   # V_{2,1}
  2  2    -7.01599928e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.20856766e-01   # F_{11}
  1  2     9.07127104e-01   # F_{12}
  2  1     9.07127104e-01   # F_{21}
  2  2    -4.20856766e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.95755739e-01   # F_{11}
  1  2     9.18355811e-01   # F_{12}
  2  1     9.18355811e-01   # F_{21}
  2  2    -3.95755739e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     4.03005643e-01   # F_{11}
  1  2     9.15197493e-01   # F_{12}
  2  1     9.15197493e-01   # F_{21}
  2  2    -4.03005643e-01   # F_{22}
Block gauge Q= 2.50366836e+03  # SM gauge couplings
     1     3.64702258e-01   # g'(Q)MSSM DRbar
     2     6.36083005e-01   # g(Q)MSSM DRbar
     3     1.01384479e+00   # g3(Q)MSSM DRbar
Block yu Q= 2.50366836e+03  
  3  3     8.33727503e-01   # Yt(Q)MSSM DRbar
Block yd Q= 2.50366836e+03  
  3  3     1.25717330e-01   # Yb(Q)MSSM DRbar
Block ye Q= 2.50366836e+03  
  3  3     9.97554862e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 2.50366836e+03 # Higgs mixing parameters
     1     2.50000000e+03    # mu(Q)MSSM DRbar
     2     9.54821820e+00    # tan beta(Q)MSSM DRbar
     3     2.43714535e+02    # higgs vev(Q)MSSM DRbar
     4     6.15955390e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 2.50366836e+03  # MSSM DRbar SUSY breaking parameters
     1     1.50000000e+02      # M_1(Q)
     2     2.50000000e+03      # M_2(Q)
     3     2.50000000e+03      # M_3(Q)
    21    -1.66526094e+05      # mH1^2(Q)
    22    -6.06899687e+06      # mH2^2(Q)
    31     1.99999999e+02      # meL(Q)
    32     1.99999999e+02      # mmuL(Q)
    33     2.50000000e+03      # mtauL(Q)
    34     2.00000001e+02      # meR(Q)
    35     2.00000001e+02      # mmuR(Q)
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
Block au Q= 2.50366836e+03  
  1  1     6.11039877e-06      # Au(Q)MSSM DRbar
  2  2     6.11047105e-06      # Ac(Q)MSSM DRbar
  3  3     1.02287385e-05      # At(Q)MSSM DRbar
Block ad Q= 2.50366836e+03  
  1  1     2.09743759e-06      # Ad(Q)MSSM DRbar
  2  2     2.09751229e-06      # As(Q)MSSM DRbar
  3  3     3.43746992e-06      # Ab(Q)MSSM DRbar
Block ae Q= 2.50366836e+03  
  1  1     0.00000000e+00      # Ae(Q)MSSM DRbar
  2  2     1.21817316e-07      # Amu(Q)MSSM DRbar
  3  3     1.22120167e-07      # Atau(Q)MSSM DRbar
