#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;  // holds last k numbers (sliding window)

        for (int i = 0; i < nums.size(); i++) {
            // If current number already exists in the sliding window → duplicate found
            if (seen.count(nums[i])) {
                return true;
            }

            // Insert current number into the window
            seen.insert(nums[i]);

            // Keep window size <= k by removing element that is now too far behind
            if (seen.size() > k) {
                seen.erase(nums[i - k]);
            }
        }
        return false;  // No duplicates found within distance k
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << (sol.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << (sol.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << endl;

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << (sol.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << endl;

    return 0;
}

/*
========================= SUMMARY =========================

PROBLEM:
- Given an array nums and integer k.
- Return true if there exist indices i and j such that:
    nums[i] == nums[j] AND |i - j| <= k

APPROACH (Sliding Window + Hash Set):
1. Use an unordered_set (hash set) to store the last k elements only.
2. As you iterate:
   - If nums[i] is already in the set → duplicate found within range → return true.
   - Otherwise, insert nums[i].
3. If the set grows beyond size k, remove the element at index (i - k) to maintain a sliding window of size k.
4. If no duplicates found → return false.

COMPLEXITY:
- Time: O(n) → each insert/erase/count is O(1) on average.
- Space: O(min(n, k)) → set holds at most k elements.

EXAMPLE:
nums = [1,2,3,1], k = 3
- Window slides as [1], [1,2], [1,2,3], then at index 3 finds "1" again → return true.

===========================================================
*/
