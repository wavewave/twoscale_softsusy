      implicit none

C!      external 
#include "../sources/micromegas.fh"
#include"lib/pmodel.fh"
*      integer iargc
C!  local parameters
      integer   fast/1/
      real*8 Beps/1.E-1/, cut/0.01/
      real*8 Omega,Xf
      character*20 mess
      character*50 argv
      integer nw,err

      if(iargc().eq.0) then
         write(*,*)'Correct usage:  ./omg <file with parameters>'
         stop
      endif

      call getarg(1,argv)                               

      err=readVar(argv)

      if(err.eq.-1) then
          write(*,*) 'Can not open the file'
          stop
      endif

      if(err.gt.0) then
          write(*,*)'Wrong file contents at line ',err
          stop
      endif

      err=sortOddParticles(mess)
      if(err.ne.0) then
          write(*,*) 'Can not calculate ',mess
          stop
      endif

      call printMasses(6,1)

                                             
      write(*,*) 'Dark Matter candidate is ', mess                                   

  
      Omega=darkOmega(Xf,fast,Beps)
      write(*,fmt='(A3,F6.2,A7,1PE10.2)')'Xf=',Xf,' Omega=',Omega 
      omg= printChannels(Xf,cut,Beps,1,6)
      end
