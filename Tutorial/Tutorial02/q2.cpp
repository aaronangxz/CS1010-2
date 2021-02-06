#include <cstdio>
#include <iostream>

using namespace std;

int climb_stair(int N)
{
 	//Base case
	if (N == 0) return 1;
	if (N == 1) return 1;
    if (N == 2) return 2;
	if (N == 3) return 4;
	//
    else return climb_stair(N - 3) + climb_stair(N - 2) + climb_stair(N - 1);
}

int main()
{
	int N;

	cout << "Number of steps = ";
	cin >> N;

    cout << climb_stair(N);
	cout << " ways to climb the staircase\n";

	return 0;
}
