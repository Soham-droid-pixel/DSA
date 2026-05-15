#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Helper function: We start at the ocean and try to climb UP the mountain.
     * If we can climb to a cell, then rain falling there can flow DOWN to the ocean.
     */
    void dfs(int r, int c, int prevHeight, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();

        // 1. Safety Checks:
        // - Stay inside the grid bounds
        // - Don't visit the same cell twice (avoid infinite loops)
        // - Crucial: Only move if the next cell is EQUAL or HIGHER (climbing up)
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        // Mark this cell as reachable by the current ocean
        visited[r][c] = true;

        // Explore in all 4 directions
        dfs(r + 1, c, heights[r][c], heights, visited); // Down
        dfs(r - 1, c, heights[r][c], heights, visited); // Up
        dfs(r, c + 1, heights[r][c], heights, visited); // Right
        dfs(r, c - 1, heights[r][c], heights, visited); // Left
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int m = heights.size();
        int n = heights[0].size();

        // Two grids to track reachability for each ocean
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 2. Start DFS from the Horizontal Borders (Top and Bottom)
        for (int j = 0; j < n; j++) {
            // Pacific: Top Row (r=0)
            dfs(0, j, heights[0][j], heights, pacific);
            // Atlantic: Bottom Row (r=m-1)
            dfs(m - 1, j, heights[m - 1][j], heights, atlantic);
        }

        // 3. Start DFS from the Vertical Borders (Left and Right)
        for (int i = 0; i < m; i++) {
            // Pacific: Left Column (c=0)
            dfs(i, 0, heights[i][0], heights, pacific);
            // Atlantic: Right Column (c=n-1)
            dfs(i, n - 1, heights[i][n - 1], heights, atlantic);
        }

        // 4. Find the intersection (cells that can reach BOTH oceans)
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1 Grid
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> result = sol.pacificAtlantic(heights);

    cout << "Cells that can reach both Pacific and Atlantic oceans:" << endl;
    for (const auto& coord : result) {
        cout << "[" << coord[0] << ", " << coord[1] << "] ";
    }
    cout << endl;

    return 0;
}