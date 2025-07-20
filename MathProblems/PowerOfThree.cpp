#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0){
            return false;
        }
        while (n%3==0) n/=3;
        return n ==1;
    }
};
int main()
{
    Solution sol;
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    if(sol.isPowerOfThree(n)){
        cout<<"Perfect power of three"<<endl;
    }
    else{
        cout<<"Not perfect power of three"<<endl;
    }
    return 0;
};