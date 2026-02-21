#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            int bits = __builtin_popcount(i);
            
            if (bits == 2 || bits == 3 || bits == 5 || bits == 7 || 
                bits == 11 || bits == 13 || bits == 17 || bits == 19) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    int left1 = 6, right1 = 10;
    int left2 = 10, right2 = 15;

    cout << "Test Case 1 (left=6, right=10):" << endl;
    cout << "Output: " << sol.countPrimeSetBits(left1, right1) << " (Expected: 4)\n" << endl;

    cout << "Test Case 2 (left=10, right=15):" << endl;
    cout << "Output: " << sol.countPrimeSetBits(left2, right2) << " (Expected: 5)\n" << endl;

    return 0;
}