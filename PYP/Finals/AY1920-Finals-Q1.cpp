#include <iostream>
#include <vector>

using namespace std;

struct Station
{
    string name;
    vector<LineNode> lines;
};

struct LineNode
{
    Station *station;
    int distance;
    LineNode *next;
};

int distance_between(LineNode *node, Station &station)
{
    //Check station.lines for node. If yes, reachable
    // 
    //else -1
}

int distance_between (Station &a, Station &b)
{
    
}