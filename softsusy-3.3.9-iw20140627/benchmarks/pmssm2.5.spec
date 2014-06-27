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
     1     1.35000000e+02  # M_1(MX)
     2     2.50000000e+03  # M_2(MX)
     3     2.50000000e+03  # M_3(MX)
     11    0.00000000e+00  # At(MX)
     12    0.00000000e+00  # Ab(MX)
     13    0.00000000e+00  # Atau(MX)
     23    2.50000000e+03  # mu(MX)
     26    2.50000000e+03  # mA(pole)
     31    1.80000000e+02  # meL(MX)
     32    1.80000000e+02  # mmuL(MX)
     33    2.50000000e+03  # mtauL(MX)
     34    1.80000000e+02  # meR(MX)
     35    1.80000000e+02  # mmuR(MX)
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
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.27645828e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04067784e+01   # MW
        25     1.17136286e+02   # h0
        35     2.50009585e+03   # H0
        36     2.49999204e+03   # A0
        37     2.50164780e+03   # H+
   1000021     2.64698287e+03   # ~g
   1000022     1.31850432e+02   # ~neutralino(1)
   1000023     2.44316791e+03   # ~neutralino(2)
   1000024     2.44335938e+03   # ~chargino(1)
   1000025    -2.50013244e+03   # ~neutralino(3)
   1000035     2.56123176e+03   # ~neutralino(4)
   1000037     2.56140578e+03   # ~chargino(2)
   1000001     2.60389206e+03   # ~d_L
   1000002     2.60285412e+03   # ~u_L
   1000003     2.60389206e+03   # ~s_L
   1000004     2.60285412e+03   # ~c_L
   1000005     2.58009059e+03   # ~b_1
   1000006     2.58129096e+03   # ~t_1
   1000011     2.83896403e+02   # ~e_L
   1000012     2.72802189e+02   # ~nue_L
   1000013     2.83896403e+02   # ~mu_L
   1000014     2.72802189e+02   # ~numu_L
   1000015     2.49908377e+03   # ~stau_1
   1000016     2.51704468e+03   # ~nu_tau_L
   2000001     2.58612298e+03   # ~d_R
   2000002     2.58540944e+03   # ~u_R
   2000003     2.58612298e+03   # ~s_R
   2000004     2.58540944e+03   # ~c_R
   2000005     2.60787737e+03   # ~b_2
   2000006     2.61221081e+03   # ~t_2
   2000011     1.99565955e+02   # ~e_R
   2000013     1.99565955e+02   # ~mu_R
   2000015     2.52250117e+03   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.04708114e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.99837691e-01   # N_{1,1}
  1  2    -2.46618201e-04   # N_{1,2}
  1  3     1.77965835e-02   # N_{1,3}
  1  4    -2.79516578e-03   # N_{1,4}
  2  1     9.34461249e-03   # N_{2,1}
  2  2     7.82284917e-01   # N_{2,2}
  2  3    -4.45841468e-01   # N_{2,3}
  2  4     4.34934906e-01   # N_{2,4}
  3  1    -1.06030197e-02   # N_{3,1}
  3  2     9.83253194e-03   # N_{3,2}
  3  3     7.06898253e-01   # N_{3,3}
  3  4     7.07167418e-01   # N_{3,4}
  4  1    -1.11734662e-02   # N_{4,1}
  4  2     6.22843134e-01   # N_{4,2}
  4  3     5.48820123e-01   # N_{4,3}
  4  4    -5.57438837e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -6.87163483e-01   # U_{1,1}
  1  2     7.26502820e-01   # U_{1,2}
  2  1    -7.26502820e-01   # U_{2,1}
  2  2    -6.87163483e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -7.01397552e-01   # V_{1,1}
  1  2     7.12770281e-01   # V_{1,2}
  2  1    -7.12770281e-01   # V_{2,1}
  2  2    -7.01397552e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.20816406e-01   # F_{11}
  1  2     9.07145828e-01   # F_{12}
  2  1     9.07145828e-01   # F_{21}
  2  2    -4.20816406e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.95748276e-01   # F_{11}
  1  2     9.18359027e-01   # F_{12}
  2  1     9.18359027e-01   # F_{21}
  2  2    -3.95748276e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     4.02974477e-01   # F_{11}
  1  2     9.15211217e-01   # F_{12}
  2  1     9.15211217e-01   # F_{21}
  2  2    -4.02974477e-01   # F_{22}
Block gauge Q= 2.50366835e+03  # SM gauge couplings
     1     3.64715088e-01   # g'(Q)MSSM DRbar
     2     6.36090059e-01   # g(Q)MSSM DRbar
     3     1.01384479e+00   # g3(Q)MSSM DRbar
Block yu Q= 2.50366835e+03  
  3  3     8.33727591e-01   # Yt(Q)MSSM DRbar
Block yd Q= 2.50366835e+03  
  3  3     1.25714568e-01   # Yb(Q)MSSM DRbar
Block ye Q= 2.50366835e+03  
  3  3     9.97575141e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 2.50366835e+03 # Higgs mixing parameters
     1     2.50000000e+03    # mu(Q)MSSM DRbar
     2     9.54821731e+00    # tan beta(Q)MSSM DRbar
     3     2.43714602e+02    # higgs vev(Q)MSSM DRbar
     4     6.15925969e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 2.50366835e+03  # MSSM DRbar SUSY breaking parameters
     1     1.35000000e+02      # M_1(Q)
     2     2.50000000e+03      # M_2(Q)
     3     2.50000000e+03      # M_3(Q)
    21    -1.66529440e+05      # mH1^2(Q)
    22    -6.06899302e+06      # mH2^2(Q)
    31     1.79999999e+02      # meL(Q)
    32     1.79999999e+02      # mmuL(Q)
    33     2.50000000e+03      # mtauL(Q)
    34     1.80000001e+02      # meR(Q)
    35     1.80000001e+02      # mmuR(Q)
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
Block au Q= 2.50366835e+03  
  1  1     6.11008769e-06      # Au(Q)MSSM DRbar
  2  2     6.11015964e-06      # Ac(Q)MSSM DRbar
  3  3     1.02288327e-05      # At(Q)MSSM DRbar
Block ad Q= 2.50366835e+03  
  1  1     2.09692011e-06      # Ad(Q)MSSM DRbar
  2  2     2.09699467e-06      # As(Q)MSSM DRbar
  3  3     3.43710330e-06      # Ab(Q)MSSM DRbar
Block ae Q= 2.50366835e+03  
  1  1     0.00000000e+00      # Ae(Q)MSSM DRbar
  2  2     1.21816275e-07      # Amu(Q)MSSM DRbar
  3  3     1.22120124e-07      # Atau(Q)MSSM DRbar
