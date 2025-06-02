#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Enter string"<<endl;
    getline(cin,s);
    int counter=0;
    bool flag=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]!=' ')
        {
            counter++;
            flag=1;
        }
        else{
            if(flag)
            break;
        }

    }
    cout<<counter;
    
    return 0;
}