#include<iostream>
using namespace std;

int main()
{
    int n,target;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int nums[n];
    cout<<"Enter sorted array"<<endl;
    for(int i=0;i<=n-1;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter target"<<endl;
    cin>>target;
    bool found=false;
    for(int i=0;i<n;i++)
    {
      if(nums[i]==target)
      {
        cout<<i;
        found=true;
        break;
      }
        
    
    else if(nums[i]>target){
        cout<<i;
        found=true;
        break;
        
      }
    
    }
    if(!found)
      {
        cout<<n;
      }
    
    
    return 0;
}