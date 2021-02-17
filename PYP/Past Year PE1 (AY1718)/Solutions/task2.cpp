#include <cstdio>
#include <iostream>

#include <cmath>

using namespace std;


//You are not allowed to modify the structure definition
struct Point3D {
    int X, Y, Z;
};

void bubbleSort2 (Point3D a[], int N, double dist[]);
void swap(Point3D &a, Point3D &b, double &distA, double &distB);

/**************** Combined ********************************/

//You are not allowed to modify the function header
int rank_reachable( Point3D planets[], int size, Point3D* starship, 
            double maxDistance, Point3D reachable[])
{
    double distance[9999] = {};
    for(int i = 0; i < size; i++){
      int planet_starship_dist_x_sq = (planets[i].X - starship->X)*(planets[i].X - starship->X);
      int planet_starship_dist_y_sq = (planets[i].Y - starship->Y)*(planets[i].Y - starship->Y);
      int planet_starship_dist_z_sq = (planets[i].Z - starship->Z)*(planets[i].Z - starship->Z);

      distance[i] = sqrt(planet_starship_dist_x_sq + planet_starship_dist_y_sq + planet_starship_dist_z_sq);
    }

    double finalDistance[9999] = {};
    int curr = 0;
    for(int i = 0; i < size; i++){
      if(distance[i] <= maxDistance) {
        finalDistance[curr] = distance[i];
        reachable[curr++] = planets[i];
      }
    }

    bubbleSort2(reachable, curr, finalDistance);

    // for(int i = 0; i < curr; i++) {
    //   cout << reachable[i].X << " " << reachable[i].Y << " " << reachable[i].Z << " " << finalDistance[i] << endl;
    // }


    return curr;
}



/************* Integer Bubble Sort ***************/
void bubbleSort2 (Point3D a[], int N, double dist[])
{
    bool is_sorted;
    int i, j, temp;

    for (i = 0; i < N; ++i) {
        is_sorted = true;
        for (j = 1; j < N -i; ++j) {

            if (dist[j-1] > dist[j]) {
                swap(a[j], a[j-1], dist[j], dist[j-1]);
                is_sorted = false;
            } 
            else if (dist[j-1] == dist[j]) {
              if(a[j-1].X > a[j].X) {
                swap(a[j], a[j-1], dist[j], dist[j-1]);
                is_sorted = false;
              } 
              else if(a[j-1].X == a[j].X) {
                if(a[j-1].Y > a[j].Y){
                  swap(a[j], a[j-1], dist[j], dist[j-1]);
                  is_sorted = false;
                } 
                else if (a[j-1].Y == a[j].Y){
                  if(a[j-1].Z > a[j].Z){
                    swap(a[j], a[j-1], dist[j], dist[j-1]);
                    is_sorted = false;
                  }
                }
              }
            }
        } 

        if (is_sorted) return;
    } 
}

void swap(Point3D &a, Point3D &b, double &distA, double &distB){
  Point3D tempPoint = a;
  a = b; 
  b = tempPoint ;

  double temp = distA;
  distA = distB ; 
  distB = temp ;
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
