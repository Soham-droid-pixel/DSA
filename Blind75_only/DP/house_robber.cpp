#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge Cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Tracking variables representing historical choices
        int prev2 = 0;       // Maximum loot possible up to 2 houses ago (dp[i-2])
        int prev1 = nums[0]; // Maximum loot possible up to 1 house ago  (dp[i-1])
        
        // Start evaluating from the second house (index 1) to the end
        for (int i = 1; i < n; i++) {
            // Core DP Formula: max(skip current house, rob current house)
            int current = max(prev1, nums[i] + prev2);
            
            // Slide our historical state tracking forward
            prev2 = prev1;
            prev1 = current;
        }
        
        // At the end of the loop, prev1 holds the maximum loot possible for all n houses
        return prev1;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1: " << sol.rob(nums1) << " (Expected: 4)" << endl;

    // Test Case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test Case 2: " << sol.rob(nums2) << " (Expected: 12)" << endl;

    return 0;
}