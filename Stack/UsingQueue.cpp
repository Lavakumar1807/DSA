#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    // Push element onto stack
    void push(int x) {
        int size = q.size();
        q.push(x);  // Add new element at the back of the queue

        // Rotate the queue to move the new element to the front
        for (int i = 0; i < size; ++i) {
            int front = q.front();
            q.push(front);
            q.pop();
        }
    }

    // Pop element from the stack
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        q.pop();
    }

    // Get the top element of the stack
    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    cout << "Top after one pop: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "Stack is empty now." << endl;
    }

    return 0;
}
