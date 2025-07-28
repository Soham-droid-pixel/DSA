#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    int arr[n];
    int targetarr[2];
    bool flag=false;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=n-1;i++){
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]+arr[j]==target)
        {
            targetarr[0]=i;
            targetarr[1]=j;
            flag=true;
            break;
        }
        
    
    
    
    }    
        if(flag)
        {
            break;
        }
        

    }
        if(flag){
        cout<<"Indices:"<<targetarr[0]<<" "<<targetarr[1];
        }
        else{
            cout<<"No soln found";
        }

    return 0;
}
/*Use hashmap for optimized code:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // stores value -> index
        
        // Loop through each element
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // number we need
            
            // If complement is already in map, we found the pair
            if (mp.count(complement)) { 
                return {mp[complement], i};
            }
            
            // Store current number with its index
            mp[nums[i]] = i;
        }
        
        return {}; // (This line won't be reached as per problem statement)
    }
};
Perfect 👍 — let’s walk through your **hash map Two Sum solution** with an example step-by-step so you can see exactly how the map changes.

---

## **Example**

Input:

```
nums = [2, 7, 11, 15]
target = 9
```

---

## **Dry Run Table**

| Step       | i | nums\[i] | complement = target - nums\[i] | Map (value → index) | Action                        |
| ---------- | - | -------- | ------------------------------ | ------------------- | ----------------------------- |
| 1          | 0 | 2        | 7                              | {}                  | 7 not in map → store 2:0      |
| 2          | 1 | 7        | 2                              | {2:0}               | 2 found in map → return {0,1} |
| **Return** |   |          |                                |                     | **Answer: \[0,1]**            |

---

## **📝 Step-by-step Explanation**

1. **Start:** map is empty
2. **i = 0**

   * nums\[i] = 2
   * complement = 9 - 2 = 7
   * Map doesn’t have 7 → store 2 with index 0
   * Map becomes `{2: 0}`
3. **i = 1**

   * nums\[i] = 7
   * complement = 9 - 7 = 2
   * Map contains 2 → we found a pair!
   * Return indices `{map[2], i}` = `{0, 1}`

---

✅ Output: **\[0, 1]** (Indices of numbers 2 and 7 that sum to 9)

---

👉 This dry run is short for 2 elements.
*/