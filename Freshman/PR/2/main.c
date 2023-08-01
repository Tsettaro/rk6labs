#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(-1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
}

void insert(Node** head, char data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        current->next->prev = current;
    }
}


Node* shift(Node* text, int position) {
    Node* current = text;
    Node* temp;
    int count = 0;
    
    while (count < position) {
        current = current->next;
        count++;
    }

    if (current->next){
        temp = current;
        current = current->next;
        current->prev = temp->prev;
        if (temp->prev != NULL) temp->prev->next = current;
        else current->prev = NULL;
        free(temp);
    } else {
        temp = current;
        current = current->prev;
        if (current) current->next = temp->next;
        free(temp);
    }

    if (position == 0) return current;
    else return text;
}

Node* exclude(Node* text, int num, unsigned int seed) {
    srand(seed);
    int length = 0;

    Node* head = text;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    if (num > length){
        printf("ERROR! Length of text less than count of exclusion!\n");
        exit(-1);
    }
    for (int i = 0; i < num; i++) {
        int position = rand() % length;
        text = shift(text, position);
        length--;
    }
    return text;
}

void printList(Node* text) {
    Node* current = text;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(Node* text) {
    Node *temp;
    while (text){
        temp = text;
        text = text->next;
        free(temp);
    }
}
int main(int argc, char* argv[]) {
    if (argc != 7) {
        printf("INCORRECT INPUT: ./a.out -f [input_file] -n [num_exclusions] -s [seed]\n");
        return -1;
    }
    
    char* file_name;
    int num_exclude;
    unsigned int seed;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            file_name = argv[++i];
        } else if (strcmp(argv[i], "-n") == 0) {
            num_exclude = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-s") == 0) {
            seed = atoi(argv[++i]);
        }
    }
    
    if (num_exclude < 0){
        exit(-2);
    }

    FILE* in = fopen(file_name, "r");

    if (!in) {
        printf("Error opening input file.\n");
        return -1;
    }

    Node* text = NULL;
    char ch;
    while ((ch = fgetc(in)) != EOF) {
        insert(&text, ch);
    }
    fclose(in);

    printf("Input text: ");
    printList(text);

    text = exclude(text, num_exclude, seed);

    printf("Modified text: ");
    printList(text);

    freeList(text);
}