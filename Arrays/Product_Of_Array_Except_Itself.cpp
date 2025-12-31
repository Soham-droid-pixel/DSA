#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Step 1: Initialize prefix and suffix arrays with 1s
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        // Step 2: Build the Prefix Array (Left Products)
        // prefix[i] contains the product of all elements BEFORE i
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Step 3: Build the Suffix Array (Right Products)
        // suffix[i] contains the product of all elements AFTER i
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Step 4: Multiply Prefix and Suffix to get the Final Answer
        // We reuse the 'prefix' array to store the result to save a bit of space
        for (int i = 0; i < nums.size(); i++) {
            prefix[i] *= suffix[i];
        }

        return prefix;
    }
};

int main() {
    Solution solver;

    // Test Case: [1, 2, 3, 4]
    vector<int> nums = {1, 2, 3, 4};

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // Call the function
    vector<int> result = solver.productExceptSelf(nums);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}