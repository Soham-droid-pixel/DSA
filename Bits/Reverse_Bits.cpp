#include <iostream>
#include <bitset>   // Used to print numbers in binary format (0s and 1s)
#include <cstdint>  // Required for uint32_t

using namespace std;

class Solution {
public:
    // We use uint32_t to ensure it is exactly 32 bits and unsigned
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            // 1. Shift result to the left to open up a spot
            result = result << 1;
            
            // 2. Add the last bit of 'n' to that open spot
            // (n & 1) gets the last bit (0 or 1)
            result = result | (n & 1);
            
            // 3. Shift 'n' to the right to process the next bit
            n = n >> 1;
        }
        
        return result;
    }
};

// --- Main Function for Testing ---
int main() {
    Solution sol;
    
    // Example: n = 43261596
    uint32_t input = 43261596;
    
    cout << "Input (Decimal): " << input << endl;
    cout << "Input (Binary):  " << bitset<32>(input) << endl;
    
    uint32_t output = sol.reverseBits(input);
    
    cout << "------------------------------------------------" << endl;
    cout << "Output (Decimal): " << output << " (Expected: 964176192)" << endl;
    cout << "Output (Binary):  " << bitset<32>(output) << endl;

    return 0;
}