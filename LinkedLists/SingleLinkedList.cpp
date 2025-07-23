#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SingleLinkedList {
    Node* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    void insertBegin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
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
    }

    void deleteBegin() {
        if (!head) return; // check if empty

        Node* current = head;
        head = head->next;
        delete current;
    }

    void deleteEnd() {
        if (!head) return;

        if (!head->next) { // Only one node
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
        cout << "Linked List : ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    void reverse(){
        Node* temp = head;
        Node* prev = nullptr;

        while(temp){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        head = prev;
    }

};

int main() {
    SingleLinkedList sll;
    sll.insertBegin(2);
    sll.insertBegin(1);
    sll.insertBegin(4);
    sll.insertEnd(5);

    sll.deleteBegin();
    sll.deleteEnd();

    sll.display();

    int size = sll.length();
    cout << "Length of the linked list : " << size << endl;

    sll.reverse();
    sll.display();

    return 0;
}