
C====== Modules =================
C   Keys to switch on
C   various modules of micrOMEGAs
C================================
   
#define MASSES_INFO
C    Display masses of odd sector
#define CONSTRAINTS
C    Not implemented
#define OMEGA
C    Calculate relic density and display contribution of
C                            individual channels 
#define INDIRECT_DETECTION
C     Compute spectra of gamma/positron/neutrinos
C     for DM annihilation; calculate <sigma*v> and
C     integrate gamma signal over DM galactic squared
C     density for given line of sight.
C!#define RESET_FORMFACTORS
C     Modify default nucleus form factors, 
C     DM velocity distribution,
C     A-dependence of Fermi-dencity.
#define WIMP_NUCLEON 
C     Calculate amplitudes and cross-sections for
C     WIMP-mucleon collisions 
#define WIMP_NUCLEUS
C     Calculate number of events for 1kg*day
C     and recoil energy distibution for various nuclei

C!#define CROSS_SECTIONS
C     Calculate cross sections and widths for
C      reactions specified by the user
 
C================ end of Modules  ======

C===== Options ========

C!#define SHOWPLOTS
C     Display  graphical plots on the screen

C===== End of DEFINE  settings ===== 


      IMPLICIT NONE
C! external functions 
#include "../sources/micromegas.fh"
#include "lib/pmodel.fh"
*      external iargc
*      integer iargc
C! local  Parameters   

      INTEGER fast/1/
      REAL*8  Beps/1.E-4/,cut/0.01/
C Variables      
      INTEGER err
      REAL*8 Omega,OmegaAppr,Xf,val
      INTEGER  narg,nw 
      character *100 argv
      character*10 mess

      real*8 Pcm,cosmin, cosmax,rw
      integer cc(2)
      integer ntot,l, nin,nout
      character*6 name(4)
      real*8 mass(4)
      real*8 cs,tw
      integer outP
      real*8  M,Emin,NGtot,Etot,sigmaV,v/0.001/,tab(250),fi
      character*100 buff
      character*6 outName(6)/'gamma','e+','p-','nu_e','nu_mu','nu_tau'/

C for WIMP_NUCLEON
      real*8  pA0(2),pA5(2),nA0(2),nA5(2),Nmass,SCcoeff,
     >ffS0P(3),ffS0N(3),ffbuff(3)

C  for WIMP_NUCLEUS
      real*8  dNdE(200),rho,nEvents

C   to save the SLHA  input/output file  uncomment  
C*      call delFiles(0)
 
      write(*,*)
      write(*,*) '========= EWSB scale input For CPVMSSM ========='
      if(iargc().eq.0) then
         write(*,*)'Correct usage: ./main  <file with parameters>'
         write(*,*)'Example: ./main  data1.par' 
         stop
      endif

      call getarg(1,argv)                               
       
      err=readVarRHNM(argv)

      if(err.eq.-1) then
          write(*,*) 'Can not open the file'
          stop
      endif

      if(err.gt.0) then
          write(*,*)'Wrong file contents at line ',err
          stop
      endif

      goto 101
100   STOP 'Wrong input' 
101   continue
C  To print list od variables uncomment   
C      CALL printVar(6)

C    to save results in SLHA format  use 
C     Call writeLesH('slha.out'); 


      err=sortOddParticles(mess)
      if(err.ne.0) then
        write(*,*) 'Can t calculate ', mess
        STOP
      endif 

#ifdef MASSES_INFO  
      write(*,*) '=== MASSES OF HIGGS AND SUSY PARTICLES: ===' 
      CALL printMasses(6,1)
#endif

#ifdef CONSTRAINTS
#endif


#ifdef OMEGA
      write(*,*)
      write(*,*) '==== Calculation of relic density ====='
      write(*,*) 'Dark Matter candidate is ', mess                                   
      if(mess.ne.'~n4') then
          write(*,*) '~n4 is not LSP'
      endif                                                                          
      Omega=darkOmega(Xf,fast,Beps)
      write(*,'(a,3x,1PE10.2)') 'Omega=',Omega

      OmegaAppr=printChannels(Xf,cut,Beps,1,6)
#endif


#ifdef  INDIRECT_DETECTION
C!! See  hep-ph/0607059 pages 10, 11 for complete explanation 
      write(*,*)
      write(*,*) '=============== Indirect detection ==========='
C** Emin - energy cut in GeV
      Emin=0.1     

C** outP: 0-photons, 1- positrons, 2 -antiprotons, 
C**     3-4-5 neutrunos with antineutrinos    
      outP=0

C** fi angle of sight     
      fi=0
 
      sigmaV=calcSpectrum(v,outP,tab,err)    
