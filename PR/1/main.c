#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int is_number(char str[]) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i]) && (str[i] != '-')) {
            return 0;
        }
        i++;
    }
    return 1;
}

unsigned int pow2(unsigned int n) {
    return 1 << n;
}

void print_binary(unsigned int number) {
    if (number >> 1) {
        print_binary(number >> 1);
    }
    printf("%c", (number & 1) ? '1' : '0');
}

int main(int argc, char **argv){
    if (argc < 2){
        printf("None argument\n");
        return -1;
    }
    if (!is_number(argv[1])){
        printf("Argument is not number\n");
        return -2;
    }
    long n = strtol(argv[1],NULL,10);
    if (n > 32 || n < 2){
        printf("Exponent is not correct\n");
        return -3;
    }
    unsigned long long result = pow2(n) * (pow2(n-1) - 1);
    printf("Binary : ");
    print_binary(result);
    putchar('\n');
    printf("Octal  : %llo\n", result);
    printf("Hex    : %llx\n", result);
}