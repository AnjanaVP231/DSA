#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("Stack Elements:\n");

        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;
printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    do
    {
        
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);

    return 0;
}
