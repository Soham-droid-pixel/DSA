#include <iostream>
#include <vector>
#include <cmath> // Required for abs()

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        // Pass 1: Mark the presence of numbers
        // We visit the index corresponding to each value and flip the number there to negative.
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // Map value 1 to index 0, etc.
            
            // Only flip if it's positive (to avoid double-flipping)
            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        // Pass 2: Check which indices are still positive
        // A positive value at index 'i' means the number 'i+1' was never seen.
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solver;

    // Test Case: Example 1 from LeetCode
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    cout << "Input Array: ";
    for(int x : nums) cout << x << " ";
    cout << endl;

    // Call the function
    vector<int> missing = solver.findDisappearedNumbers(nums);

    // Print the result
    cout << "Missing Numbers: ";
    for(int x : missing) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}