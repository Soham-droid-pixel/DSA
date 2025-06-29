#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    int minprice=arr[0];
    int profit;
    int maxprofit=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<minprice)
        {
            minprice=arr[i];
        }
        else{
        profit=arr[i]-minprice;
        if(profit>maxprofit)
        {
            maxprofit=profit;
        }
    }
    
       
    }
    cout<<"Max profit= "<<maxprofit;
    return 0;
}