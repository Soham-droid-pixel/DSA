#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n != 1) {
            if (n % 2 == 0) n /= 2;
            else if (n % 3 == 0) n /= 3;
            else if (n % 5 == 0) n /= 5;
            else return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number to check if it's ugly: ";
    cin >> num;

    if (sol.isUgly(num))
        cout << num << " is an Ugly Number." << endl;
    else
        cout << num << " is NOT an Ugly Number." << endl;

    return 0;
}
/*Ugly Number Problem – Summary Notes
💡 Definition:
A Ugly Number is a positive number whose only prime factors are 2, 3, or 5.

Examples of ugly numbers: 1, 2, 3, 4, 5, 6, 8, 10, 12, 15

Examples of non-ugly numbers: 7, 11, 14, 21, 33 (because they have other prime factors)

✅ Logic to Check If a Number is Ugly:
If n <= 0, return false (ugly numbers are positive only).

If n == 1, return true (by definition, 1 is considered an ugly number).

While n is divisible by 2, divide it by 2.

Then while divisible by 3, divide by 3.

Then while divisible by 5, divide by 5.

Finally, check if n == 1. If yes, it was made of only 2, 3, 5 → return true; otherwise → return false.

🔍 Key Concepts Learned:
Use loops to keep dividing by valid prime factors.

If you ever find n is no longer divisible by 2, 3, or 5, and it's not 1, then it has some other factor → not ugly.

Don't return too early inside loops unless a condition clearly ends the decision.

*/