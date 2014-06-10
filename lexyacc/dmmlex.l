%{
#include <stdio.h>
#include <string.h>
#include "action.h"
#include "dmmyacc.tab.h"


/*  YYSTYPE yylval;  */
extern YYSTYPE yylval;
%}
%%
[ \t]+                             /* ignore whitespaces */;
\n                                 { /* printf("ENTER "); */
                                     return ENTER;  
                                   }
(\+|-)?[0-9][0-9]*                 { /* printf("INTEGER "); */
                                     yylval.integer = atoi(yytext); 
                                     /* printf("%d \n", yylval.integer );  */
                                     return INTEGER; 
                                   }
(\+|-)?[0-9][0-9]*(\.[0-9]*)?      { /* printf("REAL");  */
                                     yylval.real = atof(yytext); 
                                     /* printf("%f \n", yylval.real );  */
                                     return REAL; 
                                   }

(\+|-)?[0-9]\.[0-9]*[eE](\+|-)?[0-9]+ { /* printf("REAL");  */
                                     yylval.real = atof(yytext); 
                                     /* printf("%f \n", yylval.real ); */
                                     return REAL;
                                   }

=                                  { /* printf("EQUAL "); */
                                     return EQUAL; 
                                   }

\[                                 { /* printf("OBRAC "); */
                                     return OBRAC ; 
                                   }

\]                                 { /* printf("CBRAC ");  */
                                     return CBRAC ; 
                                   }

\,                                 { /* printf("COMMA ");  */
                                     return COMMA; 
                                   }


#[^\n]*                            { /* printf("COMMENT "); */
                                     return COMMENT;
                                   }

method                             { /* printf("TKMETHOD ");  */
                                     return TKMETHOD; 
                                   }


single|scan|rgrun                  { /* printf("METHOD ");  */
                                     yylval.string = strdup(yytext); 
                                     return METHOD;
                                   }


scanmethod                         { /* printf("TKSCANMETHOD ") ; */ 
                                     return TKSCANMETHOD ;
                                   }

random|lattice                     { /* printf("SCANMETHOD ");  */ 
                                     yylval.string = strdup(yytext); 
                                     return SCANMETHOD; 
                                   }

shots                              { /* printf("TKSHOTS ") ; */ 
                                     return TKSHOTS ;
                                   }


option                             { /* printf("TKOPTION ") ; */
                                     return TKOPTION ;
                                   }

omega                              { /* printf("OPTION ") ; */
                                     yylval.string = strdup(yytext); 
                                     return OPTION; 
                                   }

on|off                             { /* printf("ONOFF ") ; */
                                     yylval.string = strdup(yytext); 
                                     return ONOFF ; 
                                   }

outputfile                         { /* printf("OUTFILE ");  */
                                     return TKOUTFILE; 
                                   }

\"[^\"]*\"                        { /* printf("QUOTED") ; */
                                     yylval.string = strdup(yytext); 
                                     return QUOTED;
                                   }

[a-zA-Z][a-zA-Z0-9]*               { /* printf("VAR ");  */
                                     yylval.string = strdup(yytext);
                                     /* printf("varname = %s\n",yylval.string); */
                                     return VAR; 
                                   }
%%

