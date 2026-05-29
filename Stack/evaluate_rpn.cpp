#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s : tokens) {
            // Check if the current token is an operator
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                
                // POP ORDER MATTERS: The first popped element is the right operand (b)
                // The second popped element is the left operand (a)
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();
                
                // Evaluate the expression and push the result back onto the stack
                if(s == "+") st.push(a + b);
                else if(s == "-") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else st.push(a / b);
                
            } else {
                // If it's a number, convert the string to an integer and push it
                st.push(stoi(s));
            }
        }
        
        // The final result will be the only element left in the stack
        return st.top();
    }
};

int main() {
    Solution sol;

    // Test Case 1: Simple Addition and Multiplication
    // Explanation: ((2 + 1) * 3) = 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Test Case 1 Output: " << sol.evalRPN(tokens1) << " (Expected: 9)\n";

    // Test Case 2: Division and Addition
    // Explanation: (4 + (13 / 5)) = 6 (Note: 13/5 truncates to 2)
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Test Case 2 Output: " << sol.evalRPN(tokens2) << " (Expected: 6)\n";

    // Test Case 3: Complex nested operations
    // Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Test Case 3 Output: " << sol.evalRPN(tokens3) << " (Expected: 22)\n";

    return 0;
}