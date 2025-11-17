#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


bool isPalindrome(ListNode* head) {
    vector<int> arr;
    while (head != nullptr) {
        arr.push_back(head->val);
        head = head->next;
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    // Example Linked List: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
