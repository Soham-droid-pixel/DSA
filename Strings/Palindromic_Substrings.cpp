#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int totalCount = 0;
        
        for(int i = 0; i < s.length(); i++) {
            // Check Odd (e.g., "aba")
            totalCount += expand(s, i, i);
            
            // Check Even (e.g., "abba")
            totalCount += expand(s, i, i + 1);
        }
        return totalCount;
    }

    // Helper: Expands pointers outward and counts valid palindromes
    int expand(string& s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;    // Found one!
            left--;     // Go left
            right++;    // Go right
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    string s1 = "abc";
    cout << "Input: abc -> Output: " << sol.countSubstrings(s1) << endl; 
    // Expected: 3 ("a", "b", "c")

    string s2 = "aaa";
    cout << "Input: aaa -> Output: " << sol.countSubstrings(s2) << endl; 
    // Expected: 6 ("a", "a", "a", "aa", "aa", "aaa")

    return 0;
}