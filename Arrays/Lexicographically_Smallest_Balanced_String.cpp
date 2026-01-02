#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string smallestBalancedString(string s) {
    string unique_chars = "";
    unordered_set<char> seen;

    // Step 1: Filter duplicates while PRESERVING ORDER
    // (Your code failed here because map iteration is random/hashed)
    for (char c : s) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            unique_chars += c;
        }
    }

    // Step 2: Separate into vowels and consonants
    string vowels = "";
    string consonants = "";

    for (char c : unique_chars) {
        if (isVowel(c)) {
            vowels += c;
        } else {
            consonants += c;
        }
    }

    // Step 3: Sort individually
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    // Step 4: Concatenate
    return vowels + consonants;
}

int main() {
    string s;
    // Example Input: bcabca
    // Output should be: abc
    cin >> s; 
    cout << smallestBalancedString(s) << endl;
    return 0;
}