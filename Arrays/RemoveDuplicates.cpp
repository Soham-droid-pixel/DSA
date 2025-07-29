#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[j])
        {
            j++;
            arr[j]=arr[i];
        }
        
        
            
        
    }
    for(int i=0;i<=j;i++)
    {
        cout<<arr[i];
    }
    return 0;
}
/*Sure! Let’s go through this step by step.

Your code is the **standard two-pointer solution** for the "Remove Duplicates from Sorted Array" problem.

---

### **Code Understanding**

We have:

* **`i`** → pointer that scans through the array (fast pointer)
* **`j`** → pointer that tracks position of the last unique element (slow pointer)

---

### **Logic Breakdown**

1. **Base case:**

```cpp
if (nums.size() == 0) return 0;
```

If the array is empty, there are no unique elements, so return `0`.

---

2. **Initialization:**

```cpp
int j = 0; // Points to the last unique element
```

* `j` starts at `0` because the first element is always unique.

---

3. **Loop through the array:**

```cpp
for (int i = 1; i < nums.size(); i++)
```

* `i` starts from `1` because we already considered `nums[0]` as unique.
* We compare each new element (`nums[i]`) with the last unique element (`nums[j]`).

---

4. **Check if element is unique:**

```cpp
if (nums[i] != nums[j]) {
    j++;
    nums[j] = nums[i];
}
```

* If `nums[i]` is **different** from `nums[j]` (meaning it’s a new unique value):

  * Move `j` one step forward (`j++`)
  * Copy the unique value at position `i` into position `j`
  * This **overwrites duplicates** in-place

---

5. **Return length of unique array:**

```cpp
return j + 1;
```

* Since `j` is an index (0-based), the number of unique elements is `j + 1`.

---

### **Example Walkthrough**

Input:

```
nums = [1, 1, 2, 2, 3]
```

Step-by-step:

| i | j   | nums array after operation                                                     |
| - | --- | ------------------------------------------------------------------------------ |
| 1 | 0   | Compare nums\[1]=1 with nums\[0]=1 → same, skip                                |
| 2 | 0→1 | Compare nums\[2]=2 with nums\[0]=1 → different → nums\[1]=2 → \[1, 2, 2, 2, 3] |
| 3 | 1   | Compare nums\[3]=2 with nums\[1]=2 → same, skip                                |
| 4 | 1→2 | Compare nums\[4]=3 with nums\[1]=2 → different → nums\[2]=3 → \[1, 2, 3, 2, 3] |

Return `j+1 = 3`.
Unique elements: `[1, 2, 3]`.

---

### **Key Points**

* **Why not erase?** Because erasing in `vector` shifts all elements (O(n²) total).
* **Why sorted array?** Because duplicates are always next to each other, making comparison easy.
* **Why overwrite instead of remove?** It’s O(n) and keeps memory usage minimal.

---

*/