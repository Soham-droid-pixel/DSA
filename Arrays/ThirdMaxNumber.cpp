#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long max=LONG_MIN,p1=LONG_MIN,p2=LONG_MIN;
    for(int i=0;i<n;i++)
    {
     if(arr[i]==max||arr[i]==p1||arr[i]==p2){
        continue;
     }
     if(arr[i]>max)
     {
        p2=p1;
        p1=max;
        max=arr[i];
     }
     else if(arr[i]<max && arr[i]>p1)
     {
        
        p2=p1;
        
        p1=arr[i];
     }
     else if(arr[i]<p1 && p2<arr[i])
     {
        p2=arr[i];
     }
     
    }
    if(p2!=LONG_MIN){
     cout<<"Third max = "<<p2<<endl;
    }
    else{
        cout<<"Max no is "<<max<<endl;
    }
    
    return 0;
}