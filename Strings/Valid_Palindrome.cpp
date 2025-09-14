#include<bits/stdc++.h>
using namespace std;

int main()
{
    int left,right;
    string s;
    cout<<"Enter string"<<endl;
    getline(cin,s);
    left = 0, right = s.size() - 1;
        
        while (left < right) {
            
            while (left < right && !isalnum(s[left])) left++;
            
            while (left < right && !isalnum(s[right])) right--;
            
            if (tolower(s[left]) != tolower(s[right])) {
                cout<<"false";
                return 0;
            }
            left++;
            right--;
        }
        
        cout<<"true";
return 0;
}
/*
------------------ NOTES ------------------
1. getline(cin, s) → reads full input including spaces,
   unlike cin >> s which stops at the first space.

2. isalnum(c) → checks if character is alphanumeric
   (a–z, A–Z, 0–9). All others (spaces, commas, etc.)
   are ignored.

3. tolower(c) → converts a character to lowercase so
   comparison becomes case-insensitive.

4. Two-pointer approach:
   - left starts from beginning
   - right starts from end
   - move inward while skipping non-alphanumerics
   - compare each pair → if mismatch → not palindrome.

5. Time complexity = O(n), Space = O(1).
   Very efficient, no need to build extra strings.

6. Edge cases:
   - Empty string "" → palindrome → true
   - Single character "a" → palindrome → true
   - Only spaces/punctuation → true (becomes empty)
*/
