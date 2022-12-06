#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN 2048

typedef struct Node {                  // узел в списке
    char * string;
    int rep;
    struct Node * next;
}
WORD;

WORD * in ();                        // ввод слов        
void push(WORD ** , char *);        // добавление слова в стек
void printList(WORD *);                // вывод слов из стека
void delete (WORD *);                // удаление узлов
int repeat(WORD *, char *);

int main() {    
    WORD * words = NULL;
    words = in ();
    printf("\nWords: \n");
    printList(words);
    //delete(words); 
}
WORD *in(){
    WORD * head = NULL;
    int k = 0, j = 0;
    char buf[15],line[20]={'e','r','t','y','\n','t','e','r','e','t','\n','r','t', EOF}, *elem; 
    while (line[j] != EOF) {               // ввод символов
        if (line[j] != '\n') {
            buf[k++] = line[j];
        } else {
            buf[k] = '\0';
            k = 0;
            if ((elem = (char *) malloc(strlen(buf))) == NULL) {
                printf("NOT ENOUGH MEMORY!\n");
                exit(-1);
            }
            for (int i = 0; i < strlen(buf); i++){
              elem[i] = buf[i];  
            }
            if (repeat(head, elem)) push(&head, elem);
        }
        j++;
    }
    if (k > 0 && strlen(buf) != 0) {			// проверка на содержимое буфера
        buf[j] = '\0';
        if ((elem = (char *) malloc(strlen(buf))) == NULL) {
            printf("NOT ENOUGH MEMORY!\n");
            exit(-1);
        }
        strcpy(elem, buf);
        push(&head, elem);
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
    newWord -> rep = 0;
    newWord -> string = line;
    newWord -> next = NULL;
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

void printList(WORD * head) {
    WORD *p;
    for(p = head; p->next != NULL; p = p -> next){
        printf("%s\n", p -> string);
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