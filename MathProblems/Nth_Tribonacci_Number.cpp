#include <iostream>
#include <vector>
using namespace std;

// ⚠️ Important: In Tribonacci, base cases are T(0) = 0, T(1) = 1, T(2) = 1
// ❌ Do NOT return 'n' for n == 2 → T(2) should be 1, not 2
// ✅ Always initialize dp[0] = 0, dp[1] = 1, dp[2] = 1 before recursion or DP
// 💡 Avoid TLE by using memoization (store already computed values in dp[])

/*🧠 Think of it this way:
dp[n] is like a notebook where you write the answer to tribonacci(n) once it's solved.
Initially, all entries are set to -1 — meaning "not calculated yet".
So if dp[n] != -1, it means:
"Hey, we already calculated tribonacci(n) before — just return it!"
*/

int dp[38];

int solve(int n) {
    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
    return dp[n];
}

int tribonacci(int n) {
    for (int i = 0; i < 38; ++i) {
        dp[i] = -1;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    return solve(n);
}

int main() {
    int n;
    cout << "Enter n (0 <= n <= 37): ";
    cin >> n;

    if (n < 0 || n > 37) {
        cout << "Invalid input. n should be between 0 and 37.\n";
        return 1;
    }

    int result = tribonacci(n);
    cout << "Tribonacci(" << n << ") = " << result << endl;

    return 0;
}
