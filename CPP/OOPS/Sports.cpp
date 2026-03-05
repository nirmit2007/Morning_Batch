#include<iostream>
using namespace std;

class Academic // Base Class 1
{
    private :
        float marks;

    public :
        void getAcademicData()
        {
            cout << "Enter Academic Marks : ";
            cin >> marks;
        }
        void showAcademicData()
        {
            cout << "\nAcademic Marks : " << marks;
        }
        float getMarks()
        {
            return marks;
        }
};

class Sports // Base Class 2
{
    private :
        float score;

    public :
        void getSportsData()
        {
            cout << "\nEnter Sports Score : ";
            cin >> score;
        }
        void showSportsData()
        {
            cout << "\nSports Score : " << score;
        }
        float getScore()
        {
            return score;
        }
};

class Result : public Academic, public Sports  // Derived Class
{
private:
    float total;
    float percentage;

public:
    void calculate()
    {
        total = getMarks() + getScore();
        percentage = (total / 200) * 100;
    }
    void displayResult()
    {
        showAcademicData();
        showSportsData();
        cout << "\nTotal: " << total; 
        cout << "\nPercentage: " << percentage << " %";
    }
};

int main()
{
    Result r;

    r.getAcademicData();
    r.getSportsData();

    r.calculate();
    cout << "\n-----Result-----\n";
    r.displayResult();

    return 0;
}
