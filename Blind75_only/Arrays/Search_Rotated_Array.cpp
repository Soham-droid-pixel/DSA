#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // <= ensures we don't skip the final element if left and right converge on the target
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Target found!
            if (nums[mid] == target) {
                return mid;
            }

            // STEP 1: Is the LEFT half perfectly sorted?
            if (nums[left] <= nums[mid]) {
                // Is the target strictly inside this perfectly sorted left half?
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target is here, discard right half
                } else {
                    left = mid + 1;  // Target is not here, discard left half
                }
            } 
            // STEP 2: Otherwise, the RIGHT half MUST be perfectly sorted.
            else {
                // Is the target strictly inside this perfectly sorted right half?
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Target is here, discard left half
                } else {
                    right = mid - 1; // Target is not here, discard right half
                }
            }
        }

        // Loop finished, target does not exist
        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target is in the perfectly sorted left half initially
    // Input: [4, 5, 6, 7, 0, 1, 2], Target: 5 -> Expected Output: 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test Case 1 Output: " << sol.search(nums1, 5) << " (Expected: 1)" << endl;

    // Test Case 2: Target is in the messy right half initially
    // Input: [4, 5, 6, 7, 0, 1, 2], Target: 0 -> Expected Output: 4
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test Case 2 Output: " << sol.search(nums2, 0) << " (Expected: 4)" << endl;

    // Test Case 3: Target does not exist
    // Input: [4, 5, 6, 7, 0, 1, 2], Target: 3 -> Expected Output: -1
    vector<int> nums3 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test Case 3 Output: " << sol.search(nums3, 3) << " (Expected: -1)" << endl;

    return 0;
}