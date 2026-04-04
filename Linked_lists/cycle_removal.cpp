#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool detectAndRemoveLoop(ListNode* head) {
        if (!head || !head->next) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) break; 
        }

        if (slow != fast) return false;

        slow = head;
        
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = nullptr;
        return true;
    }
};

void createLoop(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode *temp = head, *loopEntry = nullptr;
    int count = 0;
    while (temp->next) {
        if (count == pos) loopEntry = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopEntry; 
}

int main() {
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    
    createLoop(head, 1);

    Solution sol;
    if (sol.detectAndRemoveLoop(head)) {
        std::cout << "Loop detected and successfully removed!" << std::endl;
    } else {
        std::cout << "No loop found." << std::endl;
    }

    return 0;
}