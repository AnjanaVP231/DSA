#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char item)
{
    stack[++top] = item;
}

// Pop function
char pop()
{
    return stack[top--];
}

// Precedence function
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('(');
    strcat(infix, ")");

    for(i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while(precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
