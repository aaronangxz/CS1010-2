#include <cstdio>
#include <iostream>

#include <cmath>

using namespace std;


//You are not allowed to modify the structure definition
struct Point3D 
{
    int X, Y, Z;
};

/**************** Combined ********************************/
void swap(Point3D a[],int i, int j)
{
    //Swap X
    int temp;
    temp = a[i].X; 
    a[i].X = a[j].X; 
    a[j].X = temp ;

    //Swap Y
    temp = a[i].Y; 
    a[i].Y = a[j].Y; 
    a[j].Y = temp ;

    //Swap Z
    temp = a[i].Z; 
    a[i].Z = a[j].Z; 
    a[j].Z = temp ;

}

void swapPoints(Point3D a[],int i, int j)
{
    //Swap X
    int temp;
    temp = a[i].X; 
    a[i].X = a[j].X; 
    a[j].X = temp ;

    // //Swap Y
    // temp = a[i].Y; 
    // a[i].Y = a[j].Y; 
    // a[j].Y = temp ;

    // //Swap Z
    // temp = a[i].Z; 
    // a[i].Z = a[j].Z; 
    // a[j].Z = temp ;

}


double calculateDistance(Point3D starship[], Point3D planets[], int size, int i)
{
    double distance = sqrt(((starship->X - planets[i].X) * (starship->X - planets[i].X)) 
                                +((starship->Y - planets[i].Y) * (starship->Y - planets[i].Y))
                                +((starship->Z- planets[i].Z) * (starship->Z - planets[i].Z))); 
    return distance;
}

/************* Integer Bubble Sort ***************/
void bubbleSortDist (Point3D starship[], Point3D planets[], Point3D reachable[],int N)
{
    bool is_sorted;
    int i, j, temp;

    for (i = 0; i < N; ++i) 
    {
        is_sorted = true;
        for (j = 1; j < N -i; ++j) 
        {
            if(calculateDistance(starship,reachable,N,j-1) > calculateDistance(starship,reachable,N,j))
            {
                swap(reachable,j-1,j);
                is_sorted = false;
            }
        } 
        if (is_sorted) return;
    } 
}

void bubbleSortPoints (Point3D reachable[],int N)
{
    bool is_sorted, x_sorted, y_sorted, z_sorted;
    int i, j, temp;

    for (i = 0; i < N; ++i) 
    {
        x_sorted = true;
        is_sorted = true;

        //Sort X
        for (j = 1; j < N -i; ++j) 
        {
            if(reachable[j-1].X > reachable[j].X)
            {
                int temp;
                temp = reachable[j-1].X; 
                reachable[j-1].X = reachable[j].X; 
                reachable[j].X = temp ;

                is_sorted = false;
                x_sorted = false;
            }
        } 

        //Sort Y
        y_sorted = true;
        for (j = 1; j < N -i; ++j) 
                {
                    if(reachable[j-1].Y > reachable[j].Y)
                    {
                        int temp;
                        temp = reachable[j-1].Y; 
                        reachable[j-1].Y = reachable[j].Y; 
                        reachable[j].Y = temp ;

                        is_sorted = false;
                        y_sorted = false;
                    }
                } 

        //Sort Z
        z_sorted = true;
        for (j = 1; j < N -i; ++j) 
                {
                    if(reachable[j-1].Z > reachable[j].Z)
                    {
                        int temp;
                        temp = reachable[j-1].Z; 
                        reachable[j-1].Z = reachable[j].Z; 
                        reachable[j].Z = temp ;

                        is_sorted = false;
                        z_sorted = false;
                    }
                } 

        if (is_sorted) return;
    } 
}

//You are not allowed to modify the function header
int rank_reachable( Point3D planets[], int size, Point3D* starship, double maxDistance, Point3D reachable[])
{
    //Count reachable planet
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        double distance = calculateDistance(starship,planets,size,i);                     

        if (distance <= maxDistance)
        {
            reachable[count].X += planets[i].X;
            reachable[count].Y += planets[i].Y;
            reachable[count].Z += planets[i].Z;
            count ++;
        }    
    }

    //Sort by reachable distance
    bubbleSortDist(starship,planets,reachable,count);

    int sorted_distance[10]= {0};

    for (int i = 0; i < count; i++)
    {
        sorted_distance[i] = calculateDistance(starship,reachable,count,i);
    }
    
    //Sort by X,Y,Z
    for (int i = 0; i < count - 1; i++)
    {
        if (sorted_distance[i] == sorted_distance[i+1])
        {
            if (reachable[i].X > reachable[i+1].X)
            {
                swap(reachable,i,i+1);
            }
        }
    }
    
    

    
    return count;
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
