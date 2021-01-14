#include <iostream>
#include <string>

using namespace std;

void n_unique(const string& input, string& result, int nCopy)
{
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
