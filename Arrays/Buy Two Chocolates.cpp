#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    int money;
    cout<<"Enter money"<<endl;
    cin>>money;
    int minCost=INT_MAX;
    int totalCost=0;
    for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                totalCost=prices[i]+prices[j];
                if(totalCost<=money&& totalCost<minCost)
                {
                  minCost=totalCost;
                }
        
            }
        }
    if(minCost==INT_MAX)
    {
        cout<<"Answer is "<<money<<endl;
    }
    else{
    cout<<"Answer is "<< money-minCost<<endl;
    }
            
        
        
    
    return 0;
}
/*
## 📝 **Buy Two Chocolates Problem – Revision Notes**

### 📘 **Problem Statement**

Given:

* An array `prices[]` representing the prices of chocolates.
* An integer `money` representing available money.

Goal:

* Buy **exactly two** chocolates such that their total price is **≤ money**.
* Return the **leftover money** after the purchase.
* If **no valid pair** exists, return the original `money`.

---

### 🔍 **What to Remember**

1. **Try all pairs** of chocolates using nested loops.
2. **Track the minimum valid total cost** (`minCost`) of any two-chocolate combination that’s ≤ `money`.
3. If no valid pair exists, `minCost` should remain `INT_MAX`.
4. Final return:

   * If `minCost == INT_MAX` → return `money`
   * Else → return `money - minCost`

---

### ⚠️ **Mistakes I Made Earlier**

* ❌ Initialized leftover/diff to 0 → gave wrong result when no valid pair found.
* ❌ Overwrote leftover value even when a better (smaller) pair already existed.
* ❌ Incorrect loop range (`j < n-1`) → skipped last element.
* ❌ Incorrect condition logic (`||` and `&&` without proper parentheses).
* ❌ No way to check if a valid pair was found → returned wrong leftover even when purchase was impossible.

---

### 🔁 **Example Walkthrough (Dry Run)**

Input:

* `prices = [1, 2, 2]`
* `money = 3`

Iterations:

* Pair (1,2): total = 3 → valid → minCost = 3
* Pair (1,2 again): total = 3 → same → minCost remains 3
* Pair (2,2): total = 4 → invalid → skip

Since a valid pair exists with total = 3:

* Leftover = `3 - 3 = 0`

✅ Answer: 0

---

### ✅ **Core Learning Points**

* Always track if **any valid combination** is found (use `INT_MAX` trick).
* Never blindly overwrite values—always check if the new pair is **better** (i.e., lower cost).
* Proper loop indexing: `j = i+1` and `j < n`
* Avoid misleading initialization (e.g., `diff = 0`)
* Carefully group logical conditions using parentheses when combining `&&` and `||`.

---

### 💡 **Optimization Tip (If Needed)**

* Find the **two smallest elements** in the array.
* If their sum is ≤ money, return leftover.
* Else, return money.
* This reduces complexity from **O(n²)** to **O(n)**.
*/