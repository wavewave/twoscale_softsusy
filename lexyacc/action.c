#include <stdio.h>
#include <math.h>

#include "action.h"


double m32func( double alpha, double M0, double m32) ;
double find_out_m32_in_mirage( double alpha, double M0, double eps ) ;


char* printmethod( methodtype m ) 
{
  if( m == SingleMethod ) 
    return "single"; 
  else if( m == ScanMethod ) 
    return "scan" ;
  else if( m == RGRunMethod ) 
    return "rgrun"; 
  else
    return "something wrong"; 
}

char* printscan( scanmethodtype m ) 
{
  if( m == RandomScan ) 
    return "random"; 
  else if( m == LatticeScan ) 
    return "lattice" ;
  else
    return "something wrong"; 
}



int insert_int( int code, int val  ) 
{
  if( valuelist[code].isDefined == True ) {
    printf("%s is already defined!", stringlist[code] ); 
    return -1; 
  }
  
  valuelist[code].isDefined = True; 
  valuelist[code].integer = val;

  return 0 ;
}

int insert_real( int code, double val ) 
{
  if( valuelist[code].isDefined == True ) {
    printf("%s is already defined!", stringlist[code] ); 
    return -1; 
  }
  
  valuelist[code].isDefined = True; 
  valuelist[code].real = val;

  return 0 ;
}

int insert_pair( int code, pairtype val ) 
{
  if( valuelist[code].isDefined == True ) {
    printf("%s is already defined!", stringlist[code] ); 
    return -1; 
  }


  printf("val.first = %f\n", val.first ); 
  
  valuelist[code].isDefined   = True; 
  valuelist[code].pair.first  = val.first;
  valuelist[code].pair.second = val.second;

  return 0 ; 
}

int insert_triple( int code, tripletype val ) 
{
  if( valuelist[code].isDefined == True ) {
    printf("%s is already defined!", stringlist[code] ); 
    return -1; 
  }
  
  valuelist[code].isDefined   = True; 
  valuelist[code].triple.first  = val.first;
  valuelist[code].triple.second = val.second;
  valuelist[code].triple.third  = val.third;
  
  return 0; 

}

int insert_method( int code, methodtype val ) 
{
  if( valuelist[code].isDefined == True ) {
    printf("%s is already defined!", stringlist[code] ); 
    return IFAIL; 
  }
  
  valuelist[code].isDefined   = True; 
  valuelist[code].method = val;

  return ISUCCESS; 

}


int insert_scan( int code, scanmethodtype val ) 
{
  if( valuelist[code].isDefined == True ) {
    printf("%s is already defined!", stringlist[code] ); 
    return IFAIL; 
  }
  
  valuelist[code].isDefined   = True; 
  valuelist[code].scan = val;

  return ISUCCESS; 

}





int compareString(char* str) 
{
  if( !strcmp(str, "M0") ) 
    return C_M0;
  if( !strcmp(str, "alpham") )
    return C_ALPHAM; 
  if( !strcmp(str, "M32" ) ) 
    return C_M32; 
  if( !strcmp(str, "alphag") ) 
    return C_ALPHAG; 
  if( !strcmp(str, "Mmess") ) 
    return C_MMESS; 
  if( !strcmp(str, "tanb") ) 
    return C_TANB; 
  if( !strcmp(str, "sgnMu") ) 
    return C_SGNMU; 
  if( !strcmp(str, "N5") ) 
    return C_N5; 
  if( !strcmp(str, "N10") ) 
    return C_N10; 
  if( !strcmp(str, "N24") ) 
    return C_N24; 
  if( !strcmp(str, "nQ") ) 
    return C_NQ;
  if( !strcmp(str, "nU") ) 
    return C_NU; 
  if( !strcmp(str, "nD") ) 
    return C_ND; 
  if( !strcmp(str, "nL") ) 
    return C_NL; 
  if( !strcmp(str, "nE") ) 
    return C_NE; 
  if( !strcmp(str, "nHu") ) 
    return C_NHU; 
  if( !strcmp(str, "nHd") ) 
    return C_NHD; 
  if( !strcmp(str, "nM") ) 
    return C_NM; 
  if( !strcmp(str, "nH") ) 
    return C_NH; 
  if( !strcmp(str, "m32") ) 
    return C_M32; 

  return C_ERROR;  
}

