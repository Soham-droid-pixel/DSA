#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(); // Store the size of the array
        int max_len = 0;    // Initialize the maximum length found so far
        
        // Loop from 1 to n-2 because a peak cannot be at the very first or last index
        for (int i = 1; i < n - 1; i++) {
            
            // Check if current index i is a peak (higher than its neighbors)
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                
                int left = i;  // Starting point to expand left
                int right = i; // Starting point to expand right
                
                // Expand left as long as the previous element is smaller (the climb)
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--; // Move pointer to the left
                }
                
                // Expand right as long as the next element is smaller (the descent)
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++; // Move pointer to the right
                }
                
                // Calculate current mountain length: (right index - left index + 1)
                int length = right - left + 1;
                
                // Update the global maximum length found
                if (length > max_len) {
                    max_len = length;
                }
                
                // Optimization: Skip i to the end of the current mountain (right)
                // This ensures we only visit each element a limited number of times
                i = right; 
            }
        }
        
        return max_len; // Return the longest mountain length found
    }
};

int main() {
    Solution sol;
    
    // Test Case: [2,1,4,7,3,2,5] -> Mountain is [1,4,7,3,2], Length 5
    vector<int> testArr = {2, 1, 4, 7, 3, 2, 5};
    int result = sol.longestMountain(testArr);
    
    cout << "Longest Mountain Length: " << result << " (Expected: 5)" << endl;
    
    return 0;
}