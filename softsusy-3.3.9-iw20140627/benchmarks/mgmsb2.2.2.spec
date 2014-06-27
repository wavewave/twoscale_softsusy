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
     1    1.30000000e+05   # lambda
     2    1.00000000e+14   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=5.95298101e-05
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03976316e+01   # MW
        25     1.14404269e+02   # h0
        35     8.71053038e+02   # H0
        36     8.71009003e+02   # A0
        37     8.74913557e+02   # H+
   1000021     9.90608969e+02   # ~g
   1000022     1.72902857e+02   # ~neutralino(1)
   1000023     3.33151656e+02   # ~neutralino(2)
   1000024     3.33259999e+02   # ~chargino(1)
   1000025    -6.91115307e+02   # ~neutralino(3)
   1000035     6.99060767e+02   # ~neutralino(4)
   1000037     6.99978925e+02   # ~chargino(2)
   1000039     3.08100000e+00   # ~gravitino
   1000001     1.21007566e+03   # ~d_L
   1000002     1.20762398e+03   # ~u_L
   1000003     1.21007084e+03   # ~s_L
   1000004     1.20761915e+03   # ~c_L
   1000005     1.06930921e+03   # ~b_1
   1000006     8.50684606e+02   # ~t_1
   1000011     5.80438309e+02   # ~e_L
   1000012     5.74681134e+02   # ~nue_L
   1000013     5.80425905e+02   # ~mu_L
   1000014     5.74668686e+02   # ~numu_L
   1000015     3.79742895e+02   # ~stau_1
   1000016     5.70612882e+02   # ~nu_tau_L
   2000001     1.08954991e+03   # ~d_R
   2000002     1.11106282e+03   # ~u_R
   2000003     1.08954275e+03   # ~s_R
   2000004     1.11105930e+03   # ~c_R
   2000005     1.09722299e+03   # ~b_2
   2000006     1.11163551e+03   # ~t_2
   2000011     3.93870085e+02   # ~e_R
   2000013     3.93833471e+02   # ~mu_R
   2000015     5.77978930e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.04404505e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.97076789e-01   # N_{1,1}
  1  2    -1.30627386e-02   # N_{1,2}
  1  3     7.17566674e-02   # N_{1,3}
  1  4    -2.27645167e-02   # N_{1,4}
  2  1     2.54618371e-02   # N_{2,1}
  2  2     9.85283960e-01   # N_{2,2}
  2  3    -1.49303230e-01   # N_{2,3}
  2  4     7.92196839e-02   # N_{2,4}
  3  1    -3.38077555e-02   # N_{3,1}
  3  2     5.05643317e-02   # N_{3,2}
  3  3     7.03583635e-01   # N_{3,3}
  3  4     7.08004486e-01   # N_{3,4}
  4  1    -6.36129561e-02   # N_{4,1}
  4  2     1.62751747e-01   # N_{4,2}
  4  3     6.91035162e-01   # N_{4,3}
  4  4    -7.01381256e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.77077945e-01   # U_{1,1}
  1  2    -2.12881866e-01   # U_{1,2}
  2  1     2.12881866e-01   # U_{2,1}
  2  2     9.77077945e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.93548341e-01   # V_{1,1}
  1  2    -1.13409412e-01   # V_{1,2}
  2  1     1.13409412e-01   # V_{2,1}
  2  2     9.93548341e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.26395654e-01   # F_{11}
  1  2     9.74035424e-01   # F_{12}
  2  1     9.74035424e-01   # F_{21}
  2  2    -2.26395654e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     4.84028123e-01   # F_{11}
  1  2     8.75052442e-01   # F_{12}
  2  1     8.75052442e-01   # F_{21}
  2  2    -4.84028123e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     9.70982925e-02   # F_{11}
  1  2     9.95274797e-01   # F_{12}
  2  1     9.95274797e-01   # F_{21}
  2  2    -9.70982925e-02   # F_{22}
Block gauge Q= 9.43699002e+02  # SM gauge couplings
     1     3.62400066e-01   # g'(Q)MSSM DRbar
     2     6.42751910e-01   # g(Q)MSSM DRbar
     3     1.06134222e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.43699002e+02  
  3  3     8.60620099e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.43699002e+02  
  3  3     1.98846248e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.43699002e+02  
  3  3     1.50881851e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.43699002e+02 # Higgs mixing parameters
     1     6.84864851e+02    # mu(Q)MSSM DRbar
     2     1.45125992e+01    # tan beta(Q)MSSM DRbar
     3     2.44047894e+02    # higgs vev(Q)MSSM DRbar
     4     7.92454354e+05    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.43699002e+02  # MSSM DRbar SUSY breaking parameters
     1     1.76028379e+02      # M_1(Q)
     2     3.27348978e+02      # M_2(Q)
     3     9.09164948e+02      # M_3(Q)
    21     2.83671830e+05      # mH1^2(Q)
    22    -4.55211561e+05      # mH2^2(Q)
    31     5.76906084e+02      # meL(Q)
    32     5.76893677e+02      # mmuL(Q)
    33     5.73115254e+02      # mtauL(Q)
    34     3.88979601e+02      # meR(Q)
    35     3.88942550e+02      # mmuR(Q)
    36     3.77524524e+02      # mtauR(Q)
    41     1.18163056e+03      # mqL1(Q)
    42     1.18162561e+03      # mqL2(Q)
    43     1.06626959e+03      # mqL3(Q)
    44     1.08331125e+03      # muR(Q)
    45     1.08330761e+03      # mcR(Q)
    46     8.21715182e+02      # mtR(Q)
    47     1.05972387e+03      # mdR(Q)
    48     1.05971643e+03      # msR(Q)
    49     1.04613179e+03      # mbR(Q)
Block au Q= 9.43699002e+02  
  1  1    -8.49436028e+02      # Au(Q)MSSM DRbar
  2  2    -8.49431723e+02      # Ac(Q)MSSM DRbar
  3  3    -6.74507467e+02      # At(Q)MSSM DRbar
Block ad Q= 9.43699002e+02  
  1  1    -1.01629765e+03      # Ad(Q)MSSM DRbar
  2  2    -1.01629169e+03      # As(Q)MSSM DRbar
  3  3    -9.50420936e+02      # Ab(Q)MSSM DRbar
Block ae Q= 9.43699002e+02  
  1  1    -1.86649221e+02      # Ae(Q)MSSM DRbar
  2  2    -1.86642763e+02      # Amu(Q)MSSM DRbar
  3  3    -1.84681419e+02      # Atau(Q)MSSM DRbar
