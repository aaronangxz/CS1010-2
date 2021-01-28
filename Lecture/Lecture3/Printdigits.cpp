#include <iostream>

using namespace std;

void print_digit (int N)
{
    //Base case
    //N is single digit
    if (N < 10)
    {
        cout << N << endl;
        return;
    }
    
    //General Case
    //N has mroe than 1 digit
    cout << N % 10 << endl;
    print_digit(N / 10);

}

int main()
{
    int input;
    cout << "Input: ";
    cin >> input;

    print_digit(input);


}