#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer initialized to NULL (Empty Stack)
struct Node* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    // 1. Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Check for heap memory allocation failure (Stack Overflow)
    if (newNode == NULL) {
        printf("Stack Overflow! Out of memory.\n");
        return;
    }
    
    // 3. Assign data and point the new node to the current top
    newNode->data = value;
    newNode->next = top;
    
    // 4. Update top to point to the new node
    top = newNode;
    printf("%d pushed onto stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    // 1. Check for Stack Underflow
    if (isEmpty()) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1; // Return an error value
    }
    
    // 2. Temporarily store the current top node
    struct Node* temp = top;
    int poppedValue = temp->data;
    
    // 3. Move the top pointer to the next node
    top = top->next;
    
    // 4. Free up the memory of the old top node
    free(temp);
    
    return poppedValue;
}

// Function to view the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Function to print all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements (Top -> Bottom):\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate stack operations
int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    
    printf("Top element is %d\n", peek());
    
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    
    display();
    
    return 0;
}
