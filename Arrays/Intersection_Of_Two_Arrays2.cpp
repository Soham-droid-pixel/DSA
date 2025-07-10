#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Count frequency of elements in nums1
        for (int num : nums1) {
            freq[num]++;
        }

        // Check common elements in nums2
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};

int main() {
    // Example input
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution sol;
    vector<int> result = sol.intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
/*1. What if arrays are sorted?
Use two pointers to scan both arrays in linear time.

2. If nums1 is smaller than nums2?
Use hash map on nums1 (smaller one) to reduce memory usage.

3. If nums2 is stored on disk and memory is limited?
Load chunks of nums2 into memory.

Still keep a hash map of nums1 in memory.

Stream nums2 and match it with the map (disk-based processing / MapReduce logic).

*/
// Follow-up Optimizations:
// 1. If arrays are sorted → use two-pointer approach for O(n + m) time.
// 2. If nums1 is smaller → build hashmap on nums1 to save memory.
// 3. If nums2 is on disk and memory is limited → 
//    stream nums2 in chunks, keep hashmap of nums1 in memory and check matches.
/*
---

## 🧠 Detailed Explanation:

---

### ✅ 1. **What if arrays are already sorted?**

**Use Two Pointers Approach:**

* Since both arrays are sorted, you can use two indices (`i` and `j`) to walk through both arrays at the same time.
* If `nums1[i] == nums2[j]`, it's a match → add to result.
* If `nums1[i] < nums2[j]`, move pointer `i` ahead.
* If `nums1[i] > nums2[j]`, move pointer `j` ahead.

⏱ **Time Complexity**: O(n + m) — very efficient.

---

### ✅ 2. **If `nums1` is smaller than `nums2`?**

Use **hash map on the smaller array** (`nums1`) to save memory.

* Hash maps use extra space. So build the map on the **smaller array**.
* Then scan the larger array (`nums2`) and check for matches.

🔍 This is **memory-efficient** when one array is very large.

---

### ✅ 3. **If `nums2` is on disk and memory is limited?**

Let’s say:

* `nums2` is **very large** and stored on disk (not in memory).
* We cannot load it all into RAM.

Then:

* Load `nums2` in **chunks (streaming)**.
* Keep `nums1` in memory as a hash map (assuming it fits).
* For each chunk of `nums2`, check matches against the hash map.
* This is like how **MapReduce** or **big data tools** work.

---

*/