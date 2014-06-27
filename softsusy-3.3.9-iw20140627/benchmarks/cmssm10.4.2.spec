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
     1    8.50000000e+02   # m0
     2    4.00000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    2.21120347e+16   # MX scale
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=2.24014024e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03976191e+01   # MW
        25     1.14022098e+02   # h0
        35     1.01399572e+03   # H0
        36     1.01394741e+03   # A0
        37     1.01720913e+03   # H+
   1000021     9.76358733e+02   # ~g
   1000022     1.63864557e+02   # ~neutralino(1)
   1000023     3.09431760e+02   # ~neutralino(2)
   1000024     3.09342208e+02   # ~chargino(1)
   1000025    -5.24849852e+02   # ~neutralino(3)
   1000035     5.41079889e+02   # ~neutralino(4)
   1000037     5.41355359e+02   # ~chargino(2)
   1000001     1.18774212e+03   # ~d_L
   1000002     1.18527038e+03   # ~u_L
   1000003     1.18773798e+03   # ~s_L
   1000004     1.18526623e+03   # ~c_L
   1000005     1.03079336e+03   # ~b_1
   1000006     8.22265230e+02   # ~t_1
   1000011     8.88837930e+02   # ~e_L
   1000012     8.85002740e+02   # ~nue_L
   1000013     8.88825685e+02   # ~mu_L
   1000014     8.84990551e+02   # ~numu_L
   1000015     8.54334656e+02   # ~stau_1
   1000016     8.81264397e+02   # ~nu_tau_L
   2000001     1.16508602e+03   # ~d_R
   2000002     1.16633155e+03   # ~u_R
   2000003     1.16508199e+03   # ~s_R
   2000004     1.16632710e+03   # ~c_R
   2000005     1.15725963e+03   # ~b_2
   2000006     1.05751770e+03   # ~t_2
   2000011     8.63017148e+02   # ~e_R
   2000013     8.62992039e+02   # ~mu_R
   2000015     8.86055714e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -1.05047307e-01       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.93659136e-01   # N_{1,1}
  1  2    -2.54605250e-02   # N_{1,2}
  1  3     1.01462333e-01   # N_{1,3}
  1  4    -4.12150347e-02   # N_{1,4}
  2  1     5.41991860e-02   # N_{2,1}
  2  2     9.60332000e-01   # N_{2,2}
  2  3    -2.29099165e-01   # N_{2,3}
  2  4     1.49460598e-01   # N_{2,4}
  3  1    -4.07308828e-02   # N_{3,1}
  3  2     5.93883457e-02   # N_{3,2}
  3  3     7.01719327e-01   # N_{3,3}
  3  4     7.08804632e-01   # N_{3,4}
  4  1    -8.96937332e-02   # N_{4,1}
  4  2     2.71269673e-01   # N_{4,2}
  4  3     6.66939993e-01   # N_{4,3}
  4  4    -6.88156120e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.43969123e-01   # U_{1,1}
  1  2    -3.30033778e-01   # U_{1,2}
  2  1     3.30033778e-01   # U_{2,1}
  2  2     9.43969123e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.76321649e-01   # V_{1,1}
  1  2    -2.16323920e-01   # V_{1,2}
  2  1     2.16323920e-01   # V_{2,1}
  2  2     9.76321649e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     2.79639567e-01   # F_{11}
  1  2     9.60105053e-01   # F_{12}
  2  1     9.60105053e-01   # F_{21}
  2  2    -2.79639567e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     9.98641573e-01   # F_{11}
  1  2     5.21057359e-02   # F_{12}
  2  1    -5.21057359e-02   # F_{21}
  2  2     9.98641573e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     1.74424550e-01   # F_{11}
  1  2     9.84670542e-01   # F_{12}
  2  1     9.84670542e-01   # F_{21}
  2  2    -1.74424550e-01   # F_{22}
Block gauge Q= 9.06828040e+02  # SM gauge couplings
     1     3.62006509e-01   # g'(Q)MSSM DRbar
     2     6.42823051e-01   # g(Q)MSSM DRbar
     3     1.06242239e+00   # g3(Q)MSSM DRbar
Block yu Q= 9.06828040e+02  
  3  3     8.64664778e-01   # Yt(Q)MSSM DRbar
Block yd Q= 9.06828040e+02  
  3  3     1.36732937e-01   # Yb(Q)MSSM DRbar
Block ye Q= 9.06828040e+02  
  3  3     9.96780573e-02   # Ytau(Q)MSSM DRbar
Block hmix Q= 9.06828040e+02 # Higgs mixing parameters
     1     5.17374234e+02    # mu(Q)MSSM DRbar
     2     9.66569926e+00    # tan beta(Q)MSSM DRbar
     3     2.43891255e+02    # higgs vev(Q)MSSM DRbar
     4     1.04982059e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 9.06828040e+02  # MSSM DRbar SUSY breaking parameters
     1     1.66999415e+02      # M_1(Q)
     2     3.10475321e+02      # M_2(Q)
     3     8.94171860e+02      # M_3(Q)
    21     7.50482199e+05      # mH1^2(Q)
    22    -2.46326283e+05      # mH2^2(Q)
    31     8.86101186e+02      # meL(Q)
    32     8.86089035e+02      # mmuL(Q)
    33     8.82478909e+02      # mtauL(Q)
    34     8.60818560e+02      # meR(Q)
    35     8.60793422e+02      # mmuR(Q)
    36     8.53306541e+02      # mtauR(Q)
    41     1.16032504e+03      # mqL1(Q)
    42     1.16032078e+03      # mqL2(Q)
    43     1.00685835e+03      # mqL3(Q)
    44     1.14176967e+03      # muR(Q)
    45     1.14176509e+03      # mcR(Q)
    46     8.03810605e+02      # mtR(Q)
    47     1.13962037e+03      # mdR(Q)
    48     1.13961621e+03      # msR(Q)
    49     1.13161900e+03      # mbR(Q)
Block au Q= 9.06828040e+02  
  1  1    -9.16500905e+02      # Au(Q)MSSM DRbar
  2  2    -9.16496794e+02      # Ac(Q)MSSM DRbar
  3  3    -7.04980031e+02      # At(Q)MSSM DRbar
Block ad Q= 9.06828040e+02  
  1  1    -1.12355709e+03      # Ad(Q)MSSM DRbar
  2  2    -1.12355328e+03      # As(Q)MSSM DRbar
  3  3    -1.04923432e+03      # Ab(Q)MSSM DRbar
Block ae Q= 9.06828040e+02  
  1  1    -2.40109700e+02      # Ae(Q)MSSM DRbar
  2  2    -2.40105370e+02      # Amu(Q)MSSM DRbar
  3  3    -2.38821296e+02      # Atau(Q)MSSM DRbar
