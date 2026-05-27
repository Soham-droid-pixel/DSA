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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode dummy(0);
    ListNode* temp = &dummy;

    while(list1 != NULL && list2 != NULL) {

        if(list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if(list1 != NULL) {
        temp->next = list1;
    }

    if(list2 != NULL) {
        temp->next = list2;
    }

    return dummy.next;
}

int main() {

    ListNode* list1 = NULL;
    ListNode* list2 = NULL;

    insertAtEnd(list1, 1);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 5);

    insertAtEnd(list2, 2);
    insertAtEnd(list2, 4);
    insertAtEnd(list2, 6);

    ListNode* result = mergeTwoLists(list1, list2);

    printList(result);

    return 0;
}