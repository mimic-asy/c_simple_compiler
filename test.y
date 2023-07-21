%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex(); // yylex()で字句解析を行う
//yyerror()は構文解析中にエラーが発生したときに呼ばれる
void yyerror(const char* s) {
    printf("Error: %s\n", s);//エラー内容を表示
}

%}

%union {
    char* name; //識別子
    int ival;//整数
    double fval;//浮動小数点数
    char* sval; //文字列
}

%token <ival> INT     //整数
%token <sval> ID    //識別子
%left <fval> EQ NE //等号、不等号
%left <fval> LT LE GT GE //大小比較
%left <fval> ADD SUB //加算、減算
%left <fval> MUL DIV MOD //乗算、除算、剰余
%token <fval> SEMI //セミコロン
%token <fval> LP RP //括弧
%token <sval> CR //改行

%type <fval> program //プログラム
%type <fval> expr //式
%type <fval> equality // ==.!=
%type <fval> relational // <, <=, >, >=
%type <fval> add // +, -
%type <fval> muldivmod // * , / , %
%type <fval> unary //正と負
%type <fval> primary //カッコ、数値、識別子

%%
program : expr CR { $$ = $1; } //プログラムの最後に改行がある場合
        | expr { $$ = $1; } //プログラムの最後に改行がない場合
        | CR { exit(0);}
        ;
expr : equality { $$ = $1; }
     ;
equality : relational { $$ = $1; }
         | relational EQ relational { $$ = $1 == $3; } //両方int型の場合、intで計算、型
         | relational NE relational { $$ = $1 != $3; }
         ;
relational : add { $$ = $1; }
           | add LT add { $$ = $1 < $3; }
           | add LE add { $$ = $1 <= $3; }
           | add GT add { $$ = $1 > $3; }
           | add GE add { $$ = $1 >= $3; }
           ;
add : muldivmod { $$ = $1; }
    | add ADD muldivmod { $$ = $1 + $3; }
    | add SUB muldivmod { $$ = $1 - $3; }
    ;
muldivmod :unary { $$ = $1;}
          | unary MUL unary { $$ = $1 * $3; }
          | unary DIV unary { $$ = $1 / $3; }
          | unary MOD unary { $$ = (int)$1 % (int)$3; }
unary :primary { $$ = $1; }
         | ADD primary { $$ = $2; }
         | SUB primary { $$ = -$2; }
         ;
primary : INT { $$ = $1; } //整数の場合はそのまま値を返す
     | ID { printf("Identifier: %s\n", $1); free($1); } //識別子の場合はそのまま値を返す
     | SEMI { $$ = 0; } //セミコロンの場合は0を返す
     | LP expr RP { $$ = $2; } //括弧の場合は括弧内の値を返す
     ;

%%

int main() {
    // 構文解析を開始
    yyparse();
    //解析結果を表示
    printf("Result: %i\n", yylval.ival);
    printf("Result: %f\n", yylval.fval);
    // 構文解析が終了したら終了
    return 0;
}
