#include <iostream>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    // Default constructor
    ListNode() : val(0), next(nullptr) {}
    // Constructor with value
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor with value and next pointer
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Adds two numbers represented by linked lists.
 * The digits are stored in reverse order.
 * l1: The head of the first linked list (number 1).
 * l2: The head of the second linked list (number 2).
 * Returns: The head of the new linked list representing the sum.
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 1. Initialize a dummy head node and a pointer to build the result list
    ListNode* dummy = new ListNode();
    ListNode* res = dummy; // 'res' will keep track of the start of the new list (after dummy)
    
    // Initialize variables for sum and carry
    int total = 0, carry = 0;

    // 2. Iterate until both lists are processed AND there is no more carry
    while (l1 || l2 || carry) {
        // Start the total for the current digit with the carry from the previous step
        total = carry;

        // Add the digit from the first list, if available
        if (l1) {
            total += l1->val;
            l1 = l1->next; // Move to the next digit in list 1
        }
        
        // Add the digit from the second list, if available
        if (l2) {
            total += l2->val;
            l2 = l2->next; // Move to the next digit in list 2
        }

        // 3. Calculate the new digit and the new carry
        int num = total % 10;   // The new digit is the last digit of the total sum (e.g., 17 % 10 = 7)
        carry = total / 10;     // The new carry is the tens digit of the total sum (e.g., 17 / 10 = 1)
        
        // 4. Create a new node with the calculated digit and append it to the result list
        dummy->next = new ListNode(num);
        dummy = dummy->next; // Move the dummy pointer to the newly created node for the next iteration
    }

    // 5. Clean up and return the result
    ListNode* result = res->next; // The result is the node immediately after the initial dummy node
    delete res; // Free the memory allocated for the initial dummy node
    return result; 
}

// Utility function to print the list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

// Utility function to clean up the list memory
void deleteList(ListNode* head) {
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example 1: l1 = [2,4,3] (represents 342), l2 = [5,6,4] (represents 465)
    // Expected sum: 807
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    std::cout << "List 1 (342): ";
    printList(l1);
    std::cout << "List 2 (465): ";
    printList(l2);

    ListNode* sum_list = addTwoNumbers(l1, l2);

    std::cout << "Sum List (807): ";
    printList(sum_list);
    
    // Clean up memory
    deleteList(l1);
    deleteList(l2);
    deleteList(sum_list);

    std::cout << "\n--- Example 2 (with carry to end) ---\n";
    // Example 2: l1 = [9,9] (represents 99), l2 = [1] (represents 1)
    // Expected sum: 100
    l1 = new ListNode(9, new ListNode(9));
    l2 = new ListNode(1);

    std::cout << "List 1 (99): ";
    printList(l1);
    std::cout << "List 2 (1): ";
    printList(l2);

    sum_list = addTwoNumbers(l1, l2);

    std::cout << "Sum List (100): ";
    printList(sum_list);
    
    // Clean up memory
    deleteList(l1);
    deleteList(l2);
    deleteList(sum_list);

    return 0;
}