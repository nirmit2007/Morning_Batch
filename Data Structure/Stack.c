#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push();
void pop();
void display();

int main()
{
    int choice;

    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;
        }

    }while(choice!=4);

    return 0;
}

void push()
{
    int num;

    if(top == SIZE-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter Num : ");
        scanf("%d",&num);

        top++;
        stack[top] = num;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\nDeleted Element : %d",stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nStack Elements:\n");

        for(i = top; i >= 0; i--)
        {
            printf("| %d |\n",stack[i]);
        }
    }
}