#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* Head = NULL;

// Function to insert at beginning
void insertFirst(int num) {
    struct Node* temp;

    temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = num;
    temp->next = Head;
    Head = temp;
}

// Function to delete first node
void delFirst() {
    struct Node* temp;

    if (Head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = Head;
    Head = Head->next;
    free(temp);

    printf("First node deleted successfully\n");
}

// Function to display list
void display() {
    struct Node* temp = Head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, num;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert First\n");
        printf("2. Delete First\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                insertFirst(num);
                break;

            case 2:
                delFirst();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}