#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void sortedInsert(stack<int>& s, int x) {
        if (s.empty() || s.top() < x) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        sortedInsert(s, x);
        s.push(temp);
    }

    void sortStack(stack<int>& s) {
        if (!s.empty()) {
            int x = s.top();
            s.pop();
            sortStack(s);
            sortedInsert(s, x);
        }
    }
};

void printStack(stack<int> s) {
    if (s.empty()) {
        cout << "[ Empty Stack ]" << endl;
        return;
    }
    while (!s.empty()) {
        cout << "| " << s.top() << " |" << endl;
        s.pop();
    }
    cout << " --- " << endl;
}

void runTest(string title, vector<int> elements) {
    stack<int> s;
    for (int x : elements) s.push(x);

    cout << "TEST CASE: " << title << endl;
    cout << "Before:" << endl;
    printStack(s);

    Solution sol;
    sol.sortStack(s);

    cout << "After (Sorted):" << endl;
    printStack(s);
    cout << "-------------------------------" << endl;
}

int main() {
    runTest("Mixed Values", {30, -5, 18, 14, -3});
    runTest("Already Sorted", {-10, 0, 10, 20});
    runTest("Reverse Sorted", {50, 40, 30, 20, 10});
    runTest("Duplicates", {5, 1, 5, 2, 1});
    runTest("Single Element", {100});
    runTest("Empty Stack", {});

    return 0;
}