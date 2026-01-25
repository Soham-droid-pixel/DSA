#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and min()
#include <climits>   // Required for INT_MAX

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Edge case: If we only need 1 student, the difference is always 0.
        if (k == 1) return 0;

        // Step 1: Sort the scores.
        // Array: [10, 20, 30, 40, 50]
        // This puts the k scores we want next to each other.
        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Step 2: Sliding Window
        // We need a group of size 'k'.
        // We start loop at 'i = k - 1' because that is the index of the 
        // last element in the FIRST valid group.
        // Example: If k=3, we can't make a group until index 2 (items 0, 1, 2).
        for (int i = k - 1; i < nums.size(); i++) {
            
            // MATH EXPLANATION:
            // nums[i]         -> The Largest number in current group (Right side)
            // nums[i - k + 1] -> The Smallest number in current group (Left side)
            //
            // Formula: Max Score - Min Score
            int currentDiff = nums[i] - nums[i - k + 1];
            
            // Keep the smallest difference found
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
            }
        }

        return minDiff;
    }
};

// --- Driver Code ---
int main() {
    Solution sol;
    vector<int> nums = {9, 4, 1, 7}; // Sorted becomes [1, 4, 7, 9]
    int k = 2;
    cout << "Output: " << sol.minimumDifference(nums, k) << endl; // Expected: 2
    return 0;
}