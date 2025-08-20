#include <bits/stdc++.h>
using namespace std;

// ----------------- O(n^2) Brute Force -----------------
class BruteForceSolution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr.size(); j++) {
                if(i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

// ----------------- O(n) Optimized -----------------
class OptimizedSolution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for(int num : arr) {
            if(seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

// ----------------- Driver Code -----------------
int main() {
    vector<vector<int>> testCases = {
        {10, 2, 5, 3},       // true
        {3, 1, 7, 11},       // false
        {0, -2, 2},          // false
        {7, 15, 3, 4, 30}    // true
    };

    BruteForceSolution brute;
    OptimizedSolution opt;

    cout << "Running test cases...\n\n";
    for (int t = 0; t < testCases.size(); t++) {
        cout << "Test Case " << t+1 << ": ";
        for (auto x : testCases[t]) cout << x << " ";
        cout << "\n";

        bool ans1 = brute.checkIfExist(testCases[t]);
        bool ans2 = opt.checkIfExist(testCases[t]);

        cout << "  Brute Force O(n^2): " << (ans1 ? "true" : "false") << "\n";
        cout << "  Optimized O(n):    " << (ans2 ? "true" : "false") << "\n\n";
    }

    return 0;
}
/*// ✅ Idea:
// Instead of comparing every pair with nested loops (which is slow),
// we can use a hash set (unordered_set in C++) to remember the numbers we have seen so far.
// This way, we can check in O(1) time whether the required number exists.

// ✅ Steps:
// 1. Create an empty hash set "seen".
// 2. Loop through each number "num" in the array:
//      a) Before inserting "num" into the set,
//         check if either of these exists in the set:
//         - 2 * num (means we already saw a number that is double of current)
//         - num / 2 (only if num is even, means we already saw a number
//           that is half of current)
//      b) If either check passes, return true immediately.
//      c) Otherwise, insert "num" into the set and continue.
// 3. If the loop finishes without finding any pair, return false.

// ✅ Why this works:
// - If arr[i] == 2 * arr[j], then either "arr[j]" was seen first and we are now
//   processing "arr[i]", OR "arr[i]" was seen first and we are now processing "arr[j]".
// - By checking both conditions (double and half), we cover both directions.

// ✅ Example: [7, 15, 3, 4, 30]
// - Start with empty set {}
// - num = 7 → nothing to match → insert {7}
// - num = 15 → nothing to match → insert {7, 15}
// - num = 3 → nothing to match → insert {7, 15, 3}
// - num = 4 → nothing to match → insert {7, 15, 3, 4}
// - num = 30 → check set → 15 is already there → return true

// ✅ Time Complexity: O(n)
//    Each lookup and insert in the hash set is O(1) on average.
// ✅ Space Complexity: O(n)
//    We may store up to all elements in the set.
*/
