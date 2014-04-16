      SUBROUTINE HiggsEDM(NFLAG,IFLAG
     .      ,HMASS,STMASS,SBMASS,MC,OMIX,NCMAX,NHC)
************************************************************************
*
* Calculate two-loop EDMs based on NPB644(2002)263 by A. Pilaftsis
*
* Output DE = de = de  +   de    + de  +   de   + de
*                 Stop   Sbottom   Top   Bottom   Chargino
*        CS
*
* Note : (1) CS in units of 1/GeV^2
*        (2) DE is for the electron EDM in units of 10^-26 ecm
*        (3) The Thallium EDM in units of 10^-24 ecm can be obtained by
*              d[Tl]   = -5.85D0*[DE/10^-26] - 8.5D11*CS
*              DTL     =  DTL_DE             + DTL_CS
*            following Pospelov and Ritz sign convention for CS
*        (4) The muon EDM in units of 10^-24 ecm can be obtained by
*              d[muon] =  2.05D0*[DE/10^-26]
*
*
* Thallium EDM in 10^-24[ecm]:
*  d[Tl]      = -5.85D0*[DE/10^-26] - 8.5D11*[CS GeV^2]
*  RAUX_H(111)= RAUX_H(112)         + RAUX_H(113)
*
* Electron EDM in 10^-26[ecm]:
*  d[e] = DE  =de[Stop]   +de[Sbottom]+de[Top]    +de[Bottom] +de[Chargino]
*  RAUX_H(114)=RAUX_H(115)+RAUX_H(116)+RAUX_H(117)+RAUX_H(118)+RAUX_H(119)
*
* Muon EDM in 10^-24[ecm]:
*  d[mu] = 2.05D0*[DE/10^-26]
*  RAUX_H(120)
*
*
************************************************************************
      IMPLICIT REAL*8(A-H,M,O-Z)
*-----------------------------------------------------------------------
*+CDE HC_ COMMON BLOCKS:
      COMMON /HC_SMPARA/ AEM_H,ASMZ_H,MZ_H,SW_H,ME_H,MMU_H,MTAU_H,MDMT_H
     .                  ,MSMT_H,MBMT_H,MUMT_H,MCMT_H,MTPOLE_H,GAMW_H
     .                  ,GAMZ_H,EEM_H,ASMT_H,CW_H,TW_H,MW_H,GW_H,GP_H
     .                  ,V_H,GF_H,MTMT_H
*
      COMMON /HC_RSUSYPARA/ TB_H,CB_H,SB_H,MQ3_H,MU3_H,MD3_H,ML3_H,ME3_H
*
      COMPLEX*16 MU_H,M1_H,M2_H,M3_H,AT_H,AB_H,ATAU_H
      COMMON /HC_CSUSYPARA/ MU_H,M1_H,M2_H,M3_H,AT_H,AB_H,ATAU_H
*
*NEW COMMON BLOCKS for V2
*
      REAL*8     RAUX_H(999)
      COMPLEX*16 CAUX_H(999)
      COMMON /HC_RAUX/ RAUX_H
      COMMON /HC_CAUX/ CAUX_H
      DATA NAUX/999/
*-----------------------------------------------------------------------
*Input arrays
      INTEGER*8 IFLAG(NFLAG)
      COMPLEX*16 NHC(NCMAX,3)
      REAL*8 HMASS(3),STMASS(2),SBMASS(2),MC(2)
      REAL*8 OMIX(3,3)
*-----------------------------------------------------------------------
*Local arrays
      REAL*8 XIQ(2,3),ZTQ(2,3)  ! [(1=Top,2=Bottom),Higgs_I]
*     de/(e*me)[(1=stop,2=sbot,3=top,4=bot,5=chargino1,6=chargino2),Higgs_I]
      REAL*8 DE_FI(6,3),GHGG(3)
      COMPLEX*16 XT,XB
*-----------------------------------------------------------------------
* For integration
      COMMON /HiggsEDM_BODE/ Z_HiggsEDM
      EXTERNAL F0_HiggsEDM,F_HiggsEDM,G_HiggsEDM
*
      ME=ME_H
      SW=SW_H
      MW=MW_H
      V =V_H
      TB=TB_H
      CB=CB_H
      SB=SB_H
      MB=MBMT_H
      MT=MTMT_H
*
      PI=2.D0*DASIN(1.D0)
      AEM=1.D0/137.D0
*-----------------------------------------------------------------------
      NX_EDM  = 1000   ! Number of calling SUBROUTINE BODE
      EPS_EDM = 1.D-6  ! integration region of 2 loop functions:
*                        [EPS_EDM ; (1-EPS_EDM)]
      NX  = NX_EDM
      EPS = EPS_EDM
*
      X1D=EPS
      X1U=1.D0-EPS
*
      DO IH=1,3
      MH=HMASS(IH)
