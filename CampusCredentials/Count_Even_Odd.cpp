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
    int oddcounter=0;
    int evencounter=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            evencounter++;
        }
        else{
            oddcounter++;
        }
    }
    cout<<evencounter<<" "<<oddcounter;
    
    
    
    
        
     
    
   return 0;
}