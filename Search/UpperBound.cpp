#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(logn) , where n ==> size of the array
// This Algorithm works for sorted search space only
// Upper Bound :: smallest index such that : input[index] > target

void UpperBound(vector<int>& input,int target){
    int size = input.size();
    int low = 0;
    int high = size - 1 ;
    int upperBoundIndex = size;

    while(low <= high){
        int mid  = low + (high - low)/2;

        if(input[mid] > target){
            high = mid - 1;
            upperBoundIndex = mid;
        }else{
            low = mid + 1;
        }
    }

    cout<<"Upper Bound Index : "<<upperBoundIndex<<endl;
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

    UpperBound(input,target);

    /*
       // Inbuilt Upper Bound (STL version)
       
        int upperBoundIndex = upper_bound(input.begin(), input.end(), target) - input.begin();
        cout << "Upper Bound Index using STL: " << upperBoundIndex << endl;
    */
    return 0;
}