#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows in triangle: ";
    cin >> n;

    // Define triangle as a vector of vectors
    vector<vector<int>> triangle(n);
    cout << "Enter triangle values row-wise:\n";

    // Input the triangle
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1); // Each row has i+1 elements
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // Initialize dp with the last row
    vector<int> dp = triangle[n - 1];

    // Bottom-up DP
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
        }
    }

    cout << "Minimum path sum is: " << dp[0] << endl;
    return 0;
}
/*
---

### 🟩 Triangle:

```
       2          ← row 0
     3   4        ← row 1
   6   5   7      ← row 2
 4   1   8   3    ← row 3 (base case)
```

We’ll **build upward** to find the **minimum path sum from top to bottom**.

---

### 🪜 Step 1: Start with the Bottom Row as the Initial `dp`

We copy the last row into our DP array:

```cpp
dp = [4, 1, 8, 3]  // This represents the cost to reach the bottom from the bottom
```

---

### 🪜 Step 2: Process Row 2 (above the last row)

Row 2: `[6, 5, 7]`
We compute the new `dp` using:

```
dp[i] = triangle[row][i] + min(dp[i], dp[i+1])
```

Do it for each index:

* index 0:

  ```
  dp[0] = 6 + min(4, 1) = 6 + 1 = 7
  ```
* index 1:

  ```
  dp[1] = 5 + min(1, 8) = 5 + 1 = 6
  ```
* index 2:

  ```
  dp[2] = 7 + min(8, 3) = 7 + 3 = 10
  ```

Updated `dp`:

```cpp
dp = [7, 6, 10, 3]
```

---

### 🪜 Step 3: Process Row 1 (`[3, 4]`)

Now we repeat the same idea:

* index 0:

  ```
  dp[0] = 3 + min(7, 6) = 3 + 6 = 9
  ```
* index 1:

  ```
  dp[1] = 4 + min(6, 10) = 4 + 6 = 10
  ```

Updated `dp`:

```cpp
dp = [9, 10, 10, 3]
```

---

### 🪜 Step 4: Process Row 0 (`[2]`)

Only one element:

* index 0:

  ```
  dp[0] = 2 + min(9, 10) = 2 + 9 = 11
  ```

Final `dp`:

```cpp
dp = [11, 10, 10, 3]
```

---

### ✅ Final Answer:

```cpp
dp[0] = 11
```

That’s the **minimum path sum from top to bottom**.

---

### 📌 Path Taken:

Let’s trace the **actual path** that leads to sum 11:

```
2 → 3 → 5 → 1 = 11
```

* From 2, choose 3 (smaller of 3 & 4)
* From 3, choose 5 (smaller of 6 & 5)
* From 5, choose 1 (smaller of 4 & 1)

---

### 🔁 Summary of Steps:

| Step | Triangle Row Used | dp after processing |
| ---- | ----------------- | ------------------- |
| 1    | \[4, 1, 8, 3]     | \[4, 1, 8, 3]       |
| 2    | \[6, 5, 7]        | \[7, 6, 10, 3]      |
| 3    | \[3, 4]           | \[9, 10, 10, 3]     |
| 4    | \[2]              | \[11, 10, 10, 3]    |

---

*/
