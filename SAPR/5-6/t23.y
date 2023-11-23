%{
#include <stdio.h>
#include <string.h>

int free_coef = 0;

int yyerror();
int check_indexes();
int check_letters();
void out();
extern int yylex();

int var_index[512];
int len_var_index = 0;

char char_var[512];
int len_char_var = 0;

int a[512];
int len_a = 0;
%}

%union{
    char cval;
    int ival;
    struct {
        char letter;
        int index;
    } var;
}
%token <var> X
%token <cval>SIGN
%token GLT
%token <ival>COEF
%%

input:
    | input line
;

line : ineq '\n' {
        if (check_letters() && check_indexes()){
            out();
            printf("+add_value = %d\n",free_coef);
        }
        else {printf("%d %d ", check_letters(), check_indexes()); }
        //else yyerror();
        len_a = 0;
        len_char_var = 0;
        len_var_index = 0;
        free_coef = 0;
        }
    | error '\n' {
        yyerrok;
        len_a = 0;
        len_char_var = 0;
        len_var_index = 0;
        free_coef = 0;
        }
;

ineq: exp GLT COEF {
        printf("+AddValue = ");
        free_coef +=$3;
        }
    | exp GLT SIGN COEF{
        if ($3 == '-') free_coef -= $4;
        else free_coef += $4;
    }
;

exp:  exp SIGN COEF { free_coef = $2 == '+' ? free_coef - $3: free_coef + $3; }
    | exp SIGN COEF X {
	if ($3 != 0){
            char_var[len_char_var++] = $4.letter;
            var_index[len_var_index++] = $4.index;

            if ($2 == '-') a[len_a++] = -$3;
            else {a[len_a++] = $3;}
	}
        }
    | exp SIGN X {
        char_var[len_char_var++] = $3.letter;
        var_index[len_var_index++] = $3.index;

        if ($2 == '-') a[len_a++] = -1;
        else {a[len_a++] = 1;}
        }
    | SIGN COEF { free_coef = $1 == '+' ? free_coef - $2: free_coef + $2; }
    | SIGN COEF X {
        if ($2 != 0){
	    char_var[len_char_var++] = $3.letter;
            var_index[len_var_index++] = $3.index;

            if ($1 == '-') a[len_a++] = -$2;
            else {a[len_a++] = $2;}
	}
        }
    | SIGN X {
        char_var[len_char_var++] = $2.letter;
        var_index[len_var_index++] = $2.index;

        if ($1 == '-') a[len_a++] = -1;
        else {a[len_a++] = 1;}
        }
    | COEF { free_coef -=$1; }
    | COEF X {
	if ($1 != 0){
            char_var[len_char_var++] = $2.letter;
            var_index[len_var_index++] = $2.index;

            a[len_a++] = $1;
        }
	}
    | X {
        char_var[len_char_var++] = $1.letter;
        var_index[len_var_index++] = $1.index;

        a[len_a++] = 1;
        }
;
%%

int check_letters(){
    if (len_char_var < 2) return 1;
    char start = char_var[0];
    for (int i = 1; i < len_char_var; i++){
        if (char_var[i] != start) return 0;
    }
    return 1;
}

int check_indexes(){
    if (len_var_index < 2) return 1;
    for (int i = 0; i < len_var_index; i++){
        for (int j = i+1; j < len_var_index; j++){
            if (var_index[i] == var_index[j]) return 0;
        }
    }
    return 1;
}

int main() {
    return yyparse();
}

void out(){
    for (int i = 0; i < len_char_var; i++){
        if (i == 0) printf("%d*%c%d", a[i], char_var[i], var_index[i]);
        else if (a[i] < 0) printf("%d*%c%d", a[i], char_var[i], var_index[i]);
        else printf("+%d*%c%d", a[i], char_var[i], var_index[i]);
    }
}

int yyerror() {
 printf("Wrong\n");
 return 0;
}

int yywrap() {
    return 1;
}
