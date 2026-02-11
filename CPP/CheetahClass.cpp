#include<iostream>
using namespace std;

class Mammal
{
public:
    Mammal()
    {
        cout << "This is default constructor of Mammal class\n";
    }

    void displayMammal()
    {
        cout << "I am the mammal class\n";
    }
};

class Carnivore
{
public:
    Carnivore()
    {
        cout << "This is default constructor of Carnivore class\n";
    }

    void displayCarnivore()
    {
        cout << "I am a carnivore and do not depend on plants\n";
    }
};

class Cheetah : public Mammal, public Carnivore
{
public:
    Cheetah()
    {
        cout << "This is constructor of Cheetah class\n";
    }

    void displayCheetah()
    {
        cout << "I am a mammal, carnivore, and the fastest animal\n";
    }
};

int main()
{
    Cheetah c;

    c.displayMammal();      
    c.displayCarnivore();   
    c.displayCheetah();     

    return 0;
}
