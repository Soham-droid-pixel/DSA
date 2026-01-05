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
    /*int ans=0;
    for(int i=1;i<=n;i++){
    ans=ans^i;
    }
    for(int i=0;i<n;i++){
    ans=ans^nums[i];
    }*/
    
    sort(arr,arr+n);
    int j=1;
    int missing=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==j){
            j++;
        }
    missing=j;
    }
    cout<<missing;
    return 0;
}
