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
     1    1.37500000e+02   # m0
     2    5.50000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.81512839e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=8.79893656e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03955001e+01   # MW
        25     1.15527615e+02   # h0
        35     7.83714177e+02   # H0
        36     7.83461808e+02   # A0
        37     7.87805791e+02   # H+
   1000021     1.25180886e+03   # ~g
   1000022     2.25931340e+02   # ~neutralino(1)
   1000023     4.27307043e+02   # ~neutralino(2)
   1000024     4.27347979e+02   # ~chargino(1)
   1000025    -6.90897340e+02   # ~neutralino(3)
   1000035     7.03890133e+02   # ~neutralino(4)
   1000037     7.04170857e+02   # ~chargino(2)
   1000001     1.15134195e+03   # ~d_L
   1000002     1.14875393e+03   # ~u_L
   1000003     1.15133915e+03   # ~s_L
   1000004     1.14875113e+03   # ~c_L
   1000005     1.05451492e+03   # ~b_1
   1000006     8.81638974e+02   # ~t_1
   1000011     3.96770297e+02   # ~e_L
   1000012     3.88649151e+02   # ~nue_L
   1000013     3.96766713e+02   # ~mu_L
   1000014     3.88645508e+02   # ~numu_L
   1000015     2.44850710e+02   # ~stau_1
   1000016     3.87372745e+02   # ~nu_tau_L
   2000001     1.10217882e+03   # ~d_R
   2000002     1.10605648e+03   # ~u_R
   2000003     1.10217589e+03   # ~s_R
   2000004     1.10605349e+03   # ~c_R
   2000005     1.09829056e+03   # ~b_2
   2000006     1.09684614e+03   # ~t_2
   2000011     2.51946382e+02   # ~e_R
   2000013     2.51934969e+02   # ~mu_R
   2000015     3.97573634e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.06320194e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96463490e-01   # N_{1,1}
  1  2    -1.47785680e-02   # N_{1,2}
  1  3     7.62555433e-02   # N_{1,3}
  1  4    -3.20499397e-02   # N_{1,4}
  2  1     3.28411555e-02   # N_{2,1}
  2  2     9.73558365e-01   # N_{2,2}
  2  3    -1.87211453e-01   # N_{2,3}
  2  4     1.26717957e-01   # N_{2,4}
  3  1    -3.04445186e-02   # N_{3,1}
  3  2     4.42389675e-02   # N_{3,2}
  3  3     7.04031787e-01   # N_{3,3}
  3  4     7.08135077e-01   # N_{3,4}
  4  1    -7.10992432e-02   # N_{4,1}
  4  2     2.23626067e-01   # N_{4,2}
  4  3     6.80790869e-01   # N_{4,3}
  4  4    -6.93873240e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.63576922e-01   # U_{1,1}
  1  2    -2.67431327e-01   # U_{1,2}
  2  1     2.67431327e-01   # U_{2,1}
  2  2     9.63576922e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.83388016e-01   # V_{1,1}
  1  2    -1.81515864e-01   # V_{1,2}
  2  1     1.81515864e-01   # V_{2,1}
  2  2     9.83388016e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.04721566e-01   # F_{11}
  1  2     9.14439967e-01   # F_{12}
  2  1     9.14439967e-01   # F_{21}
  2  2    -4.04721566e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.78892652e-01   # F_{11}
  1  2     2.04375085e-01   # F_{12}
  2  1    -2.04375085e-01   # F_{21}
  2  2     9.78892652e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.29009203e-01   # F_{11}
  1  2     9.91643396e-01   # F_{12}
  2  1     9.91643396e-01   # F_{21}
  2  2    -1.29009203e-01   # F_{22}
Block gauge Q= 9.53955848e+02  # SM gauge couplings
     1     3.62600631e-01   # g'(Q)MSSM DRbar
     2     6.42519994e-01   # g(Q)MSSM DRbar
     3     1.05630116e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.53955848e+02  
  3  3     8.58162297e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.53955848e+02  
  3  3     1.34713035e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.53955848e+02  
  3  3     1.00453869e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.53955848e+02 # Higgs mixing parameters
     1     6.85472374e+02    # mu(Q)MSSM DRbar
     2     9.66316778e+00    # tan beta(Q)MSSM DRbar
     3     2.44012603e+02    # higgs vev(Q)MSSM DRbar
     4     6.36452879e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.53955848e+02  # MSSM DRbar SUSY breaking parameters
     1     2.31219569e+02      # M_1(Q)
     2     4.28191262e+02      # M_2(Q)
     3     1.21653518e+03      # M_3(Q)
    21     1.31959187e+05      # mH1^2(Q)
    22    -4.53883362e+05      # mH2^2(Q)
    31     3.88977041e+02      # meL(Q)
    32     3.88973403e+02      # mmuL(Q)
    33     3.87875049e+02      # mtauL(Q)
    34     2.44085713e+02      # meR(Q)
    35     2.44073919e+02      # mmuR(Q)
    36     2.40491758e+02      # mtauR(Q)
    41     1.11150425e+03      # mqL1(Q)
    42     1.11150140e+03      # mqL2(Q)
    43     1.02471120e+03      # mqL3(Q)
    44     1.06947134e+03      # muR(Q)
    45     1.06946830e+03      # mcR(Q)
    46     8.80808067e+02      # mtR(Q)
    47     1.06436286e+03      # mdR(Q)
    48     1.06435989e+03      # msR(Q)
    49     1.05893475e+03      # mbR(Q)
Block au Q= 9.53955848e+02  
  1  1    -1.24227303e+03      # Au(Q)MSSM DRbar
  2  2    -1.24226748e+03      # Ac(Q)MSSM DRbar
  3  3    -9.59891356e+02      # At(Q)MSSM DRbar
Block ad Q= 9.53955848e+02  
  1  1    -1.51822638e+03      # Ad(Q)MSSM DRbar
  2  2    -1.51822123e+03      # As(Q)MSSM DRbar
  3  3    -1.41909501e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.53955848e+02  
  1  1    -3.27857351e+02      # Ae(Q)MSSM DRbar
  2  2    -3.27851496e+02      # Amu(Q)MSSM DRbar
  3  3    -3.26084015e+02      # Atau(Q)MSSM DRbar
