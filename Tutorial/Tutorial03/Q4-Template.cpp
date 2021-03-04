#include <iostream>
#include <cstdio>

using namespace std;

struct Fraction {
    int num;
    int den;
};         


void readFraction( Fraction& fRef );
//Purpose: Read numerator and denominator into fraction structure
//Output: The fraction structure referred by fRef is updated
//Return: None

void printFraction( Fraction& fRef );
//Purpose: Print numerator and denominator in a fraction structure
//Input: The fraction structure referred by fRef is printed
//Return: None

//TODO: You need to modify this version to sort Fraction instead
int compare(Fraction f1, Fraction f2)
{
    int nF1num, nF2num;
    nF1num = f1.num * f2.den;
    nF2num = f2.num * f1.den;

    if (nF1num < nF2num) return -1;
    if (nF1num == nF2num) return 0;
    return 1;
}

void insertionSort(Fraction a[], int n)
//Purpose: Perform insertion sort on a[0...n-1]
//Output: The a[] will be sorted
//Return: None
{
    int i, j;
    Fraction next;

    for (i = 1; i < n; i++) {
        next = a[i];
        for (j = i - 1; j >= 0 && (compare(a[j],next)) == 1; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = next;
    }    
}


int main()
{

    int i;

    //declare an array of 5 fractions
    Fraction fA[5] = {{2,5}, {4,10}, {1,20}, {2,10}, {1,5}};

    //Uncomment to read 5 fractions
    //for (i = 0; i < 5; i++){
    //    readFraction( fA[i] );
    //}

    //Calll insertion sort after you've updated it to sort Fractions
    insertionSort(fA,5);
    //print the sorted fractions
    for (i = 0; i < 5; i++)
    {
        printFraction( fA[i] );
        cout << endl;
    }

    return 0;
}

void readFraction( Fraction& fRef )
{
    cin >> fRef.num >> fRef.den;
}

void printFraction( Fraction& fRef )
{
    cout << fRef.num << "/" << fRef.den;
}
