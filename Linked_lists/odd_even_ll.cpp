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

ListNode* oddEvenList(ListNode* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while(even != NULL && even->next != NULL) {

        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

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

    head = oddEvenList(head);

    printList(head);

    return 0;
}