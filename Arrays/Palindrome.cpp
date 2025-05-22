#include<iostream>
using namespace std;

int main()
{
    int n,rem;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int originalnum=n;
    int revnum=0;
    while(n>0)
    {
    rem=n%10;
    revnum=revnum*10+rem;
    n=n/10;
    }
    if(originalnum==revnum)
    {
        cout<<" "<<originalnum<<"is a palindrome number";
    }
    else{
        cout<<" "<<originalnum<<"is not a palindrome number";
    }
    return 0;
}