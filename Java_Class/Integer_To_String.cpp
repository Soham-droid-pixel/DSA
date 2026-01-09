#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string s;
    for(int i=0;i<n;i++){
      s+=to_string(arr[i]);
    }
    cout<<s;

    return 0;
}