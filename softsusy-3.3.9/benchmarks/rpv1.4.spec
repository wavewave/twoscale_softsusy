# SOFTSUSY3.3.9 SLHA compliant output
# B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145
# B.C. Allanach and M.A. Bernhardt, Comput. Phys. Commun. 181 (2010) 232,
# arXiv:0903.1805
# B.C. Allanach, M. Hanussek and C.H. Kom, arXiv:1109.3735
Block SPINFO          # Program information
     1    SOFTSUSY    # spectrum calculator
     2    3.3.9       # version number
Block MODSEL  # Select model
     1    1   # sugra
     4    1   # R-parity violating
Block SMINPUTS             # Standard Model inputs
     1    1.27934000e+02   # alpha_em^(-1)(MZ) SM MSbar
     2    1.16637000e-05   # G_Fermi
     3    1.17200000e-01   # alpha_s(MZ)MSbar
     4    9.11876000e+01   # MZ(pole)
     5    4.25000000e+00   # mb(mb)
     6    1.73300000e+02   # Mtop(pole)
     7    1.77700000e+00   # Mtau(pole)
    21    4.75000000e-03   # Mdown(2 GeV) MSbar
    22    2.40000000e-03   # Mup(2 GeV) MSbar
    23    1.04000000e-01   # Mstrange(2 GeV) MSbar
    24    1.27000000e+00   # Mcharm(Mcharm) MSbar
    11    5.10998902e-04   # Me(pole)
    13    1.05658357e-01   # Mmu(pole)
Block VCKMIN               # input CKM mixing matrix parameters
     1    2.27200000e-01   # lambda
     2    8.18000000e-01   # A
     3    2.21000000e-01   # rhobar
     4    3.40000000e-01   # etabar (no phases used in SOFTSUSY yet though)
Block MINPAR               # SUSY breaking input parameters
     3    1.00000000e+01   # tanb
     4    1.00000000e+00   # sign(mu)
     1    1.62500000e+02   # m0
     2    6.50000000e+02   # m12
     5    0.00000000e+00   # A0
Block EXTPAR               # scale of SUSY breaking BCs
     0    1.44214621e+16   # MX scale
Block RVLAMLLEIN           # input LLE couplings at MSUSY
  1 2 1   1.00000000e-02   # lambda_{121}
  2 1 1  -1.00000000e-02   # lambda_{211}
# SOFTSUSY-specific non SLHA information:
# MIXING=1 Desired accuracy=1.00000000e-03 Achieved accuracy=4.56013688e-04
Block MASS                      # Mass spectrum
# PDG code     mass             particle
        24     8.05302158e+01   # MW
        25     1.16444339e+02   # CP even neutral scalar
        35     4.57303865e+02   # CP even neutral scalar
        36     4.57303865e+02   # CP odd neutral scalar
        37     2.88873159e+02   # charged scalar
   1000021     1.46181064e+03   # ~g
   1000022     2.70956791e+02   # ~neutralino(1)
   1000023     5.11115791e+02   # ~neutralino(2)
   1000024     5.11198499e+02   # ~chargino(1)
   1000025    -8.08783870e+02   # ~neutralino(3)
   1000035     8.20381139e+02   # ~neutralino(4)
   1000037     8.20605295e+02   # ~chargino(2)
   1000011     2.96029396e+02   # charged scalar
   1000013     2.96043344e+02   # charged scalar
   1000015     4.64695046e+02   # charged scalar
   2000011     4.65520593e+02   # charged scalar
   2000013     4.65522293e+02   # charged scalar
   2000015     9.14012163e+02   # charged scalar
   1000012     4.58562935e+02   # CP even neutral scalar
   1000014     4.58567143e+02   # CP even neutral scalar
   1000016     9.10250086e+02   # CP even neutral scalar
   1000017     4.58562935e+02   # CP odd neutral scalar
   1000018     4.58567143e+02   # CP odd neutral scalar
   1000019     9.10250086e+02   # CP odd neutral scalar
   1000001     1.23128256e+03   # ~d_1
   1000003     1.27437759e+03   # ~d_2
   1000005     1.28412860e+03   # ~d_3
   2000001     1.28413263e+03   # ~d_4
   2000003     1.34205547e+03   # ~d_5
   2000005     1.34207993e+03   # ~d_6
   1000002     1.03756550e+03   # ~u_1
   1000004     1.25608686e+03   # ~u_2
   1000006     1.28907238e+03   # ~u_3
   2000002     1.28907797e+03   # ~u_4
   2000004     1.33987256e+03   # ~u_5
   2000006     1.33987852e+03   # ~u_6
        12     2.13586812e-44   # Mnu1 inverted hierarchy output
        14     1.83369218e-14   # Mnu2 inverted hierarchy output
        16     0.00000000e+00   # Mnu3 inverted hierarchy output
