#include <iostream>
using namespace std;

// Base class
class Employee
{
protected:
    int id;
    string name;

public:
    void setEmployee()
    {
        cout << "Enter Employee ID   : ";
        cin >> id;
        cout << "Enter Employee Name : ";
        cin >> name;   
    }

    void displayEmployee()
    {
        cout << "\nEmployee ID   : " << id << endl;
        cout << "Employee Name : " << name << endl;
    }
};

// Derived class
class SalaryEmployee : public Employee
{
private:
    float salary;

public:
    void setSalary()
    {
        cout << "Enter Salary        : ";
        cin >> salary;
    }

    void displaySalary()
    {
        cout << "Salary        : " << salary << endl;
    }
};

int main()
{
    SalaryEmployee emp;

    emp.setEmployee();   
    emp.setSalary();     

    emp.displayEmployee();
    emp.displaySalary();

    return 0;
}
