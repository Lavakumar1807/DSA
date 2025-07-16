#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) , where n ==> size of the array.

int main(){
    int size ;
    cout<<"Enter size of the Array : ";
    cin>>size;

    vector<int> input(size);
    cout<<"Enter Input Array : ";
    for(int i=0;i<size;i++){
        cin>>input[i];
    }

    int target ;
    cout<<"Enter Target : ";
    cin>>target;

    int i;
    for(i=0;i<size;i++){
        if(input[i] == target){
            cout<<"Target found at index : "<<i<<endl;
            break;
        }
    }

    if(i == size){
        cout<<"Target not found in the input array "<<endl;
    }
    return 0;
}