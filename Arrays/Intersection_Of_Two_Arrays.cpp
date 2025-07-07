#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n1,n2,k;
    cout<<"Enter size of array1"<<endl;
    cin>>n1;
    int nums1[n1];
    for(int i=0;i<n1;i++)
    {
      cin>>nums1[i];
    }
    cout<<"Enter size of array2"<<endl;
    cin>>n2;
    int nums2[n2];
    for(int i=0;i<n2;i++)
    {
       cin>>nums2[i];
        
    }
    vector<int> result;
     for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
            
               if(nums1[i]==nums2[j])
               {
                bool found=false;
                for(int k=0;k<result.size();k++)
                {
                 if(result[k]==nums1[i])
                 {
                    found=true;
                    break;
                 }
                 
                

                }
                if(!found)
                {
                    result.push_back(nums1[i]);
                }
                break;
            }
        }
    }
    for(int i=0;i<result.size();i++){
    cout<<result[i]<<"\t";
    }
    return 0;
}
/*

---

### 🔁 Problem Statement Recap:

> Given two integer arrays, find their **intersection** such that:

* Only common elements are included.
* Each element appears **only once** in the result.
* The result can be in any order.

---

### 📌 Approach (Brute Force with Duplicate Check):

1. **Input**: Take two arrays, say `nums1` and `nums2`.
2. **Loop through `nums1`** using index `i`.
3. For each `nums1[i]`, loop through `nums2` using index `j`.
4. **Compare values**: If `nums1[i] == nums2[j]`, then it's a **common element**.
5. **Before adding to result**, check if the value is **already present** in the result array:

   * Loop through `result` and compare.
   * If not present, then **add it** to the result.
6. **Break** inner loop after match to avoid adding duplicates from second array.
7. Finally, **print the result array**.

---

### 🧠 Key Concepts Used:

* **Nested loops**: Used to compare elements of both arrays.
* **Duplicate check**: A separate loop checks if the common element is already in the result.
* **`vector` (dynamic array)**: Used to store the final result.

---

### ⚠️ Common Mistakes to Avoid:

* Not checking for duplicates before adding to result.
* Incorrect placement of the `break` or `if(!found)` inside loops.
* Using an uninitialized variable for loop limits (e.g. uninitialized `k`).

---

### ⏱️ Time Complexity:

* Outer loop: O(n1)
* Inner loop: O(n2)
* Duplicate check loop: O(k) where `k` is result size so far
* Total: **O(n1 × n2 × k)** → inefficient for large arrays.

---

### ✅ When This Approach is OK:

* Small input sizes (as per constraints like ≤ 1000).
* Simplicity is more important than performance.

---

*/