#include <iostream>
#include <vector>
// #include <bits/stdc++.h> 
#include <set>

using namespace std;

struct Airport 
{
    string name;
    set<Airport*> connections;
};

bool direct_connect(Airport &src, Airport &dst) 
{
    // set<Airport*> ::iterator itr;
    // set<Airport*> ::iterator itr2;
    // for (itr = src.connections.begin(); itr != src.connections.end(); itr++)  
    // { 
    //     for (itr2 = dst.connections.begin(); itr2 != dst.connections.end(); itr2++)  
    //     {
    //         if(*itr == *itr2) return 1; 
    //     }
    // }
    // return 0;
    return src.connections.count(&dst);
}

bool indirect_connect(Airport &src, Airport &dst) 
{    
    if(src.connections.count(&dst)) return 1;

    vector<Airport*> src_cx;
    for (Airport* element : src.connections)
    {
        src_cx.push_back(element);
    }
    
/*
    for(int i = 0; i < src_cx.size(); i++)
    {
        // vector<Airport*> src_cxcx;
        for (Airport* element1 : src_cx[i]->connections)
        {
            // src_cxcx.push_back(element);
            if (element1->connections.count(&dst)) return 1;
        }
        // return (src_connections_connections[i]->connections.count(&dst));

        // for(int j = 0; j < src_cxcx.size(); j++)
        // {
        //     if (src_cxcx[j]->connections.count(&dst)) return 1;
        // }

        // if (src_cxcx[i]->connections.count(&dst)) return 1;
        // else return 0;

        // return (src_cxcx[i]->connections.count(&dst));

    }       
    return 0;
    // else indirect_connect(dst, dst) ;
  */  
}

int main(void)
{
    Airport SIN_s;
    Airport KUL_s;
    Airport* SIN;
    Airport* KUL;
    Airport* HND;
    Airport* NRT;
    Airport* BKK;
    Airport* JFK;
    Airport* LHR;
    Airport* DXB;

    set<Airport *> SIN_connection;
    SIN_connection.insert(KUL);
    SIN_connection.insert(HND);
    SIN_connection.insert(NRT);

    set<Airport *> KUL_connection;
    KUL_connection.insert(SIN);
    KUL_connection.insert(HND);
    KUL_connection.insert(BKK);

    SIN_s.name = "SIN";
    SIN_s.connections = SIN_connection;

    KUL_s.name = "KUL";
    KUL_s.connections = KUL_connection;

    set<Airport*> ::iterator itr;
    // for (itr = SIN_connection.begin(); itr != SIN_connection.end(); itr++)  
    // { 
    //     cout << *itr<<" "; 
    // } 
    // cout << endl;
    // for (itr = KUL_connection.begin(); itr != KUL_connection.end(); itr++)  
    // { 
    //     cout << *itr<<" "; 
    // } 

    cout << endl;
    cout << boolalpha;
    cout << direct_connect(SIN_s,KUL_s);
    cout << indirect_connect(SIN_s,KUL_s);

}
