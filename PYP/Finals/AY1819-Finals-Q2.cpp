#include <iostream>

using namespace std;

struct CarPrice 
{
    int OMV; //original market value, the "raw" price of a car 
    int COE; //Certificate of Entitlement
};

int getARF (CarPrice car)
{
    int ARF;
    if(car.OMV <= 20000) ARF = car.OMV;
    if(car.OMV >= 20001 && car.OMV <= 50000) ARF = 1.4 * car.OMV;
    else ARF = 1.8 * car.OMV;

    return ARF;
}

int compareDesirability( CarPrice carA, CarPrice carB )
{
//Purpose: Compare the desirability of carA vs carB
//Return: 0 if carA is equally desirable compared to carB
// <0 if carA is more desirable than carB (return any negative value) 
// >0 if carA is less desirable than carB (return any positive value) {
    int diff = getARF(carA) - getARF(carB);
    if (diff !=0) return diff;

    return carB.COE - carA.COE;
}

int search( CarPrice array[], CarPrice target, int low, int high ) 
//Purpose: Binary search for target carPrice in array[low...high] 
//Return: -1 if target cannot be found
// ≥0 the index of the target structure in array 
{
    int result;
    int idxOfX = -1, mid;
    while ( (low <= high) && (idxOfX == -1) ) 
    { 
        mid = (low + high) / 2;
        result = compareDesirability(array[mid],target);
        if (result == 0) idxOfX = mid;
        if(result > 0) low = mid + 1;
        else high = mid - 1;
    }
return idxOfX; 
}

int main()
{

}