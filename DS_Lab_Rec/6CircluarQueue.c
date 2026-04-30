#include <stdio.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if((rear + 1) % MAX == front)
    {
        printf("Circular Queue Full\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
            front = 0;

        rear = (rear + 1) % MAX;

        cq[rear] = value;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Circular Queue Empty\n");
    }
    else
    {
        printf("Deleted element = %d\n", cq[front]);

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Circular Queue Empty\n");
    }
    else
    {
        printf("Circular Queue Elements:\n");

        i = front;

        while(i != rear)
        {
            printf("%d ", cq[i]);
            i = (i + 1) % MAX;
        }

        printf("%d\n", cq[rear]);
    }
}

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
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 4);

    return 0;
}
