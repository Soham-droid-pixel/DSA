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

ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while(curr != NULL) {

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {

    if(head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = reverseList(slow);
    ListNode* firstHalf = head;

    while(secondHalf != NULL) {

        if(firstHalf->val != secondHalf->val) {
            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {

    ListNode* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    printList(head);

    if(isPalindrome(head)) {
        cout << "Palindrome Linked List";
    }
    else {
        cout << "Not Palindrome Linked List";
    }

    return 0;
}