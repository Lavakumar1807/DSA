#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) { // first element
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) { // removing last element
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << "\n"; // 10
    cout << "Rear: " << q.getRear() << "\n";   // 30

    q.dequeue(); // removes 10
    cout << "Front after dequeue: " << q.getFront() << "\n"; // 20

    q.dequeue(); // removes 20
    q.dequeue(); // removes 30 (now empty)
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << "\n"; // Yes

    q.enqueue(40);
    cout << "Front after adding 40: " << q.getFront() << "\n"; // 40

    return 0;
}