Block RVNMIX  # neutrino-neutralino mixing matrix 
  1 1    0.00000000e+00   # N_{11}
  1 2    0.00000000e+00   # N_{12}
  1 3    1.00000000e+00   # N_{13}
  1 4    0.00000000e+00   # N_{14}
  1 5    0.00000000e+00   # N_{15}
  1 6    0.00000000e+00   # N_{16}
  1 7    0.00000000e+00   # N_{17}
  2 1    1.00000000e+00   # N_{21}
  2 2    1.50785071e-14   # N_{22}
  2 3    0.00000000e+00   # N_{23}
  2 4    7.64795214e-24   # N_{24}
  2 5    4.86408791e-25   # N_{25}
  2 6    2.94499067e-23   # N_{26}
  2 7    2.49348383e-29   # N_{27}
  3 1   -1.50785071e-14   # N_{31}
  3 2    1.00000000e+00   # N_{32}
  3 3    0.00000000e+00   # N_{33}
  3 4   -3.83199636e-10   # N_{34}
  3 5    3.98676215e-10   # N_{35}
  3 6   -2.43076776e-09   # N_{36}
  3 7    3.23108479e-12   # N_{37}
  4 1   -1.77731465e-23   # N_{41}
  4 2    5.45527461e-10   # N_{42}
  4 3    0.00000000e+00   # N_{43}
  4 4    9.97410183e-01   # N_{44}
  4 5   -1.09743492e-02   # N_{45}
  4 6    6.53516549e-02   # N_{46}
  4 7   -2.79580401e-02   # N_{47}
  5 1    1.60255020e-23   # N_{51}
  5 2   -7.83667037e-10   # N_{52}
  5 3    0.00000000e+00   # N_{53}
  5 4    2.48119204e-02   # N_{54}
  5 5    9.79298446e-01   # N_{55}
  5 6   -1.65537896e-01   # N_{56}
  5 7    1.13824983e-01   # N_{57}
  6 1   -4.60043727e-23   # N_{61}
  6 2    1.68621951e-09   # N_{62}
  6 3    0.00000000e+00   # N_{63}
  6 4   -2.59302786e-02   # N_{64}
  6 5    3.75336456e-02   # N_{65}
  6 6    7.04883012e-01   # N_{66}
  6 7    7.07855059e-01   # N_{67}
  7 1    4.34878271e-23   # N_{71}
  7 2   -1.56823357e-09   # N_{72}
  7 3    0.00000000e+00   # N_{73}
  7 4    6.23290976e-02   # N_{74}
  7 5   -1.98608515e-01   # N_{75}
  7 6   -6.86634040e-01   # N_{76}
  7 7    6.96565457e-01   # N_{77}
Block RVUMIX  # lepton-chargino mixing matrix U
  1 1   -1.00000000e+00   # U_{11}
  1 2    1.82474395e-18   # U_{12}
  1 3    0.00000000e+00   # U_{13}
  1 4    1.96856886e-23   # U_{14}
  1 5   -3.21179917e-22   # U_{15}
  2 1    1.77053385e-18   # U_{21}
  2 2    1.00000000e+00   # U_{22}
  2 3    0.00000000e+00   # U_{23}
  2 4    2.75839430e-10   # U_{24}
  2 5   -4.55773684e-09   # U_{25}
  3 1    0.00000000e+00   # U_{31}
  3 2    0.00000000e+00   # U_{32}
  3 3    1.00000000e+00   # U_{33}
  3 4    0.00000000e+00   # U_{34}
  3 5    0.00000000e+00   # U_{35}
  4 1    9.50640558e-23   # U_{41}
  4 2   -1.34563838e-09   # U_{42}
  4 3    0.00000000e+00   # U_{43}
  4 4    9.71646699e-01   # U_{44}
  4 5   -2.36437501e-01   # U_{45}
  5 1   -3.07411009e-22   # U_{51}
  5 2    4.36329117e-09   # U_{52}
  5 3    0.00000000e+00   # U_{53}
  5 4    2.36437501e-01   # U_{54}
  5 5    9.71646699e-01   # U_{55}
