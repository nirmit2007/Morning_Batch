#include <iostream>
#include <cstring>
using namespace std;

class Customer
{
    int custID;
    char custName[30];
    char custUser[30], custPassword[30];
    float balance;

public:
    Customer()
    {
        strcpy(custUser, "cust");
        strcpy(custPassword, "cust");
        balance = 10000;
    }

    void scanCustomerDetails()
    {
        cout << "Enter Customer ID: ";
        cin >> custID;

        cout << "Enter Customer Name: ";
        cin >> custName;
    }

    void displayCustomerDetails()
    {
        cout << "\nCustomer ID : " << custID;
        cout << "\nCustomer Name : " << custName;
        cout << "\nBalance : " << balance << endl;
    }

    void depositAmount()
    {
        float deposit;
        cout << "\nEnter deposit amount: ";
        cin >> deposit;
        balance = balance + deposit;
    }

    void withdrawAmount()
    {
        float withdraw;
        cout << "\nEnter withdraw amount: ";
        cin >> withdraw;
        balance = balance - withdraw;
    }

    int login(char u[], char p[])
    {
        if (strcmp(custUser, u) == 0 && strcmp(custPassword, p) == 0)
            return 1;
        else
            return -1;
    }

    void custMenu()
    {
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Check Balance";
        cout << "\n4. Exit";
    }
};

class Bank
{
    char adminUser[30], adminPass[30];
    char bankName[30];
    int bID;

public:
    Bank()
    {
        strcpy(adminUser, "admin");
        strcpy(adminPass, "admin");
    }

    void scanBankDetails()
    {
        cout << "Enter Bank ID: ";
        cin >> bID;

        cout << "Enter Bank Name: ";
        cin >> bankName;
    }

    void displayBankDetails()
    {
        cout << "\nBank ID : " << bID;
        cout << "\nBank Name : " << bankName << endl;
    }

    int login(char u[], char p[])
    {
        if (strcmp(adminUser, u) == 0 && strcmp(adminPass, p) == 0)
            return 1;
        else
            return -1;
    }

    void adminMenu()
    {
        cout << "\n1. Create Customer";
        cout << "\n2. Display Customer";
        cout << "\n3. Exit";
    }
};

int main()
{
    Bank b;
    Customer c;

    int choice, ch;
    char user[30], pass[30];

    do
    {
        cout << "\n===== BANK SYSTEM =====";
        cout << "\n1. Admin Login";
        cout << "\n2. Customer Login";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter Admin Username: ";
            cin >> user;
            cout << "Enter Admin Password: ";
            cin >> pass;

            if (b.login(user, pass) == 1)
            {
                cout << "\nAdmin Login Successful\n";

                do
                {
                    b.adminMenu();
                    cout << "\nEnter choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                    case 1:
                        c.scanCustomerDetails();
                        break;

                    case 2:
                        c.displayCustomerDetails();
                        break;

                    case 3:
                        cout << "Exit Admin Menu\n";
                        break;
                    }

                } while (ch != 3);
            }
            else
            {
                cout << "Invalid Admin Login\n";
            }
            break;

        case 2:
            cout << "Enter Customer Username: ";
            cin >> user;
            cout << "Enter Customer Password: ";
            cin >> pass;

            if (c.login(user, pass) == 1)
            {
                cout << "\nCustomer Login Successful\n";

                do
                {
                    c.custMenu();
                    cout << "\nEnter choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                    case 1:
                        c.depositAmount();
                        break;

                    case 2:
                        c.withdrawAmount();
                        break;

                    case 3:
                        c.displayCustomerDetails();
                        break;

                    case 4:
                        cout << "Exit Customer Menu\n";
                        break;
                    }

                } while (ch != 4);
            }
            else
            {
                cout << "Invalid Customer Login\n";
            }
            break;

        case 3:
            cout << "Program Exit\n";
            break;
        }

    } while (choice != 3);

    return 0;
}