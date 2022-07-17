## Question Link :

https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true

## Code solution :

```cpp
// C++14 Language
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* p=llist;
    SinglyLinkedListNode* q=p->next;
    SinglyLinkedListNode* r=q->next;
    p->next=nullptr;
    while(q->next!=nullptr){
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    return q;
}

```