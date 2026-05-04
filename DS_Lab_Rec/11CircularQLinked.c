#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

/* -------- ENQUEUE -------- */
void enqueue()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

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

/* -------- DEQUEUE -------- */
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else if(front == rear)
    {
        temp = front;
        printf("Deleted element = %d\n", temp->data);

        front = rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        printf("Deleted element = %d\n", temp->data);

        front = front->next;
        rear->next = front;
        free(temp);
    }
}

/* -------- DISPLAY -------- */
void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;
    printf("Circular Queue Elements:\n");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != front);

    printf("(back to front)\n");
}

/* -------- MAIN -------- */
int main()
{
    int choice;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
