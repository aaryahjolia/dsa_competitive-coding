## Question Link :

https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    position--;
    SinglyLinkedListNode* head=llist;
    if(position==-1){
        llist=llist->next;
        return llist;
    }
    while(position--){
        head=head->next;
    }
    SinglyLinkedListNode* temp=head->next->next;
    head->next=temp;
    return llist;
}

```