#include<bits/stdc++.h>
using namespace std;


/* Quick sort
   Time complexity : Best ---> O(n*logn)
                     Avg  ---> O(n*logn)
                     Worst---> O(n*n)
    Space Complexity : O(n) ==> By the recursive stack
*/
int partition(vector<int> &nums,int low,int high){
    /* For random index as pivot
       int pivotindex = low + rand()%(high-low+1);
       swap(nums[pivotindex],nums[low]);
    */

     int pivot = nums[low];
     int pi = high;

     for(int i=high;i>low;i--){
        if(nums[i] >= pivot){
            swap(nums[i],nums[pi]);
            pi--;
        }
     }

     swap(nums[low],nums[pi]);

     return pi;
}

void quicksort(vector<int>& nums,int low,int high){
    if(low<high){
        int pi = partition(nums,low,high);

        quicksort(nums,low,pi-1);
        quicksort(nums,pi+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    quicksort(nums,0,n-1);

    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    return 0;
}