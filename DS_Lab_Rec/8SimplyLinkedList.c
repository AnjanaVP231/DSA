#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    char ch;
    do
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch);

    } while(ch == 'y' || ch == 'Y');
}

/* -------- INSERT -------- */
void insert_begin()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to insert: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

/* -------- DELETE -------- */
void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp = head;
        printf("Deleted element = %d\n", temp->data);

        head = head->next;
        free(temp);
    }
}

/* -------- DISPLAY -------- */
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("Linked List:\n");

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* -------- MAIN -------- */
int main()
{
    int choice;

    printf("Create Linked List\n");
    create();   // compulsory creation first

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                delete_begin();
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