Block RVVMIX  # lepton-chargino mixing matrix V
  1 1   -1.00000000e+00   # V_{11}
  1 2    3.77395855e-17   # V_{12}
  1 3    0.00000000e+00   # V_{13}
  1 4    1.54448754e-28   # V_{14}
  1 5   -5.91040738e-28   # V_{15}
  2 1    6.59830521e-17   # V_{21}
  2 2    1.00000000e+00   # V_{22}
  2 3    0.00000000e+00   # V_{23}
  2 4    4.21887143e-13   # V_{24}
  2 5   -1.61446746e-12   # V_{25}
  3 1    0.00000000e+00   # V_{31}
  3 2    0.00000000e+00   # V_{32}
  3 3    1.00000000e+00   # V_{33}
  3 4    0.00000000e+00   # V_{34}
  3 5    0.00000000e+00   # V_{35}
  4 1    2.02375089e-28   # V_{41}
  4 2   -6.74342752e-13   # V_{42}
  4 3    0.00000000e+00   # V_{43}
  4 4    9.87161427e-01   # V_{44}
  4 5   -1.59725757e-01   # V_{45}
  5 1   -4.58069694e-28   # V_{51}
  5 2    1.52635376e-12   # V_{52}
  5 3    0.00000000e+00   # V_{53}
  5 4    1.59725757e-01   # V_{54}
  5 5    9.87161427e-01   # V_{55}
Block gauge Q= 1.11356547e+03  # SM gauge couplings
     1     3.63221910e-01   # g'(Q)MSSM DRbar
     2     6.41038244e-01   # g(Q)MSSM DRbar
     3     1.05189674e+00   # g3(Q)MSSM DRbar
Block yu Q= 1.11356547e+03   # diagonal Up Yukawa matrix
  1  1     7.27357442e-06    # YU_{11}(Q)MSSM DRbar
  2  2     3.33182869e-03    # YU_{22}(Q)MSSM DRbar
  3  3     8.49102516e-01    # YU_{33}(Q)MSSM DRbar
Block yd Q= 1.11356547e+03   # diagonal down Yukawa matrix
  1  1     1.39732074e-04    # YD_{11}(Q)MSSM DRbar
  2  2     3.05946043e-03    # YD_{22}(Q)MSSM DRbar
  3  3     1.33211901e-01    # YD_{33}(Q)MSSM DRbar
Block ye Q= 1.11356547e+03   # diagonal lepton Yukawa matrix
  1  1     2.78115010e-05    # YE_{11}(Q)MSSM DRbar
  2  2     5.75053299e-03    # YE_{22}(Q)MSSM DRbar
  3  3     1.00113831e-01    # YE_{33}(Q)MSSM DRbar
Block hmix Q= 1.11356547e+03 # Higgs mixing parameters
     1     8.03369438e+02    # mu(Q)MSSM DRbar
     2     9.64755412e+00    # tan beta(Q)MSSM DRbar
     3     2.44326091e+02    # higgs vev(Q)MSSM DRbar
     4     8.58568390e+05    # mA^2(Q)MSSM DRbar
Block RVLAMLLE Q= 1.11356547e+03 # non-zero R-Parity violating LLE couplings 
  1 2 1    9.99999968e-03   # lambda_{121}
  1 2 2    1.29469625e-30   # lambda_{122}
  1 3 3    7.47969334e-30   # lambda_{133}
  2 1 1   -9.99999968e-03   # lambda_{211}
  2 1 2   -1.29469625e-30   # lambda_{212}
  2 3 3   -5.48314861e-16   # lambda_{233}
  3 1 3   -7.47969334e-30   # lambda_{313}
  3 2 3    5.48314861e-16   # lambda_{323}
Block RVLAMLQD Q= 1.11356547e+03 # non-zero R-Parity violating LQD couplings 
  1 1 1    1.04453008e-32   # lambda'_{111}
  1 1 2   -6.39160340e-37   # lambda'_{112}
  1 1 3    6.44987928e-34   # lambda'_{113}
  1 2 1   -2.91924014e-38   # lambda'_{121}
  1 2 2    2.28701814e-31   # lambda'_{122}
  1 2 3   -4.74847683e-33   # lambda'_{123}
  1 3 1    6.84382204e-37   # lambda'_{131}
  1 3 2   -1.10316746e-34   # lambda'_{132}
  1 3 3    9.95489884e-30   # lambda'_{133}
  2 1 1   -7.65715001e-19   # lambda'_{211}
  2 1 2    4.68550567e-23   # lambda'_{212}
  2 1 3   -4.72822593e-20   # lambda'_{213}
  2 2 1    2.14001329e-24   # lambda'_{221}
  2 2 2   -1.67654731e-17   # lambda'_{222}
  2 2 3    3.48097543e-19   # lambda'_{223}
  2 3 1   -5.01701440e-23   # lambda'_{231}
  2 3 2    8.08701193e-21   # lambda'_{232}
  2 3 3   -7.29765053e-16   # lambda'_{233}
