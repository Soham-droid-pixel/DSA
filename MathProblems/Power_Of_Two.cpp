#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if(n<=0) return false;
    while(n%2==0)
    {
        n=n/2;
    }
    return n==1;
}
int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    if(isPowerOfTwo(n))
    {
        cout<<"Number"<<n<<"is power of two"<<endl;
    }
    else{
        cout<<"Number"<<n<<" not a power of two"<<endl;
    }
    return 0;
}
/*
---

## ✅ **Goal**:

To check if a number is a **power of 2** without using **bitwise operators**.

---

## 🧠 **Concept**:

A number is a power of 2 if it can be **divided by 2 repeatedly** until you get **1**.
Examples of powers of 2:

* $2^0 = 1$
* $2^1 = 2$
* $2^2 = 4$
* $2^3 = 8$
* $2^4 = 16$
* ... etc.

These numbers when divided by 2 repeatedly will always become 1.

---

## 📘 **Logic Breakdown**:

1. **Negative numbers and zero** are **not** powers of 2. So first, check if `n <= 0`.
   If so, return `false`.

2. **Use a loop**:
   As long as the number is divisible by 2 (i.e., `n % 2 == 0`), keep dividing it by 2.

3. When the loop ends, we check:

   * If the final number is **1**, then the original number was a power of 2.
   * If the final number is **not 1** (e.g., 3, 5, 9), then it was **not** a power of 2.

---

## ✅ **Example 1**:

Input: `n = 16`
Steps:

* 16 → 8 → 4 → 2 → 1 ✅
* Output: Power of 2 ✅

---

## ❌ **Example 2**:

Input: `n = 18`
Steps:

* 18 → divisible by 2 → 9
* 9 is not divisible by 2 → exit loop
* 9 ≠ 1 ❌
* Output: Not a power of 2

---

## 🔍 **Why it works efficiently**:

* Each division by 2 halves the number.
* For large numbers, it takes **log₂(n)** steps — very fast.
* It avoids bitwise operators and is simple for interviews or exams.

---

*/
/*

---

## 📝 **Notes: Check Power of 2 Using Bitwise in C++**

### ✅ Concept:

A number is a power of 2 **only if** it has exactly **one bit set** in its binary representation.

### 🧠 Key property:

For any power of 2:

$$
n > 0 \quad \text{and} \quad (n \ \&\ (n - 1)) == 0
$$

### 🔍 Why this works:

* Powers of 2 in binary look like:

  * `1` = `0001`
  * `2` = `0010`
  * `4` = `0100`
  * `8` = `1000`
* Subtracting 1 from them flips the **lowest set bit** and turns all lower bits to 1.
* ANDing `n` with `n - 1` gives `0` **only if** there was one set bit (i.e., a power of 2).

### 🛑 Edge case:

Make sure `n > 0` — zero or negative numbers are **not** powers of 2.

---

## ✅ **C++ Code (Bitwise method)**

```cpp
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n))
        cout << n << " is a power of 2" << endl;
    else
        cout << n << " is NOT a power of 2" << endl;

    return 0;
}
```

---

## 🔁 Example Runs:

### Input: `8`

* `n = 8` → `1000`
* `n - 1 = 7` → `0111`
* `1000 & 0111 = 0000` ✅ → Power of 2

### Input: `6`

* `n = 6` → `0110`
* `n - 1 = 5` → `0101`
* `0110 & 0101 = 0100 ≠ 0` ❌ → Not a power of 2

---

*/