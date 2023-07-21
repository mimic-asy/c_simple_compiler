%option noyywrap
%{
#include "test.tab.h" // Bison から生成されるヘッダーファイルをインクルード
%}
%%
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
";" {return SEMI;}
"(" {return LP;}
")" {return RP;}
"<" {return LT;}
"<=" {return LE;}
">" {return GT;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
" "  {}
"\n" {return CR ;}
0|[1-9][0-9]*                                               { yylval.ival = atoi(yytext); return INT; } //整数型のトークン
((0|[1-9][0-9]*)"."[0-9]*|"."[0-9]+)(e("+"|"-"|"")[0-9]+)?  { yylval.fval = atof(yytext); return FLOAT; }//浮動小数点型のトークン
[a-zA-Z_][a-zA-Z0-9_]*                                      { yylval.sval= strdup(yytext); return ID; } //識別子のトークン,strdupは文字列をコピーする関数
%%
