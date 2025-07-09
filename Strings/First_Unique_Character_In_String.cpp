#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq; // To store character counts

        // First pass: Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Second pass: Find the first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        // If no unique character found
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Index of first unique character: " << sol.firstUniqChar(s) << endl;
    return 0;
}
/*
📝 First Unique Character in a String - Notes

🎯 Goal:
Return the index of the first non-repeating character in the string.
If none exists, return -1.

--------------------------------------------------

✅ Correct Approach:
1. Use a hashmap (unordered_map<char, int>) to count character frequencies.
2. Loop through the string again and return the first index with frequency == 1.

--------------------------------------------------

⚠️ Common Mistakes to Avoid:

1. ❌ Using nested loops (O(n²)) → too slow for long strings (s.length can be up to 10^5)
   ✅ Use hashing (unordered_map) to reduce time to O(n)

2. ❌ Returning the last unique character instead of the first
   ✅ Always check and return the **first** character with count == 1

3. ❌ Forgetting to handle cases like "aabb" properly
   ✅ In such cases, return `-1` when no unique character exists

4. ❌ Using unordered_map incorrectly
   ✅ Remember: `map[ch]++` automatically initializes count to 0 before incrementing

--------------------------------------------------

💡 Things to Remember While Revising:

🔸 This is a classic hashmap problem — know how to:
    - Count frequencies
    - Iterate to find condition based on frequency

🔸 Works in O(n) time and O(1) space (only 26 lowercase letters)

🔸 unordered_map is better than map here (faster average case due to hash table)

--------------------------------------------------

👀 Example Dry Run:
Input: "loveleetcode"
Frequencies:
l → 1, o → 2, v → 1, e → 3, t → 1, c → 1, d → 1
First with count == 1 → 'l' at index 2 → Output: 2

--------------------------------------------------

📌 Tip:
Hashmaps are your best friend in string problems. Master them.
*/

