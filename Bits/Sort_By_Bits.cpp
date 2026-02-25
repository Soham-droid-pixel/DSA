#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            if (countA == countB) {
                return a < b;
            }
            return countA < countB;
        });
        
        return arr;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> result1 = sol.sortByBits(arr1);
    
    cout << "Example 1 Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;

    vector<int> arr2 = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    vector<int> result2 = sol.sortByBits(arr2);
    
    cout << "Example 2 Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;

    return 0;
}