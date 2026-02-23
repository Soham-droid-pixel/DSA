#include <iostream>

using namespace std;

class Solution {
public:
    // Approach 1: Your first solution using the built-in C++ function
    int hammingWeightBuiltIn(int n) {
        int count = __builtin_popcount(n);
        return count;
    }

    // Approach 2: Your optimized manual math solution
    int hammingWeightManual(int n) {
        int count = 0;
        
        while (n > 0) {
            int rem = n % 2;
            if (rem == 1) {
                count++;
            }
            n = n / 2;
        }
        
        return count;
    }
};

// --- Main Function for Testing ---
int main() {
    Solution sol;
    
    // Test cases from the problem description
    int n1 = 11;
    int n2 = 128;
    int n3 = 2147483645;

    cout << "=== Testing Approach 1: Built-in Popcount ===" << endl;
    cout << "Input: " << n1 << " -> Output: " << sol.hammingWeightBuiltIn(n1) << " (Expected: 3)" << endl;
    cout << "Input: " << n2 << " -> Output: " << sol.hammingWeightBuiltIn(n2) << " (Expected: 1)" << endl;
    cout << "Input: " << n3 << " -> Output: " << sol.hammingWeightBuiltIn(n3) << " (Expected: 30)" << endl;

    cout << "\n=== Testing Approach 2: Manual Math Loop ===" << endl;
    cout << "Input: " << n1 << " -> Output: " << sol.hammingWeightManual(n1) << " (Expected: 3)" << endl;
    cout << "Input: " << n2 << " -> Output: " << sol.hammingWeightManual(n2) << " (Expected: 1)" << endl;
    cout << "Input: " << n3 << " -> Output: " << sol.hammingWeightManual(n3) << " (Expected: 30)" << endl;

    return 0;
}