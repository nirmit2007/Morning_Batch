/*
Problem Statement:

Write a C program to manage employee information using array, structure, and pointers. Your program should allow the user to store, update, delete, and display employee details through a menu-driven interface.

Requirements :

Structure:
Define a struct Employee with the following members:
int id; → Employee ID
char name[50]; → Employee Name
float salary; → Employee Salary

Array of Structures:
Use an array of struct Employee to store multiple employees.
Limit the number of employees to 5 (#define MAX 5).

Pointers:
Use pointers to access and manipulate employee data inside the functions.

Functions:

Implement the following functions, using pointers where applicable:

scanEmployee(struct Employee *e) → Input employee details.

displayEmployee(struct Employee *e) → Display one employee.

displayAll(struct Employee emp[], int n) → Display all employees.

displayParticular(struct Employee emp[], int n, int id) → Display employee by ID.

updateEmployee(struct Employee emp[], int n, int id) → Update employee Name & Salary using ID.

deleteEmployee(struct Employee emp[], int *n, int id) → Delete employee by ID.
*/
#include <stdio.h>

#define MAX 5

struct Employee
{
    int id;
    char name[50];
    float salary;
};

/* Function Prototypes */
void addEmployee(struct Employee *e);
void displayEmployee(struct Employee *e);
void displayAll(struct Employee emp[], int n);
void displayParticular(struct Employee emp[], int n, int id);
void updateEmployee(struct Employee emp[], int n, int id);
void deleteEmployee(struct Employee emp[], int *n, int id);

int main()
{
    struct Employee emp[MAX];
    int n = 0, choice, id;

    do
    {
        printf("\n\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Display Employee By Id");
        printf("\n4. Update Employee");
        printf("\n5. Delete Employee");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (n < MAX)
            {
                addEmployee(&emp[n]);
                n++;
            }
            else
            {
                printf("\nEmployee List is Full");
            }
            break;

        case 2:
            displayAll(emp, n);
            break;

        case 3:
            printf("\nEnter Employee Id: ");
            scanf("%d", &id);
            displayParticular(emp, n, id);
            break;

        case 4:
            printf("\nEnter Employee Id to Update: ");
            scanf("%d", &id);
            updateEmployee(emp, n, id);
            break;

        case 5:
            printf("\nEnter Employee Id to Delete: ");
            scanf("%d", &id);
            deleteEmployee(emp, &n, id);
            break;

        case 6:
            printf("\nExiting Program...");
            break;

        default:
            printf("\nInvalid Choice");
        }

    } while (choice != 6);

    return 0;
}

/* Add Employee */
void addEmployee(struct Employee *e)
{
    printf("\nEnter Id: ");
    scanf("%d", &e->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", e->name);

    printf("Enter Salary: ");
    scanf("%f", &e->salary);
}

/* Display One Employee */
void displayEmployee(struct Employee *e)
{
    printf("\n--------------------");
    printf("\nEmployee Id    : %d", e->id);
    printf("\nEmployee Name  : %s", e->name);
    printf("\nEmployee Salary: %.2f", e->salary);
}

/* Display All Employees */
void displayAll(struct Employee emp[], int n)
{
    if (n == 0)
    {
        printf("\nNo Employee to display");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        displayEmployee(&emp[i]);
    }
}

/* Display Particular Employee */
void displayParticular(struct Employee emp[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (emp[i].id == id)
        {
            displayEmployee(&emp[i]);
            return;
        }
    }
    printf("\nEmployee with Id %d not found", id);
}

/* Update Employee */
void updateEmployee(struct Employee emp[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (emp[i].id == id)
        {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", emp[i].name);

            printf("Enter New Salary: ");
            scanf("%f", &emp[i].salary);

            printf("\nEmployee Updated Successfully");
            return;
        }
    }
    printf("\nEmployee with Id %d not found", id);
}

/* Delete Employee */
void deleteEmployee(struct Employee emp[], int *n, int id)
{
    for (int i = 0; i < *n; i++)
    {
        if (emp[i].id == id)
        {
            for (int j = i; j < *n - 1; j++)
            {
                emp[j] = emp[j + 1];
            }
            (*n)--;

            printf("\nEmployee Deleted Successfully");
            return;
        }
    }
    printf("\nEmployee with Id %d not found", id);
}
