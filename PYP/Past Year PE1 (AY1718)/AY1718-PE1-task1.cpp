#include <cstdio>
#include <iostream>

using namespace std;

int within(int a[], int N, int lower, int upper, int result[])
{
    return 0;
}


int main()
{
    int a[] = {4, 1, 3, 1, 3, 2};
    int result[6] = {0};
    int i, nResult;

    //Try out different bounds

    nResult = within(a, 6, 2, 3, result);
    //nResult = within(a, 6, 1, 4, result);
    //nResult = within(a, 6, 5, 10, result);

    cout << nResult << " data passed the bounds\n";
    for (i = 0; i < nResult; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
