#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

void insertAtEnd(ListNode*& head, int data) {

    ListNode* newNode = new ListNode(data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode* deleteMiddle(ListNode* head) {

    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while(fast != NULL && fast->next != NULL) {

        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;

    return head;
}

int main() {

    ListNode* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    printList(head);

    head = deleteMiddle(head);

    printList(head);

    return 0;
}