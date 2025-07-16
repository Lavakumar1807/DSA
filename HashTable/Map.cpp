#include <iostream>
#include <map>
using namespace std;

int main() {
    // Declare a map from int to string
    map<int, string> myMap;

    // 1. Insert elements using insert (O(log n))
    myMap.insert({1, "Apple"});
    myMap.insert({3, "Mango"});
    myMap.insert({2, "Banana"});

    // 2. Access using [] (O(log n)) — inserts if not present
    myMap[4] = "Orange";   // Inserts 4:Orange
    myMap[2] = "Blueberry"; // Overwrites key 2's value

    // 3. Print elements (in key-sorted order) — O(n)
    cout << "Map contents:\n";
    for (auto it : myMap) {
        cout << it.first << " => " << it.second << '\n';
    }

    // 4. Find an element using find() (O(log n))
    auto it = myMap.find(3);
    if (it != myMap.end())
        cout << "\nFound key 3 => " << it->second << '\n';

    // 5. Use at() (O(log n)) — throws if key not present
    cout << "Value at key 1: " << myMap.at(1) << '\n';

    // 6. Check count() (O(log n))
    cout << "Key 5 exists? " << (myMap.count(5) ? "Yes" : "No") << '\n';

    // 7. Erase by key (O(log n))
    myMap.erase(1);  // Removes key 1

    // 8. lower_bound() and upper_bound() (O(log n))
    auto lb = myMap.lower_bound(2);  // key >= 2
    if (lb != myMap.end())
        cout << "\nlower_bound(2): " << lb->first << " => " << lb->second << '\n';

    auto ub = myMap.upper_bound(2);  // key > 2
    if (ub != myMap.end())
        cout << "upper_bound(2): " << ub->first << " => " << ub->second << '\n';

    // 9. equal_range() returns pair<lower_bound, upper_bound>
    auto range = myMap.equal_range(2);
    cout << "equal_range(2): ";
    for (auto itr = range.first; itr != range.second; ++itr)
        cout << itr->first << " => " << itr->second << '\n';

    // 10. Size and Empty (O(1))
    cout << "\nSize: " << myMap.size() << '\n';
    cout << "Is empty? " << (myMap.empty() ? "Yes" : "No") << '\n';

    // 11. Swap with another map (O(1))
    map<int, string> anotherMap;
    anotherMap[10] = "Kiwi";
    anotherMap[20] = "Pineapple";

    myMap.swap(anotherMap);

    cout << "\nAfter swapping with anotherMap:\n";
    for (auto it : myMap)
        cout << it.first << " => " << it.second << '\n';

    // 12. Clear the map (O(n))
    myMap.clear();
    cout << "After clear, is map empty? " << (myMap.empty() ? "Yes" : "No") << '\n';

    return 0;
}

/*
    map<key_type, value_type> m

    In C++, maps are associative containers that store data in the form of key value pairs sorted on the basis of keys. 
    No two mapped values can have the same keys. 
    By default, it stores data in ascending order of the keys, but this can be changes as per requirement.

    Insert an element :	O(log n)
    Delete an element by key :	O(log n)
    Access element by key :	O(log n)
    Find an element by key  : O(log n)
    Update element by key :	O(log n)
    Traverse the map : O(n)
*/