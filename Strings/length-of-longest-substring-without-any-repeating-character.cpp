#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_length = 0;
        unordered_set<char> seen;

        while (right < s.length()) {
            // If duplicate exists, shrink window from LEFT until it's gone
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                left++;
            }

            // Now it's safe to add the new character
            seen.insert(s[right]);
            
            // Update max length (current window size is right - left + 1)
            max_length = max(max_length, right - left + 1);
            
            right++;
        }
        
        return max_length;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb"); // Output: 3
    return 0;
}