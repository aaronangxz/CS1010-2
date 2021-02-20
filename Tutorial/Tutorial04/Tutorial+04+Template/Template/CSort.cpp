#include <cstdio>
#include <iostream>

using namespace std;

struct SResult 
{
    string studentID; //student id is a string with "A1234" format
    int score; //score received by students
};

void counting_sort(int score[], int N, int final[])
{
    //Note: For clarity, we use both freq[] and cfreq[]
    //      They can be combined, i.e. only 1 array if you want
    int freq[11] = {0}, cfreq[11] = {0};
    int i, curScore;

    //1. Compute Frquency
    for (i = 0; i < N; i++)
    {
        freq[score[i]] ++;
    }

    //2. Compute Cumulative Frequency
    cfreq[0] = freq[0];
    for (i = 1; i < 11; i++)
    {
        cfreq[i] = cfreq[i-1] + freq[i];        
    }

    //3. Produce Final Position
    for (i = 0; i < N; i++)
    {
        //Note the next two lines can be combined as:
        // final[ cfreq[ score[i] ] - 1 ] = score[i];
        curScore = score[i];  
        final[cfreq[curScore] - 1]  = curScore;
        cfreq[curScore]--;
    } 
}

void counting_sort2(SResult score[], int N, SResult final[])
{
    //Note: For clarity, we use both freq[] and cfreq[]
    //      They can be combined, i.e. only 1 array if you want
    int freq[11] = {0}, cfreq[11] = {0};
    //Declare new struct to store corresponding names
    SResult names[12] = {{}};
    int i, curScore;

    //1. Compute Frquency
    for (i = 0; i < N; i++)
    {
        //Update frequency count of "i"th index in results[]
        freq[score[i].score] ++;
        //Also Update the corresponding student names
        names[i].studentID = score[i].studentID;
    }

    //2. Compute Cumulative Frequency
    cfreq[0] = freq[0];
    for (i = 1; i < 11; i++)
    {
        cfreq[i] = cfreq[i-1] + freq[i];        
    }

    //3. Produce Final Position
    // for (i = 0; i < N; i++)
    // {
    //     curScore = score[i].score;
    //     final[ cfreq[ curScore ] - 1 ].score = curScore;
    //     final[cfreq[ curScore ] - 1].studentID = names[i].studentID;
    //     cfreq[curScore]--;
    // } 

    //Stable
    for (i = N-1; i >= 0; i--)
    {
        //Current score is the ith index of score[]
        curScore = score[i].score;
        //Look for corresponding index of ith score and save current score in final[]
        final[ cfreq[ curScore ] - 1 ].score = curScore;
        //Do the same for student ID
        final[cfreq[ curScore ] - 1].studentID = names[i].studentID;
        cfreq[curScore]--;
    } 
}

int main()
{
    //int sample[] = {10, 5, 7, 3, 5, 7, 7, 9, 2, 5, 7, 3};
    SResult results[12] = {{"A0001",10},{"A6969",5},{"A1145",7},{"A1111",3},{"A0005",5},{"A0009",7},
                            {"A0953",7},{"A8484",9},{"A2525",2},{"A0008",5},{"A1235",7},{"A1119",3}};
    //int sorted[12] = {0};
    SResult sorted2[12] = {{}};
    int i;

    //counting_sort(sample, 12, sorted);
    counting_sort2(results,12,sorted2);

    for (i = 0; i < 12; i++)
	{
        cout << sorted2[i].studentID << " " << sorted2[i].score << endl;
        //printf("(%s, %d)\n", sorted2[i].studentID, sorted2[i].score);
	}
    return 0;
}
