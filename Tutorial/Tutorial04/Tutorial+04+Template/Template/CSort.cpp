#include <cstdio>
#include <iostream>

using namespace std;

void counting_sort(int score[], int N, int final[])
{
    //Note: For clarity, we use both freq[] and cfreq[]
    //      They can be combined, i.e. only 1 array if you want
    int freq[11] = {0}, cfreq[11] = {0};
    int i, curScore;

    //1. Compute Frquency
    for (i = 0; i < N; i++){
        freq[ score[i] ] ++;
    }

    //2. Compute Cumulative Frequency
    cfreq[0] = freq[0];
    for (i = 1; i < 11; i++){
        cfreq[i] = cfreq[i-1] + freq[i];        
    }

    //3. Produce Final Position
    for (i = 0; i < N; i++){
        //Note the next two lines can be combined as:
        // final[ cfreq[ score[i] ] - 1 ] = score[i];
        curScore = score[i];
        final[ cfreq[ curScore ] - 1 ]  = curScore;
        cfreq[curScore]--;
    } 

}

int main()
{
    int sample[] = {10, 5, 7, 3, 5, 7, 7, 9, 2, 5, 7, 3};
    int sorted[12] = {0};
    int i;

    counting_sort(sample, 12, sorted);

    for (i = 0; i < 12; i++){
        cout << sorted[i] << " ";
    }
    cout << endl;

    return 0;
}
