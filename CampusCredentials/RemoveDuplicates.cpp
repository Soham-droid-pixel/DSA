#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    
    int n = word.length();
    string result="";
    unordered_set<int>seen;
    for(char ch:word){
        if(seen.find(ch)==seen.end()){
            cout<<ch;
            seen.insert(ch);
        }
    }

   
    return 0;
}