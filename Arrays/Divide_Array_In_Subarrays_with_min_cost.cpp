#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        // Initialize with a large value. 
        // Since max element is 50, max cost is 150. INT_MAX is safe.
        int min_cost = INT_MAX;
        
        // We need to pick 3 starting positions:
        // 1. Index 0 (Fixed): nums[0]
        // 2. Index i (Variable): nums[i]
        // 3. Index j (Variable): nums[j]
        
        // i represents the start of the 2nd subarray.
        // It can be anywhere from index 1 to n-2 (must leave room for 3rd subarray).
        for (int i = 1; i < n; i++) {
            
            // j represents the start of the 3rd subarray.
            // It must be strictly after i.
            for (int j = i + 1; j < n; j++) {
                
                int currentSum = nums[0] + nums[i] + nums[j];
                
                if (currentSum < min_cost) {
                    min_cost = currentSum;
                }
            }
        }
        
        return min_cost;
    }
};

// --- Driver Code ---
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 12};
    cout << "Test 1 Output: " << sol.minimumCost(nums1) << endl; 
    // Expected: 6 (1 + 2 + 3)

    // Example 2
    vector<int> nums2 = {5, 4, 3};
    cout << "Test 2 Output: " << sol.minimumCost(nums2) << endl; 
    // Expected: 12 (5 + 4 + 3)

    return 0;
}