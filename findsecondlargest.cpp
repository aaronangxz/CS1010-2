#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findnum_sort(int arr[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(arr[j] > arr[j + 1]) swap(&arr[j],&arr[j + 1]);
        }
    }

    int max = arr[len - 1];
    for(int i = len - 1; i >= 0; i--)
    {
        if(arr[i] < max) 
        {
            max =  arr[i];
            break;
        }
    }
    return max;
}

int findnum_iter(int arr[], int len)
{
    int max = INT_MIN;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] > max) max = arr[i];
    }
    int sec_max = INT_MIN;
    for(int j = 0; j < len; j++)
    {
        if(arr[j] < max && arr[j] > sec_max) sec_max = arr[j];
    }
    return sec_max;
}

int findnum_eff(int arr[], int len)
{
    int largest, second;
    largest = second = INT_MIN;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }
    
    if(second == INT_MIN) return -1;

    return second;
}

int main()
{
    int arr[5] = {1,77,88,3,4};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << findnum_sort(arr,len) << endl;
    cout << findnum_iter(arr,len) << endl;
    cout << findnum_eff(arr,len);

}