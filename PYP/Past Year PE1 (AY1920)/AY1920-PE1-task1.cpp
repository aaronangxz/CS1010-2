#include <cstdio>
#include <iostream>

using namespace std;

int COG(int weight[], int size)
{
    int move = 0;
    //Base case: When size is left with 1 e.g. reached centre
    if (size == 1) return 0;
    
    //Compare first index and last index
    //If lesser, move 2 pos because COG shifted 1 pos to right, plus taking account of the pos that will be removed later
    if (weight[0] < weight[size - 1]) move += 2;
    //If equal, only move 1 pos because later index that already compared will be removed
    else if (weight[0] == weight[size - 1]) move++;
    //Point weight to second index 
    //Minus size by 2
    //as we have already compared first and last
    return move + COG(&weight[1],size - 2);
}

int main()
{
    //Sample test case 1
    int w1[] = {3, 2, 9, 5, 1};
 
    cout << COG(w1, 5) << endl; 

    //Sample test case 2
    int w2[] = {1, 2, 3, 4, 5, 6, 7};
 
    cout << COG(w2, 7) << endl;

    //Sample test case 3
    int w3[] = {2, 5, 3, 1, 2};
 
    cout << COG(w3, 5) << endl;

    return 0;
}
