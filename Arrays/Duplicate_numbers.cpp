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
    unordered_set<int>seen;
    set<int>duplicates;
    
    for(int num:arr){
        if(seen.find(num)!=seen.end()){
         duplicates.insert(num);
        }
        else{
            seen.insert(num);
        }
    }
    if(duplicates.empty()){
         cout<<"No duplicates"<<endl;
    }
    else{
    for(int num:duplicates){
        cout<<num<<" ";
    }
}
   return 0;
}