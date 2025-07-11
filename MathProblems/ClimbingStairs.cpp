#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter total number of steps to check how many distinct ways u can climb by 1 step or 2 steps"<<endl;
    cin>>n;
    if(n<=2){
            cout<<"No of ways: "<<n;
            return 0;
        }
        int first=1;
        int second=2;
        for(int i=3;i<=n;i++)
        {
          int third=first+second;
          first=second;
          second=third;
        }
        cout<<"No of ways required : "<<second;
        return 0;
    

}
/*
---

## 📘 Climbing Stairs – Revision Notes

### 🧗‍♂️ Problem Statement:

You are climbing a staircase with `n` steps.
You can take either **1 step** or **2 steps** at a time.
**Goal:** Find how many **distinct ways** you can climb to the top.

---

### 🎯 Key Idea:

* At step `n`, you could’ve reached from:

  * Step `n-1` (taking 1 step)
  * Step `n-2` (taking 2 steps)
* So the number of ways to reach `n` is:

  ```
  ways(n) = ways(n - 1) + ways(n - 2)
  ```
* This is exactly like the **Fibonacci sequence**.

---

### 🧮 Base Cases:

* `ways(1) = 1`
* `ways(2) = 2`
* Build up from there.

---

### ✅ Best Approach:

* Use **Dynamic Programming** with **2 variables only** (optimized space).
* This gives:

  * **Time complexity**: O(n)
  * **Space complexity**: O(1)

---

### 🧠 Combinatorics Approach (when not to use):

**Idea:**
You can model each combination of 1s and 2s using combinations math:

* E.g., for 2 two-steps and 1 one-step → total 3 moves
  Ways to arrange = C(3, 2)

**BUT avoid this approach because:**

1. **You need factorials**, which can be heavy and lead to **integer overflow** for `n > 20`
2. Doesn't scale well for large `n`
3. More complex to implement safely compared to Fibonacci logic

✅ Okay for small `n`, but **not recommended** in interviews or competitive settings.

---

### 🚫 Common Mistakes to Avoid:

| Mistake                                                | Why it's wrong                                                                    |
| ------------------------------------------------------ | --------------------------------------------------------------------------------- |
| Returning `n` directly when `n <= 2` inside `main()`   | You skip printing anything — logic is correct, but no output shown                |
| Using recursion without memoization                    | Leads to **exponential time** and **TLE (Time Limit Exceeded)**                   |
| Using array DP but forgetting to initialize base cases | Will result in garbage/zero values                                                |
| Confusing number of steps with number of ways          | Understand: you're not counting steps, you're counting **paths** to reach the top |
| Printing combinations instead of sequences             | In this problem, **order matters** (1+2 is different from 2+1)                    |

---

### ✅ What to Remember:

* **Use bottom-up DP with two variables** (Fibonacci-like)
* Always **initialize base cases correctly**
* Understand that this is a **dynamic path-counting** problem, not a sum-combination problem
* **Order matters**: 1+2 ≠ 2+1
* Combinatorics can work but has **limitations** and can introduce **unnecessary complexity**

---

### 🌟 Interview Tip:

If asked this in an interview:

* Start with recursive relation
* Optimize it using dynamic programming
* Discuss space optimization (2 variables)
* **Do not jump directly to math formulas** unless asked

*/