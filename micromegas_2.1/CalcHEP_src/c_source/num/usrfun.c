/*
 Copyright (C) 1997, Alexander Pukhov 
*/

#include<stdlib.h>
#include<stdio.h>
#include"syst.h"
#include"interface.h"
#include"usrfun.h"
extern double pvect[400];


double usrfun(char * name)
{
   fprintf(stdout," User function U%s not defined\n",name);
   sortie(54);
   return 0.;
} 
