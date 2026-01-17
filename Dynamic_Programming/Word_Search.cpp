#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Main function to start the search
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();       // Rows
        int n = board[0].size();    // Columns

        // Step 1: Iterate through every cell to find the first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // If the first char matches, launch the recursive search (DFS)
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true; // Found the full word!
                    }
                }
            }
        }
        return false; // Tried all starting points, didn't find it.
    }

    // Step 2: Recursive Backtracking Function
    // i, j = current cell coordinates
    // k = index of the character we are looking for in 'word'
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        
        // BASE CASE 1: SUCCESS
        // If k reached the word length, we found all characters!
        if (k == word.length()) {
            return true;
        }

        // BASE CASE 2: FAILURE / BOUNDARY CHECKS
        // 1. Out of bounds (row or col)
        // 2. Character does NOT match word[k]
        // 3. Cell is already visited (marked as '#')
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }

        // --- DO (MARK) ---
        // Temporarily mark this cell as visited so we don't go back to it in this path
        char temp = board[i][j];
        board[i][j] = '#';

        // --- RECURSE (EXPLORE) ---
        // Try moving in all 4 directions: Down, Up, Right, Left
        bool found = dfs(board, word, i + 1, j, k + 1) || // Down
                     dfs(board, word, i - 1, j, k + 1) || // Up
                     dfs(board, word, i, j + 1, k + 1) || // Right
                     dfs(board, word, i, j - 1, k + 1);   // Left

        // --- UNDO (BACKTRACK) ---
        // CRITICAL: Change the cell back to its original letter!
        // This allows other paths to use this cell later.
        board[i][j] = temp;

        return found;
    }
};

int main() {
    Solution sol;

    // Test Case: Grid containing "ABCCED"
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";

    cout << "Board:" << endl;
    for(auto row : board) {
        cout << "[ ";
        for(char c : row) cout << c << " ";
        cout << "]" << endl;
    }
    cout << "Searching for: " << word << endl;

    if (sol.exist(board, word)) {
        cout << "Result: Found! (true)" << endl;
    } else {
        cout << "Result: Not Found (false)" << endl;
    }

    return 0;
}

/* ========================================================================
                             NOTEBOOK NOTES
========================================================================

1. The Pattern: "Backtracking" (DFS)
   -----------------------------------------------------
   This is NOT a simple matrix iteration. It is a "Pathfinding" problem.
   We use Recursion to simulate walking through a maze.

2. The "Do - Recurse - Undo" Template
   -----------------------------------------------------
   Every backtracking problem follows this structure:
   
   a. Base Case (Win): If index == word.length(), return true.
   b. Base Case (Fail): If out of bounds OR wrong letter, return false.
   c. DO (Mark): board[i][j] = '#' (Mark as visited so we don't loop).
   d. RECURSE: Check neighbors (dfs(i+1), dfs(i-1)...).
   e. UNDO (Backtrack): board[i][j] = original_char (Clean up logic!).

3. Why "Undo"? (The Backtracking Part)
   -----------------------------------------------------
   If we go down a path A -> B -> C and hit a dead end, we must return to B.
   But 'C' is currently marked as '#'.
   We must change '#' back to 'C' so that a different path (e.g., from D -> C)
   can use it if needed.

4. Complexity
   -----------------------------------------------------
   - Time: O(N * M * 4^L) -> Roughly. For every cell, we might check 3-4 directions for L steps.
   - Space: O(L) -> The recursion stack depth is equal to the word length.
*/