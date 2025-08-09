#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq; // Step 1: Store frequency of each number
        
        // Count frequencies
        for (int num : arr) {
            freq[num]++;
        }
        
        int result = -1; // Default result if no lucky number found
        
        // Step 2: Check for lucky condition
        for (auto& p : freq) {
            int num = p.first;
            int count = p.second;
            
            // Lucky condition: frequency == number
            if (count == num) {
                result = max(result, num); // Keep the largest lucky number
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {2, 2, 3, 4};
    cout << sol.findLucky(arr1) << endl; // Expected output: 2
    
    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    cout << sol.findLucky(arr2) << endl; // Expected output: 3
    
    vector<int> arr3 = {2, 2, 2, 3, 3};
    cout << sol.findLucky(arr3) << endl; // Expected output: -1
    
    return 0;
}

/*
-----------------------------------------
📌 LAST-MINUTE NOTES:
-----------------------------------------
1. "Lucky" means: frequency of a number == the number itself.
2. Always count frequencies first (unordered_map<int,int>).
3. Track the largest lucky number found so far (result = max(result, num)).
4. Return -1 if no lucky number exists.

-----------------------------------------
⚠️ COMMON ERRORS TO AVOID:
-----------------------------------------
❌ Don't return inside the loop immediately — you'll miss other candidates.
❌ Don't use `maxfreq` here; it's not needed for this problem.
❌ Always use braces `{}` with loops if more than one statement is inside.
❌ Make sure you compare (count == num), not (count > num) or similar.

💡 Pattern: 
This is a variation of "max occurrence" problems — same frequency-count step, 
but selection criteria changes based on the problem statement.

-----------------------------------------
*/
