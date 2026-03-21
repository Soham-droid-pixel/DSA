#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // i represents the offset from the top/bottom of the submatrix
        for (int i = 0; i < k / 2; ++i) {
            // j iterates through the columns of the submatrix
            for (int j = y; j < y + k; ++j) {
                // Swap the i-th row from the top with the i-th row from the bottom
                swap(grid[x + i][j], grid[x + k - 1 - i][j]);
            }
        }
        return grid;
    }
};

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << "----------------------------" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int x1 = 1, y1 = 0, k1 = 3;

    cout << "Test 1 | Original Grid:" << endl;
    printGrid(grid1);

    vector<vector<int>> result1 = sol.reverseSubmatrix(grid1, x1, y1, k1);

    cout << "Test 1 | After Vertical Submatrix Flip (x=1, y=0, k=3):" << endl;
    printGrid(result1);

    // Test Case 2
    vector<vector<int>> grid2 = {
        {3, 4, 2, 3},
        {2, 3, 4, 2}
    };
    int x2 = 0, y2 = 2, k2 = 2;

    cout << "Test 2 | Original Grid:" << endl;
    printGrid(grid2);

    vector<vector<int>> result2 = sol.reverseSubmatrix(grid2, x2, y2, k2);

    cout << "Test 2 | After Vertical Submatrix Flip (x=0, y=2, k=2):" << endl;
    printGrid(result2);

    return 0;
}