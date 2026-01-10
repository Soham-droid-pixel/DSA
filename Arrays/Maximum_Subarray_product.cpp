#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int current_product = 1;
        
        // Pass 1: Left to Right
        for (int i = 0; i < nums.size(); i++) {
            current_product *= nums[i];
            if (current_product > max_product) {
                max_product = current_product;
            }
            if (current_product == 0) {
                current_product = 1;
            }
        }
        
        // Pass 2: Right to Left
        current_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            current_product *= nums[i];
            if (current_product > max_product) {
                max_product = current_product;
            }
            if (current_product == 0) {
                current_product = 1;
            }
        }
        
        return max_product;
    }
};

int main() {
    // Test Case: [3, -1, 4] should be 4, [2, 3, -2, 4] should be 6
    vector<int> arr = {2, 3, -2, 4};
    
    Solution sol;
    cout << "Max Product Subarray: " << sol.maxProduct(arr) << endl;
    
    return 0;
}