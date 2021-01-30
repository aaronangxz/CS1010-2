#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/***********************************************************
   Part A. Planet related functions
***********************************************************/

//You can consider using the following defines to improve
// readability of your code

#define PLANET_SIZE 20

#define ALIVE 'X' 
#define DEAD 'O'

//This function is provided for you to review file stream
//Use similar idea for the save_alien_planet() function

void init_alien_planet( const char filename[], char alienPlanet[][20])
{
    ifstream inf(filename);
    char temp;
    int i, j;

    //Ensure the file can be opened
    if (!inf.is_open()){
        cout << "Error in opening file!\n";
        return;
    }

    //Proceed to read the file content into char 2D array
    for (i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            inf >> alienPlanet[i][j];
        }
    }
    inf.close();
}

void save_alien_planet(const char filename[], char matrix[][20])
{
    ofstream outf(filename);
    char temp;
    int i, j;

    //Ensure the file can be opened
    if (!outf.is_open()){
        cout << "Error in opening file!\n";
        return;
    }

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            outf << matrix[i][j];
        }
        outf << endl;
    }
    outf.close();
}

int search_neighbours(char Planet[][PLANET_SIZE+2], int i, int j)
{
    int count = 0;
    //Search neighbours
    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if(!(k == i && l == j))
            {
                if (Planet[k][l] == ALIVE  )
                {
                    count++;
                    //cout << "Count ++" << endl;
                }
            }
        }
    }
    return count;
}

void reset_planet (char alienPlanet[][PLANET_SIZE+2])
{
    for (int i = 0; i < PLANET_SIZE + 2; i++)
    {
        for (int j = 0; j < PLANET_SIZE + 2; j++)
        {
            alienPlanet[i][j] = DEAD;
        }
    }
}

void print_planet (char alienPlanet[][PLANET_SIZE])
{
    for (int i = 0; i < PLANET_SIZE ; i++)
    {
        for (int j = 0; j < PLANET_SIZE ; j++)
        {
            cout << alienPlanet[i][j];
        }
        cout << endl;
    }
}

void evolve_alien_planet(char alienPlanet[][20], int nGeneration)
{
    char Evolved[PLANET_SIZE + 2][PLANET_SIZE + 2] = {{DEAD}};

    reset_planet(Evolved);
    //Copy existing planet to halo planet
    for (int i = 0; i < PLANET_SIZE; i++)
    {
        for (int j = 0; j < PLANET_SIZE; j++)
        {
            Evolved[i+1][j+1] = alienPlanet[i][j];
        }
    }

    while (nGeneration > 0)
    {    
        //Search halo planet for living alien
        for (int i = 1; i <= PLANET_SIZE; i++)
        {
            for (int j = 1; j <= PLANET_SIZE; j++)
            {
                int liveCount = 0;
                if (Evolved[i][j] == ALIVE)
                {
                    //Search neighbours
                    liveCount = search_neighbours(Evolved,i,j);
                    //cout << "Count for " << i << "," << j << " is " << liveCount << endl;
                    //Conditions
                    if (liveCount < 2) 
                    {
                        alienPlanet[i-1][j-1] = DEAD;
                        //cout << i - 1 << "," << j - 1 << " is now dead." << endl;
                    }
                    //else if (liveCount == 2 || liveCount == 3) Evolved[i][j] = ALIVE;
                    else if (liveCount > 3) 
                    {
                        alienPlanet[i-1][j-1] = DEAD;
                        //cout << i - 1 << "," << j - 1 << " is now dead." << endl;
                    }            
                }  
                else if (Evolved[i][j] == DEAD)
                {
                    //Search neighbours
                    liveCount = search_neighbours(Evolved,i,j);
                    //cout << "Count for " << i << "," << j << " is " << liveCount << endl;
                    if (liveCount == 3) 
                    {
                        alienPlanet[i-1][j-1] = ALIVE;
                        //cout << i - 1 << "," << j - 1 << " is now alive." << endl;
                    }
                }
            }
        }
        //One generation done
        nGeneration --;
        //Copy updated alienPlanet to Evolved in order to perfomr next generation
        for (int i = 0; i < PLANET_SIZE; i++)
        {
            for (int j = 0; j < PLANET_SIZE; j++)
            {
                Evolved[i+1][j+1] = alienPlanet[i][j];
            }
        }
    }
}

/***********************************************************
   Main function
***********************************************************/

int main( )
{
	//Two points:
	//1. If you use the suggested defines above
	//    this can be written as "char myPlanet[PLANET_SIZE][PLANET_SIZE];
	//2. May want to think about easier ways to handle the
	//    boundaries....
	char myPlanet[20][20];

	/*****************
     *    Testing    *
	 *****************/
    init_alien_planet("planet_sample.txt", myPlanet);
	evolve_alien_planet( myPlanet, 3);

	//One example on how to use the save file
	save_alien_planet("myresult_gen_3.txt", myPlanet);

    return 0;
}