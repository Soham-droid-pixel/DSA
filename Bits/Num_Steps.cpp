#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if (bit == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }
        
        return steps + carry;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "1101";
    cout << "Input: " << s1 << " -> Output: " << sol.numSteps(s1) << " (Expected: 6)\n";
    
    // Test Case 2
    string s2 = "10";
    cout << "Input: " << s2 << " -> Output: " << sol.numSteps(s2) << " (Expected: 1)\n";
    
    // Test Case 3
    string s3 = "1";
    cout << "Input: " << s3 << " -> Output: " << sol.numSteps(s3) << " (Expected: 0)\n";
    
    return 0;
}