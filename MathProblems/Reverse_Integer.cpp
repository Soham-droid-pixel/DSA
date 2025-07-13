#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cout<<"Enter integer"<<endl;
    cin>>x;
    int d,revnum=0;
    while(x!=0)
        {
            d=x%10;
            if (revnum > INT_MAX / 10 || (revnum == INT_MAX / 10 && d > 7)) {
                cout<<"Answer is 0"<<endl;
                return 0;
            }
            if (revnum < INT_MIN / 10 || (revnum == INT_MIN / 10 && d < -8)) {
                cout<<"Answer is 0"<<endl;
                return 0;
            }
            revnum=revnum*10+d;
            x=x/10;
            
            
        }
        
        cout<<"Answer is "<<revnum<<endl;
        return 0;



}
/*
---

## 💡 Goal of This Part:

You're trying to **reverse an integer** digit by digit — but you want to **avoid overflow** (i.e., crossing the 32-bit range):

* **32-bit signed integer range**:

  * `INT_MIN = -2147483648`
  * `INT_MAX =  2147483647`

So you want to **predict** whether reversing a number will go **outside this range**, and if it does, you return `0`.

---

## 🔍 The Core Idea

You're doing:

```cpp
revnum = revnum * 10 + d;
```

* But multiplying by 10 and adding a digit can make the number too big (overflow) or too small (underflow).

Since we can't store 64-bit numbers, we **must check in advance** if `revnum * 10 + d` will overflow or not.

---

## 🔒 Step-by-Step Explanation

### ➤ 1. Check for Positive Overflow:

```cpp
if (revnum > INT_MAX / 10)
```

**Example:**
If `revnum` is already `214748365` (just a bit more than `214748364`),
then multiplying it by 10 becomes `2147483650`, which is **too big** (overflow).
So we stop and return `0`.

---

### ➤ 2. Edge Case for Last Digit:

```cpp
if (revnum == INT_MAX / 10 && d > 7)
```

`INT_MAX / 10 = 214748364`
If `revnum == 214748364`, the only digit you can safely add is **7**
Because `214748364 * 10 + 7 = 2147483647` (which is `INT_MAX`)

If `d > 7`, like `8 or 9`, it would become more than `INT_MAX`. So again: **overflow** → return `0`.

---

### ➤ 3. Check for Negative Underflow:

```cpp
if (revnum < INT_MIN / 10)
```

If `revnum` is already less than `-214748364`, multiplying by 10 will make it **too negative** → **underflow** → return `0`.

---

### ➤ 4. Edge Case for Last Digit (Negative Side):

```cpp
if (revnum == INT_MIN / 10 && d < -8)
```

If you're right on the edge (`revnum = -214748364`), the **only safe digit** to add is `-8`, because:

```
-214748364 * 10 + (-8) = -2147483648  // this is INT_MIN
```

If `d < -8`, it becomes less than `INT_MIN` → underflow → return `0`.

---

## 🧠 Summary Table

| Condition                          | Meaning                  | Why it’s checked                |
| ---------------------------------- | ------------------------ | ------------------------------- |
| `revnum > INT_MAX / 10`            | Too close to upper limit | Might overflow on next multiply |
| `revnum == INT_MAX / 10 && d > 7`  | Edge of `INT_MAX`        | Can’t add >7                    |
| `revnum < INT_MIN / 10`            | Too close to lower limit | Might underflow                 |
| `revnum == INT_MIN / 10 && d < -8` | Edge of `INT_MIN`        | Can’t add < -8                  |

---

*/
/*
---

## ✅ Goal: Reverse a 32-bit signed integer safely

* Input: `x = 123` → Output: `321`
* Input: `x = -123` → Output: `-321`
* But if the reverse causes **overflow** (e.g., `1534236469` → `9646324351`), return `0`

---

## 📌 Mistakes You Made and How to Avoid Them

---

### ❌ Mistake 1: **Wrong overflow check after the loop**

#### What you did:

```cpp
revnum = revnum * 10 + d;
// ...
if (revnum < INT_MIN && revnum > INT_MAX)
```

#### Why it's wrong:

* The overflow may have **already happened** when you did `revnum * 10 + d`.
* And this condition is **never true**, because a number can’t be both `< INT_MIN` and `> INT_MAX`.

#### ✅ Fix:

* Do the **overflow check *before* doing the multiply and add**.
* Use safe bounds to check:

```cpp
if (revnum > INT_MAX / 10 || (revnum == INT_MAX / 10 && d > 7)) return 0;
if (revnum < INT_MIN / 10 || (revnum == INT_MIN / 10 && d < -8)) return 0;
```

---

### ❌ Mistake 2: **Not printing output before return**

#### What you did:

```cpp
if (...) {
    return 0;
    cout << "Answer is 0"; // ❌ Unreachable
}
```

#### Why it's wrong:

* Code after `return` **never runs**. So your message won’t print.

#### ✅ Fix:

Put `cout` **before** the `return`:

```cpp
cout << "Answer is 0" << endl;
return 0;
```

---

### ❌ Mistake 3: **Only checking for positive input initially**

#### What you initially did:

```cpp
while (x > 0)  // ❌ Only works for positive numbers
```

#### Why it's wrong:

* This skips the loop for negative values like `x = -123`.

#### ✅ Fix:

Use:

```cpp
while (x != 0)  // ✅ Works for both positive and negative
```

---

## ✅ Key Learnings / Tips for Next Time

| Mistake Type   | What to Remember                                                    |
| -------------- | ------------------------------------------------------------------- |
| Overflow       | Always check `revnum * 10 + d` *before* doing it                    |
| INT limits     | Use `INT_MAX`, `INT_MIN`, `INT_MAX / 10`, etc. to compare safely    |
| Control flow   | Code after `return` won’t run – put `cout` before it                |
| Loop condition | Use `x != 0` instead of `x > 0` to handle negative numbers too      |
| Code hygiene   | Avoid using `bits/stdc++.h` in production code (use proper headers) |

---

## 🛡️ Bonus Tip: Understand `INT_MAX` / `INT_MIN`

| Constant  | Value       |
| --------- | ----------- |
| `INT_MAX` | 2147483647  |
| `INT_MIN` | -2147483648 |

These come from the header `<climits>`.

---

*/