#include <bits/stdc++.h>  // Includes all standard libraries
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Assume true unless proven false
        bool val = true;
        
        // Calculate slope components from first two points
        // dx = change in x, dy = change in y
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        
        // Loop through remaining points to check collinearity
        for (int i = 2; i < coordinates.size(); i++) {
            int dx2 = coordinates[i][0] - coordinates[0][0];
            int dy2 = coordinates[i][1] - coordinates[0][1];
            
            // Cross multiplication to avoid division precision errors
            // If slopes are different, points are not on the same line
            if (dy * dx2 != dy2 * dx) {
                val = false;   // Found a point that doesn't match slope
                break;         // No need to check further
            }
        }
        return val;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> coords = {{1,2},{2,3},{3,4}};
    cout << (sol.checkStraightLine(coords) ? "True" : "False") << endl;
    return 0;
}

/*
---------------- REVISION NOTES ----------------

✅ Key Points to Remember:
1. Always pick the slope from the first two points as reference.
2. Use cross multiplication:
      (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)
   to avoid division errors and floating-point precision issues.
3. Compare all points to the first point's slope.

⚠️ Common Errors to Avoid:
1. ❌ Out-of-bounds indexing:
      Avoid using coordinates[i+1] when i is at the last element.
2. ❌ Integer division:
      Do not calculate slope as dy/dx directly.
      Use cross multiplication instead.
3. ❌ Overcomplication:
      No need to store all slopes in an array — one reference slope is enough.
4. ❌ Uninitialized variables:
      Always initialize boolean flags like `val = true` before using them.

🎯 Revision Tip:
Practice 2–3 problems where slope logic is applied (like checking parallel/perpendicular lines) 
to make slope handling natural before moving to harder geometry questions.
*/