int assignint( char* str, int val ) 
{
  int code = compareString(str);

  if( typevar[code] != IntegerType ) {
    printf("mismatched type for %s!\n",str); 
    return -1 ; 
  }

  if( code == C_SGNMU ) { 
    if( val != +1 && val != -1 ) {
      printf("sgnMu must be either +1 or -1!\n"); 
      return -1; 
    }
    else {
      if( insert_int( code, val ) ) return -1; 
    }
  }
  else {
    if( insert_int( code, val ) ) return -1; 
  }
  return 0;
  
}


int assignreal( char* str, double val ) 
{
  int code = compareString(str);
  if( code == C_ERROR ) {
    printf("unknown variable %s!", str );
  }



  if( typevar[code] != RealType ) {
    printf("mismatched type for %s!\n",str); 
    return -1 ; 
  }

  if( code == C_NM ) { 
    if( insert_real( C_NQ, val )) return -1; 
    if( insert_real( C_NU, val )) return -1; 
    if( insert_real( C_ND, val )) return -1; 
    if( insert_real( C_NL, val )) return -1; 
    if( insert_real( C_NE, val )) return -1; 
  }
  else if( code == C_NH ) { 
    if( insert_real( C_NHU, val )) return -1;
    if( insert_real( C_NHD, val )) return -1; 
  }
  else {
    if( insert_real( code, val ) ) return -1; 
  }

  return 0;
  
}

int assignpair( char* str, pairtype val) {
  int code = compareString(str);
  if( code == C_ERROR ) {
    printf("unknown variable %s!", str );
  }

  if( typevar[code] != RealType ) {
    printf("mismatched type for %s!\n",str); 
    return -1 ; 
  }
  
  typevar[code] = PairType; 

  if( insert_pair( code, val ) ) return -1; 

  pairlist[numpair] = code; 
  numpair++; 

  return 0; 
  
}


int assigntriple( char* str, tripletype val ) {
  int code = compareString(str);
  if( code == C_ERROR ) {
    printf("unknown variable %s!", str );
  }

  if( typevar[code] != RealType ) {
    printf("mismatched type for %s!\n",str); 
    return -1 ; 
  }
  
  typevar[code] = TripleType; 

  if( insert_triple( code, val ) ) return -1; 

  triplelist[numtriple] = code; 
  numtriple++;

  return 0 ; 
}



void initialize( void ) 
{
  int i = 0; 

  numpair = 0 ;
  numtriple = 0; 

  typevar[C_ERROR]  = UndefinedType; 
  typevar[C_M0]     = RealType; 
  typevar[C_ALPHAM] = RealType; 
  typevar[C_ALPHAG] = RealType; 
  typevar[C_MMESS]  = RealType; 
  typevar[C_TANB]   = RealType; 
  typevar[C_SGNMU]  = IntegerType; 
  typevar[C_N5]     = IntegerType; 
  typevar[C_N10]    = IntegerType; 
  typevar[C_N24]    = IntegerType; 
  typevar[C_NQ]     = RealType; 
  typevar[C_NU]     = RealType; 
  typevar[C_ND]     = RealType; 
  typevar[C_NL]     = RealType; 
  typevar[C_NE]     = RealType; 
  typevar[C_NHU]    = RealType; 
  typevar[C_NHD]    = RealType;
  typevar[C_NM]     = RealType; 
  typevar[C_NH]     = RealType; 
  typevar[C_M32]    = RealType; 
  typevar[C_METHOD] = MethodType;
  typevar[C_SCANMETHOD] = ScanMethodType; 

  stringlist[C_ERROR]  = "error" ;
  stringlist[C_M0]     = "M0"    ; 
  stringlist[C_ALPHAM] = "alpham"; 
  stringlist[C_ALPHAG] = "alphag"; 
  stringlist[C_MMESS]  = "Mmess" ; 
  stringlist[C_TANB]   = "tanb"  ; 
  stringlist[C_SGNMU]  = "sgnMu" ;
  stringlist[C_N5]     = "N5"    ; 
  stringlist[C_N10]    = "N10"   ; 
  stringlist[C_N24]    = "N24"   ; 
  stringlist[C_NQ]     = "nQ"    ; 
  stringlist[C_NU]     = "nU"    ;
  stringlist[C_ND]     = "nD"    ; 
  stringlist[C_NL]     = "nL"    ; 
  stringlist[C_NE]     = "nE"    ; 
  stringlist[C_NHU]    = "nHu"   ; 
  stringlist[C_NHD]    = "nHd"   ; 
  stringlist[C_NM]     = "nM"    ; 
  stringlist[C_NH]     = "nH"    ; 
  stringlist[C_M32]    = "m32"   ; 

  stringlist[C_METHOD] = "method" ; 
  stringlist[C_SCANMETHOD] = "scanmethod" ; 
  stringlist[C_SHOTS] = "shots"; 

  stringlist[C_OMEGA] = "omega" ; 
  
  for( i = 0 ; i < NUMVAR ; i++ ) { 
    valuelist[i].isDefined = False; 
    pairlist[i] = 0; 
    triplelist[i] = 0;
  }

}

