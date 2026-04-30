#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue()
{
    struct node *newnode;
    int value;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;

    if(front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Circular Queue Empty\n");
    }
    else
    {
        temp = front;

        printf("Circular Queue Elements:\n");

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != front);

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1.Enqueue\n2.Display\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                display();
                break;

            case 3:
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 3);

    return 0;
}
