#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true; // Duplicate found
            }
            seen.insert(num);
        }
        return false; // No duplicates
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (sol.containsDuplicate(nums)) {
        cout << "Duplicate exists." << endl;
    } else {
        cout << "All elements are unique." << endl;
    }

    return 0;
}


/*#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int nums[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>nums[i];
    }
    int distinct=1;
    
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++){
         if(nums[i]==nums[j])
         {
            distinct=0;
         }
        
        }
        break;
      
      
      
    }
    if(distinct)
      {
        cout<<"False"<<endl;
      }
      else{
        cout<<"True"<<endl;
      }
    return 0;
    "Dont use this method because this takes o(n^2) time complexity"
}*/