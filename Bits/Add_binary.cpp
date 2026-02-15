#include <iostream>
#include <string>
#include <algorithm> // Required for reverse()

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string sum = ""; // This will store our result (backwards at first)
        
        // ---------------------------------------------------------
        // Step 1: Padding (Make strings equal length)
        // ---------------------------------------------------------
        // By adding leading zeros, we ensure both strings have the same number 
        // of characters. This prevents "out of bounds" errors later.
        // Example: a="11", b="1" -> becomes a="11", b="01"
        while(a.length() < b.length()) {
            a = "0" + a;
        }
        while(b.length() < a.length()) {
            b = "0" + b;
        }
        
        int n = a.length(); // Now 'n' is the length for BOTH strings

        // ---------------------------------------------------------
        // Step 2: Iterate Backwards (Right to Left)
        // ---------------------------------------------------------
        // We start from the last character (Least Significant Bit)
        for(int i = n - 1; i >= 0; i--) {
            // Convert characters '0' or '1' into integers 0 or 1
            int digitA = a[i] - '0'; 
            int digitB = b[i] - '0';
            
            // Calculate the total sum for this column including carry
            int total = digitA + digitB + carry;
            
            // -----------------------------------------------------
            // Step 3: Explicit Logic for Sum and Carry
            // -----------------------------------------------------
            if (total == 0) {
                // 0 + 0 = 0
                sum += '0';
                carry = 0;
            }
            else if (total == 1) {
                // 1 + 0 = 1
                sum += '1';
                carry = 0;
            }
            else if (total == 2) { 
                // 1 + 1 = 2 (Binary "10") -> Write 0, Carry 1
                sum += '0';
                carry = 1;
            }
            else if (total == 3) { 
                // 1 + 1 + Carry(1) = 3 (Binary "11") -> Write 1, Carry 1
                sum += '1';
                carry = 1;
            }
        }

        // ---------------------------------------------------------
        // Step 4: Handle Remaining Carry
        // ---------------------------------------------------------
        // If we finished the loop but still have a carry (e.g., 1+1 = 10),
        // we need to add that final '1' to the result.
        if (carry == 1) {
            sum += '1';
        }
        
        // ---------------------------------------------------------
        // Step 5: Reverse Final String
        // ---------------------------------------------------------
        // Since we added digits from right to left (LSB to MSB), our 
        // 'sum' string is currently backwards. We reverse it to fix this.
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};

// --- Main Function for Testing in VS Code ---
int main() {
    Solution sol;

    // Test Case 1: Simple addition
    string a1 = "11";
    string b1 = "1";
    cout << "Test Case 1:" << endl;
    cout << "Input:  a = " << a1 << ", b = " << b1 << endl;
    cout << "Output: " << sol.addBinary(a1, b1) << " (Expected: 100)" << endl;
    cout << "---------------------------" << endl;

    // Test Case 2: Carry over multiple digits
    string a2 = "1010";
    string b2 = "1011";
    cout << "Test Case 2:" << endl;
    cout << "Input:  a = " << a2 << ", b = " << b2 << endl;
    cout << "Output: " << sol.addBinary(a2, b2) << " (Expected: 10101)" << endl;
    cout << "---------------------------" << endl;

    // Test Case 3: Uneven lengths
    string a3 = "111";
    string b3 = "1"; // Will be padded to "001"
    cout << "Test Case 3:" << endl;
    cout << "Input:  a = " << a3 << ", b = " << b3 << endl;
    cout << "Output: " << sol.addBinary(a3, b3) << " (Expected: 1000)" << endl;

    return 0;
}