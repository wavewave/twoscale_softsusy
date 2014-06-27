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
     1    4.50000000e+02   # m0
     2    6.75000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.77127446e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.64603829e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03930679e+01   # MW
        25     1.16896203e+02   # h0
        35     1.02955317e+03   # H0
        36     1.02929721e+03   # A0
        37     1.03273344e+03   # H+
   1000021     1.52386692e+03   # ~g
   1000022     2.81702340e+02   # ~neutralino(1)
   1000023     5.33076037e+02   # ~neutralino(2)
   1000024     5.33160781e+02   # ~chargino(1)
   1000025    -8.26024875e+02   # ~neutralino(3)
   1000035     8.37848959e+02   # ~neutralino(4)
   1000037     8.38035339e+02   # ~chargino(2)
   1000001     1.44819384e+03   # ~d_L
   1000002     1.44617575e+03   # ~u_L
   1000003     1.44819011e+03   # ~s_L
   1000004     1.44617201e+03   # ~c_L
   1000005     1.31711734e+03   # ~b_1
   1000006     1.10245394e+03   # ~t_1
   1000011     6.37623958e+02   # ~e_L
   1000012     6.32479108e+02   # ~nue_L
   1000013     6.37616891e+02   # ~mu_L
   1000014     6.32472028e+02   # ~numu_L
   1000015     5.10122082e+02   # ~stau_1
   1000016     6.30169213e+02   # ~nu_tau_L
   2000001     1.39075766e+03   # ~d_R
   2000002     1.39574626e+03   # ~u_R
   2000003     1.39075382e+03   # ~s_R
   2000004     1.39574223e+03   # ~c_R
   2000005     1.38423107e+03   # ~b_2
   2000006     1.34936426e+03   # ~t_2
   2000011     5.17264902e+02   # ~e_R
   2000013     5.17247359e+02   # ~mu_R
   2000015     6.36568369e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05289636e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97501991e-01   # N_{1,1}
  1  2    -1.03320534e-02   # N_{1,2}
  1  3     6.41259664e-02   # N_{1,3}
  1  4    -2.77648645e-02   # N_{1,4}
  2  1     2.40936177e-02   # N_{2,1}
  2  2     9.78817456e-01   # N_{2,2}
  2  3    -1.66652532e-01   # N_{2,3}
  2  4     1.16459514e-01   # N_{2,4}
  3  1    -2.52431403e-02   # N_{3,1}
  3  2     3.64385918e-02   # N_{3,2}
  3  3     7.05003325e-01   # N_{3,3}
  3  4     7.07817297e-01   # N_{3,4}
  4  1    -6.14170990e-02   # N_{4,1}
  4  2     2.01201056e-01   # N_{4,2}
  4  3     6.86356399e-01   # N_{4,3}
  4  4    -6.96175961e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.71222615e-01   # U_{1,1}
  1  2    -2.38173534e-01   # U_{1,2}
  2  1     2.38173534e-01   # U_{2,1}
  2  2     9.71222615e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.85952793e-01   # V_{1,1}
  1  2    -1.67024217e-01   # V_{1,2}
  2  1     1.67024217e-01   # V_{2,1}
  2  2     9.85952793e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.29985612e-01   # F_{11}
  1  2     9.43985962e-01   # F_{12}
  2  1     9.43985962e-01   # F_{21}
  2  2    -3.29985612e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.92188551e-01   # F_{11}
  1  2     1.24747264e-01   # F_{12}
  2  1    -1.24747264e-01   # F_{21}
  2  2     9.92188551e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.03823982e-01   # F_{11}
  1  2     9.94595687e-01   # F_{12}
  2  1     9.94595687e-01   # F_{21}
  2  2    -1.03823982e-01   # F_{22}
Block gauge Q= 1.18405717e+03  # SM gauge couplings
     1     3.62870429e-01   # g'(Q)MSSM DRbar
     2     6.41220985e-01   # g(Q)MSSM DRbar
     3     1.04544720e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.18405717e+03  
  3  3     8.51410161e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.18405717e+03  
  3  3     1.33444525e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.18405717e+03  
  3  3     1.00201855e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.18405717e+03 # Higgs mixing parameters
     1     8.20158991e+02    # mu(Q)MSSM DRbar
     2     9.63744618e+00    # tan beta(Q)MSSM DRbar
     3     2.43742902e+02    # higgs vev(Q)MSSM DRbar
     4     1.09377811e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.18405717e+03  # MSSM DRbar SUSY breaking parameters
     1     2.86443518e+02      # M_1(Q)
     2     5.27790444e+02      # M_2(Q)
     3     1.47073568e+03      # M_3(Q)
    21     3.64916420e+05      # mH1^2(Q)
    22    -6.42942631e+05      # mH2^2(Q)
    31     6.31135489e+02      # meL(Q)
    32     6.31128373e+02      # mmuL(Q)
    33     6.28977203e+02      # mtauL(Q)
    34     5.12681160e+02      # meR(Q)
    35     5.12663464e+02      # mmuR(Q)
    36     5.07294221e+02      # mtauR(Q)
    41     1.40090568e+03      # mqL1(Q)
    42     1.40090187e+03      # mqL2(Q)
    43     1.28028790e+03      # mqL3(Q)
    44     1.35157175e+03      # muR(Q)
    45     1.35156765e+03      # mcR(Q)
    46     1.08876339e+03      # mtR(Q)
    47     1.34553933e+03      # mdR(Q)
    48     1.34553542e+03      # msR(Q)
    49     1.33835426e+03      # mbR(Q)
Block au Q= 1.18405717e+03  
  1  1    -1.49018066e+03      # Au(Q)MSSM DRbar
  2  2    -1.49017406e+03      # Ac(Q)MSSM DRbar
  3  3    -1.15487501e+03      # At(Q)MSSM DRbar
Block ad Q= 1.18405717e+03  
  1  1    -1.81701861e+03      # Ad(Q)MSSM DRbar
  2  2    -1.81701252e+03      # As(Q)MSSM DRbar
  3  3    -1.69933297e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.18405717e+03  
  1  1    -3.98528285e+02      # Ae(Q)MSSM DRbar
  2  2    -3.98521255e+02      # Amu(Q)MSSM DRbar
  3  3    -3.96398296e+02      # Atau(Q)MSSM DRbar
