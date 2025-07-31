#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int doublecounter = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                counter++;
            }
            
            if (doublecounter < counter) {
                doublecounter = counter;
            }
            
            if (nums[i] == 0) {
                counter = 0;
            }
        }

        return doublecounter;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    
    cout << "Max consecutive ones: " 
         << sol.findMaxConsecutiveOnes(nums) << endl;
    
    return 0;
}
/*
Loop through array.

counter counts current 1’s streak.

doublecounter stores max streak so far.

Reset counter to 0 on encountering 0*/