#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Convert array to doubly linked list
Node* convertarr2dll(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Reverse doubly linked list
Node* reverse(Node* head) {
    if (head==NULL) return nullptr;

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Swap next and back
        temp = current->back;
        current->back = current->next;
        current->next = temp;
        // Move to next node (which is previous due to swap)
        current = current->back;
    }

    // temp now points to the node before new head
    if (temp != nullptr)
        head = temp->back;

    return head;
}

// Print the doubly linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertarr2dll(arr);

    cout << "Original List: ";
    print(head);

    head = reverse(head);
    cout << "After Reversing List: ";
    print(head);

    return 0;
}
