#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * PROBLEM: Two Sum II - Input Array Is Sorted
     * Goal: Find two numbers that add up to 'target'.
     * Constraint: Array is SORTED. Space must be O(1).
     * * * YOUR WINNING LOGIC (Two Pointers):
     * Since the array is sorted, we can use two pointers:
     * 1. 'left' starts at the smallest number (start).
     * 2. 'right' starts at the largest number (end).
     * * - If sum > target: The sum is too big. We need a smaller number. 
     * So, we move 'right' pointer to the left.
     * - If sum < target: The sum is too small. We need a bigger number.
     * So, we move 'left' pointer to the right.
     * - If sum == target: WE FOUND IT!
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            
            if(sum == target) {
                // Found the pair!
                // Return 1-based indices (so add +1)
                return {left + 1, right + 1};
            }
            else if(sum > target) {
                // Sum is too big, decrease the larger number
                right--;
            }
            else {
                // Sum is too small, increase the smaller number
                left++;
            }
        }
        
        // The problem guarantees a solution, so we won't actually reach here.
        return {}; 
    }
};

// --- Driver Code to Run Locally ---
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "Test Case 1: [" << res1[0] << ", " << res1[1] << "]" << endl;
    // Expected: [1, 2]

    // Test Case 2
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "Test Case 2: [" << res2[0] << ", " << res2[1] << "]" << endl;
    // Expected: [1, 3]

    // Test Case 3
    vector<int> nums3 = {-1, 0};
    int target3 = -1;
    vector<int> res3 = sol.twoSum(nums3, target3);
    cout << "Test Case 3: [" << res3[0] << ", " << res3[1] << "]" << endl;
    // Expected: [1, 2]

    return 0;
}