#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int is_number(char str[]) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i])) {
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
    fputc((number & 1) ? '1' : '0', stdout);
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
    unsigned r = strtoul(argv[1],NULL,10);
    if (r > 32){
        printf("Exponent is very big\n");
        return -3;
    }
    unsigned long long result = pow2(r) * (pow2(r-1) - 1);
    printf("Binary : ");
    print_binary(result);
    putchar('\n');
    printf("Octal  : %llo\n", result);
    printf("Hex    : %llx\n", result);
}