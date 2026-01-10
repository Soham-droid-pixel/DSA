#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Height is limited by the shorter wall
            int h = min(height[left], height[right]);
            int w = right - left;
            
            // Update max area
            maxWater = max(maxWater, h * w);

            // Move the shorter wall inward to try and find a taller one
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};

int main() {
    // Test Case
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    Solution sol;
    cout << "Max Water Area: " << sol.maxArea(height) << endl;
    
    return 0;
}