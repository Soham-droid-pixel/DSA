#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Calculate carry (bits where both are 1)
            // Cast to unsigned to handle negative numbers safely
            int carry = (unsigned)(a & b) << 1;
            
            // Calculate sum without carry (bits where they differ)
            a = a ^ b;
            
            // Update b to be the carry
            b = carry;
        }
        return a;
    }
};

int main() {
    Solution sol;
    cout << "Sum of 1 and 2: " << sol.getSum(1, 2) << endl;      // Output: 3
    cout << "Sum of -2 and 3: " << sol.getSum(-2, 3) << endl;    // Output: 1
    return 0;
}