#include<bits/stdc++.h>
using namespace std;

/* 
   Insertion sort 
   Time complexity : O(n*n);
*/
int main(){
    vector<int> nums = {4,1,4,7,8,2,6};
    int n = nums.size();

    for(int i=1;i<n;i++){
        int temp = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>temp){
            nums[j+1]  = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

/*
   Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list
   Time complexity : Best = O(n) 
                     Avg = O(n*n)
                     Worst = O(n*n)
    It is a STABLE algorithm
*/