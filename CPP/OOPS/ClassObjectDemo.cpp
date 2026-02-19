#include<iostream>
using namespace std;

class A
{
   private : //By default it is private 
   int x,y,z;
    
   public :
    void add();
    void sub();
    void mul();
    void div();
};

void A::add() // Scope resolutuion Operator 
{
    cout<<"Enter value of x and y : ";
    cin>>x>>y;
    z = x+y;
    cout<<"\nAddition : "<<z;
}
void A::sub()
{
    z = x-y;
    cout<<"\nSubtraction : "<<z;
}
void A::mul()
{
    z = x*y;
    cout<<"\nMultiplication : "<<z;
}
void A::div()
{
    z = x/y;
    cout<<"\ndivison : "<<z;
}

int main()
{
    A obj;
    obj.add();
    obj.sub();
    obj.mul();
    obj.div();
    return 0;
}