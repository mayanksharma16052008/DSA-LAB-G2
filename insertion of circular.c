#define _CRT_SECURE_NO_WARNINGS // Prevents Visual Studio from throwing security warnings on standard functions
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insertion at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    
    if (head == NULL) {
        newNode->next = newNode; // Points to itself
        return newNode;
    }

    // Traverse to find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;       // New node points to current head
    temp->next = newNode;       // Last node points to new node
    return newNode;             // New node becomes the new head
}

// 2. Insertion at the end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    // Traverse to find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;       // Last node points to new node
    newNode->next = head;       // New node points back to head
    return head;                // Head remains unchanged
}

// 3. Insertion after a specific value
void insertAfterValue(struct Node* head, int target, int value) {
    if (head == NULL) {
        printf("The list is empty. Cannot insert after %d.\n", target);
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == target) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Inserted %d after %d.\n", value, target);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value %d not found in the list.\n", target);
}

// Function to traverse and display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

int main() {
    struct Node* head = NULL;

    // Demonstration of insertions
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 5); // List: 5 -> 10
    displayList(head);

    head = insertAtEnd(head, 20);      // List: 5 -> 10 -> 20
    head = insertAtEnd(head, 30);      // List: 5 -> 10 -> 20 -> 30
    displayList(head);

    insertAfterValue(head, 10, 15);    // List: 5 -> 10 -> 15 -> 20 -> 30
    displayList(head);

    // Free memory before exiting (Good practice)
    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}