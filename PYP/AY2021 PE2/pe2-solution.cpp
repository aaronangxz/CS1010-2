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
// Note that the question only require us to make record of the point,
// it does not need us to maintain the ships in a row or col.
// So we can just use a map to record the (points, ship)
// Also, the question does not need us to keep track of which exact parts
// of the ship is destroyed. So we just keep a counter of the parts left.
struct Grid {
    map<string, string> points;  // for each point, which to ship is occupying
    map<string, int> ships;      // for each ship number of parts left
};


//--------
// Part B. Add a ship to the grid
//--------
bool add_ship(string name, vector<string> points, Grid & grid) {
    // If a point is in the map, that means it is already occupied
    for (string p : points) {
        if (grid.points.count(p)) {
            return false;
        }
    }
    // add the ship to the point map
    for (string p : points) {
        grid.points[p] = name;
    }
    // add the number of parts of the ship
    grid.ships[name] = points.size();
    return true;
}


//--------
// Part C. Attack a point on the grid
//--------
string attack(string point, Grid & grid) {
    // If the point is not in the map, then it is unoccupied
    if (grid.points.count(point) == 0) {
        return "Missed";
    }
    // get the ship at the point
    string ship = grid.points[point];
    // We set the value to empty string if the point has already been hit
    if (ship == "") {
        return "Already Hit";
    }
    // Otherwise, a good ship part is at this point
    grid.points[point] = "";  // Set it to empty string to indicate destroyed
    grid.ships[ship] -= 1;    // Decrement the number of parts left
    if (grid.ships[ship]) {   // If some parts left
        return ship + " Hit";
    } else {                  // If zero parts left
        return ship + " Sunk";
    }
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