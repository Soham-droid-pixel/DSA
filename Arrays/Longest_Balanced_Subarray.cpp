#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // Required for max()

using namespace std;

class Solution {
public:
    /*
     * PROBLEM: Longest Balanced Subarray
     * Condition: Number of DISTINCT Even numbers == Number of DISTINCT Odd numbers.
     * * STRATEGY: Brute Force (O(N^2))
     * 1. Iterate through every possible start index 'i'.
     * 2. Iterate through every possible end index 'j'.
     * 3. Maintain a Set to track distinct numbers in the current window [i...j].
     * 4. Count distinct evens and odds.
     * 5. If counts match, update maxLen.
     */
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        // Try every possible starting position 'i'
        for (int i = 0; i < n; i++) {
            int odd = 0;
            int even = 0;
            unordered_set<int> seen; // Clear set for every new start point

            // Expand the window to the right 'j'
            for (int j = i; j < n; j++) {
                
                // Only process if we haven't seen this number in the current subarray
                // .find() checks if the element exists in the set
                if (seen.find(nums[j]) == seen.end()) {
                    seen.insert(nums[j]); // Mark as seen
                    
                    if (nums[j] % 2 != 0) {
                        odd++;
                    } else {
                        even++;
                    }
                }

                // Check condition: Distinct Evens == Distinct Odds
                // IMPORTANT: We check this at every step 'j', even if the number wasn't new.
                // Example: [2, 3, 2].
                // j=0 (2): Even=1, Odd=0.
                // j=1 (3): Even=1, Odd=1. Balanced! Len=2.
                // j=2 (2): Duplicate. Even=1, Odd=1. Balanced! Len=3.
                if (even == odd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

// --- Driver Code to Test the Solution ---
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 5, 4, 3};
    cout << "Test Case 1: " << sol.longestBalanced(nums1) << endl;
    // Expected: 4 ([2, 5, 4, 3] -> 2 even, 2 odd)

    // Test Case 2
    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << "Test Case 2: " << sol.longestBalanced(nums2) << endl;
    // Expected: 5 ([3, 2, 2, 5, 4] -> evens: {2,4}, odds: {3,5})

    // Test Case 3 (Tricky duplicate case)
    vector<int> nums3 = {1, 2, 3, 2};
    cout << "Test Case 3: " << sol.longestBalanced(nums3) << endl;
    // Expected: 3 ([2, 3, 2] -> evens: {2}, odds: {3})

    return 0;
}