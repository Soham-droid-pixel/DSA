#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans; // Stores all self-dividing numbers
        
        for (int n = left; n <= right; n++) {
            int temp = n;      // Copy of the number for digit checking
            bool ok = true;    // Flag to check if it's self-dividing
            
            while (temp > 0) {
                int digit = temp % 10; // Get last digit
                
                // Rule 1: No zero digits allowed
                // Rule 2: Every digit must divide the original number
                if (digit == 0 || n % digit != 0) {
                    ok = false;
                    break;
                }
                
                temp /= 10; // Remove last digit
            }
            
            if (ok) ans.push_back(n); // Add to result if valid
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    int left = 1, right = 22;

    vector<int> result = s.selfDividingNumbers(left, right);
    
    cout << "[ ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}

/*
================ MAIN CONCEPT =================
1️⃣ Loop from 'left' to 'right'.
2️⃣ For each number:
     - Copy it to 'temp'.
     - Extract each digit (digit = temp % 10).
     - If digit == 0 → Not allowed.
     - If number % digit != 0 → Not self-dividing.
3️⃣ If all digits pass → Add to result.
4️⃣ Return the vector of results.

🚫 COMMON ERRORS TO AVOID:
- Don't use 'arr[]' without size → use vector<int>.
- Don't insert before checking all digits → push_back after.
- Don't forget zero digit check.
- Use correct loop variable (avoid reusing 'left' or 'n' wrongly).
*/
