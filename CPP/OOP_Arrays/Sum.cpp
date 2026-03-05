#include<iostream>
using namespace std;

int main()
{
    int a,b,c,choice;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    cout<<"\n1.Addition";
    cout<<"\n2.Subtraction";
    cout<<"\n3.Multiplication";
    cout<<"\n4.Division";
    cout<<"\nEnter Your Choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1: c=a+b;
                cout<<"Sum = "<<c;
                break;
        case 2: c=a-b;
                cout<<"Subtraction = "<<c;
                break;
        case 3: c=a*b;
                cout<<"Multiplication = "<<c;
                break;
        case 4: c=a/b;
                cout<<"Division = "<<c;
                break;
        default: cout<<"Invalid Choice";
    }

    


}