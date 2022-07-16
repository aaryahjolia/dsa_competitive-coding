## Question Link :

https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    position--;
    SinglyLinkedListNode* head=llist;
    while(position--){
        head=head->next;
    }
    SinglyLinkedListNode* second_head=head->next;
    head->next=new SinglyLinkedListNode(data);
    head=head->next;
    head->next=second_head;
    return llist;
}

```