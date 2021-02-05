#include <cstdio>
#include <iostream>

using namespace std;

int climb_stair(int N)
{
 	if (N == 1 || N == 0) return 1;
    else if (N == 2) return 2;
    else return climb_stair(N - 3) + climb_stair(N - 2)+ climb_stair(N - 1);
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
