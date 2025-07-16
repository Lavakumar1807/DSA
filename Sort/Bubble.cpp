#include<bits./stdc++.h>
using namespace std;

/*  Bubble sort
    Time complexity : O(n^2)
    Space complexity : O(1);
    It is a STABLE algorithm
*/

int main(){
    vector<int> nums = {2,5,1,6,8,2,3};
    bool swapped;
    for(int i=0;i<7-1;i++){
        swapped = false;
        for(int j=0;j<7-i-1;j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped = true;
            }
        }
        if(swapped==false) break;
    }
    for(int i=0;i<7;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}