#include <iostream>
#include <vector>
#include <algorithm> // Required only for the 3rd (STL) approach

using namespace std;

class Solution {
public:
    // ==========================================================
    // SOLUTION 1: Optimized Binary Search (Manual) - BEST & REQUESTED AT TOP
    // ==========================================================
    // Time Complexity: O(log N) - Splits the array in half every time.
    // Space Complexity: O(1)
    // Logic: Standard Binary Search looking for the first element > target.
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;

        // Special check: If target is >= the biggest letter, we must wrap around
        // to the first letter immediately. This saves time.
        if (target >= letters.back()) {
            return letters[0];
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] <= target) {
                // If mid is smaller or equal, the answer must be to the Right
                low = mid + 1;
            } else {
                // If mid is greater, it's a candidate! 
                // But we try to find a smaller valid one to the Left.
                high = mid - 1;
            }
        }

        // 'low' will end up at the index of the smallest character > target.
        // Because of the wrap-around check at the start, 'low' is guaranteed valid.
        return letters[low];
    }

    // ==========================================================
    // SOLUTION 2: Linear Scan (Your Logic, Corrected)
    // ==========================================================
    // Time Complexity: O(N) - Checks every element.
    // Space Complexity: O(1)
    // Logic: The array is sorted, so the first char > target is the answer.
    char nextGreatestLetterLinear(vector<char>& letters, char target) {
        for (int i = 0; i < letters.size(); i++) {
            // Because it is sorted, the first one we find that is bigger
            // is guaranteed to be the "smallest greater".
            if (letters[i] > target) {
                return letters[i];
            }
        }
        // If we finish loop without returning, wrap around to start.
        return letters[0];
    }

    // ==========================================================
    // SOLUTION 3: C++ STL One-Liner (Pro Approach)
    // ==========================================================
    // Time Complexity: O(log N) - upper_bound uses binary search internally.
    // Space Complexity: O(1)
    char nextGreatestLetterSTL(vector<char>& letters, char target) {
        // upper_bound returns iterator to first element strictly > target
        auto it = upper_bound(letters.begin(), letters.end(), target);

        // If iterator reached the end, wrap around to index 0
        if (it == letters.end()) {
            return letters[0];
        }
        return *it;
    }
};

// --- Driver Code to Test All Approaches ---
int main() {
    Solution sol;

    // Test Case 1
    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    cout << "--- Test Case 1 (Target 'a') ---" << endl;
    cout << "Binary Search (Best): " << sol.nextGreatestLetter(letters1, target1) << endl;
    cout << "Linear Scan:          " << sol.nextGreatestLetterLinear(letters1, target1) << endl;
    cout << "STL upper_bound:      " << sol.nextGreatestLetterSTL(letters1, target1) << endl;
    cout << endl;

    // Test Case 2
    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    cout << "--- Test Case 2 (Target 'c') ---" << endl;
    cout << "Binary Search (Best): " << sol.nextGreatestLetter(letters2, target2) << endl;
    cout << "Linear Scan:          " << sol.nextGreatestLetterLinear(letters2, target2) << endl;
    cout << "STL upper_bound:      " << sol.nextGreatestLetterSTL(letters2, target2) << endl;
    cout << endl;

    // Test Case 3 (Wrap Around)
    vector<char> letters3 = {'x', 'x', 'y', 'y'};
    char target3 = 'z';
    cout << "--- Test Case 3 (Target 'z') ---" << endl;
    cout << "Binary Search (Best): " << sol.nextGreatestLetter(letters3, target3) << endl;
    cout << "Linear Scan:          " << sol.nextGreatestLetterLinear(letters3, target3) << endl;
    cout << "STL upper_bound:      " << sol.nextGreatestLetterSTL(letters3, target3) << endl;

    return 0;
}