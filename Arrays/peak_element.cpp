#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findPeakLinear(vector<int>& nums) {
        int index = 0;
        long long maxVal = LLONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                index = i;
                maxVal = nums[i];
            }
        }
        return index;
    }

    int findPeakBinary(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {1, 2, 1, 3, 5, 6, 4};

    cout << "--- Test Case 1: {1, 2, 3, 1} ---" << endl;
    cout << "Linear O(n) Result Index: " << sol.findPeakLinear(test1) << endl;
    cout << "Binary O(log n) Result Index: " << sol.findPeakBinary(test1) << endl;

    cout << "\n--- Test Case 2: {1, 2, 1, 3, 5, 6, 4} ---" << endl;
    cout << "Linear O(n) Result Index: " << sol.findPeakLinear(test2) << endl;
    cout << "Binary O(log n) Result Index: " << sol.findPeakBinary(test2) << endl;

    return 0;
}