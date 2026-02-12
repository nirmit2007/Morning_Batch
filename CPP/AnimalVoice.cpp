#include<iostream>
using namespace std;

class Animal //base class
{
    public :
        Animal()
        {
            Animal(4); // calling parameterized constructor from default constructor
            cout<<"\nThis is default constructer of super class Animal. ";
        }
        Animal(int l)
        {
            cout<<"\nAnimal has "<<l<<" legs";
        }
        void eat()
        {
            cout<<"\nAll animal need food";
        }
};
class Dog : public Animal //derived class 1
{
    public :
        Dog()
        {
            Dog(4); // calling parameterized constructor from default constructor
            cout<<"\nThis is default constructer of sub class Dog. ";
        }
        Dog(int l)
        {
            cout<<"\nDog has "<<l<<" legs";
        }
        void bark()
        {
            cout<<"\nDog barks";
        }
};
class Cat : public Animal //derived class 2
{
    public :
        Cat()
        {
            Cat(4); // calling parameterized constructor from default constructor
            cout<<"\nThis is default constructer of sub class Cat. ";
        }
        Cat(int l)
        {
            cout<<"\nCat has "<<l<<" legs";
        }
        void meow()
        {
            cout<<"\nCat meows";
        }
};
class Cow : public Animal //derived class 3
{
    public :
        Cow()
        {
            Cow(4); // calling parameterized constructor from default constructor
            cout<<"\nThis is default constructer of sub class Cow. ";
        }
        Cow(int l)
        {
            cout<<"\nCow has "<<l<<" legs";
        }
        void moo()
        {
            cout<<"\nCow moos";
        }
};
class Lion : public Animal //derived class 4
{
    public :
        Lion()
        {
            Lion(4); // calling parameterized constructor from default constructor
            cout<<"\nThis is default constructer of sub class Lion. ";
        }
        Lion(int l)
        {
            cout<<"\nLion has "<<l<<" legs";
        }
        void roar()
        {
            cout<<"\nLion roars";
        }
};
class Tiger : public Animal // derived class 5
{
    public:
        Tiger()
        {
            Tiger(4); // calling parameterized constructor from default constructor
            cout<<"\nThis is default constructor of sub class Tiger";
        }
        Tiger(int l)
        {
            cout<<"\nTiger has "<<l<<" legs";
        }
        void growl()
        {
            cout<<"\nTiger growls";
        }
}; 
int main()
{
    Dog d;
    d.eat();
    d.bark();

    cout<<"\n\n";

    Cat c;
    c.eat();
    c.meow();

    cout<<"\n\n";

    Cow w;
    w.eat();
    w.moo();

    cout<<"\n\n";
    Lion l;
    l.eat();
    l.roar();

    cout<<"\n\n";
    Tiger t;
    t.eat();
    t.growl();

    return 0;
}