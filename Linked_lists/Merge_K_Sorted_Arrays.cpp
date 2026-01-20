#include <iostream>
#include <vector>
#include <queue> // Useful for Priority Queue (Min-Heap) approach
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> mergeTwoArrays(vector<int>& arr1, vector<int>& arr2){
        vector<int>merged;
        int i=0;
        int j=0;
        while(i<arr1.size()&& j<arr2.size()){
            if(arr1[i]<arr2[j]){
                merged.push_back(arr1[i]);
                i++;
            }
            else{
                merged.push_back(arr2[j]);
                j++;
            }
        }
        while(i<arr1.size()){
            merged.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            merged.push_back(arr2[j++]);
        }
        return merged;
    }
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        if(k==0){
            return {};
        }
        int interval=1;
        while(interval<k){
            for(int i=0;i+interval<k;i+=interval*2){
                arr[i]=mergeTwoArrays(arr[i],arr[i+interval]);
            }
            interval*=2;
        }
        return arr[0];
        
    }
};

// --- Helper Code to Run and Test ---
int main() {
    Solution sol;

    // Test Case 1: Standard
    int k1 = 3;
    vector<vector<int>> arr1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Test Case 1 Input: [[1,2,3],[4,5,6],[7,8,9]]" << endl;
    vector<int> res1 = sol.mergeKSortedArrays(arr1, k1);
    
    cout << "Output: [ ";
    for (int num : res1) cout << num << " ";
    cout << "]" << endl;

    cout << "--------------------------------" << endl;

    // Test Case 2: Your Input (k=1)
    int k2 = 1;
    vector<vector<int>> arr2 = {
        {10}
    };

    cout << "Test Case 2 Input: [[10]]" << endl;
    vector<int> res2 = sol.mergeKSortedArrays(arr2, k2);

    cout << "Output: [ ";
    for (int num : res2) cout << num << " ";
    cout << "]" << endl;

    return 0;
}
/*The Analogy: The Tournament Bracket 🏆
Imagine you have 4 teams (Arrays 0, 1, 2, 3). You don't want Team 0 to play everyone one by one. You want them to play in rounds.

Let's Trace with k = 4 Arrays
Indices: 0, 1, 2, 3

Round 1 (interval = 1)
Logic: Every neighbor plays against each other.

The Loop: i starts at 0. We want to merge arr[0] and arr[0 + 1].

Action: Merge arr[0] and arr[1].

Storage: The winner (merged result) stays at index 0.

Next Step: i increases by interval * 2 (which is 2).

The Loop: i is now 2. We want to merge arr[2] and arr[2 + 1].

Action: Merge arr[2] and arr[3].

Storage: The winner stays at index 2.

End of Round:

Index 0 now holds: (Old 0 + Old 1)

Index 2 now holds: (Old 2 + Old 3)

Indices 1 and 3 are now "dead" (ignored).

Round 2 (interval = 2)
Update: interval doubles to 2.

Logic: Now we merge the "Winners" from the previous round.

The Loop: i starts at 0. We want to merge arr[0] and arr[0 + 2].

Action: Merge arr[0] (which has 0+1) and arr[2] (which has 2+3).

Storage: The winner stays at index 0.

Next Step: i increases by interval * 2 (which is 4).

Stop: 4 is not less than k (4). Loop ends.

The Result
Index 0 now holds everything: (0 + 1 + 2 + 3).

We return arr[0].

Decoding the Code Lines
interval *= 2:

This doubles the "gap" every round.

Round 1 gap: 1 (0 vs 1)

Round 2 gap: 2 (0 vs 2)

Round 3 gap: 4 (0 vs 4)

i += interval * 2:

This skips the "dead" arrays.

In Round 1, we merge (0,1), then we need to skip 1 and jump to 2. That's why we jump by 2.

In Round 2, we merge (0,2), then we need to skip 2 and 3 and jump to 4. That's why we jump by 4.

arr[i] = ...:

We are recycling the input vector arr to store our partial answers. We don't create a new separate list of lists. This saves memory. The "winner" always sits at the lower index.*/