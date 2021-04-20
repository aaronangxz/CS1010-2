#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

// *** START OF SOLUTION *** //
//   BEGIN COPY FROM HERE    //


//--------
// Part A. Implement a representation of the battleship grid
//--------
struct Grid {

};


//--------
// Part B. Add a ship to the grid
//--------
bool add_ship(string name, vector<string> points, Grid & grid) {

}


//--------
// Part C. Attack a point on the grid
//--------
string attack(string point, Grid & grid) {

}




//      END COPY HERE      //
// *** END OF SOLUTION *** //

int main() {
    Grid grid;
    cout << boolalpha;  // set to print true/false for bool
    cout << add_ship("Destroyer", {"A1", "A2", "A3"}, grid) << endl;
    cout << add_ship("Submarine", {"A1", "B1"}, grid) << endl;
    cout << add_ship("Submarine", {"C1", "D1"}, grid) << endl;

    cout << attack("A1", grid) << endl;
    cout << attack("B2", grid) << endl;
    cout << attack("C1", grid) << endl;
    cout << attack("D1", grid) << endl;
    cout << attack("C1", grid) << endl;

    return 0;
}