#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n);

    int evenIndex = 0;
    int oddIndex = 1;

    for(int i = 0; i < n; i++) {

        if(nums[i] % 2 == 0) {

            ans[evenIndex] = nums[i];

            evenIndex += 2;
        }
        else {

            ans[oddIndex] = nums[i];

            oddIndex += 2;
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

    vector<int> result = sortArrayByParityII(nums);

    cout << "Sorted Array: ";

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}