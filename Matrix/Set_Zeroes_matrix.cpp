#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 'col0' is our special flag for the 0-th column.
        // We need this because matrix[0][0] handles Row 0, but we also need something for Col 0.
        int col0 = 1; 

        // ==========================================
        // STEP 1: TRAVERSE AND MARK (Top -> Bottom)
        // ==========================================
        for(int i = 0; i < n; i++) {
            
            // 1. Check if the 0-th column itself has a 0
            if(matrix[i][0] == 0) {
                col0 = 0;
            }
            
            // 2. Check the rest of the row (columns 1 to m-1)
            // If we find a 0, we mark the "headers" (top row and left col)
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the left-most cell of this row
                    matrix[0][j] = 0; // Mark the top-most cell of this column
                }
            }
        }
        
        // ==========================================
        // STEP 2: FILL ZEROS (Bottom -> Up)
        // ==========================================
        // TRICK: We go from bottom to top so we don't overwrite the top-row markers early!
        for(int i = n - 1; i >= 0; i--) {
            
            // 1. Update the inner matrix (col 1 to m-1)
            for(int j = m - 1; j >= 1; j--) {
                // If the row header OR col header is 0, this cell becomes 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            
            // 2. Finally, update the 0-th column for this specific row
            // We do this last to avoid messing up calculations for the rest of the row
            if(col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    // Test Case:
    // [1, 1, 1]
    // [1, 0, 1]  -> Should become -> [1, 0, 1]
    // [1, 1, 1]                      [0, 0, 0]
    //                                [1, 0, 1]

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    Solution sol;
    sol.setZeroes(matrix);
    
    // Print Result
    cout << "Final Matrix:" << endl;
    for(auto row : matrix) {
        for(auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}