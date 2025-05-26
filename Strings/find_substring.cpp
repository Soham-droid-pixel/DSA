#include<iostream>
using namespace std;

int main()
{
    string needle;
    string haystack;
    cout<<"Enter needle string: "<<endl;
    cin>>needle;
    cout<<"Enter haystack string : "<<endl;
    cin>>haystack;
    int i=0;
    if(needle.length()>haystack.length())
    {
        cout<<"Needle length cannot be greater and hence output is -1"<<endl;
        return 0;
    }
    for(i=0;i<=haystack.length()-needle.length();i++)
    {
                
        if(haystack.substr(i,needle.length()).compare(needle)==0)
        {
          cout<<i<<endl;
          return 0;
        }
            
    
    

        
    }
    cout<<-1<<endl;

        


}
