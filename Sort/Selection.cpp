#include<bits/stdc++.h>
using namespace std;

/*
   Selection sort 
   Time complexity : O(n*n)
   It is not a STABLE algorithm
*/
int main(){
    vector<int> nums = {4,1,3,7,2,2,9};
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        int min = i;
        // find the minimum
        for(int j=i;j<n;j++){
            if(nums[min] > nums[j]){
                min = j;
            }
        }
        // swap minimum with current element
        swap(nums[min],nums[i]);
    }
    
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}