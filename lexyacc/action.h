#ifndef __ACTION__
#define __ACTION__

#define ISUCCESS  0 
#define IFAIL     -1

#define NUMVAR    40

#define C_ERROR   0 
#define C_M0      1
#define C_ALPHAM  2
#define C_ALPHAG  3
#define C_MMESS   4
#define C_TANB    5
#define C_SGNMU   6
#define C_N5      7
#define C_N10     8
#define C_N24     9 
#define C_NQ      10
#define C_NU      11
#define C_ND      12
#define C_NL      13
#define C_NE      14
#define C_NHU     15
#define C_NHD     16
#define C_NM      17
#define C_NH      18
#define C_M32     19

#define C_METHOD     30
#define C_SCANMETHOD 31
#define C_SHOTS      32

#define C_OMEGA 35

typedef struct _pairtype { 
  double first ; 
  double second ;
  double value; 
} pairtype ; 

typedef struct _tripletype { 
  double first; 
  double second; 
  double third; 
  double value ;
} tripletype ;


enum _valuetype {UndefinedType, IntegerType, RealType, StringType, PairType, TripleType, MethodType, ScanMethodType}; 
enum _bool {False=0, True};

enum _methodtype {SingleMethod, ScanMethod, RGRunMethod }; 

enum _scanmethodtype {RandomScan, LatticeScan };

typedef enum _valuetype valuetype; 
typedef enum _bool boolean; 
typedef enum _methodtype methodtype; 
typedef enum _scanmethodtype scanmethodtype; 

valuetype typevar[30]; 

typedef struct _value { 
  boolean isDefined; 
  union { 
    int integer; 
    double real; 
    char* string; 
    pairtype pair ; 
    tripletype triple ; 
    methodtype method ; 
    scanmethodtype scan; 
  } ;
} value; 


value valuelist[NUMVAR] ; 

char* stringlist[NUMVAR]; 

int pairlist[NUMVAR]; 

int triplelist[NUMVAR]; 


int numpair  ;
int numtriple ; 


int compareString(char* str) ; 

int assignint( char* str, int val ) ;

int assignreal( char* str, double val ) ; 

int assignpair( char* str, pairtype p); 

int assigntriple( char* str, tripletype t );

int method( char* str ); 

int scanmethod( char* str ); 

int shots( int val ); 

int option( char* str, char* val ) ;

int yaccmain( void ) ; 

void test( void ) ; 

#endif
