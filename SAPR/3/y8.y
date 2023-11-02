%{
#include <stdio.h>
int yylex();
int yyerror(char*);
%}

%start input
%token ONE ZERO

%%
input : input line
    |
    ;
line : '\n' {printf("EMPTY LINE\n");}
    | error '\n'{yyerrok;}
    | zeros'\n'{printf("CORRECT\n");}
    | ones'\n'{printf("CORRECT\n");};
zeros: ZERO
    | zeros ZERO;
ones: ONE
    | ones ONE;
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

