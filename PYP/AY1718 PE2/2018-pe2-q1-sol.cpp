#include <iostream>
#include <set>

using namespace std;

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct graph {
    int size;
    node** nodes;
} graph;

int longest_chain(graph g) {
    node *start = g.nodes[0];  // record the starting node of the longest path
    int longest = 0;           // length of longest path
    for (int i = 0; i < g.size; i++) {
        node *n = g.nodes[i];  // n is the node pointer
        int l = 0;
        set<node*> visited;     // keep track of visited node to detect cycles
        
        while (n != NULL && visited.count(n) == 0) {
            visited.insert(n);  // record visited node
            n = n->next;
            l++;
        }

        if (longest < l) {  // if we found a longer cycle
            longest = l;
            start = g.nodes[i];
        }
    }

    cout << start->value;
    for (int i = 1; i < longest; i++) { // display the longest path
        start = start->next;
        cout << "->" << start->value;
        
    }
    if (start->next)  // if it has not ended, means it is a cycle
        cout << "->...";
    cout << endl;

    return longest;
}

int main() {
    graph g;
    g.size = 10;
    g.nodes = new node*[g.size];
    
    for (int i = 0; i < g.size; i++) {
        g.nodes[i] = new node{i, NULL};
    }

    g.nodes[0]->next = g.nodes[1];
    g.nodes[1]->next = g.nodes[3];
    g.nodes[2]->next = g.nodes[3];

    g.nodes[4]->next = g.nodes[5];
    g.nodes[5]->next = g.nodes[7];
    g.nodes[6]->next = g.nodes[7];
    g.nodes[7]->next = g.nodes[8];
    g.nodes[8]->next = g.nodes[9];
    g.nodes[9]->next = g.nodes[6];

    int l = longest_chain(g);
    cout << "Length: " << l << endl;
}
