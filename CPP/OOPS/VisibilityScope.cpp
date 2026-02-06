#include <iostream>
using namespace std;
class A
{
private:
    int x, y, z;

protected:
    int p, q;

public:
    int r, s;

    A()
    {
        cout << "The default constructor is called : " << endl;
        x = 0;
        y = 0;
        z = 0;
        p = 0;
        q = 0;
        r = 0;
        s = 0;
    }
    A(int a,int b,int c,int d,int e,int f,int g){
        x=a;
        y=b;
        z=c;
        p=d;
        q=e;
        r=f;
        s=g;
    }

    void display()
    {
        cout << "This is x : " << x << endl
             << "This is y : " << y << endl
             << "This is z : " << z << endl
             << "This is p : " << p << endl
             << "This is q : " << q << endl
             << "This is r : " << r << endl
             << "This is s : " << s << endl;
    }
};
int main()
{
    A obj;
    A obj1(2,3,4,5,6,7,8);
    obj.display();

    obj1.display();

    return 0;
}