#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>nums[i];
    }
    unordered_map<int,int>seen;
        int p=n/2;
        int count;
        for(int num:nums)
        {
            seen[num]++;
            if(seen[num]>p)
            {
                cout<<"Majority Number is "<<num;
                return 0;
            }
            
        }
        
    cout<<"No majority element found";
        
        
        return 0;
}
