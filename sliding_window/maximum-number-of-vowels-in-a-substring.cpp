#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to keep the sliding logic clean
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int vowels = 0;
        
        // Step 1: Count vowels in the very first window of size k
        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) vowels++;
        }
        
        int max_vowel = vowels;
        
        // Early exit: if we already hit the max possible, no need to loop further
        if(max_vowel == k) return k;

        // Step 2: Slide the window from index k to the end
        for(int i = k; i < s.length(); i++) {
            // Add the new character if it's a vowel
            if(isVowel(s[i])) vowels++;
            
            // Remove the character that is now outside the window
            if(isVowel(s[i - k])) vowels--;

            // Update the maximum count found so far
            if(vowels > max_vowel) {
                max_vowel = vowels;
            }
            
            // Optimization: Stop early if we hit the limit k
            if(max_vowel == k) return k;
        }
        
        return max_vowel;
    }
};

int main() {
    Solution sol;
    
    // Test Case: "abciiidef", k = 3 -> "iii" has 3 vowels
    string s = "abciiidef";
    int k = 3;
    cout << "Max Vowels in window: " << sol.maxVowels(s, k) << " (Expected: 3)" << endl;
    
    return 0;
}