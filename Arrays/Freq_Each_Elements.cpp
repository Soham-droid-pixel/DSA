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
    unordered_map<int,int>counter;
    for(int num:arr){
        counter[num]++;
    }
    for(auto &it:counter){
        cout<<" "<<it.first<<"="<<it.second;
    }
    return 0;
}