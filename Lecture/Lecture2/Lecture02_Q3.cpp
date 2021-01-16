#include <iostream>

using namespace std;

int main(void)
{
    int array[] = {1,2,3,4,5};
    int *ip1, *ip2;

    ip1 = array;
    ip2 = &(array[2]);

    cout << *ip1 << endl;
    cout << *ip2 << endl;
    cout << ip1[1] << endl;
    cout << ip2[0] << ip2[1] << endl;
    ip1[1] = ip2[1];

    cout << ip1[1] << ip2[1] << endl;
}