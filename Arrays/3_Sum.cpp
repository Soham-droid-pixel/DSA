#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

// Class to solve 3-Sum problem
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // Step 1: Sort the array
        // Sorting is crucial for the two-pointer technique and duplicate handling
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        // Step 2: Iterate through the array (fixing the first number 'i')
        for (int i = 0; i < n; i++) {
            
            // Optimization: If the fixed number is > 0, we can never sum to 0
            // because the array is sorted (all subsequent numbers will also be > 0).
            if (nums[i] > 0) break;

            // Duplicate Check 1: Skip duplicate 'i' values
            // We only process the first occurrence of a number to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Two Pointers approach for the remaining two numbers
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet! Add it to the answer
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers inward
                    left++;
                    right--;

                    // Duplicate Check 2: Skip duplicates for 'left' pointer
                    while (left < right && nums[left] == nums[left - 1]) left++;

                    // Duplicate Check 3: Skip duplicates for 'right' pointer
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < 0) {
                    // Sum is too small -> Need a larger number -> Move Left pointer right
                    left++;
                }
                else {
                    // Sum is too big -> Need a smaller number -> Move Right pointer left
                    right--;
                }
            }
        }
        return ans;
    }
};

// Driver code to test locally
int main() {
    // Example 1: [-1, 0, 1, 2, -1, -4]
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    Solution obj;
    vector<vector<int>> res = obj.threeSum(nums);

    cout << "Output Triplets:" << endl;
    for (auto &triplet : res) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}