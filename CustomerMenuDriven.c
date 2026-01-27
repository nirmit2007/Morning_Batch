#include <stdio.h>

#define MAX 50

struct Customer
{
    int id;
    char name[30];
    char branch[30];
};

struct Customer c[MAX];
int n = 0;

/* function declarations */
void scan();
void display();
void displayParticular();
void update();
void deleteCustomer();

int main()
{
    int choice;

    do
    {
        printf("\n--- Customer Menu ---");
        printf("\n1. Scan");
        printf("\n2. Display All");
        printf("\n3. Display Particular");
        printf("\n4. Update");
        printf("\n5. Delete");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: scan(); break;
            case 2: display(); break;
            case 3: displayParticular(); break;
            case 4: update(); break;
            case 5: deleteCustomer(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

/* Scan */
void scan()
{
    printf("Enter ID: ");
    scanf("%d", &c[n].id);

    printf("Enter Name: ");
    scanf("%s", c[n].name);

    printf("Enter Branch: ");
    scanf("%s", c[n].branch);

    n++;
}

/* Display all */
void display()
{
    int i;

    if (n == 0)
    {
        printf("No records\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nID: %d", c[i].id);
        printf("\nName: %s", c[i].name);
        printf("\nBranch: %s\n", c[i].branch);
    }
}

/* Display particular */
void displayParticular()
{
    int id, i;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (c[i].id == id)
        {
            printf("\nID: %d", c[i].id);
            printf("\nName: %s", c[i].name);
            printf("\nBranch: %s\n", c[i].branch);
            return;
        }
    }
    printf("Customer not found\n");
}

/* Update */
void update()
{
    int id, i;

    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (c[i].id == id)
        {
            printf("Enter new Name: ");
            scanf("%s", c[i].name);

            printf("Enter new Branch: ");
            scanf("%s", c[i].branch);

            printf("Updated successfully\n");
            return;
        }
    }
    printf("Customer not found\n");
}

/* Delete */
void deleteCustomer()
{
    int id, i, j;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (c[i].id == id)
        {
            for (j = i; j < n - 1; j++)
            {
                c[j] = c[j + 1];
            }
            n--;
            printf("Deleted successfully\n");
            return;
        }
    }
    printf("Customer not found\n");
}
