#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Handle empty input
        if (nums.empty()) return 0;

        // Step 2: Move all numbers to a Hash Set for O(1) average lookup time
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        // Step 3: Iterate through the set
        for (int n : numSet) {
            
            /* 
               Only start counting if 'n' is the beginning of a sequence.
               If (n - 1) is in the set, then 'n' is not the start, 
               so we skip it to maintain O(n) total complexity.
            */
            if (numSet.find(n - 1) == numSet.end()) {
                int currentNum = n;
                int currentStreak = 1;

                // Count how far the consecutive sequence goes
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Update the global maximum streak
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

// Main function for local testing
int main() {
    Solution sol;

    // Test Case 1: Expected output 4 [1, 2, 3, 4]
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test Case 1: " << sol.longestConsecutive(nums1) << " (Expected: 4)" << endl;

    // Test Case 2: Expected output 9 [0, 1, 2, 3, 4, 5, 6, 7, 8]
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test Case 2: " << sol.longestConsecutive(nums2) << " (Expected: 9)" << endl;

    // Test Case 3: Expected output 3 [0, 1, 2]
    vector<int> nums3 = {1, 0, 1, 2};
    cout << "Test Case 3: " << sol.longestConsecutive(nums3) << " (Expected: 3)" << endl;

    return 0;
}