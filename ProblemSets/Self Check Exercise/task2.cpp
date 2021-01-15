#include <iostream>
#include <string>
#include <vector>

using namespace std;

void n_unique(const string& input, string& result, int nCopy)
{
    result = "";
    vector<int> count(26);
    for (int i = 0; i < count.size(); i++)
    {
        count[i] = 0;
    }
    
    int pos;

    for (int i = 0; i < input.size(); i++) 
    {
        if (input[i] >= 97 and input[i] <= 122) 
        {
            pos = input[i]-97;
            if (count[pos] < nCopy)
            {
                result += input[i];
            }
            count[pos]++;
        } 
        else 
        {
            result += input[i]; 
        }
    }
}
        

int main()
{
    string sample = "abcdef!!abc, cba defa bcaba.";
    string result; 

    n_unique(sample, result, 1);
    cout << "NCopy = 1, Result = " << result << endl;

    n_unique(sample, result, 2);
    cout << "NCopy = 2, Result = " << result << endl;

    n_unique(sample, result, 3);
    cout << "NCopy = 3, Result = " << result << endl;

    n_unique(sample, result, 4);
    cout << "NCopy = 4, Result = " << result << endl;

    n_unique("!!!*&%^ #$##$$!!", result, 2);
    cout << "NCopy = 2, Result = " << result << endl;

    return 0;
}
