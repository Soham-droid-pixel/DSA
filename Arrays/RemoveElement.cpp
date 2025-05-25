#include<iostream>
using namespace std;

int main()
{
    int n,p;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>nums[i];

    }
    int val;
    cout<<"Enter value to be removed"<<endl;
    cin>>val;
    int expnums[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(val!=nums[i])
        {
          expnums[k]=nums[i]; 
          k++;
          
        }

    }
    cout<<"Result= "<<k;
    return 0;
}