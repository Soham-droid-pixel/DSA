#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (char c : s) ans ^= c; // XOR all chars in s
        for (char c : t) ans ^= c; // XOR all chars in t
        return ans; // leftover is the extra char
    }
};

int main() {
    Solution sol;
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    char extraChar = sol.findTheDifference(s, t);
    cout << "The extra character is: " << extraChar << endl;

    return 0;
}
/*
---

## Problem Reminder

We have:

* `s` → original string
* `t` → same as `s` but **shuffled** and **one extra character added**.
  We need to find that extra character.

Example:

```
s = "abcd"
t = "abcde"
```

---

## Code

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (char c : s) ans ^= c; // Step 1
        for (char c : t) ans ^= c; // Step 2
        return ans; // Step 3
    }
};
```

---

## Step-by-Step Explanation

### 1️⃣ What is XOR (`^`)?

* In C++, `^` is the **bitwise XOR** operator.
* XOR between two same numbers is **0**.
* XOR between any number and 0 is the number itself.
* Example:

  ```
  'a' ^ 'a' = 0
  'a' ^ 0 = 'a'
  ```

---

### 2️⃣ Idea of the solution

If we XOR all characters in `s` and `t` together:

* Characters that appear **twice** (once in `s`, once in `t`) will cancel out → become `0`.
* The extra character appears **only in `t`**, so it won’t be cancelled.
* The final result after all XORs = **extra character**.

---

### 3️⃣ Walkthrough with example

```
s = "abcd"
t = "abcde"
```

**Step 1: XOR all in `s`**

```
ans = 0
ans ^= 'a' → ans = 'a'
ans ^= 'b' → ans = 'a' ^ 'b'
ans ^= 'c' → ans = ('a' ^ 'b') ^ 'c'
ans ^= 'd' → ans = ((( 'a' ^ 'b') ^ 'c') ^ 'd')
```

**Step 2: XOR all in `t`**

```
Continue ans ^= 'a' → cancels out with first 'a'
Continue ans ^= 'b' → cancels out
Continue ans ^= 'c' → cancels out
Continue ans ^= 'd' → cancels out
Continue ans ^= 'e' → this stays because no matching 'e' in s
```

**Final ans = 'e'**

---

### 4️⃣ Complexity

* **Time complexity**: O(n) → just one loop over each string.
* **Space complexity**: O(1) → uses only one variable.

---

*/