#include <cstdio>
#include <iostream>

using namespace std;

int linearSearch( int a[], int N, int X ) 
{
    //Initialize as -1
    int idxOfX = -1, i;

    //Loop when index less than array size and idxofX is -1
    for ( i = 0; (i < N) && (idxOfX == -1); i++ ) 
    {
        //If matches target update idxOfX
        if ( a[i] == X )
            idxOfX = i;
        //Else return -1
    }
    return idxOfX;
}

int Search7( int a[], int N) 
{
    //Initialize as -1
    int idxOfX = -1, i;

    //Loop when index less than array size and idxofX is -1
    for ( i = 0; (i < N) && (idxOfX == -1); i++ ) 
    {
        //If matches target update idxOfX
        if ( a[i] % 7 == 0 )
            idxOfX = i;
        //Else return -1
    }
    return idxOfX;
}

bool isPrime(int X)
{
    if (X<2) return false;
    int test, limit = sqrt(X);

    for (test = 2; test <= limit; test++)
    {
        if (X % test == 0) return false;
    }
    return true;
}

int SearchPrime( int a[], int N) 
{
    //Initialize as -1
    int idxOfX = -1, i;

    //Loop when index less than array size and idxofX is -1
    for ( i = 0; (i < N) && (idxOfX == -1); i++ ) 
    {
        //If matches target update idxOfX
        if (isPrime(a[i]))
            idxOfX = i;
        //Else return -1
    }
    return idxOfX;
}

int main()
{
    int array[] = {100, 42, 38, 72, 19, -7, 2, 14, 77, 89};
    int target;

    cout << "Linear Search Target = ";
    cin >> target;

    cout << "Index (-1 == not found) is ";
    cout << linearSearch(array, 10, target) << endl;

    cout << "First occurence of 7 is at index ";
    cout << Search7(array, 10) << endl;

    return 0;
}
