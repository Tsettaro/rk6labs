#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN 2048

typedef struct Node {                  // узел в списке
    char * string;
    struct Node * next;
    int rep;
}
WORD;

WORD * in ();                        // ввод слов        
void push(WORD ** , char *);        // добавление слова в стек
void printList(WORD *, FILE *);                // вывод слов из стека
void delete (WORD *);                // удаление узлов
int repeat(WORD *, char *);


int main(int count, char *argv[]) {    
    WORD * words = NULL;
    FILE f;
    f = fopen(argv[1], "w+");
    if (count < 2){
        printf("Not enough arguments.\n");
        exit (-1);
    }
    words = in ();
    printf("\nWords: \n");
    printList(words, f);
    delete(words); 
}
WORD *in(){
    WORD * head = NULL;
    int k = 0, c;
    char buf[LINE_LEN], *elem; 
    while ((c=getchar()) != EOF) {               // ввод символов
        if (c != '\n' && c != '\t' && c != ' ') {
            buf[k++] = c;
        } else {
            buf[k] = '\0';
            if (strlen(buf) == 0) continue;
            k = 0;
            if ((elem = (char *) malloc(strlen(buf))) == NULL) {
                printf("NOT ENOUGH MEMORY!\n");
                exit(-1);
            }
            strcpy(elem, buf);
            if (repeat(head, elem)) push(&head, elem);
        }
    }
    return head;
}

int repeat(WORD * headRef, char * line){
    WORD *p;
    for (p = headRef; p != NULL; p = p -> next){
        if (strcmp(p->string, line) == 0){
            p->rep+=1;
            return 0;
        }
    }
    return 1;
}

void push(WORD ** headRef, char * line) {    
    WORD * newWord, * p;
    if ((newWord = (WORD *) malloc(sizeof(WORD))) == NULL) {
        printf("NOT ENOUGH MEMORY!\n");
        exit(-1);
    }
    newWord -> rep = 0, newWord -> string = line, newWord -> next = NULL;
    if (*headRef == NULL){
        *headRef = newWord;
    } else{
        p = *headRef;
        while (p -> next != NULL){
          p = p -> next;
        }
        p -> next = newWord;
    }    
}

void printList(WORD * head, FILE * f) {
    WORD *p;
    for(p = head; p != NULL; p = p -> next){
        fprintf(f, "%s – %d\n", p -> string, p -> rep);
    } 
}

void delete (WORD *head){
    WORD *p;
    for (p = head; head -> next != NULL; head = head -> next){
        WORD *p = head;
        head = head -> next;
        free(p);
    }
}