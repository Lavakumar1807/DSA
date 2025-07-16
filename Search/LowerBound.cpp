#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(logn) , where n ==> size of the array
// This Algorithm works for sorted search space only
// Lower Bound :: smallest index such that : input[index] >= target

void LowerBound(vector<int>& input,int target){
    int size = input.size();
    int low = 0;
    int high = size - 1 ;
    int lowerBoundIndex = size;

    while(low <= high){
        int mid  = low + (high - low)/2;

        if(input[mid] >= target){
            high = mid - 1;
            lowerBoundIndex = mid;
        }else{
            low = mid + 1;
        }
    }

    cout<<"Lower Bound Index : "<<lowerBoundIndex<<endl;
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

    LowerBound(input,target);
    return 0;
}

/*
    // Inbuilt Lower Bound (STL version)

    int lowerBoundIndex = lower_bound(input.begin(), input.end(), target) - input.begin();
    cout << "Lower Bound Index using STL: " << lowerBoundIndex << endl;
*/