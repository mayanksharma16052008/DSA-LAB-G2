#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to calculate the length of the linked list
int getLinkedListLength(struct Node* head) {
    int count = 0;          
    struct Node* current = head; 

    while (current != NULL) {
        count++;           
        current = current->next;
    }

    return count;          
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // 1. Create a sample linked list: 10 -> 20 -> 30 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // 2. Find and print the length
    int length = getLinkedListLength(head);
    printf("The length of the linked list is: %d\n", length);

    // 3. Clean up allocated memory (Good practice)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}