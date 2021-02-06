#include <cstdlib>     //for random number
#include <ctime>     	//for getting current time

#include <cstdio>
#include <iostream>

using namespace std;


#define MAXROW 20
#define MAXCOL 20

//Use 9 to represent a mine
#define MINE 9

struct Cell {
	int value;	//content of a cell, 0=nothing, 1 to 8=number, 9=MINE
	bool is_open; //true=open, false=hidden
};

bool is_valid(int row, int col)
{
	if (row < 0 || row >= MAXROW){
		return false;
	}

	if (col < 0 || col >= MAXCOL){
		return false;
	}

	return true;
}

void update_neighbour(Cell field[][MAXCOL], int row, int col)
{
	int i, j;

	for (i = row-1; i <= row+1; i++){
		for (j = col-1 ; j <= col+1; j++){
			if (is_valid(i, j)){
				field[i][j].value++;
			}
		}
	}

}

void plant_mine(Cell field[][MAXCOL], int nRow, int nCol, int nMine)
{
	int i, row, col;

	i = 0;
	while (i < nMine){
		row = rand() % nRow;
		col = rand() % nCol;

		//Avoid planting mine in the same place as another mine
		if (field[row][col].value < MINE ){

			// Can comment off for debugging message
			//	cout << "Planting mine at [%d][%d]\n", row, col);
			update_neighbour(field, row, col);
			field[row][col].value = MINE;

			i++;
		}
	}

}

void set_field(Cell field[][MAXCOL], int nRow, int nCol, bool set)
//Purpose: Set the open/hidden status of the entire field
{
	int i, j;

	for (i = 0; i < nRow; i++){
		for (j = 0; j < nCol; j++){
			field[i][j].is_open = set;
		}
	}
}


void print_field(Cell field[][MAXCOL], int nRow, int nCol)
{
	int i, j;

	for (i = 0; i < nRow; i++){
		for (j = 0; j < nCol; j++){
			if (field[i][j].is_open) {
				if (field[i][j].value < MINE){    
					cout << field[i][j].value;
				} else {
					cout << "M";
				}
			} else {
				//Hidden Cell
				cout << ".";
			}
		}
		cout << "\n";
	}
}

bool user_input(int nRow, int nCol, int& refRow, int& refCol)
//Purpose: Read row, column from user
//Return true if the user doesnt want to end yet
{
	printf("Open row[0-%d, -1 to end]: ", nRow-1);
	cin >> refRow;

	printf("Open column[0-%d, -1 to end]: ", nCol-1);
	cin >> refCol;

	return (refRow != -1 && refCol != -1);
}

void open_cell(Cell field[][MAXCOL], int row, int col)
{
    //Only proceed if cell is valid e.g. not out of bounds
	if(is_valid(row,col))
	{
		//If current cell is already opened, do nothing
		if(field[row][col].is_open) return;
			//Else open it up
			field[row][col].is_open = true;
		//If it is not a mine
		if(field[row][col].value == 0)
		{
			//Open neighbouring cells, e.g. up, down, left, right.
			open_cell(field,row-1,col);
			open_cell(field,row+1,col);
			open_cell(field,row,col-1);
			open_cell(field,row,col+1);
		}
	}
}

int main()
{
	Cell field[MAXROW][MAXCOL] = {{0}};
	int nRow, nCol, row, col;

	nRow = nCol = 20;

	//Uncomment the following line for real random number
	srand(time(NULL));

	//plant the mines, usually about 10% mines
	plant_mine(field, nRow, nCol, nRow*nCol / 10);

	//Reveal the field for debugging purpose
	// Comment off this section for a "real game"
	set_field(field, nRow, nCol, true);
	print_field(field, nRow, nCol);
	set_field(field, nRow, nCol, false);

	//Game start
	print_field(field, nRow, nCol);
	while( user_input(nRow, nCol, row, col) ){
		open_cell(field, row, col);
		print_field(field, nRow, nCol);
	}

	return 0;
}
