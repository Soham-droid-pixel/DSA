#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin >> n;
    int nums[n];

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = 0;

    for(int i = 0; i < 32; i++)
    {
        int bitCount = 0;

        for(int num : nums)
        {
            if((num >> i) & 1)
            {
                bitCount++;
            }
        }

        if(bitCount % 3 != 0)
        {
            result |= (1 << i);
        }
    }

    // Handle negative numbers
    if ((result >> 31) & 1)
    {
        result -= (1LL << 32);
    }

    cout << "Single number is: " << result << endl;
    return 0;
}
/*
## 🧪 Example:

```
Input: [2, 2, 3, 2]
Goal: Find the number that appears **once** (Answer: 3)
```

All numbers appear **3 times**, except `3`.

---

### 🧠 Binary of each number

| Number | Binary (32-bit simplified) |
| ------ | -------------------------- |
| 2      | 0000 0010                  |
| 2      | 0000 0010                  |
| 3      | 0000 0011                  |
| 2      | 0000 0010                  |

---

### ✅ Step-by-step logic

Loop over **bit positions from 0 to 31** (32 total):

We'll track how many times each **bit is set** (i.e., is 1) across all numbers.

#### Bit Position 0 (LSB):

Check if bit 0 is `1` in each number:

* 2 → `0010` → bit 0 is `0`
* 2 → `0010` → bit 0 is `0`
* 3 → `0011` → bit 0 is `1` ✅
* 2 → `0010` → bit 0 is `0`

👉 Count of bit 0 set = **1**

* Not divisible by 3 → so **bit 0 is part of unique number**

Set bit 0 in `result`:

```
result = result | (1 << 0) = 000...0001
```

---

#### Bit Position 1:

* 2 → `0010` → bit 1 is `1` ✅
* 2 → `0010` → bit 1 is `1` ✅
* 3 → `0011` → bit 1 is `1` ✅
* 2 → `0010` → bit 1 is `1` ✅

👉 Count = 4

* 4 % 3 = 1 → **not divisible by 3**
* So **bit 1 is also part of the unique number**

Set bit 1:

```
result = 000...0001 | (1 << 1) = 000...0011 → decimal 3
```

---

#### Bit Positions 2 to 31:

All remaining bits are `0` for every number
→ bitCount = 0
→ divisible by 3 ✅
→ Don't set anything in result

---

### ✅ Final Answer:

```
result = 000...0011 → 3
```

**Correct!**

---

## 📚 General Cases

| Case                                                    | How it Works                                           |
| ------------------------------------------------------- | ------------------------------------------------------ |
| All numbers appear 3 times, 1 appears once              | Bit counts divisible by 3 will cancel out              |
| Unique number has 1 in a bit → count not divisible by 3 | That bit is kept in result                             |
| Works for **negative numbers** too                      | C++ uses 2’s complement; works same across all 32 bits |

---

## 💡 Example 2: `[0,1,0,1,0,1,99]`

**Binary of 99**: `000...01100011`

* All bits of 0 and 1 cancel in count (they appear 3 times)
* Bits set in 99 will remain (not divisible by 3)
* So only `99` gets constructed from those leftover bits

✅ Answer: `99`

---

## 🎯 Why this works:

> Because any bit that appears **3 times** will sum to a **multiple of 3**.
> Only the bits of the unique number will have a **remainder ≠ 0** when `mod 3`.

---

*/
/*
---

## ✅ Problem Summary

**Q:**
Given an array where every element appears **three times** except for one that appears **only once**, find that **unique element**.

**Constraints:**

* Must run in **linear time** `O(n)`
* Use **constant space** `O(1)`

---

## ✅ Final Approach: **Bit Manipulation + Modulo 3**

### 💡 Core Idea:

Every bit of numbers appearing 3 times will contribute **a multiple of 3** to the bit count.

But the **unique number's bits** will contribute just **once**, so when we do:

```cpp
bitCount % 3
```

Only bits of the **unique number** remain.

---

## 🔁 Step-by-step Algorithm

### 🔹 Step 1: Loop over 32 bits (0 to 31)

Each integer has 32 bits in C++ (`int = 4 bytes = 32 bits`).

### 🔹 Step 2: Count how many numbers have the i-th bit set

Use:

```cpp
if ((num >> i) & 1)
```

to check if bit `i` is `1`.

### 🔹 Step 3: If count % 3 ≠ 0 → That bit is set in the unique number

Set that bit in `result` using:

```cpp
result |= (1 << i);
```

### 🔹 Step 4: Handle Negative Numbers (Important)

If the **31st bit (sign bit)** is set → it’s a **negative number** in 2’s complement form.
Fix it using:

```cpp
if ((result >> 31) & 1)
    result -= (1LL << 32);
```

---

## 🧠 Key Concepts Used

| Concept                  | Explanation                               |                        |
| ------------------------ | ----------------------------------------- | ---------------------- |
| **Bitwise Shift (`>>`)** | Moves bits right to isolate bit `i`       |                        |
| **AND (`& 1`)**          | Checks if bit is set (1)                  |                        |
| \*\*OR (\`               | =\`)\*\*                                  | Sets the bit in result |
| **Modulo 3 Trick**       | Cancels out bits that appear 3 times      |                        |
| **2's Complement**       | Used to handle negative numbers in binary |                        |

---

## 🔍 Why XOR Does Not Work Here?

In case of **every number appearing twice**, XOR works:

```
a ^ a = 0
0 ^ x = x
```

But for **three times**, XOR fails:

```
a ^ a ^ a ≠ 0
```

---

## ❗ Mistakes to Avoid

| Mistake                                                   | Fix                                        |
| --------------------------------------------------------- | ------------------------------------------ |
| Using XOR like in "single number" (appears twice) problem | ❌ Doesn't work when numbers appear 3 times |
| Not handling negative numbers                             | Use 2's complement fix for 32-bit          |
| Using extra space like map or set                         | Violates O(1) space constraint             |

---

## ✅ Time and Space Complexity

* **Time:** O(32 × n) = O(n) (because 32 is constant)
* **Space:** O(1) constant

---

## 🧪 Sample Inputs

| Input                    | Output | Explanation                |
| ------------------------ | ------ | -------------------------- |
| `[2, 2, 3, 2]`           | `3`    | Only 3 appears once        |
| `[0, 1, 0, 1, 0, 1, 99]` | `99`   | All others appear 3 times  |
| `[-2, -2, -2, -5]`       | `-5`   | Works with negative number |

---

## ✅ Final Thought

This is one of those problems that:

* Tests your **bitwise thinking**
* Trains you to think **beyond brute force**
* Gives you confidence once you get it

Now you’ve learned not just how to solve it — but **why it works** and **how to debug it**. You’ve truly leveled up. 🔥

---

*/