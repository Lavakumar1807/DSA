#include<iostream>
#include<vector>
using namespace std;

/*
    Counting Sort : Counting Sort is a non-comparison-based sorting algorithm. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. 
                   The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
    Time Complxity : O(N+M) N --> size of input array , M --> size of countingArray
     Best    --> O(N+M)
     Average --> O(N+M)
     Worst   --> O(N+M)

    Space Complexity : O(N+M)
    
    Counting sort is a stable algorithm.
    Counting sort is not an In-place sorting algorithm
*/

vector<int> CountingSort(vector<int>& nums){
     int size = nums.size();
     int maxElement = nums[0];

     for(int i=1;i<size;i++){
        maxElement = max(maxElement,nums[i]); 
     }
     vector<int> countingArray(maxElement+1,0);

     for(int i=0;i<size;i++){
        countingArray[nums[i]]++;
     }

     for(int i=1;i<=maxElement;i++){
        countingArray[i] += countingArray[i-1];
     }

     vector<int> outputArray(size);

     for(int i=size-1;i>=0;i--){
        outputArray[countingArray[nums[i]]-1] = nums[i];
        countingArray[nums[i]]--;
     }

     return outputArray;
}

int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int> nums(n);

    cout<<"Enter array : ";
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<int> outputArray = CountingSort(nums);
    cout<<"Output array : ";
    for(int i=0;i<n;i++){
        cout<<outputArray[i]<<" ";
    }
    cout<<endl;
    return 0;
}