*stop
      NF=1
      QQ=2.D0/3.D0
      Z_HiggsEDM=STMASS(1)**2/MH**2
      CALL BODE(F0_HiggsEDM,X1D,X1U,NX,FST1)
      Z_HiggsEDM=STMASS(2)**2/MH**2
      CALL BODE(F0_HiggsEDM,X1D,X1U,NX,FST2)
      DE_FI(NF,IH)=3.D0*AEM*QQ**2*ME/32.D0/PI**3*DREAL(NHC(3,IH))/MH**2
     .            *DREAL(NHC(71,IH)*FST1+NHC(74,IH)*FST2)
*sbottom
      NF=2
      QF=-1.D0/3.D0
      Z_HiggsEDM=SBMASS(1)**2/MH**2
      CALL BODE(F0_HiggsEDM,X1D,X1U,NX,FSB1)
      Z_HiggsEDM=SBMASS(2)**2/MH**2
      CALL BODE(F0_HiggsEDM,X1D,X1U,NX,FSB2)
      DE_FI(NF,IH)=3.D0*AEM*QQ**2*ME/32.D0/PI**3*DREAL(NHC(3,IH))/MH**2
     .            *DREAL(NHC(75,IH)*FSB1+NHC(78,IH)*FSB2)
*top
      NF=3
      QQ=2.D0/3.D0
      Z_HiggsEDM=MT**2/MH**2
      CALL BODE(F_HiggsEDM,X1D,X1U,NX,FTOP)
      CALL BODE(G_HiggsEDM,X1D,X1U,NX,GTOP)
      DE_FI(NF,IH)=-3.D0*AEM**2*QQ**2*ME/8.D0/PI**2/SW**2/MW**2
     . *(DREAL(NHC(3,IH))*DREAL(NHC(26,IH))*FTOP
     .  +DREAL(NHC(2,IH))*DREAL(NHC(27,IH))*GTOP)
*bottom
      NF=4
      QQ=-1.D0/3.D0
      Z_HiggsEDM=MB**2/MH**2
      CALL BODE(F_HiggsEDM,X1D,X1U,NX,FBOT)
      CALL BODE(G_HiggsEDM,X1D,X1U,NX,GBOT)
      DE_FI(NF,IH)=-3.D0*AEM**2*QQ**2*ME/8.D0/PI**2/SW**2/MW**2
     . *(DREAL(NHC(3,IH))*DREAL(NHC(17,IH))*FBOT
     .  +DREAL(NHC(2,IH))*DREAL(NHC(18,IH))*GBOT)
*chargino-1
      NF=5
      Z_HiggsEDM=MC(1)**2/MH**2
      CALL BODE(F_HiggsEDM,X1D,X1U,NX,FC1)
      CALL BODE(G_HiggsEDM,X1D,X1U,NX,GC1)
      DE_FI(NF,IH)=-AEM**2*ME/4.D0/DSQRT(2.D0)/PI**2/SW**2/MW/MC(1)
     . *(DREAL(NHC(3,IH))*DREAL(NHC(59,IH))*FC1
     .  +DREAL(NHC(2,IH))*DREAL(NHC(60,IH))*GC1)
*chargino-2
      NF=6
      Z_HiggsEDM=MC(2)**2/MH**2
      CALL BODE(F_HiggsEDM,X1D,X1U,NX,FC2)
      CALL BODE(G_HiggsEDM,X1D,X1U,NX,GC2)
      DE_FI(NF,IH)=-AEM**2*ME/4.D0/DSQRT(2.D0)/PI**2/SW**2/MW/MC(2)
     . *(DREAL(NHC(3,IH))*DREAL(NHC(68,IH))*FC2
     .  +DREAL(NHC(2,IH))*DREAL(NHC(69,IH))*GC2)
*HI-g-g
      GHGG(IH)= 2.D0/3.D0*DREAL(NHC(26,IH)+NHC(17,IH))
     .        -V**2/12.D0*DREAL(NHC(71,IH)/STMASS(1)**2
     .                         +NHC(74,IH)/STMASS(2)**2
     .                         +NHC(75,IH)/SBMASS(1)**2
     .                         +NHC(78,IH)/SBMASS(2)**2)
*      
      ENDDO ! IH
*
      GEVTOCM=1.97326968D-14
      DE_STOP=(DE_FI(1,1)+DE_FI(1,2)+DE_FI(1,3))*GEVTOCM*1.D26
      DE_SBOT=(DE_FI(2,1)+DE_FI(2,2)+DE_FI(2,3))*GEVTOCM*1.D26
      DE_TOP =(DE_FI(3,1)+DE_FI(3,2)+DE_FI(3,3))*GEVTOCM*1.D26
      DE_BOT =(DE_FI(4,1)+DE_FI(4,2)+DE_FI(4,3))*GEVTOCM*1.D26
      DE_CHA =(DE_FI(5,1)+DE_FI(5,2)+DE_FI(5,3)
     .        +DE_FI(6,1)+DE_FI(6,2)+DE_FI(6,3))*GEVTOCM*1.D26
      DE=DE_STOP+DE_SBOT+DE_TOP+DE_BOT+DE_CHA
      CS=-0.1D0*TB*ME*PI*AEM/SW**2/MW**2
     .  *(GHGG(1)*OMIX(3,1)/HMASS(1)**2
     .   +GHGG(2)*OMIX(3,2)/HMASS(2)**2
     .   +GHGG(3)*OMIX(3,3)/HMASS(3)**2)
