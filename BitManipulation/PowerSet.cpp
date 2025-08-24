#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(N*(2^N)) where N is the size of the array
void generateSubsets(vector<int>& nums){
    int size = nums.size();
    int totalSubsets = 1 << size; // 2^size subsets

    cout << "Total number of subsets : " << totalSubsets << endl;

    // 0 to (2^size - 1)
    for(int mask = 0; mask < totalSubsets; mask++){
        cout << "{ ";
        for(int index = 0; index < size; index++){
            // If the index-th bit is set (1) in mask, include nums[index] in the subset
            if(mask & (1 << index)){
                cout << nums[index] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter array elements : " ;
    for(int i = 0;i < size;i++){
        cin >> nums[i];
    }

    generateSubsets(nums);

    return 0;
}