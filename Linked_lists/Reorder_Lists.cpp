#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
// This is the standard struct used in almost all Linked List problems.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // EDGE CASE: If list is empty or has only 1 node, no reordering needed.
        if (!head || !head->next) return;

        // ====================================================
        // STEP 1: FIND THE MIDDLE OF THE LIST
        // Strategy: Use Slow & Fast pointers.
        // Slow moves 1 step, Fast moves 2 steps. 
        // When Fast hits the end, Slow will be exactly at the middle.
        // ====================================================
        ListNode* slow = head;
        ListNode* fast = head;

        // Loop runs while fast is not at the end (null) and not at the last node (next is null)
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;      // Move 1 step
            fast = fast->next->next;// Move 2 steps
        }
        // At this point, 'slow' is pointing to the end of the FIRST half.

        // ====================================================
        // STEP 2: REVERSE THE SECOND HALF
        // We need to access the end of the list to bring it to the front.
        // Since we can't go backwards, we reverse the second half so we can traverse it forwards.
        // ====================================================
        
        // 'second' will be the head of the new reversed list.
        // slow->next is the node where the second half starts.
        ListNode* second = reverseList(slow->next);
        
        // CRITICAL STEP: Cut the connection between the two halves!
        // If we don't do this, we get a cycle (infinite loop).
        slow->next = nullptr; 

        // ====================================================
        // STEP 3: MERGE THE TWO HALVES (THE "ZIPPER")
        // We now have two separate lists:
        // 'first':  1 -> 2 -> null
        // 'second': 4 -> 3 -> null (Reversed)
        // We merge them: 1 -> 4 -> 2 -> 3
        // ====================================================
        ListNode* first = head;

        // We run until we run out of nodes in the second half.
        // (Second half is always equal or shorter than the first).
        while (second != nullptr) {
            
            // 1. Save the connections to the REST of the lists
            // We are about to break links, so we must remember where to go next.
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // 2. Stitch the nodes together
            first->next = second;   // Link node from L1 to L2 (e.g., 1 -> 4)
            second->next = temp1;   // Link node from L2 back to L1 (e.g., 4 -> 2)

            // 3. Move pointers forward to process the next pair
            first = temp1;
            second = temp2;
        }
    }

    // --- Helper Function: Reverse Linked List ---
    // Takes a list like 3 -> 4 -> null and returns 4 -> 3 -> null
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Save next node
            curr->next = prev;               // Point backwards
            prev = curr;                     // Move prev forward
            curr = nextTemp;                 // Move curr forward
        }
        return prev; // Prev is the new Head
    }
};

// ==========================================
// DRIVER CODE (For Local Testing)
// ==========================================

// Helper to print a list: [ 1 2 3 ]
void printList(ListNode* head) {
    cout << "[ ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]" << endl;
}

// Helper to create a list from vector: {1,2,3} -> 1->2->3
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int val : vals) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    Solution sol;

    // Test Case 1: Even number of nodes
    // Input: 1 -> 2 -> 3 -> 4
    // Expected: 1 -> 4 -> 2 -> 3
    ListNode* l1 = createList({1, 2, 3, 4});
    cout << "Test 1 Input:  "; printList(l1);
    sol.reorderList(l1);
    cout << "Test 1 Output: "; printList(l1);

    cout << "---------------------------" << endl;

    // Test Case 2: Odd number of nodes
    // Input: 1 -> 2 -> 3 -> 4 -> 5
    // Split: 1->2->3 (First) and 4->5 (Second)
    // Reverse Second: 5->4
    // Merge: 1->5->2->4->3
    ListNode* l2 = createList({1, 2, 3, 4, 5});
    cout << "Test 2 Input:  "; printList(l2);
    sol.reorderList(l2);
    cout << "Test 2 Output: "; printList(l2);

    return 0;
}