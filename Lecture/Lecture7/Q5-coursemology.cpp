template <typename T>

struct LinkNode 
{
    T item;
    LinkNode<T> *next;
};

// -- DO NOT EDIT ABOVE --
LinkNode *head;
LinkNode *tail;

struct Stack 
{
    //LinkNode<T> *mynode;
    // LinkNode<int> *first;
    LinkNode<int> *next;    
    // LinkNode[] node;
    // int *first;
    int  top;
};

// LinkNode<int>* top = NULL;

void push(Stack &s, int item) 
{
    LinkNode<int> *tmp;
    tmp = new LinkNode<int>();
    tmp->item = item;
    tmp->next = s.next;
    s.next = tmp;
    //  LinkNode<T> node = ;
    // node.item = item;
    // node.next = s->first;
    // s->first = item;
    s.top++;
}

// Note that pop need not return the value that is popped
void pop(Stack &s) 
{
    // LinkNode<int> *tmp = top;
    // tmp = top->next;
    // tmp->next = NULL;
    // free(tmp);
    // s->first = s.first.next;
    // your code here      
    s.top--;
}

int peek(Stack &s) {
    // your code here  

    LinkNode<int> *a;
    a = new LinkNode<int>();
    
    a = s.next;
    int result = 0;
    
    while ( a != NULL ) 
    {
        if (a->item != NULL)
        {
            result = a->item;
            a = a->next;
        }
        
    }
    return result;
    
}

bool empty(Stack &s) {
    // your code here  
    if (s.top == 0) return true;
    
    return false ;
}
