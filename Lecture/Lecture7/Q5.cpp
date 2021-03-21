#include <iostream>
#include<vector>;
using namespace std;

template <typename T>

struct LinkNode 
{
    T item;
    LinkNode<T> *next;
};

// -- DO NOT EDIT ABOVE --
struct Stack 
{
    //LinkNode<T> *mynode;
    LinkNode<int> *first;
    LinkNode<int> *next;
    // LinkNode<int> node[];
    // vector<int> v;
    // int *first;
};

LinkNode<int>* top = NULL;

void push(Stack &s, int item) 
{
    LinkNode<int> *tmp;
    tmp = new LinkNode<int>();  
    tmp->item = item;
    tmp->next = s.next;
    s.next = tmp;
    // LinkNode<T> node = ;
    // node.item = item;
    // node.next = s->first;
    // s->first = item;
}

// Note that pop need not return the value that is popped
void pop(Stack &s) 
{
    LinkNode<int> *tmp = top;
    top = top->next;
    tmp->next = NULL;
    free(tmp);
    // s->first = s.first.next;
    // your code here      
}

int peek(Stack &s) {
    // your code here  
}

bool empty(Stack &s) {
    // your code here  
    
}

int main(void)
{

}