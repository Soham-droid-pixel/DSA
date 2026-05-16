#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**************************************************************************
     * METHOD 1: Space-Optimized Iteration (★★★ THE BEST METHOD ★★★)
     * * Why it's the best: 
     * - Time Complexity: O(n) -> We loop exactly n-2 times.
     * - Space Complexity: O(1) -> We don't allocate any array or recursion stack.
     * - Reason to use: It provides maximum production efficiency by reducing 
     * memory footprint to a flat, constant overhead.
     *************************************************************************/
    int climbStairsSpaceOptimized(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1; // Tracks ways to reach (i - 2)
        int prev1 = 2; // Tracks ways to reach (i - 1)
        
        /* * Why is current initialized to 0?
         * In C++, declaring a local variable like `int current;` without a value 
         * means it holds unpredictable "garbage data" from memory. Initializing 
         * it to 0 is a defensive programming best practice to ensure a clean, 
         * safe state before the loop overrides it with actual calculations.
         */
        int current = 0; 
        
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2; // Summing the previous two steps
            prev2 = prev1;           // Slid state forward
            prev1 = current;         // Slide state forward
        }
        
        return current;
    }

    /**************************************************************************
     * METHOD 2: Bottom-Up Tabulation
     * * Properties:
     * - Time Complexity: O(n)
     * - Space Complexity: O(n) -> Allocates an array of size n+1.
     * - Reason to use: Highly readable and intuitive for building up a DP table.
     *************************************************************************/
    int climbStairsTabulation(int n) {
        if (n <= 2) return n;
        
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }

    /**************************************************************************
     * METHOD 3: Top-Down Memoization (Recursion + Memory Cache)
     * * Properties:
     * - Time Complexity: O(n)
     * - Space Complexity: O(n) -> Stack space + cache table array.
     * - Reason to use: Perfect if your natural mental model is recursive.
     *************************************************************************/
    int solveMemo(int n, vector<int>& memo) {
        if (n <= 2) return n; 
        
        if (memo[n] != -1) return memo[n]; // Return cached answer if it exists
        
        // Compute, cache, and return
        return memo[n] = solveMemo(n - 1, memo) + solveMemo(n - 2, memo);
    }

    int climbStairsMemoization(int n) {
        vector<int> memo(n + 1, -1);
        return solveMemo(n, memo);
    }
};

int main() {
    Solution sol;
    int steps = 5;

    cout << "--- Executing all 3 variants for n = " << steps << " ---" << endl;
    cout << "1. Space-Optimized (Best) : " << sol.climbStairsSpaceOptimized(steps) << endl;
    cout << "2. Tabulation             : " << sol.climbStairsTabulation(steps) << endl;
    cout << "3. Memoization            : " << sol.climbStairsMemoization(steps) << endl;

    return 0;
}