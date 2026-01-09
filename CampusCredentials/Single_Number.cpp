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
    int result=0;
    for(int i=0;i<n;i++){
     result=result^arr[i];
    }
    cout<<result;

}
