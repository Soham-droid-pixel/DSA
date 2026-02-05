#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * LINE-BY-LINE EXPLANATION:
     * * vector<int> result;
     * -> What it does: Creates an empty dynamic array (vector) called result.
     * -> Why: We need a place to store the new values we find. We cannot modify nums directly 
     * because we might need the original values later in the loop.
     * * int n = nums.size();
     * -> What it does: Calculates the total number of elements in the input array.
     * -> Why: We need n for our math later (specifically for the modulo % operator) 
     * to wrap around the array boundaries.
     * * for(int i = 0; i < n; i++) {
     * -> What it does: Starts a loop that goes from index 0 to n-1.
     * -> Why: The problem asks us to perform an independent action for every index in the array.
     */
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            /* * int steps = nums[i];
             * -> What it does: Looks at the value at the current index i and stores it in steps.
             * -> Example: If nums = [-1, 4, -1] and i = 0, then steps is -1.
             */
            int steps = nums[i];

            /*
             * int j = ((i + steps) % n + n) % n;
             * -> What it does: This is the Magic Formula for circular arrays. It calculates the target index j.
             * -> Breakdown:
             * 1. i + steps: Calculates the raw position. If i=0 and steps=-1, this gives -1.
             * 2. % n: Removes full cycles. In C++, -1 % 3 is -1.
             * 3. + n: Adds n to make the negative number positive. -1 + 3 becomes 2.
             * 4. % n: Handles cases where the number became exactly n (keeping it within 0 to n-1).
             * -> Visual: Imagine the array is a clock. This formula ensures that if you go back past 12, 
             * you land on 11, not -1.
             */
            int j = ((i + steps) % n + n) % n;
            
            /*
             * result.push_back(nums[j]);
             * -> What it does: Goes to index j (the one we just calculated), grabs the number there (nums[j]), 
             * and adds it to our result list.
             * -> Crucial Note: The problem says "Set result[i] to the value of the index where you land."
             */
            result.push_back(nums[j]);
        }

        /*
         * return result;
         * -> What it does: Sends the final array back as the answer.
         */
        return result;
    }
};

/*
 * =========================================================
 * TRACE WITH EXAMPLE: [-1, 4, -1]
 * Let's see why this formula fixes the error you had before.
 * Input: nums = [-1, 4, -1]
 * Size n = 3
 * * Iteration 1 (i = 0)
 * Value (steps): nums[0] is -1.
 * Math:
 * Target = 0 + (-1) = -1
 * Formula: (-1 % 3 + 3) % 3
 * (-1 + 3) % 3
 * 2 % 3 = 2
 * Action: Go to index 2. nums[2] is -1.
 * Result: [-1]
 * * Iteration 2 (i = 1)
 * Value (steps): nums[1] is 4.
 * Math:
 * Target = 1 + 4 = 5
 * Formula: (5 % 3 + 3) % 3
 * (2 + 3) % 3
 * 5 % 3 = 2
 * Action: Go to index 2. nums[2] is -1.
 * Result: [-1, -1]
 * * Iteration 3 (i = 2)
 * Value (steps): nums[2] is -1.
 * Math:
 * Target = 2 + (-1) = 1
 * Formula: (1 % 3 + 3) % 3
 * (1 + 3) % 3
 * 4 % 3 = 1
 * Action: Go to index 1. nums[1] is 4.
 * Result: [-1, -1, 4]
 * * Final Output: [-1, -1, 4] (Matches expected output!)
 * =========================================================
 */

// --- Driver Code to Test the Solution ---
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, -2, 1, 1};
    vector<int> res1 = sol.constructTransformedArray(nums1);
    
    cout << "Test Case 1: [ ";
    for(int x : res1) cout << x << " ";
    cout << "]" << endl;
    // Expected: [1 1 1 3]

    // Test Case 2 (The Tricky One)
    vector<int> nums2 = {-1, 4, -1};
    vector<int> res2 = sol.constructTransformedArray(nums2);
    
    cout << "Test Case 2: [ ";
    for(int x : res2) cout << x << " ";
    cout << "]" << endl;
    // Expected: [-1 -1 4]

    return 0;
}