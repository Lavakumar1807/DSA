#include <bits/stdc++.h>
using namespace std;

// function to find the prefix sum array
vector<int> findPrefixSum(vector<int> &arr) {
    int n = arr.size();
    vector<int> prefixSum(n);

    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    return prefixSum;
}

int main() {
    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> prefixSum = findPrefixSum(arr);
    for(auto i:prefixSum) {
        cout<<i<<" ";
    }
    return 0;
}