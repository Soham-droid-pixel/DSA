#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_result = 0;
        int mask = 0;

        // Iterate from the 31st bit down to the 0th bit
        for (int i = 31; i >= 0; i--) {
            
            // 1. Update mask to consider bits from 31 down to i
            // Example: 1000... -> 1100... -> 1110...
            mask = mask | (1 << i);
            
            // 2. Collect all prefixes of numbers using this mask
            unordered_set<int> prefixes;
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            
            // 3. GREEDY STEP:
            // Assume we CAN set the i-th bit to 1 in our result.
            // 'temp_result' is our current max plus this new hopeful bit.
            int temp_result = max_result | (1 << i);
            
            // 4. Verification:
            // Does there exist any 'prefix' in our set such that:
            // prefix ^ temp_result = [another existing prefix] ?
            // If yes, then temp_result is achievable!
            for (int prefix : prefixes) {
                if (prefixes.count(temp_result ^ prefix)) {
                    max_result = temp_result;
                    break;
                }
            }
        }
        
        return max_result;
    }
};

// --- Driver Code ---
int main() {
    Solution sol;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Max XOR: " << sol.findMaximumXOR(nums) << endl; 
    // Expected: 28
    return 0;
}