#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

// The optimal solution class you provided
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        unordered_map<long, long> buckets;
        
        // Bucket size must be at least 1 to avoid division by zero
        long bucketSize = (long)valueDiff + 1;

        for (int i = 0; i < nums.size(); ++i) {
            
            long num = nums[i];
            long bucketId = getBucketId(num, bucketSize);
            
            // Check if the current bucket already contains a close number
            if (buckets.count(bucketId)) {
                return true;
            }

            // Check the left adjacent bucket
            if (buckets.count(bucketId - 1) && abs(num - buckets[bucketId - 1]) <= valueDiff) {
                return true;
            }

            // Check the right adjacent bucket
            if (buckets.count(bucketId + 1) && abs(num - buckets[bucketId + 1]) <= valueDiff) {
                return true;
            }
            
            // Add the current element to its bucket
            buckets[bucketId] = num;
            
            // Maintain the sliding window of size indexDiff
            // Remove the oldest element's bucket if the window is full
            if (i >= indexDiff) {
                long oldNum = nums[i - indexDiff];
                long oldBucketId = getBucketId(oldNum, bucketSize);
                buckets.erase(oldBucketId);
            }
        }
        
        return false;
    }

private:
    // Helper function to get the bucket ID, handling negative numbers properly
    long getBucketId(long num, long bucketSize) {
        if (num >= 0) {
            return num / bucketSize;
        }
        // For negative numbers, we shift them before bucketing
        return (num + 1) / bucketSize - 1;
    }
};

// The main function to test the solution
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // --- Test Case 1 ---
    vector<int> nums1 = {1, 2, 3, 1};
    int indexDiff1 = 3;
    int valueDiff1 = 0;
    bool result1 = sol.containsNearbyAlmostDuplicate(nums1, indexDiff1, valueDiff1);
    cout << "Test Case 1: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0" << endl;
    cout << "Output: " << boolalpha << result1 << endl; // Expected: true
    cout << "-----------------------------------" << endl;

    // --- Test Case 2 ---
    vector<int> nums2 = {1, 5, 9, 1, 5, 9};
    int indexDiff2 = 2;
    int valueDiff2 = 3;
    bool result2 = sol.containsNearbyAlmostDuplicate(nums2, indexDiff2, valueDiff2);
    cout << "Test Case 2: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3" << endl;
    cout << "Output: " << boolalpha << result2 << endl; // Expected: false
    cout << "-----------------------------------" << endl;

    // --- Test Case 3 ---
    vector<int> nums3 = {8, 7, 15, 1, 6, 2};
    int indexDiff3 = 3;
    int valueDiff3 = 4;
    bool result3 = sol.containsNearbyAlmostDuplicate(nums3, indexDiff3, valueDiff3);
    cout << "Test Case 3: nums = [8,7,15,1,6,2], indexDiff = 3, valueDiff = 4" << endl;
    cout << "Output: " << boolalpha << result3 << endl; // Expected: true
    cout << "-----------------------------------" << endl;

    return 0;
}
/*
====================================================
   THEORY: Nearby Almost Duplicate Problem
====================================================

Problem Statement:
------------------
We are given:
  - An array of integers nums[]
  - An integer indexDiff
  - An integer valueDiff

We need to determine:
  → If there exist two distinct indices i and j such that:
       1. |i - j| <= indexDiff
       2. |nums[i] - nums[j]| <= valueDiff

In other words:
   - The two numbers must be close in index (within indexDiff steps).
   - The two numbers must be close in value (within valueDiff units).

----------------------------------------------------
 Bucketization Technique:
-------------------------
To solve this efficiently, we use a **bucket-hashmap method**:
  1. Define bucketSize = valueDiff + 1
     → Ensures that if two numbers fall in the same bucket,
       their difference is automatically <= valueDiff.
  
  2. Each number maps to a bucketId:
        bucketId(num) = num / bucketSize
        (handle negatives carefully by adjusting the formula)

  3. For each number:
       - Check if its bucket already contains a number → immediate match.
       - Check the left and right neighboring buckets 
         (bucketId - 1, bucketId + 1), since those may contain
         numbers within valueDiff.
       - If no match is found, insert the number into its bucket.

  4. Maintain a sliding window of size indexDiff:
       - If window exceeds indexDiff, remove the oldest element
         (nums[i - indexDiff]) from its bucket.

  5. If at any point a match is found, return true.
     If the loop finishes, return false.

----------------------------------------------------
 Why It Works:
--------------
- Buckets group numbers of "similar range".
- Checking only the same bucket and its neighbors ensures 
  O(1) lookups instead of O(n).
- Sliding window ensures indices difference condition.

====================================================
   EXAMPLE TRACE
====================================================

Input:
------
 nums = [4, 10, 15, 12]
 indexDiff = 2
 valueDiff = 3

Setup:
------
 bucketSize = valueDiff + 1 = 3 + 1 = 4
 Buckets are:
   0–3 → bucket 0
   4–7 → bucket 1
   8–11 → bucket 2
   12–15 → bucket 3

----------------------------------------------------
 Iteration Walkthrough:

 i = 0 → num = 4
   bucketId = 1
   No neighbors found
   Insert (1:4)
   Buckets = {1:4}

 i = 1 → num = 10
   bucketId = 2
   Neighbor bucket 1 has 4 → |10 - 4| = 6 > 3 → not valid
   Insert (2:10)
   Buckets = {1:4, 2:10}

 i = 2 → num = 15
   bucketId = 3
   Neighbor bucket 2 has 10 → |15 - 10| = 5 > 3 → not valid
   Insert (3:15)
   Sliding window: remove nums[0] = 4 (bucket 1)
   Buckets = {2:10, 3:15}

 i = 3 → num = 12
   bucketId = 3
   Bucket 3 already has 15 → |12 - 15| = 3 ≤ 3 → VALID
   Index check: |3 - 2| = 1 ≤ 2 → VALID
   → Return true

----------------------------------------------------
 Output:
--------
 Match found: (15, 12)
 Function returns true.

====================================================
*/
