#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    string words[n];
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    char x;
    cout<<"Enter character to be searched"<<endl;
    cin>>x;
    for(int i=0;i<=n-1;i++)
    {
         
        for(int j=0;j<words[i].length();j++)
         {
            if(x==words[i][j])
            {
                cout<<i;
                break;
            }
            
            
         }

           
    }
    return 0;
}