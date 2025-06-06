#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> freq;

        // Count frequencies of even numbers only
        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
            }
        }

        int maxFreq = 0;
        int result = -1;

        // Find the even number with highest frequency
        // If tie, choose the smallest one
        for (auto& p : freq) {
            int num = p.first;
            int count = p.second;
            if (count > maxFreq || (count == maxFreq && num < result)) {
                maxFreq = count;
                result = num;
            }
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int answer = sol.mostFrequentEven(nums);

    if (answer == -1) {
        cout << "No even element found" << endl;
    } else {
        cout << "Most frequent even element is: " << answer << endl;
    }

    return 0;
}
