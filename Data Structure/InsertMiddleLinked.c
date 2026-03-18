#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Head = NULL;

void create();
void display();
void insertMiddle();

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert Middle");
        printf("\n4.Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insertMiddle();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}

void create()
{
    int num;
    struct Node *temp1 = Head, *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    printf("\nEnter Num : ");
    scanf("%d", &num);

    temp->data = num;
    temp->next = NULL;

    if (Head == NULL)
    {
        Head = temp;
    }
    else
    {
        while (temp1->next != NULL)
            temp1 = temp1->next;

        temp1->next = temp;
    }
}

void display()
{
    struct Node *temp = Head;

    if (Head == NULL)
    {
        printf("\nThe Linked List is empty");
        return;
    }

    while (temp != NULL)
    {
        printf("|%d|-->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void insertMiddle()
{
    int num, pos, i = 1;
    struct Node *temp1 = Head, *temp;

    printf("\nEnter Num : ");
    scanf("%d", &num);
    printf("\nEnter Position : ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("\nInvalid position");
        return;
    }

    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    temp->data = num;

    if (pos == 1)
    {
        temp->next = Head;
        Head = temp;
        return;
    }

    while (i < pos - 1 && temp1 != NULL)
    {
        temp1 = temp1->next;
        i++;
    }

    if (temp1 == NULL)
    {
        printf("\nPosition not found");
        free(temp);
    }
    else
    {
        temp->next = temp1->next;
        temp1->next = temp;
    }
}