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
     1    1.70000000e+05   # lambda
     2    1.00000000e+14   # M_mess
     5    1.00000000e+00   # N5
     6    1.00000000e+00   # cgrav
# SOFTSUSY-specific non SLHA information:
# MIXING=0 Desired accuracy=1.00000000e-03 Achieved accuracy=1.36629603e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.03954588e+01   # MW
        25     1.16192711e+02   # h0
        35     1.11959851e+03   # H0
        36     1.11955598e+03   # A0
        37     1.12263570e+03   # H+
   1000021     1.26309128e+03   # ~g
   1000022     2.27572853e+02   # ~neutralino(1)
   1000023     4.38363021e+02   # ~neutralino(2)
   1000024     4.38499499e+02   # ~chargino(1)
   1000025    -8.78017557e+02   # ~neutralino(3)
   1000035     8.84575904e+02   # ~neutralino(4)
   1000037     8.85312381e+02   # ~chargino(2)
   1000039     4.02900000e+00   # ~gravitino
   1000001     1.55536688e+03   # ~d_L
   1000002     1.55349378e+03   # ~u_L
   1000003     1.55536073e+03   # ~s_L
   1000004     1.55348763e+03   # ~c_L
   1000005     1.37521009e+03   # ~b_1
   1000006     1.09372514e+03   # ~t_1
   1000011     7.52700404e+02   # ~e_L
   1000012     7.48204533e+02   # ~nue_L
   1000013     7.52684447e+02   # ~mu_L
   1000014     7.48188597e+02   # ~numu_L
   1000015     4.95092399e+02   # ~stau_1
   1000016     7.42989451e+02   # ~nu_tau_L
   2000001     1.39757458e+03   # ~d_R
   2000002     1.42654831e+03   # ~u_R
   2000003     1.39756545e+03   # ~s_R
   2000004     1.42654379e+03   # ~c_R
   2000005     1.40782699e+03   # ~b_2
   2000006     1.41879879e+03   # ~t_2
   2000011     5.11970916e+02   # ~e_R
   2000013     5.11923982e+02   # ~mu_R
   2000015     7.48688040e+02   # ~stau_2
Block alpha                     # Effective Higgs mixing parameter
          -7.00211214e-02       # alpha
Block nmix                  # neutralino mixing matrix
  1  1     9.98214646e-01   # N_{1,1}
  1  2    -8.06718752e-03   # N_{1,2}
  1  3     5.62714240e-02   # N_{1,3}
  1  4    -1.83294453e-02   # N_{1,4}
  2  1     1.60205892e-02   # N_{2,1}
  2  2     9.90364487e-01   # N_{2,2}
  2  3    -1.20754539e-01   # N_{2,3}
  2  4     6.58776550e-02   # N_{2,4}
  3  1    -2.64283224e-02   # N_{3,1}
  3  2     3.93106878e-02   # N_{3,2}
  3  3     7.04963238e-01   # N_{3,3}
  3  4     7.07660263e-01   # N_{3,4}
  4  1    -5.11116986e-02   # N_{4,1}
  4  2     1.32543478e-01   # N_{4,2}
  4  3     6.96619481e-01   # N_{4,3}
  4  4    -7.03236176e-01   # N_{4,4}
Block Umix                  # chargino U mixing matrix 
  1  1     9.85131569e-01   # U_{1,1}
  1  2    -1.71801608e-01   # U_{1,2}
  2  1     1.71801608e-01   # U_{2,1}
  2  2     9.85131569e-01   # U_{2,2}
Block Vmix                  # chargino V mixing matrix 
  1  1     9.95564397e-01   # V_{1,1}
  1  2    -9.40825764e-02   # V_{1,2}
  2  1     9.40825764e-02   # V_{2,1}
  2  2     9.95564397e-01   # V_{2,2}
Block stopmix               # stop mixing matrix
  1  1     1.76683900e-01   # F_{11}
  1  2     9.84267646e-01   # F_{12}
  2  1     9.84267646e-01   # F_{21}
  2  2    -1.76683900e-01   # F_{22}
Block sbotmix               # sbottom mixing matrix
  1  1     3.87301526e-01   # F_{11}
  1  2     9.21953105e-01   # F_{12}
  2  1     9.21953105e-01   # F_{21}
  2  2    -3.87301526e-01   # F_{22}
Block staumix               # stau mixing matrix
  1  1     7.40746151e-02   # F_{11}
  1  2     9.97252702e-01   # F_{12}
  2  1     9.97252702e-01   # F_{21}
  2  2    -7.40746151e-02   # F_{22}
Block gauge Q= 1.21064779e+03  # SM gauge couplings
     1     3.62925552e-01   # g'(Q)MSSM DRbar
     2     6.41435484e-01   # g(Q)MSSM DRbar
     3     1.04842906e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.21064779e+03  
  3  3     8.52151457e-01   # Yt(Q)MSSM DRbar
Block yd Q= 1.21064779e+03  
  3  3     1.96447816e-01   # Yb(Q)MSSM DRbar
Block ye Q= 1.21064779e+03  
  3  3     1.50626437e-01   # Ytau(Q)MSSM DRbar
Block hmix Q= 1.21064779e+03 # Higgs mixing parameters
     1     8.71564586e+02    # mu(Q)MSSM DRbar
     2     1.44703604e+01    # tan beta(Q)MSSM DRbar
     3     2.43749085e+02    # higgs vev(Q)MSSM DRbar
     4     1.30815512e+06    # mA^2(Q)MSSM DRbar
Block msoft Q= 1.21064779e+03  # MSSM DRbar SUSY breaking parameters
     1     2.31054098e+02      # M_1(Q)
     2     4.26885298e+02      # M_2(Q)
     3     1.16096879e+03      # M_3(Q)
    21     4.80639214e+05      # mH1^2(Q)
    22    -7.33080738e+05      # mH2^2(Q)
    31     7.48885988e+02      # meL(Q)
    32     7.48870063e+02      # mmuL(Q)
    33     7.44006484e+02      # mtauL(Q)
    34     5.06910708e+02      # meR(Q)
    35     5.06863336e+02      # mmuR(Q)
    36     4.92227250e+02      # mtauR(Q)
    41     1.52040305e+03      # mqL1(Q)
    42     1.52039674e+03      # mqL2(Q)
    43     1.37304600e+03      # mqL3(Q)
    44     1.39180543e+03      # muR(Q)
    45     1.39180076e+03      # mcR(Q)
    46     1.05712292e+03      # mtR(Q)
    47     1.36060894e+03      # mdR(Q)
    48     1.36059948e+03      # msR(Q)
    49     1.34335369e+03      # mbR(Q)
Block au Q= 1.21064779e+03  
  1  1    -1.07296520e+03      # Au(Q)MSSM DRbar
  2  2    -1.07295983e+03      # Ac(Q)MSSM DRbar
  3  3    -8.55312339e+02      # At(Q)MSSM DRbar
Block ad Q= 1.21064779e+03  
  1  1    -1.27995975e+03      # Ad(Q)MSSM DRbar
  2  2    -1.27995234e+03      # As(Q)MSSM DRbar
  3  3    -1.19804490e+03      # Ab(Q)MSSM DRbar
Block ae Q= 1.21064779e+03  
  1  1    -2.40132765e+02      # Ae(Q)MSSM DRbar
  2  2    -2.40124589e+02      # Amu(Q)MSSM DRbar
  3  3    -2.37634290e+02      # Atau(Q)MSSM DRbar
