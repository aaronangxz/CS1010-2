#include <iostream>
#include <vector>

using namespace std;

class Queue {
protected:
    std::vector<int> items;

public:
    virtual void enqueue(int i) {
        items.push_back(i);
    }

    virtual int dequeue() {
        int i = items[0];
        items.erase(items.begin());
        return i;
    }

    virtual int peek() {
        return items[0];
    }

    int size() {
        return items.size();
    }

    bool empty() {
        return items.size() == 0;
    }
};

// Q2A
// --- COPY BELOW INTO COURSEMOLOGY ---
class UniqueQueue : public Queue {
    // Your answer here
};
// --- COPY ABOVE INTO COURSEMOLOGY ---



// Q2B
// --- COPY BELOW INTO COURSEMOLOGY ---
class PriorityQueue : public Queue {

};
// --- COPY ABOVE INTO COURSEMOLOGY ---


// Q2C
// --- COPY BELOW INTO COURSEMOLOGY ---
class UniquePriorityQueue {
  
};
// --- COPY ABOVE INTO COURSEMOLOGY ---

// For testing
int main() {
    // Uncomment the class that you want to test
    Queue q;             // Normal queue    
    //UniqueQueue q;       // Unique queue    
    //PriorityQueue q;     // Priority queue
    //UniquePriorityQueue q; // Unique+Priority queue    

    // enqueue items into queue
    vector<int> items = {1, 4, 15, 3, 12, 11, 25, 3, 2, 4, 5, 1};
    for (auto it = items.begin(); it != items.end();)
        q.enqueue(*it++);

    // dequeue the queue
    while (!q.empty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
}