#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int freq[51]={0};
     int result=0;
     for(int num:nums)
     {
        freq[num]++;
     }   
     for(int i=1;i<=50;i++)
     {
        if(freq[i]==2)
        {
            result=result^i;
        }
     }
     cout<<result;
     return 0;
}