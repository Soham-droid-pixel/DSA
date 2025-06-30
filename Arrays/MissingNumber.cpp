#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int nums[n];
    int result=0;
    cout<<"Enter numbers in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    for(int i=0;i<n;i++)
    {
        result=result^i^nums[i];
    }
    result=result^n;
    cout<<result;
    
 return 0;
}
/*Absolutely! Here's a **complete and clear summary** of the XOR-based solution to the **"Missing Number"** problem — including the logic, iterations, and the bitwise explanation you asked about.

---

## ✅ Problem Summary:

You're given an array `nums` of size `n`, which contains **distinct numbers in the range \[0, n]**, but **one number is missing**. Your goal is to **find the missing number** efficiently.

---

## 🧠 XOR-Based Intuition:

We use the **bitwise XOR (^)** operator with this clever trick:

* XOR of a number with itself is `0`:
  → `a ^ a = 0`
* XOR of any number with 0 is the number itself:
  → `a ^ 0 = a`
* XOR is **commutative and associative**, so the order doesn't matter.

So if you XOR **all numbers from 0 to n** with **all elements in the array**, the matching numbers will cancel out — and you'll be left with just the **missing number**.

---

## 🔁 Example: `nums = [3, 0, 1]`

* Array size `n = 3`
* Expected range is `[0, 1, 2, 3]`
* The number **2 is missing**

---

## 🔍 Iteration Walkthrough:

We initialize:

```cpp
int result = 0;
```

Then we iterate:

```cpp
for (int i = 0; i < n; i++) {
    result = result ^ i ^ nums[i];
}
result = result ^ n;
```

---

### 🔢 Step-by-step with values:

| Iteration | i | nums\[i] | result computation     | result value |
| --------- | - | -------- | ---------------------- | ------------ |
| Init      | - | -        | result = 0             | 0            |
| i = 0     | 0 | 3        | result = 0 ^ 0 ^ 3     | 3            |
| i = 1     | 1 | 0        | result = 3 ^ 1 ^ 0 = 2 | 2            |
| i = 2     | 2 | 1        | result = 2 ^ 2 ^ 1 = 1 | 1            |
| Final     | - | -        | result = 1 ^ 3 = **2** | ✅ 2          |

---

### 🔍 Final Bitwise Step Explained: `1 ^ 3`

In binary:

```
1 = 0001
3 = 0011
----------
XOR = 0010 = 2
```

So `1 ^ 3 = 2`, which is your **missing number**.

---

## ✅ Final Output:

```
Missing number is: 2
```

---

## 🎯 Why This Works:

* XOR all `i` from `0` to `n` (full range)
* XOR all `nums[i]` in array
* All numbers **cancel out** due to XOR (because every number appears once in both)
* Only the **missing number doesn't get cancelled**
*/
