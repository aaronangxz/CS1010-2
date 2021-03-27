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
//Assume no cycles
bool indirect_connect(Airport &src, Airport &dst) 
{    
    if(direct_connect(src,dst)) return true;
    else
    {
        for(auto &a : src.connections)
        {
            if (indirect_connect(*a,dst)) return true;
        }
    }    
    return false;
}

bool indirect_connect_cycle(Airport &src, Airport &dst,set<Airport*> visited) 
{    
    if(direct_connect(src,dst)) return true;
    else if (visited.count(&dst) == 1) return false;
    else
    {
        visited.insert(&dst);
        for(auto &a : src.connections)
        {
            if(visited.count(a) ==1) continue;
            return indirect_connect_cycle(*a,dst,visited);
        }
    }    
    return false;
}

    /*
    if(src.connections.count(&dst)) return 1;
    set<Airport*> tmp = src.connections;
    set<Airport*> tmp1;

    cout << tmp.empty();

    for (Airport* element : tmp)
    {
        if (element->name == dst.name) return 1;
        tmp1.insert(element); 
    }

    for (Airport* element1 : tmp1)
    {
        if (element1->name == dst.name) return 1;
    }



    vector<Airport*> src_cx;
    for (Airport* element : src.connections)
    {
        cout << "Add " << element<< endl;
        src_cx.push_back(element);
    }
    

    for(int i = 0; i < src_cx.size(); i++)
    {
        cout << "Inside vector: " << &src_cx[i]->connections << endl;
    }
    
    for(int i = 0; i < src_cx.size(); i++)
    {
        // vector<Airport*> src_cxcx;
        for (Airport* element1 : src_cx[i]->connections)
        {
            cout << &src_cx[i]->connections << endl;
            // src_cxcx.push_back(element);
            if (element1->connections.count(&dst)) return 1;
            continue;
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

int main(void)
{
    Airport SIN_s;
    Airport KUL_s;
    Airport HND_s;
    Airport* SIN;
    Airport* KUL;
    Airport* HND;
    Airport* NRT;
    Airport* BKK;
    Airport* JFK;
    Airport* LHR;
    Airport* DXB;
    Airport* PEN;

    set<Airport *> SIN_connection;
    SIN_connection.insert(KUL);
    SIN_connection.insert(HND);
    SIN_connection.insert(NRT);

    set<Airport *> KUL_connection;
    KUL_connection.insert(SIN);
    KUL_connection.insert(PEN);
    KUL_connection.insert(BKK);

    set<Airport *> BKK_connection;
    BKK_connection.insert(KUL);
    BKK_connection.insert(DXB);
    BKK_connection.insert(LHR);


    SIN_s.name = "SIN";
    SIN_s.connections = SIN_connection;

    KUL_s.name = "KUL";
    KUL_s.connections = KUL_connection;

    HND_s.name = "HND";
    HND_s.connections = BKK_connection;

    set<Airport*> ::iterator itr;
    cout << "SIN" << endl;
    for (itr = SIN_connection.begin(); itr != SIN_connection.end(); itr++)  
    { 
        cout << *itr<<" "; 
    } 

    cout << endl;
    cout <<"KUL" << endl;
    for (itr = KUL_connection.begin(); itr != KUL_connection.end(); itr++)  
    { 
        cout << *itr<<" "; 
    } 

    cout << endl;
    cout << "BKK" << endl;
    for (itr = BKK_connection.begin(); itr != BKK_connection.end(); itr++)  
    { 
        cout << *itr<<" "; 
    } 

    cout << endl;
    cout << endl;
    cout << boolalpha;
    cout << "Direct connect " << direct_connect(SIN_s,KUL_s) << endl;
    cout << indirect_connect(SIN_s,KUL_s);

}
