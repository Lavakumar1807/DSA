#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

/*
    Maxheap : The value of the root node must be the greatest among all its descendant nodes and the same thing must be done for its left and right sub-tree also.
    heap --> array ( 0-indexed )
    nodevalue >= leftchild value
    nodevalue >= rightchild value
    Node index ==> i
    leftchild  ==> 2*i + 1
    rightchild ==> 2*i + 2
    parent     ==> ( i - 1 )/2
*/
class maxheap {
public : 
     int heap[MAX_SIZE];
     int size;

     maxheap(){
        size = 0;
     }

     void insertelement(int value){
        if(size == MAX_SIZE){
            cout<<"Overflow! Can't insert data"<<endl;
            return;
        }

        int index = size;
        heap[index] = value;
        size++;

        while(index > 0){
            int parent = (index - 1 )/2;
            if(heap[parent] < heap[index]){
                swap(heap[parent],heap[index]);
            }
            index = parent;
        }
        
     }

     void deleteelement(){
         if(size == 0){
            cout<<"Underflow! Heap is empty"<<endl;
            return;
         }

         int index = 0;
         heap[index] = heap[size-1];
         size--;

         while(index < size){
             int leftchild = 2*(index) + 1;
             int rightchild = 2*(index) + 2;
             int largest = index;
             if(leftchild < size && heap[largest] < heap[leftchild]) largest = leftchild;
             if(rightchild < size && heap[largest] < heap[rightchild]) largest = rightchild;
             
             if(largest != index){
                swap(heap[largest],heap[index]);
                index = largest;
             }else{
                return;
             }
         }
     }

     void display(){
        cout<<"Heap : ";
        for(int i=0;i<size;i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
     }
};

void heapify(vector<int> & nums,int size,int index){
    int leftchild = 2*index + 1;
    int rightchild = 2*index + 2;
    int largest = index;

    if(leftchild < size && nums[largest] < nums[leftchild]) largest = leftchild;
    if(rightchild < size && nums[largest] < nums[rightchild]) largest = rightchild;

    if(largest != index){
        swap(nums[largest],nums[index]);
        heapify(nums,size,largest);
    }else{
        return;
    }
}

int main(){
    maxheap mh;
    mh.insertelement(50);
    mh.insertelement(44);
    mh.insertelement(39);
    mh.deleteelement();

    mh.display();

    mh.insertelement(56);
    mh.insertelement(38);
    mh.deleteelement();

    mh.display();

    vector<int> nums  = {59,20,38,29,54,28};
    int size = nums.size();
    for(int index = size/2 - 1 ; index >= 0 ;index--){
        heapify(nums,size,index);
    }

    cout<<"Array after heapify : ";
    for(int i=0;i<size;i++) cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}

/*
   A Heap is a complete binary tree data structure that satisfies the heap property
   
   A Binary Heap is a complete binary tree that stores data efficiently, allowing quick access to the maximum or minimum element, depending on the type of heap. 
   It can either be a Min Heap or a Max Heap. 
   In a Min Heap, the key at the root must be the smallest among all the keys in the heap, and this property must hold true recursively for all nodes. 
   Similarly, a Max Heap follows the same principle, but with the largest key at the root.
*/