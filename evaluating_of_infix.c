#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int isOperator;   // 0 = number, 1 = operator
    int value;
    char op;
} Item;

Item stack[MAX];
int top = -1;

void pushNumber(int n) {
    stack[++top].isOperator = 0;
    stack[top].value = n;
}

void pushOperator(char op) {
    stack[++top].isOperator = 1;
    stack[top].op = op;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void calculate() {
    int b, a, result;
    char op;

    b = stack[top--].value;
    op = stack[top--].op;
    a = stack[top--].value;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }

    pushNumber(result);
}

int main() {
    char exp[MAX];
    int i = 0, num;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {

        /* If digit */
        if (isdigit(exp[i])) {
            num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            pushNumber(num);
            continue;
        }

        /* Opening bracket */
        if (exp[i] == '(') {
            pushOperator(exp[i]);
        }

        /* Closing bracket */
        else if (exp[i] == ')') {
            while (top != -1 && stack[top].op != '(')
                calculate();

            top--;  // Remove '('
        }

        /* Operator */
        else {
            while (top >= 2 &&
                   stack[top].isOperator &&
                   stack[top].op != '(' &&
                   precedence(stack[top].op) >= precedence(exp[i])) {
                calculate();
            }

            pushOperator(exp[i]);
        }

        i++;
    }

    /* Calculate remaining expression */
    while (top >= 2)
        calculate();

    printf("Result = %d\n", stack[top].value);

    return 0;
}