void printout( void ) 
{
  int i ;

  printf("\n"); 
  for( i = 0; i < NUMVAR ; i++ ) { 
    if( valuelist[i].isDefined ) { 
      if( typevar[i] == RealType )
	printf("%s : %f \n", stringlist[i], valuelist[i].real ); 
      else if( typevar[i] == IntegerType ) 
	printf("%s : %d \n", stringlist[i], valuelist[i].integer ); 
      else if( typevar[i] == PairType ) 
	printf("%s : (%f, %f) \n", stringlist[i], valuelist[i].pair.first, valuelist[i].pair.second ); 
      else if( typevar[i] == TripleType ) 
	printf("%s : (%f, %f, %f) \n", 
	       stringlist[i], 
	       valuelist[i].triple.first, 
	       valuelist[i].triple.second, 
	       valuelist[i].triple.third); 
    } 
    
  }
 
  printf("\n num of pairs   : %d \n", numpair ); 
  for( i = 0 ; i < numpair ; i++ ) { 
    printf("%s ", stringlist[pairlist[i]]); 
  }

  printf("\n num of triples : %d \n", numtriple ); 
  for( i = 0 ; i < numtriple ; i++ ) { 
    printf("%s ", stringlist[triplelist[i]]); 
  }
  printf("\n"); 


  printf(" method = %s \n", printmethod( valuelist[C_METHOD].method ) ); 

  if( valuelist[C_SCANMETHOD].isDefined ) 
    printf(" scanmethod = %s \n", printscan( valuelist[C_SCANMETHOD].scan ) ); 
  
  if( valuelist[C_SHOTS].isDefined ) 
    printf(" shots = %d \n", valuelist[C_SHOTS].integer ); 
  




}

