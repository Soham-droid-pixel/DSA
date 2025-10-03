#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cout<<"Enter value of m"<<endl;
    cin>>m;
    cout<<"Enter value of n"<<endl;
    cin>>n;
    int nums1[m+n];
    int nums2[n];
    cout<<"Enter values in nums1"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>nums1[i];
    }
    cout<<"Enter values in nums2"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k]=nums1[i];
            i--;
        }
        else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
    while(j>=0)
    {
        nums1[k]=nums2[j];
        j--;
        k--;
    }
    cout<<"Now final nums1 array"<<endl;
    for(int i=0;i<(m+n);i++)
    {
        cout<<"\t"<<nums1[i];
    }
    return 0;
}