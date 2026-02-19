#include <iostream>
using namespace std;

// ================= Part A: Single Inheritance =================

// Base class
class Person
{
protected:
    string name;

public:
    void setName()
    {
        cout << "Enter Name: ";
        cin >> name;
    }
};

// Derived class
class Teacher : public Person
{
protected:
    string subject;

public:
    void setSubject()
    {
        cout << "Enter Subject: ";
        cin >> subject;
    }

    void displayTeacher()
    {
        cout << "\n--- Teacher Details ---";
        cout << "\nName: " << name;
        cout << "\nSubject: " << subject << endl;
    }
};

// ================= Part B: Multiple Inheritance =================

// Another base class
class Student
{
protected:
    int rollNo;

public:
    void setRollNo()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
    }
};

// Multiple Inheritance
class TeachingAssistant : public Teacher, public Student
{
public:
    void displayTA()
    {
        cout << "\n--- Teaching Assistant Details ---";
        cout << "\nName: " << name;
        cout << "\nSubject: " << subject;
        cout << "\nRoll Number: " << rollNo << endl;
    }
};

// ================= Part C: Main Function =================

int main()
{
    // Teacher object
    Teacher t;
    t.setName();
    t.setSubject();
    t.displayTeacher();

    cout << "\n=============================\n";

    // Teaching Assistant object
    TeachingAssistant ta;
    ta.setName();
    ta.setSubject();
    ta.setRollNo();
    ta.displayTA();

    return 0;
}
