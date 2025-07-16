#include <iostream>
#include <vector>
using namespace std;

// ✅ Brute-force solution: O(n^2)
int maxProductBruteForce(vector<int>& nums) {
    int max = 0;
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            result = (nums[i] - 1) * (nums[j] - 1);
            if (result > max) {
                max = result;
            }
        }
    }

    return max;
}

// ✅ Optimized solution: O(n)
int maxProductOptimized(vector<int>& nums) {
    int firstMax = 0;
    int secondMax = 0;

    for (int n : nums) {
        if (n > firstMax) {
            secondMax = firstMax;
            firstMax = n;
        } else if (n > secondMax) {
            secondMax = n;
        }
    }

    return (firstMax - 1) * (secondMax - 1);
}


int main() {
    vector<int> nums;
    int n, val;

    cout << "Enter number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    cout << "\n✅ Brute-force result: " << maxProductBruteForce(nums) << endl;
    cout << "✅ Optimized result: " << maxProductOptimized(nums) << endl;

    return 0;
}
