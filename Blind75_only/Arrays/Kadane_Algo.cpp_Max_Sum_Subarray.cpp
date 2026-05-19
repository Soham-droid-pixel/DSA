#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max
#include <climits>   // Required for INT_MIN

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Track the highest global sum we have ever recorded across the timeline
        int maxGlobal = INT_MIN; 
        
        // Track the running sum of our current subarray streak
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Add the current element to our ongoing streak
            currentSum += nums[i];

            // Update the global record if our current streak just hit a new high
            maxGlobal = max(maxGlobal, currentSum);

            // KADANE'S CORE RULE: If the streak becomes negative, it's dead weight.
            // Reset it to 0 so we can start fresh from the next element.
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxGlobal;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard mixed array with a distinct peak subarray
    // Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4] -> Expected Output: 6 ([4, -1, 2, 1])
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test Case 1 Output: " << sol.maxSubArray(nums1) << " (Expected: 6)" << endl;

    // Test Case 2: Array with strictly negative numbers (Ensures INT_MIN handling works)
    // Input: [-5, -1, -3] -> Expected Output: -1 (Subarray containing just [-1])
    vector<int> nums2 = {-5, -1, -3};
    cout << "Test Case 2 Output: " << sol.maxSubArray(nums2) << " (Expected: -1)" << endl;

    return 0;
}