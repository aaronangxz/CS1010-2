#include <cstdio>
#include <iostream>

using namespace std;

int COG(int weight[], int size)
{
	int move = 0;
	// check if size = 1 because always odd, hence only left the center part
	if(size == 1) return 0;

	// cout << weight[0] << " " << weight[size-1] << endl;
	if(weight[0] < weight[size - 1]) move += 2;
	else if(weight[0] == weight[size - 1]) move++;

	// size - 2 because we compare leftmost and rightmost, after comparing can 'discard' both
    return move + COG(&weight[1], size - 2);  
}

int main()
{
    //Sample test case 1
    int w1[] = {3, 2, 9, 5, 1};
 
    cout << COG(w1, 5) << endl; 

    // Sample test case 2
    int w2[] = {1, 2, 3, 4, 5, 6, 7};
 
    cout << COG(w2, 7) << endl;

    //Sample test case 3
    int w3[] = {2, 5, 3, 1, 2};
 
    cout << COG(w3, 5) << endl;

    return 0;
}
