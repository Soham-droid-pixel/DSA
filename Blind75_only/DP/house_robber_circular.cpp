#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function: Our exact O(1) space linear House Robber 1 logic
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]
        
        for (int i = start; i <= end; i++) {
            int current = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge Case: If there's only 1 house, circular logic doesn't apply
        if (n == 1) return nums[0];
        
        // Run Case 1: From first house to second-to-last house
        int skipLastHouse = robLinear(nums, 0, n - 2);
        
        // Run Case 2: From second house to absolute last house
        int skipFirstHouse = robLinear(nums, 1, n - 1);
        
        // The answer is the best outcome of both independent choices
        return max(skipLastHouse, skipFirstHouse);
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 3, 2] -> Expected: 3
    vector<int> nums1 = {2, 3, 2};
    cout << "Test Case 1: " << sol.rob(nums1) << " (Expected: 3)" << endl;

    // Test Case 2: [1, 2, 3, 1] -> Expected: 4
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Test Case 2: " << sol.rob(nums2) << " (Expected: 4)" << endl;

    return 0;
}