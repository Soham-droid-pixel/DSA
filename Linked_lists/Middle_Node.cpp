#include <iostream>
#include <vector>

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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        // ---------------------------------------------------------
        // 🚨 CRITICAL LESSON: SHORT-CIRCUIT EVALUATION 🚨
        //
        // CORRECT ORDER: (fast != NULL && fast->next != NULL)
        // 1. Check if 'fast' exists.
        // 2. ONLY if 'fast' exists, check 'fast->next'.
        //
        // WRONG ORDER: (fast->next != NULL && fast != NULL)
        // -> If 'fast' is NULL, accessing 'fast->next' causes a CRASH (SegFault).
        // ---------------------------------------------------------
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move Slow 1 step
            fast = fast->next->next;    // Move Fast 2 steps
        }
        
        return slow;
    }
};

// --- Helper Functions to Run in VS Code ---

// 1. Function to create a Linked List from a Vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// 2. Function to print the Linked List
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Odd number of nodes [1, 2, 3, 4, 5]
    // Middle should be 3.
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(vals1);
    
    cout << "Input List: ";
    printList(head1);

    ListNode* mid1 = sol.middleNode(head1);
    cout << "Middle Node: " << mid1->val << endl; // Expected: 3
    
    cout << "-----------------" << endl;

    // Test Case 2: Even number of nodes [1, 2, 3, 4, 5, 6]
    // Middle should be 4 (the second middle).
    vector<int> vals2 = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createList(vals2);

    cout << "Input List: ";
    printList(head2);

    ListNode* mid2 = sol.middleNode(head2);
    cout << "Middle Node: " << mid2->val << endl; // Expected: 4

    return 0;
}