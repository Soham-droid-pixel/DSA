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
    int max_profit=0;
    int current_profit=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        current_profit=arr[j]-arr[i];
          if(current_profit>max_profit){
            max_profit=current_profit;
          }   
        }

    }
    if(max_profit!=0){
    cout<<"Max profit="<<max_profit;
    }
    else{
        return 0;
    }
    
    return 0;
}
/*
int min_price=INT_MAX;
int max_profit=0;
for(int i=0;i<n;i++){
if(arr[i]<min_price){
min_price=arr[i];
}
else if(arr[i]-min_price>max_profit){
max_profit=arr[i]-min_price;
}
}
return maxprofit;
}*/