C  Returns  sigma*v in cm^3/sec.
C  tab could be substituted in zInterp(z,tab) to get particle distribution in one collision
C  dN/dz, where  z=log (E/Mwinp)
       write(*,fmt="('sigma*v=',1PE8.2,'[cm^3/s]')") sigmaV

      M=lopmass()
      call spectrInfo(Emin/M,tab,NGtot,Etot) 
      write(*,fmt="(1PE8.2,1x,A6,'with E>', 1PE8.2,'GeV are produced',
     > ' in each collision')") NGtot, outName(outP+1),Emin

#ifdef SHOWPLOTS
C   Spectrum of particles produced in one collision
      write(buff,13) outName(outP+1),NGtot,Etot,sigmaV,mess,M  
13     format(A6,': ',
     > 'N=',1PE8.2,',<E/2M>=',1PE8.2,';vcs=',1PE8.2,
     >'cm^3/sec,M(',A3,')=',1PE8.2)
      err= displaySpectrum(tab,buff ,Emin/M)
#endif 
      if(outP.EQ.0) then
      write(*,fmt="('gamma flux at fi=',1PE10.2,'rad  is ',1PE10.2,
     >'[ph/cm^2/s/sr]')"), fi,
     >sigmaV*NGtot*HaloFactor(fi,rhoQisotermic)/M/M
      endif
#endif

#ifdef RESET_FORMFACTORS
C  The default nucleon form factors can be completely or partially modified 
C   by setProtonFF and setNeutronFF. For scalar form factors, one can first call
C   getScalarFF( Mu/Md, Ms/Md, sigmaPiN[MeV], sigma0[MeV], protonFF,neutronFF)  
C   or set the new coefficients by directly assigning numerical values.
C
      write(*,*)
      write(*,*) '===========Redefinition of form factors========='
  
      call getScalarFF(0.553d0,18.9d0,55.d0,35.d0,ffS0P, ffS0N)
      write(*,*) 'protonFF  for  d, u, s ', ffS0P                           
      write(*,*) 'neutronFF for  d, u, s ', ffS0N                           
C set...FF assigns scalar, vector and sigma form factors.
      call setProtonFF (ffS0P,NOFF,NOFF)
      call setNeutronFF(ffS0N,NOFF,NOFF)
C Use NOFF argument if there is no need for reassignment

C  Option to change parameters of DM velocity  distribution 

      call SetfMaxwell(220.d0,244.4d0,600.d0)
C  arg1- defines DM velocity distribution in Galaxy rest frame:
C     ~exp(-v^2/arg1^2)d^3v
C  arg2- Earth velocity with respect to Galaxy
C  arg3- Maximal DM velocity in Sun orbit with respect to Galaxy.
C  All parameters are  in [km/s] units.

C  In case DM has velocity distribution close to delta-function
C  the DM velocity V[km/s] can be defined by

      call SetfDelta(350.)

C  To change parameter of nucleus  Fermi density 
      call  setFermi(1.23d0,-0.6d0,0.52d0)
C  then half-density radius for Fermi distribution is
C          c=arg1*A^(1/3) + arg2
C   and  arg3 is the surface thickness.
C   All parameter in [fm] .
#endif


#ifdef  WIMP_NUCLEON
      write(*,*)
      write(*,*) '==== Calculation of WIMP-nucleons amplitudes  ====='   

      err=nucleonAmplitudes(NoLoop, pA0,pA5,nA0,nA5)
      write(*,*) mess,  ' -nucleon amplitudes:'
      write(*,*)'proton:  SI=',pA0(1),' SD=',pA5(1)
      write(*,*)'neutron: SI=',nA0(1),' SD=',nA5(1) 

C  nucleon mass
      Nmass=0.939d0

      SCcoeff=4/M_PI*3.8937966E8
     >*(Nmass*lopmass()/(Nmass+ lopmass()))**2
      write(*,*) mess , '-nucleon cross sections:'
    
      write(*,*)'proton  SI=',SCcoeff*pA0(1)**2,' SD=',SCcoeff*pA5(1)**2
      write(*,*)'neutron SI=',SCcoeff*nA0(1)**2,' SD=',SCcoeff*nA5(1)**2

      write(*,*) 'anti-',mess,  ' -nucleon amplitudes:'
      write(*,*)'proton:  SI=',pA0(2),' SD=',pA5(2)
      write(*,*)'neutron: SI=',nA0(2),' SD=',nA5(2) 

C  nucleon mass
      Nmass=0.939d0

      SCcoeff=4/M_PI*3.8937966E8
     >*(Nmass*lopmass()/(Nmass+ lopmass()))**2
      write(*,*) 'anti-',mess , '- nucleon cross sections:'
    
      write(*,*)'proton  SI=',SCcoeff*pA0(2)**2,' SD=',SCcoeff*pA5(2)**2
      write(*,*)'neutron SI=',SCcoeff*nA0(2)**2,' SD=',SCcoeff*nA5(2)**2


