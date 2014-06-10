#ifndef YYERRCODE
#define YYERRCODE 256
#endif

#define NAME 257
#define NUMBER 258
#define UMINUS 259
typedef union {
  double dval; 
  int vblno; 
} YYSTYPE;
extern YYSTYPE yylval;
