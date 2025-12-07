#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
    int size;
    vector<int> bit;
public:
    FenwickTree(int size){
        this->size = size;
        bit.resize(size+1, 0);
    }

    void update(int index, int value){
        while(index <= size){
            bit[index] += value;
            index += (index & (-index));
        }
    }

    int query(int index){
        int ans = 0;
        while(index > 0){
            ans += bit[index];
            index -= (index & (-index));
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,5,8,3,5,7,2,4};
    FenwickTree fw(arr.size());

    for(int i = 0; i < arr.size(); i++) fw.update(i+1, arr[i]);

    int operations;
    cout << "Number of operations : ";
    cin >> operations;

    while(operations--){
        string operation;
        cout << "Operation (update or query) : ";
        cin >> operation;

        if(operation == "update"){
            int index, value;
            cout << "Enter index (0-based): ";
            cin >> index;

            cout << "Enter new value : ";
            cin >> value;

            fw.update(index+1, value - arr[index]);
            arr[index] = value;

        } else if(operation == "query"){
            int left, right;
            cout << "Enter left (0-based): ";
            cin >> left;

            cout << "Enter right (0-based): ";
            cin >> right;

            int result = fw.query(right+1) - fw.query(left);
            cout << "Sum of elements in range [" << left << "," << right << "] = " << result << endl;

        } else {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}
