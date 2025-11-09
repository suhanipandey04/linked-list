#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }
    void push_back(int val)
    {
         Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    myList.push_back(50);
    myList.push_back(80);

    cout << "Linked List: ";
    myList.display();

    return 0;
}
