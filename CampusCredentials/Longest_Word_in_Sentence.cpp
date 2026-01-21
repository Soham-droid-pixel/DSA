#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    
    int n = word.length();
    int current_len = 0;
    int max_len = 0;
    int max_start_index = 0;
    int current_start_index = 0;
    
    for(int i = 0; i <= n; i++) {
        if(i == n || word[i] == ' ') {
            if(current_len > max_len) {
                max_len = current_len;
                max_start_index = current_start_index;
            }
            
            current_len = 0;
            current_start_index = i + 1;
        }
        else {
            current_len++;
        }
    }
    
    cout << word.substr(max_start_index, max_len);
    
    return 0;
}
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Useful for reverse()
#include <sstream>   // Useful for stringstream
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // ---------------------------------------------------------
        // TODO: WRITE YOUR LOGIC HERE
        // Goal: Reverse the order of words in the string 's'.
        // Rules:
        // 1. Words are separated by spaces.
        // 2. The result should not contain leading or trailing spaces.
        // 3. There should be only ONE space between words in the output.
        // Example: "  hello   world  " -> "world hello"
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }
        string result="";
        for(int i=words.size()-1;i>=0;i--){
            result+=words[i];
            if(i>0){
             result+=" ";
            }
        }
        return result;
        
        
        
        
    }
};

// --- Helper Code to Run and Test ---
int main() {
    Solution sol;

    // Test Case 1: Standard
    string s1 = "hello world";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s1) << "\"" << endl;
    // Expected: "world hello"

    cout << "--------------------------------" << endl;

    // Test Case 2: Extra Spaces (Leading/Trailing/Middle)
    string s2 = "  the   sky  is   blue  ";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s2) << "\"" << endl;
    // Expected: "blue is sky the"

    cout << "--------------------------------" << endl;

    // Test Case 3: Single Word
    string s3 = "Coding";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << sol.reverseWords(s3) << "\"" << endl;
    // Expected: "Coding"

    return 0;
}*/