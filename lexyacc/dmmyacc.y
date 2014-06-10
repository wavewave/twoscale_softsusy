%{
#include <stdio.h>
#include <string.h>
#include "action.h"

  int yydebug = 1; 
  
  void yyerror(const char *str) {
    fprintf(stderr,"error: %s\n",str); 
  }

  int yywrap() 
  {
    return 1;  
  }



  int yaccmain( void ) {
    initialize(); 

    yyparse(); 

    printout(); 
    
    if( checkundefined() ) {
      return IFAIL; 
      printf("\n There are undefined variables. \n"); 
    }

    return ISUCCESS; 
  }



%}

%union
{
  int        integer; 
  double     real ;
  char      *string; 
  pairtype   pair;
  tripletype triple; 
}
 
%token ENTER EQUAL COMMENT TKMETHOD TKOUTFILE OBRAC CBRAC COMMA TKSCANMETHOD TKSHOTS TKOPTION

%token <real>    REAL
%token <integer> INTEGER
%token <string>  VAR
%token <string>  METHOD
%token <string>  SCANMETHOD
%token <string>  QUOTED
%token <string>  OPTION
%token <string>  ONOFF

%type  <pair>    pair
%type  <triple>  triple

%%
statements: /* empty */
     | statements statement
     ; 

statement:
     comment ENTER 
     |
     assignment comment ENTER
     |
     methodstatement comment ENTER
     | 
     scanmethodstatement comment ENTER
     | 
     shotsstatement comment ENTER
     |
     optionstatement comment ENTER
     /*     | 
	    filestatement comment ENTER */
     ; 


comment: /* empty */
     | COMMENT
     ; 
assignment:
     VAR EQUAL INTEGER { 
       assignint( $1, $3 ) ; 
                       }
     |
     VAR EQUAL REAL    {
       assignreal( $1, $3 ); 
     }
     | 
     VAR EQUAL pair    {
       assignpair( $1, $3 ); 
     }
     |
     VAR EQUAL triple  {
       assigntriple( $1, $3 ); 
     }

pair: 
     OBRAC REAL COMMA REAL CBRAC { 
       $$.first  = $2 ; 
       $$.second = $4 ; 
     }

triple:
     OBRAC REAL COMMA REAL COMMA REAL CBRAC {
       $$.first  = $2; 
       $$.second = $4; 
       $$.third  = $6; 
     } 

methodstatement: 
     TKMETHOD METHOD { 
       method( $2 );  
     }

scanmethodstatement:
     TKSCANMETHOD SCANMETHOD {
       scanmethod( $2 ); 
     }

shotsstatement:
     TKSHOTS INTEGER {
       shots( $2 ); 
     }

optionstatement: 
     TKOPTION OPTION ONOFF {
       option( $2, $3 ) ;
     }

%%
