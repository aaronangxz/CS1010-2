#include <iostream>
#include <cstdio>

using namespace std;

struct Fraction {
    int num;
    int den;
};         


void readFraction( Fraction *fptr );
//Purpose: Read numerator and denominator into fraction structure
//Output: The fraction structure referred by fptr is updated
//Return: None

void printFraction( Fraction *fptr );
//Purpose: Print numerator and denominator in a fraction structure
//Input: The fraction structure referred by fptr is printed
//Return: None

//TODO: You need to modify this version to sort Fraction instead
void insertionSort(int a[], int n)
//Purpose: Perform insertion sort on a[0...n-1]
//Output: The a[] will be sorted
//Return: None
{
    int i, j, next;

    for (i=1; i<n; i++) {
        next = a[i];
        for (j=i-1; j>=0 && a[j]>next; j--){
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

    //printFraction(&(fA[0]));

    //read 5 fractions
    //for (i = 0; i < 5; i++){
    //    readFraction( &(fA[i]) );
    //}

    //Calll insertion sort after you've updated it to sort Fractions

    //print the sorted fractions
    for (i = 0; i < 5; i++){
        printFraction( &(fA[i]) );
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
