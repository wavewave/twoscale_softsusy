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
     1    5.50000000e+02   # m0
     2    4.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.02197550e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=7.41101795e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03910848e+01   # MW
        25     1.16560209e+02   # h0
        35     6.30938938e+02   # H0
        36     6.30910927e+02   # A0
        37     6.36449929e+02   # H+
   1000021     1.06318937e+03   # ~g
   1000022     1.86425559e+02   # ~neutralino(1)
   1000023     3.55656568e+02   # ~neutralino(2)
   1000024     3.55773643e+02   # ~chargino(1)
   1000025    -6.44992690e+02   # ~neutralino(3)
   1000035     6.53677297e+02   # ~neutralino(4)
   1000037     6.54957183e+02   # ~chargino(2)
   1000001     1.09460470e+03   # ~d_L
   1000002     1.09186755e+03   # ~u_L
   1000003     1.09456971e+03   # ~s_L
   1000004     1.09183245e+03   # ~c_L
   1000005     8.95282203e+02   # ~b_1
   1000006     7.50183323e+02   # ~t_1
   1000011     6.27371976e+02   # ~e_L
   1000012     6.21994909e+02   # ~nue_L
   1000013     6.27201249e+02   # ~mu_L
   1000014     6.21823941e+02   # ~numu_L
   1000015     4.23392188e+02   # ~stau_1
   1000016     5.64287223e+02   # ~nu_tau_L
   2000001     1.06129842e+03   # ~d_R
   2000002     1.06354058e+03   # ~u_R
   2000003     1.06122974e+03   # ~s_R
   2000004     1.06353617e+03   # ~c_R
   2000005     9.69667875e+02   # ~b_2
   2000006     9.60082747e+02   # ~t_2
   2000011     5.76242670e+02   # ~e_R
   2000013     5.75870164e+02   # ~mu_R
   2000015     5.84034872e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.60620516e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.96575380e-01   # N_{1,1}
  1  2    -1.21182564e-02   # N_{1,2}
  1  3     7.79459550e-02   # N_{1,3}
  1  4    -2.48009486e-02   # N_{1,4}
  2  1     2.78897394e-02   # N_{2,1}
  2  2     9.79608922e-01   # N_{2,2}
  2  3    -1.73026747e-01   # N_{2,3}
  2  4     9.82357784e-02   # N_{2,4}
  3  1    -3.67067932e-02   # N_{3,1}
  3  2     5.42134791e-02   # N_{3,2}
  3  3     7.03052028e-01   # N_{3,3}
  3  4     7.08118179e-01   # N_{3,4}
  4  1    -6.86460841e-02   # N_{4,1}
  4  2     1.93081349e-01   # N_{4,2}
  4  3     6.85349559e-01   # N_{4,3}
  4  4    -6.98787013e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.69098863e-01   # U_{1,1}
  1  2    -2.46672646e-01   # U_{1,2}
  2  1     2.46672646e-01   # U_{2,1}
  2  2     9.69098863e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.90068518e-01   # V_{1,1}
  1  2    -1.40585664e-01   # V_{1,2}
  2  1     1.40585664e-01   # V_{2,1}
  2  2     9.90068518e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.51820754e-01   # F_{11}
  1  2     8.92108741e-01   # F_{12}
  2  1     8.92108741e-01   # F_{21}
  2  2    -4.51820754e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     8.88884060e-01   # F_{11}
  1  2     4.58132217e-01   # F_{12}
  2  1    -4.58132217e-01   # F_{21}
  2  2     8.88884060e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     3.13501946e-01   # F_{11}
  1  2     9.49587558e-01   # F_{12}
  2  1     9.49587558e-01   # F_{21}
  2  2    -3.13501946e-01   # F_{22}
Block gauge Q= 8.23117435e+02  # SM gauge couplings
     1     3.61863495e-01   # g'(Q)MSSM DRbar
     2     6.42453062e-01   # g(Q)MSSM DRbar
     3     1.06387660e+00   # g3(Q)MSSM DRbar
Block yu Q= 8.23117435e+02  
  3  3     8.58488300e-01   # Yt(Q)MSSM DRbar
Block yd Q= 8.23117435e+02  
  3  3     4.97304759e-01   # Yb(Q)MSSM DRbar
Block ye Q= 8.23117435e+02  
  3  3     4.23565556e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 8.23117435e+02 # Higgs mixing parameters
     1     6.40358356e+02    # mu(Q)MSSM DRbar
     2     3.92490005e+01    # tan beta(Q)MSSM DRbar
     3     2.44087364e+02    # higgs vev(Q)MSSM DRbar
     4     5.09551900e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 8.23117435e+02  # MSSM DRbar SUSY breaking parameters
     1     1.88921430e+02      # M_1(Q)
     2     3.51467001e+02      # M_2(Q)
     3     1.01087159e+03      # M_3(Q)
    21    -3.01388454e+03      # mH1^2(Q)
    22    -4.04645250e+05      # mH2^2(Q)
    31     6.23756060e+02      # meL(Q)
    32     6.23585513e+02      # mmuL(Q)
    33     5.68121813e+02      # mtauL(Q)
    34     5.73354028e+02      # meR(Q)
    35     5.72980047e+02      # mmuR(Q)
    36     4.41258928e+02      # mtauR(Q)
    41     1.06299422e+03      # mqL1(Q)
    42     1.06295796e+03      # mqL2(Q)
    43     8.85958066e+02      # mqL3(Q)
    44     1.03452787e+03      # muR(Q)
    45     1.03452331e+03      # mcR(Q)
    46     7.58311522e+02      # mtR(Q)
    47     1.03117993e+03      # mdR(Q)
    48     1.03110892e+03      # msR(Q)
    49     9.26480687e+02      # mbR(Q)
Block au Q= 8.23117435e+02  
  1  1    -1.37478655e+03      # Au(Q)MSSM DRbar
  2  2    -1.37475215e+03      # Ac(Q)MSSM DRbar
  3  3    -9.37347447e+02      # At(Q)MSSM DRbar
Block ad Q= 8.23117435e+02  
  1  1    -1.60153422e+03      # Ad(Q)MSSM DRbar
  2  2    -1.60144661e+03      # As(Q)MSSM DRbar
  3  3    -1.33779438e+03      # Ab(Q)MSSM DRbar
Block ae Q= 8.23117435e+02  
  1  1    -6.02572739e+02      # Ae(Q)MSSM DRbar
  2  2    -6.02265515e+02      # Amu(Q)MSSM DRbar
  3  3    -5.01609838e+02      # Atau(Q)MSSM DRbar
