#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
    Node* head;

public:
    DoubleLinkedList() {
        head = nullptr;
    }

    void insertBegin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    void deleteBegin() {
        if (!head) return;

        Node* start = head;
        head = head->next;

        if (head) head->prev = nullptr;
        delete start;
    }

    void deleteEnd() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        Node* last = current->next;
        current->next = nullptr;
        delete last;
    }

    int length() {
        int size = 0;
        Node* current = head;
        while (current) {
            size++;
            current = current->next;
        }
        return size;
    }

    void display() {
        Node* current = head;
        cout << "Double Linked List : ";
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoubleLinkedList dll;
    dll.insertBegin(3);
    dll.insertBegin(4);

    dll.insertEnd(5);
    dll.insertEnd(8);
    dll.insertBegin(9);

    dll.deleteBegin();
    dll.deleteEnd();

    dll.display();
    cout << "Length of the Double Linked List : " << dll.length() << endl;

    return 0;
}