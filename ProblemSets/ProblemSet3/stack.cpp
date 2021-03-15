#include <vector>

template <typename T>
struct Stack {
    std::vector<T> v;
};

template <typename T>
void push(Stack<T> &s, T item) {
    s.v.push_back(item);
}

template <typename T>
T pop(Stack<T> &s) {
    T item = s.v.back();
    s.v.pop_back();
    return item;
}

template <typename T>
T peek(Stack<T> &s) {
    return s.v.back();
}

template <typename T>
bool empty(Stack<T> &s) {
    return s.v.empty();
}

template <typename T>
void clear(Stack<T> &s) {
    s.v.clear();
}