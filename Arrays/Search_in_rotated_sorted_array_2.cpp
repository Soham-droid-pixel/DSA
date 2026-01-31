#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // EDGE CASE: Handle duplicates where we can't decide direction
            // Example: [1, 0, 1, 1, 1] -> low, mid, high are all 1.
            // We just skip the duplicates at the edges.
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Case 1: Left half is sorted
            if (nums[low] <= nums[mid]) {
                // Is target inside this sorted range?
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Look in left
                } else {
                    low = mid + 1;  // Look in right
                }
            }
            // Case 2: Right half is sorted
            else {
                // Is target inside this sorted range?
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Look in right
                } else {
                    high = mid - 1; // Look in left
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << "Found 0? " << sol.search(nums, 0) << endl; // 1 (true)
    cout << "Found 3? " << sol.search(nums, 3) << endl; // 0 (false)
    return 0;
}
/*class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int>val;
        for(int i=0;i<nums.size();i++){
            val.insert(nums[i]);
            
        }
        auto it=val.find(target);
        if(it!=val.end()){
        return true;
        }
        else{
            return false;
        }
    }
};*/
/*Answer to the Follow-up QuestionDoes duplicates affect complexity? Yes.How? In the worst case (like [1,1,1,1,1,2,1]), the low++ and high-- check might run for almost every step.Result: The time complexity degrades from $O(\log N)$ to $O(N)$. This makes the worst case for this approach the same as your set approach, but on average, this is much faster!*/