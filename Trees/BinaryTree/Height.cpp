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

int Height(Node* node){
    if(node == nullptr) return 0;

    int leftHeight = Height(node->left);
    int rightHeight = Height(node->right);

    return 1 + max(leftHeight,rightHeight);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    int height = Height(root);
    cout<<"Height of the Tree : "<<height<<endl;
    return 0;
}