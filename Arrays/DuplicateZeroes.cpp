#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int originalSize = arr.size(); // Store the original size (needed to avoid extra elements after insertions)

        for (int i = 0; i < originalSize; i++) {
            if (arr[i] == 0) { 
                // Insert a zero at the next position
                arr.insert(arr.begin() + i + 1, 0);
                
                // Skip the next element (which is the zero we just inserted)
                i++;
            }
        }

        // Remove extra elements so the size remains the same as original
        arr.resize(originalSize);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,0,2,3,0,4,5,0};

    sol.duplicateZeros(arr);

    // Printing result
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
======================== REVISION NOTES ========================

PROBLEM:
    Modify array in-place: duplicate each zero, shifting elements to the right.
    Elements beyond original length are dropped.

STEPS IN SOLUTION:
    1. Store the original size before inserting new zeros.
    2. Loop through the array using index `i`.
    3. If current element is zero:
         - Insert another zero at position i+1.
         - Increment `i` to skip the inserted zero.
    4. After the loop, `arr` might have extra elements → use `resize(originalSize)`.

KEY POINTS TO REMEMBER (SYNTAX & LOGIC):
    ✅ Insert element in vector:
        arr.insert(arr.begin() + position, value);
    ✅ Resize vector to fixed length:
        arr.resize(new_size);
    ✅ Be careful when inserting while iterating — must skip inserted elements to avoid infinite loop.
    ✅ Always store the original size before insertion because size changes dynamically.

COMMON MISTAKES TO AVOID:
    ❌ Forgetting to increment `i` after inserting → causes repeated insertion or infinite loop.
    ❌ Forgetting to resize → output has extra elements beyond original.
    ❌ Using `arr[i] = 0` instead of `insert()` → overwrites but doesn’t shift.
    ❌ Not storing `originalSize` → resize will shrink too much or too little.

================================================================
*/
