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
     1    1.75000000e+02   # m0
     2    7.00000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.67790026e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.86747709e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03934018e+01   # MW
        25     1.17043622e+02   # h0
        35     9.77200061e+02   # H0
        36     9.76997027e+02   # A0
        37     9.80509639e+02   # H+
   1000021     1.56472041e+03   # ~g
   1000022     2.91383646e+02   # ~neutralino(1)
   1000023     5.51267893e+02   # ~neutralino(2)
   1000024     5.51360010e+02   # ~chargino(1)
   1000025    -8.53787659e+02   # ~neutralino(3)
   1000035     8.65237445e+02   # ~neutralino(4)
   1000037     8.65433256e+02   # ~chargino(2)
   1000001     1.43572561e+03   # ~d_L
   1000002     1.43368227e+03   # ~u_L
   1000003     1.43572215e+03   # ~s_L
   1000004     1.43367881e+03   # ~c_L
   1000005     1.31647415e+03   # ~b_1
   1000006     1.10970022e+03   # ~t_1
   1000011     5.01772039e+02   # ~e_L
   1000012     4.95319924e+02   # ~nue_L
   1000013     5.01767548e+02   # ~mu_L
   1000014     4.95315397e+02   # ~numu_L
   1000015     3.11187579e+02   # ~stau_1
   1000016     4.93732736e+02   # ~nu_tau_L
   2000001     1.37264718e+03   # ~d_R
   2000002     1.37815903e+03   # ~u_R
   2000003     1.37264358e+03   # ~s_R
   2000004     1.37815532e+03   # ~c_R
   2000005     1.36710730e+03   # ~b_2
   2000006     1.35152697e+03   # ~t_2
   2000011     3.18456782e+02   # ~e_R
   2000013     3.18442490e+02   # ~mu_R
   2000015     5.01770158e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05492023e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97675473e-01   # N_{1,1}
  1  2    -9.67187544e-03   # N_{1,2}
  1  3     6.18931644e-02   # N_{1,3}
  1  4    -2.68205604e-02   # N_{1,4}
  2  1     2.25782537e-02   # N_{2,1}
  2  2     9.80059896e-01   # N_{2,2}
  2  3    -1.61749008e-01   # N_{2,3}
  2  4     1.13181631e-01   # N_{2,4}
  3  1    -2.43764929e-02   # N_{3,1}
  3  2     3.52004347e-02   # N_{3,2}
  3  3     7.05138167e-01   # N_{3,3}
  3  4     7.07776010e-01   # N_{3,4}
  4  1    -5.94950459e-02   # N_{4,1}
  4  2     1.95320211e-01   # N_{4,2}
  4  3     6.87594837e-01   # N_{4,3}
  4  4    -6.96795304e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.73073985e-01   # U_{1,1}
  1  2    -2.30492993e-01   # U_{1,2}
  2  1     2.30492993e-01   # U_{2,1}
  2  2     9.73073985e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.86844829e-01   # V_{1,1}
  1  2    -1.61670290e-01   # V_{1,2}
  2  1     1.61670290e-01   # V_{2,1}
  2  2     9.86844829e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     3.48688177e-01   # F_{11}
  1  2     9.37238793e-01   # F_{12}
  2  1     9.37238793e-01   # F_{21}
  2  2    -3.48688177e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.85071449e-01   # F_{11}
  1  2     1.72145986e-01   # F_{12}
  2  1    -1.72145986e-01   # F_{21}
  2  2     9.85071449e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.00669375e-01   # F_{11}
  1  2     9.94919935e-01   # F_{12}
  2  1     9.94919935e-01   # F_{21}
  2  2    -1.00669375e-01   # F_{22}
Block gauge Q= 1.18926660e+03  # SM gauge couplings
     1     3.63062042e-01   # g'(Q)MSSM DRbar
     2     6.41314549e-01   # g(Q)MSSM DRbar
     3     1.04483359e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.18926660e+03  
  3  3     8.50684683e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.18926660e+03  
  3  3     1.33202956e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.18926660e+03  
  3  3     1.00300029e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.18926660e+03 # Higgs mixing parameters
     1     8.48266350e+02    # mu(Q)MSSM DRbar
     2     9.63740310e+00    # tan beta(Q)MSSM DRbar
     3     2.43760724e+02    # higgs vev(Q)MSSM DRbar
     4     9.88726092e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.18926660e+03  # MSSM DRbar SUSY breaking parameters
     1     2.97409298e+02      # M_1(Q)
     2     5.47600235e+02      # M_2(Q)
     3     1.52266576e+03      # M_3(Q)
    21     2.13361240e+05      # mH1^2(Q)
    22    -6.91376592e+05      # mH2^2(Q)
    31     4.92904758e+02      # meL(Q)
    32     4.92900214e+02      # mmuL(Q)
    33     4.91524894e+02      # mtauL(Q)
    34     3.10275172e+02      # meR(Q)
    35     3.10260489e+02      # mmuR(Q)
    36     3.05789509e+02      # mtauR(Q)
    41     1.38742509e+03      # mqL1(Q)
    42     1.38742158e+03      # mqL2(Q)
    43     1.27994929e+03      # mqL3(Q)
    44     1.33325162e+03      # muR(Q)
    45     1.33324785e+03      # mcR(Q)
    46     1.09931684e+03      # mtR(Q)
    47     1.32659022e+03      # mdR(Q)
    48     1.32658656e+03      # msR(Q)
    49     1.31993128e+03      # mbR(Q)
Block au Q= 1.18926660e+03  
  1  1    -1.54178088e+03      # Au(Q)MSSM DRbar
  2  2    -1.54177405e+03      # Ac(Q)MSSM DRbar
  3  3    -1.19569030e+03      # At(Q)MSSM DRbar
Block ad Q= 1.18926660e+03  
  1  1    -1.87905474e+03      # Ad(Q)MSSM DRbar
  2  2    -1.87904843e+03      # As(Q)MSSM DRbar
  3  3    -1.75759885e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.18926660e+03  
  1  1    -4.12741911e+02      # Ae(Q)MSSM DRbar
  2  2    -4.12734645e+02      # Amu(Q)MSSM DRbar
  3  3    -4.10535590e+02      # Atau(Q)MSSM DRbar
