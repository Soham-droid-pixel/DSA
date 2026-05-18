#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort, std::max

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Edge Case: If there are no intervals, return an empty array
        if (intervals.empty()) return {};

        // STEP 1: Sort all intervals by their start times O(N log N)
        // C++ sorts pairs/vectors by their first element by default
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        
        // Initialize our timeline by pushing the very first sorted interval
        result.push_back(intervals[0]);

        // STEP 2: Linear sweep through the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Create a reference to the last interval currently sitting in our result
            // 'back()' lets us modify it directly in-place inside the vector!
            vector<int>& lastMerged = result.back();
            
            int nextStart = intervals[i][0];
            int nextEnd   = intervals[i][1];
            int lastEnd   = lastMerged[1];

            // Scenario 1: Overlap detected!
            if (nextStart <= lastEnd) {
                lastMerged[1] = max(lastEnd, nextEnd); // Stretch the end boundary
            } 
            // Scenario 2: No overlap, a brand new independent interval begins
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard overlapping intervals
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res1 = sol.merge(intervals1);

    cout << "Test Case 1 Output: " << endl;
    for (const auto& interval : res1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl << endl;

    // Test Case 3: Out of order input requiring sorting first
    vector<vector<int>> intervals2 = {{4, 7}, {1, 4}};
    vector<vector<int>> res2 = sol.merge(intervals2);

    cout << "Test Case 2 (Unsorted Input) Output: " << endl;
    for (const auto& interval : res2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}