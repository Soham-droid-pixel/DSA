#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = n % 2;
        n = n >> 1;
        
        while (n > 0) {
            int currentBit = n % 2;
            
            if (currentBit == lastBit) {
                return false;
            }
            
            lastBit = currentBit;
            n = n >> 1;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    int n1 = 5;
    int n2 = 7;
    int n3 = 11;

    cout << "Input: " << n1 << " Output: " << (sol.hasAlternatingBits(n1) ? "true" : "false") << endl;
    cout << "Input: " << n2 << " Output: " << (sol.hasAlternatingBits(n2) ? "true" : "false") << endl;
    cout << "Input: " << n3 << " Output: " << (sol.hasAlternatingBits(n3) ? "true" : "false") << endl;

    return 0;
}