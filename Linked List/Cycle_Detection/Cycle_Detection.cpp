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
