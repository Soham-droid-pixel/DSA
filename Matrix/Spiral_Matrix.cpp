#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Safety check for empty matrix
        if (matrix.empty()) return {};

        int m = matrix.size();    // Rows (Height)
        int n = matrix[0].size(); // Cols (Width)
        vector<int> result;

        // Initialize 4 Pointers (The "Walls")
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1; // Corrected: Use 'n' for columns

        // Loop until the walls meet or cross
        while (top <= bottom && left <= right) {

            // 1. Move Right (Walk along Top Wall)
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++; // Top row is done, move ceiling down

            // 2. Move Down (Walk along Right Wall)
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Right col is done, move right wall left

            // 3. Move Left (Walk along Bottom Wall)
            // CRITICAL CHECK: Do we still have a valid row?
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--; // Bottom row is done, move floor up
            }

            // 4. Move Up (Walk along Left Wall)
            // CRITICAL CHECK: Do we still have a valid column?
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Left col is done, move left wall right
            }
        }

        return result;
    }
};

// Main function to run in VS Code
int main() {
    Solution sol;
    
    // Test Case: 3x3 Matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> output = sol.spiralOrder(matrix);

    cout << "Spiral Order: [ ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}

/* ========================================================================
                             CODE NOTES
========================================================================
1. The 4 Pointers (Walls):
   - top: Starts at 0, increases (Ceiling comes down).
   - bottom: Starts at m-1, decreases (Floor comes up).
   - left: Starts at 0, increases (Left wall moves right).
   - right: Starts at n-1, decreases (Right wall moves left).

2. Why the extra 'if' checks?
   - After moving Right and Down, we update 'top' and 'right'.
   - It is possible that 'top' crossed 'bottom' (e.g., single row matrix).
   - Without `if (top <= bottom)`, the "Move Left" loop would read a row 
     that has already been processed!

3. Initialization Trap:
   - Always ensure 'right' is initialized with n-1 (columns), not m-1 (rows).
*/