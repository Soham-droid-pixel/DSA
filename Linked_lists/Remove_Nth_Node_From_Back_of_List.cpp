#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // LINE 1 & 2: Set up the Runners
        // We create two new pointers, 'fast' and 'slow'.
        // Initially, they both point to the START (Head) of the train.
        ListNode* fast = head;
        ListNode* slow = head;

        // LINE 3: The Gap Creation Loop
        // We want 'fast' to get a head start.
        // Think of holding a stick of length 'N'. We are pushing the front of the stick forward.
        for (int i = 0; i < n; i++) {
            fast = fast->next; // Move 'fast' to the next car, N times.
        }

        // LINE 4: The "Edge Case" Check
        // Scenario: You have 5 cars, and n=5 (You want to remove the 5th car from the end).
        // That means you want to remove the HEAD itself!
        // After the loop above, 'fast' would have walked off the end of the train (NULL).
        if (fast == NULL) {
            // If 'fast' fell off, it means we must delete the first node.
            // So, the new head is the SECOND node (head->next).
            return head->next; 
        }

        // LINE 5: The Sliding Window Loop
        // Now we have a gap of size N between 'fast' and 'slow'.
        // We move BOTH forward at the same speed (1 step at a time).
        // CONDITION: Stop when 'fast' reaches the LAST CAR (not NULL).
        // Why? When 'fast' is at the last car, 'slow' is exactly BEFORE the target car.
        while (fast->next != NULL) {
            fast = fast->next; // Fast takes a step
            slow = slow->next; // Slow takes a step
        }

        // LINE 6: Identify the Victim
        // The loop finished. 'slow' is standing right before the node we want to kill.
        // Let's create a temporary pointer to remember the node we are deleting.
        ListNode* nodeToDelete = slow->next;

        // LINE 7: The Bypass (The Actual Deletion)
        // "Hey 'slow', stop pointing to 'nodeToDelete'."
        // "Instead, point to 'nodeToDelete's neighbor."
        // Effectively, we snip the link to the target node.
        slow->next = slow->next->next; 

        // LINE 8: Clean up Memory
        // In C++, if you don't delete memory, it stays there (Memory Leak).
        // We explicitly throw away the node we just removed.
        delete nodeToDelete; 
        
        // LINE 9: Return the List
        // We return 'head' because the start of the list hasn't changed 
        // (unless we hit the edge case in Line 4).
        return head;
    }
};

// --- Helper Functions for VS Code Testing ---

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test Case 1: [1, 2, 3, 4, 5], n = 2
    // We want to remove the 2nd node from the end (which is 4)
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);

    cout << "Original List: ";
    printList(head);

    // Call the function
    head = sol.removeNthFromEnd(head, 2);

    cout << "After Removing 2nd from End: ";
    printList(head); // Expected: 1 -> 2 -> 3 -> 5 -> NULL

    return 0;
}