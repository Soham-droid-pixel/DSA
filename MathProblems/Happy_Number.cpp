#include <iostream>
#include <unordered_set>
using namespace std;

int getSumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = getSumOfSquares(n);
    }

    return n == 1;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isHappy(number)) {
        cout << number << " is a Happy Number!" << endl;
    } else {
        cout << number << " is NOT a Happy Number." << endl;
    }

    return 0;
}

/*
---

## 📘 **Happy Number – First Code Mistake Review Notes**

---

### ❌ **1. You Only Performed One Iteration**

#### ➤ What You Did:

You calculated the sum of squares of digits only **once** and then checked if the result is `1`.

#### ❗ Why It’s a Problem:

A happy number might take **multiple rounds** of squaring digits to reach `1`.
For example:

* `19 → 82 → 68 → 100 → 1`

So, just one round isn’t enough.

#### ✅ How to Avoid:

You must repeat the sum-of-squares process **until either**:

* You reach 1 ✅
* Or, numbers start repeating (cycle) ❌

---

### ❌ **2. Incorrect Loop Condition: `while(n/10 != 0)`**

#### ➤ What You Did:

You used a condition that stops when the number becomes **single-digit**.

#### ❗ Why It’s a Problem:

Being single-digit doesn't mean the number is **done or happy**.
For example, `7` becomes `49`, then `97`, etc. — many steps even **after being single-digit**.

#### ✅ How to Avoid:

Don't check whether the number is single-digit. Instead, keep looping **until**:

* The number becomes **1**
* Or you're stuck in a loop of numbers

---

### ❌ **3. Final Check: `if (n == 1)` After the Loop**

#### ➤ What You Did:

You checked whether `n == 1` **after** extracting all digits (so `n` is 0 now).

#### ❗ Why It’s a Problem:

Since you've **divided `n` by 10** until it's 0, `n` can't be 1 anymore at this point. You're checking the wrong variable.

#### ✅ How to Avoid:

Make sure you're checking **the result of the sum-of-squares process**, not the leftover digit-processing variable.

---

### ❌ **4. No Cycle Detection**

#### ➤ What You Did:

You didn’t include any way to check if a number **repeats** during the process.

#### ❗ Why It’s a Problem:

Some numbers fall into a **loop** and never reach 1 (like `4 → 16 → 37 → ... → 4`).
Without cycle detection, your code could run **forever** or return a wrong result.

#### ✅ How to Avoid:

Keep track of the numbers you've already processed (e.g., in a list or set).
If a number repeats → you're in a cycle → not a happy number.

---

### 🧠 **Summary of How to Think About Happy Numbers**

| Step | What to Do                                                     |
| ---- | -------------------------------------------------------------- |
| 1️⃣  | Break the number into digits                                   |
| 2️⃣  | Square each digit and sum them                                 |
| 3️⃣  | Repeat with the new number                                     |
| 4️⃣  | Stop only if you reach 1 (happy) or detect a cycle (not happy) |

---

## 🎯 Tips to Avoid These Mistakes in the Future

* **Ask: Does this problem require repetition?** → Use loops properly.
* **Think about edge cases** like single digits, 0, or known cycles.
* **Don’t rely on format like "n becomes single-digit"** — focus on the problem’s actual logic.
* **Always test your code with known examples** (e.g., 19 is happy, 4 is not).
* **Trace on paper first** for 1–2 examples before writing code.

---

*/