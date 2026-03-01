#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
int minPartitions(string n){
char max_digit='0';
for(char c:n){
if(c>max_digit)max_digit=c;
if(max_digit=='9')break;
}
return max_digit-'0';
}
};

int main(){
Solution sol;
string n1="32";
cout<<"Input:"<<n1<<"->Output:"<<sol.minPartitions(n1)<<endl;
string n2="82734";
cout<<"Input:"<<n2<<"->Output:"<<sol.minPartitions(n2)<<endl;
string n3="27346209830709182346";
cout<<"Input:"<<n3<<"->Output:"<<sol.minPartitions(n3)<<endl;
return 0;
}