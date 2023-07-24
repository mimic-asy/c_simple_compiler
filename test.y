%{
#include <stdio.h>

extern int yylex (void);
extern int yyerror (const char* str);
%}
%token N
%token NUMBER
%left ADD SUB
%left MUL DIV
%token LE GE LT GT EQ NE
%start list
%type expr comp

%%
list :/* empty */
    | list N
    | list expr N {printf("%d\n",$2); }
    ;
comp: expr LE expr { $$ = $1 <= $3; }
    | expr GE expr { $$ = $1 >= $3; }
    | expr LT expr  { $$ = $1 < $3; }
    | expr GT expr  { $$ = $1 > $3; }
    | expr EQ expr { $$ = $1 == $3; }
    | expr NE expr { $$ = $1 != $3; }
    ;
expr: NUMBER {$$ = $1;}
    | expr ADD expr { $$ = $1 + $3; }
    | expr SUB expr { $$ = $1 - $3; }
    | expr MUL expr { $$ = $1 * $3; }
    | expr DIV expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
    ;
%%

#include "lex.yy.c"

int yyerror (const char* str){
    fprintf(stderr, "parse error near %s\n", yytext);
    return 0;
}

int main() {
    yyparse();
    return 0;
}
