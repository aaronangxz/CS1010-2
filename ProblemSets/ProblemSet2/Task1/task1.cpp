#include <cstdio>
#include <iostream>

using namespace std;

//used to count the number of times fibonacci is called
int __call_count = 0; 

int fibonacci_m(int N, int known_result[])
{
    //Do not remove the following line
    __call_count++;

    //Put your code below
    if ( N <= 2){
        return 1;
    }

    return fibonacci_m(N-1, known_result) + fibonacci_m(N-2, known_result);

}

int main()
{
    int N;
    int known[50] = {0}; 
    
    cout << "N = ";
    cin >> N;
    
    printf("Fibonacci(%d) is %d\n", N, fibonacci_m(N, known));
    printf("Fibonacci() called %d times\n", __call_count);

    return 0;
}
