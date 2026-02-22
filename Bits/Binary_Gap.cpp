#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        if (__builtin_popcount(n) <= 1) {
           return 0;
        }
        
        vector<int> result;
        while (n > 0) {
          result.push_back(n % 2);
          n = n / 2;
        }
        
        int max_count = 0;
        int last_one_index = -1;
        
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 1) {
                if (last_one_index != -1) {
                    max_count = max(max_count, i - last_one_index);
                }
                last_one_index = i;
            }
        }
        
        return max_count;
    }
};

int main() {
    Solution sol;
    cout << "Input: 22 -> Output: " << sol.binaryGap(22) << " (Expected: 2)" << endl;
    cout << "Input: 8  -> Output: " << sol.binaryGap(8) << " (Expected: 0)" << endl;
    cout << "Input: 5  -> Output: " << sol.binaryGap(5) << " (Expected: 2)" << endl;
    return 0;
}