#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int nums[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int lastNonZeroFoundAt=0;
    for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
    for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[lastNonZeroFoundAt]=nums[i];
                lastNonZeroFoundAt++;
            }
        }
    for(int i=lastNonZeroFoundAt;i<n;i++)
        {
            nums[i]=0;
        }
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<"\t";
    }
    return 0;
  
}
/*
## ✅ Problem Summary

You are given a `0-indexed` array `nums` of size `n` with **non-negative integers**.

### You need to perform:

1. For each `i` from `0` to `n-2`:

   * If `nums[i] == nums[i+1]`:

     * `nums[i] *= 2`
     * `nums[i+1] = 0`
2. After all operations, **shift all zeros to the end**, keeping non-zero elements' **relative order**.

---

## ✅ Algorithm (2-pass approach)

### 🔹 Step 1: Apply Operations

* Traverse from `i = 0` to `n - 2`
* If `nums[i] == nums[i + 1]`:

  * Double `nums[i]`
  * Set `nums[i+1] = 0`

### 🔹 Step 2: Shift Non-Zero Elements Forward

* Use a pointer `lastNonZeroFoundAt = 0`
* For each element in array:

  * If it's non-zero, move it to `nums[lastNonZeroFoundAt]` and increment the pointer

### 🔹 Step 3: Fill Remaining Positions with 0

* From `lastNonZeroFoundAt` to `n - 1`, set `nums[i] = 0`

---

## 🔄 Example Dry Run

**Input:** `nums = [1, 2, 2, 1, 1, 0]`

**Step 1 (Apply operations):**

* `2 == 2 → [1, 4, 0, 1, 1, 0]`
* `1 == 1 → [1, 4, 0, 2, 0, 0]`

**Step 2 (Shift non-zero):**

* Result: `[1, 4, 2, 0, 0, 0]`

✅ Final Output

---

## ⚠️ Common Mistakes to Avoid

### ❌ Mistake 1: Loop range in operation step

```cpp
for (int i = 0; i < n; i++)  // ❌
```

* ❗ This may cause `nums[i+1]` to go **out of bounds**.
* ✅ Use: `for (int i = 0; i < n - 1; i++)`

---

### ❌ Mistake 2: Shifting non-zero loop till `n - 1`

```cpp
for (int i = 0; i < n - 1; i++)  // ❌
```

* This **skips the last element**, which might be non-zero.
* ✅ Use: `for (int i = 0; i < n; i++)`

---

### ❌ Mistake 3: Mixing transformation + shifting logic

```cpp
// Doing both in the same loop
```

* ❗ May lead to incorrect behavior, since `nums[i]` is modified while iterating.
* ✅ Always perform **transformations first**, then shifting.

---

## 🧠 Key Takeaways

* Do **two separate passes**:

  1. One for transformation (`==` logic)
  2. One for shifting non-zeros and filling zeros
* Watch your **loop bounds**
* Use a **pointer** to track position for shifting
* Maintain the **order of non-zero elements**

---

## 🔁 Time & Space Complexity

* **Time:** O(n) — two passes over the array
* **Space:** O(1) — in-place

*/