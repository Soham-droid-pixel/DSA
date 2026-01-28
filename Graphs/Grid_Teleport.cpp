#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm> // for sort
#include <climits>   // for 1e9 const

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;
        
        // dist[i][j] stores the minimum cost to reach cell (i, j)
        // Initialize with Infinity, start point (0,0) is 0.
        vector<vector<int>> dist(m, vector<int>(n, INF));
        dist[0][0] = 0;
        
        // We run the process k+1 times:
        // Step 0: Optimize paths with 0 teleports.
        // Step 1: Optimize paths with 1 teleport... etc.
        for (int step = 0; step <= k; step++) {
            
            // ============================================
            // Phase 1: Dijkstra for Normal Moves (Right/Down)
            // ============================================
            // Min-priority queue stores {cost, flat_index}
            // flat_index is used to store (row, col) as a single integer: i * n + j
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            
            // Add all currently reachable nodes to the queue to propagate normal moves
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if (dist[i][j] != INF) {
                        pq.push({dist[i][j], i * n + j});
                    }
                }
            }
            
            // Standard Dijkstra Logic
            while(!pq.empty()) {
                auto [d, flat] = pq.top();
                pq.pop();
                int r = flat / n;
                int c = flat % n;
                
                // If we found a shorter path to this cell already, skip
                if (d > dist[r][c]) continue;
                
                // Try moving Right (0,1) and Down (1,0)
                int dr[] = {0, 1};
                int dc[] = {1, 0};
                
                for(int i = 0; i < 2; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    // Boundary Check
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        int newCost = d + grid[nr][nc]; // Cost = Dest Value
                        if (newCost < dist[nr][nc]) {
                            dist[nr][nc] = newCost;
                            pq.push({newCost, nr * n + nc});
                        }
                    }
                }
            }
            
            // ============================================
            // Phase 2: Teleportation Logic
            // ============================================
            // "Unlock" teleport shortcuts for the NEXT step.
            if (step < k) {
                // Collect all cells to process them by value
                vector<tuple<int, int, int>> cells;
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        cells.emplace_back(grid[i][j], i, j);
                    }
                }
                
                // Sort Descending: Because we can teleport FROM higher TO lower (or equal).
                // This lets us propagate the minimum cost downwards.
                sort(cells.rbegin(), cells.rend());
                
                int min_cost_so_far = INF;
                int idx = 0;
                
                // BATCH PROCESSING: Process all cells with Equal Values together
                // This fixes the bug where sorting order matters for equal values.
                while(idx < cells.size()) {
                    int current_val = get<0>(cells[idx]);
                    int start = idx;
                    
                    // Find the end of this value group
                    while(idx < cells.size() && get<0>(cells[idx]) == current_val) {
                        idx++;
                    }
                    
                    // --- Inside this Equal-Value Group ---
                    
                    // 1. Find the best cost existing inside this group
                    int group_min = INF;
                    for(int i = start; i < idx; i++) {
                        auto [v, r, c] = cells[i];
                        group_min = min(group_min, dist[r][c]);
                    }
                    
                    // 2. Combine with min_cost flowing down from higher values
                    min_cost_so_far = min(min_cost_so_far, group_min);
                    
                    // 3. Update EVERYONE in this group with the new global minimum
                    // Since teleport cost is 0, they can all reach each other or be reached
                    // from higher values instantly.
                    for(int i = start; i < idx; i++) {
                        auto [v, r, c] = cells[i];
                        dist[r][c] = min(dist[r][c], min_cost_so_far);
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};

// --- Driver Code ---
int main() {
    Solution sol;
    
    // Test Case 1: The "Tricky" Equal Value Case
    vector<vector<int>> grid1 = {
        {1, 3, 3},
        {2, 5, 4},
        {4, 3, 5}
    };
    int k1 = 2;
    cout << "Test 1 Output: " << sol.minCost(grid1, k1) << endl; 
    // Expected: 7
    
    // Test Case 2: Simple Down-Right
    vector<vector<int>> grid2 = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    int k2 = 1;
    cout << "Test 2 Output: " << sol.minCost(grid2, k2) << endl; 
    // Expected: 9

    return 0;
}
/*Revision: Grid TeleportationTopic: Graph / Shortest Path / DijkstraDifficulty: Hard1. The Problem:Move Right/Down (Cost = Value).Teleport anywhere if (dest <= source) (Cost = 0). Limited to $K$ times.2. The Challenge:Standard Dijkstra is too slow because "Teleport Anywhere" adds too many edges ($N^2$ edges).3. The Trick (Optimization):Layering: Iterate $K$ times. Each loop represents "What if we use 1 more teleport?"Sorting: Sort grid cells Descending.If sorted, you know that if you visit a cell with value 50, you can teleport to any cell with value 40 (seen later in the sorted list).Maintain a variable min_cost_so_far. This carries the cheapest "teleport source" cost down the list.4. The "Gotcha" (Bug Fix):Equal Values: If two cells have the same value (e.g., 5), they can teleport to each other.Fix: Process equal values in a Batch. Find the min cost of the whole group, then update the whole group at once.*/