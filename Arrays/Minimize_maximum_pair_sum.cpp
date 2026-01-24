#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and max()

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Step 1: Sort the array to arrange elements from smallest to largest.
        // This allows us to pair the smallest with the largest optimally.
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        int max_sum = 0;
        
        // Step 2: Two Pointer Approach
        while (left < right) {
            int curr_sum = nums[left] + nums[right];
            
            // Track the maximum pair sum encountered so far
            max_sum = max(max_sum, curr_sum);
            
            // Move pointers inward
            left++;
            right--;
        }
        
        return max_sum;
    }
};

// --- Helper Code to Run and Test ---
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 5, 2, 3};
    cout << "Input: [3, 5, 2, 3]" << endl;
    cout << "Output: " << sol.minPairSum(nums1) << endl; 
    // Expected: 7 (Pairs: 2+5=7, 3+3=6 -> Max is 7)

    cout << "-----------------" << endl;

    // Test Case 2
    vector<int> nums2 = {3, 5, 4, 2, 4, 6};
    cout << "Input: [3, 5, 4, 2, 4, 6]" << endl;
    cout << "Output: " << sol.minPairSum(nums2) << endl;
    // Expected: 8 (Pairs: 2+6=8, 3+5=8, 4+4=8 -> Max is 8)

    return 0;
}