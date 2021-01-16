#include <cstdio>       //for printf()
#include <iostream>
#include <cstdlib>    //for random number generator, rand()

using namespace std;

#define MAXROW 20
#define MAXCOL 20

//Use 9 to represent a mine
#define MINE 9

void print_field(int field[][MAXCOL], int nRow, int nCol);
//Purpose: Display (print) a minefield of nRow x nCol
//         Mines are printed as "M"
//         Non-Mines are printed as a single digit, representing
//             number of near-by mines


void plant_mine(int field[][MAXCOL], int nRow, int nCol, int nMine);
//Purpose: Add nMine mines randomly in a field of nRow X nCol
//Note:    Does not use the "halo" approach.


void update_neighbour(int field[][MAXCOL], int row, int col);
//Purpose: Update the count in the 8 neighbouring cells of [row][col]


void plant_mine_halo(int field[][MAXCOL], 
                        int nRow, int nCol, int nMine);
//Purpose: Add nMine mines randomly in a field of nRow X nCol
//Note:    Use the "halo" approach to simplify border checking



int main()
{
    int field[MAXROW][MAXCOL] = {{0}};
    int nRow, nCol;

    nRow = nCol = 20;

    //before initialization
    print_field(field, nRow, nCol);

    //plant the mines
    //plant_mine(field, nRow, nCol, 10);
    plant_mine_halo(field, nRow, nCol, 10);

    //after initialization
    print_field(field, nRow, nCol);

    return 0;
}

void print_field(int field[][MAXCOL], int nRow, int nCol)
{

}

void update_neighbour(int field[][MAXCOL], int row, int col)
{

}

void plant_mine(int field[][MAXCOL], int nRow, int nCol, int nMine)
{
    int i, row, col;

    for (i = 0; i < nMine; i++){
        row = rand() % nRow;
        col = rand() % nCol;
        printf("Planting mine at [%d][%d]\n", row, col);
        field[row][col] = MINE;
        update_neighbour(field, row, col);  
    }

}

void plant_mine_halo(int field[][MAXCOL], int nRow, int nCol, int nMine)
{
}


