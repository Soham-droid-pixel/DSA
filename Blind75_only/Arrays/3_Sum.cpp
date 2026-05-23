#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // STEP 1: Sort the array! 
        // This makes finding duplicates easy and enables the Two-Pointer squeeze.
        sort(nums.begin(), nums.end());
        
        // Loop to set the 'Anchor' element
        for (int i = 0; i < n - 2; i++) {
            
            // OPTIMIZATION: Since the array is sorted, if our anchor is greater than 0, 
            // it is mathematically impossible for the remaining numbers to sum down to 0.
            if (nums[i] > 0) break;
            
            // DUPLICATE DODGE 1: If the anchor is the same as the last anchor, skip it.
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // STEP 2: Set up the Two-Pointer squeeze for the remaining array
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // We found a valid triplet! Save it.
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // DUPLICATE DODGE 2: Skip identical adjacent elements for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // DUPLICATE DODGE 3: Skip identical adjacent elements for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward to look for the next valid combination
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // The sum is too small. Move left pointer up to increase the sum.
                    left++;
                } 
                else {
                    // The sum is too big. Move right pointer down to decrease the sum.
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard input with multiple combinations
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res1 = sol.threeSum(nums1);
    
    cout << "Test Case 1 Output: \n";
    for (const auto& triplet : res1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << "\n\n";

    // Test Case 2: All zeroes
    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> res2 = sol.threeSum(nums2);
    
    cout << "Test Case 2 Output: \n";
    for (const auto& triplet : res2) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << "\n";

    return 0;
}
/*How to Remember This for Exams
When you look at this code, don't try to memorize every line. Just remember the Four Rules of 3Sum:

Sort First: sort(nums.begin(), nums.end());

Anchor Loop: Run i up to n - 2 (leaving room for left and right).

Squeeze: left = i + 1, right = n - 1. If sum < 0, move left. If sum > 0, move right.

Skip Neighbors: Whenever you move a pointer (i, left, or right), check if its new value is exactly the same as its old value. If it is, keep moving!*/