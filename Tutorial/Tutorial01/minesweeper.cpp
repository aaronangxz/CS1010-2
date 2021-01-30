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
    //print_field(field, nRow, nCol);

    //plant the mines
    //plant_mine(field, nRow, nCol, 10);
    plant_mine_halo(field, nRow, nCol, 10);

    //after initialization
    print_field(field, nRow, nCol);

    return 0;
}



void print_field(int field[][MAXCOL], int nRow, int nCol)
{
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            if (field[i][j] < MINE)
            {
                cout << field[i][j];
            }
            else
            {
                cout << "M";
            } 
        }
        cout << endl;   
    }
}

bool valid_check(int row, int col)
{
    //If out of bounds, dont count
    if ((row >= 0 && row < MAXROW) && (col >= 0 && col < MAXCOL))    
    {
        return true;
    }
    return false;
}

void update_neighbour(int field[][MAXCOL], int row, int col)
{
    /*
             N.W   N   N.E 
               \   |   / 
                \  |  / 
            W----Cell----E 
                 / | \ 
               /   |  \ 
            S.W    S   S.E 
  
        Cell-->Current Cell (row, col) 
        N -->  North        (row-1, col) 
        S -->  South        (row+1, col) 
        E -->  East         (row, col+1) 
        W -->  West            (row, col-1) 
        N.E--> North-East   (row-1, col+1) 
        N.W--> North-West   (row-1, col-1) 
        S.E--> South-East   (row+1, col+1) 
        S.W--> South-West   (row+1, col-1)
    */
    /*    if (valid_check(row - 1,col) == true) field[row - 1][col] ++;
        if (valid_check(row + 1,col) == true) field[row + 1][col] ++;
        if (valid_check(row,col + 1) == true) field[row][col + 1] ++;
        if (valid_check(row,col - 1) == true) field[row][col - 1] ++;
        if (valid_check(row - 1,col + 1) == true) field[row - 1][col + 1] ++;
        if (valid_check(row - 1,col - 1) == true) field[row - 1][col - 1] ++;
        if (valid_check(row + 1,col + 1) == true) field[row + 1][col + 1] ++;
        if (valid_check(row + 1,col - 1) == true) field[row + 1][col - 1] ++;
    */
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if (valid_check(i,j)) field[i][j]++ ;
            }
        }
}

void plant_mine(int field[][MAXCOL], int nRow, int nCol, int nMine)
{
    int i, row, col;

    for (i = 0; i < nMine; i++)
    {
        row = rand() % nRow;
        col = rand() % nCol;
        printf("Planting mine at [%d][%d]\n", row, col);
        //Only when current cell is not a mine
        if (field[row][col] != 9)
        {
            field[row][col] = MINE;
            update_neighbour(field, row, col);  
        }
        //Otherwise generate new random cell
        else i--;
    }
}

void plant_mine_halo(int field[][MAXCOL], int nRow, int nCol, int nMine)
{
    int field_halo[MAXROW + 2][MAXCOL + 2] = {{0}};

    for (int i = 0; i < MAXROW; i++)
    {
        for (int j = 0; j < MAXCOL; j++)
        {
            field_halo[i+1][j+1] = field[i][j];
        }
    }
    
    int i, row, col;

    for (i = 0; i < nMine; i++)
    {
        row = (rand() % nRow) + 1 ;
        col = (rand() % nCol) + 1;
        printf("Planting mine at [%d][%d]\n", row, col);
    }
    field_halo[row][col] = MINE;
    for (int i = row - 1; i < row + 1; i++)
    {
        for (int j = col - 1; j < col + 1; j++)
        {
            field_halo[i][j]++;
        }
    }

    for (int i = 0; i < MAXROW; i++)
    {
        for (int j = 0; j < MAXCOL; j++)
        {
            field[i][j] = field_halo[i+1][j+1];
        }
    }
}