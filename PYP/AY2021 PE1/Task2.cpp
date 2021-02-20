#include <cstdio>
#include <iostream>

using namespace std;

#define MAXCOL 10
#define MAXROW 10

void print_map(bool map[][MAXCOL], int nRow, int nCol)
{
    int i, j;

    for (i = 0; i < nRow; i++){
        for (j = 0; j < nCol; j++){
            if (map[i][j]){ // Occupied
                cout << '@';
            } else {
                cout << '.';  //Not occupied
            }
        }
        cout << endl;
    }
    cout << endl;
}

/*****************************************************
 * You are ALLOWED to define additional functions for this task
 * Remember to paste all _additional_ functions for the task during submission
 ****************************************************/
int violateSD(bool map[][MAXCOL], int row, int col)
//Purpose: check whether the person at [row][col] violates social distancing
//Return:
//     if [row][col] is not occupied, return 0
//     Otherwise, count the number of occupied locaions around [row][col] in 
//        the "Fat-Cross" shape as described in question sheet
{
    return 0;  //remember to change this
}


int main()
{
    //Boolean 2D array. Note that 0 = false, 1 = true
    // true means the space is occupied, false means empty
    bool map[MAXROW][MAXCOL] = {
        { 1, 1, 0, 0, 0, 1, 0, 0, 1, 1 },   //row 0
        { 1, 0, 1, 0, 0, 1, 0, 0, 0, 1 },   //row 1
        { 0, 1, 1, 0, 0, 0, 1, 1, 0, 1 },   //row 2
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },   //row 3
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 4
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 5
        { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 6
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 7
        { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },   //row 8
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }    //row 9
    };

    print_map(map, MAXROW, MAXCOL);

    cout << violateSD(map, 4, 0) << endl; //Is anyone there?
    cout << violateSD(map, 6, 5) << endl; //Wow, looks like a full gathering there!
    cout << violateSD(map, 0, 0) << endl; //the person at upper left
    cout << violateSD(map, 0, 8) << endl; //the person near upper right
    cout << violateSD(map, 6, 1) << endl;

    return 0;
}