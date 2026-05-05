#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

/* Push */
void push(char x)
{
    stack[++top] = x;
}

/* Pop */
char pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}

/* Priority */
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;

    return -1;
}

int main()
{
    char exp[100];
    char *e, x;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    e = exp;

    printf("Postfix Expression: ");

    while(*e != '\0')
    {
        /* Operand */
        if(isalnum(*e))
        {
            printf("%c", *e);
        }

        /* Left parenthesis */
        else if(*e == '(')
        {
            push(*e);
        }

        /* Right parenthesis */
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }

        /* Operator */
        else
        {
            while(top != -1 && 
                 (priority(stack[top]) > priority(*e) ||
                 (priority(stack[top]) == priority(*e) && *e != '^')))
            {
                printf("%c", pop());
            }
            push(*e);
        }

        e++;
    }

    /* Pop remaining */
    while(top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}
