#include <cstdio>
#include <iostream>

using namespace std;

int linearSearch( int a[], int N, int X ) 
{
    int idxOfX = -1, i;

    for ( i = 0; (i < N) && (idxOfX == -1); i++ ) {
        if ( a[i] == X )
            idxOfX = i;
    }

    return idxOfX;
}


int main()
{
    int array[] = {100, 42, 38, 72, 19, -7, 2, 14, 77, 89};
    int target;

    cout << "Target = ";
    cin >> target;

    cout << "Index (-1 == not found) is ";
    cout << linearSearch(array, 10, target) << endl;

    return 0;
}
