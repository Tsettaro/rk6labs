#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POINT_LEN 3
#define LINE_LEN 256
char *pointers[POINT_LEN];

char *str(char *line){
    char *input, *x, c;
    int stl;
    stl = strlen(line)-1;
	input = (char *)calloc(stl + 1, sizeof(char));
    x = &input[0];
    for (int i = 0; i < stl && i < LINE_LEN; i++){
        c = line[i];
        if (c != '\t' && c != ' '){
            *x = c;
            x++;
        }
    }
    return input;
}
int main(){
    char line[LINE_LEN];
    int i;
    i = 0;
    while (i < POINT_LEN){
        fgets(line, LINE_LEN, stdin);
        pointers[i] = str(line);
        i++;
    }
    i = 0;
	while (i < POINT_LEN) {
		printf("Pointers[%d] = %s\n", i, pointers[i]);
		i++;
	}
}
