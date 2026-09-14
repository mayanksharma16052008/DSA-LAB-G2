#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    
    // Use a do-while loop because it's circular
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(back to head: %d)\n", head->data);
}

// Function to insert a node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = data;

    // If the list is empty, make the new node point to itself
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    // Otherwise, traverse to the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Update links to insert the new node at the end
    temp->next = newNode;
    newNode->next = head;

    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the circular linked list
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    // Print the list
    printList(head);

    // Free allocated memory (Good practice)
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
