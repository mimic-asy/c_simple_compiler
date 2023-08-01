%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "header.hpp"

extern int yyerror( const char* ) ;
extern int yyparse( void ) ;
extern int yylex( void ) ;
extern char* yytext ;
extern FILE* yyin ;
%}

%union{
    struct Node* node;
}

%token <node> INT
%token SN
%token EQ NEQ LT LE GT GE
%token LPAR RPAR
%left ADD SUB
%left MUL DIV
%type <node> expr term factor

%%


program : stmt
        | program stmt
        ;
stmt    : expr SN
        | SN {exit(0);}
        ;
expr    :term
        | expr EQ expr {$$ = NEEQNode($1,"EQ",$3);}
        | expr NEQ expr {$$ = NEEQNode($1,"NEQ",$3);}
        | expr LT expr {$$ = compNode($1,"LT",$3);}
        | expr LE expr {$$ = compNode($1,"LE",$3);}
        | expr GT expr {$$ = compNode($1,"GT",$3);}
        | expr GE expr {$$ = compNode($1,"GE",$3);}
        | expr ADD term {$$ = calcNode($1,"ADD",$3);}
        | expr SUB term {$$ = calcNode($1,"SUB",$3);}
        ;
term    : factor
        | term MUL factor {$$ = calcNode($1,"MUL",$3);}
        | term DIV factor {$$ = calcNode($1,"DIV",$3);}
        ;
factor  : INT {$$ = makeNode($1);}
        | LPAR expr RPAR {$$ = $2;}
        ;

%%

int yyerror( char const* str )
{
	fprintf( stderr , "parser error near %s\n" , yytext ) ;
	return 0 ;
}

int main( void )
{
	yyin = stdin ;
	if ( yyparse() ) {
		fprintf( stderr , "Error !\n" ) ;
		exit( 1 ) ;
	}
}