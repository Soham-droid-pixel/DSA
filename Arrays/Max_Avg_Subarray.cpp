#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For fixed decimal points

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        
        // Step 1: Initialize the first window
        for(int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        
        // Step 2: Slide the window
        for(int i = k; i < nums.size(); i++) {
            current_sum += nums[i];      // Add the new element (entering)
            current_sum -= nums[i - k];  // Subtract the old element (leaving)
            
            if(current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        
        // Step 3: Return the average
        return max_sum / k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    
    // Set precision to 5 decimal places like LeetCode
    cout << fixed << setprecision(5);
    cout << "Maximum Average: " << sol.findMaxAverage(nums, k) << " (Expected: 12.75000)" << endl;
    
    return 0;
}