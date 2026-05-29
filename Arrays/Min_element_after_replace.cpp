#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {

public:

    int minElement(vector<int>& nums) {

        int rem;
        int minrem = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {

            int totalrem = 0;
            int num = nums[i];

            while(num > 0) {

                rem = num % 10;
                totalrem += rem;
                num = num / 10;
            }

            if(minrem > totalrem) {
                minrem = totalrem;
            }
        }

        return minrem;
    }
};

int main() {

    Solution s;

    vector<int> nums = {123, 45, 6, 789};

    cout << s.minElement(nums);

    return 0;
}