#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;

        delNode(ansNode);
        addNode(ansNode);
        m[key] = head->next; // update to new position

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main() {
    // Example usage:
    LRUCache cache(2); // capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);

    cout << "Get 1: " << cache.get(1) << endl; // returns 10

    cache.put(3, 30); // evicts key 2

    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // returns 30

    cache.put(4, 40); // evicts key 1

    cout << "Get 1: " << cache.get(1) << endl; // returns -1
    cout << "Get 3: " << cache.get(3) << endl; // returns 30
    cout << "Get 4: " << cache.get(4) << endl; // returns 40

    return 0;
}