#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Declare an unordered_map from int to string
    unordered_map<int, string> myMap;

    // 1. Insert elements using insert (Average O(1))
    myMap.insert({1, "Apple"});
    myMap.insert({3, "Mango"});
    myMap.insert({2, "Banana"});

    // 2. Access using [] (Average O(1)) — inserts if not present
    myMap[4] = "Orange";     // Inserts 4:Orange
    myMap[2] = "Blueberry";  // Overwrites key 2's value

    // 3. Print elements (NOT sorted) — O(n)
    cout << "Map contents:\n";
    for (auto it : myMap) {
        cout << it.first << " => " << it.second << '\n';
    }

    // 4. Find an element using find() (Average O(1))
    auto it = myMap.find(3);
    if (it != myMap.end())
        cout << "\nFound key 3 => " << it->second << '\n';

    // 5. Use at() (Average O(1))
    cout << "Value at key 1: " << myMap.at(1) << '\n';

    // 6. Check count() (Average O(1))
    cout << "Key 5 exists? " << (myMap.count(5) ? "Yes" : "No") << '\n';

    // 7. Erase by key (Average O(1))
    myMap.erase(1);

    // NOTE: unordered_map does NOT have lower_bound, upper_bound, or equal_range

    // 8. Size and Empty (O(1))
    cout << "\nSize: " << myMap.size() << '\n';
    cout << "Is empty? " << (myMap.empty() ? "Yes" : "No") << '\n';

    // 9. Swap with another map (O(1))
    unordered_map<int, string> anotherMap;
    anotherMap[10] = "Kiwi";
    anotherMap[20] = "Pineapple";

    myMap.swap(anotherMap);

    cout << "\nAfter swapping with anotherMap:\n";
    for (auto it : myMap)
        cout << it.first << " => " << it.second << '\n';

    // 10. Clear the map (O(n))
    myMap.clear();
    cout << "After clear, is map empty? " << (myMap.empty() ? "Yes" : "No") << '\n';

    return 0;
}

/*
   unordered_map<key_type, value_type> ump

   In C++, unordered_map is an unordered associative container that stores data in the form of unique key-value pairs. 
   But unlike map, unordered map stores its elements using hashing. 
   This provides average constant-time complexity O(1) for search, insert, and delete operations but the elements are not sorted in any particular order.

    Insert an element : O(1) (average)
    Delete an element by key :	O(1) (average)
    Access element by key  : O(1) (average)
    Find element by key	 : O(1) (average)
    Update element by key :	O(1) (average)
    Traverse the map :	O(n)
*/