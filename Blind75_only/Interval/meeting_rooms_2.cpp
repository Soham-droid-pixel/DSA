#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort, std::max

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // EDGE CASE: If there are no meetings, we need 0 rooms
        if (intervals.empty()) return 0;

        int n = intervals.size();
        vector<int> startTimes;
        vector<int> endTimes;

        // STEP 1: Unpack starts and ends into separate arrays
        for (int i = 0; i < n; i++) {
            startTimes.push_back(intervals[i][0]);
            endTimes.push_back(intervals[i][1]);
        }

        // STEP 2: Sort both timelines chronologically O(N log N)
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int activeRooms = 0;
        int maxRoomsNeeded = 0;

        int startPtr = 0;
        int endPtr = 0;

        // STEP 3: Sweep through time using two pointers
        while (startPtr < n) {
            // If a meeting is starting BEFORE the oldest active meeting ends,
            // we have no choice but to allocate a brand-new room.
            if (startTimes[startPtr] < endTimes[endPtr]) {
                activeRooms++;
                startPtr++; // Move to look at the next upcoming meeting
            } 
            // If a meeting ends before or EXACTLY when the next one starts,
            // a room safely opens up.
            else {
                activeRooms--;
                endPtr++; // Move to track the next meeting's wrap-up time
            }

            // Track the historical peak of concurrently active rooms
            maxRoomsNeeded = max(maxRoomsNeeded, activeRooms);
        }

        return maxRoomsNeeded;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Overlapping chain -> Expected: 2
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Test Case 1 Rooms Needed: " << sol.minMeetingRooms(intervals1) << " (Expected: 2)" << endl;

    // Test Case 2: Non-overlapping touching meetings -> Expected: 1
    // [7,10] starts exactly when [2,7] ends. The room is handed over directly.
    vector<vector<int>> intervals2 = {{7, 10}, {2, 7}};
    cout << "Test Case 2 Rooms Needed: " << sol.minMeetingRooms(intervals2) << " (Expected: 1)" << endl;

    return 0;
}