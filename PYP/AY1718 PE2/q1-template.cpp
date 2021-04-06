#include <iostream>

using namespace std;

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct graph {
    int size;
    node** nodes;
} graph;

// ----- COPY BELOW INTO COURSEMOLOGY ----
int longest_chain(graph g) {
    // Your answer here

}
// ----- COPY ABOVE INTO COURSEMOLOGY ----

int main() {
    // For testing. This creates the graph shown in the question
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
    //g.nodes[9]->next = g.nodes[6]; // This creates a cycle

    int l = longest_chain(g);
    cout << "Length: " << l << endl;
    return 0;
}