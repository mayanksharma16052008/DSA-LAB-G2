#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the end
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position; // Element found
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

int main() {
    struct Node* head = NULL;

    // Insert sample elements: 10 -> 20 -> 30 -> 40
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    int key = 30; // Element to search
    int result = search(head, key);

    if (result != -1) {
        printf("Element %d found at position %d.\n", key, result);
    } else {
        printf("Element %d not found in the linked list.\n", key);
    }

    return 0;
}