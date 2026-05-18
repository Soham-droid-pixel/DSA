#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

class Solution {
public:
    // STEP 1: Standalone comparator function sorting by END times
    // Must be 'static' so std::sort can reference it without an object instance
    static bool compareEndTimes(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // True if interval 'a' finishes before interval 'b'
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // STEP 2: Pass our clean helper function as the custom sorting rule
        sort(intervals.begin(), intervals.end(), compareEndTimes);

        int removals = 0;
        // Seed our timeline tracker with the end time of the earliest finishing interval
        int lastEnd = intervals[0][1];

        // STEP 3: Single linear sweep across remaining elements
        for (int i = 1; i < intervals.size(); i++) {
            int nextStart = intervals[i][0];
            int nextEnd   = intervals[i][1];

            // If the next interval starts before the current anchor finishes -> Collision!
            if (nextStart < lastEnd) {
                removals++; // Greedily drop this interval to preserve maximum timeline space
            } 
            // Safe gap or touching point found. Move our timeline anchor forward
            else {
                lastEnd = nextEnd;
            }
        }

        return removals;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard overlapping chain
    // Input: [[1,2],[2,3],[3,4],[1,3]] -> Expected Output: 1 (Remove [1,3])
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Test Case 1 Output: " << sol.eraseOverlapIntervals(intervals1) << " (Expected: 1)" << endl;

    // Test Case 2: Multi-layer identical stacks
    // Input: [[1,2],[1,2],[1,2]] -> Expected Output: 2 (Remove two [1,2] intervals)
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Test Case 2 Output: " << sol.eraseOverlapIntervals(intervals2) << " (Expected: 2)" << endl;

    // Test Case 3: Perfectly non-overlapping intervals touching at boundaries
    // Input: [[1,2],[2,3]] -> Expected Output: 0 (No intervals need to be removed)
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};
    cout << "Test Case 3 Output: " << sol.eraseOverlapIntervals(intervals3) << " (Expected: 0)" << endl;

    return 0;
}