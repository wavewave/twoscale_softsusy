	SUBROUTINE CHECKMIN(PAR,PROB)

**********************************************************************	
* Subroutine to check whether the physical minimum of the effective
* potential (<h1>, <h2> and <s> =/= 0) is deeper than minima with
* <h1>, <h2> or <s> = 0
*
* If not: PROB(28) =/= 0
*
* The effective potential includes 1 loop contributions (large logs 
* + finite) from (s)top and (s)bottom loops
*
* As a byproduct, the soft masses squared mh1, mh2 and mss (implicitely
* at the scale QSTSB, and used only by NMHDECAY) are computed here
* and stored in COMMON/QMHIGGS
* If mh1, mh2 >> Q2 then PROB(29)=/=0
*
**********************************************************************

	IMPLICIT NONE

	DOUBLE PRECISION PAR(*),PROB(*)
	DOUBLE PRECISION B
	DOUBLE PRECISION QSTSB,pi,cc,mQ3,mU3,mD3,At,Ab
	DOUBLE PRECISION mst1,mst2,s2t,msb1,msb2,s2b,XT,XB
	DOUBLE PRECISION Mstop,dMst,Wt
	DOUBLE PRECISION Msbot,dMsb,Wb
	DOUBLE PRECISION ct,fmt1,fmt2,fmt,gmt
	DOUBLE PRECISION cb,fmb1,fmb2,fmb,gmb
	DOUBLE PRECISION V,V0,V1,V2,V3,D,mh1,mh2,mss
	DOUBLE PRECISION ALSMZ,ALEMMZ,GF,g1,g2,S2TW
	DOUBLE PRECISION MS,MC,MB,MBP,MT,MTAU,MMUON,MZ,MW
	DOUBLE PRECISION M2,REW,EPS
	DOUBLE PRECISION ZHU,ZHD,ZS,H1Q,H2Q,TANBQ
	DOUBLE PRECISION HTQ,HBQ,MTOPQ,MBOTQ
	DOUBLE PRECISION LQ,KQ,ALQ,AKQ,MUQ,NUQ
	DOUBLE PRECISION G1Q,G2Q,GQ,ALSQ,Q2
	
	COMMON/GAUGE/ALSMZ,ALEMMZ,GF,g1,g2,S2TW
	COMMON/SMSPEC/MS,MC,MB,MBP,MT,MTAU,MMUON,MZ,MW
	COMMON/STSBSCALE/QSTSB
	COMMON/QMHIGGS/MH1,MH2,MSS
	COMMON/RADCOR/mst1,mst2,s2t,msb1,msb2,s2b,XT,XB
	COMMON/RADCOR2/MQ3,MU3,MD3,AT,AB
	COMMON/QGAUGE/G1Q,G2Q,GQ,ALSQ
	COMMON/QHIGGS/ZHU,ZHD,ZS,H1Q,H2Q,TANBQ
	COMMON/QQUARK/HTQ,HBQ,MTOPQ,MBOTQ
	COMMON/QNMPAR/LQ,KQ,ALQ,AKQ,MUQ,NUQ
	COMMON/RENSCALE/Q2

	pi=4.D0*DATAN(1.D0)
	cc=3.D0/(32.D0*pi**2)
	EPS=-1.D-2

	
*   Parameters for (S)top/(S)bottom rad. corrs. in wrong minima:

	Mstop=(mQ3+mU3)/2.D0
	dMst=(mQ3-mU3)/2.D0
	Msbot=(mQ3+mD3)/2.D0
	dMsb=(mQ3-mD3)/2.D0
	
	IF(MIN(mst1,msb1).LE.0.D0)RETURN

	ct=3.D0*htq**2/(16.D0*pi**2)
	fmt1=mst1*(DLOG(mst1/QSTSB)-1.D0)
	fmt2=mst2*(DLOG(mst2/QSTSB)-1.D0)
	fmt=mtopq**2*(DLOG(mtopq**2/QSTSB)-1.D0)
	IF(mst1-mst2.NE.0.D0)THEN
	 gmt=(fmt2-fmt1)/(mst2-mst1)
	ELSE
	 gmt=DLOG(mst1/QSTSB)
	ENDIF

	cb=3.D0*hbq**2/(16.D0*pi**2)
	fmb1=msb1*(DLOG(msb1/QSTSB)-1.D0)
	fmb2=msb2*(DLOG(msb2/QSTSB)-1.D0)
	fmb=mbotq**2*(DLOG(mbotq**2/QSTSB)-1.D0)
	IF(msb1-msb2.NE.0.D0)THEN
	 gmb=(fmb2-fmb1)/(msb2-msb1)
	ELSE
	 gmb=DLOG(msb1/QSTSB)
	ENDIF

