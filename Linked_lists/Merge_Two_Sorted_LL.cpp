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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Create a Dummy Node to simplify head handling
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // 2. Iterate while BOTH lists have nodes
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // 3. Attach the remaining nodes (if any)
        if (list1 != NULL) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // 4. Return the actual head (skipping dummy)
        return dummyNode->next;
    }
};

// --- Helper Functions to Run Locally ---

// Helper to create a Linked List from a vector
ListNode* createList(vector<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int val : vals) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper to print a Linked List
void printList(ListNode* head) {
    cout << "[ ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});
    
    cout << "Merging [1,2,4] and [1,3,4]..." << endl;
    ListNode* merged = sol.mergeTwoLists(l1, l2);
    printList(merged); 
    // Expected: [ 1 1 2 3 4 4 ]

    // Test Case 2 (Empty)
    ListNode* l3 = createList({});
    ListNode* l4 = createList({});
    cout << "Merging [] and []..." << endl;
    printList(sol.mergeTwoLists(l3, l4));
    // Expected: [ ]

    // Test Case 3 (One Empty)
    ListNode* l5 = createList({});
    ListNode* l6 = createList({0});
    cout << "Merging [] and [0]..." << endl;
    printList(sol.mergeTwoLists(l5, l6));
    // Expected: [ 0 ]

    return 0;
}