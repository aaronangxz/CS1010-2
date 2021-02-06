#include <cstdio>
#include <iostream>

#include <cmath>

using namespace std;


//You are not allowed to modify the structure definition
struct Point3D {
    int X, Y, Z;
};

/**************** Combined ********************************/

//You are not allowed to modify the function header
int rank_reachable( Point3D planets[], int size, Point3D* starship, 
            double maxDistance, Point3D reachable[])
{
   
    return 0;
}



/************* Integer Bubble Sort ***************/
void bubbleSort2 (int a[], int N)
{
    bool is_sorted;
    int i, j, temp;

    for (i = 0; i < N; ++i) {
        is_sorted = true;
        for (j = 1; j < N -i; ++j) {

            if (a[j-1] > a[j]) {
                temp = a[j-1] ; 
                a[j-1] = a[j] ; 
                a[j] = temp ;
                is_sorted = false;
            }
        } 

        if (is_sorted) return;
    } 
}


int main()
{
    Point3D planets[10] = {
                                   {-9, 1, 0 },
                                   {9, 10, 10},
                                   {8, -3, -6},
                                   {3, 3, 3},
                                   {-4, -9, 5},
                                   {5, 3, 3},
                                   {-4, 3, -3},
                                   {3, 5, 3},
                                   {10, -3, -9},
                                   {-3, -5, 8 }
                                };

    Point3D starship = {4, 4, 4};

    Point3D nearbyPlanets[10] = {{0}};
    int numNearby, i;

    //Task 2. Sample output
    numNearby = rank_reachable( planets, 10, &starship, 12, nearbyPlanets);
    for (i = 0; i < numNearby; i++){
        printf("(%d, %d, %d)\n", nearbyPlanets[i].X, 
                nearbyPlanets[i].Y, nearbyPlanets[i].Z);
    }

    return 0;
}
