#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> seen;   // map to count frequency of each number
        vector<int> result;
        int p = nums.size() / 3;       // threshold = floor(n/3)

        // Step 1: Count frequency of each element
        for (int num : nums) {
            seen[num]++;
        }

        // Step 2: Collect elements whose count > n/3
        for (auto &it : seen) {                 // it = pair<const int,int>
            if (it.second > p) {                // check frequency
                result.push_back(it.first);     // store the element itself
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> nums1 = {3,2,3};
    vector<int> nums2 = {1};
    vector<int> nums3 = {1,2};

    vector<int> res1 = sol.majorityElement(nums1);
    vector<int> res2 = sol.majorityElement(nums2);
    vector<int> res3 = sol.majorityElement(nums3);

    // Print results
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    cout << "Output 3: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}
/*
---

📘 **Notes for Majority Element II Code**

1. **`unordered_map<int,int> seen;`**

   * Stores frequency of each number.
   * `key = element from nums`
   * `value = frequency of that element`

2. **`int p = nums.size()/3;`**

   * Problem requires elements that appear more than `⌊n/3⌋` times.
   * Example: If `n = 6`, threshold `p = 2`.

3. **Counting loop**

   ```cpp
   for (int num : nums) {
       seen[num]++;
   }
   ```

   * Iterates through array.
   * Increments count of each number in `seen`.

4. **Filtering loop**

   ```cpp
   for (auto &it : seen) {
       if (it.second > p) {
           result.push_back(it.first);
       }
   }
   ```

   * Each element in `unordered_map` is a `pair<const int, int>`.
   * `it.first` → key (the element)
   * `it.second` → value (frequency)
   * `auto &it` = shorthand for `pair<const int,int>& it`, avoids copies.

5. **Result**

   * Stores only numbers (not counts) that appear more than `n/3` times.

6. **`main()`**

   * Tests with sample inputs: `[3,2,3]`, `[1]`, `[1,2]`.
   * Prints results.

---

*/