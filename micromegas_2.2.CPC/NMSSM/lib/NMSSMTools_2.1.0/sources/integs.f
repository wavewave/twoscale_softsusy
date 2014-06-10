*   Subroutines to integrate the RGEs for the soft terms


	SUBROUTINE
     C	 ODEINTS(YSTART,NVAR,X1,X2,EPS,DERIVSS,RKQSS,IFAIL)

*   Driver subroutine to integrate Ordinary Differential Equations
*   using the Runge-Kutta 5th order method with adaptative step size
*   (from Numerical Recipes)
*   IFAIL=1 stepsize smaller than minimum in ODEINTS
*   IFAIL=2 too many steps in ODEINTS
*   IFAIL=3 stepsize underflow in RKQSS
*   IFAIL=4 max(|dy(i)/dx|*(1+x)/(1+|y(i)|)) > 1/eps^2

	IMPLICIT NONE

	INTEGER NVAR,NMAX,IFAIL,MAXSTP,NSTP,I
	PARAMETER(MAXSTP=10000,NMAX=500)

	DOUBLE PRECISION YSTART(NVAR),Y(NMAX),YSCAL(NMAX)
	DOUBLE PRECISION DYDX(NMAX),X,X1,X2,EPS,TINY
	DOUBLE PRECISION H1,HMIN,H,HDID,HNEXT

	EXTERNAL DERIVSS,RKQSS

	IFAIL=0
	TINY=EPS**4
	H1=DSQRT(EPS)*DABS(X2-X1)
	HMIN=EPS**2*DABS(X2-X1)

	X=X1
	H=DSIGN(H1,X2-X1)
	DO I=1,NVAR
	 Y(I)=YSTART(I)
	ENDDO

	DO NSTP=1,MAXSTP

	 CALL DERIVSS(NVAR,X,Y,DYDX)

	 DO I=1,NVAR
	  IF(DABS(DYDX(I))*(1.D0+X)/(1.D0+DABS(Y(I))).GT.EPS**-2)IFAIL=4
	 ENDDO
	 IF(IFAIL.NE.0)RETURN

	 DO I=1,NVAR
	  YSCAL(I)=DABS(Y(I))+DABS(H*DYDX(I))+TINY
	 ENDDO

	 IF((X+H-X2)*(X+H-X1).GT.0.D0) H=X2-X

	 CALL
     C	  RKQSS(Y,DYDX,NVAR,X,H,EPS,YSCAL,HDID,HNEXT,DERIVSS,IFAIL)

	 IF(IFAIL.NE.0)RETURN

	 IF((X-X2)*(X2-X1).GE.0.D0)THEN
	  DO I=1,NVAR
	   YSTART(I)=Y(I)
	  ENDDO
	  RETURN
	 ENDIF

	 IF(ABS(HNEXT).LT.HMIN)THEN
	  IFAIL=1
	  RETURN
	 ENDIF

	 H=HNEXT

	ENDDO

	IFAIL=2

	RETURN
	END


	SUBROUTINE RKQSS(Y,DYDX,N,X,HTRY,EPS,YSCAL,HDID,
     C	 HNEXT,DERIVSS,IFAIL)

*   Stepper subroutine for ODEINTS

	IMPLICIT NONE

	INTEGER IFAIL,I,N,NMAX
	PARAMETER(NMAX=500)

	DOUBLE PRECISION EPS,HDID,HNEXT,HTRY,X,DYDX(N),Y(N),YSCAL(N)
	DOUBLE PRECISION ERRMAX,H,HTEMP,XNEW,YERR(NMAX),YTEMP(NMAX)
	DOUBLE PRECISION SAFETY,PGROW,PSHRNK,ERRCON

	EXTERNAL DERIVSS

	SAFETY=.9D0
	PGROW=-.2D0
	PSHRNK=-.25D0
	ERRCON=(5.D0/SAFETY)**(1.D0/PGROW)
	H=HTRY