*   Soft masses

	B=Alq+nuq
	mh1= -lq**2*h2q**2 - muq**2 + muq*B/tanbq 
     C  + gq/2.D0*(h2q**2-h1q**2)
     C	   - ct*(fmt1+fmt2-2.D0*fmt+At*Xt*gmt)
     C	   + cb*muq/tanbq*Xb*gmb
	mh2= -lq**2*h1q**2 - muq**2 + muq*B*tanbq 
     C     + gq/2.D0*(h1q**2-h2q**2)
     C	   + ct*muq*tanbq*Xt*gmt
     C	   - cb*(fmb1+fmb2-2.D0*fmb+Ab*Xb*gmb)
	mss= -lq**2*(h1q**2+h2q**2) - 2.D0*nuq**2
     C	   + lq**2*h1q*h2q/muq*(B+nuq) - nuq*Akq
     C	   + ct*lq**2*h1q*h2q/muq*Xt*gmt
     C	   + cb*lq**2*h1q*h2q/muq*Xb*gmb

* Large tan(beta) electroweak corrections to the minimization 
* equations:
	 
	 M2=PAR(21)
	 REW=1.D0/(16.D0*PI**2)*GQ*Kq/Lq*(2.D0*S2TW-3.D0)
     C      *DLOG(MAX(M2**2,MUQ**2,MZ**2)/QSTSB)

	 MH1=MH1-REW*MUq**2/TANBQ    
  	 MH2=MH2-REW*MUq**2*TANBQ	 

*   Physical minimum

	V= muq**2*(h1q**2+h2q**2) + lq**2*h1q**2*h2q**2 + nuq**4/kq**2
     C	  - 2.D0*nuq*muq*h1q*h2q - 2.D0*Alq*muq*h1q*h2q 
     C    + 2.D0/3.D0*Akq*nuq**3/kq**2
     C    +gq/4.D0*(h1q**2-h2q**2)**2
     C	  + mh1*h1q**2 + mh2*h2q**2 + mss*muq**2/lq**2
     C	  + cc*
     C	  ( mst1**2*(DLOG(mst1/QSTSB)-1.5D0)
     C	  + mst2**2*(DLOG(mst2/QSTSB)-1.5D0)
     C	  - 2.D0*mtopq**4*(DLOG(mtopq**2/QSTSB)-1.5D0)
     C	  + msb1**2*(DLOG(msb1/QSTSB)-1.5D0)
     C	  + msb2**2*(DLOG(msb2/QSTSB)-1.5D0)
     C	  - 2.D0*mbotq**4*(DLOG(mbotq**2/QSTSB)-1.5D0))

*   Minimum with h1=h2=s=0

	mst1=mU3
	mst2=mQ3
	msb1=mD3
	msb2=mQ3
	V0= 0.D0
     C	  + cc*
     C	  ( mst1**2*(DLOG(mst1/QSTSB)-1.5D0)
     C	  + mst2**2*(DLOG(mst2/QSTSB)-1.5D0)
     C	  + msb1**2*(DLOG(msb1/QSTSB)-1.5D0)
     C	  + msb2**2*(DLOG(msb2/QSTSB)-1.5D0))
	IF(V.NE.0.D0)THEN
	 PROB(28)=DDIM(EPS,(V0-V)/DABS(V))
	ELSE
	 PROB(28)=DDIM(EPS,V0)
	ENDIF

