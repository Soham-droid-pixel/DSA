#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Utilizing vector<unsigned int> handles huge intermediate combinations 
        // by wrapping around safely without triggering signed integer overflow crashes.
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1; // Base case: 1 way to make an amount of 0 (by choosing nothing)
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        // Safely downcasts the unsigned int back to int for the final return
        return dp[amount]; 
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard small input
    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};
    cout << "Test Case 1 (Amount 5): " << sol.change(amount1, coins1) << " (Expected: 4)" << endl;

    // Test Case 2: Impossible amount
    int amount2 = 3;
    vector<int> coins2 = {2};
    cout << "Test Case 2 (Amount 3): " << sol.change(amount2, coins2) << " (Expected: 0)" << endl;

    // Test Case 3: High branch factor (Simulating your exact large-input test case)
    int amount3 = 4681;
    vector<int> coins3 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}; 
    cout << "Test Case 3 (Large Input): " << sol.change(amount3, coins3) << " (Runs successfully without crashing!)" << endl;

    return 0;
}