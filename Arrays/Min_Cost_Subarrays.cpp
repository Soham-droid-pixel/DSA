#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // ==================================================================================
    // PROBLEM: Divide Array Into Subarrays With Minimum Cost II
    // ==================================================================================
    // Logic:
    // 1. The first element nums[0] is ALWAYS part of the cost. We can add it at the end.
    // 2. We need to select (k-1) additional elements from the rest of the array (nums[1...]).
    // 3. CONSTRAINT: The difference between the index of the first selected element 
    //    and the last selected element must be <= dist.
    // 4. TRANSLATION: This effectively means we need to find the Minimum Sum of (k-1) 
    //    elements inside a SLIDING WINDOW of size (dist + 1).
    //
    // Algorithm (Two Sets / Heaps Pattern):
    // - We maintain two multisets: 
    //   a) 'L' (Low): Holds the smallest (k-1) numbers in the current window.
    //   b) 'R' (Rest): Holds the remaining numbers in the current window.
    // - As we slide the window:
    //   1. Insert new number.
    //   2. Remove old number (if it falls out of the window).
    //   3. Re-balance L and R so L always has exactly (k-1) items.
    //   4. Track the sum of L.
    
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long currentSum = 0; // Sum of elements in set L
        long long minSum = LLONG_MAX;
        
        int n = nums.size();
        
        // Use multisets because numbers can be duplicated
        multiset<int> L; // Stores the smallest (k-1) elements
        multiset<int> R; // Stores the larger elements
        
        // We need to pick k-1 elements from the window (since 1st element is nums[0])
        int needed = k - 1; 

        // Iterate starting from index 1 (since index 0 is fixed)
        for (int i = 1; i < n; ++i) {
            
            // --- STEP 1: INSERT NEW ELEMENT ---
            // Initially, assume we put it in L.
            L.insert(nums[i]);
            currentSum += nums[i];
            
            // Balance: If L has too many elements, move the largest to R
            if (L.size() > needed) {
                // Get largest element in L (last element)
                auto it = prev(L.end());
                int val = *it;
                
                L.erase(it);      // Remove from L
                currentSum -= val; // Update sum
                R.insert(val);    // Move to R
            } 
            // Optimization: If the new element we added to L is actually bigger than 
            // the smallest in R, we should swap them to keep L containing strictly smallest.
            else if (!L.empty() && !R.empty() && *L.rbegin() > *R.begin()) {
                int valL = *L.rbegin();
                int valR = *R.begin();
                
                // Swap L's max with R's min
                L.erase(prev(L.end()));
                currentSum -= valL;
                R.erase(R.begin());
                
                L.insert(valR);
                currentSum += valR;
                R.insert(valL);
            }

            // --- STEP 2: REMOVE OLD ELEMENT ---
            // The window size is effectively (dist + 1).
            // If i is far enough, the element at (i - dist - 1) falls out.
            if (i > dist + 1) {
                int valToRemove = nums[i - (dist + 1)];
                
                // Try to find and remove from L first
                auto itL = L.find(valToRemove);
                if (itL != L.end()) {
                    L.erase(itL);
                    currentSum -= valToRemove;
                } else {
                    // Otherwise, it must be in R
                    auto itR = R.find(valToRemove);
                    if (itR != R.end()) {
                        R.erase(itR);
                    }
                }
            }
            
            // --- STEP 3: RE-BALANCE AFTER REMOVAL ---
            // If we removed from L, it might be smaller than 'needed'. 
            // Refill it from R.
            if (L.size() < needed && !R.empty()) {
                auto it = R.begin();
                int val = *it;
                R.erase(it);
                
                L.insert(val);
                currentSum += val;
            }

            // --- STEP 4: UPDATE ANSWER ---
            // Only update minSum if we have filled our requirement of (k-1) items
            if (L.size() == needed) {
                minSum = min(minSum, currentSum);
            }
        }
        
        // Add the cost of the first element (which is mandatory)
        return (long long)nums[0] + minSum;
    }
};

// --- Driver Code ---
int main() {
    Solution sol;
    
    // Test Case 1:
    // We keep 1. We need 2 more items. Window dist=3.
    // Windows of size 4: [3,2,6,4], [2,6,4,2]
    // Smallest 2 in first window: 2+3=5.
    // Smallest 2 in second window: 2+2=4.
    // Total = 1 + 4 = 5.
    vector<int> nums = {1, 3, 2, 6, 4, 2}; 
    int k = 3;
    int dist = 3;
    
    cout << "Minimum Cost: " << sol.minimumCost(nums, k, dist) << endl;
    // Expected Output: 5

    return 0;
}