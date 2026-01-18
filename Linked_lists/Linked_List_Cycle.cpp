#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Edge Case: Empty list or single node (no loop possible)
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // THE SAFETY BELT LOOP
        // We must check 'fast->next' because fast moves 2 steps.
        // If fast is at the last node, fast->next is NULL, so fast->next->next would crash.
        while (fast != NULL && fast->next != NULL) {
            
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps

            // Collision check: If they meet, there is a cycle.
            if (slow == fast) {
                return true; 
            }
        }

        // If fast reaches NULL, the track has an end. No cycle.
        return false;
    }
};

int main() {
    // 1. Create Nodes
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // 2. Link them: 3 -> 2 -> 0 -> -4
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // 3. CREATE THE CYCLE (The Magic Step)
    // Connect the last node (-4) back to the second node (2)
    node4->next = node2; 

    // 4. Test the Solution
    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "Result: Cycle Detected! (True)" << endl;
    } else {
        cout << "Result: No Cycle. (False)" << endl;
    }

    // Note: We cannot delete nodes easily here because of the infinite loop!
    // In a real program, you would need to break the cycle first to free memory.
    
    return 0;
}

/* ========================================================================
                             NOTEBOOK NOTES 
========================================================================

1. The Algorithm: "Tortoise and Hare" (Floyd's Cycle Detection)
   - Uses two pointers moving at different speeds.
   - Slow: Moves 1 step.
   - Fast: Moves 2 steps.

2. The Logic:
   - If there is NO loop, Fast will reach NULL (the finish line).
   - If there IS a loop, Fast will eventually "lap" (catch up to) Slow.
   - Imagine a race track: The faster runner eventually passes the slower one 
     again if they keep running in circles.

3. The "Crash Prevention" Rule (Memorize this!):
   - Always check: while (fast != NULL && fast->next != NULL)
   - Why? Because 'fast' jumps 2 steps. You cannot jump off a cliff!

4. Complexity:
   - Time: O(N) -> We traverse the list linearly.
   - Space: O(1) -> No Map/Notebook needed! Just 2 pointers.
*/