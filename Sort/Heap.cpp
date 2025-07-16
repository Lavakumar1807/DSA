#include<bits/stdc++.h>
using namespace std;

/*  Heap sort : Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure.
                It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first).
                We repeat the same process for the remaining elements.
    Time complexity - O(nlogn)
    It is an in-place algorithm
    It is unstable
*/

void heapify(vector<int>& nums, int size, int index){

    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && nums[left] > nums[largest]) largest = left;

    if (right < size && nums[right] > nums[largest]) largest = right;

    if (largest != index) {
        swap(nums[index], nums[largest]);
        heapify(nums, size, largest);
    }
}

void heapsort(vector<int> &nums){
    int size = nums.size();

    // Build heap
    for(int index = size/2 - 1;index>=0;index--){
        heapify(nums,size,index);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main(){
    vector<int> nums = { 9, 4, 3, 8, 10, 2, 5 };
    heapsort(nums);

    int size = nums.size();
    cout<<"Array after sorting  : ";
    for(int i=0;i<size;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}