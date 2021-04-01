#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

// *** START OF SOLUTION *** //
//   BEGIN COPY FROM HERE    //
#define CLASS

class Snake {
// your code here

};

//      END COPY HERE      //
// *** END OF SOLUTION *** //


//*** START OF HELPER FUNCTIONS ***//
// Do not edit or copy into Coursemology //

// Get the state from the snake and draws a row x column grid
void display(Snake &s, int row, int col) {
    //vector<vector<bool>> grid = vector<vector<bool>>(NROW, vector<bool>(NCOL, false));
    vector<vector<bool>> grid = vector<vector<bool>>(row, vector<bool>(col, false));
    s.get_state(grid);
    for (auto row : grid) {
        for (bool b : row) {
            cout << (b ? '*' : '.');  // display * for snake, . for empty
        }
        cout << endl;
    }
    cout << endl;
}

void play(int length, int row, int col, string moves) {
    bool grow = false;
    Snake s(length, row, col);    
    display(s, row*2, col*2);
    for (char c : moves) {
        if (c == '+') {
            grow = true;
            continue;
        }
        usleep(500000);
        s.move(c, grow);
        grow = false;              
        display(s, row*2, col*2);
    }
}
//*** END OF HELPER FUNCTIONS ***//

int main() {
    Snake s(5, 3, 1);

    display(s, 7, 7);
    s.move('s', false);

    s.move('s', false);
    display(s, 7, 7);

    s.move('e', false);
    display(s, 7, 7);

    s.move('e', true);
    display(s, 7, 7);

    s.move('n', false);
    display(s, 7, 7);

    // This function moves the snake according to the given string
    // + means to grow when moving in the following direction.
    // You can uncomment to test a longer sequence of moves
    // play(4, 3, 3, "sse+en+n+w+ww");

    return 0;
}
