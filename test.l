WS   " "
N   "\n"
ADD  "+"
SUB  "-"
MUL  "*"
DIV  "/"
RAP [()]
NUMBER [1-9][[:digit:]]*|0
EQ  "=="
LT   "<"
GT   ">"
LE  "<="
GE  ">="
NE  "!="

%%
{ADD} {return ADD;}
{NUMBER} {yylval = atoi(yytext); return(NUMBER);}
{SUB} {return SUB;}
{MUL} {return MUL;}
{DIV} {return DIV;}
{EQ}  {return EQ;}
{LE}  {return LE;}
{GE}  {return GE;}
{LT}  {return LT;}
{GT}  {return GT;}
{NE}  {return NE;}
{WS}
{N} {return N;}
.
%%