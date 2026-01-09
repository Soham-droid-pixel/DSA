#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cout << "Enter sentence: ";
    getline(cin, s);

    map<char,int>count;
    for(char ch:s){
        count[ch]++;
    }
    for(auto &it:count){
        cout<<it.first<<it.second;
    }

    return 0;
}
/*Optimized one
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<int> freq(256, 0);

    for (char ch : s) {
        freq[ch]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << freq[i];
        }
    }

    return 0;
}*/