#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        
        return nums[low];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 1, 2};
    int result1 = sol.findMin(nums1);
    cout << "Input: [3, 4, 5, 1, 2]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "-----------------------------------" << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int result2 = sol.findMin(nums2);
    cout << "Input: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "-----------------------------------" << endl;

    vector<int> nums3 = {11, 13, 15, 17};
    int result3 = sol.findMin(nums3);
    cout << "Input: [11, 13, 15, 17]" << endl;
    cout << "Output: " << result3 << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}