#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and max()

using namespace std;

class Solution {
public:
    /*
     * PROBLEM: Minimum Number of Removals to Make Array Balanced
     * Rule: An array is balanced if max <= min * k.
     * Goal: Remove the minimum number of elements to satisfy this rule.
     * * LOGIC IN PLAIN ENGLISH:
     * Instead of trying to figure out which numbers to remove, we try to find 
     * the LONGEST subarray that we can KEEP.
     * * 1. We SORT the array. This ensures that for any window from index i to j:
     * - nums[i] is automatically the Minimum.
     * - nums[j] is automatically the Maximum.
     * * 2. We use a SLIDING WINDOW (Two Pointers):
     * - 'j' expands the window to the right (finding new Max).
     * - 'i' shrinks the window from the left (removing small numbers) if the condition breaks.
     */
    int minRemovals(vector<int>& nums, int k) {
        // Step 1: Sort to easily find min and max in a range.
        // Once sorted, any contiguous subarray nums[i...j] has min = nums[i] and max = nums[j].
        sort(nums.begin(), nums.end());
        
        int n = nums.size(); // Total count of numbers
        int i = 0;           // Left Pointer (Start of valid window)
        int ans = 0;         // Stores the max length of a valid window found so far
        
        // Step 2: Iterate with Right Pointer 'j'
        for (int j = 0; j < n; j++) {
            
            // Step 3: Check Validity
            // Condition: max > min * k
            // current Max is nums[j]
            // current Min is nums[i]
            // We use (long long) to prevent integer overflow during multiplication.
            while ((long long)nums[j] > (long long)nums[i] * k) {
                // If invalid, shrink window from the left.
                // This effectively "removes" the smallest number to try and satisfy the condition.
                i++;
            }
            
            // Step 4: Update Best Score
            // The size of the current valid window is (j - i + 1).
            // We keep the largest size we've seen.
            ans = max(ans, j - i + 1);
        }
        
        // Step 5: Calculate Result
        // We want Minimum Removals.
        // Removals = Total Elements - Max Elements Kept
        return n - ans;
    }
};

/*
 * =========================================================
 * TRACE EXAMPLE
 * Input: nums = [1, 6, 2, 9], k = 3
 * Sorted: [1, 2, 6, 9]
 * * 1. j=0 (Val 1): 
 * Window [1]. Check: 1 <= 1*3? Yes. 
 * Valid. Size = 1. ans = 1.
 * * 2. j=1 (Val 2): 
 * Window [1, 2]. Check: 2 <= 1*3? Yes. 
 * Valid. Size = 2. ans = 2.
 * * 3. j=2 (Val 6): 
 * Window [1, 2, 6]. Check: 6 > 1*3? YES (Invalid).
 * -> Increment 'i' (remove 1). Window becomes [2, 6].
 * -> Check: 6 <= 2*3? Yes. Valid.
 * Size = 2. ans stays 2.
 * * 4. j=3 (Val 9): 
 * Window [2, 6, 9]. Check: 9 > 2*3? YES (Invalid).
 * -> Increment 'i' (remove 2). Window becomes [6, 9].
 * -> Check: 9 <= 6*3? Yes. Valid.
 * Size = 2. ans stays 2.
 * * Final Calculation: n(4) - ans(2) = 2 Removals.
 * =========================================================
 */

// --- Driver Code ---
int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 1, 5};
    int k1 = 2;
    cout << "Test Case 1 Output: " << sol.minRemovals(nums1, k1) << endl; 
    // Expected: 1 (Remove 5, keep [1, 2])

    // Test Case 2
    vector<int> nums2 = {1, 6, 2, 9};
    int k2 = 3;
    cout << "Test Case 2 Output: " << sol.minRemovals(nums2, k2) << endl; 
    // Expected: 2 (Remove 1 and 9, keep [2, 6])

    return 0;
}