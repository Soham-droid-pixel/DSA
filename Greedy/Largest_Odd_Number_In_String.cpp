#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {   // check if digit is odd
                return num.substr(0, i + 1); // return substring from 0 to i
            }
        }
        return ""; // no odd digit found
    }
};

int main() {
    Solution sol;

    // Example test cases
    string num1 = "52";
    string num2 = "4206";
    string num3 = "35427";

    cout << "Input: " << num1 << " -> Output: " << sol.largestOddNumber(num1) << endl;
    cout << "Input: " << num2 << " -> Output: " << sol.largestOddNumber(num2) << endl;
    cout << "Input: " << num3 << " -> Output: " << sol.largestOddNumber(num3) << endl;

    return 0;
}

/*
---------------------------------------------------------
📝 CONCEPTS & EXPLANATION
---------------------------------------------------------

🔹 Problem:
- You are given a numeric string "num".
- Find the largest odd number that is a non-empty substring.
- Return it as a string, or "" if no odd number exists.

---------------------------------------------------------
🔹 Key Insight:
- A number is odd if its last digit is odd (1, 3, 5, 7, 9).
- The largest possible substring that is odd MUST end with an odd digit.
- So, we just need to find the **last odd digit** from right to left.

---------------------------------------------------------
🔹 Code Walkthrough:

1. Loop from end to start:
   for (int i = num.size() - 1; i >= 0; i--)

2. Check if current digit is odd:
   (num[i] - '0') % 2 != 0
   - num[i] is a character ('0'..'9').
   - Subtracting '0' converts char to int.
     Example: '7' - '0' = 7.

3. If odd digit found:
   return num.substr(0, i + 1);
   - substr(startIndex, length)
   - Here: startIndex = 0, length = i+1
   - This keeps the entire substring from the start until that odd digit.

4. If no odd digit found:
   return "".

---------------------------------------------------------
🔹 Dry Run:

Example 1: num = "52"
- Traverse from right:
  '2' -> even
  '5' -> odd → return "5"

Output: "5"

Example 2: num = "4206"
- Traverse from right:
  '6' -> even
  '0' -> even
  '2' -> even
  '4' -> even
- No odd digit found → return ""

Output: ""

Example 3: num = "35427"
- Traverse from right:
  '7' -> odd → return "35427"

Output: "35427"

---------------------------------------------------------
🔹 Complexity:
- Time Complexity: O(n) (single loop over string)
- Space Complexity: O(1) (constant extra space)

---------------------------------------------------------
🔥 Key Learning:
- Always check the **property of the problem** (odd numbers depend only on last digit).
- Instead of brute forcing all substrings (O(n^2)), we reduced it to O(n).
---------------------------------------------------------
*/
