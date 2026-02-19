#include<iostream>
using namespace std;

class StaticEx
{
    public:
        static int count;
        int count1; 

        StaticEx()
        {
            cout << "This is the static example of contructor";
        }
        ~StaticEx()
        {
            cout << "The destructor called";
        }
};

int StaticEx :: count = 4;
int main()
{
    StaticEx obj;
    obj.count;
    cout << StaticEx :: count;
    cout << "\nThe count instance variable is " << obj.count1;
    return 0;
}