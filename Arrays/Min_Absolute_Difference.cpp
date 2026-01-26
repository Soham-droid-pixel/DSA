#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int min_diff = INT_MAX;
        vector<vector<int>> result;
        
        // Safety check: If array has fewer than 2 elements, return empty
        if (arr.size() < 2) return result;

        for(int i = 0; i < arr.size() - 1; i++) {
            int curr_diff = arr[i+1] - arr[i];
            
            if(curr_diff < min_diff) {
                min_diff = curr_diff;
                result.clear();
                // Explicitly create the vector for compatibility
                result.push_back({arr[i], arr[i+1]}); 
            } 
            else if (curr_diff == min_diff) {
                result.push_back({arr[i], arr[i+1]});
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 2, 1, 3};
    
    vector<vector<int>> output = sol.minimumAbsDifference(nums);
    
    cout << "Output pairs: [ ";
    // FIXED: Changed variable name from 'pair' to 'vec' to avoid conflicts
    for(auto vec : output) {
        cout << "[" << vec[0] << "," << vec[1] << "] ";
    }
    cout << "]" << endl;

    return 0;
}