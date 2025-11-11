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

// Remove duplicates from sorted doubly linked list
Node* removeduplicate(Node* head) {
    if (!head) return head;
    
    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* dup = current->next;
            current->next = dup->next;
            if (dup->next) dup->next->back = current;
            delete dup; // free memory
        } else {
            current = current->next;
        }
    }
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
    vector<int> arr = {1, 1, 3, 4, 5, 6, 6};
    Node* head = convertarr2dll(arr);

    cout << "Original List: ";
    print(head);

    head = removeduplicate(head);
    cout << "After removing duplicates: ";
    print(head);

    return 0;
}
