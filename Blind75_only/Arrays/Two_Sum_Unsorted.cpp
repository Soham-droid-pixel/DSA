#include <iostream>
#include <vector>
#include <unordered_map> // Key header required for O(1) hash map operations

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map database structure mapped as: { Element_Value -> Original_Index }
        unordered_map<int, int> seen;
        
        // Single linear pass execution step
        for (int i = 0; i < nums.size(); i++) {
            // Find the exact mathematical partner required to reach target sum
            int complement = target - nums[i];
            
            // Check if this needed partner was logged by previous loop steps
            // 'seen.end()' represents a failure to find the key in the map
            if (seen.find(complement) != seen.end()) {
                // Pair found! Return the saved historical index and current index
                return {seen[complement], i};
            }
            
            // If the partner isn't found yet, log the current value and index 
            // so future elements can look back and find it
            seen[nums[i]] = i;
        }
        
        // Return a boundary fallback vector if no match layout exists
        return {-1, -1}; 
    }
};

// Local entry point test architecture
int main() {
    Solution sol;
    
    // Sample Test Case: [3, 2, 4] with target = 6
    vector<int> nums = {3, 2, 4};
    int target = 6;
    
    vector<int> result = sol.twoSum(nums, target);
    
    // Output Verification
    cout << "Target found at indices: [" << result[0] << ", " << result[1] << "]\n";
    
    return 0;
}