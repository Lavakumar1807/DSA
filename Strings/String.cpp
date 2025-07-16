#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    
    // 1. Concatenation
    string s3 = s1 + " " + s2;
    cout << "Concatenated: " << s3 << endl;

    // 2. Append
    s1.append(" Everyone");
    cout << "Appended: " << s1 << endl;

    // 3. Length / Size
    cout << "Length: " << s1.length() << ", Size: " << s1.size() << endl;

    // 4. Access characters
    cout << "First character: " << s1[0] << ", Last character: " << s1[s1.size()-1] << endl;

    // 5. Substring
    string sub = s1.substr(6, 8);  // start at index 6, length 8
    cout << "Substring: " << sub << endl;

    // 6. Find substring
    int pos = s1.find("Everyone");
    int size = s1.size();
    if (pos < size)
        cout << "'Everyone' found at position : " << pos << endl;
    else
        cout << "'Everyone' not found!" << endl;

    // 7. Replace
    s1.replace(6, 8, "All");
    cout << "After replace: " << s1 << endl;

    // 8. Erase
    s1.erase(5, 4);  // remove 4 chars from index 5
    cout << "After erase: " << s1 << endl;

    // 9. Insert
    s1.insert(5, " Dear");
    cout << "After insert: " << s1 << endl;

    // 10. Compare
    string a = "apple", b = "banana";
    if (a < b) cout << a << " comes before " << b << endl;

    // 11. Reverse
    reverse(s1.begin(), s1.end());
    cout << "Reversed: " << s1 << endl;

    // 12. Sort
    string sorted = s2;
    sort(sorted.begin(), sorted.end());
    cout << "Sorted s2: " << sorted << endl;

    // 13. Convert to upper/lower case
    string temp = "HeLLo";
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    cout << "Lowercase: " << temp << endl;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    cout << "Uppercase: " << temp << endl;

    // 14. Clear string
    temp.clear();
    cout << "After clear, temp is empty? " << (temp.empty() ? "Yes" : "No") << endl;

    // 15. Input a line with spaces
    string line;
    cout << "Enter a line: ";
    getline(cin, line);
    cout << "You entered: " << line << endl;

    return 0;
}
