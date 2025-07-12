#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    int nums[n];
    cout<<"Enter sorted array in ascending order"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int high=n-1;
    int low=0;
    int mid;
    while(low<=high)
    {
        mid=low +(high-low)/2;//Prevent integer overflow
        if (nums[mid]<target)
        {
            low =mid+1;
        }
        else if(nums[mid]==target)
        {
            cout<<"Index is: "<<mid;
            return 0;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"Index = -1"<<endl;
    return 0;

}