#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, exp;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    return head;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if(head->next != NULL)
        {
            printf(" + ");
        }

        head = head->next;
    }

    printf("\n");
}

struct node *add(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL, *temp, *newnode;

    while(poly1 != NULL && poly2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(poly1->exp == poly2->exp)
        {
            newnode->coeff = poly1->coeff + poly2->coeff;
            newnode->exp = poly1->exp;

            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->exp > poly2->exp)
        {
            newnode->coeff = poly1->coeff;
            newnode->exp = poly1->exp;

            poly1 = poly1->next;
        }
        else
        {
            newnode->coeff = poly2->coeff;
            newnode->exp = poly2->exp;

            poly2 = poly2->next;
        }

        newnode->next = NULL;

        if(result == NULL)
        {
            result = newnode;
        }
        else
        {
            temp = result;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    return result;
}

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    printf("First Polynomial\n");
    poly1 = create(poly1);

    printf("Second Polynomial\n");
    poly2 = create(poly2);

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = add(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
