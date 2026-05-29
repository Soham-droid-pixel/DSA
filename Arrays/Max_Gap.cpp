#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    int maximumGap(vector<int>& nums) {

        if(nums.size() < 2) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int diff = 0;
        int maxDiff = INT_MIN;

        for(int i = 0; i < nums.size() - 1; i++) {

            diff = nums[i + 1] - nums[i];

            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3, 6, 9, 1};

    cout << s.maximumGap(nums);

    return 0;
}