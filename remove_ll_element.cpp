#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy->next;
}


void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head);

    int valToRemove = 6;
    head = removeElements(head, valToRemove);

    cout << "List after removing " << valToRemove << ": ";
    printList(head);

    return 0;
}