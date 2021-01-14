#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

void compute_stats(int array[], int size, double* average,double* stddev)
{
    int i = 0, j = 0;
    while (i < size)
    {
        *average += array[i];
        i++;
    }
    *average /= i;

    while (j < size)
    {
        *stddev += ((array[j] - *average) * (array[j] - *average));
        j++;
    }
    *stddev = sqrt(*stddev / (size - 1));
}

int main()
{
    int sample[] = {1, 2, 3, 4, 5, 6, 7, 8};
    //int sample[] = {727, 1086, 1091, 1361, 1490, 1956};
    double avg, stdd;

    compute_stats( sample, 8, &avg, &stdd);

    //Using C-Style printf for convenience
    printf("Average = %.4f, Std. Deviation = %.4f\n", avg, stdd);

    return 0;
}
