#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string to get words in correct order
        // Example: "the sky is blue" -> "eulb si yks eht"
        reverse(s.begin(), s.end());

        int n = s.length();
        int idx = 0; // "Write" pointer: where we place the cleaned-up characters
        int i = 0;   // "Read" pointer: where we are currently looking

        while (i < n) {
            if (s[i] != ' ') {
                // If this is NOT the first word, add a single space separator first
                if (idx != 0) s[idx++] = ' ';

                // 'start' marks the beginning of the current word in our "clean" version
                int start = idx;

                // Copy the word from the read pointer (i) to the write pointer (idx)
                while (i < n && s[i] != ' ') {
                    s[idx++] = s[i++];
                }

                // 'end' marks the end of the word we just copied
                int end = idx;

                // Step 2: Reverse ONLY the current word to fix its letters
                // "eulb" -> "blue"
                reverse(s.begin() + start, s.begin() + end);
            } else {
                // If it's just a space, skip it
                i++;
            }
        }

        // Step 3: Cut off any extra characters (garbage) remaining at the end
        s.resize(idx);
        
        return s;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard sentence
    string s1 = "the sky is blue";
    cout << "Input:  \"" << s1 << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s1) << "\"" << endl;
    cout << "---------------------------" << endl;

    // Test Case 2: Leading and trailing spaces
    string s2 = "  hello world  ";
    cout << "Input:  \"" << s2 << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s2) << "\"" << endl;
    cout << "---------------------------" << endl;

    // Test Case 3: Multiple spaces between words
    string s3 = "a good   example";
    cout << "Input:  \"" << s3 << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s3) << "\"" << endl;
    cout << "---------------------------" << endl;

    return 0;
}