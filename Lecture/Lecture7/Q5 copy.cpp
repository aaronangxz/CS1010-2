#include <iostream>
#include<vector>;
using namespace std;

struct LinkNode 
{
    int item;
    LinkNode *next;
};

// -- DO NOT EDIT ABOVE --

struct Stack 
{
    LinkNode *top;
};

// LinkNode<int>* top = NULL;

void push(Stack &s, int item) 
{
    LinkNode *tmp;
    tmp = new LinkNode();
    tmp = s.top;
    tmp->item = item;
    s.top = tmp;
    tmp->next = s.top;
}

// Note that pop need not return the value that is popped
void pop(Stack &s) 
{
    LinkNode *tmp = NULL;
    tmp = s.top;
    s.top = s.top->next;
}

int peek(Stack &s) 
{
    return s.top->item;
}

bool empty(Stack &s) {
    // your code here  
    if (s.top == NULL) return true;
    return false ;
}
