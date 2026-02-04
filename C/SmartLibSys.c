/*
Define a structure named Book with the following members:

int bookId → unique for each book
char title[40] → title of the book
char author[30] → author name
float price → must be greater than 0
int issuedCount → number of times the book has been issued (starts at 0)

Create an array of structures capable of storing a maximum of 10 books.

Your program must repeatedly display the following menu using a do-while loop until the user chooses to exit:
Add a new book
Issue a book
Return a book
Display all books
Display most issued book
Delete a book by ID
Exit
Book ID must be (no duplicates).
Price must be .
issuedCount must start from 0.
If the array is full, display an error
Ask for bookId.
If the book exists:
Increment issuedCount.


If the book does not exist:
Display: Invalid Book ID


Ask for bookId.
Decrease issuedCount .
If issuedCount is 0, print: Book was not issued
  If the book ID is invalid, display an error message.

  
Display all books in the following format:
                ID     Title         Author   Price     IssuedCount
If no books exist, display: Library is empty
Find the book with the .
If multiple books have the same highest count:
Display the book with the .


If all issued counts are 0, print: No book has been issued yet


Remove the book from the array .
Shift the remaining elements properly.
If book ID does not exist, display: Book ID not found
Terminate the program .
 Must use
 Must use
 Must use
 No global variables
 */
#include <stdio.h>

#define MAX 10

struct Book
{
    int bookId;
    char title[40];
    char author[30];
    float price;
    int issuedCount;
};

void addBook(struct Book b[], int *count);
void issueBook(struct Book b[], int count);
void returnBook(struct Book b[], int count);
void displayBooks(struct Book b[], int count);
void mostIssuedBook(struct Book b[], int count);
void deleteBook(struct Book b[], int *count);

int main()
{
    struct Book books[MAX];
    int count = 0;
    int choice;

    do
    {
        printf("\n===== LIBRARY MENU =====");
        printf("\n1. Add New Book");
        printf("\n2. Issue a Book");
        printf("\n3. Return a Book");
        printf("\n4. Display All Books");
        printf("\n5. Display Most Issued Book");
        printf("\n6. Delete Book by ID");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(books, &count);
            break;
        case 2:
            issueBook(books, count);
            break;
        case 3:
            returnBook(books, count);
            break;
        case 4:
            displayBooks(books, count);
            break;
        case 5:
            mostIssuedBook(books, count);
            break;
        case 6:
            deleteBook(books, &count);
            break;
        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}

void addBook(struct Book b[], int *count)
{
    int i, id;

    if (*count == MAX)
    {
        printf("\nLibrary is full\n");
        return;
    }

    printf("\nEnter Book Id: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (b[i].bookId == id)
        {
            printf("\nDuplicate Book Id not allowed\n");
            return;
        }
    }

    b[*count].bookId = id;

    printf("Enter Title: ");
    scanf(" %[^\n]", b[*count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", b[*count].author);

    do
    {
        printf("Enter Price (>0): ");
        scanf("%f", &b[*count].price);
    } while (b[*count].price <= 0);

    b[*count].issuedCount = 0;
    (*count)++;

    printf("Book added successfully\n");
}

void issueBook(struct Book b[], int count)
{
    int id, i;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (b[i].bookId == id)
        {
            b[i].issuedCount++;
            printf("Book issued successfully\n");
            return;
        }
    }
    printf("Invalid Book ID\n");
}

void returnBook(struct Book b[], int count)
{
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (b[i].bookId == id)
        {
            if (b[i].issuedCount == 0)
                printf("Book was not issued\n");
            else
            {
                b[i].issuedCount--;
                printf("Book returned successfully\n");
            }
            return;
        }
    }
    printf("Invalid Book ID\n");
}

void displayBooks(struct Book b[], int count)
{
    int i;

    if (count == 0)
    {
        printf("Library is empty\n");
        return;
    }

    printf("\nID  Title            Author           Price   Issued\n");
    for (i = 0; i < count; i++)
    {
        printf("%d   %-15s %-15s %.2f   %d\n",
               b[i].bookId, b[i].title, b[i].author,
               b[i].price, b[i].issuedCount);
    }
}

void mostIssuedBook(struct Book b[], int count)
{
    int i, max = 0, index = -1;

    for (i = 0; i < count; i++)
    {
        if (b[i].issuedCount > max)
        {
            max = b[i].issuedCount;
            index = i;
        }
    }

    if (index == -1)
        printf("No book has been issued yet\n");
    else
        printf("Most Issued Book: %s (Issued %d times)\n",
               b[index].title, b[index].issuedCount);
}

void deleteBook(struct Book b[], int *count)
{
    int id, i, j;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (b[i].bookId == id)
        {
            for (j = i; j < *count - 1; j++)
                b[j] = b[j + 1];

            (*count)--;
            printf("Book deleted successfully\n");
            return;
        }
    }
    printf("Book ID not found\n");
}
