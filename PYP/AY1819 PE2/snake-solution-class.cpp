#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <unistd.h>
#include <wchar.h>
#include <stdlib.h>

using namespace std;

#define NROW 7
#define NCOL 7
#define N 7

struct Snake {
Snake(int length, int row, int col);
void move(char direction, bool grow);
void get_state(vector<vector<bool>> &grid);
};


class Snake {
    struct Point {
        int x, y;
    };    
    queue<Point> body;

public:
    Snake(int length, int row, int col) {        
        Point p = {col, row};    
        for (int i=0; i<length; i++) {
            body.push(p);        
        }  
    }

    void move(char direction, bool grow) {
        Point p = body.back();
        if (direction == 'n')
            p.x--;
        if (direction == 's')
            p.x++;
        if (direction == 'w')
            p.y--;
        if (direction == 'e')
            p.y++;
        
        // add head
        body.push(p);

        // delete tail
        if (!grow)    
            body.pop();    
    }

    void get_state(vector<vector<bool>> &grid) {
        for (int i=0; i<body.size(); i++) {
            Point p = body.front();
            grid[p.x][p.y] = true;
            body.pop();
            body.push(p);
        }            
    }

};

// B. Creates a new snake of given length at row and col.
template <typename T>
Snake new_game(T length, int row, int col) {   
    return Snake(length, row, col);
}

// C. Move the snake
template <typename T>
void move(T &snake, char direction, bool grow) {
    if (Snake *s = dynamic_cast<Snake*>(&snake)){
        s->move(direction, grow);
    }
}

// D. Fill up the given grid with the current game state
//    '.' for empty, 'X' for snake
template <typename T>
void get_state(T &snake, vector<vector<bool>> &grid) {
    if (Snake *s = dynamic_cast<Snake*>(&snake)){
        s->get_state(grid);
    }
}

//*** START OF HELPER FUNCTIONS ***//
void display(Snake &s) {
    vector<vector<bool>> grid = vector<vector<bool>>(NROW, vector<bool>(NCOL, false));
    //bool grid[N][N] = {{0}};
    get_state(s, grid);
    //for (int i=0; i<NROW; i++) {
    //    for (int j=0; j<NCOL; j++) {
    for (auto row : grid) {
        for (bool b : row) {
            cout << (b ? " \\T " : " F ");
        }
        cout << "\\\\" << endl;
    }
}

void erase() {
    for (int i=0; i<N; i++) {
        //cout << "\x1b[A          \r";
        //cout << "\033[H          \r";
        //cout << "\033[2J\033[1;1H";
    }   
}

void play(int length, string moves) {
    Snake s = new_game(length, 3, 1);
    display(s);
    bool grow = false;
    for (char c : moves) {
        if (c == '+') {
            grow = true;
            continue;
        }
        usleep(500000);
        //system("CLS");
        //erase();
        cout << endl << endl;
        printf("\\cpp{move(snake, '%c', %s); get_state(snake, grid);}\\\\\n", c, grow ? "true" : "false");
        cout << "Grid contains:\\\\\\texttt{";
        move(s, c, grow);
        display(s);
        cout << "}";
        grow = false;              
    }
}
//*** END OF HELPER FUNCTIONS ***//

int main() {
    // Snake s = new_game(5);

    // move(s, 's');
    // move(s, 's');
    // move(s, 's');
    // move(s, 'e');
    // move(s, 'e');

    
    // display(s);
    // usleep(1000000);
    // erase();
    // move(s, 'n');
    // display(s);
    play(4, "sse+en+n+w+ww");

    return 0;
}