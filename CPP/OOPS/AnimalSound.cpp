#include<iostream>
using namespace std;

class Animal
{
    int leg;
    char sound[20];
    
    public:
        void getDetails();
        void displayDetails();

        Animal()
        {
            cout<<"\nThis is the default constant of super class Animal";
        }
};

void Animal :: getDetails()
{
    cout<<"\nEnter the number of leg posses : ";
    cin>>leg;
    cout<<"\nEnter the general sound :";
    cin>>sound;
}

void Animal :: displayDetails()
{
    cout<<"\nThe numbers of legs are "<<leg;
    cout<<"\nThe Sound is "<<sound;
}

class Dog : public Animal
{
    char color[20];
    int vaccines;

    public:    
        void getDogDetails();
        void displayDogDetails();

        Dog()
        {
            cout<<"This is the default constant of the sub class Dog";
        }   
};

void Dog :: getDogDetails()
{
    cout<<"\nEnter the color of dog : ";
    cin>>color;
    cout<<"\nEnter the number of vaccines : ";
    cin>>vaccines;
}

void Dog :: displayDogDetails()
{
    cout<<"\nThe color of dog is "<<color;
    cout<<"\nThe number of vaccines are "<<vaccines;
}

int main()
{
    Dog d;
    d.getDetails();
    d.getDogDetails();
    d.displayDetails();
    d.displayDogDetails();

    return 0;
}