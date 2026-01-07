#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double sum=0.0;
    double avg=0.0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    avg=sum/n;
    cout<<"Sum="<<sum<<" "<<"Avg="<<avg;
    
    
        
     
    
   return 0;
}