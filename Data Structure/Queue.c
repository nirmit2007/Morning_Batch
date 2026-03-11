#include <stdio.h>
#define SIZE 5

int q[SIZE];
int rear = -1;
int front = -1;

void insert();
void deleteElement();
void display();

int main()
{
    int choice;

    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 4);

    return 0;
}

void insert()
{
    int num;

    if (rear == SIZE - 1)
    {
        printf("\nThe Queue is Full");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;

        printf("\nEnter Num : ");
        scanf("%d", &num);

        q[rear] = num;
    }
    else
    {
        printf("\nEnter Num : ");
        scanf("%d", &num);

        rear++;
        q[rear] = num;
    }
}

void deleteElement()
{
    if (front == -1)
    {
        printf("\nThe Queue is Empty");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nThe Queue is Empty");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("\t| %d |", q[i]);
        }
    }
}