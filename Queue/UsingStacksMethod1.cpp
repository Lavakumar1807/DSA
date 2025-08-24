#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int element) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(element);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue() {
        if (s1.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        s1.pop();
    }

    int getFront() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << "\n"; // 10

    q.dequeue();
    cout << "Front after dequeue: " << q.getFront() << "\n"; // 20

    q.enqueue(40);
    cout << "Front after enqueue(40): " << q.getFront() << "\n"; // 20

    q.dequeue();
    cout << "Front now: " << q.getFront() << "\n"; // 30

    return 0;
}
