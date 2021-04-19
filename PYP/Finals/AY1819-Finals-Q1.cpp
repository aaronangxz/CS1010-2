#include <iostream>
#include <stack>
#define NCOL 5 //number of columns
#define NROW 6 //number of rows
#define EMPTY '.' //empty cell

using namespace std;
//Purpose: Move block(s) down one step in column "col" //Return: true if any block is moved, false if cannot move 
bool fall_one_step( char grid[NROW][NCOL], int col ) 
{
    stack<char> s;
    int count = 0;
    int move = 0;
    bool isFall = false;
    for(int i = 0; i < NROW ; i++)
    {
        if(grid[i][col] != EMPTY)
        {
            s.push(grid[i][col]);
            count ++;
        }
    }

    for(int j = NROW - 1; j >= 0; j--)
    {
        
        if(s.empty()) break;
        if(move <= count)
        {
            grid[j][col] = s.top();
            s.pop();
            move++;
        }
        
    }

    for(int k = NROW - 1 - count; k >= 0; k--)
    {
        grid[k][col] = EMPTY;
    }
    // if (isFall) return true;
    // return false;
}

//Purpose: Move block(s) as far as possible for ALL columns 
void apply_gravity( char grid[NROW][NCOL] )
{
    for(int i = 0; i < NCOL; i++)
    {
        fall_one_step(grid,i);
    }
}
    
int main()
{
    char grid[NROW][NCOL]; //the entire grid, declared in the main()
    grid[0][0] = '@'; grid[0][1] = '%'; grid[0][2] = 'S'; grid[0][3] = 'N'; grid[0][4] = '#';
    grid[1][0] = '@'; grid[1][1] = EMPTY; grid[1][2] = 'S'; grid[1][3] = 'N'; grid[1][4] = '#';
    grid[2][0] = EMPTY; grid[2][1] = '*'; grid[2][2] = EMPTY; grid[2][3] = EMPTY; grid[2][4] = '#';
    grid[3][0] = EMPTY; grid[3][1] = EMPTY; grid[3][2] = EMPTY; grid[3][3] = 'X'; grid[3][4] = '$';
    grid[4][0] = EMPTY; grid[4][1] = EMPTY; grid[4][2] = 'T'; grid[4][3] = EMPTY; grid[4][4] = '8';
    grid[5][0] = EMPTY; grid[5][1] = '$'; grid[5][2] = 'T'; grid[5][3] = EMPTY; grid[5][4] = '8';
    cout << boolalpha;
    apply_gravity(grid);
    // cout << fall_one_step(grid,3) << endl;
    for(int i = 0; i < NROW; i++)
    {
        for(int j = 0; j < NCOL; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}