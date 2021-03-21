#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <set>

using namespace std;

struct Airport {
    string name;
    set<Airport *> connections;
};

bool direct_connect(Airport &src, Airport &dst) 
{
    // set<Airport *> connections = src.connections;
    return src.connections.count(&dst);
}

bool indirect_connect(Airport &src, Airport &dst) 
{    
    
}

int main(void)
{

}
