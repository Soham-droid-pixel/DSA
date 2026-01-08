#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> words;
    string word;
    while(cin >> word) {
        words.push_back(word);
    }
    for(int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if(i > 0) cout << " ";
    }
    
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    
    int n = word.length();
    int left=0;
    int right=n-1;
    //Both below methods are for reversing string and words both
    /*while(left<right){
        char temp=word[left];
        word[left]=word[right];
        word[right]=temp;
        left++;
        right--;
    }*/
   /*reverse(word.begin(),word.end());
   for(char ch:word){
    cout<<ch<<"";
   }This is for reversing the words too with reversal of strings
   for(char ch:word){
    cout<<ch<<"";
   }
    return 0;
}*/