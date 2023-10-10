%{
    #include <stdio.h>
    int yylex();
    int yyerror(char*);
%}

%start input
%token ONE ZERO

%%
input : {printf("Enter the line: \n");}
    | input line;
line : '\n' {printf("EMPTY LINE\n");}
    | error '\n'{yyerrok;}
    | binary'\n';
binary: ZERO
    | binary ZERO
    | ONE
    | binary ONE;
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

