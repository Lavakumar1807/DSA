#include <bits/stdc++.h>
using namespace std;

// Segment Tree – Range Sum Query & Point Update (0-Based Indexing)
class SegmentTree{
    int size;
    vector<int> tree;
public:
    SegmentTree(){}  // Default Constructor

    SegmentTree(vector<int>& arr){
        int n = arr.size();
        size = 4*n;
        tree.resize(size,0);
        build(0,0,n-1,arr);
    }

    void build(int node,int low,int high,vector<int>& arr){
        if(low == high){
            tree[node] = arr[low];
            return;
        }

        int mid = (low + high)/2;
        build(2*node+1,low,mid,arr);
        build(2*node+2,mid+1,high,arr);
        
        // Update according to the logic
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void update(int node,int low,int high,int index,int value){
        if(low == high){
            tree[node] = value;
            return;
        }

        int mid = (low + high)/2;
        if(index <= mid) update(2*node+1,low,mid,index,value);
        else update(2*node+2,mid+1,high,index,value);

        // Update according to the logic
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int query(int node,int low,int high,int left,int right){
        if(high < left || low > right){
            return 0; // no overlap
        }

        if(left <= low && high <= right){
            return tree[node]; // complete overlap
        }

        int mid = (low + high)/2;
        int leftQuery = query(2*node+1,low,mid,left,right);
        int rightQuery = query(2*node+2,mid+1,high,left,right);

        return leftQuery + rightQuery; // Update according to the logic
    }
};

int main(){
    vector<int> arr = {1,5,8,3,5,7,2,4};
    SegmentTree seg(arr);

    int operations;
    cout << "Number of operations : ";
    cin >> operations;

    while(operations--){
        string operation;
        cout << "What is the type of operation (update or query) : ";
        cin >> operation;
        
        if(operation == "update"){
            int index,value;
            cout << "Enter index : ";
            cin >> index;

            cout << "Enter value : ";
            cin >> value;

            seg.update(0,0,arr.size()-1,index,value);
        }else if(operation == "query"){
            int left,right;
            cout << "Enter lower bound : ";
            cin >> left;

            cout << "Enter upper bound : ";
            cin >> right;

            int value = seg.query(0,0,arr.size()-1,left,right);
            cout << "Sum of elements in range [" << left << "," << right << "] : " << value << endl; 
        }else{
            cout << "Invalid operation" << endl;
        }
    }
}