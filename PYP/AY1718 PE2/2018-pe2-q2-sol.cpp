#include <iostream>
#include <vector>

using namespace std;

class Queue {
protected:
    vector<int> items;

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

/* For all three classes, we only need to override the enqueue
   method because once we get the order of the items in the queue 
   correct, the dequeue and other functions is the same.

   Or you can leave enqueue the same and override dequeue, but that
   in more complicated.
*/

// Q2A
class UniqueQueue : public Queue {
public:
    void enqueue(int i) {
        // search if i is already in queue
        for (auto it = items.begin(); it != items.end(); it++) {
            if (*it == i)
                return;  // don't do anything if item is already in queue
        }

        Queue::enqueue(i);  // otherwise let superclass enqueue
    }
};


// Q2B
class PriorityQueue : public Queue {
public:
    void enqueue(int i) {
        // linear search where to insert
        auto it = items.begin();
        while (it != items.end()) {
            if (i%10 < *it%10)  // once the index is found
                break;          // break out of the loop
            it++;
        }
        items.insert(it, i);  // insert into the position
    }
};


// Q2C
// Subclass priority queue so it will take care of the ordering
// So we only need to handle the unique part
class UniquePriorityQueue : public PriorityQueue {
  public:
    // copied from UniqueQueue
    void enqueue(int i) {
        // search if i is already in queue
        for (auto it = items.begin(); it != items.end(); it++) {
            if (*it == i)
                return;
        }

        PriorityQueue::enqueue(i);  // But call PriorityQueue's enqueue
    }    
};

int main() {
    // Normal queue
    //Queue q;
    // Unique queue
    //UniqueQueue q;
    // Priority queue
    //PriorityQueue q;
    UniquePriorityQueue q;

    vector<int> items = {1, 4, 15, 3, 12, 11, 25, 3, 2, 4, 5, 1};
    for (auto it = items.begin(); it != items.end();)
        q.enqueue(*it++);

    // dequeue the queue
    while (!q.empty()) {
        cout << q.dequeue() << ", ";
    }
    cout << endl;
}