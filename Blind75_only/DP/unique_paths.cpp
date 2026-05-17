#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create an m x n 2D table initialized entirely with 1
        // This automatically sets up the base cases for the first row and first column
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Start filling the table from position (1, 1)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // The current cell is the sum of the cell above it and the cell to its left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        // The bottom-right corner holds the total unique paths
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    // Test Case 1: m = 3, n = 7 -> Expected: 28
    cout << "Test Case 1: " << sol.uniquePaths(3, 7) << " (Expected: 28)" << endl;

    // Test Case 2: m = 3, n = 2 -> Expected: 3
    cout << "Test Case 2: " << sol.uniquePaths(3, 2) << " (Expected: 3)" << endl;

    return 0;
}