#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * Determines if all courses can be finished given the prerequisites.
     * Uses Kahn's Algorithm (BFS-based Topological Sort).
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build the Adjacency List and calculate In-Degrees
        // adj[u] contains a list of courses that depend on course u.
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (auto& edge : prerequisites) {
            int course = edge[0]; // Course ai
            int prereq = edge[1]; // Prerequisite bi
            
            // Directed edge: prereq -> course
            adj[prereq].push_back(course);
            
            // Increment in-degree for the dependent course
            inDegree[course]++;
        }

        // 2. Identify all courses with zero prerequisites
        // These are our starting points (entry-level courses).
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i); //
            }
        }

        // 3. Process courses using BFS
        int count = 0; // Tracks how many courses we've successfully "taken"
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++; //

            // For every course that depends on the current course
            for (int neighbor : adj[curr]) {
                // Satisfy one prerequisite for the neighbor
                inDegree[neighbor]--; 
                
                // If all prerequisites are satisfied, add to queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. Return true if we processed all courses (no cycles found)
        return count == numCourses;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Possible to finish
    int n1 = 2;
    vector<vector<int>> pre1 = {{1, 0}}; 
    cout << "Test Case 1 (Possible): " << (sol.canFinish(n1, pre1) ? "True" : "False") << endl;

    // Test Case 2: Impossible due to cycle
    int n2 = 2;
    vector<vector<int>> pre2 = {{1, 0}, {0, 1}}; 
    cout << "Test Case 2 (Impossible): " << (sol.canFinish(n2, pre2) ? "True" : "False") << endl;

    // Test Case 3: Complex valid graph
    int n3 = 4;
    vector<vector<int>> pre3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Test Case 3 (Complex Valid): " << (sol.canFinish(n3, pre3) ? "True" : "False") << endl;

    return 0;
}