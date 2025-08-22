#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = result ^ (start + (2 * i));
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 5, start1 = 0;
    cout << "Input: n = " << n1 << ", start = " << start1 << endl;
    cout << "Output: " << sol.xorOperation(n1, start1) << endl;

    // Example 2
    int n2 = 4, start2 = 3;
    cout << "Input: n = " << n2 << ", start = " << start2 << endl;
    cout << "Output: " << sol.xorOperation(n2, start2) << endl;

    return 0;
}
