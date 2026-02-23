#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Method 1: Your accepted built-in solution O(n)
    vector<int> countBitsBuiltIn(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            result.push_back(__builtin_popcount(i));
        }
        return result;
    }

    // Method 2: Your manual math solution (Fixed) O(n log n)
    vector<int> countBitsManual(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int num = i; 
            while (num > 0) {
                int rem = num % 2;
                if (rem == 1) { 
                    count++;
                }
                num = num / 2;
            }
            result.push_back(count);
        }
        return result;
    }

    // Method 3: The O(n) "Pro" Interview Solution (Dynamic Programming)
    vector<int> countBitsOptimal(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};

// --- Helper function to print vectors ---
void printVector(const vector<int>& vec, const string& methodName) {
    cout << methodName << ": [";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

// --- Main Function for Testing ---
int main() {
    Solution sol;
    int n = 5;

    cout << "Input: n = " << n << "\n" << endl;

    vector<int> res1 = sol.countBitsBuiltIn(n);
    printVector(res1, "Method 1 (Built-In)");

    vector<int> res2 = sol.countBitsManual(n);
    printVector(res2, "Method 2 (Manual)");

    vector<int> res3 = sol.countBitsOptimal(n);
    printVector(res3, "Method 3 (Optimal O(n))");

    return 0;
}