#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to perform backtracking recursive exploration
    void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& currentPath) {
        // BASE CASE 1: If the remaining target hits exactly 0, we found a valid combination!
        if (target == 0) {
            result.push_back(currentPath); // Save the successful path
            return;
        }

        // BASE CASE 2: If we run out of elements OR target goes negative (overshot), stop exploring
        if (index == candidates.size() || target < 0) {
            return;
        }

        // --- CHOICE 1: "PICK" THE CURRENT ELEMENT ---
        // We can only pick the number if it fits into our remaining target
        if (candidates[index] <= target) {
            currentPath.push_back(candidates[index]); // 1. Take the element
            
            // 2. Explore: Notice we DO NOT increment 'index'. We stay at the same index
            // because the problem allows us to reuse the same number infinitely!
            findCombinations(index, target - candidates[index], candidates, result, currentPath);
            
            currentPath.pop_back(); // 3. Backtrack: Clean up/remove the element to test other branches
        }

        // --- CHOICE 2: "DON'T PICK" THE CURRENT ELEMENT ---
        // Skip the current element entirely and move forward to the next number.
        // This prevents us from ever looking back at this number, avoiding duplicate combinations.
        findCombinations(index + 1, target, candidates, result, currentPath);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentPath; // Acts as our dynamic tracking list
        
        // Start recursive exploration from index 0 with the initial target
        findCombinations(0, target, candidates, result, currentPath);
        
        return result;
    }
};

// Main function configured for local testing in VS Code
int main() {
    Solution sol;
    
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> totalCombinations = sol.combinationSum(candidates, target);
    
    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const auto& combination : totalCombinations) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}