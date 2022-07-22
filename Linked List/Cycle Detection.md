# Cycle Detection in a Linked List

When a node in a linked list points to one of its previous nodes, a cycle is formed.

If we traverse a linked list through the head pointer, we shall never encounter its end, i.e. NULL. This property makes its use in the standard 'hare and tortoise technique' used to detect a cycle in a singly linked list.

## Algorithm

We take two pointers, ideally 'fast' and 'slow'. Move the fast pointer two nodes and the slow pointer single node at a time. If fast reaches the end of the list, there is no cycle in the linked list, whereas if fast and slow ever point to the same node, it indicates that there is a cycle present in the linked list.

Further, to find at which node the cycle is formed, we place one of the pointers, fast or slow at the head, and move both pointers one node at a time. The node at which they meet will be the node the cycle is formed.

## Intuition
The intuition behind this algorithm comes from a circular racing track where two players will always meet each other unless they're running with the same speed.

## Code

``` cpp
#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int data;
};

void insertAtTail(Node *tail, int temp);
int detectCycle(Node *head);

int main() {

    int ans;
    Node *head = new Node(), *tail = head;

    // inserting nodes into linked list
    insertAtTail(tail, 1); // 1
    tail = tail -> next;
    insertAtTail(tail, 2); // 1 -> 2
    tail = tail -> next;
    insertAtTail(tail, 3); // 1 -> 2 -> 3
    tail = tail -> next;
    insertAtTail(tail, 4); // 1 -> 2 -> 3 -> 4
    tail = tail -> next;
    insertAtTail(tail, 5); // 1 -> 2 -> 3 -> 4 -> 5
    tail = tail -> next;
    // creating a cycle
    tail -> next = head -> next -> next; // 1 -> 2 -> 3 -> 4 -> 5 -> 2
    tail = tail -> next;
    
    ans = detectCycle(head -> next);

    /* ans = 0 indicates no cycle present in the list. any other number indicates the
    presence of a cycle and represents the value of the node at which cycle is forming */

    if (ans) {
        cout << "Cycle detected at " << ans;
    }
    else {
        cout << "No cycle detected";
    }

    return 0;
}

void insertAtTail(Node *tail, int data) {
  
    Node *temp = new Node();
    temp -> data = data;
    temp -> next = NULL;
    tail -> next = temp;
}

int detectCycle(Node *head) {

    /*using the standard hare and tortoise technique - two pointers are marked at the head of the
    linked list, one traverses one node at a time, the other, two nodes at a time. if they meet, it
    implies that a cycle is present */
    Node *fast = head, *slow = head;

    while (1) {
        if(fast == NULL || fast -> next == NULL) {
            return 0; // no cycle present
        }

        fast = fast -> next -> next;
        slow = slow -> next;

        if (slow == fast) {
            break;
        }
    }

    slow = head;
    
    // finding the node at which cycle is formed
    while (slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow -> data;
}
```
### Run Code
https://ide.geeksforgeeks.org/59d8bb3c-2e74-4078-839d-c51423eac7a0

### Output

```
Cycle detected at 2
```

Time Complexity: O(n)  
Space Complexity: O(1)
