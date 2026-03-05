#include<iostream>
using namespace std;

class Bank
{
    int custId;
    string custName;
    float balance,depositeAmount,withdrawAmount;

    public :
    Bank()
    {
        cout << "\nThe Default Constructed Called";
        balance = 10000;
        cout << "\nThe Balance Initialized";
    }
    void scan();
    void withdraw();
    void deposite();
    void banalce();
};

void Bank :: scan()
{
    cout << "\nEnter Customer Id : ";
    cin >> custId;
    cout << "\nEnter Customer Name : ";
    cin >> custName;
}
void Bank ::  withdraw()
{
    float Tbalance;

    cout << "\nEnter amount for withdraw : ";
    cin >> withdrawAmount;

    if(withdrawAmount > balance)
    {
        cout << "\nInsufficient Balance";
    }
    else
    {
        Tbalance = balance - withdrawAmount;
        cout << "\nThe Balance after Withdraw : " << Tbalance;
        balance = Tbalance;
    }
}
void Bank :: deposite()
{
    float Tbalance;

    cout << "\nEnter amount for deposite : ";
    cin >> depositeAmount;

    Tbalance = balance + depositeAmount;
    cout << "\nThe Balance after Deposite : " << Tbalance;
    balance = Tbalance;
}
void Bank :: banalce()
{
    cout << "\nThe Current Balance : " << balance;
}
