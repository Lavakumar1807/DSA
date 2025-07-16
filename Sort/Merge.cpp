#include<bits./stdc++.h>
using namespace std;

/* Merge sort
   Time complexity : O(nlogn)
   Space complexity : O(n)
*/

void merge(vector<int>& nums,int low ,int mid,int high){
     vector<int> temp;
     int  left = low,right = mid+1;
     while(left<=mid && right<=high){
          if(nums[left]<=nums[right]){
              temp.push_back(nums[left]);
              left++;
          }
          else{
             temp.push_back(nums[right]);
             right++;
          }
     }

     while(left<=mid){
         temp.push_back(nums[left]);
         left++;
     }
     while(right<=high){
        temp.push_back(nums[right]);
        right++;
     }

     for(int j=low;j<=high;j++){
        nums[j] = temp[j-low];
     }
}

void mergesort(vector<int>& nums,int low,int high){
    if(low>=high) return;
    int mid = (low + high)/2;
    mergesort(nums,low,mid);
    mergesort(nums,mid+1,high);
    merge(nums,low,mid,high);
}

int main(){
    vector<int> nums = {3,2,4,1,3,1,2};
    mergesort(nums,0,6);
    cout<<"Merge sort..."<<endl;
    cout<<"Nums : ";
    for(int i=0;i<7;i++){
       cout<<nums[i]<<" ";
    }
    return 0;
}