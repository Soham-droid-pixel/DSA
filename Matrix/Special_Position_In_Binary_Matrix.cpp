#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), counter = 0;
        vector<int> rowCount(m, 0), colCount(n, 0);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    counter++;
                }
            }
        }
        return counter;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    cout << "Special positions: " << sol.numSpecial(mat) << " (Expected: 1)" << endl;
    return 0;
}