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
    cout<<endl;
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    int low=0;
    int high=n-1;
    int mid=0;
    while(low<=high){
       mid=low+(high-low)/2;
       if(arr[mid]==target){
         cout<<mid;
         return 0;
       }
       if(arr[mid]>target){
        high=mid-1;
       }
       else{
        low=mid+1;
       }
    }
    cout<<low;;
    return 0;

}
