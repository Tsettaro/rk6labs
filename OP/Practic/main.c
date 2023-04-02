#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

int check(char n[]){
    unsigned int c = 0;
    //printf("%s", n);
    int l = strlen(n);
    for (int i = l-1; i >= 0; i--){
        unsigned a = n[i] - '0';
        if (a > 9) {return -1;}
        if ((c*10+a < c)){return -1;}
        c = c * 10 + a;
    }
    return 1;
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Not enough arguments");
        return -1;
    }
    if(check(argv[1])){
        unsigned n = atoi(argv[1]);
        printf("%u", n);
        unsigned result = pow(2, n) * (pow(2, n-1) - 1);

        printf("Binary: %b\n", result);
        printf("Octal  : %o\n", result);
        printf("Hex    : %x\n", result);
    }
}
