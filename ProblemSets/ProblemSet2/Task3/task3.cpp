#include <cstdio>
#include <iostream>

using namespace std;



struct Point {
	int X, Y;
};


void sort(Point a[], int n) 
{
    //You can adapt any of the insertion / selection / bubble sort
 
}

int main()
{
	int i;
	Point ptArray[5] = { {11, 34}, {5, 73}, {11, 19}, {13, 5}, {11,
		68}};

	sort(ptArray, 5);

	//The output should match the order given in question
	for (i = 0; i < 5; i++){
		printf("(%d, %d)\n", ptArray[i].X, ptArray[i].Y);
	}

	return 0;
}
