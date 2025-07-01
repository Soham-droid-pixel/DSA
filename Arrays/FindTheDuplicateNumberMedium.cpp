#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size (should be n+1 for values in [1,n])" << endl;
    cin >> n;

    int nums[n];
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Phase 1: Detect cycle
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the start of cycle (duplicate)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    cout << "Duplicate number is: " << slow << endl;

    return 0;
}
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    result=nums[i];
                }
                
            }
        }
        return result;
    }
};this will exceed time complexity..dont use this method.Use Floyd Algorithm by detecting cycle*/