#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

struct Employee e[10];
int n = 0;

void addEmployee();
void displayEmployee();
void updateEmployee();
void deleteEmployee();

int main()
{
    int ch;

    do
    {
        printf("\n\n--- Employee Menu ---");
        printf("\n1. Add Employee");
        printf("\n2. Display Employee");
        printf("\n3. Update Employee");
        printf("\n4. Delete Employee");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployee();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!");
        }

    } while (1);

    return 0;
}

void addEmployee()
{
    if (n >= 10)
    {
        printf("Employee limit reached!");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &e[n].id);

    printf("Enter Name: ");
    scanf("%s", e[n].name);

    printf("Enter Salary: ");
    scanf("%f", &e[n].salary);

    n++;
    printf("Employee Added Successfully!");
}

void displayEmployee()
{
    int i;

    if (n == 0)
    {
        printf("No Employees Found!");
        return;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nID: %d | Name: %s | Salary: %.2f",
               e[i].id, e[i].name, e[i].salary);
    }
}

void updateEmployee()
{
    int id, i;

    printf("\nEnter Employee ID to Update: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("Enter New Name: ");
            scanf("%s", e[i].name);

            printf("Enter New Salary: ");
            scanf("%f", &e[i].salary);

            printf("Employee Updated Successfully!");
            return;
        }
    }

    printf("Employee Not Found!");
}

void deleteEmployee()
{
    int id, i, j;

    printf("\nEnter Employee ID to Delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            for (j = i; j < n - 1; j++)
            {
                e[j] = e[j + 1];
            }
            n--;
            printf("Employee Deleted Successfully!");
            return;
        }
    }

    printf("Employee Not Found!");
}
