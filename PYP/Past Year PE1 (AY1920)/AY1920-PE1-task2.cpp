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

void flyRIGHT (char region[MAXROW][MAXCOL],int row)
{
    for (int i = 1; i < MAXCOL ; i++)
    {
        if(region[row][i] != EMPTY) region[row][i] = CROSS;
        else region[row][i] = RIGHT;
    }
}

void flyLEFT (char region[MAXROW][MAXCOL],int row)
{
    for (int i = MAXCOL - 2; i >= 0; i--)
    {
        if(region[row][i] != EMPTY) region[row][i] = CROSS;
        else region[row][i] = LEFT;
    }
}

void flyUP (char region[MAXROW][MAXCOL],int col)
{
    for (int i = MAXROW - 2; i >= 0; i--)
    {
        if(region[i][col] != EMPTY) region[i][col] = CROSS;
        else region[i][col] = UP;
    }
}

void flyDOWN (char region[MAXROW][MAXCOL],int col)
{
    for (int i = 1; i < MAXROW; i++)
    {
        if(region[i][col] != EMPTY) region[i][col] = CROSS;
        else region[i][col] = DOWN;
    }
}

void plot_trail(char region[MAXROW][MAXCOL])
{
    for (int row = 0; row < MAXROW; row++)
    {
        if (region[row][0] == RIGHT)
        {
            flyRIGHT(region,row);
        }
        if (region[row][MAXCOL - 1] == LEFT)
        {
            flyLEFT(region,row);
        }
    }

    for (int col = 0; col < MAXCOL; col++)
    {
        if (region[0][col] == DOWN)
        {
            flyDOWN(region,col);
        }
        if (region[MAXROW - 1][col] == UP)
        {
            flyUP(region,col);
        }
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
