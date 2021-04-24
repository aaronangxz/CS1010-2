#include <iostream>
#include <math.h>

using namespace std;

struct Pipe
{
    int height;
    Pipe *next;
};

bool can_win(Pipe* p)
{
    while(p->next)
    {
        if(abs(p->height - p->next->height) > 1) return false;
        p = p->next;
    }
    return true;
}

bool can_win_with_spring(Pipe *p)
{
    //Default is always 1 unit height
    int spring = 1;
    int diff;
    while(p->next)
    {
        //Current diff between heights
        diff = p->height - p->next->height;
        //When diff is negative, not possible to jump
        if(spring + diff < 0) return false;
        //When diff is negative, spring back to 1
        //Else spring becomes unit height to jump next
        spring = max(1,diff);
        p = p->next;
    }
    return true;
}

int main()
{
    Pipe *a, *b, *c;
    a->height = 1;
    a->next = b;
    b->height = 2;
    b->next = c;
    c->height = 5;
    c->next = NULL;

    cout << boolalpha;
    cout << can_win(a);

}