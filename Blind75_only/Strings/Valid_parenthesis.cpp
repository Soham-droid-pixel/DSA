#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for (char ch : s) {

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        // Closing brackets
        else {

            if (st.empty()) {
                return false;
            }

            char top = st.top();

            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {

                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {

    string s;
    cin >> s;

    if (isValid(s)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}