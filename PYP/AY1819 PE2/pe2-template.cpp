#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

// *** START OF SOLUTION *** //
//   BEGIN COPY FROM HERE    //


//--------
// Part A. Implement a representation of Snake
//--------
struct Snake {
    
};


//--------
// Part B. Create a new snake of given length starting at row and col
//--------
Snake new_game(int length, int row, int col) {    

}


//--------
// Part C. Move the snake
//--------
void move(Snake &snake, char direction, bool grow) {

}


//--------
// Part D. Set the given grid with the current game state
//--------
void get_state(Snake &snake, vector<vector<bool>> grid) {
    
}



//      END COPY HERE      //
// *** END OF SOLUTION *** //

//*** START OF HELPER FUNCTIONS ***//
// Do not edit or copy into Coursemology //

// Get the state from the snake and draws a row x column grid
void display(Snake &s, int row, int col) {
    //vector<vector<bool>> grid = vector<vector<bool>>(NROW, vector<bool>(NCOL, false));
    vector<vector<bool>> grid = vector<vector<bool>>(row, vector<bool>(col, false));
    get_state(s, grid);
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
    Snake s = new_game(length, row, col);    
    display(s, row, col);
    for (char c : moves) {
        if (c == '+') {
            grow = true;
            continue;
        }
        usleep(500000);
        move(s, c, grow);
        grow = false;              
        display(s, row, col);              
    }
}
//*** END OF HELPER FUNCTIONS ***//

int main() {
    Snake s = new_game(5, 3, 1);

    display(s, 7, 7);
    move(s, 's', false);

    move(s, 's', false);
    display(s, 7, 7);

    move(s, 'e', false);
    display(s, 7, 7);

    move(s, 'e', true);
    display(s, 7, 7);

    move(s, 'n', false);
    display(s, 7, 7);

    // This function moves the snake according to the given string
    // play(4, 7, 7, "sse+en+n+w+ww");

    return 0;
}