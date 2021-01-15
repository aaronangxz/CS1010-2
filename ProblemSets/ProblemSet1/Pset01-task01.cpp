#include <cstdio>
#include <iostream>

using namespace std;

void print_solid_slanted_pyramid( int height )
{
	int count = 0;
	for (int i = 0; i < height; i++)	
	{
		count ++;
		for (int j = 0; j < count; j++)
		{
			cout << "#";
		}
		cout << endl;
	}
}

void print_solid_symmetric_pyramid( int height )
{
	int count = 0;
	for (int i = 0; i < height; i++)	
	{
		count ++;
		for (int k = 0; k < height - count; k++)
		{
			cout << " ";
		}
		
		for (int j = 0; j < (count * 2) - 1; j ++)
		{
			cout << "#";
		}
		cout << endl;
	}
}

void print_hollow_symmetric_pyramid(int height, char outer, char inner )
{
	
	int count = 0;
	for (int i = 0; i < height; i++)	
	{
		count ++;
		bool isrun = false;
		//Last row
		if (count == height)
		{
			inner = outer;
		}
		//Print spaces
		for (int k = 0; k < height - count; k++)
		{
			cout << " ";
		}
		
		//Start to print
		for (int j = 0; j < (count * 2) - 1; j ++)
		{
			cout << outer;
			//Onlt run if inner has not run yet
			if (isrun != true)
			{
				for (int l = 0; l < (count * 2) - 3; l++)
				{
					isrun = true;
					cout << inner;
					j++;
				}
			}
		}
		cout << endl;
	}
}

int main()
{
	//Comment / modify the following statements to test
	//You can attempt the parts independently

	// print_solid_slanted_pyramid(4);

	// print_solid_symmetric_pyramid(4);

	print_hollow_symmetric_pyramid( 4, '#', '$');

	return 0;
}
