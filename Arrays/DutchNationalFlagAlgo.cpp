// Sort an array of 0s, 1s and 2s using Dutch National Flag Algorithm

#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array of 0s, 1s and 2s
void sort012(vector<int> &nums) {
    int n = nums.size();
    int low = 0,mid = 0,high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = { 0, 1, 2, 0, 1, 2 };
    int n = nums.size();

    sort012(nums);

    for (int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}

/*
==> Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
   The idea is to sort the array of size n using three pointers: low = 0, mid = 0 and high = n - 1 such that the array is divided into three parts -

    arr[0] to arr[low - 1]: This part will have all the zeros.
    arr[low] to arr[mid - 1]: This part will have all the ones.
    arr[high + 1] to arr[n - 1]: This part will have all the twos.
    Here, low indicates the position where next 0 should be placed, mid is used to traverse through the array and high indicates the position where next 2 should be placed.

    Traverse over the array till mid <= high, according to the value of arr[mid] we can have three cases:

    arr[mid] = 0, then swap arr[low] and arr[mid] and increment low by 1 because all the zeros are till index low - 1 and move to the next element so increment mid by 1.
    arr[mid] = 1, then move to the next element so increment mid by 1.
    arr[mid] = 2, then swap arr[mid] and arr[high] and decrement high by 1 because all the twos are from index high + 1 to n - 1. Now, we don't move to the next element because the element which is now at index mid can be a 0 and therefore needs to be checked again.
*/