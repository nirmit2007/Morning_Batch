#include <stdio.h>
#include <stdlib.h>

#define EMPSIZE 100

struct Employee
{
    int id, salary, age, active;
    char name[50], dept[50];
};

struct Employee empList[EMPSIZE];
int empCount = 0;

int findIndexById(int id)
{
    int i;
    for (i = 0; i < empCount; i++)
    {
        if (empList[i].active == 1 && empList[i].id == id)
            return i;
    }
    return -1;
}

void addEmployee()
{
    struct Employee e;

    if (empCount >= EMPSIZE)
    {
        printf("\nEmployee List is Full.");
        return;
    }

    printf("\nEnter Employee Id: ");
    scanf("%d", &e.id);

    if (findIndexById(e.id) != -1)
    {
        printf("\nID already exists.");
        return;
    }

    printf("Enter Employee Name: ");
    scanf("%s", e.name);

    printf("Enter Employee Salary: ");
    scanf("%d", &e.salary);

    printf("Enter Employee Dept Name: ");
    scanf("%s", e.dept);

    printf("Enter Employee Age: ");
    scanf("%d", &e.age);

    e.active = 1;
    empList[empCount++] = e;

    printf("Employee Added Successfully!");
}

void updateEmployee()
{
    int id, index;

    printf("\nEnter Employee Id to Update: ");
    scanf("%d", &id);

    index = findIndexById(id);
    if (index == -1)
    {
        printf("Employee Not Found.");
        return;
    }

    printf("Enter New Name: ");
    scanf("%s", empList[index].name);

    printf("Enter New Salary: ");
    scanf("%d", &empList[index].salary);

    printf("Enter New Age: ");
    scanf("%d", &empList[index].age);

    printf("Enter New Department: ");
    scanf("%s", empList[index].dept);

    printf("Employee Updated Successfully!");
}

void deleteEmployee()
{
    int id, index;

    printf("\nEnter Employee Id to Delete: ");
    scanf("%d", &id);

    index = findIndexById(id);
    if (index == -1)
    {
        printf("Employee Not Found.");
        return;
    }

    empList[index].active = 0;
    printf("Employee Deleted Successfully!");
}

void printEmployee(struct Employee e)
{
    printf("\nId: %d | Name: %s | Salary: %d | Dept: %s | Age: %d",
           e.id, e.name, e.salary, e.dept, e.age);
}

void dispEmployee()
{
    int i, found = 0;

    for (i = 0; i < empCount; i++)
    {
        if (empList[i].active == 1)
        {
            printEmployee(empList[i]);
            found = 1;
        }
    }

    if (!found)
        printf("\nEmployee List is Empty.");
}

int main()
{
    int choice;

    do
    {
        printf("\n\n--- Employee Menu ---");
        printf("\n1) Insert Employee");
        printf("\n2) Update Employee");
        printf("\n3) Delete Employee");
        printf("\n4) Display Employees");
        printf("\n5) Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addEmployee(); break;
            case 2: updateEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: dispEmployee(); break;
            case 5: printf("Exiting..."); break;
            default: printf("Invalid Choice!");
        }

    } while (choice != 5);

    return 0;
}
