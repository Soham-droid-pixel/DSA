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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // The Dummy Node: Our anchor that never moves
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy, *nex = dummy, *pre = dummy;
        int count = 0;

        // 1. Count total nodes to know when to stop
        curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        // 2. Perform the "Pluck and Tuck" reversal
        while (count >= k) {
            curr = pre->next; // The first node of the group
            nex = curr->next; // The node we are about to move to the front

            for (int i = 1; i < k; i++) {
                curr->next = nex->next;   // Skip
                nex->next = pre->next;   // Connect
                pre->next = nex;         // Hook
                nex = curr->next;        // Update next
            }
            
            pre = curr; // Move the anchor to the end of the reversed group
            count -= k;
        }

        return dummy->next;
    }
};

// --- Helper Functions for Testing ---

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: k = 2
    vector<int> v1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode* head1 = createList(v1);
    cout << "Test 1 | Original: "; printList(head1);
    ListNode* res1 = sol.reverseKGroup(head1, k1);
    cout << "Test 1 | k=" << k1 << " Result: "; printList(res1);
    cout << "-----------------------------------" << endl;

    // Test Case 2: k = 3
    vector<int> v2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    ListNode* head2 = createList(v2);
    cout << "Test 2 | Original: "; printList(head2);
    ListNode* res2 = sol.reverseKGroup(head2, k2);
    cout << "Test 2 | k=" << k2 << " Result: "; printList(res2);

    return 0;
}