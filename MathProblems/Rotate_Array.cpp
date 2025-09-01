#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // handle case when k >= n

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse last n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,3,4,5,6,7};
    int k1 = 3;
    sol.rotate(nums1, k1);

    cout << "After rotating by " << k1 << " steps: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    // Example 2
    vector<int> nums2 = {-1,-100,3,99};
    int k2 = 2;
    sol.rotate(nums2, k2);

    cout << "After rotating by " << k2 << " steps: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    return 0;
}
/*Why k % n?

If k is larger than the size of the array n, full rotations repeat the array.

Example: rotating 7 elements by 7, 14, 21 … times → array looks the same.

So we only need k % n rotations.

Reverse Method Logic

Rotate right by k steps:

Reverse the whole array.

Reverse the first k elements.

Reverse the remaining n-k elements.

Example:
nums = [1,2,3,4,5,6,7], k = 3

Step 1 → [7,6,5,4,3,2,1]

Step 2 (first 3) → [5,6,7,4,3,2,1]

Step 3 (last 4) → [5,6,7,1,2,3,4] ✅

Complexity

Time Complexity: O(n) → each reverse is O(n), total 3*O(n) = O(n).

Space Complexity: O(1) → done in-place, no extra array needed.

Why Interviewers Like It

Checks if candidate understands array manipulation.

Uses simple STL (reverse) efficiently.

Runs fast for large constraints (n up to 10^5).*/