#endif


#ifdef WIMP_NUCLEUS
      write(*,*)
      write(*,*) '============= Direct Detection ============'

C     rho - DM density in GeV/sm^3
      rho=0.3

      write(*,*) 'WIMP-73Ge:'
      nEvents=nucleusRecoil(rho,fDvMaxwell,73,Z_Ge,J_Ge73,
     >S00Ge73,S01Ge73,S11Ge73,NoLoop,dNdE)
      write(*,*) '73Ge: Total number of events=',nEvents,' /day/kg'
      write(*,*) ' Number of events in 10 - 50 KeV region=',
     >             cutRecoilResult(dNdE,10,50), ' /day/kg'

#ifdef SHOWPLOTS
       err=displayRecoilPlot(dNdE,
     >               'Distribution of recoil energy of 73Ge',0,199)
#endif
       write(*,*) 
       write(*,*) 'WIMP-131Xe:' 
       nEvents=nucleusRecoil(rho,fDvMaxwell,131,Z_Xe,J_Xe131,
     > S00Xe131,S01Xe131,S11Xe131,NoLoop,dNdE)

      write(*,*) '131Xe: Total number of events=',nEvents,' /day/kg'
      write(*,*) ' Number of events in 10 - 50 KeV region=',
     >             cutRecoilResult(dNdE,10,50), ' /day/kg'
#ifdef SHOWPLOTS
      err=displayRecoilPlot(dNdE,
     >    'Distribution of recoil energy of 131Xe',0,199);
#endif
      write(*,*)
      write(*,*)'WIMP-3He:'
C  If SD form factors are not known or for spin=0 nucleus one can use 

      nEvents=nucleusRecoil0(rho,fDvMaxwell,3,Z_He,J_He3,
     >  Sp_He3,Sn_He3,NoLoop,dNdE);
      write(*,*) '3He: Total number of events=',nEvents,' /day/kg\n'
#ifdef SHOWPLOTS
      err=displayRecoilPlot(dNdE,
     > 'Distribution of recoil energy of 3He',0,50)
#endif


#endif


#ifdef CROSS_SECTIONS
      write(*,*)
      write(*,*)'======Calculations of withs and cross sections======='
      write(*,*) 'Widths:'
      tw= decay2Info('Z',6)
      rw= decay2Info('H',6)
    
      write(*,*) 
      write(*,*) 'Cross Sections'
      Pcm=500
      cosmin=-0.99
      cosmax=0.99
      write(*,*) 'Process e,E->2*x at Pcm= ',Pcm, 'GeV'
      call setHelicities(0.45D0,-0.45D0)
      call newProcess('e%,E%->2*x','eE_2x',cc)
      if(cc(1).ne.0 ) then
        call procInfo1(cc,ntot,nin,nout)
        write(*,*) ntot,nin,nout
        do l=1,ntot
          call procInfo2(cc,l,name,mass)
          write(*,fmt='(A3,1x,A3,A4,A3,1x,A3,$)')
     >     name(1),name(2),' -> ', name(3),name(4)

          cs= cs22(cc,l,Pcm,cosmin,cosmax,err)
          if(err.ne.0) then 
              write(*,*) 'Error'
          else if(cs.eq.0.) then
              write(*,*) 'Zero'
          else 
              write(*,fmt="(1PE8.2,'[pb]')") cs
          endif 
        enddo
      endif 
    
      write(*,*)
      write(*,fmt="('Neutralino annihilation at V_rel=', 1PE8.2)") v
     
      call newProcess(' ','omg__tn4__t_n4',cc)
      call assignValW('Q', 2*lopmass())
      if(cc(1).ne.0) then
        call procInfo1(cc,ntot,nin,nout)
        do l=1, ntot 
          call procInfo2(cc,l,name,mass)
          if(l.eq.1) then
             Pcm=mass(1)*v/2 
             write(*,*) '(Pcm=',Pcm,')'
          endif
          write(*,fmt='(A3,1x,A3,A4,A3,1x,A3,$)')
     >     name(1),name(2),' -> ', name(3),name(4)
          cs= cs22(cc,l,Pcm,-1D0,1D0,err)
          if(err.ne.0) then 
              write(*,*) 'Error'
          else if(cs.eq.0.) then
            write(*,*) 'Zero'
          else 
             write(*,fmt="('cs=',1PE8.2,'[pb]','  sigma*v=',1PE8.2,
     >       '[cm^3/s]')") cs,cs*v*2.9979E-26

          endif 
        enddo
      endif
#endif
      END
