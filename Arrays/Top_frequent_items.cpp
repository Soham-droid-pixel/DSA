#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using a Map
        // Time: O(N)
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Create Buckets
        // Index = Frequency
        // Value = List of numbers with that frequency
        // Size is n+1 because a number can appear at most n times.
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& it : counts) {
            int number = it.first;
            int frequency = it.second;
            buckets[frequency].push_back(number);
        }

        // Step 3: Iterate backwards (from highest frequency to lowest)
        // Time: O(N)
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            // If this bucket has numbers, add them to result
            for (int num : buckets[i]) {
                result.push_back(num);
                // Check if we have found enough numbers
                if (result.size() == k) {
                    return result; 
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case: [1,1,1,2,2,3], k = 2
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    cout << "Input Array: ";
    for(int x : nums) cout << x << " ";
    cout << "\nTarget k: " << k << endl;

    // Run the function
    vector<int> result = solver.topKFrequent(nums, k);

    // Print output
    cout << "Top " << k << " Frequent Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}