#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Notice it is strictly '<' and not '<='. 
        // We want the loop to break exactly when left == right.
        while (left < right) {
            // Exam Trick: Use this formula to prevent integer overflow 
            // instead of (left + right) / 2
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // The mid element is larger than the right boundary.
                // This means the drop-off (minimum) is strictly to the right.
                left = mid + 1;
            } else {
                // The mid element is smaller than or equal to the right boundary.
                // This means the right half is sorted, so the minimum is at mid or to its left.
                right = mid;
            }
        }

        // When left == right, we have isolated the absolute minimum element.
        return nums[left];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard rotated array
    // Input: [3, 4, 5, 1, 2] -> Expected Output: 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Test Case 1 Output: " << sol.findMin(nums1) << " (Expected: 1)" << endl;

    // Test Case 2: Heavily rotated array
    // Input: [4, 5, 6, 7, 0, 1, 2] -> Expected Output: 0
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test Case 2 Output: " << sol.findMin(nums2) << " (Expected: 0)" << endl;

    // Test Case 3: Fully sorted array (rotated 0 times)
    // Input: [11, 13, 15, 17] -> Expected Output: 11
    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Test Case 3 Output: " << sol.findMin(nums3) << " (Expected: 11)" << endl;

    return 0;
}