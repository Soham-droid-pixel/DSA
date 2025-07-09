#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;
    if(num==0)
    {
        cout<<0;
    }
    else if(num%9==0)
    {
      cout<<9;
    }
    else{
        cout<<num%9;
    }
    return 0;

}
/*
⚠️ Common Mistakes to Avoid:

1. ❌ Only doing digit addition twice
   - Your earlier code did only two digit-sum passes (e.g., 38 → 11 → 2).
   - But what if the result is still >= 10? You need a loop or math trick!

2. ❌ Using unnecessary loops when O(1) solution exists
   - Though looping works, it's slower and less elegant for interviews.

3. ❌ Ignoring num == 0 case
   - Digital root of 0 is 0, not 9.

4. ❌ Forgetting optimization when asked for O(1)
   - Always look for math-based tricks when loops aren't allowed.

📌 Tip:
This is a classic **Digital Root / Math trick** question. Expect this in fast round interviews (Amazon, Adobe, etc.).
*/

/*class Solution {
public:
    int addDigits(int num) {
        int result=0;
        int revnum=0;
        int result2=0;
        while(num!=0)
        {
            revnum=num%10;
            result=result+revnum;
            num=num/10;
            

        }
        while(result!=0)
        {
            revnum=result%10;
            result2=result2+revnum;
            result=result/10;
            
        }
        return result2;
            }
};Dont use this..instead use above program*/