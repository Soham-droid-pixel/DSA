#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;                      // Stores the lucky numbers we find
        int m = matrix.size();                 // Number of rows in the matrix
        int n = matrix[0].size();               // Number of columns in the matrix

        // Loop through each row of the matrix
        for (int i = 0; i < m; i++) {
            int minVal = matrix[i][0];          // Assume first element in row is the smallest
            int col = 0;                        // Column index of the smallest element

            // Step 1: Find the minimum element in this row
            for (int j = 1; j < n; j++) {       // Loop through the rest of the columns in the row
                if (matrix[i][j] < minVal) {    // If a smaller element is found
                    minVal = matrix[i][j];      // Update the smallest value
                    col = j;                    // Remember its column index
                }
            }

            // Step 2: Check if this min value is the maximum in its column
            bool isLucky = true;                // Assume it is lucky until proven otherwise
            for (int k = 0; k < m; k++) {       // Loop through all rows in that column
                if (matrix[k][col] > minVal) {  // If any element in the column is greater
                    isLucky = false;            // Then it's not the maximum in the column
                    break;                      // No need to check further
                }
            }

            // Step 3: If it's both min in row and max in column, store it
            if (isLucky) ans.push_back(minVal);
        }

        return ans;                             // Return all lucky numbers found
    }
};

int main() {
    // Example input
    vector<vector<int>> matrix = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    };

    Solution sol;
    vector<int> result = sol.luckyNumbers(matrix);

    // Output the result
    cout << "Lucky Numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
