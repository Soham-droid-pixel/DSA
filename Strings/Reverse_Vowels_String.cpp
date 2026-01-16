#include <iostream>
#include <string>
#include <algorithm> // For swap

using namespace std;

class Solution {
public:
    // Helper function to check if a char is a vowel
    bool isVowel(char c) {
        c = tolower(c); // Convert to lowercase for easy checking
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 1. If left character is NOT a vowel, move forward
            if (!isVowel(s[left])) {
                left++;
            }
            // 2. If right character is NOT a vowel, move backward
            else if (!isVowel(s[right])) {
                right--;
            }
            // 3. Both are vowels -> SWAP them and move both pointers
            else {
                // Using built-in swap function (cleaner than temp variable)
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string input1 = "IceCreAm";
    string output1 = sol.reverseVowels(input1);
    cout << "Input:  " << "IceCreAm" << endl;
    cout << "Output: " << output1 << endl; // Expected: "AceCreIm"
    cout << "---------------------" << endl;

    // Test Case 2
    string input2 = "leetcode";
    string output2 = sol.reverseVowels(input2);
    cout << "Input:  " << "leetcode" << endl;
    cout << "Output: " << output2 << endl; // Expected: "leotcede"

    return 0;
}