## Question Link :

https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* p=llist;
    DoublyLinkedListNode* q=p->next;    
    while(q){
        swap(p->next,p->prev);
        p=p->prev;
        q=q->next;
    }    
    swap(p->next,p->prev);
    return p;
}

```