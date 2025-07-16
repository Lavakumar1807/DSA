#include<bits/stdc++.h>
using namespace std;

// Kadane's Algo
int maxSubArraySum(vector<int>& nums) {
    int size = nums.size();
    
    int maxSum = nums[0];  // Initialize with first element
    int currentMax = nums[0];

    for (int i = 1; i < size; ++i) {
        currentMax = max(nums[i], currentMax + nums[i]);  // extend or start new subarray
        maxSum = max(maxSum, currentMax);
    }

    /*
        int sum = 0;
        for(int i = 0;i < size;i++){
            sum += nums[i];
            maxSum = max(maxSum,sum);

            if(sum < 0) sum = 0;
        }
    */

    return maxSum;
}

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = maxSubArraySum(arr);

    cout<<"Max subarray sum : "<<maxSum<<endl;
    return 0;
}