#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to explore and mark all connected land
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Safety Net: Boundary checks and water/visited check
        // If we go off the map, or hit water ('0'), we stop and go back.
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') {
            return;
        }

        // 2. Mark current cell as visited by "sinking" it (turning '1' to '0')
        grid[r][c] = '0';

        // 3. Explore all 4 neighbors (Up, Down, Left, Right)
        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        // 4. The Scanner: Scan every single cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find land ('1'), we found a brand new island!
                if (grid[i][j] == '1') {
                    islandCount++; // Count it
                    // Use DFS to find and sink all connected land of this specific island
                    dfs(grid, i, j);
                }
            }
        }

        return islandCount; // Return the total number of islands found
    }
};

// Main function to test the code
int main() {
    Solution sol;

    // Test Case 1: One big connected island
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << "Test Case 1:" << endl;
    cout << "Expected Output: 1" << endl;
    cout << "Actual Output:   " << sol.numIslands(grid1) << endl << endl;

    // Test Case 2: Three separate islands
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Test Case 2:" << endl;
    cout << "Expected Output: 3" << endl;
    cout << "Actual Output:   " << sol.numIslands(grid2) << endl;

    return 0;
}