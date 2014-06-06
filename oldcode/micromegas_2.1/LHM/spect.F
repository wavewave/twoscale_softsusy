
      implicit none 
C! external functions 
#include"../sources/micromegas.fh"
#include"lib/pmodel.fh"
*     integer iargc 
C! local parameters
      integer outP,err
      real*8  M,Emin,Ntot,Etot,sigmaV,v/0.001/,tab(250),fi
      character*20 mess
      character*100 fname,buff
      character*6 outName(6)/'gamma','e+','p-','nu_e','nu_mu','nu_tau'/
  
      if(iargc().eq.0) then
         write(*,*)' The program need one arguments,'
         write(*,*)' name of file with MSSM parameters'
         stop
      endif
      
      call getarg(1,fname)

      err=readVar(fname)
      if(err.eq.-1) stop 'Can not open the file'
      if(err.gt.0)then 
         write(*,*) 'Wrong file contents at line ',err 
         stop
      endif
   
      if(err.gt.0) then
           stop 'can not calculate masses'
      endif

      err=sortOddParticles(mess)

      if(err.ne.0) then
        write(*,*) 'Can t calculate ', mess
        STOP
      endif 

c      call printMasses(6,1)

C** Emin - energy cut           
      Emin=0.1     
C** outP: 0-photons, 1- positrons, 2 -antiprotons, 
C**     3-4-5 neutrunos with antineutrinos    
      outP=0
C** fi angle of sight [rad]    
      fi=0
 
      sigmaV=calcSpectrum(v,outP,tab,err)    
      M=lopmass()
      call spectrInfo(Emin/M,tab,Ntot,Etot) 
      write(buff,13) outName(outP+1),Ntot,Etot,sigmaV,mess,M  
13     format(A6,': ',
     > 'N=',1PE8.2,',<E/2M>=',1PE8.2,';vcs=',1PE8.2,
     >'cm^3/sec,M(',A3,')=',1PE8.2)

      call spectrTable(tab,'tab',buff, Emin/M ,300)
    
      call system('../CalcHEP_src/bin/tab_view < tab&') 
      
      write(*,fmt='(A26,1PE10.2 )') 'gamma flux[ph/cm^2/s/sr]= ',
     > sigmaV*Ntot*HaloFactor(fi, rhoQisotermic)/M/M  

100   STOP
      end
