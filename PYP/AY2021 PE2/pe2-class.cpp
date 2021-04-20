#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

// *** START OF SOLUTION *** //
//   BEGIN COPY FROM HERE    //
#define CLASS

class Grid {
// your code here

};

//      END COPY HERE      //
// *** END OF SOLUTION *** //


int main() {
    Grid grid;
    cout << boolalpha;  // set to print true/false for bool
    cout << grid.add_ship("Destroyer", {"A1", "A2", "A3"}) << endl;
    cout << grid.add_ship("Submarine", {"A1", "B1"}) << endl;
    cout << grid.add_ship("Submarine", {"C1", "D1"}) << endl;

    cout << grid.attack("A1") << endl;
    cout << grid.attack("B2") << endl;
    cout << grid.attack("C1") << endl;
    cout << grid.attack("D1") << endl;
    cout << grid.attack("C1") << endl;

    return 0;
}