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
     1    5.50000000e+04   # lambda
     2    1.10000000e+05   # M_mess
     5    3.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.28809918e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.04003439e+01   # MW
        25     1.13490918e+02   # h0
        35     5.21240283e+02   # H0
        36     5.20983332e+02   # A0
        37     5.27356985e+02   # H+
   1000021     1.26173541e+03   # ~g
   1000022     2.28535920e+02   # ~neutralino(1)
   1000023     3.75233305e+02   # ~neutralino(2)
   1000024     3.72562599e+02   # ~chargino(1)
   1000025    -4.13392043e+02   # ~neutralino(3)
   1000035     4.99918093e+02   # ~neutralino(4)
   1000037     4.99687271e+02   # ~chargino(2)
   1000039     1.43385000e-09   # ~gravitino
   1000001     1.20490141e+03   # ~d_L
   1000002     1.20241253e+03   # ~u_L
   1000003     1.20489990e+03   # ~s_L
   1000004     1.20241101e+03   # ~c_L
   1000005     1.14763301e+03   # ~b_1
   1000006     1.07335363e+03   # ~t_1
   1000011     3.57185978e+02   # ~e_L
   1000012     3.47962038e+02   # ~nue_L
   1000013     3.57184529e+02   # ~mu_L
   1000014     3.47960556e+02   # ~numu_L
   1000015     1.70022319e+02   # ~stau_1
   1000016     3.47284423e+02   # ~nu_tau_L
   2000001     1.15609474e+03   # ~d_R
   2000002     1.15885504e+03   # ~u_R
   2000003     1.15609263e+03   # ~s_R
   2000004     1.15885396e+03   # ~c_R
   2000005     1.16431493e+03   # ~b_2
   2000006     1.17679756e+03   # ~t_2
   2000011     1.75959744e+02   # ~e_R
   2000013     1.75953790e+02   # ~mu_R
   2000015     3.58201824e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.44799294e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.79037821e-01   # N_{1,1}
  1  2    -3.93672194e-02   # N_{1,2}
  1  3     1.70915466e-01   # N_{1,3}
  1  4    -1.03552261e-01   # N_{1,4}
  2  1    -1.83725028e-01   # N_{2,1}
  2  2    -5.63239041e-01   # N_{2,2}
  2  3     5.90958793e-01   # N_{2,3}
  2  4    -5.47516759e-01   # N_{2,4}
  3  1    -4.48716816e-02   # N_{3,1}
  3  2     6.02111505e-02   # N_{3,2}
  3  3     7.00738732e-01   # N_{3,3}
  3  4     7.09454988e-01   # N_{3,4}
  4  1    -7.56081454e-02   # N_{4,1}
  4  2     8.23156499e-01   # N_{4,2}
  4  3     3.61276678e-01   # N_{4,3}
  4  4    -4.31481110e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1    -5.08301827e-01   # U_{1,1}
  1  2     8.61178990e-01   # U_{1,2}
  2  1    -8.61178990e-01   # U_{2,1}
  2  2    -5.08301827e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1    -6.07684967e-01   # V_{1,1}
  1  2     7.94178180e-01   # V_{1,2}
  2  1    -7.94178180e-01   # V_{2,1}
  2  2    -6.07684967e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.84791660e-01   # F_{11}
  1  2     9.58589438e-01   # F_{12}
  2  1     9.58589438e-01   # F_{21}
  2  2    -2.84791660e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.68307850e-01   # F_{11}
  1  2     8.83565367e-01   # F_{12}
  2  1     8.83565367e-01   # F_{21}
  2  2    -4.68307850e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.09732795e-01   # F_{11}
  1  2     9.93961123e-01   # F_{12}
  2  1     9.93961123e-01   # F_{21}
  2  2    -1.09732795e-01   # F_{22}
Block gauge Q= 1.09054802e+03  # SM gauge couplings
     1     3.63267418e-01   # g'(Q)MSSM DRbar
     2     6.43394097e-01   # g(Q)MSSM DRbar
     3     1.05266438e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.09054802e+03  
  3  3     8.58368621e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.09054802e+03  
  3  3     2.03132813e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.09054802e+03  
  3  3     1.51776002e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.09054802e+03 # Higgs mixing parameters
     1     4.04625844e+02    # mu(Q)MSSM DRbar
     2     1.44867358e+01    # tan beta(Q)MSSM DRbar
     3     2.43599004e+02    # higgs vev(Q)MSSM DRbar
     4     3.09090372e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.09054802e+03  # MSSM DRbar SUSY breaking parameters
     1     2.38808717e+02      # M_1(Q)
     2     4.47862592e+02      # M_2(Q)
     3     1.20463535e+03      # M_3(Q)
    21     1.05466835e+05      # mH1^2(Q)
    22    -1.42379060e+05      # mH2^2(Q)
    31     3.47483338e+02      # meL(Q)
    32     3.47481858e+02      # mmuL(Q)
    33     3.47025974e+02      # mtauL(Q)
    34     1.64108719e+02      # meR(Q)
    35     1.64102351e+02      # mmuR(Q)
    36     1.62130086e+02      # mtauR(Q)
    41     1.16012223e+03      # mqL1(Q)
    42     1.16012068e+03      # mqL2(Q)
    43     1.12329065e+03      # mqL3(Q)
    44     1.11707456e+03      # muR(Q)
    45     1.11707346e+03      # mcR(Q)
    46     1.04218593e+03      # mtR(Q)
    47     1.11313379e+03      # mdR(Q)
    48     1.11313163e+03      # msR(Q)
    49     1.10893784e+03      # mbR(Q)
Block au Q= 1.09054802e+03  
  1  1    -3.61154604e+02      # Au(Q)MSSM DRbar
  2  2    -3.61154097e+02      # Ac(Q)MSSM DRbar
  3  3    -3.40565876e+02      # At(Q)MSSM DRbar
Block ad Q= 1.09054802e+03  
  1  1    -3.83972300e+02      # Ad(Q)MSSM DRbar
  2  2    -3.83971593e+02      # As(Q)MSSM DRbar
  3  3    -3.76216534e+02      # Ab(Q)MSSM DRbar
Block ae Q= 1.09054802e+03  
  1  1    -3.76467995e+01      # Ae(Q)MSSM DRbar
  2  2    -3.76465252e+01      # Amu(Q)MSSM DRbar
  3  3    -3.75620991e+01      # Atau(Q)MSSM DRbar
