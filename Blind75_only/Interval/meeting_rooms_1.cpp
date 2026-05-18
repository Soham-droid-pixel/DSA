#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // EDGE CASE 1: No meetings scheduled. No conflicts possible!
        if (intervals.empty()) return true;
        
        // EDGE CASE 2: Only 1 meeting scheduled. You can always attend it!
        if (intervals.size() == 1) return true;

        // STEP 1: Sort by start times out-of-the-box
        sort(intervals.begin(), intervals.end());

        // STEP 2: Check every meeting against the one right before it
        for (int i = 1; i < intervals.size(); i++) {
            int currentEnd = intervals[i - 1][1];
            int nextStart  = intervals[i][0];

            // CRASH CONDITION: Next meeting starts before the current one finishes
            if (nextStart < currentEnd) {
                return false; // Instant termination
            }
        }

        // If the loop finishes without hitting a conflict, we are safe!
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Overlapping meetings -> Expected: false
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test Case 1: " << sol.canAttendMeetings(intervals1) << " (Expected: false)" << endl;

    // Test Case 2: Non-overlapping touching meetings -> Expected: true
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Test Case 2: " << sol.canAttendMeetings(intervals2) << " (Expected: true)" << endl;

    // Test Case 3: Empty array edge case -> Expected: true
    vector<vector<int>> intervals3 = {};
    cout << "Test Case 3 (Empty): " << sol.canAttendMeetings(intervals3) << " (Expected: true)" << endl;

    return 0;
}