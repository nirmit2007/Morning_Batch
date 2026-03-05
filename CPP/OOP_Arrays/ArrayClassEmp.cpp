#include<iostream>
using namespace std;

class Employee
{
    int id;
    string name;

    public:
        Employee()
        {
            cout << "Employee Initialized";
        }
    // declaration of functions    
    void getData();
    void putData();    
};

void Employee :: getData()
{
    cout << "\nEnter Id : ";
    cin >> id;
    cout << "\nEnter Name : ";
    cin >> name;
}

void Employee :: putData()
{
    cout << id << " ";
    cout << name << " ";
    cout << endl;
}

int main()
{
    Employee emp[30];
    int i,n;

    cout << "\nEnter No of Employee : ";
    cin >> n;
    
    for(i=0;i<n;i++)
    {
        emp[i].getData();
    }

     for(i=0;i<n;i++)
    {
        emp[i].putData();
    }
    return 0;
}

