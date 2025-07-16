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

// (Node,Left,Right)
void PreOrder(Node* node){
    if(node == nullptr) return;

    cout<<node->data<<" ";
    PreOrder(node->left);
    PreOrder(node->right);
}

// (Left,Node,Right)
void InOrder(Node* node){
    if(node == nullptr) return;

    InOrder(node->left);
    cout<<node->data<<" ";
    InOrder(node->right);
}

void IterativeInorder(Node* root){
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
    cout<<endl;
}

// (Left,Right,Node)
void PostOrder(Node* node){
    if(node == nullptr) return;

    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->data<<" ";
}


void LevelOrder(Node* root){
    vector<vector<int>> levelorder;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            level.push_back(node->data);
        }
        levelorder.push_back(level);
    }

    cout<<"Levelorder Traversal : ";
    for(auto level : levelorder){
        for(auto node : level){
            cout<<node<<" ";
        }
    }

    cout<<endl;
}

// From Left to Right
// Reference : XY-Plane (X-axis as verticals) , (Y-axis as levels)
void VerticalOrderTraversal(Node* root){
   map<int,map<int,multiset<int>>> nodes; // vertical-->level-->{set of nodes} , There can be multiple nodes at the same (vertical,level)
   queue<pair<Node*,pair<int,int>>> todo; // (node,vertical,level)
   todo.push({root,{0,0}});
   while(!todo.empty()){
      auto front = todo.front();
      todo.pop();
      Node* node = front.first;
      int x = front.second.first;
      int y = front.second.second;
      nodes[x][y].insert(node->data);
      if(node->left) todo.push({node->left,{x-1,y+1}});
      if(node->right) todo.push({node->right,{x+1,y+1}});
   }
   vector<vector<int>> verticalOrder;
   for(auto p : nodes){
    vector<int> col;
    for(auto q : p.second){
        col.insert(col.end(),q.second.begin(),q.second.end());
    }
    verticalOrder.push_back(col);
   }

   cout<<"Vertical Order Traversal : ";
   for(auto i : verticalOrder){
      for(auto j : i){
        cout<<j<<" ";
      }
   }
   cout<<endl;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);

    cout<<"PreOrder Traversal : ";
    PreOrder(root);
    cout<<endl;

    cout<<"InOrder Traversal : ";
    InOrder(root);
    cout<<endl;

    cout<<"Iterative InOrder Traversal : ";
    IterativeInorder(root);

    cout<<"PostOrder Traversal : ";
    PostOrder(root);
    cout<<endl;

    LevelOrder(root);

    VerticalOrderTraversal(root);
    return 0;
}