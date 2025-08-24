#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Pointer to array that holds stack elements
    int capacity;   // Maximum size of the stack
    int top;        // Index of the top element

public:
    // Constructor to initialize the stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1; // Indicates stack is empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push operation: add element to the top of the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    // Pop operation: remove and return the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Return a sentinel value if empty
        }
        return arr[top--];
    }

    // Peek operation: get the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack stack(3); // Create a stack of size 3

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is " << stack.peek() << endl;

    cout << "Popped element is " << stack.pop() << endl;
    cout << "Top element is " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
