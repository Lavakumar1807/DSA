#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& nums,int size,int index){
    int largest = index;
    int leftChildIndex = 2*index + 1;
    int rightChidIndex = 2*index + 2;

    if(leftChildIndex < size && nums[largest] < nums[leftChildIndex]) largest = leftChildIndex;
    if(rightChidIndex < size && nums[largest] < nums[rightChidIndex]) largest = rightChidIndex;

    if(largest != index){
        swap(nums[largest],nums[index]);
        heapify(nums,size,largest);
    }
}

void HeapSort(vector<int>& nums){
    int  size = nums.size();

    // Build Heap
    for(int i = size/2 - 1;i >= 0;i--){
        heapify(nums,size,i);
    }

    for(int i = size - 1;i > 0;i--){
        swap(nums[0],nums[i]);
        heapify(nums,i,0);
    }
}

int main(){
    int size = 0;
    cout<<"Enter size of the array : ";
    cin>>size;

    vector<int> nums;
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++){
        int number;
        cin>>number;
        nums.push_back(number);
    }

    HeapSort(nums);

    cout<<"Nums array after Heap Sort : ";
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}