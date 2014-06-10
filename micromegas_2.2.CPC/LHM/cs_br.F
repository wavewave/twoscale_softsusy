      implicit none
C! external functions
#include "../sources/micromegas.fh"
#include "lib/pmodel.fh"
C!  local parameters   
      real*8 Pcm,Xf,cosmin, cosmax
        
      integer err 
      integer cc(2)
      character*200 fname
      integer ntot,l, nin,nout
      character*6 name(4)
      real*8 mass(4)
      real*8 cs,tw

      if(iargc().eq.0) then
         write(*,*)' The program need one arguments,'
         write(*,*)' name of file with  parameters'
         stop
      endif
      
      call getarg(1,fname)

      err=readVar(fname)
      if(err.eq.-1) stop 'Can not open the file'
      if(err.gt.0)then 
         write(*,*) 'Wrong file contents at line ',err 
         stop
      endif
    
      write(*,*) 'Examples of calculations of particle widths'
      tw= decay2Info('Z',6)
      tw= decay2Info('W+',6)
    
      write(*,*) 
      write(*,*) 'Examples of calculations of cross sections'
      Pcm=500
      cosmin=-0.99
      cosmax=0.99
      write(*,*) 'Process e,E->2*x at Pcm= ',Pcm, 'GeV'
      call newProcess('e,E->2*x','eE_2x',cc)
      write(*,*) 'ok1', cc(1)
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
              write(*,*) cs, '[pb]'
          endif 
        enddo
      endif 
    
      write(*,*)
      write(*,*) 'Neutralino annihilation at freez-out'
      Xf=25
     
      call newProcess(' ','omg_to1___to1',cc)
      if(cc(1).ne.0) then
        call procInfo1(cc,ntot,nin,nout)
        do l=1, ntot 
          call procInfo2(cc,l,name,mass)
          if(l.eq.1) then
             Pcm=mass(1)*sqrt(3/(2*Xf)) 
             write(*,*) '(Pcm=',Pcm,')'
          endif
          write(*,fmt='(A3,1x,A3,A4,A3,1x,A3,$)')
     >     name(1),name(2),' -> ', name(3),name(4)
          cs= cs22(cc,l,Pcm,-1.D0,1.D0,err)
          if(err.ne.0) then 
              write(*,*) 'Error'
          else if(cs.eq.0.) then
            write(*,*) 'Zero'
          else 
            write(*,*) cs, '[pb]'
          endif 
        enddo
      endif
      end  
