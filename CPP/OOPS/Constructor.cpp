#include<iostream>
using namespace std;

class A
{
    private :
        int x,y,p,q;

    protected :
        int r,s;
    public :
        A()
        {
            cout<<"\nDefault Constructor";
            x=0;
            y=0;
            p=0;
            q=0;
            r=0;
            s=0;
        }
        A(int a,int b,int c,int d,int e,int f)
        {
            cout<<"\nValues of parameterised";
            x=a;
            y=b;
            p=c;
            q=d;
            r=e;
            s=f;
        }
        A(A &obj1)
        {
            cout<<"\nValues of copy";
            x=obj1.x;
            y=obj1.y;
            p=obj1.p;
            q=obj1.q;
            r=obj1.r;
            s=obj1.s;

        }
        void display()
        {
            cout<<"\nx = "<<x<<" y = "<<y<<" p = "<<p<<" q = "<<q<<" r = "<<r<<" s = "<<s;
        }
};
int main()
{
    A obj;
    obj.display();
    A obj1(10,20,30,40,50,60);
    obj1.display();
    A obj2(obj1);
    obj2.display();
}