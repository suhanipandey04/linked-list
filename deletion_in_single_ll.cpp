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

    void pop_front(int val) {
       if(head==NULL)
       {
        cout<<"linked list is empty"<<endl;

       } 
       Node* temp=head;
       head=head->next;
       temp->next=NULL;
       delete temp;
    }
    void pop_back(int val)
    {
        if(head==NULL)
       {
        cout<<"linked list is empty"<<endl;

       } 
       Node* temp=head;
       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=NULL;
       delete tail;
       tail=temp;
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
    
    cout << "Linked List: ";
    myList.display();
    



    return 0;
}

