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

// Print the doubly linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Delete head node
Node* deletehead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

// Delete tail node
Node* deletetail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    Node* newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

// Delete k-th position node
Node* deletekthpos(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;

    int cnt = 1;
    Node* knode = head;
    while (knode != nullptr && cnt < k) {
        knode = knode->next;
        cnt++;
    }

    if (knode == nullptr) {
        cout << "Position " << k << " does not exist." << endl;
        return head;
    }

    Node* prev = knode->back;
    Node* front = knode->next;

    if (prev == nullptr)
        return deletehead(head);  // deleting first node
    else if (front == nullptr)
        return deletetail(head);  // deleting last node
    else {
        prev->next = front;
        front->back = prev;
        delete knode;
        return head;
    }
}

// Delete a given node (not position-based)
Node* deletenode(Node* head, Node* temp) {
    if (head == nullptr || temp == nullptr) return head;

    // If deleting head
    if (temp->back == nullptr)
        return deletehead(head);

    // If deleting tail
    if (temp->next == nullptr)
        return deletetail(head);

    // Deleting middle node
    Node* prev = temp->back;
    Node* front = temp->next;

    prev->next = front;
    front->back = prev;

    delete temp;
    return head;
}

// Insert before head
Node* insertbeforehead(Node* head, int val) {
    Node* newhead = new Node(val, head, nullptr);
    if (head != nullptr)
        head->back = newhead;
    return newhead;
}

// Insert before tail
Node* insertbeforetail(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }

    if (head->next == nullptr) {
        return insertbeforehead(head, val);
    }

    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertarr2dll(arr);

    cout << "Original List: ";
    print(head);

    // Delete head
    head = deletehead(head);
    cout << "After deleting head: ";
    print(head);

    // Delete tail
    head = deletetail(head);
    cout << "After deleting tail: ";
    print(head);

    // Delete given node (first node now)
    head = deletenode(head, head);
    cout << "After deleting given node (head): ";
    print(head);

    // Delete by position
    head = deletekthpos(head, 2);
    cout << "After deleting position 2: ";
    print(head);

    // Insert before head
    head = insertbeforehead(head, 10);
    cout << "After inserting before head: ";
    print(head);

    // Insert before tail
    head = insertbeforetail(head, 19);
    cout << "After inserting before tail: ";
    print(head);

    return 0;
}