*   Minimum with h2=s=0

	V1=0.D0
	IF(mh1.LT.0)THEN
	 mtopq=htq*DSQRT(-2.D0*mh1/gq)
	 Wt=DSQRT(dMst**2+mtopq**2*At**2)
	 mst1=Mstop+mtopq**2-Wt
	 mst2=Mstop+mtopq**2+Wt
	 msb1=mD3
	 msb2=mQ3
	 IF(mst1.LE.0.D0)GOTO 1
	 V1= -mh1**2/gq
     C	   + cc*
     C	   ( mst1**2*(DLOG(mst1/QSTSB)-1.5D0)
     C	   + mst2**2*(DLOG(mst2/QSTSB)-1.5D0)
     C	   - 2.D0*mtopq**4*(DLOG(mtopq**2/QSTSB)-1.5D0)
     C	   + msb1**2*(DLOG(msb1/QSTSB)-1.5D0)
     C	   + msb2**2*(DLOG(msb2/QSTSB)-1.5D0))
	 IF(V.NE.0.D0)THEN
	  PROB(28)=PROB(28)+DDIM(EPS,(V1-V)/DABS(V))
	 ELSE
	  PROB(28)=PROB(28)+DDIM(EPS,V1)
	 ENDIF
 1	ENDIF

*   Minimum with h1=s=0

	V2=0.D0
	IF(mh2.LT.0)THEN
	 mst1=mU3
	 mst2=mQ3
	 mbotq=hbq*DSQRT(-2.D0*mh2/gq)
	 Wb=DSQRT(dMsb**2+mbotq**2*Ab**2)
	 msb1=Msbot+mbotq**2-Wb
	 msb2=Msbot+mbotq**2+Wb
	 IF(msb1.LE.0.D0)GOTO 2
	 V2= -mh2**2/gq
     C	   + cc*
     C	   ( mst1**2*(DLOG(mst1/QSTSB)-1.5D0)
     C	   + mst2**2*(DLOG(mst2/QSTSB)-1.5D0)
     C	   + msb1**2*(DLOG(msb1/QSTSB)-1.5D0)
     C	   + msb2**2*(DLOG(msb2/QSTSB)-1.5D0)
     C	   - 2.D0*mbotq**4*(DLOG(mbotq**2/QSTSB)-1.5D0))
	 IF(V.NE.0.D0)THEN
	  PROB(28)=PROB(28)+DDIM(EPS,(V2-V)/DABS(V))
	 ELSE
	  PROB(28)=PROB(28)+DDIM(EPS,V2)
	 ENDIF
 2	ENDIF

*   Minimum with h1=h2=0

	V3=0.D0
	D=Akq**2-8.D0*mss
	IF(D.GT.0)THEN
	 mst1=mU3
	 mst2=mQ3
	 msb1=mD3
	 msb2=mQ3
	 IF(Akq.GT.0.D0)nuq=(-Akq-DSQRT(D))/4.D0
	 IF(Akq.LT.0.D0)nuq=(-Akq+DSQRT(D))/4.D0
	 V3= (nuq**2+2.D0/3.D0*Akq*nuq+mss)*nuq**2/kq**2
     C	   + cc*
     C	   ( mst1**2*(DLOG(mst1/QSTSB)-1.5D0)
     C	   + mst2**2*(DLOG(mst2/QSTSB)-1.5D0)
     C	   + msb1**2*(DLOG(msb1/QSTSB)-1.5D0)
     C	   + msb2**2*(DLOG(msb2/QSTSB)-1.5D0))
	 IF(V.NE.0.D0)THEN
	  PROB(28)=PROB(28)+DDIM(EPS,(V3-V)/DABS(V))
	 ELSE
	  PROB(28)=PROB(28)+DDIM(EPS,V3)
	 ENDIF
	ENDIF

	PROB(29)=DDIM(MAX(DABS(MH1),DABS(MH2))/Q2,10.D0)

	!PRINT*,"CALL CHECKMIN"
	!PRINT*,""
	!PRINT*,"V =",V
	!PRINT*,"V0 =",V0
	!PRINT*,"V1 =",V1
	!PRINT*,"V2 =",V2
	!PRINT*,"V3 =",V3
	!PRINT*,""
	!PRINT*,""

	END


