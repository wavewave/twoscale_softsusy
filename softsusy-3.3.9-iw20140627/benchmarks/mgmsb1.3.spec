# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    2   # gmsb
Block SMINPUTS             # Standard Model inputs
     1    1.27934000e+02   # alpha_em^(-1)(MZ) SM MSbar
     2    1.16637000e-05   # G_Fermi
     3    1.17200000e-01   # alpha_s(MZ)MSbar
     4    9.11876000e+01   # MZ(pole)
     5    4.25000000e+00   # mb(mb)
     6    1.73300000e+02   # Mtop(pole)
     7    1.77700000e+00   # Mtau(pole)
Block MINPAR               # SUSY breaking input parameters
     3    1.50000000e+01   # tanb
     4    1.00000000e+00   # sign(mu)
     1    4.50000000e+04   # lambda
     2    9.00000000e+04   # M_mess
     5    3.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=4.13470438e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04022027e+01   # MW
        25     1.12046737e+02   # h0
        35     4.31794113e+02   # H0
        36     4.31483488e+02   # A0
        37     4.39149467e+02   # H+
   1000021     1.05245702e+03   # ~g
   1000022     1.84859163e+02   # ~neutralino(1)
   1000023     3.04849357e+02   # ~neutralino(2)
   1000024     3.01859155e+02   # ~chargino(1)
   1000025    -3.48795647e+02   # ~neutralino(3)
   1000035     4.24314348e+02   # ~neutralino(4)
   1000037     4.24056390e+02   # ~chargino(2)
   1000039     9.59850000e-10   # ~gravitino
   1000001     1.00383717e+03   # ~d_L
   1000002     1.00081420e+03   # ~u_L
   1000003     1.00383590e+03   # ~s_L
   1000004     1.00081293e+03   # ~c_L
   1000005     9.55684269e+02   # ~b_1
   1000006     8.95299310e+02   # ~t_1
   1000011     2.94135405e+02   # ~e_L
   1000012     2.82913246e+02   # ~nue_L
   1000013     2.94134225e+02   # ~mu_L
   1000014     2.82912023e+02   # ~numu_L
   1000015     1.39383809e+02   # ~stau_1
   1000016     2.82352865e+02   # ~nu_tau_L
   2000001     9.64096481e+02   # ~d_R
   2000002     9.65952782e+02   # ~u_R
   2000003     9.64094718e+02   # ~s_R
   2000004     9.65951883e+02   # ~c_R
   2000005     9.71063645e+02   # ~b_2
   2000006     9.86097316e+02   # ~t_2
   2000011     1.45768623e+02   # ~e_R
   2000013     1.45763797e+02   # ~mu_R
   2000015     2.95710288e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.69044446e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.71223561e-01   # N_{1,1}
  1  2    -5.39631974e-02   # N_{1,2}
  1  3     2.00094437e-01   # N_{1,3}
  1  4    -1.17366882e-01   # N_{1,4}
  2  1    -2.12034572e-01   # N_{2,1}
  2  2    -6.13822919e-01   # N_{2,2}
  2  3     5.65301316e-01   # N_{2,3}
  2  4    -5.08622833e-01   # N_{2,4}
  3  1    -5.38969128e-02   # N_{3,1}
  3  2     7.26931810e-02   # N_{3,2}
  3  3     6.97921237e-01   # N_{3,3}
  3  4     7.10434213e-01   # N_{3,4}
  4  1    -9.41342573e-02   # N_{4,1}
  4  2     7.84235359e-01   # N_{4,2}
  4  3     3.91538741e-01   # N_{4,3}
  4  4    -4.72028661e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -5.51745317e-01   # U_{1,1}
  1  2     8.34012653e-01   # U_{1,2}
  2  1    -8.34012653e-01   # U_{2,1}
  2  2    -5.51745317e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -6.66168914e-01   # V_{1,1}
  1  2     7.45800897e-01   # V_{1,2}
  2  1    -7.45800897e-01   # V_{2,1}
  2  2    -6.66168914e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.32999157e-01   # F_{11}
  1  2     9.42927124e-01   # F_{12}
  2  1     9.42927124e-01   # F_{21}
  2  2    -3.32999157e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     5.36925622e-01   # F_{11}
  1  2     8.43629585e-01   # F_{12}
  2  1     8.43629585e-01   # F_{21}
  2  2    -5.36925622e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.35367050e-01   # F_{11}
  1  2     9.90795520e-01   # F_{12}
  2  1     9.90795520e-01   # F_{21}
  2  2    -1.35367050e-01   # F_{22}
Block gauge Q= 9.11118539e+02  # SM gauge couplings
     1     3.62885652e-01   # g'(Q)MSSM DRbar
     2     6.44415094e-01   # g(Q)MSSM DRbar
     3     1.06221075e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.11118539e+02  
  3  3     8.64761302e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.11118539e+02  
  3  3     2.05043653e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.11118539e+02  
  3  3     1.51969327e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.11118539e+02 # Higgs mixing parameters
     1     3.39955141e+02    # mu(Q)MSSM DRbar
     2     1.45173671e+01    # tan beta(Q)MSSM DRbar
     3     2.43803969e+02    # higgs vev(Q)MSSM DRbar
     4     2.12497595e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.11118539e+02  # MSSM DRbar SUSY breaking parameters
     1     1.94940793e+02      # M_1(Q)
     2     3.67497831e+02      # M_2(Q)
     3     1.00341289e+03      # M_3(Q)
    21     7.05612302e+04      # mH1^2(Q)
    22    -1.02349575e+05      # mH2^2(Q)
    31     2.85058007e+02      # meL(Q)
    32     2.85056795e+02      # mmuL(Q)
    33     2.84684394e+02      # mtauL(Q)
    34     1.33835485e+02      # meR(Q)
    35     1.33830240e+02      # mmuR(Q)
    36     1.32209342e+02      # mtauR(Q)
    41     9.65416668e+02      # mqL1(Q)
    42     9.65415368e+02      # mqL2(Q)
    43     9.34577856e+02      # mqL3(Q)
    44     9.30612553e+02      # muR(Q)
    45     9.30611632e+02      # mcR(Q)
    46     8.67983455e+02      # mtR(Q)
    47     9.27470524e+02      # mdR(Q)
    48     9.27468715e+02      # msR(Q)
    49     9.23946498e+02      # mbR(Q)
Block au Q= 9.11118539e+02  
  1  1    -3.03324719e+02      # Au(Q)MSSM DRbar
  2  2    -3.03324290e+02      # Ac(Q)MSSM DRbar
  3  3    -2.85892613e+02      # At(Q)MSSM DRbar
Block ad Q= 9.11118539e+02  
  1  1    -3.22735423e+02      # Ad(Q)MSSM DRbar
  2  2    -3.22734824e+02      # As(Q)MSSM DRbar
  3  3    -3.16164117e+02      # Ab(Q)MSSM DRbar
Block ae Q= 9.11118539e+02  
  1  1    -3.07531305e+01      # Ae(Q)MSSM DRbar
  2  2    -3.07529062e+01      # Amu(Q)MSSM DRbar
  3  3    -3.06839939e+01      # Atau(Q)MSSM DRbar
