#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

struct Student
{
    int std;
    char name[20];
    float marks;
};

void addData(struct Student s[]);
void showData(struct Student s[]);

int main()
{
    struct Student s[SIZE];
    int choice;

    while (1)
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Data of Students");
        printf("\n2. Show Data of Students");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addData(s);
                break;

            case 2:
                showData(s);
                break;

            case 3:
                printf("\nProgram exited successfully.\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

void addData(struct Student s[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter details of Student %d", i + 1);

        printf("\nEnter Std   : ");
        scanf("%d", &s[i].std);

        printf("Enter Name  : ");
        scanf("%s", s[i].name);

        printf("Enter Marks : ");
        scanf("%f", &s[i].marks);
    }

    printf("\nAll student data stored successfully.\n");
}

void showData(struct Student s[])
{
    int i;

    printf("\nStd\tName\tMarks");
    printf("\n---------------------------");

    for (i = 0; i < SIZE; i++)
    {
        printf("\n%d\t%s\t%.2f",
               s[i].std,
               s[i].name,
               s[i].marks);
    }

    printf("\n");
}
