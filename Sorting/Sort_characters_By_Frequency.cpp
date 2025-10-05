#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // Not strictly needed for this version, but good practice

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character.
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create buckets. The index represents the frequency.
        // The size is s.length() + 1 because a character can appear at most s.length() times.
        vector<string> buckets(s.length() + 1, "");

        // Step 3: Fill the buckets.
        for (auto const& [character, frequency] : freq) {
            buckets[frequency].push_back(character);
        }

        // Step 4: Build the result string by iterating through buckets backwards.
        string result = "";
        for (int i = s.length(); i > 0; --i) {
            // If any characters had this frequency...
            if (!buckets[i].empty()) {
                // ...add them to the result string.
                for (char c : buckets[i]) {
                    result += string(i, c); // Append the character 'i' times
                }
            }
        }
        
        return result;
    }
};

// main() function to test the Solution class
int main() {
    Solution sol;

    // --- Test Case 1 ---
    string s1 = "tree";
    string result1 = sol.frequencySort(s1);
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << result1 << "\"" << endl; // Expected: "eert" or "eetr"
    cout << "-----------------------------------" << endl;

    // --- Test Case 2 ---
    string s2 = "cccaaa";
    string result2 = sol.frequencySort(s2);
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << result2 << "\"" << endl; // Expected: "aaaccc" or "cccaaa"
    cout << "-----------------------------------" << endl;

    // --- Test Case 3 ---
    string s3 = "Aabb";
    string result3 = sol.frequencySort(s3);
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << result3 << "\"" << endl; // Expected: "bbAa" or "bbaA"
    cout << "-----------------------------------" << endl;

    return 0;
}