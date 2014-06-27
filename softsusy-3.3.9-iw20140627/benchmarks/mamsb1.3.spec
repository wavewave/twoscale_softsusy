# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    3   # amsb
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
     2    6.00000000e+04   # m3/2
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.30022894e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.20212351e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03918519e+01   # MW
        25     1.15409864e+02   # h0
        35     1.06453262e+03   # H0
        36     1.06437152e+03   # A0
        37     1.06764229e+03   # H+
   1000021    -1.28226785e+03   # ~g
   1000022     1.97415858e+02   # ~neutralino(1)
   1000023     5.49091367e+02   # ~neutralino(2)
   1000024     1.97585709e+02   # ~chargino(1)
   1000025    -1.02069857e+03   # ~neutralino(3)
   1000035     1.02661907e+03   # ~neutralino(4)
   1000037     1.02559451e+03   # ~chargino(2)
   1000039     6.00000000e+04   # ~gravitino
   1000001     1.27602361e+03   # ~d_L
   1000002     1.27371966e+03   # ~u_L
   1000003     1.27601588e+03   # ~s_L
   1000004     1.27371191e+03   # ~c_L
   1000005     1.10853333e+03   # ~b_1
   1000006     9.26015653e+02   # ~t_1
   1000011     3.87388779e+02   # ~e_L
   1000012     3.79011247e+02   # ~nue_L
   1000013     3.87371882e+02   # ~mu_L
   1000014     3.78994050e+02   # ~numu_L
   1000015     3.48477006e+02   # ~stau_1
   1000016     3.73707600e+02   # ~nu_tau_L
   2000001     1.28948827e+03   # ~d_R
   2000002     1.27993110e+03   # ~u_R
   2000003     1.28947998e+03   # ~s_R
   2000004     1.27992400e+03   # ~c_R
   2000005     1.27225778e+03   # ~b_2
   2000006     1.14253359e+03   # ~t_2
   2000011     3.74881565e+02   # ~e_R
   2000013     3.74846662e+02   # ~mu_R
   2000015     3.96446021e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05614311e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1    -3.77008312e-03   # N_{1,1}
  1  2     9.96454132e-01   # N_{1,2}
  1  3    -8.08643115e-02   # N_{1,3}
  1  4     2.29327959e-02   # N_{1,4}
  2  1     9.97183781e-01   # N_{2,1}
  2  2     9.81537877e-03   # N_{2,2}
  2  3     6.34826955e-02   # N_{2,3}
  2  4    -3.87054649e-02   # N_{2,4}
  3  1    -1.78549491e-02   # N_{3,1}
  3  2     4.08996056e-02   # N_{3,2}
  3  3     7.05428372e-01   # N_{3,3}
  3  4     7.07374890e-01   # N_{3,4}
  4  1    -7.27426598e-02   # N_{4,1}
  4  2     7.28700496e-02   # N_{4,2}
  4  3     7.01285764e-01   # N_{4,3}
  4  4    -7.05405372e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.93500408e-01   # U_{1,1}
  1  2    -1.13828554e-01   # U_{1,2}
  2  1     1.13828554e-01   # U_{2,1}
  2  2     9.93500408e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.99477459e-01   # V_{1,1}
  1  2    -3.23235170e-02   # V_{1,2}
  2  1     3.23235170e-02   # V_{2,1}
  2  2     9.99477459e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1    -3.61127017e-01   # F_{11}
  1  2     9.32516637e-01   # F_{12}
  2  1     9.32516637e-01   # F_{21}
  2  2     3.61127017e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.98813118e-01   # F_{11}
  1  2     4.87068353e-02   # F_{12}
  2  1    -4.87068353e-02   # F_{21}
  2  2     9.98813118e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     5.57696839e-01   # F_{11}
  1  2     8.30044719e-01   # F_{12}
  2  1     8.30044719e-01   # F_{21}
  2  2    -5.57696839e-01   # F_{22}
Block gauge Q= 9.91543258e+02  # SM gauge couplings
     1     3.62517714e-01   # g'(Q)MSSM DRbar
     2     6.44082627e-01   # g(Q)MSSM DRbar
     3     1.05399667e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.91543258e+02  
  3  3     8.57777940e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.91543258e+02  
  3  3     1.47581612e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.91543258e+02  
  3  3     9.92462253e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.91543258e+02 # Higgs mixing parameters
     1     1.02020148e+03    # mu(Q)MSSM DRbar
     2     9.65972700e+00    # tan beta(Q)MSSM DRbar
     3     2.44243457e+02    # higgs vev(Q)MSSM DRbar
     4     1.13330177e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.91543258e+02  # MSSM DRbar SUSY breaking parameters
     1     5.59602234e+02      # M_1(Q)
     2     1.90422221e+02      # M_2(Q)
     3    -1.22154506e+03      # M_3(Q)
    21     7.36616825e+04      # mH1^2(Q)
    22    -1.01740339e+06      # mH2^2(Q)
    31     3.83166358e+02      # meL(Q)
    32     3.83149342e+02      # mmuL(Q)
    33     3.78142930e+02      # mtauL(Q)
    34     3.67230900e+02      # meR(Q)
    35     3.67195377e+02      # mmuR(Q)
    36     3.56660351e+02      # mtauR(Q)
    41     1.23783674e+03      # mqL1(Q)
    42     1.23782876e+03      # mqL2(Q)
    43     1.07285285e+03      # mqL3(Q)
    44     1.24507892e+03      # muR(Q)
    45     1.24507160e+03      # mcR(Q)
    46     9.07645882e+02      # mtR(Q)
    47     1.25424935e+03      # mdR(Q)
    48     1.25424079e+03      # msR(Q)
    49     1.23650687e+03      # mbR(Q)
Block au Q= 9.91543258e+02  
  1  1     1.92812765e+03      # Au(Q)MSSM DRbar
  2  2     1.92811138e+03      # Ac(Q)MSSM DRbar
  3  3     1.09361033e+03      # At(Q)MSSM DRbar
Block ad Q= 9.91543258e+02  
  1  1     2.72566754e+03      # Ad(Q)MSSM DRbar
  2  2     2.72565250e+03      # As(Q)MSSM DRbar
  3  3     2.42743391e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.91543258e+02  
  1  1     5.88174853e+02      # Ae(Q)MSSM DRbar
  2  2     5.88136923e+02      # Amu(Q)MSSM DRbar
  3  3     5.76926623e+02      # Atau(Q)MSSM DRbar
