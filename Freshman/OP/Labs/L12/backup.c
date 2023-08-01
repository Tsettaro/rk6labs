#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINE_LEN 2048

typedef struct Node {                   // узел в списке
    char * string;
    struct Node * next;
    int rep;
}
WORD;

WORD * in ();                           // ввод слов
void append(WORD ** , char * );           // добавление слова в список
void List(WORD * , FILE * );       		// вывод слов из стека в файл
void delete(WORD * );                   // удаление узлов
int repeat(WORD * , char * );           // есть ли слово в списке?

int main(int argc, char * argv[]) {
    WORD * words = NULL;
    FILE * f;
    f = fopen(argv[1], "w");            // создаём или открываем файл с функцией записи
    if (argc < 2) {
        printf("Incorrect number of arguments.\n");
        exit(-1);
    }
    words = in ();
	if (words){
		List(words, f);
		printf("\n\033[33mFile %s is complete.\n", argv[1]);
    	fclose(f);                         // закрываем файл
    	delete(words);           		   // удаляем список
	}
}


WORD * in () {
    WORD * head = NULL;
    int j = 0, c;
    char line[LINE_LEN], * elem;
    while ((c = getchar()) != EOF) {               	// ввод символов
        if (c != ' ' && iscntrl(c) == 0) {
            line[j++] = c;
        } else {
            line[j] = '\0';
            j = 0;
            if (strlen(line) == 0) continue;      	// пустую строку не обрабатываем
            if ((elem = (char *) malloc(strlen(line))) == NULL) {
                printf("NOT ENOUGH MEMORY!\n");
                exit(-1);
            }
            strcpy(elem, line);
            if (repeat(head, elem)) append(&head, elem);
        }
    }
    if (j > 0 && strlen(line) != 0) {			    // проверка на содержимое буфера
        line[j] = '\0';
        if ((elem = (char *) malloc(strlen(line))) == NULL) {
            printf("NOT ENOUGH MEMORY!\n");
            exit(-1);
        }
        strcpy(elem, line);
        if (repeat(head, elem)) append(&head, elem); // добавляем слово в список, если его там не было (иначе +1 к повтору)
    }
    return head;
}

int repeat(WORD * headRef, char * line) {
    WORD * p;
    for (p = headRef; p != NULL; p = p -> next) {
        if (strcmp(p -> string, line) == 0) {
            p -> rep += 1;
            return 0;
        }
    }
    return 1;
}

void append(WORD ** headRef, char * line) {
    WORD * newWord, * p;
    if ((newWord = (WORD * ) malloc(sizeof(WORD))) == NULL) {
        printf("NOT ENOUGH MEMORY!\n");
        exit(-1);
    }
    newWord -> rep = 1, newWord -> string = line, newWord -> next = NULL;
    if (* headRef == NULL) {
        * headRef = newWord;
    } else {
        p = * headRef;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newWord;
    }
}

void List(WORD * head, FILE * f) {
    WORD * p;
    fprintf(f, "Words - count:\n\n");
    for (p = head; p != NULL; p = p -> next) {
        fprintf(f, "%s - %d\n", p -> string, p -> rep);
    }
}

void delete(WORD * head) {
    WORD * p;
    while (head -> next != NULL){
        p = head;
        head = head -> next;
        free(p);
    }
}
