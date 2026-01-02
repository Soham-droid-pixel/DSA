#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate
#include <unordered_set>

using namespace std;

vector<int> transform_list(vector<int> arr, int k) {
    int n = arr.size();
    vector<int> combined_list;

    // Step 1: Sliding Window to get all subarrays of size k
    for (int i = 0; i <= n - k; i++) {
        // Create subarray from index i to i+k
        vector<int> sub(arr.begin() + i, arr.begin() + i + k);
        
        // Calculate sum
        long long current_sum = accumulate(sub.begin(), sub.end(), 0LL);

        // Step 2: Transform based on sum parity
        if (current_sum % 2 == 0) {
            // Even sum -> Reverse
            reverse(sub.begin(), sub.end());
        } else {
            // Odd sum -> Sort
            sort(sub.begin(), sub.end());
        }

        // Step 3: Append to master list
        combined_list.insert(combined_list.end(), sub.begin(), sub.end());
    }

    // Step 4: Remove duplicates while PRESERVING ORDER
    vector<int> final_result;
    unordered_set<int> seen;

    for (int num : combined_list) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            final_result.push_back(num);
        }
    }

    return final_result;
}

int main() {
    // Sample Input logic
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int k;
    cin >> k;

    vector<int> res = transform_list(arr, k);
    
    for(int x : res) cout << x << " ";
    return 0;
}