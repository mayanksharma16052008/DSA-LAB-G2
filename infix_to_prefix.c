#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    char reversed[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    strcpy(reversed, infix);

    // Step 1: Reverse the expression
    reverse(reversed);

    // Step 2: Swap brackets
    for (i = 0; reversed[i] != '\0'; i++)
    {
        if (reversed[i] == '(')
            reversed[i] = ')';
        else if (reversed[i] == ')')
            reversed[i] = '(';
    }

    // Step 3: Convert reversed expression to postfix
    top = -1;

    for (i = 0; reversed[i] != '\0'; i++)
    {
        ch = reversed[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) > precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    // Step 4: Reverse postfix to get prefix
    reverse(postfix);

    strcpy(prefix, postfix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
