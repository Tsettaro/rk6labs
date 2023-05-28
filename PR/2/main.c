#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void insertNode(Node** head, char data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    
    printf("\n");
}

void freeList(Node* head) {
    Node* current = head;
    
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void shiftCharacters(Node* head, int position) {
    Node* current = head;
    int count = 0;
    
    // Move to the node at the given position
    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }
    
    if (current == NULL || current->next == NULL) {
        return;  // Invalid position or last node, no need to shift
    }
    
    Node* nextNode = current->next;
    while (nextNode != NULL) {
        current->data = nextNode->data;
        current = nextNode;
        nextNode = nextNode->next;
    }
    
    // Remove the last node
    current->next = NULL;
    free(nextNode);
}

void excludeRandomCharacters(Node* head, int numExclusions, unsigned int seed) {
    srand(seed);
    int length = 0;
    
    // Count the number of nodes in the list
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    // Exclude random characters
    for (int i = 0; i < numExclusions; i++) {
        int position = rand() % length;
        shiftCharacters(head, position);
        length--;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        printf("Usage: ./program -f [input_file] -n [num_exclusions] -s [seed]\n");
        return 1;
    }
    
    char* inputFileName;
    int numExclusions;
    unsigned int seed;
    
    // Parsing command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            inputFileName = argv[++i];
        } else if (strcmp(argv[i], "-n") == 0) {
            numExclusions = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-s") == 0) {
            seed = atoi(argv[++i]);
        }
    }
    
    // Read input file
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    // Create linked list from input text
    Node* head = NULL;
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        insertNode(&head, ch);
    }
    
    fclose(inputFile);
    
    // Exclude random characters
    excludeRandomCharacters(head, numExclusions, seed);
    
    // Print modified text
    printf("Modified text:\n");
    printList(head);
    
    // Cleanup
    freeList(head);
    
    return 0;
}