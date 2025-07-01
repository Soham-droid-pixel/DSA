#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int lastNonZeroFoundAt=0;
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
### 📘 **Conceptual Notes**

#### 🔹 **Problem Goal**:

* Move all `0`s in an array to the **end**.
* Keep the **relative order of non-zero elements** the same.
* Modify the array **in-place** (no extra array allowed).

#### 🔹 **Core Idea**:

* Traverse the array.
* Shift all non-zero elements toward the beginning.
* After placing all non-zeros, fill the remaining positions with `0`.

---

### 🧠 **What You’re Really Doing**

* You’re **compressing** non-zero values to the left.
* Then you're **padding** the rest of the array with zeroes.

---

### ⛔ Common Mistakes to Avoid

1. **❌ Trying to Sort the Array**

   * This is **not** a sorting problem; sorting will ruin the relative order.

2. **❌ Using Nested Loops Unnecessarily**

   * Avoid unnecessary `O(n²)` time complexity.
   * A single pass (or two simple passes) is enough.

3. **❌ Using Extra Arrays**

   * The question **explicitly requires in-place modification**.
   * Creating a second array breaks that constraint.

4. **❌ Swapping Without a Plan**

   * Swapping can lead to loss of order if not handled carefully.
   * A simple overwrite method with a position tracker is cleaner.

5. **❌ Forgetting to Fill Remaining Elements with Zeros**

   * After moving non-zero elements, remember to replace the rest with `0`.

6. **❌ Ignoring Edge Cases**

   * Arrays like `[0, 0, 0]`, `[1, 2, 3]`, `[0]`, `[]` (empty array) should be handled.

---

### 🧪 Dry Run Strategy

Before finalizing your solution, test it with:

* **All zeros** → `[0, 0, 0]`
* **No zeros** → `[1, 2, 3]`
* **Zeros in between** → `[0, 1, 0, 2]`
* **Single element** → `[0]`, `[5]`
* **Empty array** → `[]`

---

### 📝 Key Takeaways

* Use a **position pointer** to track where to place non-zero elements.
* Remember: **order matters**.
* Think in **two phases**:

  1. Move non-zeros forward.
  2. Fill remaining with zeros.
* Keep **time complexity O(n)** and **space O(1)**.

*/