int checkundefined( void ) 
{
  int checkm0m32alpham = 0; 

  if( valuelist[C_ALPHAG].isDefined == False ) return -1;
  if( valuelist[C_MMESS].isDefined == False ) return -1;
  if( valuelist[C_TANB].isDefined == False ) return -1;
  if( valuelist[C_SGNMU].isDefined == False ) return -1;
  if( valuelist[C_N5].isDefined == False ) return -1;
  if( valuelist[C_N10].isDefined == False ) return -1;
  if( valuelist[C_N24].isDefined == False ) return -1;
  if( valuelist[C_NQ].isDefined == False ) return -1;
  if( valuelist[C_NU].isDefined == False ) return -1;
  if( valuelist[C_ND].isDefined == False ) return -1;
  if( valuelist[C_NL].isDefined == False ) return -1;
  if( valuelist[C_NE].isDefined == False ) return -1;
  if( valuelist[C_NHU].isDefined == False ) return -1;
  if( valuelist[C_NHD].isDefined == False ) return -1;
  /*  if( valuelist[C_NM].isDefined == False ) return -1;
      if( valuelist[C_NH].isDefined == False ) return -1; */

  if( valuelist[C_METHOD].isDefined == False )
    return IFAIL; 

  if( valuelist[C_METHOD].method == SingleMethod || 
      valuelist[C_METHOD].method == RGRunMethod ) {
    if( numpair )   {
      printf(" nonzero numpair for single \n"); 
      return IFAIL;
    }
    if( numtriple ) {
      printf(" nonzero numtriple for single \n"); 
      return IFAIL; 
    }
  }
  else if( valuelist[C_METHOD].method == ScanMethod ){
    if(valuelist[C_SCANMETHOD].scan == RandomScan)
      {
	if( numtriple ) return IFAIL;
	if( ! numpair ) return IFAIL;
      }
    else if(valuelist[C_SCANMETHOD].scan == LatticeScan)
      {
	if( ! numtriple ) return IFAIL;
	if( numpair ) return IFAIL;
      }
  }

  
  /* Check only two of  M0, M32, ALPHAM are defined */

  if( valuelist[C_M0].isDefined == True && 
      valuelist[C_ALPHAM].isDefined == True &&
      valuelist[C_M32].isDefined == False ) 
    checkm0m32alpham = 0 ; 
  else if( valuelist[C_M32].isDefined == True && 
      valuelist[C_ALPHAM].isDefined == True &&
      valuelist[C_M0].isDefined == False ) 
    checkm0m32alpham = 0 ; 
  else if( valuelist[C_M0].isDefined == True && 
      valuelist[C_M32].isDefined == True &&
      valuelist[C_ALPHAM].isDefined == False )
    checkm0m32alpham = 0 ; 
  else 
    checkm0m32alpham = -1 ;


  if( checkm0m32alpham ) 
    return IFAIL; 
  else
    return ISUCCESS;





  return -1; 
}



double m32func( double alpha, double M0, double m32) 
{
  const double MPLANCK = 2.4e18; 
  return alpha * M0 * log( MPLANCK / m32 ) ;  

}

double find_out_m32_in_mirage( double alpha, double M0, double eps ) 
{
  double x = 30000 ; 
  double xnew ; 
  
  xnew = x ; 

  do {  
    x = xnew; 
    xnew = m32func( alpha, M0, x )  ; 

  } while(abs(xnew-x) > x*eps ) ; 

  return x; 
}


int method( char* str )  
{
  if( !strcmp(str , "single" ) ) {
    return insert_method( C_METHOD, SingleMethod ) ; 
  }
  else if( !strcmp(str, "scan" ) ) { 
    return insert_method( C_METHOD, ScanMethod ) ;
  }
  else if( !strcmp(str, "rgrun" ) ) { 
    return insert_method( C_METHOD, RGRunMethod ); 
  }
  else
    return IFAIL; 

}

int scanmethod( char* str )
{
  if( valuelist[C_METHOD].method != ScanMethod ) {
    printf("In scanmethod: The Method is not scan. \n"); 
    return IFAIL; 
  }

  if( !strcmp(str , "random" ) ) {
    return insert_scan( C_SCANMETHOD, RandomScan ); 
  }
  else if( !strcmp(str, "lattice" ) ) { 
    return insert_scan( C_SCANMETHOD, LatticeScan ); 
  }
  else 
    return IFAIL; 
}

int shots( int val )
{
  if( valuelist[C_METHOD].method != ScanMethod ) {
    printf("In shots: The Method is not scan. \n"); 
    return IFAIL; 
  }

  if( valuelist[C_SCANMETHOD].scan != RandomScan ) {
    printf("In shots: The scan method is not random. \n"); 
    return IFAIL; 
  }

  if( val > 0 ) { 
    return insert_int( C_SHOTS, val ) ;
  }
  else {
    return IFAIL; 
  }

}

int option( char* str, char* val ) 
{
  if( !strcmp( str, "omega" ) ) { 
    if( !strcmp( val, "on" ) ) {
      valuelist[C_OMEGA].integer = 1; 
    }
    else { 
      valuelist[C_OMEGA].integer = 0; 
    }
	
    return ISUCCESS; 
  
  }  
  else
    return IFAIL ;
}     


void test( void ) 
{
  printf("\n this is a test!!!!!\n"); 
}
