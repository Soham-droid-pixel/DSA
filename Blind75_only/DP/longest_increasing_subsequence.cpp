#include <iostream>
#include <vector>
#include <algorithm> // Required for std::lower_bound

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        // This vector will store the smallest tail of all increasing subsequences found so far.
        vector<int> tails;

        for (int x : nums) {
            // If tails is empty or x is greater than the largest element we've seen so far,
            // x successfully extends the longest increasing subsequence.
            if (tails.empty() || x > tails.back()) {
                tails.push_back(x);
            } 
            else {
                // Otherwise, find the first element in tails that is >= x.
                // std::lower_bound uses Binary Search under the hood because 'tails' is sorted.
                auto it = lower_bound(tails.begin(), tails.end(), x);
                
                // Replace that element with x to maintain the smallest possible tail.
                *it = x;
            }
        }

        // The size of the tails vector represents the length of the LIS.
        return tails.size();
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Test Case 1: " << sol.lengthOfLIS(nums1) << " (Expected: 4)" << endl; 
    // One valid LIS is [2, 3, 7, 101] or [2, 5, 7, 18]

    // Test Case 2: Multiple identical elements
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Test Case 2: " << sol.lengthOfLIS(nums2) << " (Expected: 4)" << endl; 
    // LIS is [0, 1, 2, 3]

    // Test Case 3: Strictly decreasing
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Test Case 3: " << sol.lengthOfLIS(nums3) << " (Expected: 1)" << endl; 
    // Subsequence must be STRICTLY increasing

    return 0;
}