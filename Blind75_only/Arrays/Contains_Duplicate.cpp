#include <iostream>
#include <vector>
#include <unordered_set> // Crucial header for O(1) average lookup times

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create an empty hash set to keep track of numbers we've seen so far
        unordered_set<int> seen;
        
        // Loop through every number in the array
        for (int i = 0; i < nums.size(); i++) {
            // 'seen.end()' means the number was NOT found in the set.
            // If seen.find() does NOT equal seen.end(), it means we found a match!
            if (seen.find(nums[i]) != seen.end()) {
                return true; // Found a duplicate, exit early immediately
            }
            
            // If it's a new number, insert it into our set tracking bucket
            seen.insert(nums[i]);
        }
        
        // If the loop finishes completely, every single number is unique
        return false;
    }
};

int main() {
    Solution sol;
    
    // Enable printing 'true' or 'false' instead of '1' or '0'
    cout << boolalpha;

    // Test Case 1: Contains duplicates -> Expected: true
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1: " << sol.containsDuplicate(nums1) << " (Expected: true)" << endl;

    // Test Case 2: All unique elements -> Expected: false
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test Case 2: " << sol.containsDuplicate(nums2) << " (Expected: false)" << endl;

    // Test Case 3: Multiple repeating elements -> Expected: true
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test Case 3: " << sol.containsDuplicate(nums3) << " (Expected: true)" << endl;

    return 0;
}