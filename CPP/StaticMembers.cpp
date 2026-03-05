#include <iostream>
using namespace std;

class Shape
{   
    private:
        int length,breadth,radius;
    public:
        static int count; 

        Shape()
        {
            cout << "The constructor is initialized" << endl;
            length = 23;
            breadth = 12;
            radius = 5;
        }
        static void counter();
};        

int Shape::count = 0; // Initialize static member variable
void Shape::counter() {
    count++;
    cout << "Number of shapes created: " << count << endl;
}

int main()
{
    Shape triangle; 
    Shape rectangle; 
    Shape square;
    triangle.counter(); 
    rectangle.counter();  
    square.counter(); 
    Shape ::counter(); 
    cout << triangle.count << endl;
    return 0;
}