/*

Define the following structure in C:

struct BankAccount
{
int accountNumber;
float balance;
float interest;
};


Write a menu-driven C program that uses only one structure variable and a pointer to that structure to perform the operations described below.

The program must repeatedly display the menu and execute the selected option until the user chooses to exit.

Menu Options
1. Open Account
2. Deposit Amount
3. Withdraw Amount
4. Calculate Interest
5. Display Account Details
6. Exit

Operation Specifications

1. Open Account
-Read account number and initial balance from the user.
-Initialize the interest value to 0.

2. Deposit Amount
-Read deposit amount from the user.
-If the deposit amount is greater than 0, add it to the balance.
-Otherwise, display an appropriate error message.

3. Withdraw Amount

-Read withdrawal amount from the user.
-Allow withdrawal only if:
* The withdrawal amount is greater than 0, and
* The balance after withdrawal remains at least 1000.
-If withdrawal is not permitted, display a suitable message.

4. Calculate Interest
-Calculate interest based on the current balance according to the following conditions:
*Balance Condition Interest Rate
Balance ≥ 50000 6%
Balance ≥ 20000 4%
Balance < 20000 2%
-Store the calculated interest in the structure.
-Do not modify the balance during this operation.

5. Display Account Details
-Display the following information:
*Account number
*Current balance
*Calculated interest
*Final amount (balance + interest)

6. Exit
Terminate the program

-> Constraints

*Use only while loop for repetition
*Access structure members only through a pointer
*Arrays are not allowed
*For loop is not allowed
*Global variables are not allowed

*/
#include<stdio.h>

struct BankAccount
{
    int accountNumber;
    float balance;
    float interest;
};

int main()
{
    int choice;
    float amount;

    struct BankAccount acc;
    struct BankAccount *p = &acc;

    p->accountNumber = 0;
    p->balance = 0;
    p->interest = 0;

    while(1)
    {
        printf("\n===== MENU =====");
        printf("\n1. Open Account");
        printf("\n2. Deposit Amount");
        printf("\n3. Withdraw Amount");
        printf("\n4. Calculate Interest");
        printf("\n5. Display Account Details");
        printf("\n6. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter Account Number : ");
                scanf("%d",&p->accountNumber);
                printf("Enter Balance : ");
                scanf("%f",&p->balance);
                p->interest = 0;
                break;

            case 2:
                printf("\nEnter Deposit Amount : ");
                scanf("%f",&amount);

                if(amount > 0)
                    p->balance += amount;
                else
                    printf("Invalid Amount");
                break;

            case 3:
                printf("\nEnter Withdraw Amount : ");
                scanf("%f",&amount);

                if(amount > 0 && p->balance - amount >= 1000)
                    p->balance -= amount;
                else
                    printf("Minimum balance 1000 required");
                break;

            case 4:
                if(p->balance >= 50000)
                    p->interest = p->balance * 0.06;
                else if(p->balance >= 20000)
                    p->interest = p->balance * 0.04;
                else
                    p->interest = p->balance * 0.02;
                break;

            case 5:
                printf("\nAccount Number : %d", p->accountNumber);
                printf("\nBalance        : %.2f", p->balance);
                printf("\nInterest       : %.2f", p->interest);
                printf("\nFinal Amount   : %.2f", p->balance + p->interest);
                break;

            case 6:
                return 0;

            default:
                printf("\nInvalid Choice");
        }
    }
}
