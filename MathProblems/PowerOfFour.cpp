#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n = n / 4;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (sol.isPowerOfFour(n)) {
        cout << "Perfect power of four" << endl;
    } else {
        cout << "Not perfect power of four" << endl;
    }

    return 0;
}
