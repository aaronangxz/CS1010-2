#include <cstdio>
#include <iostream>

using namespace std;


#define MAXCOL 15
#define MAXROW 20

#define LEFT '<'
#define RIGHT '>'
#define UP '^'
#define DOWN 'v'
#define CROSS 'X'
#define EMPTY '-'

void print_trail(char region[MAXROW][MAXCOL], int nRow, int nCol)
{
    int i, j;

    for (i = 0; i < nRow; i++){
        for (j = 0; j < nCol; j++){
            printf("%c", region[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*********** My own functions for changing the columns and rows ***********/
void change_up_down(char region[MAXROW][MAXCOL], char direction, int col){
    for(int i = 1; i < MAXROW; i++) {
        if(region[i][col] != EMPTY) region[i][col] = CROSS;
        else region[i][col] = direction;
    }
}

void change_down_up(char region[MAXROW][MAXCOL], char direction, int col){
    for(int i = MAXROW - 2; i >= 0; i--) {
        if(region[i][col] != EMPTY) region[i][col] = CROSS;
        else region[i][col] = direction;
    }
}

void change_left_right(char region[MAXROW][MAXCOL], char direction, int row){
    for(int i = 1; i < MAXCOL; i++) {
        if(region[row][i] != EMPTY) region[row][i] = CROSS;
        else region[row][i] = direction;
    }
}

void change_right_left(char region[MAXROW][MAXCOL], char direction, int row){
    for(int i = MAXCOL - 2; i >= 0; i--) {
        if(region[row][i] != EMPTY) region[row][i] = CROSS;
        else region[row][i] = direction;
    }
}
/****************************************************************************/

void plot_trail(char region[MAXROW][MAXCOL])
{
    // plane on top can only go down, and plane at bottom can only go on top
    for(int i = 0; i < MAXCOL; i++){
        // do plane on top first
        if(region[0][i] == DOWN) change_up_down(region, DOWN, i);

        //do plane at bottom
        if(region[MAXROW-1][i] == UP) change_down_up(region, UP, i);
    }

    // plane on right can go left, and plane on left can go right
    for(int i = 0; i < MAXROW; i++){
        // do plane on left
        if(region[i][0] == RIGHT) change_left_right(region, RIGHT, i);

        //do plane at right
        if(region[i][MAXCOL-1] == LEFT) change_right_left(region, LEFT, i);
    }

}


int main()
{
    char region[MAXROW][MAXCOL] = {
        '-','-','-','-','v','-','-','^','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','P','P','E','1','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '>','-','-','-','-','-','1','-','N','O','T','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','h','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','a','-','-','-',
        '<','-','-','-','-','-','-','-','-','-','-','r','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','d','-','-','-',
        '-','-','-','-','-','-','-','@','-','-','-','!','-','-','-',
        '-','-','-','-','-','-','$','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','*','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-','^','-','-','-','-','-','>',
        '-','-','-','-','-','-','-','<','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','>','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','v','-','-','-','-','-','-','-','<',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '-','-','v','-','-','-','-','-','-','-','^','-','-','-','-'
    };

    //Before trail is plotted
    print_trail(region, MAXROW, MAXCOL); 

    plot_trail(region);

    //After trail is plotted
    print_trail(region, MAXROW, MAXCOL); 

    return 0;
}
