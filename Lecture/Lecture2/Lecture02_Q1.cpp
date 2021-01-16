#include <iostream>

using namespace std;

int main(void)
{
    int i, j;
    int *ip1, *ip2;

    i = 123;
    j = 456;

    ip1 = &i;
    ip2 = &j;

    cout << "1. ip1 @ " << ip1 << " is : " << *ip1 << endl;
    cout << "2. ip2 @ " << ip2 << " is : " << *ip2 << endl;
    cout << "i @ " << &i << " is " << i << ", j @ "<< &j << " is " << j << endl << endl;


    ip1 = ip2;

    cout << "3. ip1 @ " << ip1 <<" is : " << *ip1 << endl;
    cout << "3. ip2 @ " << ip2 <<" is : " << *ip2 << endl;
    cout << "i @ " << &i << " is " << i << ", j @ "<< &j << " is " << j << endl << endl;


    *ip1 = 0;
    cout << "4. *ip1 is : " << *ip1 << endl;
    cout << "i @ " << &i << " is " << i << ", j @ "<< &j << " is " << j << endl << endl;
}