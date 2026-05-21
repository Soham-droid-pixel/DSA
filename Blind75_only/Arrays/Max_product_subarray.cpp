#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max, std::min, std::swap

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Initialize our trackers with the very first element
        int maxGlobal = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        // Start looping from the second element
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            // THE SWAP TRICK: 
            // Multiplying by a negative flips the extremes. 
            // So, we swap our max and min trackers before multiplying!
            if (num < 0) {
                swap(currentMax, currentMin);
            }

            // Calculate the new max and min. 
            // We either continue the existing chain (current * num), 
            // or we reset the chain and start fresh from the current number (num).
            currentMax = max(num, currentMax * num);
            currentMin = min(num, currentMin * num);

            // Update the historical global record
            maxGlobal = max(maxGlobal, currentMax);
        }

        return maxGlobal;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard array with a negative interruption
    // Input: [2, 3, -2, 4] -> Expected Output: 6 ([2, 3])
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Test Case 1 Output: " << sol.maxProduct(nums1) << " (Expected: 6)" << endl;

    // Test Case 2: The Double Negative Trap
    // Input: [-2, 3, -4] -> Expected Output: 24 (The whole array: -2 * 3 * -4)
    vector<int> nums2 = {-2, 3, -4};
    cout << "Test Case 2 Output: " << sol.maxProduct(nums2) << " (Expected: 24)" << endl;

    // Test Case 3: Zero breaking the chain
    // Input: [-2, 0, -1] -> Expected Output: 0 (The zero resets everything)
    vector<int> nums3 = {-2, 0, -1};
    cout << "Test Case 3 Output: " << sol.maxProduct(nums3) << " (Expected: 0)" << endl;

    return 0;
}