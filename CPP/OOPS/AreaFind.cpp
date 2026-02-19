#include<iostream>
using namespace std;

class Shape
{
public:
    virtual void calculateArea() = 0;   // Pure virtual function
};

// Triangle class
class Triangle : public Shape
{
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    void calculateArea()
    {
        float area = 0.5 * base * height;
        cout << "Area of Triangle = " << area << endl;
    }
};

// Rectangle class
class Rectangle : public Shape
{
protected:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    virtual void calculateArea()
    {
        float area = length * breadth;
        cout << "Area of Rectangle = " << area << endl;
    }
};

// Square class (inherits Rectangle)
class Square : public Rectangle
{
public:
    Square(float l) : Rectangle(l, l) {}

    void calculateArea()
    {
        float area = length * length;
        cout << "Area of Square = " << area << endl;
    }
};

int main()
{
    Triangle t(10, 5);
    Rectangle r(8, 4);
    Square s(6);

    t.calculateArea();
    r.calculateArea();
    s.calculateArea();

    return 0;
}
