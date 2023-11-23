%{
 #include <stdio.h>
 #include "y.tab.h"
%}

NUMBERS 0|([1-9][0-9]*)
%%
\n return '\n';

[ \t] ;

[A-Za-z]({NUMBERS}) { yylval.var.letter = yytext[0]; yylval.var.index = atoi(yytext+1); return X; }

(<=?)|(>=?)  { return GLT; }

[\+\-]  { yylval.cval = yytext[0]; return SIGN; }

{NUMBERS} { yylval.ival = atoi(yytext); return COEF; }

. ;


