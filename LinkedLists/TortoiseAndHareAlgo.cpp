#include <bits/stdc++.h>
using namespace std;

class Node {
public : 
    int data;
    Node* next;
    
    Node(int value){
        this->data = value;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public : 
    LinkedList(){
        head = nullptr;
    }

    void insert(int value) {
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

    // Middle as the Second of Two Middles (for even-sized list)
    Node* findMiddle(){
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* detectingStartingPointOfCycle() {
        Node* slow = head;
        Node* fast = head;
    
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
    
            // Cycle detected
            if (slow == fast) {
                slow = head;
    
                // Move both one step at a time
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
    
                return slow; // starting point of the cycle
            }
        }
    
        return nullptr; // No cycle
    }
    

    void display(){
        Node* current = head;
        cout << "Linked List : ";
        while(current){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList ll;
    ll.insert(4);
    ll.insert(5);
    ll.insert(1);
    ll.insert(3);
    ll.insert(8);
    ll.insert(2);

    Node* middleNode = ll.findMiddle();
    cout << "Middle Node : " << middleNode->data << endl;

    ll.display();

    Node* startOfCycle = ll.detectingStartingPointOfCycle();
    if(startOfCycle){
        cout << "There is a cycle. Starting point : " << startOfCycle->data << endl;
    }else{
        cout << "There is no cycle detected" << endl;
    }

    return 0;
}

/*
  Hare-Tortoise algorithm is a pointer algorithm that uses only two pointers, moving through the sequence at different speeds. 
  This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. 
  The faster one is called the fast pointer and the other one is called the slow pointer.

    The Fast pointer may reach the end (NULL) which shows that there is no loop in the linked list.
    The Fast pointer again catches the slow pointer at some time therefore a loop exists in the linked list.
*/