#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getSize() {
        return size;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {   // first element
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // if queue became empty
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int getRear() {
        if (isEmpty()) return -1;
        return rear->data;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << "\n"; // 10
    cout << "Rear: " << q.getRear() << "\n";   // 30

    q.dequeue(); // removes 10
    cout << "Front after dequeue: " << q.getFront() << "\n"; // 20

    q.dequeue();
    q.dequeue();
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << "\n"; // Yes

    q.enqueue(40);
    cout << "Front after adding 40: " << q.getFront() << "\n"; // 40

    return 0;
}
