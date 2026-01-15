#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ==========================================
    // APPROACH 1: OPTIMIZED (In-Place, O(1) Space)
    // ==========================================
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // STEP 1: Transpose (Swap across Main Diagonal)
        // We swap matrix[i][j] with matrix[j][i]
        for (int i = 0; i < n; i++) {
            // CRITICAL: j starts at 'i' to avoid double-swapping and only touch Upper Triangle
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // STEP 2: Reverse Each Row
        // This flips the matrix horizontally to complete the 90-degree rotation
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // ==========================================
    // APPROACH 2: BRUTE FORCE (Extra Space O(N^2))
    // ==========================================
    void rotateBruteForce(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Create a separate dummy matrix
        vector<vector<int>> dummy(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // The Formula: Old (i, j) moves to New (j, n-1-i)
                dummy[j][n - 1 - i] = matrix[i][j];
            }
        }
        // Copy back to original matrix
        matrix = dummy;
    }
};

// Function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;

    // Test Case
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Using Optimized Approach
    sol.rotate(matrix);

    cout << "\nRotated Matrix (90 deg Clockwise):" << endl;
    printMatrix(matrix);

    return 0;
}

/* ========================================================================
                             NOTEBOOK NOTES
========================================================================

1. The Brute Force Code: dummy[j][n-1-i]
------------------------------------------------------------
You asked about the formula. Let's trace where elements should go when rotated 90° clockwise.

Imagine a 3 x 3 matrix (n=3).

First Row (i=0) becomes the Last Column (col = 2)
   matrix[0][0] -> Top-Right (0, 2)
   matrix[0][1] -> Middle-Right (1, 2)
   matrix[0][2] -> Bottom-Right (2, 2)

Pattern: The Row index 0 turned into Column index 2 (which is n-1). 
The Column index became the Row index.

General Rule for 90° Rotation:
   - The Old Column (j) becomes the New Row.
   - The Old Row (i) becomes the New Column... but flipped.
     Row 0 -> Col n-1
     Row 1 -> Col n-2
     Row i -> Col n-1-i

Therefore the formula:
   dummy[j][n-1-i] = matrix[i][j]
   (New Row is j, New Col is n-1-i)


2. The Optimized Code: Why j = i?
------------------------------------------------------------
In the Transpose step, we are swapping elements across the Main Diagonal 
(the line from top-left to bottom-right).

The Problem with starting at j=0:
   If you iterate j from 0 to n, you will visit every cell twice.
   - When i=0, j=1: You swap (0,1) with (1,0). (Good!)
   - ...later, when i=1, j=0: You swap (1,0) with (0,1). (Bad!)
   You just swapped them back to their original positions!

The Solution (j = i):
   By starting j at i, you only look at the Upper Triangle of the matrix 
   (the part above and including the diagonal).
   
   - When i=0, you swap (0,1), (0,2), etc.
   - When i=1, you start at (1,1). You skip (1,0) because (0,1) already handled that swap.

Visual Loop Trace:
   i=0: Swaps (0,0)<->(0,0), (0,1)<->(1,0), (0,2)<->(2,0)
   i=1: Swaps (1,1)<->(1,1), (1,2)<->(2,1) (Notice we skipped (1,0))
   i=2: Swaps (2,2)<->(2,2) (Done)

This ensures every pair is swapped exactly once.
*/