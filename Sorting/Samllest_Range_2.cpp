#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n-1] - nums[0]; // initial range

        for (int i = 0; i < n - 1; i++) {
            int leftUp  = nums[i] + k;      // last element of left side moved up
            int rightDown = nums[i+1] - k;  // first element of right side moved down

            int high = max(nums[n-1] - k, leftUp);
            int low  = min(nums[0] + k, rightDown);

            ans = min(ans, high - low);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1};
    int k1 = 0;
    cout << "Example 1 Output: " << sol.smallestRangeII(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = {0, 10};
    int k2 = 2;
    cout << "Example 2 Output: " << sol.smallestRangeII(nums2, k2) << endl;

    // Example 3
    vector<int> nums3 = {1, 3, 6};
    int k3 = 3;
    cout << "Example 3 Output: " << sol.smallestRangeII(nums3, k3) << endl;

    return 0;
}

/*
------------------------------------------------------------
 C++ Program Explanation
------------------------------------------------------------
Problem:
Given an array nums and integer k, each element can be 
changed to nums[i] + k or nums[i] - k. The score is 
defined as max(nums) - min(nums). We need the minimum score.

Approach:
1. Sort the array.
2. Initial answer = nums[n-1] - nums[0] (no changes).
3. For each possible "cut point" i (0 <= i < n-1):
   - Left side (0..i) → add +k
   - Right side (i+1..n-1) → subtract -k
   - Compute new max and min, update answer.
4. Return the minimum answer.

Examples:
Input: nums = [1], k = 0 → Output: 0
Input: nums = [0,10], k = 2 → Output: 6
Input: nums = [1,3,6], k = 3 → Output: 3

------------------------------------------------------------
*/
