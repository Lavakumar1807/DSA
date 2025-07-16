#include<bits/stdc++.h>
using namespace std;

class Node{
public : 
   int data;
   Node* left;
   Node* right;

   Node(int value){
     data = value;
     left = nullptr;
     right = nullptr;
   }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    return 0;
}

/*
  Binary Tree is a non-linear and hierarchical data structure where each node has at most two children referred to as the left child and the right child.  
  The topmost node in a binary tree is called the root, and the bottom-most nodes are called leaves.

  Each node in a Binary Tree has three parts:
    1. Data
    2. Pointer to the left child
    3. Pointer to the right child

==> Use any below method to implement Nodes of binary tree

    // 1: Using struct
    struct Node {
        int data;
        Node* left,
        Node* right;

        Node(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    // 2: Using class
    class Node {
    public:
        int data;
        Node* left, 
        Node* right;

        Node(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Terminologies in Binary Tree
    Nodes : The fundamental part of a binary tree, where each node contains data and link to two child nodes.
    Root : The topmost node in a tree is known as the root node. It has no parent and serves as the starting point for all nodes in the tree.
    Parent Node : A node that has one or more child nodes. In a binary tree, each node can have at most two children.
    Child Node :  A node that is a descendant of another node (its parent).
    Leaf Node : A node that does not have any children or both children are null.
    Internal Node: A node that has at least one child. This includes all nodes except the leaf nodes.
    Depth of a Node : The number of edges from a specific node to the root node. The depth of the root node is zero.
*/