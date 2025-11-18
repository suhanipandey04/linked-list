#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* lista = headA;
    ListNode* listb = headB;

    while (lista != listb) {
        lista = (lista != nullptr) ? lista->next : headB;
        listb = (listb != nullptr) ? listb->next : headA;
    }
    return lista;
}


int main() {
    
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    // List A
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    // List B
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    ListNode* result = getIntersectionNode(headA, headB);
    if (result)
        cout << "Intersection at node with value: " << result->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}