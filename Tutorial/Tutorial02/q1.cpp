#include <cstdio>
#include <iostream>

using namespace std;

int power(int base, int exponent)
{
	//Base case
	if (exponent == 1) return base;
	return base * power(base,exponent - 1);

}

void print_prime_factor( int number )
{
	//Base casw
	if (number == 1) 
	{
		cout << endl;
		return;
	}
	//Starts checking from 2 onwards
	int i = 2;
	//When there is remainder, check next
	while(number % i != 0)
	{
		i ++;
	}
	//Otherwise print out factor
	cout << i << " ";
	//Begin next
	print_prime_factor(number / i);
}

int min_element(int array[], int N)
{
	
	return 0;
}

int main()
{
	cout << "2^5 = " << power(2, 5) << endl;

	print_prime_factor(140);

	int array[] = { 6, 7, -1, 3, -9};
	cout << "Min = " <<  min_element(array, 5) << endl;

	return 0;
}
