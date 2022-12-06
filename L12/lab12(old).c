#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN 4096

typedef struct Node {  					// узел в списке
    char * string;
    struct Node * next;
    int rep;
}
WORD;


int check(WORD **, char *);
WORD * in ();						    // ввод слов
void push(WORD ** , char *);			// добавление слова в стек
void printList(WORD *);					// вывод слов из стека
void delete (WORD *);					// удаление узлов

int main() {
    WORD * words = NULL;
    words = in ();
    printf("\nWords: \n");
    printList(words);
	delete(words);
}

WORD * in () {
    WORD * head = NULL;
    int j = 0, c;
    char line[LINE_LEN], * elem;
    while ((c = getchar()) != EOF) {               	// ввод символов
        if (c != ' ' && c != '\n' && c != '\t') {
            if (isalpha(c)) line[j++] = c;
        } else {
            line[j] = '\0';
            j = 0;
            if (strlen(line) == 0) continue;      	// пустую строку не обрабатываем
            if ((elem = (char *) malloc(strlen(line))) == NULL) {
                printf("NOT ENOUGH MEMORY!\n");
                exit(-1);
            }
            strcpy(elem, line);
            push(&head, elem);
        }
    }
    if (j > 0 && strlen(line) != 0) {			    // проверка на содержимое буфера
        line[j] = '\0';
        if ((elem = (char *) malloc(strlen(line))) == NULL) {
            printf("NOT ENOUGH MEMORY!\n");
            exit(-1);
        }
        strcpy(elem, line);
        push(&head, elem);
    }
    return head;
}


void push(WORD ** headRef, char * line) {
    WORD * newWord;
    if ((newWord = (WORD *) malloc(sizeof(WORD))) == NULL) {
        printf("NOT ENOUGH MEMORY!\n");
        exit(-1);
    }
    newWord -> string = line;				    // запоминаем слово
    newWord -> next = *headRef;			    	// запоминаем адрес предыдущего узла
    *headRef = newWord;					        // новый узел
}

void printList(WORD * head) {
	WORD *p;
	for (p = head; p != NULL; p = p -> next){
		printf("%s\n", p -> string);
	}
}

void delete (WORD *head){
	while (head){
		WORD *q = head->next;
    	free(head);
		head = q->next;
	}
}

