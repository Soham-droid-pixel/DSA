#include<bits/stdc++.h>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    
    int n = word.length();
    int vowels=0,consonants=0;
    for(int i=0;i<n;i++){
        char ch=tolower(word[i]);
        if(isalpha(ch)){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            vowels++;
        }
        else{
            consonants++;
        }
    }
}
    cout<<"No of vowels= "<<vowels<<"No of consonants= "<<consonants;
   
    return 0;
}