#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string res = "";
        for (string s : strs) {
            // PROTOCOL: [Length of String] + [#] + [Actual String]
            // We use '#' as a marker to show where the length number ends.
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    /**
     * @param str: A single encoded string
     * @return: decodes the string back into the original list of strings
     */
    vector<string> decode(string &str) {
        vector<string> res;
        int i = 0; // Pointer to the start of the current length-prefix
        
        while (i < str.size()) {
            int j = i;
            
            // 1. Find the delimiter '#' to figure out where the length ends
            while (str[j] != '#') {
                j++;
            }
            
            // 2. Extract the length from the substring before the '#'
            int len = stoi(str.substr(i, j - i));
            
            // 3. Move i to the start of the actual string (one position after '#')
            i = j + 1;
            
            // 4. Use the known length to grab the exact string content
            res.push_back(str.substr(i, len));
            
            // 5. Jump i to the start of the next length-prefix
            i += len;
        }
        return res;
    }
};

// --- Helper function to print results for testing ---
void printResult(const vector<string>& original, const vector<string>& decoded) {
    bool match = (original == decoded);
    cout << "Match: " << (match ? "✅ SUCCESS" : "❌ FAILED") << endl;
    cout << "Decoded List: [";
    for (int i = 0; i < decoded.size(); i++) {
        cout << "\"" << decoded[i] << "\"" << (i == decoded.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl << "----------------------------" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard words
    vector<string> input1 = {"lint", "code", "love", "you"};
    string encoded1 = sol.encode(input1);
    vector<string> decoded1 = sol.decode(encoded1);
    cout << "Test 1 | Encoded: " << encoded1 << endl;
    printResult(input1, decoded1);

    // Test Case 2: Handling the delimiter '#' inside the string
    vector<string> input2 = {"we", "say", "#", "yes", "5#hello"};
    string encoded2 = sol.encode(input2);
    vector<string> decoded2 = sol.decode(encoded2);
    cout << "Test 2 | Encoded: " << encoded2 << endl;
    printResult(input2, decoded2);

    // Test Case 3: Empty strings and spaces
    vector<string> input3 = {"", " ", "!!!", "123"};
    string encoded3 = sol.encode(input3);
    vector<string> decoded3 = sol.decode(encoded3);
    cout << "Test 3 | Encoded: " << encoded3 << endl;
    printResult(input3, decoded3);

    return 0;
}