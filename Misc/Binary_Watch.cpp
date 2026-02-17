#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result; // Corrected from vector<int> to vector<string>
        
        // Loop through all Hours (0-11)
        for(int h = 0; h < 12; h++) {
            
            // Loop through all Minutes (0-59)
            for(int m = 0; m < 60; m++) {
                
                // Count bits: __builtin_popcount is a GCC/Clang specific function
                // It counts how many 1s are in the binary representation
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    
                    string time = to_string(h) + ":";
                    
                    // Add leading zero for single digit minutes (e.g., 1:05)
                    if(m < 10) {
                        time += "0";
                    }
                    
                    time += to_string(m);
                    result.push_back(time);
                } 
            }
        }
        return result;
    }
};

// --- Main Function for Testing ---
int main() {
    Solution sol;
    int turnedOn = 1; // Example input

    vector<string> times = sol.readBinaryWatch(turnedOn);

    cout << "Possible times for turnedOn = " << turnedOn << ":" << endl;
    cout << "[";
    for(int i = 0; i < times.size(); i++) {
        cout << "\"" << times[i] << "\"";
        if (i < times.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}