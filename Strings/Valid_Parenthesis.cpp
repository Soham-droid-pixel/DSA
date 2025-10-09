#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                bracket_stack.push(ch);
            } else {
                if (bracket_stack.empty()) {
                    return false;
                }
                char top = bracket_stack.top();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
                bracket_stack.pop();
            }
        }
        return bracket_stack.empty();
    }
};

int main() {
    Solution sol;
    vector<string> test_cases = {
        "()", 
        "()[]{}", 
        "(]", 
        "([)]", 
        "{[]}",
        "]"
    };

    cout << "Running tests..." << endl;
    for (const auto& test : test_cases) {
        bool result = sol.isValid(test);
        cout << "Input: \"" << test << "\" -> Output: " << boolalpha << result << endl;
    }

    return 0;
}