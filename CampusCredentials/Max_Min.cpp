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
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Max="<<max;
    cout<<"Min="<<min;
   return 0;
}