Block RVLAMUDD Q= 1.11356547e+03 # non-zero R-Parity violating UDD couplings 
Block RVTLLE Q= 1.11356547e+03 # non-zero R-Parity violating LLE soft terms 
  1 2 1    2.90110106e-07   # T_{121}
  1 2 2   -1.14890097e-27   # T_{122}
  1 3 3   -8.55602954e-27   # T_{133}
  2 1 1   -2.90110106e-07   # T_{211}
  2 1 2    1.14890097e-27   # T_{212}
  2 3 3    6.27225318e-13   # T_{233}
  3 1 3    8.55602954e-27   # T_{313}
  3 2 3   -6.27225318e-13   # T_{323}
Block RVTLQD Q= 1.11356547e+03 # non-zero R-Parity violating LQD soft terms 
  1 1 1   -2.64105866e-29   # T'_{111}
  1 1 2   -4.67239861e-33   # T'_{112}
  1 1 3    4.71829071e-30   # T'_{113}
  1 2 1   -2.13403767e-34   # T'_{121}
  1 2 2   -5.78220107e-28   # T'_{122}
  1 2 3   -3.47368289e-29   # T'_{123}
  1 3 1    5.03013872e-33   # T'_{131}
  1 3 2   -8.10817725e-31   # T'_{132}
  1 3 3   -2.40125894e-26   # T'_{133}
  2 1 1    1.93609410e-15   # T'_{211}
  2 1 2    3.42518831e-19   # T'_{212}
  2 1 3   -3.45883061e-16   # T'_{213}
  2 2 1    1.56439582e-20   # T'_{221}
  2 2 2    4.23878709e-14   # T'_{222}
  2 2 3    2.54644774e-15   # T'_{223}
  2 3 1   -3.68743654e-19   # T'_{231}
  2 3 2    5.94384982e-17   # T'_{232}
  2 3 3    1.76030348e-12   # T'_{233}
Block RVTUDD Q= 1.11356547e+03 # non-zero R-Parity violating UDD soft terms 
Block RVKAPPA Q= 1.11356547e+03 # R-Parity violating kappa 
     1    6.00143637e-26   # kappa_{1}
     2   -4.39948081e-12   # kappa_{2}
     3    0.00000000e+00   # kappa_{3}
Block RVD Q= 1.11356547e+03 # R-Parity violating D 
     1   -3.91648387e-23   # D_{1}
     2    2.87112057e-09   # D_{2}
     3    0.00000000e+00   # D_{3}
Block RVSNVEV Q= 1.11356547e+03 # sneutrino VEVs D 
     1    2.44242984e-21   # SneutrinoVev_{1}
     2   -1.91333570e-07   # SneutrinoVev_{2}
     3    0.00000000e+00   # SneutrinoVev_{3}
Block RVM2LH1 Q= 1.11356547e+03 # M2LH1 
     1    7.29264319e-23   # M2LH1_{1}
     2   -5.34613371e-09   # M2LH1_{2}
     3    0.00000000e+00   # M2LH1_{3}
Block UPMNS Q= 9.11876000e+01 # neutrino mixing matrix (inverted  hierarchy)
  1  1     1.00000000e+00   # UPMNS_{11} matrix element
  1  2    -1.50804143e-14   # UPMNS_{12} matrix element
  1  3     0.00000000e+00   # UPMNS_{13} matrix element
  2  1     1.50804143e-14   # UPMNS_{21} matrix element
  2  2     1.00000000e+00   # UPMNS_{22} matrix element
  2  3     0.00000000e+00   # UPMNS_{23} matrix element
  3  1     0.00000000e+00   # UPMNS_{31} matrix element
  3  2     0.00000000e+00   # UPMNS_{32} matrix element
  3  3     1.00000000e+00   # UPMNS_{33} matrix element
