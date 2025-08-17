#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // Step 1: Find the largest element and its index
        int largest = INT_MIN;
        int maxIndex = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                largest = nums[i];
                maxIndex = i;
            }
        }

        // Step 2: Check if largest is at least twice every other number
        for (int i = 0; i < nums.size(); i++) {
            if (i != maxIndex && largest < 2 * nums[i]) {
                return -1; // fails condition
            }
        }

        return maxIndex;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {3, 6, 1, 0};
    cout << "Output for [3,6,1,0]: " << sol.dominantIndex(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Output for [1,2,3,4]: " << sol.dominantIndex(nums2) << endl;

    return 0;
}


/*
------------------------------------
🔑 KEY NOTES (for revision)
------------------------------------

1. Step-by-step idea:
   - First pass: Find the largest element and its index.
   - Second pass: Verify if "largest >= 2 * every other element".
   - If condition holds, return the index of largest, else return -1.

2. Common mistakes to avoid:
   ❌ Initializing largest = 0 (fails if negatives allowed, safer = INT_MIN or nums[0]).
   ❌ Forgetting to skip the largest element itself in the second loop.
   ❌ Returning wrong index (make sure you store maxIndex when updating largest).

3. Time & Space Complexity:
   - Time: O(2n) → simplifies to O(n). Optimal enough.
   - Space: O(1). Perfect.

4. For optimization:
   - One-pass approach exists → track both largest and second largest in a single scan.
   - But the two-pass approach is simpler and clear for interviews.

------------------------------------
*/
