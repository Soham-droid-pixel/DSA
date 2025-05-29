#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;

    vector<int> digits(n);
    cout << "Enter array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }


    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1;
            
            break;
        } else {
            
            digits[i] = 0;
        }
    }

    
    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }

    cout << "Final array:" << endl;
    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i];
    }
    cout << endl;

    return 0;
}
