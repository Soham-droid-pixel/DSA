#include <iostream>
#include <string>
#include <algorithm> // Required for min() and swap()

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        // NOTE 1: The Loop Step
        // The problem asks us to reverse the first 'k' chars for every '2k' chars.
        // Instead of a complex nested loop, we just jump 'i' by '2 * k' each time.
        // Steps: 0, 2k, 4k, 6k...
        for(int i = 0; i < n; i += 2 * k) {
            
            // NOTE 2: Setting the Window
            // 'left' always starts at the beginning of our current chunk (i).
            int left = i;
            
            // NOTE 3: The Safety Guard (Crucial!)
            // We WANT to reverse up to 'i + k - 1'.
            // BUT if that index goes past the end of the string (n - 1),
            // we must stop at 'n - 1' to avoid a crash.
            // min() automatically picks the safer option.
            int right = min(i + k - 1, n - 1); 
            
            // NOTE 4: Two-Pointer Reversal
            // Standard swap logic to reverse the characters in the range [left, right]
            while(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

// --- Helper Code to Run and Test ---
int main() {
    Solution sol;

    // Test Case 1: Normal Case
    // "abcdefg", k=2
    // 1. i=0: Reverse first 2 chars ('ab' -> 'ba'). String: "bacdefg"
    // 2. i=4 (step 2k): Reverse 'ef' -> 'fe'. String: "bacdfe g"
    // Result: "bacdfeg"
    string s1 = "abcdefg";
    int k1 = 2;
    cout << "Test 1 (Expected: bacdfeg): " << sol.reverseStr(s1, k1) << endl;

    // Test Case 2: Fewer than k characters left at the end
    // "abcd", k=2
    // 1. i=0: Reverse 'ab' -> 'ba'. String: "bacd"
    // 2. i=4: Loop ends.
    string s2 = "abcd";
    int k2 = 2;
    cout << "Test 2 (Expected: bacd):    " << sol.reverseStr(s2, k2) << endl;

    // Test Case 3: Very small string (Edge case)
    // "a", k=2. Reverses everything because length < k.
    string s3 = "a";
    int k3 = 2;
    cout << "Test 3 (Expected: a):       " << sol.reverseStr(s3, k3) << endl;

    return 0;
}