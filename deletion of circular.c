
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to add a node to the end of the circular linked list
struct Node* addNode(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

// Function to delete the first node
struct Node* deleteBegin(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* head = tail->next;

    // If there is only one node
    if (head == tail) {
        free(tail);
        return NULL;
    }

    // Skip the head node
    tail->next = head->next;
    free(head);
    return tail;
}

// Function to delete the last node
struct Node* deleteEnd(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = tail->next;

    // If there is only one node
    if (current == tail) {
        free(tail);
        return NULL;
    }

    // Traverse to the second last node
    while (current->next != tail) {
        current = current->next;
    }

    current->next = tail->next;
    free(tail);
    return current;
}

// Function to print the list
void printList(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* p = tail->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("(back to head)\n");
}

int main() {
    struct Node* tail = NULL;

    // Build list: 10 -> 20 -> 30
    tail = addNode(tail, 10);
    tail = addNode(tail, 20);
    tail = addNode(tail, 30);

    printf("Initial list:\n");
    printList(tail);

    // Delete beginning
    tail = deleteBegin(tail);
    printf("After deleting beginning:\n");
    printList(tail);

    // Delete end
    tail = deleteEnd(tail);
    printf("After deleting end:\n");
    printList(tail);

    return 0;
}
