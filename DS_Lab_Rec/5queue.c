#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if(rear == MAX - 1)
    {
        printf("Queue Full\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Deleted element = %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Queue Elements:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
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
