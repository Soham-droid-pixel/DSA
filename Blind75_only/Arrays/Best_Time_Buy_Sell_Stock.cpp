#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min and std::max

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Handle edge case where no transaction can happen
        if (prices.size() < 2) return 0;

        // Initialize minPrice to the first day's price
        int minPrice = prices[0];
        int maxProfit = 0;

        // Walk through the timeline from day 2 onwards
        for (int i = 1; i < prices.size(); i++) {
            // Scenario 1: We found a cheaper day to buy! Update our valley.
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 
            // Scenario 2: Today's price is higher than our valley. 
            // Calculate potential profit and update our record if it's a new high.
            else {
                int potentialProfit = prices[i] - minPrice;
                maxProfit = max(maxProfit, potentialProfit);
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard chart with a clear valley and peak
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test Case 1 Output: " << sol.maxProfit(prices1) << " (Expected: 5)" << endl;

    // Test Case 2: Crashing stock where no profit can be made
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test Case 2 Output: " << sol.maxProfit(prices2) << " (Expected: 0)" << endl;

    return 0;
}