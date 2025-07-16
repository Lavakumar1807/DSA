// BST - Binary Search Tree
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

void InsertNode(Node* root,int value){
    Node* temp = root;
    while(true){
        if(temp->left == nullptr && temp->data > value){
            temp->left = new Node(value);
            break;
        }else if(temp->right == nullptr && temp->data < value){
            temp->right = new Node(value);
            break;
        }
        if(temp->data > value){
            temp = temp->left;
        }else temp = temp->right;
    }
}

bool searchElement(Node* root,int target){
    if(root == nullptr) return false;
    Node* temp = root;
    while(temp != nullptr){
        if(temp->data == target){
            return true;
        }
        if(temp->data > target){
            temp = temp->left;
        }else temp = temp->right;
    }

    return false;
}

void Inorder(Node* node){
    if(node == nullptr) return ;

    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

int main(){
    Node* root = new Node(8);
    InsertNode(root,3);
    InsertNode(root,10);
    InsertNode(root,6);
    InsertNode(root,4);
    InsertNode(root,14);
    InsertNode(root,13);
    InsertNode(root,1);
    InsertNode(root,7);

    Inorder(root); // This has to print the tree in sorted order as it is BST
    cout<<endl;

    int target = 13;
    if(searchElement(root,target)){
        cout<<"Target present in the tree"<<endl;
    }else cout<<"Target not present"<<endl;

    return 0;
}

/*
   1) Left Child Value < Node Value < Rigt Child Value
   2) Left subtree is also a BST
   3) Right subtree is also a BST

   A Binary Search Tree (BST) is a data structure used in computer science for organizing and storing data in a sorted manner.
   Each node in a Binary Search Tree has at most two children, a left child and a right child, with the left child containing values less than the parent node and the right child containing values greater than the parent node.
   This hierarchical structure allows for efficient searching, insertion, and deletion operations on the data stored in the tree.

   Binary search tree follows all properties of binary tree and for every nodes, its left subtree contains values less than the node and the right subtree contains values greater than the node. 
*/