1	CALL RKCKS(Y,DYDX,N,X,H,YTEMP,YERR,DERIVSS)

	ERRMAX=0.D0
	DO I=1,N
	 ERRMAX=MAX(ERRMAX,DABS(YERR(I)/YSCAL(I)))
	ENDDO
	ERRMAX=ERRMAX/EPS

	IF(ERRMAX.GT.1.D0)THEN

	 HTEMP=SAFETY*H*(ERRMAX**PSHRNK)
	 H=SIGN(MAX(DABS(HTEMP),.1D0*DABS(H)),H)
	 XNEW=X+H
	 IF(XNEW.EQ.X)THEN
	  IFAIL=3
	  RETURN
	 ENDIF
	 GOTO 1

	ELSE

	 IF(ERRMAX.GT.ERRCON)THEN
	  HNEXT=SAFETY*H*(ERRMAX**PGROW)
	 ELSE
	  HNEXT=5.D0*H
	 ENDIF
	 HDID=H
	 X=X+H
	 DO I=1,N
	  Y(I)=YTEMP(I)
	 ENDDO
	 RETURN

	ENDIF

	END


	SUBROUTINE RKCKS(Y,DYDX,N,X,H,YOUT,YERR,DERIVSS)

*   Algorithm subroutine for ODEINT

	IMPLICIT NONE

	INTEGER I,N,NMAX
	PARAMETER(NMAX=500)

	DOUBLE PRECISION H,X,DYDX(N),Y(N),YERR(N),YOUT(N)
	DOUBLE PRECISION AK2(NMAX),AK3(NMAX),AK4(NMAX)
	DOUBLE PRECISION AK5(NMAX),AK6(NMAX),YTEMP(NMAX)
	DOUBLE PRECISION A2,A3,A4,A5,A6,C1,C3,C4,C6
	DOUBLE PRECISION B21,B31,B32,B41,B42,B43,B51,B52,B53,B54
	DOUBLE PRECISION B61,B62,B63,B64,B65,DC1,DC3,DC4,DC5,DC6

	PARAMETER(A2=.2D0, A3=.3D0, A4=.6D0, A5=1.D0, A6=.875D0,
     .	 B21=.2D0, B31=3.D0/40.D0, B32=9.D0/40.D0, B41=.3D0, B42=-.9D0,
     .	 B43=1.2D0,B51=-11.D0/54.D0, B52=2.5D0, B53=-70.D0/27.D0,
     .	 B54=35.D0/27.D0, B61=1631.D0/55296.D0, B62=175.D0/512.D0,
     .	 B63=575.D0/13824.D0, B64=44275.D0/110592.D0,
     .	 B65=253.D0/4096.D0, C1=37.D0/378.D0, C3=250.D0/621.D0,
     .	 C4=125.D0/594.D0, C6=512.D0/1771.D0, DC1=C1-2825.D0/27648.D0,
     .	 DC3=C3-18575.D0/48384.D0, DC4=C4-13525.D0/55296.D0,
     .	 DC5=-277.D0/14336.D0, DC6=C6-.25D0)

	EXTERNAL DERIVSS

	DO I=1,N
	 YTEMP(I)=Y(I)+B21*H*DYDX(I)
	ENDDO
	CALL DERIVSS(N,X+A2*H,YTEMP,AK2)
	DO I=1,N
	 YTEMP(I)=Y(I)+H*(B31*DYDX(I)+B32*AK2(I))
	ENDDO
	CALL DERIVSS(N,X+A3*H,YTEMP,AK3)
	DO I=1,N
	 YTEMP(I)=Y(I)+H*(B41*DYDX(I)+B42*AK2(I)+B43*AK3(I))
	ENDDO
	CALL DERIVSS(N,X+A4*H,YTEMP,AK4)
	DO I=1,N
	 YTEMP(I)=Y(I)+H*(B51*DYDX(I)+B52*AK2(I)+B53*AK3(I)+B54*AK4(I))
	ENDDO
	CALL DERIVSS(N,X+A5*H,YTEMP,AK5)
	DO I=1,N
	 YTEMP(I)=Y(I)+H*(B61*DYDX(I)+B62*AK2(I)+B63*AK3(I)+B64*AK4(I)+
     .	  B65*AK5(I))
	ENDDO
	CALL DERIVSS(N,X+A6*H,YTEMP,AK6)
	DO I=1,N
	 YOUT(I)=Y(I)+H*(C1*DYDX(I)+C3*AK3(I)+C4*AK4(I)+C6*AK6(I))
	ENDDO
	DO I=1,N
	 YERR(I)=H*(DC1*DYDX(I)+DC3*AK3(I)+DC4*AK4(I)+DC5*AK5(I)+DC6*
     .	  AK6(I))
	ENDDO

	RETURN
	END


	SUBROUTINE DERIVSS(N,X,Y,F)

