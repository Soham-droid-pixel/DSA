#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        // Step 1: Handle the edge case for 0
        if (n == 0) {
            return 1;
        }

        vector<int> result;
        
        // Step 2: Extract bits (LSB goes to index 0)
        while (n > 0) {
            int rem = n % 2;
            result.push_back(rem);
            n = n / 2; // Move to the next bit
        }

        // Step 3: Flip the bits (0 becomes 1, 1 becomes 0)
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 1) {
                result[i] = 0;
            } else {
                result[i] = 1;
            }
        }

        // Step 4: Convert binary back to decimal
        int complement = 0;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 1) {
                // Since result[0] is the 2^0 bit, we use the index as the power
                complement += pow(2, i);
            }
        }

        return complement;
    }
};

int main() {
    Solution sol;

    // Test Case 1: n = 5 (Binary 101, Complement 010 -> 2)
    cout << "Input: 5 -> Output: " << sol.bitwiseComplement(5) << " (Expected: 2)" << endl;

    // Test Case 2: n = 7 (Binary 111, Complement 000 -> 0)
    cout << "Input: 7 -> Output: " << sol.bitwiseComplement(7) << " (Expected: 0)" << endl;

    // Test Case 3: n = 10 (Binary 1010, Complement 0101 -> 5)
    cout << "Input: 10 -> Output: " << sol.bitwiseComplement(10) << " (Expected: 5)" << endl;

    return 0;
}