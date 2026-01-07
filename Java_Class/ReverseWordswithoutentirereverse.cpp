#include <iostream>
#include <string>
#include <algorithm> // For swap

using namespace std;

int main() {
    string s;
    cout << "Enter sentence: ";
    getline(cin, s);

    int start = 0;

    for(int i = 0; i <= s.length(); i++) {
        // If we hit a space OR the end of the string
        if(i == s.length() || s[i] == ' ') {
            
            // Reverse the word between 'start' and 'i-1'
            int l = start;
            int r = i - 1;

            while(l < r) {
                swap(s[l], s[r]); // Swaps characters easily
                l++;
                r--;
            }

            // Update start for the next word
            start = i + 1;
        }
    }

    cout << s << endl;

    return 0;
}