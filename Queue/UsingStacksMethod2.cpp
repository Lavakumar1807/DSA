#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue: O(1)
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue: Amortized O(1), worst O(n)
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (s2.empty()) {
            // Move all elements from s1 → s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get front element
    int getFront() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Check if empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << "\n"; // 10

    q.dequeue(); // removes 10
    cout << "Front after dequeue: " << q.getFront() << "\n"; // 20

    q.enqueue(40);
    cout << "Front after enqueue(40): " << q.getFront() << "\n"; // 20

    q.dequeue();
    q.dequeue();
    cout << "Front after removing more: " << q.getFront() << "\n"; // 40

    return 0;
}
