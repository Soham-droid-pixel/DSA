#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        // We use i <= s.length() to catch the last word 
        // after the loop would normally end.
        for (int i = 0; i <= s.length(); i++) {
            
            // Short-circuit logic: If i is at the end, 
            // don't even look at s[i] to avoid out-of-bounds.
            if (i == s.length() || s[i] == ' ') {
                int j = i;
                
                // reverse(first, last) reverses [first, last)
                // The 'last' iterator is exclusive.
                reverse(s.begin() + start, s.begin() + j);
                
                // Move start to the first character of the next word
                start = i + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "Let's take LeetCode contest";
    cout << "Test 1 | Input: " << s1 << endl;
    cout << "Expected: s'teL ekat edoCteeL tsetnoc" << endl;
    cout << "Got     : " << sol.reverseWords(s1) << endl << endl;

    // Test Case 2
    string s2 = "Mr Ding";
    cout << "Test 2 | Input: " << s2 << endl;
    cout << "Expected: rM gniD" << endl;
    cout << "Got     : " << sol.reverseWords(s2) << endl << endl;

    // Test Case 3 (Single Word)
    string s3 = "Hello";
    cout << "Test 3 | Input: " << s3 << endl;
    cout << "Expected: olleH" << endl;
    cout << "Got     : " << sol.reverseWords(s3) << endl;

    return 0;
}