#include<iostream>
using namespace std;

int main()
{
    int n;
    int result=0;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<=n-1;i++){
        cin>>nums[i];
    }
    for(int num:nums)
    {
        result=result^num;
    }
    cout<<"Unique single number is "<<result<<endl;
    return 0;

}