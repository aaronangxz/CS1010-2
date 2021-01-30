#include <cstdio>
#include <iostream>
#include <cmath>    //for sqrt()

using namespace std;

struct Point {
    int X, Y;
};


struct Line {
    //Consists of two points
    struct Point start, end;
};


void readPoint( Point& pRef );
//Purpose: Read X,Y coordinates into Point structure
//Output: The point structure referred by pptr is updated
//Return: None

void printPoint( Point& pRef );
//Purpose: Print X,Y coordinates of a Point structure
//Output: The point structure referred by pptr is printed
//Return: None


/***** For tutorial 1, to be implemented*************************/
void readLine( Line& lRef );
//Purpose: Read two points of a straight line 
//Output: The line structure lRef is updated
//Return: None

void printLine( Line& lRef );
//Purpose: Print the two points of a line structure
//Output: The line structure lRef is printed
//Return: None


double length( Line *l );
//Purpose: Calculate the length of the line, line is passed by address
//Return: Length of the line

double length2( Line& l );
//Purpose: Calculate the length of the line, line is passed by reference
//Return: Length of the line


int compareLine( Line& L1, Line& L2 );
//Purpose: Compare the length of line L1 vs line L2
//Return: an integer to indicate
//  -1 = L1 is shorter than L2
//   0 = L1 has the same length as L2
//   1 = L1 is longer than L2

int main()
{
    //Declare a line
    Line l;
    Line l2;

    //Read a line
    readLine( l ); 

    //Print a line
    printLine( l );
    
    //Simple test of length 
    cout << "Length V1: " << length(&l) << endl; 

    //Simple test of length2, notice how "l" is passed to the function 
    cout << "Length V2: " << length2(l) << endl; 

    //Simple test of compareLine, should get 3 different answers 
    l2 = l;
    cout << "Compare result = " << compareLine(l, l2) << endl;

    l2.start.X--;
    cout << "Compare result = " << compareLine(l, l2) << endl;

    l2 = l;
    l2.start.X++;
    cout << "Compare result = " << compareLine(l, l2) << endl;
    
    return 0;
}

void readPoint( Point& pRef )
{
    cout << "Enter X and Y coordinate of a point: ";
    cin >>  pRef.X >> pRef.Y;
}

void printPoint( Point& pRef )
{
    //An example of the more conveneint C-style printf() 
    printf("(%d,%d)", pRef.X, pRef.Y);
}

void readLine( Line &lRef )
{
    readPoint(lRef.start);
    readPoint(lRef.end);
}

void printLine( Line &lRef )
{
    printPoint(lRef.start);
    printPoint(lRef.end);
}

double length( Line *l )
{ 
    return sqrt(((l->end.X - l->start.X) * (l->end.X - l->start.X)) + ((l->end.Y - l->start.Y) * (l->end.Y - l->start.Y)));
    //return sqrt(pow(l->end.X - l->start.X,2) + pow(l->end.X - l->start.X,2));
}

double length2( Line& l )
{   
    return sqrt(((l.end.X - l.start.X) * (l.end.X - l.start.X)) + ((l.end.Y - l.start.Y) * (l.end.Y - l.start.Y)));
    //return sqrt(pow(l.end.X - l.start.X,2) + pow(l.end.X - l.start.X,2));
}


int compareLine( Line& L1, Line& L2 ) 
{
    if (length2(L1) > length2(L2)) return -1;
    else if (length2(L2) > length2(L1))return 1;
    else return 0;
}