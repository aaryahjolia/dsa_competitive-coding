## Question Link :

https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data){
    DoublyLinkedListNode* new_node=new DoublyLinkedListNode(data);
    new_node->next = new_node->prev = nullptr;
    
    if(llist==nullptr){
        return new_node;
    }    
    if(llist->data>data){
        new_node->next=llist;
        llist->prev=new_node;
        return new_node;
    }
    
    DoublyLinkedListNode* head = sortedInsert(llist->next, data);
    llist->next=head;
    head->prev=llist;
    return llist;
}

```