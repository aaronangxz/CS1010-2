#include <iostream>
using namespace std;

int main(void)
{
    string input;
    bool palindrome = true;
    cin >> input;
    for (int i = 0; i < (input.size())/2 ; i++)
    {
        if (input[i] != input[input.size() - 1 - i]) 
        {
            palindrome = false;
            break;
        }
        //cout << "State now is " << palindrome << " in " << i << " for " << input[i] << " & " << input[input.size() - 1 - i] << endl;
    }
    
    if (palindrome == 0)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
}