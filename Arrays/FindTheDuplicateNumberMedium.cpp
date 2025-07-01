#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size (should be n+1 for values in [1,n])" << endl;
    cin >> n;

    int nums[n];
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Phase 1: Detect cycle
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the start of cycle (duplicate)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    cout << "Duplicate number is: " << slow << endl;

    return 0;
}
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    result=nums[i];
                }
                
            }
        }
        return result;
    }
};this will exceed time complexity..dont use this method.Use Floyd Algorithm by detecting cycle*/
/*
## 📝 Find the Duplicate Number – Revision Notes (Floyd’s Algorithm)

---

### 📌 **Problem Summary**

* Given an array of size `n+1` containing integers from `1` to `n`.
* Exactly **one number is repeated**, may appear multiple times.
* Must **not modify the array**.
* Must use **only constant extra space**.
* Return the **duplicate number**.

---

### ❗ **Constraints to Remember**

* Do **not** sort the array (modifies it).
* Do **not** use extra data structures (like hash maps/sets).
* Must run in **O(n)** time.
* Must use **O(1)** space.

---

### 💡 **Core Concept**

* Treat the array like a **linked list**, where:

  * Each element is a pointer to the **next index**.
* Due to the repeated number, a **cycle** is formed in this list-like structure.

---

### 🔁 **Floyd’s Cycle Detection (Tortoise and Hare Algorithm)**

#### **Phase 1 – Detect the cycle**

* Use two pointers: `slow` (moves 1 step) and `fast` (moves 2 steps).
* They will eventually meet inside the cycle, confirming a loop exists.

#### **Phase 2 – Find the cycle's entry point**

* Reset one pointer to the start of the array.
* Move both pointers one step at a time.
* They will meet at the **duplicate number** (start of the cycle).

---

### 📘 **Why This Works**

* The repeated number causes a loop in the pointer chain.
* Meeting point inside the cycle isn’t necessarily the duplicate.
* The math behind the steps ensures both pointers meet at the **start of the cycle** (i.e., the duplicate) in the second phase.

---

### 🧠 **Important Insight**

* This is **not about finding a loop** in a normal linked list, but simulating one using the array’s values.
* The **duplicate number is the cycle's entry point**.
* Works purely due to the **Pigeonhole Principle** — more numbers than slots = at least one repeat.

---

### ✅ **Time and Space Complexity**

| Aspect            | Value |
| ----------------- | ----- |
| Time Complexity   | O(n)  |
| Space Complexity  | O(1)  |
| Modifies Array?   | ❌ No  |
| Extra Structures? | ❌ No  |

---

### 🧪 **Example Dry Run**

**Input**: `[1, 3, 4, 2, 2]`

* The "linked path" will form a cycle: `1 → 3 → 2 → 4 → 2 → 4...`
* Cycle start = `2` → that's the **duplicate number**

*/