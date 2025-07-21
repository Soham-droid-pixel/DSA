#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1)
            return n;
        else
            return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << sol.fib(n) << endl;
    return 0;
}
/*#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int prev2 = 0, prev1 = 1, current;
        for(int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << sol.fib(n) << endl;
    return 0;
}
Use this imp*/