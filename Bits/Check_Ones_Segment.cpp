#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        // We start from the second character (index 1)
        // because the first character is guaranteed to be '1'.
        for (int i = 1; i < s.length(); i++) {
            
            // If we find the pattern "01", it means a new segment of 
            // ones has started after a gap of zeros.
            if (s[i - 1] == '0' && s[i] == '1') {
                return false; // Found more than one segment
            }
        }
        
        // If the loop finishes without finding "01", 
        // there is only one contiguous segment of ones.
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: "1001" -> False (Two segments)
    string s1 = "1001";
    cout << "Input: " << s1 << " -> Output: " << (sol.checkOnesSegment(s1) ? "true" : "false") << " (Expected: false)" << endl;
    
    // Test Case 2: "110" -> True (One segment)
    string s2 = "110";
    cout << "Input: " << s2 << " -> Output: " << (sol.checkOnesSegment(s2) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 3: "1" -> True (Single one)
    string s3 = "1";
    cout << "Input: " << s3 << " -> Output: " << (sol.checkOnesSegment(s3) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 4: "10" -> True (One segment)
    string s4 = "10";
    cout << "Input: " << s4 << " -> Output: " << (sol.checkOnesSegment(s4) ? "true" : "false") << " (Expected: true)" << endl;
    
    return 0;
}