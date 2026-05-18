#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n = nums.size();
        int repeating = -1;
        int missing = -1;

        // Check the frequency of every number from 1 to N
        for (int i = 1; i <= n; i++) {
            int currentCount = 0;
            
            // Linear search to count occurrences of 'i'
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    currentCount++;
                }
            }

            // Categorize based on count
            if (currentCount == 2) {
                repeating = i;
            } else if (currentCount == 0) {
                missing = i;
            }

            // Early exit optimization if both are found
            if (repeating != -1 && missing != -1) {
                break;
            }
        }

        return {repeating, missing}; // Returns {A, B}
    }
};