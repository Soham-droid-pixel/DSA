#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        // Convert the integer into a string so we can modify its digits directly
        string s = to_string(num);

        // Loop through each digit (character) in the string
        for (char &c : s) {       // '&c' means we take reference, not copy
            if (c == '6') {       // as soon as we find the first '6'
                c = '9';          // change it into '9'
                break;            // stop immediately (only one change allowed)
            }
        }

        // Convert the modified string back into an integer
        return stoi(s);           // stoi = string → integer
    }
};

// Optional main function for testing
int main() {
    Solution sol;
    int num;

    cout << "Enter number (only digits 6 and 9): ";
    cin >> num;

    int result = sol.maximum69Number(num);
    cout << "Maximum number after one change: " << result << endl;

    return 0;
}
