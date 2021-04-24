#include <iostream>
#include <math.h>

using namespace std;

struct Pipe
{
    int height;
    Pipe *next, *alt;
};

bool can_win_multi(Pipe* p)
{
    //Base case
    if(p->next == NULL) return true;
    //If diff between current & next is ok 
    //and if the next node is okay as well
    if(abs(p->height - p->next->height <= 1) & can_win_multi(p->next)) return true;
    //If alt node is present 
    //and the diff between current & next is ok
    //and alt node is ok as well
    if(p->alt != NULL & abs(p->height - p->alt->height) <= 1 & can_win_multi(p->alt)) return true;
    return false;
}
