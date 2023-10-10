%{
#include <stdio.h>
int yyerror(char*);
int yylex();
%}

%start input
%token ONE ZERO

%%
input:
    input line
    | /* epsilon */
    ;

line:
    '\n' {printf("EMPTY LINE\n");}
    | error '\n'{yyerrok;}
    | expr {printf("CORRECT\n");}
    ;

expr:
    ONE ONE expr_n ZERO;

expr_n:
    expr
    | /* epsilon */
    ;
    
%%

int yyerror(char *s){
    printf("INCORRECT\n");
    return 1;
}

int yylex(){
    int c;
    c = getchar();
    switch(c){
        case '1' : return ONE;
        case '0' : return ZERO;
        case EOF : return 0;
        default : return c;
    }
}

int main(){
    yyparse();
}
