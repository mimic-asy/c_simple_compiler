
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.hpp"
#include "test.tab.h"


extern "C" int yywrap( void ){ return 1 ; }
%}

%%
" "
"\n"  return SN ;
"+"   return ADD;
"-"   return SUB;
"*"   return MUL;
"/"   return DIV;
"("   return LPAR;
")"   return RPAR;
"=="  return EQ;
"!="  return NEQ;
"<"   return LT;
"<="  return LE;
">"   return GT;
">="  return GE;

[0-9]+  {   yylval.node = new Node;
            yylval.node->value = atoi(yytext); return INT; }
