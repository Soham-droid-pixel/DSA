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
    ListNode* reverseList(ListNode* head) {
        // ---------------------------------------------------------
        // TODO: WRITE YOUR LOGIC HERE
        // Remember the mantra: "Save, Point Back, Move Ahead"
        ListNode *prev=NULL;
        ListNode *temp=head;
        while(temp!=NULL){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
        
        
        
        
        
        
        
        
        
        // ---------------------------------------------------------
     // Replace this with 'return prev;'
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Driver code to test your function
int main() {
    // 1. Create a hardcoded list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // 2. Call your function
    Solution sol;
    ListNode* newHead = sol.reverseList(head);

    // 3. Print the result
    cout << "Reversed List: ";
    printList(newHead);

    return 0;
}