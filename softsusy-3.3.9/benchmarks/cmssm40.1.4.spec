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
     1    3.75000000e+02   # m0
     2    6.50000000e+02   # m12
     5   -5.00000000e+02   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.71624646e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=9.24524561e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03886879e+01   # MW
        25     1.18308920e+02   # h0
        35     7.58115282e+02   # H0
        36     7.58120257e+02   # A0
        37     7.62665376e+02   # H+
   1000021     1.46727874e+03   # ~g
   1000022     2.72324154e+02   # ~neutralino(1)
   1000023     5.18124550e+02   # ~neutralino(2)
   1000024     5.18265832e+02   # ~chargino(1)
   1000025    -8.60813206e+02   # ~neutralino(3)
   1000035     8.68429008e+02   # ~neutralino(4)
   1000037     8.69329146e+02   # ~chargino(2)
   1000001     1.38375687e+03   # ~d_L
   1000002     1.38158888e+03   # ~u_L
   1000003     1.38371877e+03   # ~s_L
   1000004     1.38155071e+03   # ~c_L
   1000005     1.16924180e+03   # ~b_1
   1000006     1.01167387e+03   # ~t_1
   1000011     5.75708851e+02   # ~e_L
   1000012     5.69951127e+02   # ~nue_L
   1000013     5.75566979e+02   # ~mu_L
   1000014     5.69808680e+02   # ~numu_L
   1000015     2.72394831e+02   # ~stau_1
   1000016     5.20575765e+02   # ~nu_tau_L
   2000001     1.32750302e+03   # ~d_R
   2000002     1.33228503e+03   # ~u_R
   2000003     1.32742723e+03   # ~s_R
   2000004     1.33228021e+03   # ~c_R
   2000005     1.23480532e+03   # ~b_2
   2000006     1.23564953e+03   # ~t_2
   2000011     4.48955353e+02   # ~e_R
   2000013     4.48587867e+02   # ~mu_R
   2000015     5.46001322e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -2.60025512e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.98034056e-01   # N_{1,1}
  1  2    -6.88787525e-03   # N_{1,2}
  1  3     5.88867065e-02   # N_{1,3}
  1  4    -2.03208089e-02   # N_{1,4}
  2  1     1.69719393e-02   # N_{2,1}
  2  2     9.85824319e-01   # N_{2,2}
  2  3    -1.42133819e-01   # N_{2,3}
  2  4     8.75233901e-02   # N_{2,4}
  3  1    -2.69124839e-02   # N_{3,1}
  3  2     3.92683843e-02   # N_{3,2}
  3  3     7.04925247e-01   # N_{3,3}
  3  4     7.07682209e-01   # N_{3,4}
  4  1    -5.39971646e-02   # N_{4,1}
  4  2     1.62975348e-01   # N_{4,2}
  4  3     6.92394923e-01   # N_{4,3}
  4  4    -7.00794272e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.79328146e-01   # U_{1,1}
  1  2    -2.02277984e-01   # U_{1,2}
  2  1     2.02277984e-01   # U_{2,1}
  2  2     9.79328146e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.92158877e-01   # V_{1,1}
  1  2    -1.24983050e-01   # V_{1,2}
  2  1     1.24983050e-01   # V_{2,1}
  2  2     9.92158877e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     4.17875018e-01   # F_{11}
  1  2     9.08504524e-01   # F_{12}
  2  1     9.08504524e-01   # F_{21}
  2  2    -4.17875018e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     8.08908552e-01   # F_{11}
  1  2     5.87934482e-01   # F_{12}
  2  1    -5.87934482e-01   # F_{21}
  2  2     8.08908552e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     3.02966099e-01   # F_{11}
  1  2     9.53001334e-01   # F_{12}
  2  1     9.53001334e-01   # F_{21}
  2  2    -3.02966099e-01   # F_{22}
Block gauge Q= 1.08706487e+03  # SM gauge couplings
     1     3.62685065e-01   # g'(Q)MSSM DRbar
     2     6.41137384e-01   # g(Q)MSSM DRbar
     3     1.04857635e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.08706487e+03  
  3  3     8.48084657e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.08706487e+03  
  3  3     4.89904405e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.08706487e+03  
  3  3     4.27865073e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.08706487e+03 # Higgs mixing parameters
     1     8.57816335e+02    # mu(Q)MSSM DRbar
     2     3.91757375e+01    # tan beta(Q)MSSM DRbar
     3     2.43738697e+02    # higgs vev(Q)MSSM DRbar
     4     7.28517226e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.08706487e+03  # MSSM DRbar SUSY breaking parameters
     1     2.76577978e+02      # M_1(Q)
     2     5.10367908e+02      # M_2(Q)
     3     1.42573129e+03      # M_3(Q)
    21    -1.63092368e+05      # mH1^2(Q)
    22    -7.21531136e+05      # mH2^2(Q)
    31     5.68931038e+02      # meL(Q)
    32     5.68787834e+02      # mmuL(Q)
    33     5.22709239e+02      # mtauL(Q)
    34     4.43880501e+02      # meR(Q)
    35     4.43508773e+02      # mmuR(Q)
    36     3.07313024e+02      # mtauR(Q)
    41     1.34026217e+03      # mqL1(Q)
    42     1.34022333e+03      # mqL2(Q)
    43     1.16072026e+03      # mqL3(Q)
    44     1.29200583e+03      # muR(Q)
    45     1.29200094e+03      # mcR(Q)
    46     1.01384746e+03      # mtR(Q)
    47     1.28614727e+03      # mdR(Q)
    48     1.28607025e+03      # msR(Q)
    49     1.17580535e+03      # mbR(Q)
Block au Q= 1.08706487e+03  
  1  1    -1.78771101e+03      # Au(Q)MSSM DRbar
  2  2    -1.78766909e+03      # Ac(Q)MSSM DRbar
  3  3    -1.25732017e+03      # At(Q)MSSM DRbar
Block ad Q= 1.08706487e+03  
  1  1    -2.06510901e+03      # Ad(Q)MSSM DRbar
  2  2    -2.06500226e+03      # As(Q)MSSM DRbar
  3  3    -1.74605087e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.08706487e+03  
  1  1    -6.86158558e+02      # Ae(Q)MSSM DRbar
  2  2    -6.85825526e+02      # Amu(Q)MSSM DRbar
  3  3    -5.74035182e+02      # Atau(Q)MSSM DRbar
