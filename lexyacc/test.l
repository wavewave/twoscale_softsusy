%{
  #include "test.tab.h"
  #include <math.h>

  int yylex (void);
  void yyerror (char const *);


  extern double vbltable[26]; 
%}

%%
([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {
     yylval.dval = atof(yytext) ; return NUMBER; 
     }

[ \t]  ;     /* ignore white space */ ; 

[a-z] { yylval.vblno = yytext[0] - 'a' ; return NAME; }

"$" {return 0; /* end of input */}

\n   |
.    return yytext[0] ; 
%%


     /* Called by yyparse on error.  */
     void
     yyerror (char const *s)
     {
       fprintf (stderr, "%s\n", s);
     }
