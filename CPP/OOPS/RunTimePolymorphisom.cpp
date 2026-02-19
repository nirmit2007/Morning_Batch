#include<iostream>
using namespace std;

class Parent
{
    int l,b,ans;

    public:
        Parent()
        {
            cout << "\nThis is the default parent class";
            l=30;
            b=40;
            ans=0;
        }
        virtual void Area()
        {
            cout << "\nThis is the area function of parent class";
            ans = l*b;
            cout << "\nAns of Area is  " << ans;
        }
};

class Derived : public Parent
{
    int l,ans;

    public:
        Derived()
        {
            l=2;
            cout << "\nThis is the derived class of default constructor";
        }
        void Area()
        {
            cout << "\nThis is the area of derived class";
            ans = l*l;
            cout << "\nThe area is  " << ans;
        }
};

int main()
{
    Parent *ptr;
    Parent obj1;
    Derived obj2;
    ptr = &obj1;
    ptr -> Area();
    ptr = &obj2;
    ptr -> Area();
    return 0;
}