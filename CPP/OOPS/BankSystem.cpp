/*
    Name  : Nirmit Chaudhari
    DOC   : 13-06-26
    Objective : To make a banking system based on multilevel inheritance
*/

#include <iostream>
using namespace std;

class Customer
{
protected:
    string name;
    int customerID;

public:
    void inputCustomer()
    {
        cout << "\nEnter Customer Name : ";
        cin >> name;
        cout << "Enter Customer ID : ";
        cin >> customerID;
    }

    void displayCustomer()
    {
        cout << "\nCustomer Name : " << name;
        cout << "\nCustomer ID : " << customerID;
    }
};

class Account : public Customer
{
protected:
    int accountNumber;
    float balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Number : ";
        cin >> accountNumber;
        cout << "Enter Initial Balance : ";
        cin >> balance;

        if(balance < 0)
            balance = 0;
    }

    void deposit()
    {
        float amount;
        cout << "\nEnter amount to deposit : ";
        cin >> amount;

        if(amount > 0)
        {
            balance += amount;
            cout << "Amount Deposited Successfully!";
        }
        else
        {
            cout << "Invalid Deposit Amount!";
        }
    }

    void withdraw()
    {
        float amount;
        cout << "\nEnter amount to withdraw : ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!";
        }
        else
        {
            cout << "Insufficient or Invalid Balance!";
        }
    }

    void displayAccount()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Balance : " << balance;
    }
};

class SavingsAccount : public Account
{
protected:
    float interestRate;

public:
    void setInterestRate()
    {
        cout << "\nEnter Interest Rate (%): ";
        cin >> interestRate;
    }

    void calculateInterest()
    {
        float interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "\nInterest Added : " << interest;
    }

    void displayFinalBalance()
    {
        cout << "\nFinal Balance after Interest : " << balance;
    }
};

int main()
{
    SavingsAccount s;
    int choice;

    cout << "\n------ CUSTOMER DETAILS ------";
    s.inputCustomer();

    cout << "\n------ ACCOUNT CREATION ------";
    s.createAccount();

    do
    {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Add Interest";
        cout << "\n4. Display Details";
        cout << "\n5. Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1: s.deposit(); break;
            case 2: s.withdraw(); break;
            case 3: 
                s.setInterestRate();
                s.calculateInterest(); 
                break;
            case 4:
                s.displayCustomer();
                s.displayAccount();
                s.displayFinalBalance();
                break;
            case 5:
                cout << "\nThank You!";
                break;
            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
