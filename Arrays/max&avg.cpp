#include<iostream>
using namespace std;

int main()
{
    int n,maximum;
    double avg=0.0;
    double sum =0.0;
    cout<<"enter how many numbers you want"<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"Invalid input of numbers"<<endl;
    }
    else{
    int arr[n];
    
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
        
        
    }
    maximum=arr[0];
    for(int i=0;i<=n-1;i++)
    {
        
        if(arr[i]>maximum)
        {
            maximum=arr[i];
            
        }
    sum=sum+arr[i];
    }
    cout<<"Maximum number:"<<maximum<<endl;
    avg=sum/n;
    cout<<"Average value: "<<avg;
    return 0;
} 

}