Block msq2 Q= 1.11356547e+03 # super CKM squark mass^2 matrix - DRbar
  1  1     1.68008618e+06    # (m^_Q^2)_{11}
  1  2     5.71987996e+01    # (m^_Q^2)_{12}
  1  3    -1.35343385e+03    # (m^_Q^2)_{13}
  2  1     5.71987996e+01    # (m^_Q^2)_{21}
  2  2     1.67967171e+06    # (m^_Q^2)_{22}
  2  3     9.96425091e+03    # (m^_Q^2)_{23}
  3  1    -1.35343385e+03    # (m^_Q^2)_{31}
  3  2     9.96425091e+03    # (m^_Q^2)_{32}
  3  3     1.43243906e+06    # (m^_Q^2)_{33}
Block msl2 Q= 1.11356547e+03 # super MNS slepton mass^2 matrix - DRbar
  1  1     2.08850643e+05    # (m^_L^2)_{11}
  1  2    -1.75213575e-23    # (m^_L^2)_{12}
  1  3     0.00000000e+00    # (m^_L^2)_{13}
  2  1    -1.75213575e-23    # (m^_L^2)_{21}
  2  2     2.08846817e+05    # (m^_L^2)_{22}
  2  3     0.00000000e+00    # (m^_L^2)_{23}
  3  1     0.00000000e+00    # (m^_L^2)_{31}
  3  2     0.00000000e+00    # (m^_L^2)_{32}
  3  3     2.07703435e+05    # (m^_L^2)_{33}
Block msd2 Q= 1.11356547e+03 # super CKM squark mass^2 matrix - DRbar
  1  1     1.53857463e+06    # (m^_d^2)_{11}
  1  2    -3.96299188e-06    # (m^_d^2)_{12}
  1  3     4.10156375e-03    # (m^_d^2)_{13}
  2  1    -3.96299188e-06    # (m^_d^2)_{21}
  2  2     1.53856621e+06    # (m^_d^2)_{22}
  2  3    -6.61159821e-01    # (m^_d^2)_{23}
  3  1     4.10156375e-03    # (m^_d^2)_{31}
  3  2    -6.61159821e-01    # (m^_d^2)_{32}
  3  3     1.52329939e+06    # (m^_d^2)_{33}
Block msu2 Q= 1.11356547e+03 # super CKM squark mass^2 matrix - DRbar
  1  1     1.55378613e+06    # (m^_u^2)_{11}
  1  2    -2.00659741e-08    # (m^_u^2)_{12}
  1  3    -1.77969748e-05    # (m^_u^2)_{13}
  2  1    -2.00659741e-08    # (m^_u^2)_{21}
  2  2     1.55377742e+06    # (m^_u^2)_{22}
  2  3    -8.66226985e-02    # (m^_u^2)_{23}
  3  1    -1.77969748e-05    # (m^_u^2)_{31}
  3  2    -8.66226985e-02    # (m^_u^2)_{32}
  3  3     1.06146652e+06    # (m^_u^2)_{33}
Block mse2 Q= 1.11356547e+03 # super MNS slepton mass^2 matrix - DRbar
  1  1     8.29126525e+04    # (m^_e^2)_{11}
  1  2    -1.41420174e-15    # (m^_e^2)_{12}
  1  3     0.00000000e+00    # (m^_e^2)_{13}
  2  1    -1.41420174e-15    # (m^_e^2)_{21}
  2  2     8.29262852e+04    # (m^_e^2)_{22}
  2  3     0.00000000e+00    # (m^_e^2)_{23}
  3  1     0.00000000e+00    # (m^_e^2)_{31}
  3  2     0.00000000e+00    # (m^_e^2)_{32}
  3  3     8.05728007e+04    # (m^_e^2)_{33}
Block tu Q= 1.11356547e+03   # super CKM trilinear matrix - DRbar
  1  1    -1.05229274e-02    # (T^_u)_{11}
  1  2    -2.19140640e-08    # (T^_u)_{12}
  1  3    -9.74150636e-08    # (T^_u)_{13}
  2  1    -1.00382624e-05    # (T^_u)_{21}
  2  2    -4.82030888e+00    # (T^_u)_{22}
  2  3    -4.73710109e-04    # (T^_u)_{23}
  3  1    -1.34068830e-02    # (T^_u)_{31}
  3  2    -1.42297130e-01    # (T^_u)_{32}
  3  3    -9.56514653e+02    # (T^_u)_{33}
