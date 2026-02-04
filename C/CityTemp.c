/*
Write a C program that analyzes weekly temperature data for multiple cities using structures, pointers, and for loops only.

Each city has a name and temperature readings for 7 consecutive days. The program must calculate the average weekly temperature for each city and count how many days had a temperature strictly greater than 35°C.

Only cities that satisfy both of the following conditions should be displayed:

Average weekly temperature is 30°C or higher

Number of days with temperature greater than 35°C is at least 3

Program Requirements
Define a structure City containing:

city name

array of 7 floating-point temperatures

average temperature

count of hot days

Use functions to:

read city data

compute average temperature and hot-day count

display qualifying cities

Use:

pointer to structure when accessing city data inside functions

for loops only (no while or do-while loops)

Do not use global variables.

Output the average temperature up to two decimal places.


Output Format

Display the city name, average temperature, and hot-day count only for cities that satisfy the given conditions.

Additional Constraints

Use correct structure member access (. and ->)

Ensure counters are reset correctly for each city

Program must work for any valid number of cities
*/
#include<stdio.h>

struct City
{
    char name[50];
    float temp[7];
    float avgTemp;
    int hotDays;
};

void readCityData(struct City *c);
void calculateData(struct City *c);
void displayCities(struct City *c, int n);

int main()
{
    int i, n;

    printf("\nEnter number of cities : ");
    scanf("%d", &n);

    struct City cities[n];

    for (i = 0; i < n; i++)
    {
        readCityData(&cities[i]);
        calculateData(&cities[i]);
    }

    displayCities(cities, n);

    return 0;
}

void readCityData(struct City *c)
{
    int i;

    printf("\nEnter city name : ");
    scanf("%s", c->name);

    printf("Enter temperatures for 7 days : ");
    for (i = 0; i < 7; i++)
    {
        scanf("%f", &c->temp[i]);
    }
}

void calculateData(struct City *c)
{
    int i;
    float sum = 0.0;

    c->hotDays = 0;

    for (i = 0; i < 7; i++)
    {
        sum += c->temp[i];

        if (c->temp[i] > 35.0)
        {
            c->hotDays++;
        }
    }

    c->avgTemp = sum / 7.0;
}

void displayCities(struct City *c, int n)
{
    int i;

    printf("\n===== Qualified Cities =====\n");

    for (i = 0; i < n; i++)
    {
        if (c[i].avgTemp >= 30.0 && c[i].hotDays >= 3)
        {
            printf("\nCity : %s", c[i].name);
            printf("\nAverage Temperature : %.2f", c[i].avgTemp);
            printf("\nHot Days : %d\n", c[i].hotDays);
        }
    }
}

