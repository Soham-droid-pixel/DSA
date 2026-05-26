#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x) {

    if (x < 0) {
        return false;
    }

    string val = to_string(x);

    int left = 0;
    int right = val.length() - 1;

    while (left < right) {

        if (val[left] != val[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {

    int x;

    cin >> x;

    if (isPalindrome(x)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}