#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 1. Find First Position
        int first = binarySearch(nums, target, true);
        
        // Optimization: If not found, return immediately
        if (first == -1) return {-1, -1};

        // 2. Find Last Position
        int last = binarySearch(nums, target, false);

        return {first, last};
    }

private:
    // Helper: Runs Binary Search. 
    // If findFirst == true, it looks LEFT. If false, it looks RIGHT.
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid; // Record the index
                
                // DECISION: Go Left or Go Right?
                if (findFirst) right = mid - 1; // Look Left for start
                else           left = mid + 1;  // Look Right for end
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard case
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    cout << "Input Array: [5, 7, 7, 8, 8, 10]" << endl;
    cout << "Target: " << target << endl;

    vector<int> result = solver.searchRange(nums, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    // Test Case 2: Target not found
    int target2 = 6;
    cout << "\nTarget: " << target2 << endl;
    vector<int> result2 = solver.searchRange(nums, target2);
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}