## Question Link :

https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* head=new SinglyLinkedListNode(data);
    head->next=llist;
    llist=head;
    return head;
}

```