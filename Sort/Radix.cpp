#include<iostream>
#include<vector>
using namespace std;

/* 
    RadixSort : Radix Sort is a linear sorting algorithm that sorts elements by processing them digit by digit.
               It is an efficient sorting algorithm for integers or strings with fixed-size keys. 
    Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by the individual digits which share the same significant position and value.
    Time Complexity : O(d*(n+b))  where d is the number of digits, n is the number of elements, and b is the base of the number system being used.
    Space complexity : O(n+b) where n is the number of elements and b is the base of the number system.
    
*/
void CountingSort(vector<int> &nums,int size,int exp){
    vector<int> outputArray(size);
    vector<int> count(10,0);

    for(int i=0;i<size;i++){
        count[(nums[i]/exp)%10]++;
    }
    
    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    for(int i=size-1;i>=0;i--){
        outputArray[count[(nums[i]/exp)%10]-1] = nums[i];
        count[(nums[i]/exp)%10]--;
    }

    for(int i=0;i<size;i++){
        nums[i] = outputArray[i];
    }
}

void RadixSort(vector<int> &nums){
    int size = nums.size();
    int maxElement = nums[0];
    for(int i=0;i<size;i++){
        maxElement = max(maxElement,nums[i]);
    }

    for(int exp=1;(maxElement/exp)>0 ;exp*=10){
        CountingSort(nums,size,exp);
    }
}
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter array : ";
    for(int i=0;i<n;i++) cin>>nums[i];

    RadixSort(nums);
    cout<<"Array : ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}