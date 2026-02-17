#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // 1. Calculate the Length of the list
        ListNode *temp = head;
        int length = 0;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        // 2. Find the k-th node from the Beginning
        // We start at head and move (k-1) times
        ListNode *firstNode = head;
        for(int i = 0; i < k - 1; i++) {
            firstNode = firstNode->next;
        }

        // 3. Find the k-th node from the End
        // The k-th node from end is the (Length - k + 1)-th node from start.
        // Since we are moving pointers, we need to move (Length - k) times from head.
        ListNode *secondNode = head;
        int moves = length - k;
        for(int i = 0; i < moves; i++) {
            secondNode = secondNode->next;
        }

        // 4. Swap the VALUES (Not the pointers)
        // This is much safer and accepted in interviews unless asked otherwise.
        swap(firstNode->val, secondNode->val);

        return head;
    }
};

// --- Helper Functions to make this run in VS Code ---

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to create a linked list from a vector (array)
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// --- Main Function ---
int main() {
    Solution sol;

    // Test Case: List = [1, 2, 3, 4, 5], k = 2
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 2;

    // Create and Print Original
    ListNode* head = createList(values);
    cout << "Original List: ";
    printList(head);

    // Run Solution
    head = sol.swapNodes(head, k);

    // Print Result
    cout << "After Swapping k=" << k << ": ";
    printList(head);

    return 0;
}