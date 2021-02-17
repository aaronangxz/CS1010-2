#include <cstdio>
#include <iostream>

using namespace std;

int within(int a[], int N, int lower, int upper, int result[])
{
    if(N == 0) return 0;

    int result_add = 0;
    if(a[0] >= lower && a[0] <= upper) {
        result_add = 1;
        result[0] = a[0];
        result = &result[1];
    }

    return result_add + within(&a[1], N - 1, lower, upper, result);
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
