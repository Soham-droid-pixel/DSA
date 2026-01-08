#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    
    int n = word.length();
    int left=0;
    int right=n-1;
    while(left<right){
        if(tolower(word[left])!=tolower(word[right])){
            cout<<"No";
            return 0;
        }
        left++;
        right--;
    }
    cout<<"Yes";
   
    return 0;
}