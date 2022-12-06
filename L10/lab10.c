#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define POINT_LEN 2048
#define LINE_LEN 2048

void in (char * []);				// ввод слов
char * str(char * );				// создание динамического массива строк
void out(char * []);				// вывод строк
void clear(char * []);				// очищение массива указателей

int main() {
    char * pointers[POINT_LEN];
    in (pointers);				
    out(pointers);				
    clear(pointers);				
}

void in (char * pointers[]) { 			
    char line[LINE_LEN], c;
    int i, count;
    i = 0, count = 0;
    while ((c = getchar()) != EOF) { 		// ввод символов
        if (c == '\n') {
            line[i] = '\0';
            i = 0;
            pointers[count++] = str(line);
        } else {
            if (c != '\t' && c != ' ') { 	// проверка на символы-разделители
                line[i++] = c;
            }
        }
    }
    if (i > 0 && strlen(line) != 0) { 		// проверка на содержимое буфера
        line[i] = '\0';
        i = 0;
        pointers[count++] = str(line);
    }
    pointers[count] = NULL;
}

char * str(char * line) { 			
    char * input;
    int stl;
    stl = strlen(line);
    if ((input = (char * ) malloc(stl + 1)) == NULL) {
        printf("MEMORY OFF");
        exit(-1);
    }
    strcpy(input, line);
    return input;
}

void out(char * pointers[]) { 			
    printf("\n\nOutput:\n");
    for (int i = 0; pointers[i] != NULL; i++) {
        printf("%s\n", pointers[i]);
    }
}

void clear(char * pointers[]) {
    for (int i = 0; pointers[i] != NULL; i++) {
        free(pointers[i]);
    }
}
