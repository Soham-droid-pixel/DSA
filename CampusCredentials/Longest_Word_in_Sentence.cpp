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