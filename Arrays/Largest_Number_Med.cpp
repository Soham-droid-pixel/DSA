#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Step 1: Convert all numbers to strings
        // Why? Because we want to compare concatenations like "9"+"34" vs "34"+"9"
        vector<string> arr;
        for (int n : nums) {
            arr.push_back(to_string(n));
        }

        // Step 2: Sort using custom comparator
        // sort(arr.begin(), arr.end(), compare_function)
        // Here we give a lambda function as comparator
        // Comparator Rule:
        // For two strings a and b:
        //    If a+b > b+a, then a should come before b
        //    Otherwise, b should come before a
        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;  
            // Example: 
            // a = "9", b = "34"
            // a+b = "934", b+a = "349"
            // Since "934" > "349", "9" will be placed before "34"
        });

        // Step 3: Edge case
        // If the largest number is "0" (means all are zeros), return "0"
        if (arr[0] == "0") {
            return "0";
        }

        // Step 4: Build the final string by concatenating
        string ans = "";
        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};

// -------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {10, 2};
    cout << "Input: [10,2]\n";
    cout << "Output: " << sol.largestNumber(nums1) << "\n\n";  
    // Expected: "210"

    // Example 2
    vector<int> nums2 = {3, 30, 34, 5, 9};
    cout << "Input: [3,30,34,5,9]\n";
    cout << "Output: " << sol.largestNumber(nums2) << "\n";  
    // Expected: "9534330"

    return 0;
}
/*
sort(start_iterator, end_iterator, comparator_function);
Normally, sort arranges elements in ascending order.

But here, we pass a custom comparator (lambda function).

🔹 Lambda function: [](string a, string b) { return a+b > b+a; }

[] → capture list (don’t worry much, here it’s empty).

(string a, string b) → inputs given to comparator.

{ return a+b > b+a; } → rule for sorting.

👉 Meaning: When comparing two strings a and b:

Put a before b if a+b is greater than b+a.

Example:

Compare "9" and "34".

"9" + "34" = "934"

"34" + "9" = "349"

Since "934" > "349", "9" should come first.

This ensures numbers are ordered in such a way that their concatenation forms the largest possible number.*/