#include <cstdio>
#include <iostream>
using namespace std;

struct Fraction
{
    int num;
    int dem;
};

void readFraction(Fraction& fRef);
void printFraction(Fraction& fRef);

int main()
{
    //Declare array of 5 fractions
    Fraction fA[5];

    //read 5 fractions
    for (int i = 0; i < 5; i++)
    {
        readFraction(fA[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printFraction(fA[i]);
    }
}

void readFraction(Fraction& fRef)
{
    cin >> fRef.num >> fRef.dem;
}

void printFraction(Fraction& fRef)
{
    cout << fRef.num << "/" << fRef.dem << endl;
}