#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[100], top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];
    int i, op1, op2;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == ' ')
            continue;

        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+':
                    push(op1 + op2);
                    break;

                case '-':
                    push(op1 - op2);
                    break;

                case '*':
                    push(op1 * op2);
                    break;

                case '/':
                    push(op1 / op2);
                    break;

                case '^':
                    push(pow(op1, op2));
                    break;
            }
        }
    }

    printf("Result = %d", pop());

    return 0;
}
