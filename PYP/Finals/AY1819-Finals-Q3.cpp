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
    Pipe* curr = p;
    Pipe* next = p->next;

    while(curr->next != NULL)
    {
        cout << "loop" << endl;
        if(abs(curr->height - next->height) > 1) return false;
        curr = next;
        next = curr->next;
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