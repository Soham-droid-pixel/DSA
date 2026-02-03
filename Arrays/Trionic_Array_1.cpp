#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // A Trionic array must have at least 4 elements to form (Up, Down, Up)
        // Indices: 0 < p < q < n-1
        if (n < 4) return false;

        int i = 0;

        // PHASE 1: Walk UP to the Peak (p)
        while (i < n - 1 && nums[i] < nums[i+1]) {
            i++;
        }
        int p = i;
        // Check: Must have moved up (p > 0) AND cannot be at end yet
        if (p == 0 || p == n - 1) return false;

        // PHASE 2: Walk DOWN to the Valley (q)
        while (i < n - 1 && nums[i] > nums[i+1]) {
            i++;
        }
        int q = i;
        // Check: Must have moved down (q > p) AND cannot be at end yet
        if (q == p || q == n - 1) return false;

        // PHASE 3: Walk UP to the End
        while (i < n - 1 && nums[i] < nums[i+1]) {
            i++;
        }

        // FINAL CHECK: Did we successfully reach the last index?
        return (i == n - 1);
    }
};

// --- Driver Code ---
int main() {
    Solution sol;

    // Test Case 1: Valid Trionic [Up, Down, Up]
    vector<int> nums1 = {1, 3, 5, 4, 2, 6};
    cout << "Test 1 (Expected True): " << (sol.isTrionic(nums1) ? "True" : "False") << endl;

    // Test Case 2: Invalid (Only Up and Down)
    vector<int> nums2 = {1, 2, 3, 4, 1};
    cout << "Test 2 (Expected False): " << (sol.isTrionic(nums2) ? "True" : "False") << endl;

    return 0;
}