*   2-loop Renormalization group equations for g1, g2, g3,
*   lambda, kappa, htop, hbot, htau and for all soft terms
*   to be integrated by ODEINTS

	IMPLICIT NONE

	INTEGER N
	DOUBLE PRECISION X,Y(N),F(N),PI,c2,S
	DOUBLE PRECISION G1,G2,G3,L2,K2,HT2,HB2,HTAU2
	DOUBLE PRECISION M1,M2,M3,AL,AK,AT,AB,ATAU,AMUON
	DOUBLE PRECISION MHU,MHD,MS,MQ3,MU3,MD3,MQ,MU,MD
	DOUBLE PRECISION ML3,ME3,ML,ME,SP,SIG1,SIG2,SIG3

	PI=4.D0*DATAN(1.D0)
	c2=1.D0/(16.D0*PI**2)
	
	G1=Y(1)
	G2=Y(2)
	G3=Y(3)
	L2=Y(4)
	K2=Y(5)
	HT2=Y(6)
	HB2=Y(7)
	HTAU2=Y(8)
	M1=Y(9)
	M2=Y(10)
	M3=Y(11)
	AL=Y(12)
	AK=Y(13)
	AT=Y(14)
	AB=Y(15)
	ATAU=Y(16)
	MHU=Y(17)
	MHD=Y(18)
	MS=Y(19)
	MQ3=Y(20)
	MU3=Y(21)
	MD3=Y(22)
	MQ=Y(23)
	MU=Y(24)
	MD=Y(25)
	ML3=Y(26)
	ME3=Y(27)
	ML=Y(28)
	ME=Y(29)
	AMUON=Y(30)

        S=g1*(MHU-MHD+MQ3-2.D0*MU3+MD3+2.D0*(MQ
     .	  -2.D0*MU+MD)+ME3-ML3+2.D0*(ME-ML))

	SP=HT2*(-3.D0*MHU-MQ3+4.D0*MU3)+HB2*(3.D0*MHD-MQ3-2.D0*MD3)

	SIG1=G1/3.D0*(3.D0*MHU+3.D0*MHD+MQ3+2.D0*MQ+3.D0*ML3+6.D0*ML
     .	     +8.D0*MU3+16.D0*MU+2.D0*MD3+4.D0*MD+6.D0*ME3+12.D0*ME)

        SIG2=G2*(MHU+MHD+3.D0*MQ3+6.D0*MQ+ML3+2.D0*ML)

	SIG3=G3*(2.D0*MQ3+4.D0*MQ+MU3+2.D0*MU+MD3+2.D0*MD)

	F(1)= 11.D0*g1**2
     .	    + c2*g1**2*(199.D0/9.D0*g1 + 9.D0*g2 + 88.D0/3.D0*g3
     .	    - 2.D0*L2 - 26.D0/3.D0*HT2 - 14.D0/3.D0*HB2 - 6.D0*HTAU2)

	F(2) = g2**2
     .	    + c2*g2**2*(3.D0*g1 + 25.D0*g2 + 24.D0*g3
     .	    - 2.D0*L2 - 6.D0*HT2 - 6.D0*HB2 - 2.D0*HTAU2)

	F(3)= -3.D0*g3**2
     .	    + c2*g3**2*(11.D0/3.D0*g1 + 9.D0*g2 + 14.D0*g3
     .	    - 4 .D0*HT2 - 4.D0*HB2)

	F(4)= L2*(-g1 - 3.D0*g2
     .	    + 4.D0*L2 + 2.D0*K2 + 3.D0*HT2 + 3.D0*HB2 + HTAU2)
     .	    + c2*L2*(L2*(2.D0*g1 + 6.D0*g2
     .	    - 10.D0*L2 - 12.D0*K2 - 9.D0*HT2 - 9.D0*HB2)
     .	    + 23.D0/2.D0*g1**2 + 15.D0/2.D0*g2**2 + 3.D0*g1*g2
     .	    + 4.D0/3.D0*g1*HT2 - 2.D0/3.D0*g1*HB2
     .	    + 16.D0*g3*HT2 + 16.D0*g3*HB2
     .	    - 9.D0*HT2**2 - 9.D0*HB2**2 - 6.D0*HT2*HB2 - 8.D0*K2**2)

	F(5)= 6.D0*K2*(L2 + K2)
     .	    + c2*K2*(24.D0*K2*(L2 - K2)
     .	    + 6.D0*L2*(g1 + 3.D0*g2 - 2.D0*L2 + 3.D0*HT2 + 3.D0*HB2))

	F(6)= HT2*(-13.D0/9.D0*g1 - 3.D0*g2 - 16.D0/3.D0*g3
     .	    + L2 + 6.D0*HT2 + HB2)
     .	    + c2*HT2*(HT2*(2.D0*g1 + 6.D0*g2 + 16.D0*g3
     .	    - 3.D0*L2 - 22.D0*HT2 - 5.D0*HB2)
     .	    + 2743.D0/162.D0*g1**2 + 15.D0/2.D0*g2** 2- 16.D0/9.D0*g3**2
     .	    + 5.D0/3.D0*g1*g2 + 136.D0/27.D0*g1*g3 + 8.D0*g2*g3
     .	    + 2.D0/3.D0*g1*HB2 - 3.D0*L2**2 - 2.D0*L2*K2
     .	    - 4.D0*L2*HB2 - 5.D0*HB2**2-HB2*HTAU2)

	F(7)= HB2*(-7.D0/9.D0*g1 - 3.D0*g2 - 16.D0/3.D0*g3
     .	    + L2 + HT2 + 6.D0*HB2+HTAU2)
     .	    + c2*HB2*(HB2*(2.D0/3.D0*g1 + 6.D0*g2 + 16.D0*g3
     .	    - 3.D0*L2 - 5.D0*HT2 - 22.D0*HB2-3.D0*HTAU2)
     .	    + 1435.D0/162.D0*g1**2 + 15.D0/2.D0*g2**2 - 16.D0/9.D0*g3**2
     .	    + 5.D0/3.D0*g1*g2 + 40.D0/27.D0*g1*g3 + 8.D0*g2*g3
     .	    + 4.D0/3.D0*g1*HT2 - 3.D0*L2**2 - 2.D0*L2*K2
     .	    - 4.D0*L2*HT2 - 5.D0*HT2**2-3.D0*HTAU2**2)
     
	F(8)= HTAU2*(-3.D0*g1 - 3.D0*g2
     .	    + L2 + 3.D0*HB2 + 4.D0*HTAU2)
     .	    + c2*HTAU2*(-10.D0*HTAU2**2-9.D0*HTAU2*HB2-9.D0*HB2**2
     .	    - 3.D0*HB2*HT2+HTAU2*(2.D0*G1+6.D0*G2)
     .	    + HB2*(16*G3-2.D0/3.D0*G1)
     .	    + 75.D0/2.D0*G1**2+3.D0*G1*G2+15.D0/2.D0*G2**2)
     
        F(9)=11.D0*g1*M1
     .	     +c2*g1*(398.D0/9.D0*g1*M1+9.D0*g2*(M1+M2)
     .	     +88.D0/3.D0*g3*(M1+M3)+26.D0/3.D0*HT2*(AT-M1)
     .	     +14.D0/3.D0*HB2*(AB-M1)+6.D0*HTAU2*(ATAU-M1)
     .	     +2.D0*L2*(AL-M1))
	
	F(10)=g2*M2
     .	     +c2*g2*(3.D0*g1*(M1+M2)+50.D0*g2*M2
     .	     +24.D0*g3*(M2+M3)+6.D0*HT2*(AT-M2)
     .	     +6.D0*HB2*(AB-M2)+2.D0*HTAU2*(ATAU-M2)
     .	     +2.D0*L2*(AL-M2))
	
	F(11)=-3.D0*g3*M3
     .	     +c2*g3*(11.D0/3.D0*g1*(M1+M3)
     .	     +9.D0*g2*(M2+M3)
     .	     +28.D0*g3*M3+4.D0*HT2*(AT-M3)
     .	     +4.D0*HB2*(AB-M3))

	F(12)=(4.D0*L2*AL+2.D0*K2*AK+3.D0*HT2*AT
     .	      +3.D0*HB2*AB+HTAU2*ATAU+g1*M1+3.D0*g2*M2)

	F(13)=(6.D0*(L2*AL+K2*AK))

	F(14)=L2*AL+6.D0*HT2*AT+HB2*AB
     .	      +13.D0/9.D0*g1*M1+3.D0*g2*M2+16.D0/3.D0*g3*M3
     .	      +c2*(-44.D0*AT*HT2**2-5.D0*AT*HT2*HB2
     .	      -5.D0*AB*HT2*HB2-10.D0*AB*HB2**2
     .	      -HB2*HTAU2*(AB+ATAU)
     .	      +AT*HT2*(16.D0*g3+6.D0*g2+2.D0*g1)
     .	      -HT2*(16.D0*g3*M3+6.D0*g2*M2+2.D0*g1*M1)
     .	      +2.D0/3.D0*g1*HB2*(AB-M1)
     .	      +32.D0/9.D0*g3**2*M3-8.D0*g2*g3*(M2+M3)
     .	      -136.D0/27.D0*g1*g3*(M1+M2)-15.D0*g2**2*M2
     .	      -5.D0/3.D0*g1*g2*(M1+M2)-2743.D0/81.D0*g1**2*M1)

	F(15)=L2*AL+HT2*AT+6.D0*HB2*AB+HTAU2*ATAU
     .	      +7.D0/9.D0*g1*M1+3.D0*g2*M2+16.D0/3.D0*g3*M3
     .	      +c2*(-44.D0*AB*HB2**2-5.D0*AB*HT2*HB2
     .	      -5.D0*AT*HT2*HB2-10.D0*AT*HT2**2
     .	      -3.D0*HB2*HTAU2*(AB+ATAU)-6.D0*ATAU*HTAU2**2
     .	      +AB*HB2*(16.D0*g3+6.D0*g2+2.D0/3.D0*g1)
     .	      -HB2*(16.D0*g3*M3+6.D0*g2*M2+2.D0/3.D0*g1*M1)
     .	      +4.D0/3.D0*g1*HT2*(AT-M1)+2.D0*HTAU2*G1*(ATAU-M1)
     .	      +32.D0/9.D0*g3**2*M3-8.D0*g2*g3*(M2+M3)
     .	      -40.D0/27.D0*g1*g3*(M1+M2)-15.D0*g2**2*M2
     .	      -5.D0/3.D0*g1*g2*(M1+M2)-1435.D0/81.D0*g1**2*M1)

	F(16)=L2*AL+3.D0*HB2*AB+4.D0*HTAU2*ATAU
     .	      +3.D0*g1*M1+3.D0*g2*M2
     .	      +c2*(-20.D0*ATAU*HTAU2**2-9.D0*ATAU*HTAU2*HB2
     .	      -3.D0*(AT+AB)*HT2*HB2-18.D0*AB*HB2**2
     .	      -12.D0*HB2*HTAU2*AB
     .	      +6.D0*HTAU2*G2*(ATAU-M2)+16.D0*HB2*G3*(AB-M3)
     .	      +2.D0/3.D0*HB2*G1*(M1-AB)+2.D0*HTAU2*G1*(ATAU-M1)
     .	      -15.D0*g2**2*M2
     .	      -3.D0*g1*g2*(M1+M2)-75.D0*g1**2*M1)

	F(17)=L2*(MHU+MHD+MS+AL**2)
     .	      +3.D0*HT2*(MHU+MQ3+MU3+AT**2)
     .	      -g1*M1**2-3.D0*g2*M2**2+S/2.D0
     .	      +C2*(-3.D0*HT2**2*(6.D0*(MHU+MU3+MQ3)+12.D0*AT**2)
     .	      -3.D0*HT2*HB2*(MHU+MHD+2.D0*MQ3+MU3+MD3+(AT+AB)**2)
     .	      +16.D0*G3*HT2*(MHU+MQ3+MU3+AT**2+2.D0*M3*(M3-AT))
     .	      +4.D0/3.D0*G1*HT2*(MHU+MQ3+MU3+AT**2+2.D0*M1*(M1-AT))
     .	      +33.D0/2.D0*G2**2*M2**2+3.D0*G1*G2*(M1**2+M2**2+M1*M2)
     .	      +69.D0/2.D0*G1**2*M1**2+G1*SP+1.D0/2.D0*G1*SIG1
     .	      +3.D0/2.D0*G2*SIG2)

	F(18)=L2*(MHU+MHD+MS+AL**2)
     .	      +3.D0*HB2*(MHD+MQ3+MQ+AB**2)
     .	      +HTAU2*(MHD+ML3+ME3+ATAU**2)
     .	      -g1*M1**2-3.D0*g2*M2**2-S/2.D0
     .	      +C2*(-3.D0*HB2**2*(6.D0*(MHD+MD3+MQ3)+12.D0*AB**2)
     .	      -3.D0*HT2*HB2*(MHU+MHD+2.D0*MQ3+MU3+MD3+(AT+AB)**2)
     .	      -6.D0*HTAU2**2*(MHD+ML3+ME3+2.D0*ATAU**2)
     .	      +16.D0*G3*HB2*(MHD+MQ3+MD3+AB**2+2.D0*M3*(M3-AB))
     .	      -2.D0/3.D0*G1*HB2*(MHD+MQ3+MD3+AB**2+2.D0*M1*(M1-AB))
     .	      +2.D0*G1*HTAU2*(MHD+ML3+ME3+ATAU**2+2.D0*M1*(M1-ATAU))
     .	      +33.D0/2.D0*G2**2*M2**2+3.D0*G1*G2*(M1**2+M2**2+M1*M2)
     .	      +69.D0/2.D0*G1**2*M1**2-G1*SP+1.D0/2.D0*G1*SIG1
     .	      +3.D0/2.D0*G2*SIG2)

	F(19)=2.D0*L2*(MHU+MHD+MS+AL**2)
     .	      +2.D0*K2*(3.D0*MS+AK**2)

	F(20)=HT2*(MHU+MQ3+MU3+AT**2)
     .	      +HB2*(MHD+MQ3+MD3+AB**2)
     .	      -g1*M1**2/9.D0-3.D0*g2*M2**2
     .	      -16.D0/3.D0*g3*M3**2+S/3.D0
     .	      +C2*(-10.D0*HT2**2*(MHU+MU3+MQ3+2.D0*AT**2)
     .	      -10.D0*HB2**2*(MHD+MD3+MQ3+2.D0*AB**2)
     .	      -HTAU2*HB2*(2.D0*MHD+MQ3+MD3+ML3+ME3+(ATAU+AB)**2)
     .	      +4.D0/3.D0*G1*HT2*(MHU+MQ3+MU3+AT**2+2.D0*M1*(M1-AT))
     .	      +2.D0/3.D0*G1*HB2*(MHD+MQ3+MD3+AB**2+2.D0*M1*(M1-AB))
     .	      -64.D0/3.D0*G3**2*M3**2+16.D0*G2*G3*(M2**2+M3**2+M2*M3)
     .	      +16.D0/27.D0*G1*G3*(M1**2+M3**2+M1*M3)
     .	      +33.D0/2.D0*G2**2*M2**2
     .	      +1.D0/3.D0*G1*G2*(M1**2+M2**2+M1*M2)
     .	      +199.D0/54.D0*G1**2*M1**2+1.D0/3.D0*G1*SP
     .	      +1.D0/18.D0*G1*SIG1+3.D0/2.D0*G2*SIG2+8.D0/3.D0*G3*SIG3)

	F(21)=2.D0*HT2*(MHU+MQ3+MU3+AT**2)
     .	      -16.D0/9.D0*g1*M1**2
     .	      -16.D0/3.D0*g3*M3**2-2.D0/3.D0*S
     .	      +C2*(-16.D0*HT2**2*(MHU+MU3+MQ3+2.D0*AT**2)
     .	      -2.D0*HT2*HB2*(MU3+MHU+MHD+2.D0*MQ3+MD3+(AT+AB)**2)
     .	      +3.D0*G2*HT2*(MU3+2.D0*MHU+2.D0*MQ3+MU3+2.D0*AT**2
     .	      +4.D0*M2*(M2-AT))
     .	      -1.D0/3.D0*G1*HT2*(MU3+2.D0*MHU+2.D0*MQ3+MU3+2.D0*AT**2
     .	      +4.D0*M1*(M1-AT))
     .	      -64.D0/3.D0*G3**2*M3**2
     .	      +256.D0/27.D0*G1*G3*(M1**2+M3**2+M1*M3)
     .	      +1712.D0/27.D0*G1**2*M1**2-4.D0/3.D0*G1*SP
     .	      +8.D0/9.D0*G1*SIG1+8.D0/3.D0*G3*SIG3)

	F(22)=2.D0*HB2*(MHD+MQ3+MD3+AB**2)
     .	      -4.D0/9.D0*g1*M1**2
     .	      -16.D0/3.D0*g3*M3**2+1.D0/3.D0*S
     .	      +C2*(-16.D0*HB2**2*(MHD+MD3+MQ3+2.D0*AB**2)
     .	      -2.D0*HT2*HB2*(MD3+MHU+MHD+2.D0*MQ3+MU3+(AT+AB)**2)
     .	      -2.D0*HTAU2*HB2*(MD3+2.D0*MHD+MQ3+ML3+ME3+(ATAU+AB)**2)
     .	      +3.D0*G2*HB2*(MD3+2.D0*MHD+2.D0*MQ3+MD3+2.D0*AB**2
     .	      +4.D0*M2*(M2-AB))
     .	      +1.D0/3.D0*G1*HB2*(MD3+2.D0*MHD+2.D0*MQ3+MD3+2.D0*AB**2
     .	      +4.D0*M1*(M1-AB))
     .	      -64.D0/3.D0*G3**2*M3**2
     .	      +64.D0/27.D0*G1*G3*(M1**2+M3**2+M1*M3)
     .	      +404.D0/27.D0*G1**2*M1**2+2.D0/3.D0*G1*SP
     .	      +2.D0/9.D0*G1*SIG1+8.D0/3.D0*G3*SIG3)

	F(23)=-g1*M1**2/9.D0-3.D0*g2*M2**2
     .	      -16.D0/3.D0*g3*M3**2+S/3.D0
     .	      +C2*(-64.D0/3.D0*G3**2*M3**2
     .	      +16.D0*G2*G3*(M2**2+M3**2+M2*M3)
     .	      +16.D0/27.D0*G1*G3*(M1**2+M3**2+M1*M3)
     .	      +33.D0/2.D0*G2**2*M2**2+1.D0/3.D0*G1*G2*(M1**2+M2**2
     .	      +M1*M2)+199.D0/54.D0*G1**2*M1**2+1.D0/3.D0*G1*SP
     .	      +1.D0/18.D0*G1*SIG1+3.D0/2.D0*G2*SIG2+8.D0/3.D0*G3*SIG3)

	F(24)=-16.D0/9.D0*g1*M1**2
     .	      -16.D0/3.D0*g3*M3**2-2.D0/3.D0*S
     .	      +C2*(-64.D0/3.D0*G3**2*M3**2
     .	      +256.D0/27.D0*G1*G3*(M1**2+M3**2+M1*M3)
     .	      +1712.D0/27.D0*G1**2*M1**2-4.D0/3.D0*G1*SP
     .	      +8.D0/9.D0*G1*SIG1+8.D0/3.D0*G3*SIG3)
  
	F(25)=-4.D0/9.D0*g1*M1**2
     .	      -16.D0/3.D0*g3*M3**2+1.D0/3.D0*S
     .	      +C2*(-64.D0/3.D0*G3**2*M3**2
     .	      +64.D0/27.D0*G1*G3*(M1**2+M3**2+M1*M3)
     .	      +404.D0/27.D0*G1**2*M1**2+2.D0/3.D0*G1*SP
     .	      +2.D0/9.D0*G1*SIG1+8.D0/3.D0*G3*SIG3)

        F(26)=HTAU2*(MHD+ML3+ME3+ATAU**2)
     .	      -g1*M1**2-3.D0*g2*M2**2-1.D0/2.D0*S
     .	      +C2*(-6.D0*HTAU2*(ML3+MHD+ME3+2.D0*ATAU**2)
     .	      -3.D0*HTAU2*HB2*(ML3+2.D0*MHD+ME3+MQ3+MD3+(ATAU+AB)**2)
     .	      +2.D0*G1*HTAU2*(ML3+MHD+ME3+ATAU**2+2.D0*M1*(M1-ATAU))
     .	      +33.D0/2.D0*G2**2*M2**2+3.D0/2.D0*G1*G2*(M1**2+M2**2
     .	      +M1*M2)+69.D0/2.D0*G1**2*M1**2-G1*SP+1.D0/2.D0*G1*SIG1
     .	      +3.D0/2.D0*G2*SIG2)

	F(27)=2.D0*HTAU2*(MHD+ML3+ME3+ATAU**2)
     .	      -4.D0*g1*M1**2+S
     .	      +C2*(-8.D0*HTAU2*(ML3+MHD+ME3+2.D0*ATAU**2)
     .	      -6.D0*HTAU2*HB2*(ML3+2.D0*MHD+ME3+MQ3+MD3+(ATAU+AB)**2)
     .	      +6.D0*G2*HTAU2*(ME3+MHD+ML3+ATAU**2+2.D0*M2*(M2-ATAU))
     .	      -2.D0*G1*HTAU2*(ML3+MHD+ME3+ATAU**2+2.D0*M1*(M1-ATAU))
     .	      +156.D0*G1**2*M1**2+2.D0*G1*SP+2.D0*G1*SIG1)

	F(28)=-g1*M1**2-3.D0*g2*M2**2-1.D0/2.D0*S
     .	      +C2*(+33.D0/2.D0*G2**2*M2**2
     .	      +3.D0/2.D0*G1*G2*(M1**2+M2**2+M1*M2)
     .	      +69.D0/2.D0*G1**2*M1**2-G1*SP+1.D0/2.D0*G1*SIG1
     .	      +3.D0/2.D0*G2*SIG2)

	F(29)=-4.D0*g1*M1**2+S
     .	      +C2*(156.D0*G1**2*M1**2+2.D0*G1*SP+2.D0*G1*SIG1)

	F(30)=L2*AL+3.D0*HB2*AB+HTAU2*ATAU
     .	      +3.D0*g1*M1+3.D0*g2*M2
     .	      +c2*(-6.D0*ATAU*HTAU2**2
     .	      -3.D0*(AT+AB)*HT2*HB2-18.D0*AB*HB2**2
     .	      +16.D0*HB2*G3*(AB-M3)
     .	      +2.D0/3.D0*HB2*G1*(M1-AB)+2.D0*HTAU2*G1*(ATAU-M1)
     .	      -15.D0*g2**2*M2
     .	      -3.D0*g1*g2*(M1+M2)-75.D0*g1**2*M1)

	RETURN
	END
