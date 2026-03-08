#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * Why this works (Cantor's Diagonal Argument):
     * We build a string 'res' of length n. 
     * For each index 'i', we look at the i-th character of the i-th string in 'nums'.
     * We flip that character (0 -> 1, 1 -> 0) and add it to our result.
     * * Because res[i] is guaranteed to be different from nums[i][i], 
     * our final 'res' is guaranteed to be different from every string in 'nums'.
     */
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the diagonal character is '0', we take '1', and vice versa.
            if (nums[i][i] == '0') {
                res += '1';
            } else {
                res += '0';
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> nums1 = {"01", "10"};
    cout << "Input: [\"01\",\"10\"] -> Output: " << sol.findDifferentBinaryString(nums1) << endl;

    // Test Case 2
    vector<string> nums2 = {"00", "01"};
    cout << "Input: [\"00\",\"01\"] -> Output: " << sol.findDifferentBinaryString(nums2) << endl;

    // Test Case 3
    vector<string> nums3 = {"111", "011", "001"};
    cout << "Input: [\"111\",\"011\",\"001\"] -> Output: " << sol.findDifferentBinaryString(nums3) << endl;

    return 0;
}