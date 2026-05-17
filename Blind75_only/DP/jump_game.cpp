#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is completely beyond our maximum possible reach,
            // it means we are trapped on a previous zero island.
            if (i > maxReachable) {
                return false;
            }
            
            // Update the furthest index we can catch from this stepping stone
            maxReachable = max(maxReachable, i + nums[i]);
            
            // Optimization: If the destination is already within sight, stop looping
            if (maxReachable >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 3, 1, 1, 4] -> Expected: true
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << boolalpha;
    cout << "Test Case 1: " << sol.canJump(nums1) << " (Expected: true)" << endl;

    // Test Case 2: [3, 2, 1, 0, 4] -> Expected: false
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test Case 2: " << sol.canJump(nums2) << " (Expected: false)" << endl;

    return 0;
}