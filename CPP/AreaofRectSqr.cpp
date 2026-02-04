/*
Create a program using Object-Oriented Programming concepts with the following requirements:

Create a class named Shape.

The class should have the following private data members:

length (integer)

breadth (integer)

Create a public member function named area() that calculates and returns the area of a rectangle using:

area =length×breadth

Create another public member function named area1() to calculate the area of a square.

In the main function:

Create an object of the Shape class.

Assign values to the data members.

Call both area() and area1() functions and display the results.

Note:

Use proper access specifiers.

Follow good coding style and indentation.

Take input from the user for dimensions.

Part 2 : 

swapValues()
-->Swap the values of length and breadth without using a third variable.

checkZero()
-->Return 1 if any dimension is zero, otherwise return 0.

 increment()
-->Increase both length and breadth by 1 and return the new area.

Last Part Of Question

mysteryArea()
--> This method should modify length and breadth using the rules below and finally return the area.

Rules (follow in order):

1] If length is even → divide it by 2
Otherwise → add 3 to it

2] If breadth is odd → multiply it by 2
Otherwise → subtract 2 from it

3] If after step 1 & 2 any value becomes negative → make it positive.

4] Now compare both values:

    If length > breadth → subtract breadth from length

   If breadth > length → subtract length from breadth

   If equal → add 1 to both

5] Repeat step 4 one more time.

6] Return the final area using:

area = length × breadth
*/

#include <iostream>
using namespace std;

class shape
{
    int length;
    int breadth;

public:
    void setValues(int l, int b) // It set values
    {
        length = l;
        breadth = b;
    }

    int area() // Area of rectangle
    {
        return length * breadth;
    }

    int area1() // Area of square
    {
        return length * length;
    }

    void swapValues()
    {
        length = length + breadth;
        breadth = length - breadth;
        length = length - breadth;
    }

    int checkZero()
    {
        if (length == 0 || breadth == 0)
            return 1;
        else
            return 0;
    }

    int increment()
    {
        length++;
        breadth++;
        return length * breadth;
    }

    int mysteryArea()
    {
        // Step 1
        if (length % 2 == 0)
            length = length / 2;
        else
            length = length + 3;

        // Step 2
        if (breadth % 2 != 0)
            breadth = breadth * 2;
        else
            breadth = breadth - 2;

        // Step 3
        if (length < 0)
            length = -length;
        if (breadth < 0)
            breadth = -breadth;

        // Step 4 (first time)
        if (length > breadth)
            length = length - breadth;
        else if (breadth > length)
            breadth = breadth - length;
        else
        {
            length++;
            breadth++;
        }

        // Step 5 (second time)
        if (length > breadth)
            length = length - breadth;
        else if (breadth > length)
            breadth = breadth - length;
        else
        {
            length++;
            breadth++;
        }

        // Step 6
        return length * breadth;
    }

    void display()
    {
        cout << "Length = " << length << endl;
        cout << "Breadth = " << breadth << endl;
    }
};

int main()
{
    shape obj;
    int l, b;

    cout << "Enter Length : ";
    cin >> l;

    cout << "Enter Breadth : ";
    cin >> b;

    obj.setValues(l, b);

    cout << "Area of Rectangle = " << obj.area() << endl;
    cout << "Area of Square = " << obj.area1() << endl;

    // Swap values
    obj.swapValues();
    cout << "\nAfter Swapping :" << endl;
    obj.display();

    // Check zero
    cout << "\nCheck Zero Result : " << obj.checkZero() << endl;

    // Increment and get new area
    cout << "\nArea after Increment : " << obj.increment() << endl;
    obj.display();

    // Mystery Area
    cout << "\nMystery Area : " << obj.mysteryArea() << endl;
    obj.display();

    return 0;
}
