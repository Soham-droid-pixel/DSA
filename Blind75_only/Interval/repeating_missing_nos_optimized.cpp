#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        long long n = nums.size();

        // 1. Calculate Ideal Math Formulas
        long long idealSum = (n * (n + 1)) / 2;
        long long idealSumSquares = (n * (n + 1) * (2 * n + 1)) / 6;

        // 2. Calculate Actual Sums from the Array
        long long actualSum = 0;
        long long actualSumSquares = 0;
        
        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
            actualSumSquares += (long long)nums[i] * (long long)nums[i];
        }

        // 3. Set up algebraic relationships
        // val1 = X - Y
        long long val1 = actualSum - idealSum; 
        
        // val2 = X^2 - Y^2
        long long val2 = actualSumSquares - idealSumSquares; 

        // Find X + Y using: (X^2 - Y^2) / (X - Y)
        val2 = val2 / val1; 

        // 4. Solve the linear equations system
        // X = ((X + Y) + (X - Y)) / 2
        long long repeating = (val1 + val2) / 2;
        
        // Y = X - (X - Y)
        long long missing = repeating - val1;

        return {(int)repeating, (int)missing};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 4, 1, 1}; // Example 1
    
    vector<int> ans = sol.findMissingRepeatingNumbers(nums);
    cout << "Repeating (A): " << ans[0] << ", Missing (B): " << ans[1] << "\n";
    
    return 0;
}