Block td Q= 1.11356547e+03   # super CKM trilinear matrix - DRbar
  1  1    -2.45771908e-01    # (T^_d)_{11}
  1  2    -3.58086932e-06    # (T^_d)_{12}
  1  3     8.51730134e-05    # (T^_d)_{13}
  2  1    -7.84035324e-05    # (T^_d)_{21}
  2  2    -5.38066736e+00    # (T^_d)_{22}
  2  3    -1.37295888e-02    # (T^_d)_{23}
  3  1     8.10467740e-02    # (T^_d)_{31}
  3  2    -5.96683592e-01    # (T^_d)_{32}
  3  3    -2.19353612e+02    # (T^_d)_{33}
Block te Q= 1.11356547e+03   # super CKM trilinear matrix - DRbar
  1  1    -1.06239843e-02    # (T^_e)_{11}
  1  2    -2.74168945e-21    # (T^_e)_{12}
  1  3     0.00000000e+00    # (T^_e)_{13}
  2  1    -1.31250309e-23    # (T^_e)_{21}
  2  2    -2.19662171e+00    # (T^_e)_{22}
  2  3     0.00000000e+00    # (T^_e)_{23}
  3  1     0.00000000e+00    # (T^_e)_{31}
  3  2     0.00000000e+00    # (T^_e)_{32}
  3  3    -3.80380503e+01    # (T^_e)_{33}
Block VCKM Q= 1.11356547e+03 # DRbar CKM mixing matrix
  1  1     9.73840749e-01    # CKM_{11} matrix element
  1  2     2.27197341e-01    # CKM_{12} matrix element
  1  3     3.94502745e-03    # CKM_{13} matrix element
  2  1    -2.27161574e-01    # CKM_{21} matrix element
  2  2     9.72963013e-01    # CKM_{22} matrix element
  2  3     4.17204461e-02    # CKM_{23} matrix element
  3  1     5.64040860e-03    # CKM_{31} matrix element
  3  2    -4.15252291e-02    # CKM_{32} matrix element
  3  3     9.99121535e-01    # CKM_{33} matrix element
Block msoft Q= 1.11356547e+03 # MSSM DRbar SUSY breaking parameters
     1     2.76748590e+02     # M_1(Q)
     2     5.08651947e+02     # M_2(Q)
     3     1.42150319e+03     # M_3(Q)
    21     1.83204843e+05     # mH1^2(Q)
    22    -6.00072616e+05     # mH2^2(Q)
Block USQMIX  # super CKM squark mass^2 matrix
  1  1     1.89820662e-05   # (USQMIX)_{11}
  1  2     2.00996483e-04   # (USQMIX)_{12}
  1  3     3.69632889e-01   # (USQMIX)_{13}
  1  4     1.00868241e-10   # (USQMIX)_{14}
  1  5     4.89863954e-07   # (USQMIX)_{15}
  1  6     9.29177855e-01   # (USQMIX)_{16}
  2  1     1.29020730e-04   # (USQMIX)_{21}
  2  2     1.36550109e-03   # (USQMIX)_{22}
  2  3     9.29176898e-01   # (USQMIX)_{23}
  2  4     3.04543707e-09   # (USQMIX)_{24}
  2  5     1.47670025e-05   # (USQMIX)_{25}
  2  6    -3.69632806e-01   # (USQMIX)_{26}
  3  1     1.16624406e-07   # (USQMIX)_{31}
  3  2     6.55953106e-03   # (USQMIX)_{32}
  3  3    -2.27120083e-05   # (USQMIX)_{33}
  3  4     1.85761374e-08   # (USQMIX)_{34}
  3  5     9.99978486e-01   # (USQMIX)_{35}
  3  6     7.08885483e-06   # (USQMIX)_{36}
  4  1     1.43193846e-05   # (USQMIX)_{41}
  4  2     1.32773160e-10   # (USQMIX)_{42}
  4  3    -4.68408561e-09   # (USQMIX)_{43}
  4  4     1.00000000e+00   # (USQMIX)_{44}
  4  5    -1.85791948e-08   # (USQMIX)_{45}
  4  6     1.46225478e-09   # (USQMIX)_{46}
  5  1     1.37456432e-01   # (USQMIX)_{51}
  5  2     9.90485536e-01   # (USQMIX)_{52}
  5  3    -1.34766364e-03   # (USQMIX)_{53}
  5  4    -1.96855051e-06   # (USQMIX)_{54}
  5  5    -6.49730932e-03   # (USQMIX)_{55}
  5  6     3.19046208e-04   # (USQMIX)_{56}
  6  1     9.90507805e-01   # (USQMIX)_{61}
  6  2    -1.37453524e-01   # (USQMIX)_{62}
  6  3     5.89046943e-05   # (USQMIX)_{63}
  6  4    -1.41834269e-05   # (USQMIX)_{64}
  6  5     9.01535972e-04   # (USQMIX)_{65}
  6  6    -1.39346453e-05   # (USQMIX)_{66}
