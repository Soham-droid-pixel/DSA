#include <bits/stdc++.h>  // includes all standard C++ libraries
using namespace std;

/*
========================================
Approach 1: Square + sort (O(n log n))
========================================
- Step 1: Square each element
- Step 2: Use STL sort() to sort the array
- Complexity: O(n log n)
- STL function: sort(begin, end)
  -> sort() internally uses Introsort 
     (QuickSort + HeapSort + InsertionSort)
  -> Always gives O(n log n) worst-case
*/
vector<int> sortedSquares_NlogN(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] * nums[i];  // square each element
    }
    sort(nums.begin(), nums.end());   // sort entire vector
    return nums;
}

/*
========================================
Approach 2: Two-pointer method (O(n))
========================================
- Step 1: Use two pointers: left at start, right at end
- Step 2: Compare absolute values
- Step 3: Put larger square at the end of result[]
- Step 4: Move pointer inward
- Complexity: O(n)
- STL function used: abs(x) → gives absolute value
*/
vector<int> sortedSquares_On(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n); // output array of size n
    int left = 0, right = n - 1;
    int pos = n - 1;       // fill result[] from the back

    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos--] = nums[left] * nums[left];
            left++;
        } else {
            result[pos--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}

// Utility function to print a vector
void printVector(vector<int> &v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> nums2 = {-7, -3, 2, 3, 11};

    cout << "Input 1: ";
    printVector(nums1);

    // Approach 1: O(n log n)
    vector<int> res1 = sortedSquares_NlogN(nums1);
    cout << "Approach 1 (O(n log n)) result: ";
    printVector(res1);

    // Approach 2: O(n)
    vector<int> res2 = sortedSquares_On(nums2);
    cout << "Input 2: ";
    printVector(nums2);
    cout << "Approach 2 (O(n)) result: ";
    printVector(res2);

    return 0;
}
