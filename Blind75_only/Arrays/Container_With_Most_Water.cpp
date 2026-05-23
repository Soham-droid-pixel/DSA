#include <iostream>
#include <vector>
#include <algorithm> // Required for std::min and std::max

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxGlobalArea = 0;

        while (left < right) {
            // Width is the physical distance between the two pointers
            int width = right - left;
            
            // Height is restricted by the shorter wall (otherwise water spills out)
            int currentHeight = min(height[left], height[right]);
            
            // Calculate current capacity and update the global record
            int currentArea = width * currentHeight;
            maxGlobalArea = max(maxGlobalArea, currentArea);

            // THE BOTTLENECK RULE: 
            // Always move the pointer pointing to the shorter line to seek a taller one.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxGlobalArea;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard mountain-shaped chart
    // Input: [1, 8, 6, 2, 5, 4, 8, 3, 7] -> Expected Output: 49
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test Case 1 Output: " << sol.maxArea(height1) << " (Expected: 49)" << endl;

    // Test Case 2: Just two uniform walls
    // Input: [1, 1] -> Expected Output: 1
    vector<int> height2 = {1, 1};
    cout << "Test Case 2 Output: " << sol.maxArea(height2) << " (Expected: 1)" << endl;

    return 0;
}