#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {

    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] % 2 == 0) {
            ans.push_back(nums[i]);
        }
    }

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] % 2 != 0) {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sortArrayByParity(nums);

    cout << "Array after parity sorting: ";

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}