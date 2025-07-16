#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(logn) , where n ==> size of the array.
// Binary Search can be applied to a sorted search space only.

void BinarySearch(vector<int>& input,int target){
    int size = input.size();
    int low = 0;
    int high = size - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(input[mid] == target){
            cout<<"Target found at index : "<<mid<<endl;
            return;
        }else if(target > input[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout<<"Target element not found in the input array"<<endl;
    return;
}

int main(){
    int size;
    cout<<"Enter size of the input array : ";
    cin>>size;

    vector<int> input(size);
    cout<<"Enter input array : ";
    for(int i=0;i<size;i++){
        cin>>input[i];
    }

    int target;
    cout<<"Enter Target : ";
    cin>>target;

    BinarySearch(input,target);

    /*
       // Inbuilt binary search
       
       bool isFound = binary_search(input.begin(),input.end(),target);
       if(isFound){
         cout<<"Target element found"<<endl;
       }else{
         cout<<"Target element not found"<<endl;
       }
    */
    return 0;
}