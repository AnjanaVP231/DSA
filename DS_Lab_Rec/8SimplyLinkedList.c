#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* -------- CREATE -------- */
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

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);

    } while(ch == 'y' || ch == 'Y');
}

/* -------- COUNT -------- */
int count()
{
    int c = 0;
    struct node *temp = head;

    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

/* -------- INSERT AT POSITION -------- */
void insert_pos()
{
    int pos, i;
    struct node *newnode, *temp;

    int n = count();

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newnode->data);

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for(i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

/* -------- DELETE AT POSITION -------- */
void delete_pos()
{
    int pos, i;
    struct node *temp, *prev;

    int n = count();

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        temp = head;
        printf("Deleted element = %d\n", temp->data);

        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;
        for(i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        printf("Deleted element = %d\n", temp->data);
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
        return;
    }

    printf("Linked List:\n");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------- MAIN -------- */
int main()
{
    int choice;

    printf("Create Linked List\n");
    create();

    do
    {
        printf("\n1.Insert at Position\n2.Delete at Position\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_pos();
                break;

            case 2:
                delete_pos();
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
