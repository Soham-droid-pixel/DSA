#include <iostream>
#include <vector>
#include <unordered_map> 
#include <climits>       

// The Solution class containing both methods
class Solution {
public:
   
    int findMinWithHashMap(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        int min = INT_MAX;

        // First loop to populate the map
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // Second loop to find the minimum key in the map
        for (auto& it : map) {
            if (it.first < min) {
                min = it.first;
            }
        }
        return min;
    }

    int findMin(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high]) {
                // The right side is sorted, so the minimum is in the left half (or is mid).
                high = mid;
            } else if (nums[mid] > nums[high]) {
                // The pivot is in the right half.
                low = mid + 1;
            } else { // nums[mid] == nums[high]
                // Cannot decide, so safely shrink the search space.
                high--;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Simple sorted array
    std::vector<int> nums1 = {1, 3, 5};
    std::cout << "--- Test Case 1: [1, 3, 5] ---" << std::endl;
    std::cout << "Your Hash Map Output:   " << sol.findMinWithHashMap(nums1) << std::endl;
    std::cout << "Optimal BS Output:      " << sol.findMin(nums1) << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Test Case 2: Rotated array with duplicates
    std::vector<int> nums2 = {2, 2, 2, 0, 1};
    std::cout << "--- Test Case 2: [2, 2, 2, 0, 1] ---" << std::endl;
    std::cout << "Your Hash Map Output:   " << sol.findMinWithHashMap(nums2) << std::endl;
    std::cout << "Optimal BS Output:      " << sol.findMin(nums2) << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Test Case 3: Tricky duplicates
    std::vector<int> nums3 = {3, 3, 1, 3};
    std::cout << "--- Test Case 3: [3, 3, 1, 3] ---" << std::endl;
    std::cout << "Your Hash Map Output:   " << sol.findMinWithHashMap(nums3) << std::endl;
    std::cout << "Optimal BS Output:      " << sol.findMin(nums3) << std::endl;
    std::cout << "---------------------------------" << std::endl;

    return 0;
}

/*
 * =====================================================================================
 * ================== Why The Binary Search Technique is Better ========================
 * =====================================================================================
 * Both solutions in this file get the correct answer, which is excellent. However,
 * the binary search approach is considered optimal for several key reasons related to
 * efficiency.
 *
 * 1. SPACE COMPLEXITY: O(1) vs O(N)
 * -------------------------------------
 * - The Optimal (Binary Search) Solution: O(1) - Constant Space
 * This is the most significant advantage. The code only uses a few integer variables
 * (`low`, `high`, `mid`). Its memory usage does not increase no matter how large the
 * input array is.
 * - Your Hash Map Solution: O(N) - Linear Space
 * Your `unordered_map` needs to store unique elements. For a large array of 5000
 * unique elements, this means allocating space for 5000 map entries, which is far
 * less memory-efficient.
 *
 * WINNER: Binary Search is vastly more memory-efficient.
 *
 * 2. TIME COMPLEXITY: O(log N) Average vs O(N)
 * ----------------------------------------------
 * - The Optimal (Binary Search) Solution: O(log N) on average, O(N) in the worst case.
 * By repeatedly cutting the search space in half, this algorithm is exponentially
 * faster for most inputs. An array of a million elements takes roughly 20 steps,
 * not a million.
 * - Your Hash Map Solution: O(N) always.
 * Your code must iterate through the entire array at least once to build the map.
 * For an array of a million elements, it will always take a million steps.
 *
 * WINNER: Binary Search is significantly faster on average.
 *
 * 3. CORE PRINCIPLE: Using ALL the Information
 * -----------------------------------------------
 * The problem states the array is "sorted and rotated". Your solution doesn't use
 * this critical piece of information—it would work even on a completely unsorted
 * array. The binary search approach is specifically designed to exploit the
 * "sorted" property to discard huge chunks of the input at each step, which is the
 * key insight the problem is testing for.
 */