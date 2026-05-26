#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(i >= 0 && j >= 0) {

        if(nums1[i] > nums2[j]) {

            nums1[k] = nums1[i];

            i--;
        }
        else {

            nums1[k] = nums2[j];

            j--;
        }

        k--;
    }

    while(j >= 0) {

        nums1[k] = nums2[j];

        j--;
        k--;
    }
}

int main() {

    int m, n;

    cout << "Enter number of elements in nums1: ";
    cin >> m;

    cout << "Enter number of elements in nums2: ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter elements of nums1: ";

    for(int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter elements of nums2: ";

    for(int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    cout << "Merged Sorted Array: ";

    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}