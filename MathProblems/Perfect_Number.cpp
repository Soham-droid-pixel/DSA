#include <iostream>
#include <cmath>
using namespace std;

// ✅ Optimized Version – O(√n)
class SolutionOptimized {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;

        int sum = 1; // 1 is always a divisor

        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};

// 🔁 Original Version (O(n)) – Your Solution
class SolutionOriginal {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        
        int result = 1; // 1 is always a divisor
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                result += i;
            }
        }

        return result == num;
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    SolutionOriginal original;
    SolutionOptimized optimized;

    cout << "\nUsing Original (O(n)) Version: ";
    cout << (original.checkPerfectNumber(num) ? "Perfect Number ✅" : "Not a Perfect Number ❌") << endl;

    cout << "Using Optimized (O(√n)) Version: ";
    cout << (optimized.checkPerfectNumber(num) ? "Perfect Number ✅" : "Not a Perfect Number ❌") << endl;

    return 0;
}
/*My version 
for (int i = 2; i < num; i++) {
    if (num % i == 0) {
        result += i;
    }
}
Time Complexity: O(n) – Checks every number from 2 up to num - 1.

Space Complexity: O(1) – No extra space.

✅ Simple and easy to write.

❌ Inefficient for large inputs (e.g., 10^8) — may cause Time Limit Exceeded on platforms like LeetCode.

Optimized version
for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
        sum += i;
        if (i != num / i) {
            sum += num / i;
        }
    }
}
Time Complexity: O(√n) – Only checks up to the square root of the number.

Why is it faster?

If i is a divisor of num, then so is num / i.

So, you get two divisors at once, saving time.

✅ Efficient and scalable.

✅ Accepted for large values in competitive programming.


---

## ✅ Concept 1: Why Check Only up to √num?

### 📌 Suppose:

You want to find all divisors of a number `num = 28`.

Normally, you might loop from `2` to `27` to check all possible divisors (your original method).

But you **don’t need to go that far**. Here's why:

---

## ✅ Concept 2: "If `i` is a divisor of `num`, then `num / i` is also a divisor"

Let’s say `i = 2` is a divisor of `28`.

Then:

```cpp
28 ÷ 2 = 14
```

This means:

* `2` is a divisor
* `14` is also a divisor

📌 **You discovered two divisors in one step**: `i` and `num / i`

---

## 💡 Example: Divisors of 28

Loop only till `√28 ≈ 5.29` → So loop from `2` to `5`

| i | num % i | num / i | Add both?       |
| - | ------- | ------- | --------------- |
| 2 | 0       | 14      | ✅ Add 2 and 14  |
| 3 | 1       | -       | ❌ Not a divisor |
| 4 | 0       | 7       | ✅ Add 4 and 7   |
| 5 | 3       | -       | ❌ Not a divisor |

So we only checked 4 values (`2`, `3`, `4`, `5`) instead of 26!

We collected all these divisors: `1, 2, 14, 4, 7`
Sum: `1 + 2 + 14 + 4 + 7 = 28 ✅`

---

## ✅ Efficiency Explained

### In Your Code (O(n)):

```cpp
for(int i = 2; i < num; i++) { ... }
```

– You check every number up to `num - 1`. For `num = 10^8`, that’s **almost 100 million checks!** ❌

---

### In Optimized Code (O(√n)):

```cpp
for(int i = 2; i * i <= num; ++i) { ... }
```

– You only check up to `sqrt(num)` — for `num = 10^8`, that’s about **10,000 checks**! ✅

**Way faster**, especially for big numbers (used in interviews, contests, LeetCode, etc.)

---

## ✅ Summary in Simple Words:

* Every number has *paired* divisors — if you find one (`i`), the other is (`num / i`)
* This **cuts the loop in half or more**.
* We only need to check up to `√num` and we automatically get both divisors.
* For square numbers (like 16), we ensure not to count `i` and `num/i` twice (like 4 × 4).

---

*/