Block DSQMIX  # super CKM squark mass^2 matrix
  1  1     4.66671844e-03   # (DSQMIX)_{11}
  1  2    -3.43577167e-02   # (DSQMIX)_{12}
  1  3     9.81836634e-01   # (DSQMIX)_{13}
  1  4     8.13876222e-07   # (DSQMIX)_{14}
  1  5    -1.31204339e-04   # (DSQMIX)_{15}
  1  6     1.86533041e-01   # (DSQMIX)_{16}
  2  1    -1.43467914e-03   # (DSQMIX)_{21}
  2  2     1.05631872e-02   # (DSQMIX)_{22}
  2  3    -1.86271271e-01   # (DSQMIX)_{23}
  2  4    -1.51062395e-06   # (DSQMIX)_{24}
  2  5     2.43608313e-04   # (DSQMIX)_{25}
  2  6     9.82440489e-01   # (DSQMIX)_{26}
  3  1     1.36666768e-06   # (DSQMIX)_{31}
  3  2     3.39500715e-03   # (DSQMIX)_{32}
  3  3     2.95814440e-04   # (DSQMIX)_{33}
  3  4     3.57022542e-06   # (DSQMIX)_{34}
  3  5     9.99994167e-01   # (DSQMIX)_{35}
  3  6    -2.28375451e-04   # (DSQMIX)_{36}
  4  1     1.55518134e-04   # (DSQMIX)_{41}
  4  2     5.02651779e-08   # (DSQMIX)_{42}
  4  3    -1.83603569e-06   # (DSQMIX)_{43}
  4  4     9.99999988e-01   # (DSQMIX)_{44}
  4  5    -3.56976267e-06   # (DSQMIX)_{45}
  4  6     1.41696166e-06   # (DSQMIX)_{46}
  5  1    -1.35316333e-01   # (DSQMIX)_{51}
  5  2     9.90132469e-01   # (DSQMIX)_{52}
  5  3     3.60520283e-02   # (DSQMIX)_{53}
  5  4     2.10542050e-05   # (DSQMIX)_{54}
  5  5    -3.37292148e-03   # (DSQMIX)_{55}
  5  6    -4.00717530e-03   # (DSQMIX)_{56}
  6  1     9.90790406e-01   # (DSQMIX)_{61}
  6  2     1.35403595e-01   # (DSQMIX)_{62}
  6  3     2.95052517e-05   # (DSQMIX)_{63}
  6  4    -1.54094271e-04   # (DSQMIX)_{64}
  6  5    -4.61061869e-04   # (DSQMIX)_{65}
  6  6    -3.27666488e-06   # (DSQMIX)_{66}
