#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    int value;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;

    top = newnode;
}

void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        temp = top;

        printf("Deleted = %d\n", top->data);

        top = top->next;

        free(temp);
    }
}

void display()
{
    struct node *temp = top;

    if(top == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("Stack Elements:\n");

        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
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
