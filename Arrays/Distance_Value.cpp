#include <iostream>
#include <vector>
#include <cmath> // Required for abs()

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int counter = 0;
        for(int i = 0; i < arr1.size(); i++) {
            bool isSafe = 1;
            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    isSafe = 0;
                    break;
                }
            }
            if(isSafe) {
                counter++;
            }
        }
        return counter;
    }
};

// --- Main Function for Testing ---
int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1_1 = {4, 5, 8};
    vector<int> arr2_1 = {10, 9, 1, 8};
    int d1 = 2;
    cout << "Test Case 1 Output: " << sol.findTheDistanceValue(arr1_1, arr2_1, d1) << " (Expected: 2)" << endl;

    // Test Case 2
    vector<int> arr1_2 = {1, 4, 2, 3};
    vector<int> arr2_2 = {-4, -3, 6, 10, 20, 30};
    int d2 = 3;
    cout << "Test Case 2 Output: " << sol.findTheDistanceValue(arr1_2, arr2_2, d2) << " (Expected: 2)" << endl;

    // Test Case 3
    vector<int> arr1_3 = {2, 1, 100, 3};
    vector<int> arr2_3 = {-5, -2, 10, -3, 7};
    int d3 = 6;
    cout << "Test Case 3 Output: " << sol.findTheDistanceValue(arr1_3, arr2_3, d3) << " (Expected: 1)" << endl;

    return 0;
}