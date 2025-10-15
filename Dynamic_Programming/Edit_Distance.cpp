#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];
                    
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }
        
        return dp[m][n];
    }
};

// main() function to test the Solution class
int main() {
    Solution sol;

    // --- Test Case 1 ---
    string word1_1 = "horse";
    string word2_1 = "ros";
    int result1 = sol.minDistance(word1_1, word2_1);
    cout << "Input: word1 = \"" << word1_1 << "\", word2 = \"" << word2_1 << "\"" << endl;
    cout << "Output: " << result1 << endl; // Expected: 3
    cout << "-----------------------------------" << endl;

    // --- Test Case 2 ---
    string word1_2 = "intention";
    string word2_2 = "execution";
    int result2 = sol.minDistance(word1_2, word2_2);
    cout << "Input: word1 = \"" << word1_2 << "\", word2 = \"" << word2_2 << "\"" << endl;
    cout << "Output: " << result2 << endl; // Expected: 5
    cout << "-----------------------------------" << endl;

    return 0;
}

/*
====================================================================
## Easy Notes: Edit Distance (Dynamic Programming) Algorithm
====================================================================

**The Goal:**
Find the minimum number of operations (insert, delete, replace) to change `word1` into `word2`.

**The Strategy (Dynamic Programming):**
We build a grid (a 2D vector called `dp`) that helps us find the answer by solving smaller, easier subproblems first.

**Meaning of `dp[i][j]`:**
Each cell `dp[i][j]` in our grid stores a single number: the minimum cost to convert the first `i` characters of `word1` into the first `j` characters of `word2`.

**Step 1: The Base Cases (Setting up the Grid's Borders)**
* The first row (`dp[0][j]`) represents converting an empty string to `word2`. This requires `j` insertions. So, we fill this row with `0, 1, 2, 3, ...`.
* The first column (`dp[i][0]`) represents converting `word1` to an empty string. This requires `i` deletions. So, we fill this column with `0, 1, 2, 3, ...`.

**Step 2: The Main Logic (Filling the Inside of the Grid)**
We loop through the grid and fill each cell `dp[i][j]` based on one of two rules:

* **Rule 1: If the characters match (`word1[i-1] == word2[j-1]`):**
    * No operation is needed for this character.
    * The cost is the same as the problem without these characters. We just copy the value from the top-left diagonal cell.
    * `dp[i][j] = dp[i-1][j-1];`

* **Rule 2: If the characters DO NOT match:**
    * We must perform an operation, which costs 1. We choose the operation that comes from the cheapest previous step.
    * We look at our three neighbors:
        * `dp[i-1][j]` (cell above): Represents a **Deletion**.
        * `dp[i][j-1]` (cell to the left): Represents an **Insertion**.
        * `dp[i-1][j-1]` (cell on the diagonal): Represents a **Replacement**.
    * We find the minimum value of these three neighbors and add 1.
    * `dp[i][j] = 1 + min(deletion, insertion, replacement);`

**The Final Answer:**
After the grid is completely filled, the final answer is the number in the bottom-right corner: `dp[m][n]`.

*/