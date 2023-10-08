#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define STACK 512
#define LINE_LEN 4096

typedef struct emp {
    char * test[STACK];
    int top;
}
stc;

void init(stc * );
int lat(char);
void push(stc * , char * );
void pop(stc * );

int main() {
    stc * stk;
    char line[LINE_LEN], c;
    int j;
    stk = (stc * ) malloc(sizeof(stc));
    if (stk == NULL) {
        printf("NOT ENOUGH MEMORY");
        exit(-1);
    }
    init(stk);
    j = 0;
    while ((c = getchar()) != EOF) {
        if ((c == '\n') || ((c == ' ')) || ((c == '\t'))) {
            line[j] = '\0';
            j = 0;
            push(stk, line);
        } else {
            line[j++] = c;
        }
    }
    pop(stk);
}

void init(stc * stk) {
    stk -> top = 0;
}

int lat(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void push(stc * stk, char * line) {
    char * input, c;
    int x, stl;
    x = 0;
    stl = strlen(line);
    if ((input = (char * ) malloc(stl + 1)) == NULL) {
        printf("MEMORY OFF");
        exit(-1);
    }
    for (int i = 0; i < stl; i++) {
        c = line[i];
        if (lat(c)) {
            input[x] = c;
            x++;
        }
    }
    if (stk -> top < STACK) {
        stk -> test[stk -> top] = input;
        stk -> top++;
    } else {
        printf("Stack full: %d!\n", stk -> top);
    }

}

void pop(stc * stk) {
    while (stk -> top > 0) {
        stk -> top--;
        printf("%s\n", stk -> test[stk -> top]);
    }
}