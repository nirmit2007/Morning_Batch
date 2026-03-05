#include<iostream>
using namespace std;

class Student
{
    public:
        int id;
        //Default COnstructor is required for static array declaration
        Student() : id(0)
        {
     
        }
        Student (int p_id) : id(p_id)
        {
            // Parameterized Constructor
        }

        void displayId()
        {
            cout << "\nStudent Id : " << id;
        }
};
int main()
{
    int i;
    Student students [3];

    for(i=0;i<3;i++)
    {
        students[i].id = i+1;
    }
     for(i=0;i<3;i++)
    {
        students[i].displayId();
    }

    Student students_init[3] 
    {
        Student(101),Student(102),Student(102)
    };
    students_init[0].displayId();
    return 0;
}