#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cout<<"Enter string1"<<endl;
    getline(cin,s1);
    cout<<"enter string 2"<<endl;
    getline(cin,s2);
    unordered_map<char,int>map1;
    if (s1.length() != s2.length()) {
        cout << "False" << endl;
        return 0; 
    }
    for(int i=0;i<s1.length();i++)
    {
            map1[s1[i]]++;
    }
    unordered_map<char,int>map2;
    for(int i=0;i<s2.length();i++)
    {
            map2[s2[i]]++;
    }
    if(map1==map2){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
   return 0;
}