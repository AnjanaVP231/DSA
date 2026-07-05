#include <stdio.h>

#define MAX 5

int dq[MAX];
int front = -1, rear = -1;

void insertFront()
{
    int value;

    if(front == 0)
    {
        printf("No space at front\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
        {
            front = rear = 0;
        }
        else
        {
            front--;
        }

        dq[front] = value;
    }
}

void insertRear()
{
    int value;

    if(rear == MAX - 1)
    {
        printf("Deque Full\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
            front = 0;

        rear++;

        dq[rear] = value;
    }
}

void deleteFront()
{
    if(front == -1 || front > rear)
    {
        printf("Deque Empty\n");
    }
    else
    {
        printf("Deleted from Front = %d\n", dq[front]);
        front++;
    }
}

void deleteRear()
{
    if(front == -1 || front > rear)
    {
        printf("Deque Empty\n");
    }
    else
    {
        printf("Deleted from Rear = %d\n", dq[rear]);
        rear--;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("Deque Empty\n");
    }
    else
    {
        printf("Deque Elements:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", dq[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 6);

    return 0;
}
