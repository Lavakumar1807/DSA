#include <iostream>
using namespace std;

// Function to find majority element
int findMajority(int arr[], int n)
{
    int candidate = -1, votes = 0;
    // Finding majority candidate
    for (int i = 0; i < n; i++) {
        if (votes == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate)
            votes++;
        else
            votes--;
    }
    int count = 0;
    
    // Checking if majority candidate occurs more than n/2 times
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;
    return -1;
}
int main()
{
    int arr[] = { 1, 1, 1, 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int majority = findMajority(arr, n);
    cout << " The majority element is : " << majority;
    return 0;
}

/*
    Time Complexity: O(n) ( For two passes over the array )
    Space Complexity: O(1)
*/