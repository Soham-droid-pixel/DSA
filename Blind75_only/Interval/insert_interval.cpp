#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min and std::max

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // PHASE 1: Add all intervals that finish strictly BEFORE the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++; // Move to next interval
        }
        
        // PHASE 2: Merge all overlapping intervals into one giant newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]); // Stretch left boundary
            newInterval[1] = max(newInterval[1], intervals[i][1]); // Stretch right boundary
            i++;
        }
        // Push the completely merged newInterval into our final timeline
        result.push_back(newInterval);
        
        // PHASE 3: Add all remaining intervals that start strictly AFTER the new interval ends
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Overlap requiring single merge
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> res1 = sol.insert(intervals1, newInterval1);

    cout << "Test Case 1 Output: " << endl;
    for (const auto& interval : res1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl << endl;

    // Test Case 2: Multi-interval destructive overlap
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> res2 = sol.insert(intervals2, newInterval2);

    cout << "Test Case 2 Output: " << endl;
    for (const auto& interval : res2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}