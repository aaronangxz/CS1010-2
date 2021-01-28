#include <iostream>
#include <cstdio>

using namespace std;

int polynomial(int xValue, int termArray[], int nTerm)
{
   
    return 0;   //remember to change!
}

void printPolynomial(int termArray[], int nTerm)
{
    int i;

    for (i = 0; i < nTerm; i++){
        if (i > 0){
            cout << "+ ";
        }
        cout << termArray[i];
        switch(i){
            case 0: 
                cout << "X";
                break;
            default:   
                cout << "X^" << (i+1);
        }
        cout << " ";
    }

    cout << endl;
}

int main()
{

    int poly[] = {3,2,1};

    //Test cases A
    printPolynomial(poly,3);
    cout << "When X = 2, = " << polynomial(2, poly, 3) << endl;
    cout << "When X = 3, = " << polynomial(3, poly, 3) << endl << endl;
    

    //Test cases B
    int poly2[] = {7,5,3,2};
    printPolynomial(poly2,4);
    cout << "When X = 11, = " << polynomial(11, poly2, 4) << endl;
    cout << "When X = 13, = " << polynomial(13, poly2, 4) << endl;

    return 0;
}
