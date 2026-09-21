#include <stdio.h>
#define size 5
int stack[size];
int top = -1;
void push(int x) {
    if (top == size - 1) {
        printf("Stack Overflow\n");
    } else {
        top = top + 1;
        stack[top] = x;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Deleted element is %d\n", stack[top]);
        top = top - 1;
    }
}
void peek() {
    if (top==-1) {
        printf("Stack is empty\n");
    }
    else {
        printf("%d ",stack[top]);
    }
}
int main() {
    int ch = 1, c, x;
    printf("Enter the commands: \n");
    while (ch != 0) {
        printf("\nEnter 2 for push and 3 for pop: ");
        scanf("%d", &c);
        if (c == 2) {
            printf("Enter the data to push: ");
            scanf("%d", &x);
            push(x);
        } else if (c == 3) {
            pop();
        } else {
            printf("Invalid command\n");
        }
        printf("Enter 0 to exit or 1 to continue: ");
        scanf("%d", &ch);
    }
    printf("The elements in the stack are:");
    while (top != -1) {
        peek();
        top--;
    }
    return 0;
}