*
*Thallium EDM in 10^-24 [ecm] following Pospelov and Ritz sign for CS
      DTL_STOP= -5.85D0*DE_STOP
      DTL_SBOT= -5.85D0*DE_SBOT
      DTL_TOP = -5.85D0*DE_TOP
      DTL_BOT = -5.85D0*DE_BOT
      DTL_CHA = -5.85D0*DE_CHA
      DTL_DE  = -5.85D0*DE
      DTL_CS  = -8.5D11*CS
      DTL     = DTL_DE+DTL_CS
*Muon EDM in 10^-24 [ecm]
      DMUON   = 2.05D0*DE
*
*
*Fill some COMMON BLOCK /HC_RAUX/ RAUX_H
*Thallium EDM in 10^-24 [ecm]
      RAUX_H(111)=DTL
      RAUX_H(112)=DTL_DE
      RAUX_H(113)=DTL_CS
*Electron EDM in 10^-24 [ecm]
      RAUX_H(114)=DE
      RAUX_H(115)=DE_STOP
      RAUX_H(116)=DE_SBOT
      RAUX_H(117)=DE_TOP
      RAUX_H(118)=DE_BOT
      RAUX_H(119)=DE_CHA
*Muon EDM in 10^-24 [ecm]
      RAUX_H(120)=DMUON

*-----------------------------------------------------------------------
      IF(IFLAG(15).EQ.1) THEN
      print*,'---------------------------------------------------------'
      print*,'              Higgs-mediated two-loop EDMs'
      WRITE(*,10) ADEG(M3_H),ADEG(AT_H)
      print*,'---------------------------------------------------------'
      WRITE(*,11) RAUX_H(111)
      WRITE(*,12) RAUX_H(112)
      WRITE(*,13) RAUX_H(113)
      WRITE(*,14) RAUX_H(114)
      WRITE(*,15) RAUX_H(120)
      print*,'---------------------------------------------------------'
      print*,' '

      write(21,fmt='("EDMth",2x,1PE16.8)') RAUX_H(111)*1.E-24
      write(21,fmt='("EDMel",2x,1PE16.8)') RAUX_H(114)*1.E-26
      write(21,fmt='("EDMmu",2x,1PE16.8)') RAUX_H(120)*1.E-24

      ENDIF
*
*-----------------------------------------------------------------------
 10   FORMAT(1X,6x,'Phi_3 = ',E10.4
     .         ,'^o and Phi_At = ',E10.4,'^o')
 11   FORMAT(2X,'Thallium[10^-24 ecm]: ',E10.4)
 12   FORMAT(2X,21x,'[',E10.4,' from electron EDM]')
 13   FORMAT(2X,21x,'[',E10.4,' from C_S      EDM]')
 14   FORMAT(2X,'Electron[10^-26 ecm]: ',E10.4)
 15   FORMAT(2X,'Muon[10^-24 ecm]    : ',E10.4)
*
      RETURN
      END

      REAL*8 FUNCTION F0_HiggsEDM(X1)
************************************************************************
*
*  F(z)=x*(1-x)/[z-x*(1-x)]*ln[x*(1-x)/z]
*
************************************************************************
      IMPLICIT REAL*8(A-H,M,O-Z)
      COMMON /HiggsEDM_BODE/ Z_HiggsEDM
*
      Z=Z_HiggsEDM
      X=X1
*
      IF(X.EQ.0.D0 .OR. X.EQ.1.D0) THEN
       F0_HiggsEDM=0.D0
      ELSE 
       F0_HiggsEDM=X*(1.D0-X)/(Z-X*(1.D0-X))*DLOG(X*(1.D0-X)/Z)
      ENDIF
*
      RETURN
      END

      REAL*8 FUNCTION F_HiggsEDM(X1)
************************************************************************
*
*  f(z)=z/2*[1-2*x*(1-x)]/[x*(1-x)-z]*ln[x*(1-x)/z]
*
************************************************************************
      IMPLICIT REAL*8(A-H,M,O-Z)
      COMMON /HiggsEDM_BODE/ Z_HiggsEDM
*
      Z=Z_HiggsEDM
      X=X1
*
      F_HiggsEDM=Z/2.D0*(1.D0-2.D0*X*(1.D0-X))/(X*(1.D0-X)-Z)
     .       *DLOG(X*(1.D0-X)/Z)
*
      RETURN
      END

      REAL*8 FUNCTION G_HiggsEDM(X1)
************************************************************************
*
*  g(z)=z/2*1/[x*(1-x)-z]*ln[x*(1-x)/z]
*
************************************************************************
      IMPLICIT REAL*8(A-H,M,O-Z)
      COMMON /HiggsEDM_BODE/ Z_HiggsEDM
*
      Z=Z_HiggsEDM
      X=X1
*
      G_HiggsEDM=Z/2.D0/(X*(1.D0-X)-Z)*DLOG(X*(1.D0-X)/Z)
*
      RETURN
      END
