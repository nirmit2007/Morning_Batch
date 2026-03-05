#include<iostream>
using namespace std;

class Bank
{
    int id;
    string name;
    float rate;

public:
    Bank()
    {
        cout << "Default Constructor of Bank\n";
        rate = 10.00f;
    }

    void scanDetails();
    void displayDetails();
};

void Bank :: scanDetails()
{
    cout << "\nEnter Bank ID   : ";
    cin >> id;
    cout << "Enter Bank Name : ";
    cin >> name;
}

void Bank :: displayDetails()
{
    cout << "\nBank ID   : " << id << endl;
    cout << "Bank Name : " << name << endl;
    cout << "Rate      : " << rate << endl;
}

class Account : public Bank
{
    int accNo;
    float balance;

public:
    Account()
    {
        cout << "Default Constructor of Account\n";
        balance = 10000.00f;
    }

    void scanAccountDetails();
    void displayAccountDetails();
    void checkBalance();
    void depositAmount();
    void withdrawAmount();
};

void Account :: scanAccountDetails()
{
    cout << "\nEnter Account Number : ";
    cin >> accNo;
}

void Account :: displayAccountDetails()
{
    cout << "\nAccount Number : " << accNo << endl;
    cout << "Balance        : " << balance << endl;
}

void Account :: checkBalance()
{
    cout << "\nCurrent Balance : " << balance << endl;
}

void Account :: depositAmount()
{
    float amt;
    cout << "\nEnter Amount to Deposit : ";
    cin >> amt;
    balance += amt;
}

void Account :: withdrawAmount()
{
    float amt;
    cout << "\nEnter Amount to Withdraw : ";
    cin >> amt;

    if(amt <= balance)
        balance -= amt;
    else
        cout << "Insufficient Balance!\n";
}

class Customer : public Account
{
    int custId;
    string custName;

public:
    Customer()
    {
        cout << "Default Constructor of Customer\n";
    }

    void scanCustomerDetails();
    void displayCustomerDetails();
};

void Customer :: scanCustomerDetails()
{
    cout << "\nEnter Customer ID   : ";
    cin >> custId;
    cout << "Enter Customer Name : ";
    cin >> custName;
}

void Customer :: displayCustomerDetails()
{
    cout << "\nCustomer ID   : " << custId << endl;
    cout << "Customer Name : " << custName << endl;
}

int main()
{
    Customer cust;

    cust.scanDetails();
    cust.scanAccountDetails();
    cust.scanCustomerDetails();

    cust.displayDetails();
    cust.displayAccountDetails();
    cust.displayCustomerDetails();

    cust.depositAmount();
    cust.withdrawAmount();
    cust.checkBalance();

    return 0;
}