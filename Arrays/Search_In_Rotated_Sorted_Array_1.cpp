#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        
        // FIX: Use <= to handle single elements and the final collision
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            // Check if Left Side is Sorted
            if(nums[left] <= nums[mid]){
                // Logic: Is target inside the sorted left half?
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            // Otherwise, Right Side is Sorted
            else{
                // Logic: Is target inside the sorted right half?
                if(nums[right] >= target && target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Driver Code (Required for VS Code)
int main() {
    Solution sol;

    // Test Case 1: Target is present
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    
    int result1 = sol.search(nums1, target1);
    cout << "Test Case 1 (Target 0): Index " << result1 << endl; 
    // Expected: 4

    // Test Case 2: Target is NOT present
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;

    int result2 = sol.search(nums2, target2);
    cout << "Test Case 2 (Target 3): Index " << result2 << endl; 
    // Expected: -1

    return 0;
}