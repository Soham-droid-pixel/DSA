#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    int arr[n];
    int targetarr[2];
    bool flag=false;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=n-1;i++){
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]+arr[j]==target)
        {
            targetarr[0]=i;
            targetarr[1]=j;
            flag=true;
            break;
        }
        
    
    
    
    }    
        if(flag)
        {
            break;
        }
        

    }
        if(flag){
        cout<<"Indices:"<<targetarr[0]<<" "<<targetarr[1];
        }
        else{
            cout<<"No soln found";
        }

    return 0;
}