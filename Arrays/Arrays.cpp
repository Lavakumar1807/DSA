#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int nums[5] = {3,1,2,5,3};
    sort(nums,nums+5);
    reverse(nums,nums+5);
    cout<<"Element at index 3 : "<<nums[3]<<endl;
    
    array<int,5> a = {3,1,5,6,7};
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    vector<int> v = {4,1,4,5,6};
    v.push_back(8);
    v.push_back(6);
    v.pop_back();
    v.erase(v.begin()+1,v.begin()+3);
    cout<<"Element at index 2 : "<<v[2]<<endl;
    cout<<"Front element of the vector : "<<v.front()<<endl;
    cout<<"Last element of the vector : "<<v.back()<<endl;
    v.insert(v.begin()+3,18);
    
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<"count of element 4 : "<<count(v.begin(),v.end(),4)<<endl;
    cout<<"Minimum element in the vecrtor : "<<*min_element(v.begin(),v.end())<<endl;
    cout<<"Maximum element in the vecrtor : "<<*max_element(v.begin(),v.end())<<endl;

    cout<<"Vector : ";
    int size = v.size();
    for(int i=0;i<size;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.shrink_to_fit(); // Requests the reduction of capacity to fit the size.
    v.clear();
    cout<<"Size of vector after clearing : "<<v.size()<<endl;
    if(v.empty()) cout<<"Vector is empty"<<endl;
    else cout<<"Vector is not empty"<<endl;

    return 0;
}

/*
   std::array<type,size> arrays_name ===> This is fixed size container
   std::vector<type> vector_name ===> This is dynamic array that automatically resize when needed
*/