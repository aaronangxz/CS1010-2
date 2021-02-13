#include <cstdio>
#include <iostream>

using namespace std;

struct Point 
{
	int X, Y;
};

void swap(Point a[], Point b[])
{
	Point temp;
	temp = a[1];
	a[1] = b[1];
	b[1] = temp;
}

void sort(Point a[], int n) 
{
    cout<< "Called sort" << endl;
	//You can adapt any of the insertion / selection / bubble sort
	
	//Base case
	if (n == 1) return;
	
	for (int i = 0; i < n - 1; i++)
	{
		for(int j = 0 ; j < n - i - 1; j++)
		{
			if (a[j].X > a[j+1].X)
			{
				swap(a[j].X,a[j+1].X);
				swap(a[j].Y,a[j+1].Y);
			}
			else if (a[j].X == a[j+1].X)
			{
				if (a[j].Y > a[j+1].Y)
				{
					swap(a[j].X,a[j+1].X);
					swap(a[j].Y,a[j+1].Y);
				}		
			}
		}	
	} 
	//sort(a,n-1);
}

int main()
{
	int i;
	Point ptArray[5] = { {5, 73}, {11, 34}, {11, 19}, {13, 5}, {11,68}};

	sort(ptArray, 5);

	//The output should match the order given in question
	for (i = 0; i < 5; i++)
	{
		printf("(%d, %d)\n", ptArray[i].X, ptArray[i].Y);
	}

	return 0;
}
