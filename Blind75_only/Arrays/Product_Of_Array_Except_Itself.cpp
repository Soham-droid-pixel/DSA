#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // Initialize answer array with 1s

        // PASS 1: Calculate the prefix products (left side)
        // 'runningPrefix' tracks the product of all elements strictly to the left of index i
        int runningPrefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = runningPrefix;       // Assign the product of everything to the left
            runningPrefix *= nums[i];        // Update the running product for the next element
        }

        // PASS 2: Calculate the suffix products (right side) on the fly
        // 'runningSuffix' tracks the product of all elements strictly to the right of index i
        int runningSuffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= runningSuffix;      // Multiply with the product of everything to the right
            runningSuffix *= nums[i];        // Update the running product for the next element moving left
        }

        return answer;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard positive array
    // Input: [1, 2, 3, 4] -> Expected Output: [24, 12, 8, 6]
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> res1 = sol.productExceptSelf(nums1);

    cout << "Test Case 1 Output: [ ";
    for (int x : res1) cout << x << " ";
    cout << "]" << endl;

    // Test Case 2: Array containing a zero element
    // Input: [-1, 1, 0, -3, 3] -> Expected Output: [0, 0, 9, 0, 0]
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> res2 = sol.productExceptSelf(nums2);

    cout << "Test Case 2 Output: [ ";
    for (int x : res2) cout << x << " ";
    cout << "]" << endl;

    return 0;
}