Block RVLMIX  # charged higgs-slepton mixing matrix 
  1 1    0.00000000e+00   # C_{11}
  1 2    0.00000000e+00   # C_{12}
  1 3    0.00000000e+00   # C_{13}
  1 4    0.00000000e+00   # C_{14}
  1 5    1.11798830e-01   # C_{15}
  1 6    0.00000000e+00   # C_{16}
  1 7    0.00000000e+00   # C_{17}
  1 8    9.93730860e-01   # C_{18}
  2 1   -6.18704213e-29   # C_{21}
  2 2    9.28050011e-28   # C_{22}
  2 3    3.19617329e-05   # C_{23}
  2 4    1.14839991e-18   # C_{24}
  2 5    0.00000000e+00   # C_{25}
  2 6    9.99999999e-01   # C_{26}
  2 7    1.07793136e-16   # C_{27}
  2 8    0.00000000e+00   # C_{28}
  3 1   -5.52161766e-13   # C_{31}
  3 2    8.28295144e-12   # C_{32}
  3 3    7.04981825e-21   # C_{33}
  3 4    6.60913991e-03   # C_{34}
  3 5    0.00000000e+00   # C_{35}
  3 6   -1.07798372e-16   # C_{36}
  3 7    9.99978159e-01   # C_{37}
  3 8    0.00000000e+00   # C_{38}
  4 1   -1.84757014e-26   # C_{41}
  4 2   -8.31541764e-27   # C_{42}
  4 3    9.99999999e-01   # C_{43}
  4 4   -1.90694287e-18   # C_{44}
  4 5    0.00000000e+00   # C_{45}
  4 6   -3.19617329e-05   # C_{46}
  4 7    2.10805723e-21   # C_{47}
  4 8    0.00000000e+00   # C_{48}
  5 1    1.44682484e-12   # C_{51}
  5 2    6.30056111e-13   # C_{52}
  5 3    1.90690121e-18   # C_{53}
  5 4    9.99978159e-01   # C_{54}
  5 5    0.00000000e+00   # C_{55}
  5 6   -4.36015866e-19   # C_{56}
  5 7   -6.60913991e-03   # C_{57}
  5 8    0.00000000e+00   # C_{58}
  6 1    0.00000000e+00   # C_{61}
  6 2    0.00000000e+00   # C_{62}
  6 3    0.00000000e+00   # C_{63}
  6 4    0.00000000e+00   # C_{64}
  6 5    9.93730860e-01   # C_{65}
  6 6    0.00000000e+00   # C_{66}
  6 7    0.00000000e+00   # C_{67}
  6 8   -1.11798830e-01   # C_{68}
  7 1    9.94670913e-01   # C_{71}
  7 2    1.03100796e-01   # C_{72}
  7 3    1.92316976e-26   # C_{73}
  7 4   -1.50605522e-12   # C_{74}
  7 5    0.00000000e+00   # C_{75}
  7 6   -1.24836379e-30   # C_{76}
  7 7   -2.94812344e-13   # C_{77}
  7 8    0.00000000e+00   # C_{78}
Block RVHMIX  # CP-even neutral scalar mixing matrix 
  1 1    1.05001115e-01   # curlyN_{11}
  1 2    9.94472104e-01   # curlyN_{12}
  1 3    4.01679596e-25   # curlyN_{13}
  1 4   -3.14684614e-11   # curlyN_{14}
  1 5    0.00000000e+00   # curlyN_{15}
  2 1    0.00000000e+00   # curlyN_{21}
  2 2    0.00000000e+00   # curlyN_{22}
  2 3    0.00000000e+00   # curlyN_{23}
  2 4    0.00000000e+00   # curlyN_{24}
  2 5    1.00000000e+00   # curlyN_{25}
  3 1    5.31381099e-12   # curlyN_{31}
  3 2    3.10823251e-11   # curlyN_{32}
  3 3    1.90713272e-18   # curlyN_{33}
  3 4    1.00000000e+00   # curlyN_{34}
  3 5    0.00000000e+00   # curlyN_{35}
  4 1   -6.78514249e-26   # curlyN_{41}
  4 2   -3.96808652e-25   # curlyN_{42}
  4 3    1.00000000e+00   # curlyN_{43}
  4 4   -1.90713272e-18   # curlyN_{44}
  4 5    0.00000000e+00   # curlyN_{45}
  5 1    9.94472104e-01   # curlyN_{51}
  5 2   -1.05001115e-01   # curlyN_{52}
  5 3    2.58071444e-26   # curlyN_{53}
  5 4   -2.02075800e-12   # curlyN_{54}
  5 5    0.00000000e+00   # curlyN_{55}
Block RVAMIX  # CP-odd neutral scalar mixing matrix 
  1 1    0.00000000e+00   # curlyN~_{11}
  1 2    0.00000000e+00   # curlyN~_{12}
  1 3    0.00000000e+00   # curlyN~_{13}
  1 4    0.00000000e+00   # curlyN~_{14}
  1 5    1.00000000e+00   # curlyN~_{15}
  2 1   -3.31305193e-12   # curlyN~_{21}
  2 2    3.20895019e-11   # curlyN~_{22}
  2 3    1.90713272e-18   # curlyN~_{23}
  2 4    1.00000000e+00   # curlyN~_{24}
  2 5    0.00000000e+00   # curlyN~_{25}
  3 1    4.22879453e-26   # curlyN~_{31}
  3 2   -4.09703163e-25   # curlyN~_{32}
  3 3    1.00000000e+00   # curlyN~_{33}
  3 4   -1.90713272e-18   # curlyN~_{34}
  3 5    0.00000000e+00   # curlyN~_{35}
  4 1    9.94670917e-01   # curlyN~_{41}
  4 2    1.03100758e-01   # curlyN~_{42}
  4 3    1.78092404e-28   # curlyN~_{43}
  4 4   -1.30555692e-14   # curlyN~_{44}
  4 5    0.00000000e+00   # curlyN~_{45}