#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        long long total = 0;  
        int left = 0, ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            total += nums[right];
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;
    cout << sol.maxFrequency(nums1, k1) << endl;

    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;
    cout << sol.maxFrequency(nums2, k2) << endl;

    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    cout << sol.maxFrequency(nums3, k3) << endl;

    return 0;
}
