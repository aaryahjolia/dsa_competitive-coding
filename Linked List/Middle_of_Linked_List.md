## Description
Traversing the linked list with 2 pointers to find the middle node of the linked list.

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

//Also Known as tortoise hare method where we use a fast pointer and a slow pointer
ListNode* findMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next; //Traverse 1 node at a time
        fast = fast -> next -> next; //Traverse 2 nodes at a time
    }

    return slow; //Finally the middle node will be stored in slow
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    // Find the middle of the linked list
    ListNode* middle = findMiddle(head);

    if (middle != nullptr)
        cout << "Middle element: " << middle -> val << endl;
    else
        cout << "Linked list is empty." << endl;

    // Clean up the memory
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
```
## Run Code
https://ide.geeksforgeeks.org/online-cpp14-compiler/76385d10-1474-41ca-8859-ec5293448563

## Complexities
### Time Complexity  :
O(n)
### Space Complexity  :
O(1)

